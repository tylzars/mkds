#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Second argument of InitSecondHand: a vector at 0x0c, halfwords from 0x28.
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

// 0x28-byte object CreateSecondHandUpdateList loads from data_021590ec.
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

// 0x2c-byte object CreateSecondHandDrawList loads from data_02159114.
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

// 0x40-byte object CreateSecondHandKindData loads from data_02159140.
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

void InitSecondHand(Unk020e43a8 *secondHand, Unk020e5684 *courseRow);
void ComputeSphereHitOnSecondHand(Unk020e43a8 *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void UpdateSecondHand(u32 a, Unk020e43a8 *secondHand);
void DrawSecondHand(u32 a, Unk020e43a8 *secondHand, u32 b, u32 alpha);
Unk020e59e4 *CreateSecondHandUpdateList(void);
Unk020e5a40 *CreateSecondHandDrawList(void);
Unk020e5a9c *CreateSecondHandKindData(void);
void InitObPakkunSf(Unk020e43a8 *obPakkunSf);
