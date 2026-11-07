#pragma once

#include "types.h"

typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef struct NNSG3dRenderObj NNSG3dRenderObj;

// Values of ModelAnimation.mKind: the kind of animation the entries hold.
typedef enum {
    MODEL_ANIMATION_KIND_JOINT,
    MODEL_ANIMATION_KIND_TEX_SRT,
    MODEL_ANIMATION_KIND_TEX_PAT,
    MODEL_ANIMATION_KIND_VIS,
    MODEL_ANIMATION_KIND_MAT_C
} ModelAnimationKind;

// One model's animations: a table of animation objects and one loop flag per entry; one entry plays at a time.
// A change of entry can fade from the old one (StartModelAnimationBlend).
typedef struct ModelAnimation {
    /* 00 */ u16 mLoopMode;
    /* 02 */ u16 mDone;
    /* 04 */ s32 mFrameCountFixed;
    /* 08 */ s32 mFrameStep;
    /* 0c */ s32 mFrameIndex;
    /* 10 */ u16 mLoopsDone;
    /* 12 */ u16 mLoopCount;
    /* 14 */ NNSG3dRenderObj *mRenderObj;
    /* 18 */ u16 mAnmObjCount;
    /* 1a */ u16 mCurrentIndex;
    /* 1c */ NNSG3dAnmObj **mAnmObjs;
    /* 20 */ u32 *mLoopFlags;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u32 mKind;
    /* 2c */ BOOL mBlending;
    /* 30 */ s32 mBlendRatioStep;
    /* 34 */ NNSG3dAnmObj *mPreviousAnmObj;
} ModelAnimation;

extern s32 (*gAnmFrameCountGetters[])(NNSG3dAnmObj *a);

typedef struct Unk020882fc_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mFrameCount;
} Unk020882fc_08;

typedef struct Unk020882fc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk020882fc_08 *mUnk_08;
} Unk020882fc;

extern u32 gAnmObjSizeRequired;

s32 GetModelAnimationFrameCountFixed(void *a);
void AdvanceModelAnimationBlend(ModelAnimation *p);
void AdvanceModelAnimation(void *a);
void StartModelAnimationBlend(void *a, u16 b);
void SetModelAnimation(void *a, s32 b);
void InitModelAnimationEntries(void *a, void *b, void *c);
void InitModelAnimationEntry(void *a, s32 b, void *c, u32 d, void *e);
void InitModelAnimation(u32 a, void *b, void *c, u32 d, void *e, void *f);
unsigned int func_020882fc(Unk020882fc *p0);
unsigned int func_02088308(Unk020882fc *p0);
unsigned int func_02088314(Unk020882fc *p0);
unsigned int func_02088320(Unk020882fc *p0);
unsigned int func_0208832c(Unk020882fc *p0);
