#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

// Scene function of gSceneFuncs[9] (scene 'Logo' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunLogoScene(SceneNumbers *sceneNumbers);
void UpdateLogoSceneCallback(void *sceneNumbers);
void WriteLogoSceneRegistersCallback(void);
void ApplySavedSoundModeCallback(void);
void InitLogoSceneCallback(void);
void WaitThreadFunctionsDone(void);
u32 QueueThreadFunction(void (*function)(void));
void RunQueuedThreadFunctions(void *threadArgument);
