#include "03/code_021d1970.h"

void *GetOamRangeEntry(OamRange *range, int index) {
    return &range->mEntries[index];
}

u8 GetOamRangeEntryCount(OamRange *range) {
    return range->mEntryCount;
}
