#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// Nine words.
typedef struct MtxFx33 {
    /* 00 */ s32 mUnk_00[9];
} MtxFx33;

void MTX_MultVec33(const Vec3 *vec, const s32 *m, Vec3 *dst);
void MTX_Concat33(const s32 *a, const s32 *b, s32 *ab);
void MTX_RotAxis33(MtxFx43 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal);
void MTX_ScaleApply33(const MtxFx43 *src, MtxFx43 *dst, s32 x, s32 y, s32 z);
