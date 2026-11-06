#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_02042044.h"
#include "code_02012b30.h" // MtxFx43
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f9c6c.h"

struct MtxFx43;
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e6b58.h"

// The flat water level of a course (the map object's y) and the three water_efct effect files; 0x10 bytes, built by
// CreateWaterEfct (kinds 5, 0xe, 0xf) into gWaterEfct and published as gCourseWaterEfct; Unk0217b4d8 is the same four
// words.
typedef struct WaterEfct {
    // y of the flat water level (the map object's y); GetHeightAboveWaterOrEfct subtracts it from a y.
    /* 00 */ s32 mHeight;
    // The file MapObj/water_efct.nsbmd as FindCourseFile returned it in CreateWaterEfct (a pointer to the whole file,
    // not a built model object); returned by GetWaterEfctNsbmdFile.
    /* 04 */ void *mNsbmdFile;
    // The file MapObj/water_efct.nsbca (whole file), see mNsbmdFile.
    /* 08 */ void *mNsbcaFile;
    // The file MapObj/water_efct.nsbma (whole file), see mNsbmdFile.
    /* 0c */ void *mNsbmaFile;
} WaterEfct;

// Prefix view (0x68 bytes) of MapObject, held by gWaterMapObject.
typedef struct Unk020da384 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0x56];
    /* 66 */ u16 mUnk_66;
} Unk020da384;

// Object of 0x6c bytes at 0x68 and 0xd4 of Water; the word at 0x04 points to a table object.
typedef struct Unk020d9cf4_68 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0201290c *mUnk_04;
    /* 08 */ u8 mUnk_08[0x64];
} Unk020d9cf4_68;

