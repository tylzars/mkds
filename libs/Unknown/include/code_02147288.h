#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

void Vec3MultiplyMatrix4x3(const Vec3 *a, const Unk02012f58 *b, Vec3 *c);
void Matrix4x3Multiply(const Unk02012f58 *a, const Unk02012f58 *b, Unk02012f58 *c);
s32 Matrix4x3Invert(const Unk02012f58 *a, Unk02012f58 *b);
void Matrix4x3FromVec3AndPair(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d);
void Matrix4x3ScaleRowsCopyRow3(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e);
