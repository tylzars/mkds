#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 GetScrollListSelectedRow(void) {
    return (gScrollList->mSelectedRow);
}

void SetScrollListEnabled(u32 enabled) {
    gScrollList->mEnabled = enabled;
}

u32 IsScrollListPickFinished(void) {
    return (gScrollList->mPickFinished);
}

u32 IsScrollListPickStarted(void) {
    return (gScrollList->mPickStarted);
}

#pragma thumb off
