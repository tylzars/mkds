#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void SetScrollListSlotVisible(s32 slot, s32 visible) {
    s32 group;
    for (group = 0; group < gScrollList->mGroupCount; group++) {
        ScrollList *scrollList = gScrollList;
        scrollList->mEntries[slot + scrollList->mGroupFirstEntries[group]].mUnk_00 = visible;
    }
}

#pragma thumb off
