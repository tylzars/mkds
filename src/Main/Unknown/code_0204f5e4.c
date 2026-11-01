#include "Main/Unknown/code_0204f5e4.h"

#pragma thumb on

void func_0204f5e4(void) {
    int v1;
    Unk0217aa00_16a0_view *v2;
    Unk0217aa00_16a0 *v3;
    u32 v4;
    u32 v5;
    v4 = ((int) 0xe0000000u);
    v5 = ((u32) 0xdfffffffu);
    v2 = &data_0217aa00->mUnk_16a0_view;
    v1 = 0;
    v3 = v2->mUnk_000;
    do {
        v3->mUnk_34 = 0;
        v3->mUnk_74 = 0;
        v3->mUnk_78 = 0;
        v3->mUnk_84 = v3->mUnk_84 & v5;
        v3->mUnk_84 = v3->mUnk_84 & v4;
        v3 = v3 + 1;
        v1 = v1 + 1;
    } while (v1 < 0xc);
    v2->mUnk_668 = 0xc;
}

#pragma thumb off
