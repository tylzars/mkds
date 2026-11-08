#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u16 GetPackedTouchPoint(void);
void func_02046c74(void);
void func_02046ca8(InputSlotPair *pair, s32 b, s32 c);
void UpdateTouchMicInput(void);
void func_02046e24(void);
void func_02046e84(void);
void StopMicInput(void);
void StopTouchAutoSampling(void);
void StartMicInput(void *heap);
void StartTouchAutoSampling(void);
