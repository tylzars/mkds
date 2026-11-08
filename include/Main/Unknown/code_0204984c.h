#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

s32 func_0204984c(SceneNumbers *sceneNumbers, s32 b);
void func_02049980(s32 kind);
u32 func_0204998c(void);
BOOL ShouldGoSleepMode(void);
u32 func_02049b6c(void);
void InitSceneRunState(void *heap);
void ScenePostSleepCallback(void);
void ScenePreSleepCallback(void *arg);
void func_02049e38(s32 kind);
void func_02049f60(void);
void func_0204a1a8(void *arg);
s32 func_0204a340(s32 scene, s32 nextScene);
s32 func_0204a428(s32 sceneNumber, s32 *b);
void func_0204a4d8(void);
u32 GetSceneFadeToFadedFrameCount(void);
s16 GetSceneFadeToClearFrameCount(void);
