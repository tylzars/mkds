#pragma once

#include "types.h"

typedef struct Unk0206bcb0 Unk0206bcb0;

// Stack frame of func_02068494 from its stack offset 0: a halfword and four vectors.
typedef struct Unk02068494 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ Vec3 mUnk_28;
} Unk02068494;

void func_020681f0(Unk0206bcb0 *a);
void func_02068440(Unk0206bcb0 *a, s32 b);
void func_02068494(Unk0206bcb0 *a, s32 b, s32 c);
void func_02068640(Unk0206bcb0 *a, s32 b);
void func_020688a0(Unk0206bcb0 *a);
void func_02068a00(Unk0206bcb0 *a);
void func_02068a10(Unk0206bcb0 *a);
void func_02068a64(Unk0206bcb0 *a, s32 b, s32 c);
void func_02068b5c(Unk0206bcb0 *a);
void func_02068b98(Unk0206bcb0 *a);

void func_020757d8(void);