// The course water: two models (the files ..._waterA and ..._waterC, Yoshi has no A) circling a map object's x/z while
// the surface height swings between two heights the creator gives; 0x180 bytes, built by the five Create...Water
// functions into gWater and published as gCourseWater.
typedef struct Water {
    // X of model A (the model of mModelAFile, letter A from the file name ..._waterA): mCenterX + mModelARadius * the
    // first value of the gPairsByAngle pair for mCircleAngle; UpdateWater writes it only while model A exists
    // (InitWaterFields first sets it to mCenterX).
    /* 00 */ s32 mModelAX;
    // y of the water surface: the models are drawn at it and the getters subtract it from a y; it stays 0 for the
    // courses whose creator passes both heights as 0.
    /* 04 */ s32 mHeight;
    // Z of model A: mCenterZ + mModelARadius * the second value of the pair for mCircleAngle; see mModelAX.
    /* 08 */ s32 mModelAZ;
    // X of model C (the model of mModelCFile, letter C from ..._waterC): mCenterX + mModelCRadius * the first pair
    // value for mCircleAngle - mModelCAngleOffset; its y is mUnk_10 (copy of mHeight).
    /* 0c */ s32 mModelCX;
    // y of model C: every write copies mHeight (code_020d94dc.c:79, :110, :200), the only reads are the translation y
    // of model C in DrawWater (code_020d94dc.c:165, :170); it is only ever set from mHeight.
    /* 10 */ s32 mModelCY;
    // Z of model C, as mModelCX with the second pair value.
    /* 14 */ s32 mModelCZ;
    // x of the water map object (copied by InitWaterFields from gWaterMapObject); both models circle around it.
    /* 18 */ s32 mCenterX;
    // (a + b) / 2 of the two heights the creator gives; the height swings around it.
    /* 1c */ s32 mMidHeight;
    // z of the water map object; both models circle around it.
    /* 20 */ s32 mCenterZ;
    // UpdateWater switches on it: 0 the angle advances towards the top, 1 hold at the top, 2 the angle advances towards
    // the bottom, 3 hold at the bottom; only UpdateWater writes it.
    /* 24 */ s32 mState;
    // (a - b) / 2 of the two heights the creator gives; mHeight is mMidHeight plus this times mHeightFactor (both
    // creators with different heights pass the larger first).
    /* 28 */ s32 mHeightAmplitude;
    // 0x10000 per turn, index (angle >> 4) * 2 into gPairsByAngle; advances only in states 0 and 2; 0x4000 is the top
    // (pair value +1.0), 0xc000 the bottom; GetWaterHeightAngle returns it.
    /* 2c */ u16 mHeightAngle;
    // 0x10000 / the cycle length (in UpdateWater calls) the creator gives; added to mHeightAngle per call in states 0
    // and 2.
    /* 2e */ u16 mHeightAnglePerFrame;
    // 1.12 fixed (0x1000 = 1.0), the first value of the gPairsByAngle pair for mHeightAngle (-1.0 .. +1.0), refreshed
    // in states 0 and 2; mHeight = mMidHeight + mHeightAmplitude * this; the HUD gauge reads it.
    /* 30 */ s32 mHeightFactor;
    // How many UpdateWater calls state 1 holds (mHoldFrames must exceed it; the height and angle stay, the models keep
    // circling); state 1 starts at angle 0x4000 where the pair value is +1.0 = the top, because the two creators with
    // different heights pass the larger first (0xe8000 > 0xc5000, 0x78000 > 0x62000).
    /* 34 */ u16 mHighHoldFrameCount;
    // How many UpdateWater calls state 3 holds, at angle 0xc000 (pair value -1.0 = the bottom); see
    // mHighHoldFrameCount.
    /* 36 */ u16 mLowHoldFrameCount;
    // Counts up one per UpdateWater call in states 1 and 3, zeroed when the state is entered, compared with
    // mHighHoldFrameCount / mLowHoldFrameCount.
    /* 38 */ u16 mHoldFrames;
    /* 3a */ u16 mUnk_3a;
    // 0x10000 per turn: the angle of the circle model A moves on (model C uses it minus mModelCAngleOffset); advances
    // every UpdateWater call by mCircleAnglePerFrame.
    /* 3c */ u16 mCircleAngle;
    /* 3e */ u16 mUnk_3e;
    // mHeightAnglePerFrame / 4, added to mCircleAngle every UpdateWater call.
    /* 40 */ u16 mCircleAnglePerFrame;
    /* 42 */ u8 mUnk_42[2];
    // Radius of the circle of model A.
    /* 44 */ s32 mModelARadius;
    // Radius of the circle of model C.
    /* 48 */ s32 mModelCRadius;
    /* 4c */ s32 mUnk_4c;
    // Model C's angle is mCircleAngle minus this (0x7fff or 0x4e20 in the creators); one write, one read.
    /* 50 */ u16 mModelCAngleOffset;
    /* 52 */ u16 mUnk_52;
    // A creator argument that is 1 in all five creators; DrawWater draws A then C when it is non-zero and C then A when
    // it is 0, which the shipped creators never do.
    /* 54 */ s32 mDrawModelAFirst;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u16 mUnk_5a;
    /* 5c */ u16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    // Pointer FindCourseMapObjFile returned for ..._waterA.nsbmd, NULL for Yoshi; every use of model A tests it.
    /* 60 */ void *mModelAFile;
    // Pointer FindCourseMapObjFile returned for ..._waterC.nsbmd; never NULL in the five creators.
    /* 64 */ void *mModelCFile;
    /* 68 */ Unk020d9cf4_68 mUnk_68;
    /* d4 */ Unk020d9cf4_68 mUnk_d4;
    /* 140 */ MtxFx43 mUnk_140;
    /* 170 */ s32 mUnk_170;
    // The file MapObj/water_efct.nsbmd as FindCourseFile returned it (a pointer to the whole file, not a built model
    // object), loaded by InitWater; the getter returns it when mUnk_170 is
    // non-zero and no WaterEfct exists.
    /* 174 */ void *mEfctNsbmdFile;
    // The file MapObj/water_efct.nsbca (whole file), loaded by InitWater; see mEfctNsbmdFile.
    /* 178 */ void *mEfctNsbcaFile;
    // The file MapObj/water_efct.nsbma (whole file), loaded by InitWater; see mEfctNsbmdFile.
    /* 17c */ void *mEfctNsbmaFile;
} Water;

// Object allocated by func_020d9de0; 0x40 bytes.
typedef struct Unk020d9de0 {
    /* 00 */ s32 mUnk_00[0x10];
} Unk020d9de0;

void InitWater(Unk020da384 *a, void *b, UnkFunc *c);
void UpdateWater(Water *a);
void DrawWater(Water *a, struct MtxFx43 *b);
Unk020d9de0 *func_020d9de0(void);
void InitWaterFields(s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, u16 g, u16 h, u16 i, u16 j, u16 k, u16 l, u16 m, u16 n,
                     s32 o);
void CreateMiniStage3Water(void);
void CreateBeachWater(void);
void CreateTownWater(void);
void CreateYoshiWater(void);
void CreateHyudoroWater(void);
void InitWaterModels(Water *a);
void CreateWaterEfct(Unk020da384 *a);
void func_020d9810(s32 a, s32 *b, s32 *c, s32 *d, s32 *e);
void func_020d970c(s32 a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h, s32 *i);
void func_020d95c0(const Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e, s32 f);
void func_020d94dc(const Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e, s32 f);
