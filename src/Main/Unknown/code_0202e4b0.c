#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_0202e680.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202ecd4.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"

#pragma optimize_for_size on

#pragma thumb on

void func_0202e530(void *a, s32 b, const void *c, u16 d, u16 e, s32 f, Unk02124b1c *g, void *h, const void *i, s32 j,
                   s32 k, s32 l, s32 m, void (*n)(int a, int b, int c, int d)) {
    s32 i0;
    gScrollList = HeapAlloc(a, 0x674);
    func_0202e68c(gScrollList, 0x674);
    gScrollList->mUnk_000 = b;
    b = b * 2;
    gScrollList->mUnk_004 = HeapAllocAligned(a, b, 0x20);
    func_0202e680(c, gScrollList->mUnk_004, b);
    func_0202e680(i, gScrollList->mUnk_058, 0x600);
    gScrollList->mUnk_02c = d;
    gScrollList->mUnk_02e = e;
    gScrollList->mUnk_030 = f;
    gScrollList->mUnk_008 = g;
    gScrollList->mRowCount = m;
    gScrollList->mUnk_028 = n;
    gScrollList->mUnk_00c = h;
    gScrollList->mUnk_010 = j;
    gScrollList->mUnk_014 = k;
    gScrollList->mUnk_018 = l;
    gScrollList->mEnabled = 1;
    gScrollList->mUnk_01c = -1;
    gScrollList->mUnk_020 = gScrollList->mUnk_01c;
    func_0202edd0();
    func_0202f120(0, -1, -1, GetScrollListSelectedSlot());
    for (i0 = 0; i0 < 6 && i0 < gScrollList->mRowCount; i0++) {
        func_0202f120(1, i0 + 1, i0, -1);
    }
    func_0202ee3c(0, 0);
    func_0202ee3c(6, 0);
    for (i0 = gScrollList->mRowCount; i0 < 5; i0++) {
        func_0202ee3c(i0 + 1, 0);
    }
    gScrollList->mUnk_008[gScrollList->mUnk_02e].mUnk_00 = gScrollList->mRowCount > 5;
    if (gScrollList->mRowCount == 0) {
        gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 0;
    }
    gScrollList->mUnk_048 = 0xf;
}

void func_0202e4b0(void) {
    gScrollList->mPickStarted = 0;
    gScrollList->mPickFinished = gScrollList->mPickStarted;
    func_0202eec0();
    func_0202ed04();
    switch (gScrollList->mState) {
        case 0:
            func_0202e9f0();
            break;
        case 1:
            func_0202e9ac();
            break;
        case 2:
            func_0202e968();
            break;
        case 3:
            func_0202e84c();
            break;
        case 4:
            func_0202e72c();
            break;
        case 5:
            func_0202e6c4();
            break;
    }
    func_0202ee88();
}

#pragma thumb off
