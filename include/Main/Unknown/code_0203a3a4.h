#pragma once

#include "types.h"

typedef struct Unk0203a0dc Unk0203a0dc;

unsigned int func_0203a3a4(void);
void SetNextRaceKind(unsigned int p0);
u32 func_0203a3cc(u32 a);
unsigned int IsCameraChainEnded(void);
u32 func_0203a440(u32 a);
u32 func_0203a48c(u32 arg0);
u16 func_0203a4a8(u32 a, u32 b);
unsigned int func_0203a4cc(void);
void func_0203a4d4(u32 a);
unsigned int GetCurrentRaceKind(void);
void func_0203a520(Unk0203a0dc *a, u32 b);
void func_0203a8e0(unsigned int p0);
unsigned int func_0203a8f4(void);
u32 func_0203a908(u32 a);
u32 func_0203a9ec(u32 a);
void func_0203aaa8(void);
void func_0203aacc(void);
// Slot mInit of the Race scene; not the whole preparation (RunRaceScene and RunScene's prologue run
// before it). Calls in order: CreateOverlayExpHeap (creates the heap that FreeOverlayExpHeap destroys),
// StopWvrAndWait (kinds 3 and 5) or ClearLcdcBankAndStartWvrAndWait + func_02053e74, Init3dEngine, func_02056158,
// func_0203ad58 (screen layout), func_020431e4, InitRace, InitChoisesS, func_020b03bc,
// func_020af99c (not kind 3), func_02043a9c, and the mode 5 net state / mode 2 func_02046fb4
// extras. Does not allocate gRace: InitRace does.
void InitRaceScene(void);
void func_0203ad58(void *a);
u32 func_0203afe4(u32 a);
BOOL func_0203b018(u32 a, void *b, u32 c);
