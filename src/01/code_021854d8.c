#include "01/code_021854d8.h"

#pragma thumb off

void func_ov001_021854f4(int a) {
    (*(u32 *) (u32) 0x4000000u) = (*(u32 *) (u32) 0x4000000u) & 0xffffe0ff | a << 8;
    return;
}

void func_ov001_021854d8(int a) {
    *((u32 *) 0x04001000u) = (*(u32 *) ((u32) ((u32 *) 0x04001000u))) & 0xffffe0ff | a << 8;
    return;
}

#pragma thumb on
