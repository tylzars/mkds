#include "Main/Unknown/code_02124bc8.h"
#include "Main/Unknown/code_02124bf0.h"

#pragma thumb on

void DrawLayoutTableEntry(s32 index, Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout,
                          void *oamList, LayoutTableEntry *table) {
    DrawLayoutEntry(index, cells, cellLayout, labelLayout, oamList, OFFSET_PTR(LayoutTableEntry, table, index * 0x40),
                    1);
}

#pragma thumb off
