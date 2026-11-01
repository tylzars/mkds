#include "Main/Unknown/code_02006ffc.h"

#pragma thumb on

void func_02007008(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) (&data_02161780))) + 0) = p0;
}

u32 func_02006ffc(void) {
    return ((u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_02161780))) + 0));
}

#pragma thumb off
