#pragma once

#include "types.h"

typedef struct Unk0209188c {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk0209188c;

#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0206bcb0.h"

u8 func_020917d0(int param_1, u32 param_2, unsigned char *param_3, u8 *param_4);
u8 func_02091828(Unk020912a0 *a, Unk0206bcb0 *b, u8 *c, u8 *d);
void func_0209188c(Unk0209188c *p0);
