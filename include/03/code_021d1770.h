#pragma once

#include "types.h"

// 8-byte object at index i of OamRange.mUnk_08: GetOamRangeEntryPosition reads bits 16-24 and bits 0-7 of its word
// at 0x00.
typedef struct OamEntry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} OamEntry;

// Object passed to GetOamRangeEntryPosition: a pointer at 0x08 to OamEntry objects, indexed by its second
// argument, and their number at 0x0c. The two pointers at 0x00 and 0x04 link the objects of a list.
typedef struct OamRange {
    /* 00 */ struct OamRange *mPrev;
    /* 04 */ struct OamRange *mNext;
    /* 08 */ OamEntry *mEntries;
    /* 0c */ u8 mEntryCount;
} OamRange;

void GetOamRangeEntryPosition(OamRange *range, int index, u32 *xPos, s32 *yPos);
