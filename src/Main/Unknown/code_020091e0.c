#include "Main/Unknown/code_020091e0.h"

#pragma thumb on

void func_020091e0(void *p0, u32 p1) {
    *(u16 *) ((u8 *) (u32) p0 + 10) = (u16) 0x20u;
    *(u16 *) ((u8 *) (u32) p0 + 12) = (u16) p1;
    *(u16 *) ((u8 *) (u32) p0 + 14) = (u16) (((((p1) & (0xffff0000u))) >> 16));
    *(u16 *) ((u8 *) (u32) p0 + 16) =
        (u16) (((u32) * (const u16 *) ((u8 *) (u32) (((((p0) + (0x0u))) + (0x48u))) + 0)));
}

#pragma thumb off
