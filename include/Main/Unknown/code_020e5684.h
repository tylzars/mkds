#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Second argument of func_020e5684: a vector at 0x0c, halfwords from 0x28.
typedef struct Unk020e5684 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[0x10];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
} Unk020e5684;

void CreateSecondHand(void);

typedef struct Unk020e43a8 Unk020e43a8;

// 0x28-byte object func_020e59e4 loads from data_021590ec.
typedef struct Unk020e59e4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
} Unk020e59e4;

// 0x2c-byte object func_020e5a40 loads from data_02159114.
typedef struct Unk020e5a40 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
} Unk020e5a40;

// 0x40-byte object func_020e5a9c loads from data_02159140.
typedef struct Unk020e5a9c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk020e5a9c;

void CreateObPakkunSf(void);

extern Unk020e59e4 *data_0217b81c;
extern Unk020e5a40 *data_0217b824;
extern Unk020e59e4 *data_0217b828;
extern Unk020e5a40 *data_0217b82c;
extern Unk020e59e4 *data_0217b834;
extern Unk020e5a40 *data_0217b840;

void func_020e5684(Unk020e43a8 *p, Unk020e5684 *q);
void func_020e57a0(Unk020e43a8 *p, Vec3 *a, s32 b, Vec3 *c);
void func_020e595c(u32 a, Unk020e43a8 *p);
void func_020e5990(u32 a, Unk020e43a8 *p, u32 b, u32 c);
Unk020e59e4 *func_020e59e4(void);
Unk020e5a40 *func_020e5a40(void);
Unk020e5a9c *func_020e5a9c(void);
void func_020e5aec(Unk020e43a8 *p);
