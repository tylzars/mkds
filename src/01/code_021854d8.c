#include "01/code_021854d8.h"
#include "registers.h"

#pragma thumb off

void func_ov001_021854f4(int bits) {
    (*(u32 *) 0x4000000u) = (*(u32 *) 0x4000000u) & 0xffffe0ff | bits << 8;
}

void func_ov001_021854d8(int bits) {
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff | bits << 8;
}

#pragma thumb on
