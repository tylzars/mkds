#pragma once

#include "types.h"

typedef struct Unk020ec490 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ u8 mUnk_1c[0x74];
    /* 90 */ u16 mUnk_90;
    /* 92 */ u16 mUnk_92;
    /* 94 */ u8 mUnk_94[0xc];
    /* a0 */ s32 mUnk_a0;
    /* a4 */ u32 mUnk_a4;
    /* a8 */ u32 mUnk_a8;
    /* ac */ u16 mUnk_ac;
    /* ae */ u16 mUnk_ae;
} Unk020ec490;

void func_020ec490(Unk020ec490 *a);
