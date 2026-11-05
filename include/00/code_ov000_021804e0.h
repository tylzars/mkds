#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

extern u8 *data_ov000_021b4c60;

void *func_ov000_021804e0(void);
void *func_ov000_021804f4(void);
// Scene function of gSceneFuncs[12] (scene 'WiFiMenu' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
s32 RunWiFiMenuScene(SceneNumbers *a);
void UpdateWiFiMenuScene(SceneNumbers *a);
void func_ov000_0218058c(void);
// Calls the current state's release callback, clears the state callbacks, destroys the heap of
// func_0202bb60 and clears gWiFiStates and the list block.
void ReleaseWiFiMenuScene(void);
void InitWiFiMenuScene(s16 *a);
