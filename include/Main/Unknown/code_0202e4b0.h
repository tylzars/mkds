#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"

void AdvanceScrollList(void);
void InitScrollList(void *heap, s32 b, const void *groupFirstEntries, u16 cursorEntry, u16 e, s32 f,
                    LayoutTableEntry *entries, void *rects, const void *screenMap, s32 upRectIndex, s32 downRectIndex,
                    s32 firstRowRectIndex, s32 rowCount,
                    void (*callback)(int heap, int b, int groupFirstEntries, int cursorEntry));
