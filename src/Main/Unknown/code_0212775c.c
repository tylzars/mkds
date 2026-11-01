#include "Main/Unknown/code_0212775c.h"

#pragma thumb on

s32 func_02127794(void) {
    if ((int) data_0217d3f4->mUnk_20 != 0) {
        return 0xffffffff;
    }
    return data_0217d3f4->mUnk_18;
}

u32 func_02127788(void) {
    return ((u32) *
            (const u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_0217d3f4))) + 0))) + 28));
}

void func_0212775c(int param_1, u32 param_2) {
    if (param_1 == -1) {
        *(u32 *) ((int) data_0217d3f4 + 0x8b0) = param_2;
        return;
    }
    *(u32 *) ((int) data_0217d3f4 + param_1 * 4 + 0x8a8) = param_2;
}

#pragma thumb off
