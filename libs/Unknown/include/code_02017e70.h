#pragma once

#include "types.h"

// Block of 16 bytes followed by mSize bytes, linked through mPrev and mNext; ExpHeapBlockInit sets it up over a
// range. Halfword 2 holds a byte, seven bits and a flag.
typedef struct ExpHeapBlock {
    /* 00 */ u16 mTag;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mSize;
    /* 08 */ struct ExpHeapBlock *mPrev;
    /* 0c */ struct ExpHeapBlock *mNext;
} ExpHeapBlock;

// Two addresses: ExpHeapBlockGetRange writes the start of a block (minus its offset) and the end of its data.
typedef struct ExpHeapRange {
    /* 00 */ u32 mStart;
    /* 04 */ u32 mEnd;
} ExpHeapRange;

ExpHeapBlock *ExpHeapBlockInit(ExpHeapRange *a, u16 b);
