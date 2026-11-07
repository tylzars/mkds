#pragma once

#include "types.h"

struct Unk0201ca6c;

typedef struct KartFollowEffect {
    /* 00 */ u8 mUnk_00[0x90];
    /* 90 */ void (*mUnk_90)(struct Unk0201ca6c *p, s32 a);
    /* 94 */ u8 mUnk_94[0x5];
    /* 99 */ u8 mCountLimit;
    /* 9a */ u8 mCount;
    /* 9b */ u8 mKartIndex;
} KartFollowEffect;

// Two kart indices, -1 for none.
typedef struct KartIndexPair {
    /* 00 */ s16 mFirst;
    /* 02 */ s16 mSecond;
} KartIndexPair;

// Four pairs; rows of gOtherKartPairs and the value of gOtherKartPairsCopy.
typedef struct OtherKartPairs {
    /* 00 */ KartIndexPair mPairs[4];
} OtherKartPairs;

#include "Main/Unknown/code_0206bcb0.h"

// Twelve bytes: a count and two effect ids.
typedef struct KartEffectIdSet {
    /* 00 */ u16 mCount;
    /* 04 */ s32 mEffectIds[2];
} KartEffectIdSet;

// 0x20 bytes: id sets for the entry kart and the others, a start function and a velocity factor index.
typedef struct KartSurfaceEffectRow {
    /* 00 */ KartEffectIdSet mEffectIdSets[2];
    /* 18 */ s32 (*mStartEffects)(KartEffectIdSet *a, s32 b, Kart *p);
    /* 1c */ s32 mVelocityFactorIndex;
} KartSurfaceEffectRow;

#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"

extern const OtherKartPairs gOtherKartPairs[];
extern KartSurfaceEffectRow gKartSurfaceEffectRows[];
extern KartSurfaceEffectRow gKartSurfaceEffectRow1;
extern KartSurfaceEffectRow gKartSurfaceEffectRow3;
extern KartSurfaceEffectRow gKartSurfaceEffectRow4;
extern KartSurfaceEffectRow gKartSurfaceEffectRow5;
extern KartSurfaceEffectRow gKartSurfaceEffectRow6;
extern KartSurfaceEffectRow gKartSurfaceEffectRow7;
extern s32 data_02165934;
extern s32 data_02165938;
extern s32 data_02165940;
extern s32 data_02165954;
extern s32 data_02165958;
extern s32 data_0216595c;
extern s32 data_02165960;
extern s32 data_02165964;
extern s32 data_02165968;
extern s32 gKartEffectVelocityFactors[];
extern Vec3 data_02165984;
extern Unk0201ca6c *gFirstCourseCameraEffect;
extern Unk0201ca6c *gKartBoostCameraEffect;
extern Unk0201ca6c *gSecondCourseCameraEffect;
extern s32 data_0217ae9c;
extern OtherKartPairs gOtherKartPairsCopy;

void PlaceKartKillerEffect(s32 a, Vec3 *b);
void StartKartKillerEffect(s32 a);
void ReleaseKartStarEffects(s32 a);
void StopKartStarEffects(s32 a);
void AdvanceKartStarEffects(s32 a);
void StartKartStarEffects(s32 a);
void AdvanceKartAheadEffectWithLimit(Unk0201ca6c *p, s32 a);
void AdvanceKartAheadEffect(Unk0201ca6c *p, s32 a);
void PlaceEffectAheadAndUpOfKart(Unk0201ca6c *p, Kart *q, s32 a, s32 b);
void PlaceKartAheadEffect(Unk0201ca6c *p, Kart *q, void *a);
void AdvanceKartFollowEffectWithVelocity(Unk0201ca6c *p, s32 a);
void SetupKartFollowEffectWithVelocity(KartFollowEffect *effect, unsigned int kartIndex, unsigned int countLimit);
void AdvanceKartFollowEffect(Unk0201ca6c *p, s32 a);
void SetupKartFollowEffect(KartFollowEffect *effect, unsigned int kartIndex, unsigned int countLimit);
void func_02081f30(void);
void func_02082034(Unk0201ca6c *p, s32 a);
void func_020821cc(Unk0201ca6c *p, s32 a);
void func_02082368(Unk0201ca6c *p, s32 a);
void func_020824d0(Unk0201ca6c *p, s32 a);
void func_0208266c(Unk0201ca6c *p, s32 a);
void func_02082750(Unk0201ca6c *p, s32 a);
void func_02082a10(Unk0201ca6c *p, s32 a);
void InitCourseCameraEffects(void);
void PlaceOtherKartEffect(Unk0201ca6c *p, s32 a);
void StartEffectsAtOtherKarts(s32 a);
void AdvanceOtherKartEffect(Unk0201ca6c *p, s32 a);
void AdvanceKartWaterEffect(Unk0201ca6c *p, s32 a);
void AdvanceKartSideEffectWithVelocity(Unk0201ca6c *p, s32 a);
void AdvanceKartSideEffect(Unk0201ca6c *p, s32 a);
void AdvanceKartCurrentEffect(Unk0201ca6c *p, s32 a);
void AdvanceKartBoostCameraEffect(Unk0201ca6c *p, s32 a);
void ReleaseKartSurfaceEffects(Kart *p);
void StopKartWaterEffects(Kart *p);
void StopKartEffectPairs(Kart *p, s32 a);
void StopKartCurrentEffects(Kart *p);
BOOL StartKartWaterEffects(KartEffectIdSet *a, s32 b, Kart *p);
s32 StartKartSideEffectsWithVelocity(KartEffectIdSet *a, s32 b, Kart *p);
s32 StartKartSideEffects(KartEffectIdSet *a, s32 b, Kart *p);
BOOL StartKartCurrentEffect(KartEffectIdSet *a, s32 b, Kart *p);
void func_02083de8(s32 a, Kart *p);
void ApplyKartWaterEffects(Kart *p);
void ApplyKartSurfaceEffect(s32 a, Kart *p);
void StartKartBoostCameraEffect(u32 a, Kart *p);
void func_020840c0(Kart *p);
void func_02084114(Kart *p);
void func_0208419c(Kart *p);
void func_02084224(Kart *p);
void func_020842ac(Kart *p);
void func_02084334(Kart *p);
void func_02084384(Kart *p);
void func_020843d8(Kart *p);
void func_0208442c(Kart *p);
// Copies the position source of the Kart into the position of its matrix (Kart.mUnk_174), then computes mSidePositions
// and mSideDirections of the Kart from the model points 2 and 3 and the Kart matrix.
void ComputeKartSidePoints(Kart *p);
// Allocates the KartEffects records for a Karts and clears them.
void InitKartEffects(u32 a);
// Returns the KartEffects record of Kart number n.
KartEffects *GetKartEffects(int arg0);
