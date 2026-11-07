#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e6fd4.h"

// Block of eight words at 0xb0 and 0xd0 of Crab: the u16 at 0x00 grows by 0x18 each step, 0x14 and 0x1c move
// 0x10 and 0x18 towards zero.
typedef struct Unk0209a7dc_b0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0209a7dc_b0;

// Object of kind 0x1ac (Crab), one state per value of mState; draws crab and crab_hand.
typedef struct Crab {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u16 mUnk_0a2;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ Unk0209a7dc_b0 mUnk_0b0;
    /* 0d0 */ Unk0209a7dc_b0 mUnk_0d0;
    /* 0f0 */ Unk020e0144 mUnk_0f0;
    /* State number of this kind's own per-frame switch in UpdateCrab; this object does not use MapObject.mUnk_80's
       state machine; also set by the group init and by the collision push (2) */
    /* 114 */ s32 mState;
} Crab;

// Table of object pointers with a halfword count behind it.
typedef struct Unk0209af98 {
    /* 00 */ Crab **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209af98;

typedef struct Crab Crab;
typedef struct Kart Kart;

void CreateCrabAndCrabHand(void *a);

void *CreateCrabUpdateList(void);
void *CreateCrabDrawList(void);
void CreateCrabKindData(void);
void UpdateCrab(void *a, Crab *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 func_0209af64(s32 a, s32 b);
s16 func_0209af80(s32 a);
void InitCrabObjects(Unk0209af98 *p);
void DrawCrab(void *a, Crab *b);
unsigned int func_0209b1f8(unsigned int p0);
u8 CollideItemObjectWithCrab(Crab *a, Kart *b, u8 *c, u8 *d);
u8 CollideKartWithCrab(Crab *a, Kart *b, u8 *c, u8 *d);
void func_0209b388(Crab *a, Vec3 *b, Vec3 *c, Vec3 *d);
void InitCrab(u32 arg0); /* starts the path follower (InitGroupFollower) */
