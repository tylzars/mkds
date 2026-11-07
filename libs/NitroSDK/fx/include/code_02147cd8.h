#pragma once

#include "types.h"

// Three halfword components.
typedef struct Vec3s16 {
    /* 00 */ s16 x;
    /* 02 */ s16 y;
    /* 04 */ s16 z;
} Vec3s16;

s32 FX_ModS32(s32 numer, s32 denom);
s32 FX_DivS32(s32 numer, s32 denom);
void FX_DivAsync(s32 numer, s32 denom);
s32 FX_GetSqrtResult(void);
void FX_InvAsync(s32 denom);
s32 FX_GetDivResult(void);
s64 FX_GetDivResultFx64c(void);
s32 FX_Sqrt(s32 x);
s64 FX_InvFx64c(s32 denom);
s32 FX_Inv(s32 denom);
s32 FX_Div(s32 numer, s32 denom);
s32 VEC_Distance(const Vec3 *a, const Vec3 *b);
// Argument order: scale, vector, base, result: result = base + vector * scale (scale with 12 fractional bits).
void VEC_MultAdd(s32 scale, const Vec3 *vector, const Vec3 *base, Vec3 *result);
void VEC_Fx16Normalize(const Vec3s16 *src, Vec3s16 *dst);
void VEC_Normalize(const Vec3 *src, Vec3 *dst);
s32 VEC_Mag(const Vec3 *v);
void VEC_Fx16CrossProduct(const Vec3s16 *a, const Vec3s16 *b, Vec3s16 *result);
void VEC_CrossProduct(const Vec3 *a, const Vec3 *b, Vec3 *result);
s32 VEC_Fx16DotProduct(const Vec3s16 *a, const Vec3s16 *b);
s32 VEC_DotProduct(const Vec3 *a, const Vec3 *b);
void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *difference);
void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *sum);
