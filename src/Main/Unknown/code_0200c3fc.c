#include "Main/Unknown/code_0200c3fc.h"

#pragma thumb on

void func_0200c3fc(s32 param_1) {
    s32 i;

    if (data_0216fdf4 != 0) {
        i = param_1 - 1;
        func_0214d168(&data_0216fdf4->mUnk_000[i * 0x20], 0, 0x1e);
        data_0216fdf4->mUnk_1e0[i] = 0;
    }
}

#pragma thumb off
