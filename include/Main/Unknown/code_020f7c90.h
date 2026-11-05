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

// Element of the table behind data_02159c3c, 0xe bytes.
typedef struct Unk02159c3c {
    /* 00 */ u16 mUnk_00[7];
} Unk02159c3c;

extern Unk02159c3c data_02159c3c[];

void func_020f80c0(ItemSlotTable *a, s32 b);
void CreateItemSlotTables(void);
u8 func_020f7ea8(void *a, void *b);
void func_020f7c90(ItemObject *a, Vec3 *b, Vec3 *c);
