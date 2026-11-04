#pragma once

#include "types.h"

// 16 bytes: two words and two pointers to other RangeEntry (RangeListFree and RangeListAllocAligned unlink and relink
// them).
typedef struct RangeEntry {
    /* 00 */ u32 mStart;
    /* 04 */ u32 mSize;
    /* 08 */ struct RangeEntry *mPrev;
    /* 0c */ struct RangeEntry *mNext;
} RangeEntry;

s32 RangeListFree(RangeEntry **a, RangeEntry **b, u32 c, u32 d);
s32 RangeListAllocAligned(RangeEntry **a, RangeEntry **b, u32 *c, u32 d, u32 e);
s32 RangeListAlloc(RangeEntry **a, RangeEntry **b, u32 *c, u32 d);
s32 RangeListAdd(RangeEntry **a, RangeEntry **b, u32 c, u32 d);
RangeEntry *RangeEntryPoolInit(RangeEntry *p, u32 n);
