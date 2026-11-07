#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

void MTX_Identity33_(MtxFx43 *dst);
void MTX_Copy33To43_(const s32 *src, s32 *dst);
void MTX_Transpose33_(const void *src, void *dst);
void MTX_RotX33_(s32 *dst, s32 sinVal, s32 cosVal);
void MTX_RotY33_(s32 *dst, s32 sinVal, s32 cosVal);
void MTX_RotZ33_(s32 *dst, s32 sinVal, s32 cosVal);
