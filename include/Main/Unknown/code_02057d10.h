#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

// Scene function of gSceneFuncs[9] (scene 'Logo' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunLogoScene(SceneNumbers *a);
void func_02057d58(void *a);
void func_02057d64(void);
void func_02057d70(void);
void func_02057d7c(void);
void func_02057d9c(void);
u32 func_02057df0(void (*a)(void));
void func_02057e8c(void *a);
