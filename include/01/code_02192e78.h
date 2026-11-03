#pragma once

#include "types.h"

void func_ov001_02192e78(u16 a);
int func_ov001_02192e84(void);
u32 GetOptionPrevState(void);
void RequestOptionState(u32 a);
void SetOptionStateCallbacks(UnkFunc **a);
void func_ov001_02192ec4(void);
void AdvanceOptionStates(void);
void func_ov001_02192f8c(void);
void InitOptionStates(void *heap, s16 a);
void func_ov001_021930ac(void);
void LoadOptionData(void);
void ClearOptionStateCallbacks(void);
