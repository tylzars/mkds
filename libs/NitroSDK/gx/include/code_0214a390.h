#pragma once

#include "types.h"

void G2x_SetBlendBrightness_(vu16 *reg, u32 plane, s32 brightness);
void G2x_SetBlendAlpha_(vu16 *reg, u32 plane1, int plane2, u32 ev1, int ev2);
void G2x_SetBGyAffine_(vu16 *reg, const s32 *mtx, s32 centerX, s32 centerY, s32 x1, s32 y1);
void G2x_SetBlendBrightnessExt_(vu16 *reg, u32 plane1, u32 plane2, u32 ev1, u32 ev2, s32 brightness);
