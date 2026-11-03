#pragma once

#include "types.h"

// Three words: the code multiplies the first by 60, adds the second, multiplies by 1000 and adds the third.
typedef struct Unk020b1bf8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk020b1bf8;

// Four bytes: a halfword and two bytes.
typedef struct Unk020b1a34_0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020b1a34_0c;

s32 func_020b1bf8(Unk020b1bf8 *a, Unk020b1bf8 *b, Unk020b1a34_0c *c);
void func_020b1a34(void);
