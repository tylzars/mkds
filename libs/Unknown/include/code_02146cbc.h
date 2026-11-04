#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

void Matrix3x3Identity(Unk02012f58 *a);
void Matrix3x3ToMatrix4x3(const s32 *a, s32 *b);
void Matrix3x3Transpose(const void *a, void *b);
void Matrix3x3FromPairX(s32 *a, s32 b, s32 c);
void Matrix3x3FromPairY(s32 *a, s32 b, s32 c);
void Matrix3x3FromPairZ(s32 *a, s32 b, s32 c);
