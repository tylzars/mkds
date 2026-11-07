#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"
#include "g2d_NOB_load.h"
#include "code_020222ec.h"

#pragma thumb on

void InitLayoutTable(void *heap, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, Unk02124b1c **tableOut) {
    u16 count;

    count = cellLayout->mUnk_06;
    if (labelLayout != NULL) {
        count = count + labelLayout->mUnk_06;
    }
    *tableOut = HeapAlloc(heap, count << 6);
    InitLayoutTableEntries(*tableOut, count);
}

// Draws entry a: first the entry it is chained to, then itself; appends the cell OAMs to the list, and returns without
// drawing when the entry is disabled or lies off the 256 x 192 screen.
u32 DrawLayoutEntry(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout,
                    Unk02124c70 *oamList, Unk02124b1c *entry, s32 incrementFlag) {
    s32 width;
    s32 height;
    s32 *matrix;
    Unk0201ea84 l20[3];
    s32 position[2];
    Unk020224e0_c *cellData;
    Unk0201ea30_08 *cellEntry;
    u16 groupIndex;
    u32 oamCount;
    Unk02124c70_00 *group;

    if (entry->mUnk_38 != -1) {
        DrawLayoutEntry(entry->mUnk_38 + cellLayout->mUnk_06, cells, cellLayout, labelLayout, oamList,
                        entry - index + cellLayout->mUnk_06 + entry->mUnk_38, incrementFlag);
    }
    matrix = NULL;
    if (entry->mUnk_00 == 0) {
        return (u32) matrix;
    }
    if (index >= cellLayout->mUnk_06) {
        Unk0212428c *labelEntry = func_0201ea58(labelLayout, index - cellLayout->mUnk_06);
        cellData = entry->mUnk_3c->mUnk_44;
        l20[0] = labelEntry->mUnk_00;
        l20[1] = labelEntry->mUnk_02;
        width = cellData->mUnk_08 - cellData->mUnk_0c;
        height = cellData->mUnk_0a - cellData->mUnk_0e;
        position[0] = l20[0].mUnk_00_0 << 12;
        position[1] = l20[1].mUnk_00_0 << 12;
    } else {
        cellEntry = func_0201ea30(cellLayout, index);
        cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mUnk_04);
        l20[2] = cellEntry->mUnk_00_0;
        l20[0] = l20[2];
        l20[1] = cellEntry->mUnk_00_2;
        width = cellData->mUnk_08 - cellData->mUnk_0c;
        height = cellData->mUnk_0a - cellData->mUnk_0e;
        position[0] = ((width >> 1) + func_0201ebe8(l20[2], width)) << 12;
        position[1] = ((height >> 1) + func_0201eba0(cellEntry->mUnk_00_2, height)) << 12;
    }
    if (entry->mUnk_08 != FALSE) {
        if (index >= cellLayout->mUnk_06) {
            position[0] = entry->mUnk_0c << 12;
            position[1] = entry->mUnk_0e << 12;
        } else {
            position[0] = (entry->mUnk_0c + (width >> 1) * (1 - l20[0].mUnk_00_12)) << 12;
            position[1] = (entry->mUnk_0e + (height >> 1) * (1 - l20[1].mUnk_00_12)) << 12;
        }
    }
    position[0] += entry->mUnk_04 << 12;
    position[1] += entry->mUnk_06 << 12;
    if ((position[0] >> 12) + width < 0 || (position[0] >> 12) - width > 0x100 || (position[1] >> 12) + height < 0 ||
        (position[1] >> 12) - height > 0xc0) {
        return 0;
    }
    groupIndex = func_020ae5e4(oamList);
    if (entry->mUnk_10 != 0) {
        matrix = entry->mUnk_24;
        group = &oamList->mUnk_000[groupIndex];
        group->mUnk_00[0].mUnk_00[3] = entry->mUnk_14[0] >> 4;
        group->mUnk_00[1].mUnk_00[3] = entry->mUnk_14[1] >> 4;
        group->mUnk_00[2].mUnk_00[3] = entry->mUnk_14[2] >> 4;
        group->mUnk_00[3].mUnk_00[3] = entry->mUnk_14[3] >> 4;
        if (incrementFlag != 0) {
            func_020ae5d4(oamList);
        }
    }
    oamCount = oamList->mUnk_400;
    oamList->mUnk_400 += NNS_G2dMakeCellToOams(&oamList->mUnk_000[0].mUnk_00[oamCount], 0x80 - oamCount, cellData,
                                               matrix, position, groupIndex, entry->mUnk_34);
}

void DrawLayoutTable(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout, void *oamList,
                     Unk02124b1c *table) {
    s32 i;
    for (i = ((Unk0201ea30 *) cellLayout)->mUnk_06 - 1; i >= 0; i--) {
        DrawLayoutEntry(i, cells, cellLayout, labelLayout, oamList, (Unk02124b1c *) table + i, 1);
    }
}

void func_02124bf0(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, void *labelLayout, void *oamList, void *table) {
    s32 i;
    for (i = ((Unk0201ea30 *) cellLayout)->mUnk_06 - 1; i >= 0; i--) {
        DrawLayoutEntry(i, cells, cellLayout, labelLayout, oamList, (Unk02124b1c *) table + i, 0);
    }
}

#pragma thumb off
