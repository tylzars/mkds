#include "Main/Unknown/code_020d4bf0.h"

#pragma thumb on

void func_020d4bf0(void) {
    int v1;
    v1 = ((int) (u32) ((u8 *) &data_0217b4f8));
    *(u32 *) (((u32) (u32) ((u8 *) &data_0217b4f8)) + 0x50) = 1;
    *(u32 *) (v1 + 0x54) = 0;
    if ((int) data_021759c0->mUnk_00c == 2) {
        *(u32 *) &data_0217b4f4 = ((u32) 0x00258000u);
        return;
    }
    *(u32 *) &data_0217b4f4 = ((u32) 0x0012c000u);
}

#pragma thumb off
