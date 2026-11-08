#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_0201c528.h" // Unk0201ca6c
#include "01/code_0219b250.h"
#include "Main/Unknown/code_02093ff0.h" // TeresaWobble

// Object behind gTrophy (a 0x124-byte allocation).
typedef struct Trophy {
    /* 000 */ u16 mModelIndex;
    /* 002 */ u16 mRankIndex;
    /* 004 */ u16 mRotateYAngle;
    /* 008 */ TeresaWobble mRotateZWobble;
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
