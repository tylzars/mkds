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
#include "code_02023374.h"
#include "code_02149fe0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214b824.h"

#pragma optimize_for_size on

#pragma thumb on

void func_02036108(void *a) {
    void *h;
    u32 b;
    s32 j;
    s32 i;
    u16 v;

    func_02036438(a);
    data_02174e6c->mUnk_64c = 9;
    data_02174e6c->mUnk_634 = func_02047a28(data_021646e0);
    data_02174e6c->mUnk_000 = func_020b403c(0);
    b = G2S_GetBG1CharPtr();
    h = GetBmgEntry(data_02174e6c->mUnk_634, 0x79);
    NNS_G2dCharCanvasInitForBG(data_02174e6c->mUnk_004, (u8 *) b + 0x400, 0x20, 4, 4);
    func_020362c4(&data_02174e6c->mUnk_024, data_02174e6c->mUnk_004, data_02174e6c->mUnk_000, 1, 4);
    func_0203629c(&data_02174e6c->mUnk_024, 8, 0, 3, 0x209, h);
    for (i = 0x16; i < 0x18; i++) {
        for (j = 0; j < 0x20; j++) {
            v = (((j + i + 1) & 1) << 12) | 1;
            data_02174e6c->mUnk_034[j + (u32) i * 0x20] = v;
        }
    }
    DC_StoreRange(data_02174e6c->mUnk_034, 0x600);
    GXS_LoadBG3Scr(data_02174e6c->mUnk_034, 0, 0x600);
    func_02036264(data_02174e6c->mUnk_034, 0x600);
    for (i = 0x14; i < 0x16; i++) {
        for (j = 0; j < 0x20; j++) {
            data_02174e6c->mUnk_034[j + (u32) i * 0x20] = j + (u32) (i - 0x14) * 0x20 + 0x20;
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
