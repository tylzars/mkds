#include "Main/Unknown/code_0202ee68.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 GetScrollListHiddenBottomSlot(void) {
    u32 slot;
    slot = (gScrollList->mHiddenTopSlot + 6) % (7);
    return slot;
}

#pragma thumb off
