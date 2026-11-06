#pragma once

#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_0210a578.h"

#include "types.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec
#include "Main/Unknown/code_02080b1c.h" // Unk020905a8

typedef struct UnkVec16 {
    s16 x;
    s16 y;
    s16 z;
} UnkVec16;

struct Unk020888b4;

typedef struct Unk0206c1ac_B {
    /* 0 */ u32 mUnk_00;
    /* 4 */ Vec3 mUnk_04;
} Unk0206c1ac_B;

typedef struct Unk0206c1ac_A {
    /* 0 */ Unk0206c1ac_B *mUnk_00;
} Unk0206c1ac_A;

typedef struct Unk0206c1ac {
    /* 0 */ u8 mUnk_00[0x20];
    /* 20 */ Unk0206c1ac_A *mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ u8 mUnk_34[0xc];
    /* 40 */ Vec3 mUnk_40;
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ UnkVec16 mUnk_50;
    /* 56 */ u8 mUnk_56[0x16];
    /* 6c */ s32 mUnk_6c;
    /* 70 */ u8 mUnk_70[2];
    /* 72 */ u16 mUnk_72;
} Unk0206c1ac;

// The 0x98-byte record of one kart slot, copied from a row of kartphysicalparam.bin (50 rows: 37 kart rows, then 13
// character rows used in mode 2). Edited in place per race: mBaseSpeedLimit by the engine class, the surface tables by
// the character row. Read by the Kart step and the item objects (Race).
typedef struct KartPhysicalParam {
    // Base radius (0x8000 = 8.0 in 12-bit fixed).
    /* 0 */ s32 mRadius;
    /* 4 */ s32 mUnk_04;
    /* 8 */ s32 mUnk_08;
    // s16, read only by the kart-kart push (the ratio of the two karts' values); the file column grows with the kart
    // size.
    /* c */ s16 mWeight;
    /* e */ s16 mUnk_0e;
    // Top speed before the factors, scaled by the engine class at creation (x0xb33 / x0xd9a); reached: the length is
    // cut to the limit.
    /* 10 */ s32 mBaseSpeedLimit;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s16 mUnk_30;
    /* 32 */ s16 mUnk_32;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38[12];
    // 12 factors out of 0x1000, indexed by the surface group; entry 4 is also the floor of the below-the-level path.
    /* 68 */ s32 mSurfaceSpeedLimitFactors[12];
} KartPhysicalParam;

// Event counters of the selected entry's Kart (seven words; the one at 0 is a flag set to 1). Every writer tests that
// the Kart is the selected entry. Read by the rank score of the grand prix and the goal tests of mission run. What each
// counter counts is not named.
typedef struct EntryKartCounters {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
    /* 8 */ s32 mUnk_08;
    /* c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
} EntryKartCounters;

struct Kart;

// 16-byte entry of the table at Unk0217d26c.mUnk_04: func_0210dd44 calls mUnk_04 with the words at 8 and 0xc.
typedef struct Unk0210ddf4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void (*mUnk_04)(void *, s32);
    /* 08 */ void *mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0210ddf4;

typedef struct Unk0217d26c {
    /* 0 */ s32 mUnk_00;
    /* 4 */ Unk0210ddf4 *mUnk_04;
} Unk0217d26c;

extern Unk0217d26c data_0217d294;
extern Unk0217d26c data_0217d29c;

typedef struct Unk0206ceb4 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
    /* 14 */ s16 mUnk_14;
    /* 16 */ s16 mUnk_16;
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ BOOL mUnk_24;
    /* 28 */ s16 mUnk_28;
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ Unk020905a8 mUnk_2c;
} Unk0206ceb4;

typedef struct Unk0206bcb0_514 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ s16 mUnk_40;
    /* 42 */ u8 mUnk_42[2];
    /* 44 */ u32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ Vec4 mUnk_4c;
    /* 5c */ s16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ u8 mUnk_68[0x18];
    /* 80 */ NNSFndList mUnk_80;
    /* 8c */ NNSFndList mUnk_8c;
    /* 98 */ Vec3 mUnk_98;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ Vec3 mUnk_a8;
    /* b4 */ u16 mUnk_b4;
} Unk0206bcb0_514;

typedef struct Unk0206c5e4_208 {
    /* 0 */ BOOL mUnk_00;
} Unk0206c5e4_208;

