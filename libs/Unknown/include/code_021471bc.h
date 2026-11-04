#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

void Matrix4x3Identity(Unk02012f58 *a);
void Matrix4x3ToMatrix4x4(const Unk02012f58 *a, s32 *b);
void Matrix4x3FromDiagonal(Unk02012f58 *a, s32 b, s32 c, s32 d);
void Matrix4x3FromPairX(s32 *a, s32 b, s32 c);
void Matrix4x3FromPairY(void *a, s32 b, s32 c);
void Matrix4x3FromPairZ(s32 *a, s32 b, s32 c);
