#pragma once

#include "types.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e6fd4.h"

typedef struct ItemObject ItemObject;

// Object of kind 0x1ac (Crab), one state per value of mState; draws crab and crab_hand.
typedef struct Crab {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mRotateZAnglePerFrame;
    /* 0a2 */ u16 mRotateZAngle;
    /* 0a4 */ s32 mTimer;
    /* 0a8 */ s32 mCrabNsbtpFrameIndexFixed12;
    /* 0ac */ s32 mHandNsbtpFrameIndexFixed12;
    /* 0b0 */ TeresaWobble mCrabWobble;
    /* 0d0 */ TeresaWobble mHandWobble;
    /* 0f0 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in UpdateCrab; this object does not use MapObject.mUnk_80's
       state machine; also set by the group init and by the collision push (2) */
    /* 114 */ s32 mState;
} Crab;

// Table of object pointers with a halfword count behind it.
typedef struct Unk0209af98 {
    /* 00 */ Crab **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
} Unk0209af98;

typedef struct Crab Crab;
typedef struct Kart Kart;

void CreateCrabAndCrabHand(void *a);

void *CreateCrabUpdateList(void);
void *CreateCrabDrawList(void);
void CreateCrabKindData(void);
void UpdateCrab(void *a, Crab *crab); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 func_0209af64(s32 a, s32 b);
s16 func_0209af80(s32 a);
void InitCrabObjects(Unk0209af98 *mapObjectList);
void DrawCrab(void *a, Crab *crab);
unsigned int func_0209b1f8(unsigned int p0);
u8 CollideItemObjectWithCrab(Crab *crab, ItemObject *itemObject, u8 *c, u8 *d);
u8 CollideKartWithCrab(Crab *crab, Kart *kart, u8 *c, u8 *d);
void StartCrabLaunch(Crab *crab, Vec3 *sourcePosition, Vec3 *sourceDirection, Vec3 *sourceVelocity);
void InitCrab(u32 crab); /* starts the path follower (InitGroupFollower) */
