#pragma once

#include "types.h"

typedef struct Unk021abca0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0x40];
} Unk021abca0;

void func_ov000_021abca0(void *f, const u8 *b, u32 c);
