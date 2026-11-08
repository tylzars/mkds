#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u32 func_0202f0a8(u32 slotIndex);
u32 func_0202f0c8(InputSlotPair *pair);
u32 func_0202f0fc(InputSlotPair *pair);
void CallScrollListCallback(s32 action, s32 slot, s32 row, s32 selectedSlot);
