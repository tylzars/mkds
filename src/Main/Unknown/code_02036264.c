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
#include "code_02023374.h"
#include "code_02149fe0.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214b824.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

void func_02036264(void *a, u32 b) {
    func_02036278(a, 0, b);
}

void func_02036278(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    MemFillWordsByBlock(v, a, c);
}

u32 func_0203629c(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    return func_02024340(a, b, c, d, e, f);
}

void func_020362c4(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

#pragma thumb on

void func_020362dc(void *a) {
    void *h;
    u32 b;
    s32 j;
    s32 i;
    u16 v;

    func_02036438(a);
    data_02174e6c->mUnk_64c = 0;
    func_0204aa28(1);
    data_02174e6c->mUnk_638 = func_020d1630()->mUnk_20;
    data_02174e6c->mUnk_000 = (u8 *) func_020d1630() + 0x14;
    b = G2sBg1CntBits2To5Address();
    h = GetBmgEntry(data_02174e6c->mUnk_638, 1);
    func_02023408(data_02174e6c->mUnk_004, (u8 *) b + 0x400, 0x20, 4, 4);
    func_020362c4(&data_02174e6c->mUnk_024, data_02174e6c->mUnk_004, data_02174e6c->mUnk_000, 1, 4);
    func_0203629c(&data_02174e6c->mUnk_024, 0x80, 0, 3, 0x211, h);
    for (i = 7; i < 9; i++) {
        for (j = 0; j < 0x20; j++) {
            v = (((j + i + 1) & 1) << 12) | 1;
            data_02174e6c->mUnk_034[j + (u32) i * 0x20] = v;
            data_02174e6c->mUnk_034[j + ((u32) i + 7) * 0x20] = v;
        }
    }
    func_0200ee58(data_02174e6c->mUnk_034, 0x600);
    func_0214bb64(data_02174e6c->mUnk_034, 0, 0x600);
    func_02036264(data_02174e6c->mUnk_034, 0x600);
    for (i = 10; i < 14; i++) {
        for (j = 0; j < 0x20; j++) {
            data_02174e6c->mUnk_034[j + (u32) i * 0x20] = j + ((u32) i - 10) * 0x20 + 0x20;
        }
    }
    func_0200ee58(data_02174e6c->mUnk_034, 0x600);
    func_0214bd04(data_02174e6c->mUnk_034, 0, 0x600);
    func_02036258();
    FrmHeapShrinkInParent(data_02174e6c->mHeap);
}

#pragma thumb off
