#include "03/code_021d1fd0.h"
#include "03/code_021d1cd4.h"
#include "Main/Unknown/code_02023000.h"
#include "03/code_021d3000.h"

#include "03/unk_021da000.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "Main/Unknown/code_02022000.h"
#include "code_02022aa8.h"
#include "g2d_CharCanvas.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/unk_021d67d8.h"
#include "code_0200eddc.h"
#include "code_0214a054.h"
#include "code_0214a314.h"
#include "code_0214a2f4.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "03/code_021d1000.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1d60.h"
#include "03/unk_021d7000.h"
#include "registers.h"

void InitTextCanvases(void) {
    TextCanvases *canvases = AllocExpHeapBlock(0x798, 4);
    u32 *b;
    s32 i;

    gTextCanvases = canvases;
    gTextCanvases->mFreeObjCanvases = CreateFilledPointerStack(0x20, canvases->mObjCanvasStorage, 0x38);
    b = NULL;
    for (i = 0; i < 2; i++) {
        gTextCanvases->mFontFiles[i] = func_ov003_021d14b8(data_ov003_021d7c0c[i], b, 4);
        NNS_G2dFontInitUTF16(&gTextCanvases->mFonts[i], gTextCanvases->mFontFiles[i]);
    }
}

void ReleaseTextCanvases(void) {
    int i;
    for (i = 0; i < 2; i++) {
        func_ov003_021d1490(gTextCanvases->mFontFiles[i]);
    }
    func_ov003_021d1d4c(gTextCanvases->mFreeObjCanvases);
    FreeExpHeapBlockAndClearPointer(&gTextCanvases);
}

ObjTextCanvas *CreateObjTextCanvas(u32 screen, u16 areaWidth, u16 areaHeight, s32 fromFront, u32 *entryCount,
                                   s32 fontIndex) {
    ObjTextCanvas *canvas = PopPointerStack(gTextCanvases->mFreeObjCanvases);
    u32 charName;
    u32 charBase;
    Unk02022aa8 *font;

    canvas->mAreaWidth = areaWidth;
    canvas->mAreaHeight = areaHeight;
    canvas->mUnk_30 = func_ov003_021d309c(screen, areaWidth * areaHeight, fromFront, &charName);
    canvas->mCharName = charName;
    *entryCount = NNSi_G2dCalcRequiredOBJ(areaWidth, areaHeight);
    if (screen == 1) {
        charBase = 0x6600000;
    } else {
        charBase = 0x6400000;
    }
    charBase += charName << 7;
    NNS_G2dCharCanvasInitForOBJ1D(canvas, (void *) charBase, areaWidth, areaHeight, 4);
    canvas->mUnk_18(canvas, 0);
    font = &gTextCanvases->mFonts[fontIndex];
    canvas->mUnk_20 = canvas;
    canvas->mUnk_24 = font;
    canvas->mUnk_28 = 1;
    canvas->mUnk_2c = 1;
    return canvas;
}

void DeleteObjTextCanvas(void *canvas) {
    func_ov003_021d305c(*OFFSET_PTR(u32, canvas, 0x30));
    PushPointerStack(gTextCanvases->mFreeObjCanvases, canvas);
}

BgTextCanvas *InitBgTextCanvas(u32 screen, u32 fontIndex) {
    BgTextCanvas *canvas = &gTextCanvases->mBgTextCanvases[screen];
    u32 areaHeight = data_ov003_021d67e2[screen * 2];
    u32 areaWidth = data_ov003_021d67e0[screen * 2];
    vu16 *bgControl;
    u32 screenBase;
    u8 *font;

    canvas->mChars = AllocExpHeapBlock((areaWidth * areaHeight) << 5, 0x20);
    if (screen == 1) {
        bgControl = &reg_G2S_DB_BG0CNT;
        *bgControl &= ~0x40;
        *bgControl = (*bgControl & 0x43) | 0xc00;
    } else {
        bgControl = &reg_G2_BG0CNT;
        *bgControl &= ~0x40;
        *bgControl = (*bgControl & 0x43) | 0xc00;
    }
    NNS_G2dCharCanvasInitForBG(canvas, canvas->mChars, areaWidth, areaHeight, 4);
    font = (u8 *) gTextCanvases->mFonts + fontIndex * 12;
    canvas->mUnk_20.mCharCanvas = canvas;
    canvas->mUnk_20.mFont = font;
    canvas->mUnk_20.mCharSpacing = 1;
    canvas->mUnk_20.mLineSpacing = 1;
    if (screen == 1) {
        screenBase = G2S_GetBG0ScrPtr();
    } else {
        screenBase = G2_GetBG0ScrPtr();
    }
    NNS_G2dMapScrToCharText((u16 *) screenBase, areaWidth, areaHeight, 0, 0, 0x20, data_ov003_021d67dc[screen], 0xf);
    ClearBgTextCanvas(canvas, 0);
    canvas->mUploadTask =
        func_ov003_021d3544(1, AdvanceBgTextCanvasUpload, &gTextCanvases->mBgUploadPending[screen], 200);
    return canvas;
}

