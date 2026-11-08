#pragma once

#include "types.h"

void DrawCanvasText(unsigned int canvas, unsigned int xPos, unsigned int yPos, unsigned int color, unsigned int flags,
                    unsigned int text);

#include "Main/Unknown/types_02180728.h"
#include "g2d_CharCanvas.h"

// 0x38-byte object; InitBgTextCanvas sets it up.
typedef struct BgTextCanvas {
    /* 00 */ Unk02023374 mUnk_00;
    /* 20 */ TextCanvas mUnk_20;
    /* 30 */ u8 *mChars;
    /* 34 */ u32 mUploadTask;
} BgTextCanvas;

#include "03/code_021d1d88.h"

void DrawCanvasTextRect(BgTextCanvas *canvas, s32 xPos, s32 yPos, s32 width, s32 height, u32 color, u32 flags,
                        void *text);

#include "03/code_021d2fa0.h"

typedef struct ObjTextCanvas {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct ObjTextCanvas *a, u32 b);
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ struct ObjTextCanvas *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ ObjCharRange *mUnk_30;
    /* 34 */ u16 mCharName;
    /* 36 */ u8 mAreaWidth;
    /* 37 */ u8 mAreaHeight;
} ObjTextCanvas;

typedef struct TextCanvases {
    /* 000 */ Unk02022aa8 mFonts[2];
    /* 018 */ u8 mObjCanvasStorage[0x700];
    /* 718 */ BgTextCanvas mBgTextCanvases[2];
    /* 788 */ PointerStack *mFreeObjCanvases;
    /* 78c */ Unk02021f9c *mFontFiles[2];
    /* 794 */ u8 mBgUploadPending[4];
} TextCanvases;

#include "03/code_021d1770.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_02024000.h"
#include "g2d_NSC_load.h"
#include "code_02022aa8.h"

void RequestBgTextCanvasUpload(void *canvas);
void ArrangeObjTextCanvasRange(ObjTextCanvas *canvas, s32 xPos, s32 yPos, OamRange *range, s32 f);
void ClearBgTextCanvas(BgTextCanvas *canvas, u32 color);
void DrawCharsCentered(void *canvas, s32 xPos, u32 yPos, u32 color, s32 cellWidth, u16 *text, s32 fontIndex);
void DrawCanvasChar(void *canvas, u32 xPos, u32 yPos, u32 color, u16 charCode, int fontIndex);
void ReleaseBgTextCanvasOfScreen(u32 index);
void ReleaseBgTextCanvas(BgTextCanvas *canvas);
void AdvanceBgTextCanvasUpload(u32 task, u8 *flag);
BgTextCanvas *InitBgTextCanvas(u32 screen, u32 fontIndex);
void DeleteObjTextCanvas(void *canvas);
ObjTextCanvas *CreateObjTextCanvas(u32 screen, u16 areaWidth, u16 areaHeight, s32 fromFront, u32 *entryCount,
                                   s32 fontIndex);
void ReleaseTextCanvases(void);
void InitTextCanvases(void);
