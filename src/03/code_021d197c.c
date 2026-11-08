#include "03/code_021d197c.h"
#include "03/code_021d1970.h"
#include "03/unk_021da000.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d1d60.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"
#include "03/code_021d2eb8.h"
#include "03/code_021d2ecc.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"

OamRange *CreateOamRangeFromNceImage(u32 screen, u32 imageIndex, s32 fromFront) {
    OamRange *range = CreateOamRange(screen, gNceFiles[screen][imageIndex].mEntryCount, fromFront);

    CopyNceImageToOamEntries(screen, imageIndex, GetOamRangeEntry(range, 0));
    return range;
}

void InitOamRanges(void) {
    s32 i;

    gOamRanges = AllocZeroedExpHeapBlock(0x450, 4);
    for (i = 0; i < 2; i++) {
        gOamRanges[i].mFreeRanges = CreateFilledPointerStack(0x20, &gOamRanges[i], 0x10);
        gOamRanges[i].mUnk_220 = func_ov003_021d2ecc();
        gOamRanges[i].mListStart.mEntries = func_ov003_021d2eec(i, 0x40);
        gOamRanges[i].mListEnd.mEntries = func_ov003_021d2eec(i, 0x7f) + 1;
        func_ov003_021d2e50(gOamRanges[i].mUnk_220, &gOamRanges[i].mListStart);
        func_ov003_021d2e5c(gOamRanges[i].mUnk_220, &gOamRanges[i].mListEnd);
    }
}

void ReleaseOamRanges(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_ov003_021d2eb8(gOamRanges[i].mUnk_220);
        func_ov003_021d1d4c(gOamRanges[i].mFreeRanges);
    }
    FreeExpHeapBlockAndClearPointer(&gOamRanges);
}

OamRange *CreateOamRange(u32 screen, s32 entryCount, s32 fromFront) {
    OamRange *range;
    u32 interrupts;
    OamRange *node;
    OamRange *neighbor;
    OamEntry *start;

    range = PopPointerStack(gOamRanges[screen].mFreeRanges);
    interrupts = OS_DisableIrqMask(1);
    if (fromFront != 0) {
        node = &gOamRanges[screen].mListStart;
        if (node != &gOamRanges[screen].mListEnd) {
            do {
                neighbor = node->mNext;
                start = node->mEntries + node->mEntryCount;
                if (start + entryCount <= neighbor->mEntries) {
                    range->mEntries = start;
                    AddNodeBefore((u32) neighbor, (u32) range);
                    break;
                }
                node = neighbor;
            } while (node != &gOamRanges[screen].mListEnd);
        }
        if (node == &gOamRanges[screen].mListEnd) {
            OS_Terminate();
        }
    } else {
        node = &gOamRanges[screen].mListEnd;
        if (node != &gOamRanges[screen].mListStart) {
            do {
                neighbor = node->mPrev;
                start = node->mEntries - entryCount;
                if (start >= neighbor->mEntries + neighbor->mEntryCount) {
                    range->mEntries = start;
                    AddNodeBefore((u32) node, (u32) range);
                    break;
                }
                node = neighbor;
            } while (node != &gOamRanges[screen].mListStart);
        }
        if (node == &gOamRanges[screen].mListStart) {
            OS_Terminate();
        }
    }
    OS_EnableIrqMask(interrupts);
    range->mEntryCount = entryCount;
    return range;
}

void DeleteOamRange(OamRange *range) {
    OamEntry *entries = range->mEntries;
    u32 screen = 0;
    s32 i;

    for (i = 0; i < range->mEntryCount; i++, entries++) {
        entries->mUnk_00 = (entries->mUnk_00 & 0xc1fffcff) | 0x200;
    }
    RemoveNodeFromList((u32) range);
    if (range >= (OamRange *) &gOamRanges[1]) {
        screen = 1;
    }
    PushPointerStack(gOamRanges[screen].mFreeRanges, range);
}