void AdvanceBgTextCanvasUpload(u32 task, u8 *flag) {
    TextCanvases *canvases;
    u32 size;

    if (*flag != 0) {
        canvases = gTextCanvases;
        if (flag == &canvases->mBgUploadPending[0]) {
            size = (data_ov003_021d67e0[0] * data_ov003_021d67e0[1]) << 5;
            DC_FlushRange(canvases->mBgTextCanvases[0].mChars, size);
            GX_LoadBG0Char(gTextCanvases->mBgTextCanvases[0].mChars, data_ov003_021d67dc[0] << 5, size);
        } else {
            size = (data_ov003_021d67e0[2] * data_ov003_021d67e0[3]) << 5;
            DC_FlushRange(canvases->mBgTextCanvases[1].mChars, size);
            GXS_LoadBG0Char(gTextCanvases->mBgTextCanvases[1].mChars, data_ov003_021d67dc[1] << 5, size);
        }
        *flag = 0;
    }
}

void ReleaseBgTextCanvas(BgTextCanvas *canvas) {
    // placeholders: the values are sent through the stack
    volatile u16 a;
    volatile u16 b;
    void *charBase;

    func_ov003_021d34c0(1, canvas->mUploadTask);
    if (canvas == gTextCanvases->mBgTextCanvases) {
        charBase = (void *) G2_GetBG0CharPtr();
        a = 0;
        MIi_CpuClear16(a, charBase, (data_ov003_021d67e0[0] * data_ov003_021d67e0[1]) << 5);
    } else {
        charBase = (void *) G2_GetBG0CharPtr();
        b = 0;
        MIi_CpuClear16(b, charBase, (data_ov003_021d67e0[2] * data_ov003_021d67e0[3]) << 5);
    }
    FreeExpHeapBlockAndClearPointer(&canvas->mChars);
}

void ReleaseBgTextCanvasOfScreen(u32 index) {
    ReleaseBgTextCanvas(&gTextCanvases->mBgTextCanvases[index]);
}

void DrawCanvasText(u32 canvas, u32 xPos, u32 yPos, u32 color, u32 flags, u32 text) {
    u32 v2 = flags;
    u32 v4 = text;
    u32 v6 = ((canvas) + (0x20u));
    u32 v7 = NNSi_G2dTextCanvasDrawText((TextCanvas *) v6, xPos, yPos, color, v2, (void *) v4);
}

void DrawCanvasChar(void *canvas, u32 xPos, u32 yPos, u32 color, u16 charCode, int fontIndex) {
    NNS_G2dCharCanvasDrawChar(canvas, gTextCanvases->mFonts + fontIndex, xPos, yPos, color, charCode);
}

void DrawCharsCentered(void *canvas, s32 xPos, u32 yPos, u32 color, s32 cellWidth, u16 *text, s32 fontIndex) {
    Unk02022aa8 *font;
    u32 glyphIndex;
    NNSG2dCharWidths *widths;
    s32 charWidth;

    while (*text != 0) {
        font = gTextCanvases->mFonts + fontIndex;
        glyphIndex = NNS_G2dFontFindGlyphIndex(font, *text);
        if (glyphIndex == 0xffff) {
            glyphIndex = font->mUnk_00->mUnk_02;
        }
        widths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
        if (font->mUnk_08 != 0) {
            charWidth = widths->mLeft + widths->mGlyphWidth;
        } else {
            charWidth = widths->mCharWidth;
        }
        DrawCanvasChar(canvas, xPos + ((cellWidth - charWidth) >> 1), yPos, color, *text, fontIndex);
        xPos += cellWidth;
        text++;
    }
}

void DrawCanvasTextRect(BgTextCanvas *canvas, s32 xPos, s32 yPos, s32 width, s32 height, u32 color, u32 flags,
                        void *text) {
    NNSi_G2dTextCanvasDrawTextRect(&canvas->mUnk_20, xPos, yPos, width, height, color, flags, text);
}

void ClearBgTextCanvas(BgTextCanvas *canvas, u32 color) {
    canvas->mUnk_00.mUnk_18(&canvas->mUnk_00, color);
}

void ArrangeObjTextCanvasRange(Unk021d1ffc *canvas, s32 xPos, s32 yPos, OamRange *range, s32 f) {
    void *entries = GetOamRangeEntry(range, 0);

    SetOamRangeEffect(range, -1, 0, 0);
    func_ov003_021d1890(range, -1, 0, 0xf);
    func_ov003_021d1790(range, -1, f);
    NNS_G2dArrangeOBJ1D(entries, canvas->mUnk_36, canvas->mUnk_37, xPos, yPos, 0, canvas->mUnk_34, 2);
}

void RequestBgTextCanvasUpload(void *canvas) {
    TextCanvases *state = gTextCanvases;
    if (canvas == state->mBgTextCanvases) {
        state->mBgUploadPending[0] = 1;
    } else {
        state->mBgUploadPending[1] = 1;
    }
}
