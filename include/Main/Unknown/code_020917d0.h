#pragma once

#include "types.h"

typedef struct Unk020912a0 Unk020912a0;
typedef struct Unk0206bcb0 Unk0206bcb0;

typedef struct Unk0209188c {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk0209188c;

u8 func_020917d0(int a, u32 b, unsigned char *c, u8 *d);
u8 func_02091828(Unk020912a0 *a, Unk0206bcb0 *b, u8 *c, u8 *d);
void func_0209188c(Unk0209188c *p0);
