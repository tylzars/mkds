#include "Main/Unknown/code_020d4bf0.h"

#pragma thumb on

void func_020d4bf0(void) {
    data_0217b4f8.mUnk_50 = 1;
    data_0217b4f8.mUnk_54 = 0;
    if ((int) data_021759c0->mUnk_00c == 2) {
        *(u32 *) &data_0217b4f4 = ((u32) 0x00258000u);
        return;
    }
    *(u32 *) &data_0217b4f4 = ((u32) 0x0012c000u);
}

#pragma thumb off
