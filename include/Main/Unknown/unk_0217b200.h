#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_0201c528.h" // Unk0201ca6c
#include "01/code_0219b250.h"

// The 0x20 bytes at 0x08 of the object behind gTrophy.
typedef struct Unk0217b200_08 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0217b200_08;

// Object behind gTrophy (a 0x124-byte allocation).
typedef struct Trophy {
    /* 000 */ u16 mModelIndex;
    /* 002 */ u16 mRankIndex;
    /* 004 */ u16 mRotateYAngle;
    /* 008 */ Unk0217b200_08 mRotateZWobble;
    /* 028 */ u8 mModel[0x6c];
    /* 094 */ ModelAnimationView mModelAnimation;
    /* 0b4 */ u8 mUnk_0b4[0x18];
    /* 0cc */ MtxFx43 mEffectMatrix;
    /* 0fc */ s16 mLight0X;
    /* 0fe */ s16 mLight1X;
    /* 100 */ s16 mLight0Y;
    /* 102 */ s16 mLight1Y;
    /* 104 */ s16 mLight0Z;
    /* 106 */ s16 mLight1Z;
    /* 108 */ Vec3 mEffectOffset;
    /* 114 */ s32 mUnk_114;
    /* 118 */ Unk0201ca6c *mEffect0;
    /* 11c */ Unk0201ca6c *mEffect4;
    /* 120 */ Unk0201ca6c *mEffect5;
} Trophy;

extern Trophy *gTrophy;
