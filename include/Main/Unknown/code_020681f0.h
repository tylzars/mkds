#pragma once

#include "types.h"

typedef struct Kart Kart;

// Stack frame of func_02068494 from its stack offset 0: a halfword and four vectors.
typedef struct Unk02068494 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ Vec3 mUnk_28;
} Unk02068494;

void AdvanceKartDriftCharge(Kart *a);
void SetKartDriftCharge(Kart *a, s32 b);
void func_02068494(Kart *a, s32 b, s32 c);
void func_02068640(Kart *a, s32 b);
void func_020688a0(Kart *a);
void func_02068a00(Kart *a);
void func_02068a10(Kart *a);
void func_02068a64(Kart *a, s32 b, s32 c);
void func_02068b5c(Kart *a);
void func_02068b98(Kart *a);
