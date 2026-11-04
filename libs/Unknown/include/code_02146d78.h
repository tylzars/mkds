#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

// Nine words.
typedef struct Matrix3x3 {
    /* 00 */ s32 mUnk_00[9];
} Matrix3x3;

void Vec3MultiplyMatrix3x3(const Vec3 *a, const s32 *b, Vec3 *c);
void Matrix3x3Multiply(const s32 *a, const s32 *b, s32 *c);
void Matrix4x3FirstThreeRowsFromVec3AndPair(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d);
void Matrix4x3ScaleFirstThreeRows(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e);
