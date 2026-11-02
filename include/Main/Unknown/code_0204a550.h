#pragma once

#include "types.h"

// Object read at 0x00 and written at 0x04 by func_0204a598.
typedef struct Unk0204a598 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ s16 mUnk_04;
} Unk0204a598;

s32 func_0204a550(void *a);
void func_0204a598(Unk0204a598 *a);
void func_0204a5e8(void);
unsigned int func_0204a5f4(unsigned int p0);
