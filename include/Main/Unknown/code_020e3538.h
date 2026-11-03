#pragma once

#include "types.h"

typedef struct Unk020e3538 {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x4];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x8];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x94];
    /* ac */ u32 mUnk_ac;
    /* b0 */ u8 mUnk_b0[0x8];
    /* b8 */ u16 mUnk_b8;
} Unk020e3538;

void func_020e3538(Unk020e3538 *p0);
