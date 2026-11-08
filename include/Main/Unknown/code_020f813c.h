#pragma once

#include "types.h"

typedef struct ItemSlotTable ItemSlotTable;

typedef struct KartItems KartItems;

// Address after one table: start + 2 + rows * columns from the two header bytes
u8 *ComputeItemSlotTableDataEnd(u8 *data);
u8 *LoadItemSlotTableData(ItemSlotTable *table, u8 *data);
void SetActiveItem(KartItems *kartItems, unsigned int itemIndex);
// HUD tick: picks the item shown now (random entry of the spin or possible-items list other than the last, or the
// result while stopping); called only on spin tick frames
void PickItemSlotShownItem(KartItems *slot);
void StopItemSlot(KartItems *slot);
// After the roulette ran to its end: gives the pool objects back, resets the state, mActiveItem and results; the caller
// gives the item
void FinishItemSlot(KartItems *slot);
BOOL UpdateItemSlot(KartItems *slot, KartItems *kartItems);
void func_020f86c4(KartItems *slot);
// Returns without starting when the roulette runs or mActiveItem is set
void StartItemSlot(KartItems *slot, s32 forcedRowHandle, s32 rank, s32 isHumanGhostOrPeer, s32 shortSpin);
void InitItemSlot(KartItems *slot, KartItems *kartItems);
// Weighted roll of one item from a row (the kart's rank, or a forced row); sums the weights of the allowed items, draws
// with the race random, then replaces an item whose pool is full by item 2 (4 in mode 5) and frees pool objects until
// the item fits; writes the spin list when asked; also called by a course object
s32 PickItem(s32 kartVariant, s32 forcedRowHandle, s32 param_3, s32 param_4, s32 isEntryKart, s32 itemCount);
