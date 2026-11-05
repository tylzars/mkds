#pragma once

#include "types.h"

typedef struct Sman Sman;
typedef struct Kart Kart;

typedef struct Unk0209188c {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk0209188c;

u8 func_020917d0(Sman *a, u32 b, unsigned char *c, u8 *d);
u8 func_02091828(Sman *a, Kart *b, u8 *c, u8 *d);
void func_0209188c(Unk0209188c *p0);
