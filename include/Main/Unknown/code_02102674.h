#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"

// Object of item kind 10, element of gItemPools[10].
typedef struct ItemGesso {
    /* 000 */ ItemObject mUnk_000;
    /* 12c */ Kart *mKart;
    /* 130 */ u8 mOrthoQuadCounts[0x8];
    /* 138 */ s32 mStepIndex;
    /* 13c */ Vec3 mViewOffset;
    /* 148 */ s32 mVelocityX;
    /* 14c */ s32 mVelocityY;
    /* 150 */ s32 mUnk_150;
    /* 154 */ s32 mTargetVelocityX;
    /* 158 */ s32 mTargetVelocityY;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ BOOL mUnk_160;
    /* 164 */ s32 mApproachRate;
    /* 168 */ s32 mDamping;
    /* 16c */ s32 mStepTimer;
    /* 170 */ s32 mUnk_170;
    /* 174 */ s32 mUnk_174;
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ Vec3 mUnk_184;
    /* 190 */ u8 mUnk_190[0x4];
    /* 194 */ s32 mUnk_194;
    /* 198 */ BOOL mVisible;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ u8 mUnk_1a0[0x14];
} ItemGesso;

// Row of the 0xc-byte table behind gItemGessoSteps.
typedef struct ItemGessoStep {
    /* 00 */ s16 mTargetVelocityX;
    /* 02 */ s16 mTargetVelocityY;
    /* 04 */ s16 mApproachRate;
    /* 06 */ s16 mDamping;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} ItemGessoStep;

extern ItemGessoStep gItemGessoSteps[];

void CreateItemTeresaFrameScaleTable(void);
void ComputeItemGessoFrameCount(void);
void InitItemGessoFromData(ItemGesso *gesso);
void CopyItemGessoData(void *data, ItemGesso *gesso, void *toData);
void DrawItemGesso(ItemGesso *p, s32 param_2, NsbmdModel *t);
void AdvanceItemGesso(ItemGesso *p);
