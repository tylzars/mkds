#pragma once

#include "types.h"

typedef struct Unk020e49c0 {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x4];
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0x4a];
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x50];
    /* b8 */ u32 mUnk_b8;
    /* bc */ u8 mUnk_bc[0x4];
    /* c0 */ u32 mUnk_c0;
} Unk020e49c0;

void EnterPukupukuState3(Unk020e49c0 *p0);
