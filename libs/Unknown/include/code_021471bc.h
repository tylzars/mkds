#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

void MTX_Identity43_(MtxFx43 *dst);
void MTX_Copy43To44_(const MtxFx43 *src, s32 *dst);
void MTX_Scale43_(MtxFx43 *dst, s32 x, s32 y, s32 z);
void MTX_RotX43_(s32 *dst, s32 sinVal, s32 cosVal);
void MTX_RotY43_(MtxFx43 *dst, s32 sinVal, s32 cosVal);
void MTX_RotZ43_(s32 *dst, s32 sinVal, s32 cosVal);
