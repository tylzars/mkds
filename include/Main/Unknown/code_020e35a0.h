#pragma once

#include "types.h"

typedef struct Unk020e35a0 {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x4];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x8];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x94];
    /* ac */ u32 mUnk_ac;
} Unk020e35a0;

void func_020e35a0(Unk020e35a0 *p0);
