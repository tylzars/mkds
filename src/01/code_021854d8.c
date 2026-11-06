#include "01/code_021854d8.h"
#include "registers.h"

#pragma thumb off

void func_ov001_021854f4(int a) {
    (*(u32 *) 0x4000000u) = (*(u32 *) 0x4000000u) & 0xffffe0ff | a << 8;
    return;
}

void func_ov001_021854d8(int a) {
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff | a << 8;
    return;
}

#pragma thumb on
