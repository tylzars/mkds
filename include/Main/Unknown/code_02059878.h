#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void func_02059878(void);
void func_02059954(u8 *a);
u32 func_02059b28(u32 a);
// Scene function of gSceneFuncs[10] (scene 'Result' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunResultScene(SceneNumbers *a);
