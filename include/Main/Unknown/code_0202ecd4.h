#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 func_0202ecd4(u32 slotIndex, u32 mask);
u16 func_0202ecf0(InputSlot *slot, u32 mask);
void AdvanceScrollListRightColumnTimer(void);
void SetScrollListRightColumnHighBits(s32 highBits);
void PlaceScrollListCursor(void);
