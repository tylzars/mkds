#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 func_0202ee20(u32 first, u32 second) {
    return (((gScrollList->mUnk_008[second].mUnk_0e)) - ((gScrollList->mUnk_008[first].mUnk_0e)));
}

u32 GetScrollListSelectedSlot(void) {
    u32 slot;
    slot = (gScrollList->mHiddenTopSlot + gScrollList->mSelectedVisibleRow + 1) % (7);
    return slot;
}

#pragma thumb off
