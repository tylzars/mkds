#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_0202e680.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202ecd4.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"

#pragma optimize_for_size on

#pragma thumb on

void func_0202e4b0(void) {
    data_02174e48->mUnk_668 = 0;
    data_02174e48->mUnk_664 = data_02174e48->mUnk_668;
    func_0202eec0();
    func_0202ed04();
    switch (data_02174e48->mUnk_670) {
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

void func_0202e530(void *a, s32 b, const void *c, u16 d, u16 e, s32 f, Unk02124b1c *g, void *h, const void *i, s32 j,
                   s32 k, s32 l, s32 m, void (*n)(int a, int b, int c, int d)) {
    s32 i0;
    data_02174e48 = func_02036bec(a, 0x674);
    func_0202e68c(data_02174e48, 0x674);
    data_02174e48->mUnk_000 = b;
    b = b * 2;
    data_02174e48->mUnk_004 = func_02036b74(a, b, 0x20);
    func_0202e680(c, data_02174e48->mUnk_004, b);
    func_0202e680(i, data_02174e48->mUnk_058, 0x600);
    data_02174e48->mUnk_02c = d;
    data_02174e48->mUnk_02e = e;
    data_02174e48->mUnk_030 = f;
    data_02174e48->mUnk_008 = g;
    data_02174e48->mUnk_034 = m;
    data_02174e48->mUnk_028 = n;
    data_02174e48->mUnk_00c = h;
    data_02174e48->mUnk_010 = j;
    data_02174e48->mUnk_014 = k;
    data_02174e48->mUnk_018 = l;
    data_02174e48->mUnk_660 = 1;
    data_02174e48->mUnk_01c = -1;
    data_02174e48->mUnk_020 = data_02174e48->mUnk_01c;
    func_0202edd0();
    func_0202f120(0, -1, -1, func_0202edfc());
    for (i0 = 0; i0 < 6 && i0 < data_02174e48->mUnk_034; i0++) {
        func_0202f120(1, i0 + 1, i0, -1);
    }
    func_0202ee3c(0, 0);
    func_0202ee3c(6, 0);
    for (i0 = data_02174e48->mUnk_034; i0 < 5; i0++) {
        func_0202ee3c(i0 + 1, 0);
    }
    data_02174e48->mUnk_008[data_02174e48->mUnk_02e].mUnk_00 = data_02174e48->mUnk_034 > 5;
    if (data_02174e48->mUnk_034 == 0) {
        data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 0;
    }
    data_02174e48->mUnk_048 = 0xf;
}

#pragma thumb off
