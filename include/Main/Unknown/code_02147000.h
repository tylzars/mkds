#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

void Matrix4x3Identity(Unk02012f58 *param_1);
void Matrix4x3FromPairY(void *, s32, s32);
void Matrix4x3FromDiagonal(Unk02012f58 *param_1, s32 param_2, s32 param_3, s32 param_4);
void Matrix4x3ToMatrix4x4(const Unk02012f58 *a, s32 *b);
void Matrix4x4Identity(s32 *a);
void Matrix4x4ToMatrix4x3(const s32 *a, Unk02012f58 *b);
void Matrix4x3FromPairX(s32 *p0, s32 p1, s32 p2);
void Matrix4x3FromPairZ(s32 *p0, s32 p1, s32 p2);
