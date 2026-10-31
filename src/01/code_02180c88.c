#include "01/code_02180c88.h"

#pragma thumb off

u32 func_ov001_02180ca4(void) {
    return ((u32) data_021755a0);
}

void func_ov001_02180c88(u32 p0) {
    *(u32 *) ((u8 *) (u32) (p0) + 0) = (u32) 0x1000u;
    *(u32 *) ((u8 *) (u32) (p0) + 4) = (u32) 0x0u;
    *(u32 *) ((u8 *) (u32) (p0) + 8) = (u32) 0x0u;
    *(u32 *) ((u8 *) (u32) (p0) + 12) = (u32) 0x1000u;
}

#pragma thumb on
