#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0, Unk020e6fd4

// Element of 0x10 bytes: a position, then two halfwords.
typedef struct Unk0209df84_c4 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0209df84_c4;

// Object of func_0209df84: after the shared part, the counts at 0xa0 and 0xa2, a grid of elements from 0xc4 (rows of
// 0x140 bytes, 0xa0 rows of 0xa2 elements) and the words from 0x19c4.
typedef struct Unk0209df84 {
    /* 0000 */ Unk020e71a0 mUnk_00;
    /* 00a0 */ u16 mUnk_a0;
    /* 00a2 */ u16 mUnk_a2;
    /* 00a4 */ u16 mUnk_a4;
    /* 00a6 */ u8 mUnk_a6[2];
    /* 00a8 */ s32 mUnk_a8;
    /* 00ac */ s32 mUnk_ac;
    /* 00b0 */ u16 mUnk_b0;
    /* 00b2 */ u16 mUnk_b2;
    /* 00b4 */ Vec3 mUnk_b4;
    /* 00c0 */ u8 mUnk_c0[2];
    /* 00c2 */ u16 mUnk_c2;
    /* 00c4 */ Unk0209df84_c4 mUnk_c4[20][20];
    /* 19c4 */ s32 mUnk_19c4[8];
    /* 19e4 */ s32 mUnk_19e4;
} Unk0209df84;

// Object given to func_0209e950, which sets the word at 0x1c.
typedef struct Unk0209e950 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk0209e950;

u32 func_0209df00(void);
u32 func_0209df20(void);
void func_0209df44(void);
void func_0209df84(void *a, Unk0209df84 *b);
void func_0209e310(Unk020e6fd4 *p);
void func_0209e508(void *a, Unk0209df84 *b);
void func_0209e938(void *a);
void func_0209e950(Unk0209e950 *a);
BOOL func_0209e988(Unk0209df84 *a, Vec3 *b, s32 c);
u8 func_0209ea10(Unk0209df84 *a, Unk0206bcb0 *b, u8 *c, u8 *d);
void func_0209ea90(Unk0209df84 *a);
u32 func_0209eb04(void);
