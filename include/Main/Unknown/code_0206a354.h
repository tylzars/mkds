#pragma once

#include "types.h"

typedef struct Kart Kart;

// Object read by func_0206b020: vectors at 0x04, 0x28, 0x34 and 0x40.
typedef struct Unk0206b020 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0x18];
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ Vec3 mUnk_40;
} Unk0206b020;

extern const s16 data_usa_02154a54[];
extern const s16 data_usa_021654c4;
extern const s32 data_usa_021654d0;
extern const s32 data_usa_021654d4;
extern const s32 data_usa_021654e0;
extern const s32 data_usa_021654e4;
extern const s32 data_usa_021654e8;
extern const s32 data_usa_021654f0;
extern const s32 data_usa_02165508;
extern const s32 data_usa_0216550c;
extern const Vec4 data_usa_0216556c;

void func_0206a354(Kart *p);
void func_0206a624(Kart *p);
void func_0206a784(Kart *p);
s32 func_0206a980(Kart *p, const Vec3 *a, s32 b);
void func_0206ac10(Kart *p);
void func_0206add0(Kart *p, const Vec3 *a, s32 b);
BOOL func_0206b020(Kart *p, Unk0206b020 *a);
void func_0206b16c(Kart *p);
void func_0206b358(Kart *p);
BOOL func_0206b4d0(Kart *p);
void func_0206b5b4(Kart *p);
void func_0206b914(Kart *p);
BOOL func_0206bab8(Kart *p);
void func_0206bb04(Kart *p);
void func_0206bbb4(Kart *p, int a, int b);
