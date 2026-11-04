#pragma once

#include "types.h"

// Three halfword components.
typedef struct Vec3s16 {
    /* 00 */ s16 x;
    /* 02 */ s16 y;
    /* 04 */ s16 z;
} Vec3s16;

u32 Div32Remainder(u32 a, u32 b);
u32 Div32(u32 a, u32 b);
void DivFixed12Start(s32 a, s32 b);
u32 SqrtFixed12Result(void);
void ReciprocalFixed12Start(s32 a);
s32 DivFixed12Result(void);
s64 DivResult64(void);
u32 SqrtFixed12(s32 a);
s64 ReciprocalFixed12Raw(s32 a);
s32 ReciprocalFixed12(s32 a);
s32 DivFixed12(s32 a, s32 b);
s32 Vec3Distance(const Vec3 *a, const Vec3 *b);
// Argument order: scalar, vector, base, result: result = base + vector * scalar (scalar with 12 fractional bits).
void Vec3AddScaled(s32 a, const Vec3 *b, const Vec3 *c, Vec3 *d);
void Vec3s16Normalize(const Vec3s16 *a, Vec3s16 *b);
void Vec3Normalize(const Vec3 *a, Vec3 *b);
s32 Vec3Length(const Vec3 *a);
void Vec3s16Cross(const Vec3s16 *a, const Vec3s16 *b, Vec3s16 *c);
void Vec3Cross(const Vec3 *a, const Vec3 *b, Vec3 *c);
s32 Vec3s16Dot(const Vec3s16 *a, const Vec3s16 *b);
s32 Vec3Dot(const Vec3 *a, const Vec3 *b);
void Vec3Sub(const Vec3 *a, const Vec3 *b, Vec3 *c);
void Vec3Add(const Vec3 *a, const Vec3 *b, Vec3 *c);
