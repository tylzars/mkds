#pragma once

#include "types.h"

// Header of 16 bytes before each block of an Exp heap, followed by mBlockSize bytes; blocks are linked through
// mMBHeadPrev and mMBHeadNext. mAttribute holds the group ID in bits 0 to 7, the offset to the start of the block in
// bits 8 to 14 and the end of the heap the block was taken from in bit 15.
typedef struct NNSiFndExpHeapMBlockHead {
    /* 00 */ u16 mSignature;
    /* 02 */ u16 mAttribute;
    /* 04 */ u32 mBlockSize;
    /* 08 */ struct NNSiFndExpHeapMBlockHead *mMBHeadPrev;
    /* 0c */ struct NNSiFndExpHeapMBlockHead *mMBHeadNext;
} NNSiFndExpHeapMBlockHead;

// Start and end of a block of memory: GetRegionOfMBlock writes the start of a block (minus its offset) and the end of
// its data.
typedef struct NNSiMemRegion {
    /* 00 */ void *mStart;
    /* 04 */ void *mEnd;
} NNSiMemRegion;

NNSiFndExpHeapMBlockHead *InitMBlock(const NNSiMemRegion *region, u16 signature);
