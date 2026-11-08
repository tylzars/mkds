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

void AdvanceKartDriftCharge(Kart *kart);
void SetKartDriftCharge(Kart *kart, s32 charge);
void func_02068494(Kart *kart, s32 b, s32 c);
void func_02068640(Kart *kart, s32 b);
void func_020688a0(Kart *kart);
void func_02068a00(Kart *kart);
void func_02068a10(Kart *kart);
void func_02068a64(Kart *kart, s32 b, s32 c);
void func_02068b5c(Kart *kart);
void func_02068b98(Kart *kart);
