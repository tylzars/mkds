#pragma once

#include "types.h"

void AdvanceSelectReturnState1(void);
void AdvanceSelectReturnState0(void);
void RefreshAndQueueSelectReturnPaletteBits(s32 a);
s32 LoadSelectReturn(s32 a);
void InitSelectReturnDisplay(void);
