#pragma once

#include "types.h"

typedef struct Kart Kart;

// Six words of a table written by func_01ff9598 and the functions after it, at 0x00, 0x04, 0x10, 0x14, 0x30 and 0x34.
typedef struct Unk01ff9598_A {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x18];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk01ff9598_A;

// Read by func_01ff9598, func_01ff9684, func_01ff96cc, func_01ff974c and func_01ff9828.
typedef struct Unk01ff9598 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s16 mUnk_20;
    /* 22 */ s16 mUnk_22;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
} Unk01ff9598;

// Object with a flag word at 0x00, vectors at 0x04 and 0x10, and blocks at 0x28 and 0x4c passed to func_01ff9048.
typedef struct Unk01ff9940 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ u8 mUnk_28[0x24];
    /* 4c */ u8 mUnk_4c[0xc];
} Unk01ff9940;

typedef struct Unk01ff9940_B {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
} Unk01ff9940_B;

typedef struct Unk01ff9940_C {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk01ff9940_C;

void func_01ff9598(Unk01ff9598_A *a, Unk01ff9598 *b);
void func_01ff9684(Unk01ff9598_A *a, Unk01ff9598 *b);
void func_01ff96cc(Unk01ff9598_A *a, Unk01ff9598 *b);
void func_01ff974c(Unk01ff9598_A *a, Unk01ff9598 *b);
void func_01ff9828(Unk01ff9598_A *a, Unk01ff9598 *b);
void func_01ff9940(Unk01ff9940 *a, Unk01ff9940_B *b, Unk01ff9940_C *c, u32 d);
void func_01ff9a94(Unk01ff9940 *a);
void func_01ff9b70(Kart *p);
void func_01ff9c40(Kart *p);
void func_01ff9c9c(Kart *p, u32 a);
void func_01ff9cb0(Kart *p);
void func_01ff9d18(Kart *p);
void func_01ff9e5c(Kart *p);
void func_01ff9f60(Kart *p, Vec3 *a);
void func_01ffa0c4(Kart *p);
void func_01ffa11c(Kart *p, const Vec3 *a);
BOOL func_01ffa1f8(Kart *p);
void func_01ffa350(Kart *p, u32 a);
BOOL func_01ffa380(Kart *p, u32 a, Vec3 *b);
BOOL func_01ffa41c(Kart *p, u32 a, Vec3 *b);
BOOL func_01ffa478(Kart *p, u32 a, Vec3 *b);
