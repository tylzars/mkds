#pragma once

#include "types.h"

struct Unk020888b4;

// Writes to b the quaternion a scaled to length 1 (0x1000); no test for a zero quaternion.
void QuaternionNormalize(const Vec4 *a, Vec4 *b);
s32 func_01ffd0e8(Vec4 *a, const Vec3 *b, const Vec3 *c);
// Writes to c the quaternion of a rotation about the axis a by the angle b (0x10000 per turn): a scaled by the sine of
// half the angle in x, y, z and the cosine of half the angle in w.
void QuaternionFromAxisAngle(const Vec3 *a, s32 b, Vec4 *c);
void func_01ffd224(struct Unk020888b4 *p, Vec3 *a, Vec3 *b);
s32 func_01ffd648(Vec3 *a, s32 b, s32 c, s32 d, u16 e);
s32 func_01ffd778(Vec3 *a, s32 b, s32 c, s32 d, u16 e);
void func_01ffd900(s32 a, s32 b);
void func_01ffdb70(void);
