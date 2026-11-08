#pragma once

#include "types.h"

// Record of 0x54 bytes: four positions, then words at 0x30 and 0x34.
typedef struct Segment {
    /* 00 */ Vec3 mPoints[4];
    /* 30 */ s32 mProgressLength;
    /* 34 */ s32 mInverseProgressLength;
    /* 38 */ s32 mCurveLength;
    /* 3c */ s32 mInverseCurveLength;
    /* 40 */ s32 mStraightLength;
    /* 44 */ s32 mInverseStraightLength;
    /* 48 */ Vec3 mUp;
} Segment;

typedef struct GroupPath {
    /* 00 */ Segment *mSegments;
    /* 04 */ s32 mSegmentCount;
    /* 08 */ s32 mWraps;
} GroupPath;

typedef struct GroupFollower {
    /* 00 */ GroupPath *mPath;
    /* 04 */ s32 mSpeed;
    /* 08 */ u16 mGroupIndex;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ s32 mSegmentIndex;
    /* 10 */ s32 mProgressStep;
    /* 14 */ s32 mProgress;
    /* 18 */ s32 mForward;
    /* 1c */ struct CourseMapGroupEntry *mFromEntry;
    /* 20 */ struct CourseMapGroupEntry *mToEntry;
} GroupFollower;

// Sub-object at 0x80 of Unk020e005c and MapObject: func_02046be8 stores its second, fourth and third arguments at
// 0x00, 0x08 and 0x0c and zeroes 0x04, 0x0e and 0x10.
typedef struct Unk020e005c_080 {
    /* 00 */ UnkFunc *const *mUnk_00;
    /* 04 */ u32 mStateFrames;
    /* 08 */ void *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} Unk020e005c_080;

typedef struct Unk020e005c {
    /* 000 */ u16 mUnk_000;
    // Flags of the map object, the same bytes as MapObject.mFlags.
    /* 002 */ u16 mFlags;
    // Position, the same bytes as MapObject.mPos.
    /* 004 */ Vec3 mPos;
    /* 010 */ Vec3 mUnk_010;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ Vec3 mUnk_028;
    /* 034 */ Vec3 mUnk_034;
    /* 040 */ Vec3 mUnk_040;
    /* 04c */ u8 mUnk_04c[0x1a];
    // Alpha of the object, the same bytes as MapObject.mAlpha.
    /* 066 */ u16 mAlpha;
    /* 068 */ u8 mUnk_068[8];
    // Squared distance beyond which bit 2 of mDistanceSquaredAndFlags is set, the same bytes as
    // MapObject.mFarDistanceSquared.
    /* 070 */ s32 mFarDistanceSquared;
    /* 074 */ u8 mUnk_074[0x4];
    // Squared distance and flags word, the same bytes as MapObject.mDistanceSquaredAndFlags.
    /* 078 */ u32 mDistanceSquaredAndFlags;
    /* 07c */ u8 mUnk_07c[0x4];
    // State machine of the kind, the same bytes as MapObject.mStateMachine.
    /* 080 */ Unk020e005c_080 mStateMachine;
    /* 094 */ u8 mUnk_094[0xc];
    /* 0a0 */ Vec3 mUnk_0a0;
    /* 0ac */ Vec3 mUnk_0ac;
    /* 0b8 */ Vec3 mUnk_0b8;
    /* 0c4 */ u8 mUnk_0c4[0x24];
    /* 0e8 */ Vec3 mUnk_0e8;
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ BOOL mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ void *mUnk_140;
    /* 144 */ GroupFollower mUnk_144;
    /* 168 */ s32 mUnk_168;
    /* 16c */ u16 mUnk_16c;
} Unk020e005c;

void UpdateKoopaBlockState1(Unk020e005c *koopaBlock);
void EnterKoopaBlockState1(Unk020e005c *koopaBlock);
void UpdateKoopaBlockState0(Unk020e005c *koopaBlock);