// The 0x38 bytes at 0x450 of a Kart: words at 0x08, 0x28, 0x30 and 0x34 and a byte at 0x2c.
typedef struct Unk0206bcb0_A {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x1c];
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d[3];
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
} Unk0206bcb0_A;

// Bits of Kart.mUnk_7c.
// Set once at set-up (func_02071e28) when mIndex == data_021759c0->mEntryIndex, i.e. the selected entry.
#define KART_7C_INDEX_IS_SELECTED_ENTRY 0x1
// Set at set-up when the entry's mKind is 2. Bit 0x2 and this bit are also tested together as 6 / 0x402004 (left
// literal).
#define KART_7C_ENTRY_KIND_2 0x4
// Set at set-up when mKartModelsEntry->mUnk_008 != NULL (a snapshot taken then).
#define KART_7C_MODELS_ENTRY_008_SET 0x10

// Bits of Kart.mUnk_44.
// Set on both Karts of a pair when the near test passed; cleared at the start of the next step (inside the literal
// 0x57ffffdf).
#define KART_44_NEAR_KART 0x20

typedef struct Kart {
    // Sound source of the Kart (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    /* 44 */ vu32 mUnk_44;
    /* 48 */ vu32 mUnk_48;
    /* 4c */ vu32 mUnk_4c;
    /* 50 */ Vec3 mUnk_50;
    /* 05c */ Vec3 mUnk_05c;
    /* 68 */ Vec3 mUnk_68;
    /* 74 */ u16 mIndex;
    /* 76 */ u8 mUnk_76[0x2];
    /* 78 */ s32 mEntryIndex;
    /* 7c */ vu32 mUnk_7c;
    /* 80 */ Vec3 mPos;
    /* 8c */ Vec3 mPrevPos;
    /* 98 */ Vec3 mUnk_98;
    /* a4 */ Vec3 mVelocity;
    /* b0 */ Vec3 mVelocityDirection;
    // Size scale of the kart (x, y, z; 0x1000 = 1.0): mScaleBase times mScaleFactor per axis, y also times
    // mScaleYFactor. Zero at the start placement (ResetKartToStartPlacement) and where the kart is moved to a far
    // corner (func_02068b98, func_02068640).
    /* bc */ Vec3 mScale;
    // Negative step added by ApplyKartGravity to mVerticalSpeed, by func_01ff9c40 to mHopSpeed while hopping and to a
    // speed of the mode-5 record; -0x2b9 at reset, 0 after the water-height branch of func_0206ff50.
    /* c8 */ s32 mGravity;
    // The value mSpeedLimit follows: it falls by x0xf37/0x1000 per step but never below it and rises to it at once.
    // Written by the step, by the companion objects (their own choice) and at set-up; read by the companion objects as
    // the kart's limit.
    /* cc */ s32 mSpeedLimitGoal;
    /* d0 */ s32 mSpeedLimit;
    /* d4 */ u32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ union {
        struct {
            s32 mUnk_e0;
            Vec3 mUnk_e4;
            Vec3 mUnk_f0;
            u32 mUnk_fc;
            s32 mUnk_100;
            struct Unk020e04b0 *mUnk_104;
            Vec3 mUnk_108;
            u8 mUnk_114[6];
            s16 mUnk_11a;
            s32 mUnk_11c;
        };
        struct {
            Vec4 mUnk_e0_m;
            Vec4 mUnk_f0_q;
            Vec4 mUnk_100_q;
            Vec4 mUnk_110_q;
        };
    };
    /* 120 */ union {
        struct {
            Vec3 mUnk_120;
            Vec3 mUnk_12c;
            Vec3 mUnk_138;
            Vec3 mUnk_144;
        };
        MtxFx43 mUnk_120_m;
    };
    /* 150 */ union {
        struct {
            Vec3 mUnk_150;
            Vec3 mUnk_15c;
            Vec3 mUnk_168;
            Vec3 mUnk_174;
        };
        MtxFx43 mUnk_150_m;
    };
    /* 180 */ vs32 mState;
    /* 184 */ MtxFx43 mWobbleMatrix;
    /* 1b4 */ MtxFx43 *mDrawMatrix;
    // Collision center of the Kart: the position moved up by mRadius plus 0x400 along the up vector. The
    // collision sweep ends here; Kart.mPrevCollisionCenter is where it starts.
    /* 1b8 */ Vec3 mCollisionCenter;
    // Collision center of the previous step, set from the previous position by slot 5 of Kart.mSlotFunctions: the start
    // of the collision sweep that ends at Kart.mCollisionCenter.
    /* 1c4 */ Vec3 mPrevCollisionCenter;
    // Current radius: the record's radius times two scales (code_01ffba68.c:208), set from the record at creation.
    /* 1d0 */ s32 mRadius;
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ Vec3 mUnk_1d8;
    /* 1e4 */ Vec3 mUnk_1e4;
    /* 1f0 */ Vec3 mUnk_1f0;
    /* 1fc */ Vec3 mUnk_1fc;
    /* 208 */ Unk0206c5e4_208 *mUnk_208;
    // The functions of one Kart, one per slot index: 0 set-up at creation, 1 reset to the starting values, 2 stores the
    // squared distance in the sound source, 3 and 4 the two steps UpdateKarts runs for every Kart, 5 stores the
    // previous collision center, 6 respawn, 7 start placement, 8 does nothing. 7 and 8 are never called. InitKart fills
    // it from gKartDefaultSlotFunctions and replaces slots 2 to 5; it also replaces slots 3 and 4 with an empty
    // function when gRace.mUseChainCameras is set and Unk021759c0.mUnk_00c is not 5.
    /* 20c */ void (*mSlotFunctions[9])(struct Kart *);
    /* 230 */ void (*mUnk_230)(struct Kart *);
    /* 234 */ s16 mUnk_234;
    // Angle about world up that orients the kart (0x10000 per turn): set from a direction vector or a start rotation,
    // turned by the step functions and by mHeadingAnglePerFrame; mHeadingAngleOffset is added on top when the
    // orientation is built.
    /* 236 */ u16 mHeadingAngle;
    /* 238 */ s16 mBoostTimer;
    /* 23a */ s16 mUnk_23a;
    /* 23c */ s16 mUnk_23c;
    /* 23e */ u8 mUnk_23e[2];
    /* 240 */ u32 mUnk_240;
    /* 244 */ Vec3 mUnk_244;
    /* 250 */ Vec3 mUnk_250;
    /* 25c */ s32 mUnk_25c;
    // Vertical speed added to mVelocity.y after mVelocity is rebuilt each step, so it persists; mGravity is added to
    // it, it is reset to -0x2b9 or -0xd9d on a ground hit while negative, and a hop start adds a kick.
    /* 260 */ s32 mVerticalSpeed;
    /* 264 */ u8 mUnk_264[4];
    /* 268 */ Vec3 mUnk_268;
    /* 274 */ s32 mUnk_274;
    /* 278 */ Vec3 mUnk_278;
    /* 284 */ Vec3 mUnk_284;
    /* 290 */ Vec3 mUnk_290;
    /* 29c */ s32 mUnk_29c;
    /* 2a0 */ s32 mVelocityLengthRatio;
    /* 2a4 */ s32 mVelocityLength;
    /* 2a8 */ s32 mForwardSpeed;
    // mPos.y while the floor-hit bit is set; read once (the fall height of a landing).
    /* 2ac */ s32 mLastGroundY;
    /* 2b0 */ u16 mTestedKartMask;
    /* 2b2 */ u16 mNearKartMask;
    /* 2b4 */ u16 mPrevNearKartMask;
    /* 2b6 */ u8 mUnk_2b6[2];
    // Vertical speed of the hop arc: 0x1405 at the start (func_0206c5e4), mGravity added each step by func_01ff9c40,
    // integrated into mHopHeight, 0 once the height is below 0.
    /* 2b8 */ s32 mHopSpeed;
    // Height of the hop arc, integrated from mHopSpeed; 0 at the start and when it would go below 0. The camera, its
    // look-at and the replay record subtract it from mPos.y.
    /* 2bc */ s32 mHopHeight;
    // Angle about the x axis that tilts the kart while mHopSpeed > 0 and bit 2 of mUnk_44 is set (0x9c4 minus
    // mHopHeight * 500 / 0x1000, 0x352 when that exceeds 0x6a4); 0 otherwise. 0x10000 per turn.
    /* 2c0 */ u16 mHopTiltAngle;
    /* 2c2 */ u8 mUnk_2c2[2];
    // Sign 1 / -1 / 0 of a turn, latched when it starts (from mUnk_48 bits 0x10 / 8, or from the entry's input bits
    // 0x10 / 0x20) and cleared when it ends; read only as a sign.
    /* 2c4 */ s32 mTurnDirection;
    /* 2c8 */ s16 mUnk_2c8;
    /* 2ca */ s16 mUnk_2ca;
    // Pointer to this slot's KartPhysicalParam; set once in func_020726bc. The record is shared by nothing else.
    /* 2cc */ KartPhysicalParam *mPhysicalParam;
    // Two words of charphysicalparam.bin for the entry's character: [0] scales the surface factors below 0x1000, [1] is
    // added to mWeight.
    /* 2d0 */ s32 *mCharPhysicalParam;
    /* 2d4 */ s32 mUnk_2d4;
    /* 2d8 */ Vec3 mUnk_2d8;
    /* 2e4 */ Vec3 mUnk_2e4;
    /* 2f0 */ Vec3 mUnk_2f0;
    /* 2fc */ s32 mDriftCharge;
    /* 300 */ u16 mLeftTurnCount;
    /* 302 */ u16 mRightTurnCount;
    /* 304 */ u16 *mAwayTurnCounter;
    /* 308 */ u16 *mTowardTurnCounter;
    /* 30c */ s32 mTurnCountTimer;
    /* 310 */ struct Unk020888b4 *mUnk_310;
    /* 314 */ u16 mRotationAngle;
    /* 316 */ u8 mUnk_316[2];
    /* 318 */ s32 mRotationAngleSum;
    /* 31c */ Vec3 mRotationAxis;
    /* 328 */ Vec3 mUnk_328;
    /* 334 */ s32 mUnk_334;
    /* 338 */ u16 mUnk_338;
    /* 33a */ u8 mUnk_33a[2];
    /* 33c */ s32 mUnk_33c;
    /* 340 */ s32 mUnk_340;
    /* 344 */ s32 mUnk_344;
    /* 348 */ s32 mUnk_348;
    /* 34c */ Vec4 mRotationQuaternion;
    /* 35c */ s16 mRotationEndFrames;
    /* 35e */ u8 mUnk_35e[2];
    /* 360 */ s32 mRotationAnglePerFrame;
    /* 364 */ u16 mYRotationAngle;
    /* 366 */ u16 mYRotationCount;
    /* 368 */ s32 mYRotationAngleSum;
    /* 36c */ s32 mYRotationAnglePerFrame;
    /* 370 */ u16 mUnk_370;
    /* 372 */ u8 mUnk_372[2];
    /* 374 */ Vec3 mUnk_374;
    // Calls of UpdateKartAirborne since the floor-hit bit (mUnk_44 & 0x10) was last set; not every step (skipped below
    // y = 0).
    /* 380 */ u32 mAirborneFrames;
    // Draw gate of the kart: 0xffff while it is drawn, 0 when DrawKart skips it (hidden states, or the off phase of
    // the blink); other draw code skips its drawing while it is 0; 0 at reset for an entry of kind 2.
    /* 384 */ u16 mVisible;
    // Angle added to mHeadingAngle each step, first multiplied by 0xe66 / 0x1000 and cut to 0 below 0x14; set in
    // func_0206f04c, 0 at reset.
    /* 386 */ s16 mHeadingAnglePerFrame;
    // Angle that follows mTurnDirection: eased toward 11000 or -11000, changed by the turn input and cut back to 0 on
    // the ground; it is the angle of the rotation of mUnk_278 about mUnk_244 in func_01ffb130.
    /* 388 */ s16 mTurnAngle;
    /* 38a */ s16 mUnk_38a;
    /* 38c */ s32 mUnk_38c;
    /* 390 */ u8 mUnk_390[4];
    /* 394 */ s32 mUnk_394;
    /* 398 */ s32 mUnk_398;
    /* 39c */ s32 mUnk_39c;
    /* 3a0 */ s32 mUnk_3a0;
    // Angle of the tire object about the x axis (0x10000 per turn), advanced each step in func_020641f0 from the speed
    // ratio and used by DrawKart; 0 at reset.
    /* 3a4 */ u16 mTireSpinAngle;
    /* 3a6 */ u8 mUnk_3a6[2];
    /* 3a8 */ s32 mUnk_3a8;
    /* 3ac */ u16 mUnk_3ac;
    /* 3ae */ u8 mUnk_3ae[2];
    // mVelocity, minus mVerticalSpeed on a floor hit, shifted right by 4 each step (func_01ff9b70); copied or scaled
    // into the velocity (mUnk_40) of effect objects.
    /* 3b0 */ Vec3 mEffectVelocity;
    /* 3bc */ u16 mUnk_3bc;
    /* 3be */ u16 mUnk_3be;
    /* 3c0 */ s16 mUnk_3c0;
    /* 3c2 */ u8 mUnk_3c2[2];
    // Number of the course respawn slot this Kart goes back to, set when it falls or when it respawns with none chosen;
    // -1 means none chosen (ResetKart writes -1).
    /* 3c4 */ s32 mRespawnSlot;
    /* 3c8 */ s16 mUnk_3c8;
    /* 3ca */ u8 mUnk_3ca[2];
    /* 3cc */ s32 mUnk_3cc;
    /* 3d0 */ s16 mUnk_3d0;
    // Countdown of 0x14 set on the slower kart of a kart-kart contact in CollideKartWithKarts and counted down by
    // func_01ffc8cc, which calls func_0210b12c at 0 (what that call does is unknown).
    /* 3d2 */ s16 mKartCollisionTimer;
    /* 3d4 */ s16 mUnk_3d4;
    /* 3d6 */ u8 mUnk_3d6[2];
    /* 3d8 */ s32 mUnk_3d8;
    // Result of the handler: index into the two 12-entry tables of the record; -1 when the floor is left; compared with
    // 8 and 0xb. Group meanings unknown.
    /* 3dc */ s32 mSurfaceGroup;
    // Bits 8..12 of the attribute of the strongest ground hit (mask 0x1e34ef); indexes gKartSurfaceFunctions; 0 after
    // reset.
    /* 3e0 */ s32 mSurfaceKind;
    // Bits 5..7 of the same attribute: second selector (effect tables).
    /* 3e4 */ s32 mSurfaceVariant;
    /* 3e8 */ s16 mUnk_3e8;
    /* 3ea */ u8 mUnk_3ea[2];
    /* 3ec */ s32 mUnk_3ec;
    /* 3f0 */ s32 mUnk_3f0;
    /* 3f4 */ s32 mUnk_3f4;
    /* 3f8 */ s32 mUnk_3f8;
    /* 3fc */ u16 mUnk_3fc;
    /* 3fe */ u16 mUnk_3fe;
    /* 400 */ u16 mUnk_400;
    /* 402 */ u8 mUnk_402[2];
    /* 404 */ s32 mUnk_404;
    /* 408 */ s32 mUnk_408;
    /* 40c */ s32 mUnk_40c;
    /* 410 */ s32 mUnk_410;
    /* 414 */ s32 mUnk_414;
    /* 418 */ s32 mUnk_418;
    // Part of mScale looked up in three tables (x, y, z) of 25 entries (0x800 up to 0x1000) by a step counter, forwards
    // or backwards; 0x1000 when no step runs.
    /* 41c */ Vec3 mScaleFactor;
    // Part of mScale held at 0x1000, eased down to 0x800 while the countdown of func_0206a354 runs and set back to
    // 0x1000 at its end; mScaleFactor is the table-driven part.
    /* 428 */ Vec3 mScaleBase;
    // Factor of mScale.y only: 0x1000 normally, lowered by 0x4cd per call to a floor of 0x4cd in func_02069f6c.
    /* 434 */ s32 mScaleYFactor;
    /* 438 */ struct MapObject *mUnk_438[2];
    /* 440 */ u16 mUnk_440[2];
    /* 444 */ s32 mUnk_444[2];
    /* 44c */ struct MapObject *mUnk_44c;
    /* 450 */ Unk0206bcb0_A mUnk_450;
    /* 488 */ u32 mUnk_488;
    /* 48c */ s32 (*mUnk_48c)(void *);
    /* 490 */ u32 mUnk_490;
    /* 494 */ u8 mUnk_494[0x24];
    /* 4b8 */ s32 mUnk_4b8;
    /* 4bc */ s32 mUnk_4bc;
    /* 4c0 */ s32 mUnk_4c0;
    /* 4c4 */ s32 mUnk_4c4;
    /* 4c8 */ s32 mUnk_4c8;
    /* 4cc */ s32 mUnk_4cc;
    /* 4d0 */ u32 mUnk_4d0;
    /* 4d4 */ s32 mUnk_4d4;
    /* 4d8 */ s16 mUnk_4d8;
    /* 4da */ s16 mUnk_4da;
    /* 4dc */ s16 mUnk_4dc;
    // Angle added to mHeadingAngle when the orientation is built, never to mHeadingAngle itself; func_020713a0 swings
    // it back and forth and sets it to 0 at the end.
    /* 4de */ s16 mHeadingAngleOffset;
    // Angle added to mHeadingAngleOffset each step by func_020713a0; changed by 0x3c per call toward the swing
    // direction and clamped to 0x17c, later 0xd2; 0 at reset.
    /* 4e0 */ s16 mHeadingAngleOffsetPerFrame;
    /* 4e2 */ s16 mUnk_4e2;
    /* 4e4 */ u16 mUnk_4e4;
    /* 4e6 */ u8 mUnk_4e6[2];
    /* 4e8 */ s32 mUnk_4e8;
    /* 4ec */ s32 mUnk_4ec;
    /* 4f0 */ Vec3 mUnk_4f0;
    /* 4fc */ u16 mUnk_4fc;
    /* 4fe */ u8 mUnk_4fe[2];
    /* 500 */ u32 mUnk_500;
    /* 504 */ u16 mUnk_504;
    /* 506 */ u16 mUnk_506;
    // Points to mPos, or for a kind-3 entry in mode 5 to a Vec3 of the received record (mUnk_514); set in InitKart.
    // Draw, culling, effect placement and the position getter read the position through it.
    /* 508 */ Vec3 *mPosSource;
    /* 50c */ Vec4 *mUnk_50c;
    /* 510 */ Vec3 *mUnk_510;
    /* 514 */ Unk0206bcb0_514 *mUnk_514;
    /* 518 */ Unk0210b7ec mUnk_518;
    /* 528 */ u8 mUnk_528[0xc];
    /* 534 */ Vec3 *mUnk_534;
    /* 538 */ Unk0206ceb4 mUnk_538;
    /* 590 */ struct Unk0206bcb0_590 *mKartModelsEntry;
    /* 594 */ s32 mWobbleAmplitude;
    /* 598 */ s16 mWobbleDirection;
    /* 59a */ u8 mUnk_59a[2];
    /* 59c */ s32 mUnk_59c;
    /* 5a0 */ u16 mWobbleAngle;
    /* 5a2 */ u8 mUnk_5a2[2];
    /* 5a4 */ s32 mUnk_5a4;
} Kart;

