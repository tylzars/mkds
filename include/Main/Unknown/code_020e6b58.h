#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

MtxFx43 *SetTranslationMatrixPos(Vec3 *a);
MtxFx43 *func_020e6b94(Vec3 *a);
MtxFx43 *func_020e6bd0(Vec3 *a);
void func_020e6c0c(void);
MtxFx43 *func_020e6c3c(Vec3 *v, s32 a1, s32 a2);
MtxFx43 *func_020e6cbc(Vec3 *a);
MtxFx43 *SetViewTransposeMatrixPos(Vec3 *a);
s32 func_020e6d34(Vec3 *v, MtxFx43 *h);
s32 func_020e6d88(Vec3 *v);
void SetViewMatrices(MtxFx43 *p);
