#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146c98.h"

#pragma thumb on

void InitLayoutTableEntries(LayoutTableEntry *entry, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        entry->mVisible = 1;
        entry->mOffsetX = 0;
        entry->mOffsetY = 0;
        entry->mUnk_08 = FALSE;
        entry->mPositionX = 0;
        entry->mPositionY = 0;
        entry->mUseMatrix = 0;
        MTX_Identity22_(entry->mUnk_14);
        MTX_Identity22_(entry->mMatrix);
        entry->mUnk_34 = 1;
        entry->mLabelIndex = -1;
        entry->mLabelCanvas = NULL;
        entry++;
    }
}

#pragma thumb off
