#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// Sixteen words written by G3i_OrthoW_ and G3i_FrustumW_.
typedef struct Unk0214ad4c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0214ad4c;

void G3X_SetFogTable(const void *fogTable);
s32 G3X_GetVectorMtx(void *m);
s32 G3X_GetClipMtx(void *m);
void G3X_SetFog(s32 enable, u32 fogMode, u32 fogSlope, u32 fogOffset);
void G3X_ResetMtxStack(void);
void G3X_InitMtxStack(void);
void G3X_ClearFifo(void);
void G3X_Reset(void);
void G3X_Init(void);
void G3i_LookAt_(const Vec3 *camPos, const Vec3 *camUp, const Vec3 *target, int draw, MtxFx43 *mtx);
void G3i_OrthoW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                 Unk0214ad4c *mtx);
void G3i_FrustumW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                   Unk0214ad4c *mtx);
