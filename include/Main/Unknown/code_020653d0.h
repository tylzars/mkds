#pragma once

#include "types.h"

typedef struct Unk0206bcb0 Unk0206bcb0;

// Second parameter of func_020653d0.
typedef struct Unk020653d0 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk020653d0;

void func_020653d0(Unk0206bcb0 *p, Unk020653d0 *a, s32 n);
