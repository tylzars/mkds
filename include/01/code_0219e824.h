#pragma once

#include "types.h"

// Scene function of gSceneFuncs[11] (scene 'Nickname' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
int RunNicknameScene(void *a);
void func_ov001_0219e858(s16 *param_1);
void func_ov001_0219e89c(void);
void func_ov001_0219e8c0(void);
void func_ov001_0219e8d8(s16 *a);
u8 *func_ov001_0219e90c(void);
u8 *func_ov001_0219e920(void);
// Scene function of gSceneFuncs[7] (scene 'Option' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
int RunOptionScene(void *a);
void UpdateOptionScene(s16 *a);
void func_ov001_0219e9a4(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseOptionScene(void);
void InitOptionScene(s16 *a);
// Scene function of gSceneFuncs[15] (scene 'Ending' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
int RunEndingScene(void *a);
