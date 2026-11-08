#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020e516c.h"

// Second argument of InitItemBox: a Vec3 at 0x00 and halfwords at 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30 and 0x34.
typedef struct Unk020de6a8_1 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0x1a];
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[2];
    /* 34 */ s16 mUnk_34;
} Unk020de6a8_1;

// Object of 0x108 or more bytes handled by InitItemBox.
typedef struct ItemBox {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mBoxRotationIndex;
    /* 0a2 */ u16 mQuestionRotationIndex;
    /* 0a4 */ u16 mFramesSinceHit;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s16 mUnk_0b0;
    /* 0b2 */ u8 mUnk_0b2[2];
    /* 0b4 */ ShadowMatrix mUnk_0b4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec;
    /* 0f0 */ u16 mPolygonId;
    /* 0f2 */ u16 mUnk_0f2;
    /* 0f4 */ u16 mUnk_0f4;
    /* 0f6 */ u8 mUnk_0f6[2];
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ Vec3 *mUnk_0fc;
    /* 100 */ UnkFunc *mUnk_100;
    /* 104 */ void *mUnk_104;
    /* 108 */ GroupFollowerWithSpeeds mFollower;
} ItemBox;

void CreateBoxAndQuestion(void);
void InitItemBox(ItemBox *itemBox, Unk020de6a8_1 *row);
Unk020de390 *CreateEarthenPipeKindData(void);
Unk020de334 *CreateEarthenPipeDrawList(void);
Unk020de2d8 *CreateEarthenPipeUpdateList(void);
void SetupDrawEarthenPipe(void);
