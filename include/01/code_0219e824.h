#pragma once

#include "types.h"

// Scene function of gSceneFuncs[11] (scene 'Nickname' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
int RunNicknameScene(void *a);
void UpdateNicknameScene(s16 *param_1);
void func_ov001_0219e89c(void);
void ReleaseNicknameScene(void);
void InitNicknameScene(s16 *a);
u8 *GetOptionSecondBuffer(void);
u8 *GetOptionFirstBuffer(void);
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
