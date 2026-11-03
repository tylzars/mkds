#pragma once

#include "types.h"

typedef struct Unk0206bcb0 Unk0206bcb0;

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

void func_0206a354(Unk0206bcb0 *p);
void func_0206a624(Unk0206bcb0 *p);
void func_0206a784(Unk0206bcb0 *p);
s32 func_0206a980(Unk0206bcb0 *p, const Vec3 *a, s32 b);
void func_0206ac10(Unk0206bcb0 *p);
void func_0206add0(Unk0206bcb0 *p, const Vec3 *a, s32 b);
BOOL func_0206b020(Unk0206bcb0 *p, Unk0206b020 *a);
void func_0206b16c(Unk0206bcb0 *p);
void func_0206b358(Unk0206bcb0 *p);
BOOL func_0206b4d0(Unk0206bcb0 *p);
void func_0206b5b4(Unk0206bcb0 *p);
void func_0206b914(Unk0206bcb0 *p);
BOOL func_0206bab8(Unk0206bcb0 *p);
void func_0206bb04(Unk0206bcb0 *p);
void func_0206bbb4(Unk0206bcb0 *p, int a, int b);
