#pragma once

#include "types.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/unk_02175000.h"

extern SceneCallbacks gKeyboardSceneCallbacks;

// Scene function of gSceneFuncs[14] (scene 'Keyboard' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
s32 RunKeyboardScene(void *a);
void UpdateKeyboardScene(s16 *a);
void func_0212891c(void);
