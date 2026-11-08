#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

// A weight table parsed from "Item/ItemSlotList.dat": mRowCount rows of 18 halfwords (one weight per item) plus one end
// row of 0xffff. Three globals: data_0217bc6c, data_0217bc64 (row = the kart's rank) and data_0217bc74 (row = a forced
// argument minus one).
typedef struct ItemSlotTable {
    /* 00 */ s32 mRowCount;
    /* 04 */ u16 (*mRows)[0x12];
} ItemSlotTable;

extern ItemSlotTable data_0217bc74;

extern ItemSlotTable data_0217bc64;

extern ItemSlotTable data_0217bc6c;

// Element of the table behind gItemSlotRowRemaps, 0xe bytes.
typedef struct ItemSlotRowRemap {
    /* 00 */ u16 mSourceRowNumbers[7];
} ItemSlotRowRemap;

extern ItemSlotRowRemap gItemSlotRowRemaps[];

void func_020f80c0(ItemSlotTable *table, s32 kartCount);
void CreateItemSlotTables(void);
u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam);
void func_020f7c90(ItemObject *item, Vec3 *otherPos, Vec3 *normal);
