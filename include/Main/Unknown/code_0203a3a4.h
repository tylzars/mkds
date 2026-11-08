#pragma once

#include "types.h"

typedef struct Unk0203a0dc Unk0203a0dc;

unsigned int func_0203a3a4(void);
void SetNextRaceKind(unsigned int raceKind);
u32 func_0203a3cc(u32 slotIndex);
unsigned int IsCameraChainEnded(void);
u32 func_0203a440(u32 slotIndex);
u32 func_0203a48c(u32 index);
u16 GetDownBits(u32 slotIndex, u32 mask);
unsigned int func_0203a4cc(void);
void func_0203a4d4(u32 a);
unsigned int GetCurrentRaceKind(void);
void SetNextSceneFromPickedValue(Unk0203a0dc *sceneNumbers, u32 pickedValue);
void func_0203a8e0(unsigned int pickedValue);
unsigned int func_0203a8f4(void);
u32 ShouldEndStaffRoll(u32 sceneFrames);
u32 ShouldEndAwardRace(u32 sceneFrames);
void func_0203aaa8(void);
void func_0203aacc(void);
// Slot mInit of the Race scene; not the whole preparation (RunRaceScene and RunScene's prologue run
// before it). Calls in order: CreateOverlayExpHeap (creates the heap that FreeOverlayExpHeap destroys),
// StopWvrAndWait (kinds 3 and 5) or ClearLcdcBankAndStartWvrAndWait + func_02053e74, Init3dEngine, InitDispCap,
// SetupRaceDisplay (screen layout), func_020431e4, InitRace, InitChoisesS, func_020b03bc,
// func_020af99c (not kind 3), func_02043a9c, and the mode 5 net state / mode 2 StartMicInput
// extras. Does not allocate gRace: InitRace does.
void InitRaceScene(void);
void SetupRaceDisplay(void *heap);
u32 ShouldUpdateRace(u32 sceneFrames);
BOOL TryFormatGhostPath(u32 courseId, void *buffer, u32 size);
