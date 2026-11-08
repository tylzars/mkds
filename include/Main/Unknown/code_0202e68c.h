#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

void func_0202e68c(void *dest, u32 size);
void func_0202e6a0(void *dest, u32 value, u32 size);
void AdvanceScrollListPick(void);
void AdvanceScrollListScrollDown(void);
void AdvanceScrollListScrollUp(void);
void AdvanceScrollListSelectDown(void);
void AdvanceScrollListSelectUp(void);
void AdvanceScrollListState0(void);
u16 func_0202ec7c(u32 slotIndex, u32 mask);
u16 func_0202ec98(InputSlot *slot, u32 mask);
