#pragma once

#include "types.h"

void func_02039774(void);
// Writes the cross product of a and b to axb (12 fractional bits); each component is shifted right by 12 without the
// rounding term that Vec3Cross adds. axb may be a or b.
void Vec3CrossUnrounded(const Vec3 *a, const Vec3 *b, Vec3 *axb);
// Returns the dot product of a and b (fixed point with 12 fractional bits), shifted right by 12 without the rounding
// term that Vec3Dot adds.
s32 Vec3DotUnrounded(const Vec3 *a, const Vec3 *b);
// Writes the vector v scaled to length 0x1000 to dst with the hardware divider and square root and returns the length
// of v. It does not test for a zero vector (many callers test the squared length against 16 first);
// Vec3NormalizeAndGetLengthOrZero does. dst may be v.
s32 Vec3NormalizeAndGetLengthUnchecked(const Vec3 *v, Vec3 *dst);
void func_020399a8(void);
void func_02039a1c(void);
void func_02039abc(u32 a, s32 b);
void func_02039b24(void);
void func_02039b94(u32 a);
void func_02039bd4(void);
void func_02039c7c(void);
