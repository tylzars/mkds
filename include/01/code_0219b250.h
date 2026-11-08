#pragma once

#include "types.h"
#include "code_02012b30.h"

// Object at Unk0219b250.mNsbcaAnimation and mNsbtpAnimation (a 0x38-byte allocation).
typedef struct ModelAnimationView {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} ModelAnimationView;

// Object at Unk0219b250.mAnimatedModel (a 0x6c-byte allocation).
typedef struct Unk0219b250_10 {
    /* 00 */ u8 mUnk_00[0x4];
    /* 04 */ NNSG3dResMdl *mResMdl;
    /* 08 */ u8 mUnk_08[0x24];
    /* 2c */ struct Unk02188950 *mUnk_2c;
} Unk0219b250_10;

// Object behind Unk02188950.mNsbmd: the 0x2c-byte allocation made by LoadMapObjectModelAnimated and
// LoadMapObjectModelShadow.
typedef struct Unk0219b250 {
    // Overlay view of MapObjectModel.mScale.
    /* 00 */ Vec3 mScale;
    // Not accessed through this view.
    /* 0c */ void *mNsbmdModel;
    // Overlay view of MapObjectModel.mAnimatedModel.
    /* 10 */ Unk0219b250_10 *mAnimatedModel;
    // Overlay view of MapObjectModel.mShadowModel.
    /* 14 */ void *mShadowModel;
    // Overlay view of MapObjectModel.mNsbmdFile.
    /* 18 */ void *mNsbmdFile;
    // Overlay view of MapObjectModel.mAnimations[0].
    /* 1c */ ModelAnimationView *mNsbcaAnimation;
    // Overlay view of MapObjectModel.mAnimations[1].
    /* 20 */ ModelAnimationView *mNsbtpAnimation;
    // Overlay view of MapObjectModel.mAnimations[2].
    /* 24 */ void *mNsbmaAnimation;
    // Overlay view of MapObjectModel.mAnimations[3].
    /* 28 */ void *mNsbtaAnimation;
} Unk0219b250;

// First argument of LoadMapObjectModelAnimated and LoadMapObjectModelShadow.
typedef struct Unk0219b478 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0219b478;

void func_ov001_0219b250(Unk0219b250 *p0);
void func_ov001_0219b25c(Unk0219b250 *p0, void *p1);
void func_ov001_0219b28c(Unk0219b250 *p0, void *p1);
void LoadMapObjectModelNsbtpAnimation(Unk0219b250 *p0, const char *p1);
void LoadMapObjectModelNsbtaAnimation(Unk0219b250 *p0, const char *p1);
void LoadMapObjectModelNsbmaAnimation(Unk0219b250 *p0, const char *p1);
void LoadMapObjectModelNsbcaAnimation(Unk0219b250 *p0, const char *p1);
Unk0219b250 *LoadMapObjectModelShadow(Unk0219b478 *p0, const char *p1);
Unk0219b250 *LoadMapObjectModelAnimated(Unk0219b478 *p0, const char *p1);
void *LoadMissionRunFile(const char *p0);
void *func_ov001_0219b510(void *p0, void *p1, void *p2, u32 p3, u16 p4, u16 p5, u16 p6);
