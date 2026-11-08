#include "Main/Unknown/code_02036264.h"
#include "Main/Unknown/code_02035d18.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036258.h"
#include "Main/Unknown/code_02036438.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "code_02149fe0.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214b824.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

#pragma thumb on

void SetupWLMenuMBChildMessage(void *heap) {
    void *text;
    u32 charBase;
    s32 column;
    s32 row;
    u16 entry;

    InitWLMenuMessage(heap);
    gWLMenuMessage->mState = 0;
    func_0204aa28(1);
    gWLMenuMessage->mMBChildMessages = func_020d1630()->mUnk_20;
    gWLMenuMessage->mFont = (u8 *) func_020d1630() + 0x14;
    charBase = G2S_GetBG1CharPtr();
    text = GetBmgEntry(gWLMenuMessage->mMBChildMessages, 1);
    NNS_G2dCharCanvasInitForBG(gWLMenuMessage->mCharCanvas, (u8 *) charBase + 0x400, 0x20, 4, 4);
    func_020362c4(&gWLMenuMessage->mTextCanvas, gWLMenuMessage->mCharCanvas, gWLMenuMessage->mFont, 1, 4);
    func_0203629c(&gWLMenuMessage->mTextCanvas, 0x80, 0, 3, 0x211, text);
    for (row = 7; row < 9; row++) {
        for (column = 0; column < 0x20; column++) {
            entry = (((column + row + 1) & 1) << 12) | 1;
            gWLMenuMessage->mScreenMap[column + row * 0x20] = entry;
            gWLMenuMessage->mScreenMap[column + (row + 7) * 0x20] = entry;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG3Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    func_02036264(gWLMenuMessage->mScreenMap, 0x600);
    for (row = 10; row < 14; row++) {
        for (column = 0; column < 0x20; column++) {
            gWLMenuMessage->mScreenMap[column + row * 0x20] = column + (row - 10) * 0x20 + 0x20;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG1Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    func_02036258();
    FrmHeapShrinkInParent(gWLMenuMessage->mHeap);
}

#pragma thumb off

void func_020362c4(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 func_0203629c(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

void func_02036278(void *dest, u32 fillValue, u32 size) {
    volatile u32 fillData = fillValue;
    MIi_CpuClearFast(fillData, dest, size);
}

void func_02036264(void *dest, u32 size) {
    func_02036278(dest, 0, size);
}
