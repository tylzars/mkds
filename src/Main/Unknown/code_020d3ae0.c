#include "Main/Unknown/code_020d3ae0.h"

#pragma thumb on

void func_020d3ae0(s32 param_1, Unk020e71a0 *param_2) {
    int v1;
    u32 v2;
    v1 = 0x2710;
    if (0x2710 <= param_1) {
        param_2->mUnk_02 = param_2->mUnk_02 | (*(u16 *) &data_021568e8);
        param_1 = (param_1 - v1) * 0x10000 >> 0x10;
    }
    v2 = func_020d2178((u32) param_1);
    param_2->mUnk_74 = v2;
}

#pragma thumb off
