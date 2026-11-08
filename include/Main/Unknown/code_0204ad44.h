#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void func_0204ad44(void);
void func_0204af70(void *heap);
// Scene function of gSceneFuncs[6] (scene 'WLMenu' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunWLMenuScene(SceneNumbers *sceneNumbers);
void UpdateWLMenuSceneCallback(void *sceneNumbers);
void func_0204b024(void);
void ReleaseWLMenuSceneCallback(void);
