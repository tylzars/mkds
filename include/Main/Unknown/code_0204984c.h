#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

s32 func_0204984c(SceneNumbers *a, s32 b);
void func_02049980(s32 a);
u32 func_0204998c(void);
BOOL ShouldGoSleepMode(void);
u32 func_02049b6c(void);
void InitSceneRunState(void *a);
void ScenePostSleepCallback(void);
void ScenePreSleepCallback(void *a);
void func_02049e38(s32 a);
void func_02049f60(void);
void func_0204a1a8(void *a);
s32 func_0204a340(s32 a, s32 b);
s32 func_0204a428(s32 a, s32 *b);
void func_0204a4d8(void);
u32 GetSceneFadeToFadedFrameCount(void);
s16 GetSceneFadeToClearFrameCount(void);
