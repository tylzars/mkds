#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // LayoutTableEntry, Unk02021dc8, Unk0201ea30
#include "code_02022030.h" // GXOamAttr

// 0x20 bytes: four 8-byte entries (the table behind OamList is indexed in 8-byte steps by DrawLayoutEntry and in
// 0x20-byte steps for the groups of four it fills).
typedef struct Unk02124c70_00 {
    /* 00 */ GXOamAttr mUnk_00[4];
} Unk02124c70_00;

// 0x404 bytes: 0x20 groups of four 8-byte entries, then two halfwords (DrawLayoutEntry adds the return value of
// NNS_G2dMakeCellToOams to mUnk_400; GetOamMatrixCount returns mUnk_402).
typedef struct OamList {
    /* 000 */ Unk02124c70_00 mUnk_000[0x20];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} OamList;

void InitLayoutTable(void *heap, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, LayoutTableEntry **tableOut);
u32 DrawLayoutEntry(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, OamList *oamList,
                    LayoutTableEntry *entry, s32 incrementFlag);
void DrawLayoutTable(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout, void *oamList,
                     LayoutTableEntry *table);
void func_02124bf0(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, void *labelLayout, void *oamList, void *table);
