#pragma once

#include "types.h"
#include "Main/Unknown/code_020487fc.h" // SceneNumbers

s32 func_02055730(u16 a);
s32 func_0205579c(s32 a, s32 b);
s32 func_02055808(s32 a);
void func_020559ec(const void *entryName, s32 entryIndex, s32 keepMask);
// Scene function of gSceneFuncs[8] (scene 'Record' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunRecordScene(SceneNumbers *sceneNumbers);
void func_02055a94(void);
BOOL func_02055afc(void);
BOOL func_02055b1c(void);
void func_02055bd4(u32 frameCount);
void func_02055c18(u32 frameCount);
void StopDispCapBlend(void);
void StartDispCapBlend(u8 blendMin);
void AdvanceDispCap(s32 a);
void AdvanceDispCapBlend(s32 a);
void ToggleDispCapBanks(void);
void SetupDispCap(void);
void SetupDispCapMode1(void);
void SetDispCapMode(s32 mode);
u32 ClearDispCapPointer(void);
void InitDispCap(void *heap);
u8 func_02056208(void);
