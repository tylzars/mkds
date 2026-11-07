#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d849c.h"

// 0x1c-byte element of the table behind gCollisionSlots.
typedef struct CollisionSlot {
    /* 00 */ s16 mHighEndIndex;
    /* 02 */ s16 mLowEndIndex;
    /* 04 */ s32 mHighZ;
    /* 08 */ s32 mLowZ;
    /* 0c */ Vec3 *mCenterPos;
    /* 10 */ s32 mRadius;
    /* 14 */ u16 mFlags;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ void *mObject;
} CollisionSlot;

// Four-byte element of the tables behind gCollisionSlotHighEnds and gCollisionSlotLowEnds.
typedef struct CollisionSlotEnd {
    /* 00 */ u32 mOtherEndIndex : 8;
// Low-end list: the slot index. High-end list: the lowest low-end index the search scans down to.
    /* 01 */ u32 mUnk_01 : 8;
    /* 02 */ s32 mEndX : 16;
} CollisionSlotEnd;

u32 FreeCollisionSlot(s32 a);
s32 CreateCollisionSlot(Vec3 *a, s32 b, s32 c, void *d);
// Object behind the pointer func_020d5a68 and func_020d5aa0 read: a pointer at 0x00 and a word at 0x04.
typedef struct Unk020d5a68 {
    /* 00 */ Unk020e005c *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020d5a68;

// Element object of InitRock: MapObject and the words and halfword used after it.
typedef struct Unk020d5bf0 {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mStartY;
    /* 0a4 */ Unk020d84e4 mUnk_0a4;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ Vec3 mBasePos;
    /* 0f0 */ Vec3 *mSideVectors;
    /* 0f4 */ BOOL mBounceSide;
    /* 0f8 */ s32 mOffsetVelocityX;
    /* 0fc */ s32 mOffsetVelocityZ;
    /* 100 */ s32 mOffsetX;
    /* 104 */ s32 mOffsetZ;
    /* 108 */ u16 mSinceGroundFrames;
    /* 10a */ u8 mUnk_10a[2];
    /* 10c */ s32 mStartScale;
    /* 110 */ s32 mScalePerFrame;
    /* 114 */ s32 mScaleLimit;
    /* 118 */ s32 mBottomOffsetReciprocal;
    /* 11c */ s32 mBottomOffset;
    /* 120 */ s32 mBounceRatio;
} Unk020d5bf0;

// Twelve bytes func_020d634c fills: a word and three halfwords.
typedef struct Unk020d634c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
} Unk020d634c;

void UpdateRock(void *a, Unk020d5bf0 *p);
void func_020d634c(Unk020d5bf0 *p, s32 b);
u8 func_020d5f8c(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d);
u8 func_020d5f64(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d);
void ResetRock(Unk020d5bf0 *p);
void InitRock(Unk020d5bf0 *p, struct CourseMapRow *q);
void CreateNsbmdAndShadowNsbmd(void *a, const char *name, const char *shadowName);
void CreateRock(void *a);
void CreateRock2(void *a);
void LoadCourseCollisionData(Unk0217b614 *p, Unk0217b614 *a);
void InitCourseCollision(void);
void func_020d5aa0(void *a, u32 b, Unk020e04b0 *c, Vec3 *d, Vec3 *e);
BOOL func_020d5a68(void *a, u32 b, Unk020e04b0 *c);
u16 PickCollisionHitValue(u32 a);
void InitCollisionSlots(void);
void FindCollisionSlotsAroundPos(Vec3 *a, s32 b, s32 c);
void SetCollisionSlotRadius(s16 a, s32 b);
void DisableCollisionSlot(s16 a);
void EnableCollisionSlot(s16 a);
