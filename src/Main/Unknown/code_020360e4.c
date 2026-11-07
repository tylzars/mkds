#include "Main/Unknown/code_020360e4.h"
#include "Main/Unknown/code_02035d18.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036258.h"
#include "Main/Unknown/code_02036264.h"
#include "Main/Unknown/code_02036438.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "code_02149fe0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214b824.h"

#pragma optimize_for_size on

#pragma thumb on

void func_02036108(void *a) {
    void *text;
    u32 charBase;
    s32 column;
    s32 row;
    u16 entry;

    func_02036438(a);
    data_02174e6c->mState = 9;
    data_02174e6c->mUnk_634 = FindFileInLoadedArchives(data_021646e0);
    data_02174e6c->mUnk_000 = func_020b403c(0);
    charBase = G2S_GetBG1CharPtr();
    text = GetBmgEntry(data_02174e6c->mUnk_634, 0x79);
    NNS_G2dCharCanvasInitForBG(data_02174e6c->mUnk_004, (u8 *) charBase + 0x400, 0x20, 4, 4);
    func_020362c4(&data_02174e6c->mUnk_024, data_02174e6c->mUnk_004, data_02174e6c->mUnk_000, 1, 4);
    func_0203629c(&data_02174e6c->mUnk_024, 8, 0, 3, 0x209, text);
    for (row = 0x16; row < 0x18; row++) {
        for (column = 0; column < 0x20; column++) {
            entry = (((column + row + 1) & 1) << 12) | 1;
            data_02174e6c->mUnk_034[column + row * 0x20] = entry;
        }
    }
    DC_StoreRange(data_02174e6c->mUnk_034, 0x600);
    GXS_LoadBG3Scr(data_02174e6c->mUnk_034, 0, 0x600);
    func_02036264(data_02174e6c->mUnk_034, 0x600);
    for (row = 0x14; row < 0x16; row++) {
        for (column = 0; column < 0x20; column++) {
            data_02174e6c->mUnk_034[column + row * 0x20] = column + (row - 0x14) * 0x20 + 0x20;
        }
    }
    DC_StoreRange(data_02174e6c->mUnk_034, 0x600);
    GXS_LoadBG1Scr(data_02174e6c->mUnk_034, 0, 0x600);
    if (func_02035e44() != 0) {
        func_02036258();
    }
    FrmHeapShrinkInParent(data_02174e6c->mHeap);
}

#pragma thumb off

u32 func_020360e4(void) {
    return (data_0217aa00->mUnk_0454 & 0x40) != 0;
}
