#pragma once

#include "types.h"

typedef struct ItemSlotTable ItemSlotTable;

typedef struct KartItems KartItems;

// Address after one table: start + 2 + rows * columns from the two header bytes
u32 ComputeItemSlotTableDataEnd(u32 arg0);
u8 *LoadItemSlotTableData(ItemSlotTable *param_1, u8 *param_2);
void SetActiveItem(KartItems *p0, unsigned int p1);
// HUD tick: picks the item shown now (random entry of the spin or possible-items list other than the last, or the
// result while stopping); called only on spin tick frames
void PickItemSlotShownItem(KartItems *param_1);
void StopItemSlot(KartItems *param_1);
// After the roulette ran to its end: gives the pool objects back, resets the state, mActiveItem and results; the caller
// gives the item
void FinishItemSlot(KartItems *param_1);
BOOL UpdateItemSlot(KartItems *param_1, KartItems *param_2);
void func_020f86c4(KartItems *param_1);
// Returns without starting when the roulette runs or mActiveItem is set
void StartItemSlot(KartItems *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
void InitItemSlot(KartItems *param_1, KartItems *param_2);
// Weighted roll of one item from a row (the kart's rank, or a forced row); sums the weights of the allowed items, draws
// with the race random, then replaces an item whose pool is full by item 2 (4 in mode 5) and frees pool objects until
// the item fits; writes the spin list when asked; also called by a course object
s32 PickItem(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);
