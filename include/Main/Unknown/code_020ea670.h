#pragma once

#include "types.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020ebef8.h"

// First argument of func_020ea670, func_020ea740, func_020ea7cc and func_020ea8a8.
typedef struct Unk020ea670 {
    /* 000 */ void *mUnk_000;
    /* 004 */ Unk0201290c *mUnk_004;
} Unk020ea670;

extern Unk020ea670 *gWoodbox1;

// First argument of func_020ea868.
typedef struct Unk020ea868 {
    /* 000 */ u8 mUnk_000[0x6e];
    /* 06e */ u16 mUnk_06e;
} Unk020ea868;

// Second argument of func_020eb498, func_020eb760 and func_020eb7e0.
typedef struct Unk020eb498 {
    /* 000 */ Vec3 mUnk_000;
    /* 00c */ u8 mUnk_00c[4];
    /* 010 */ s32 mUnk_010;
    /* 014 */ u8 mUnk_014[0x14];
    /* 028 */ s16 mUnk_028;
    /* 02a */ s16 mUnk_02a;
    /* 02c */ u8 mUnk_02c[0x30];
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ u8 mUnk_068[0xc];
    /* 074 */ u16 mUnk_074;
    /* 076 */ u8 mUnk_076[0x2e];
    /* 0a4 */ Vec3 mUnk_0a4;
    /* 0b0 */ u8 mUnk_0b0[0x1ec];
    /* 29c */ s32 mUnk_29c;
    /* 2a0 */ u8 mUnk_2a0[4];
    /* 2a4 */ s32 mUnk_2a4;
} Unk020eb498;

// Objects read by func_020ea670.
typedef struct Unk020ea670_08 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mUnk_008;
} Unk020ea670_08;

typedef struct Unk020ea670_0a {
    /* 000 */ u8 mUnk_000[10];
    /* 00a */ u16 mUnk_00a;
} Unk020ea670_0a;

typedef struct Unk020ea670_0c {
    /* 000 */ u8 mUnk_000[12];
    /* 00c */ u32 mUnk_00c;
} Unk020ea670_0c;

void func_020ea670(Unk020ea670 *param_1, s32 param_2);
void func_020ea740(Unk020ea670 *param_1, s32 param_2);
void func_020ea7cc(Unk020ea670 *param_1, s32 param_2);
void func_020ea84c(void);
void func_020ea868(Unk020ea868 *param_1, void *param_2, void *param_3, u32 param_4);
void func_020ea8a8(Unk020ea670 *param_1, void *param_2, void *param_3, s32 param_4);
void func_020ea94c(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5, Vec3 *param_6);
void func_020eaa14(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5, Vec3 *param_6);
void func_020eac20(Vec3 *param_1, s32 param_2);
void func_020eacc0(Vec3 *param_1, s32 param_2, Vec3 *param_3, Vec3 *param_4);
s32 func_020ead80(Vec3 *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7,
                  Vec3 *param_8);
s32 func_020eafc4(Vec3 *param_1, Vec3 *param_2, Vec3 *param_3, Vec3 *param_4, Vec3 *param_5, s32 param_6,
                  Vec3 *param_7);
void func_020eb2a0(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, Vec3 *param_5);
void func_020eb3f0(Vec3 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4);
void func_020eb498(Unk020ebef8 *param_1, Unk020eb498 *param_2);
void func_020eb720(void);
void CreateWoodbox1(void);
u32 func_020eb760(Unk020ebef8 *param_1, Unk020eb498 *param_2, u8 *param_3, u8 *param_4);
u32 func_020eb7e0(Unk020ebef8 *param_1, Unk020eb498 *param_2, u8 *param_3, u8 *param_4);
void func_020eb8f8(Unk020ebef8 *param_1);
void func_020ebab0(Unk020ebef8 *param_1);
void func_020ebb04(Unk020ebef8 *param_1);
BOOL func_020ebc2c(Unk020ebef8 *param_1);
void func_020ebe68(Unk020ebef8 *param_1);
