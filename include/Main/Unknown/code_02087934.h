#pragma once

#include "types.h"

typedef struct ModelAnimation ModelAnimation;

void func_02087934(u32 color);
void func_020879e8(s32 texWidthFixed, s32 texHeightFixed);
void func_02087ab0(s32 texWidthFixed, s32 texHeightFixed);
void AdvanceModelAnimationFrame(ModelAnimation *modelAnimation);
void func_02087b9c(ModelAnimation *modelAnimation);
void ResetModelAnimationWithLoopFlag(ModelAnimation *modelAnimation, s32 frameCountFixed, u16 loopFlag);
