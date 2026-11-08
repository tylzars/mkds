#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

MtxFx43 *SetTranslationMatrixPos(Vec3 *position);
MtxFx43 *func_020e6b94(Vec3 *position);
MtxFx43 *func_020e6bd0(Vec3 *position);
void func_020e6c0c(void);
MtxFx43 *func_020e6c3c(Vec3 *position, s32 horizontalFactor, s32 yOffset);
MtxFx43 *func_020e6cbc(Vec3 *position);
MtxFx43 *SetViewTransposeMatrixPos(Vec3 *position);
s32 func_020e6d34(Vec3 *yAxis, MtxFx43 *matrix);
s32 func_020e6d88(Vec3 *yAxis);
void SetViewMatrices(MtxFx43 *viewMatrix);
