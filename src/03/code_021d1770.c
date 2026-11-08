#include "03/code_021d1770.h"

void GetOamRangeEntryPosition(OamRange *range, int index, u32 *xPos, s32 *yPos) {
    OamEntry *entries;

    entries = range->mEntries;
    *xPos = (entries[index].mUnk_00 & 0x01ff0000) >> 0x10;
    *yPos = entries[index].mUnk_00 & 0xff;
}