extern Kart *data_0217b8c8;

extern int data_02154f10[];

void StartKartState(Kart *p, int mode);
BOOL func_0206c094(Kart *p);
int func_0206c0a8(Kart *p);
BOOL func_0206c0b0(Kart *p);
BOOL func_0206c0e0(Kart *p);
void func_0206c11c(Kart *p);
void func_0206c14c(Kart *p);
void func_0206c17c(Kart *p);
void func_0206c1ac(Unk0206c1ac *obj, Kart *p);
void func_0206c2b4(Unk0206c1ac *obj, Kart *p);
BOOL func_0206c354(Kart *p, const Vec3 *a, int flag);
void func_0206c450(Unk0206c1ac *obj, Kart *p);
void func_0206c488(Unk0206c1ac *obj, Kart *p);

void func_0208b748(u32 idx, const Vec3 *pos, void *p, void (*cb)());
int func_0206c494(Kart *p);
void func_0206cc60(Kart *p, int arg);
#include "Main/Unknown/code_0210ab48.h"
void func_0206cdd4(Kart *p);
void func_0206ceb4(s32 *out, Kart *p);
extern Unk0217d26c data_0217d26c;
extern Unk0217d26c data_0217d274;
extern Unk0217d26c data_0217d284;
extern Unk0217d26c data_0217d28c;
#include "Main/Unknown/code_0210dc7c.h"
void func_020718c8(void *p, int arg);
void func_02071944(void *p, int arg);
#include "Main/Unknown/code_021035ac.h"
BOOL func_0206bcb0(Kart *p, int a, int b);
BOOL TryStartKartState(Kart *p, int a);
void func_0206c5e4(Kart *p);
void GetKartForward(const Kart *p, Vec3 *out);
void GetKartUp(const Kart *p, Vec3 *out);

#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_02079c0c.h"
