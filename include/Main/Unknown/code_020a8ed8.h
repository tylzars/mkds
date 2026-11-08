#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e516c.h"

// Object of kinds 0x1b0 and 0x1b3 (IronBall; kind 0x1b3 has only Init and Draw, no update or collision group), 0x134
// bytes: the shared MapObject part, a GroupFollower at 0xc4 and a ShadowMatrix at 0xe8.
typedef struct IronBall {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mRotateZAngle;
    /* 0a4 */ s32 mState1Timer;
    /* 0a8 */ s32 mTimer;
    /* 0ac */ s32 mNextStartLap;
    /* 0b0 */ s32 mPathSpeed;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mHeightOffset;
    /* 0c0 */ s32 mHeightSpeed;
    /* 0c4 */ GroupFollower mFollower;
    /* 0e8 */ ShadowMatrix mShadowMatrix;
    /* 11c */ Vec3 mUnk_11c;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mState;
} IronBall;

#include "Main/Unknown/code_020a826c.h" // Unk020a826c_a0

void func_020a8ed8(Unk020a826c_a0 *soundPart, Vec3 *position);
void *CreateIronBallUpdateList(void);
void *CreateIronBallDrawList(void);
void *CreateIronBallShadowDrawList(void);
void CreateIronBallKindData(void);
void UpdateIronBall(void *a, IronBall *ironBall); /* kind 0x1b0 only */
void InitIronBallObjects(MapObjectList *mapObjectList);
void DrawIronBallShadow(void *a, IronBall *ironBall, u32 c, u32 d);
unsigned int func_020a9cd0(unsigned int p0);
