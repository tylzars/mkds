#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void ResetPendingFiles(void) {
    int i;
    Unk0217aa00_16a0_view *view;
    BlockEntry *entry;
    u32 flagBitsMask;
    u32 clearPendingMask;
    flagBitsMask = (0xe0000000u);
    clearPendingMask = (0xdfffffffu);
    view = &data_0217aa00->mUnk_16a0_view;
    i = 0;
    entry = view->mBlockEntries;
    do {
        entry->mPath = 0;
        entry->mBuffer = NULL;
        entry->mUncompressedBuffer = NULL;
        entry->mUnk_84 = entry->mUnk_84 & clearPendingMask;
        entry->mUnk_84 = entry->mUnk_84 & flagBitsMask;
        entry = entry + 1;
        i = i + 1;
    } while (i < 0xc);
    view->mNextLoadIndex = 0xc;
}

#pragma thumb off
