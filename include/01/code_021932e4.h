#pragma once

#include "types.h"

typedef struct OptionTopMenu OptionTopMenu;

extern u8 data_ov001_021a65dc[];
extern s32 data_ov001_021a65e4[];
extern const char data_ov001_021a8254[];
extern const char data_ov001_021a8260[];

void RegisterOptionTopMenuCallbacks(void);
void func_ov001_02193308(void);
void AdvanceOptionTopMenu(void);
void func_ov001_021933dc(void);
void AdvanceOptionTopMenuState9(void);
void AdvanceOptionTopMenuState8(void);
void AdvanceOptionTopMenuState7(void);
void AdvanceOptionTopMenuState6(void);
void AdvanceOptionTopMenuState5(void);
void AdvanceOptionTopMenuState4(void);
void AdvanceOptionTopMenuState3(void);
void AdvanceOptionTopMenuState2(void);
void AdvanceOptionTopMenuState1(void);
void AdvanceOptionTopMenuState0(void);
void LocateAndQueueOptionTopMenu(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionTopMenu(void);
void InitOptionTopMenu(void *heap);
