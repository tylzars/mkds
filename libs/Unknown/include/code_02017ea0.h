#pragma once

#include "types.h"
#include "code_02017e70.h" // NNSiFndExpHeapMBlockHead, NNSiMemRegion

// First and last blocks of a chain linked through mMBHeadPrev and mMBHeadNext of NNSiFndExpHeapMBlockHead.
typedef struct NNSiFndExpMBlockList {
    /* 00 */ NNSiFndExpHeapMBlockHead *mHead;
    /* 04 */ NNSiFndExpHeapMBlockHead *mTail;
} NNSiFndExpMBlockList;

NNSiFndExpHeapMBlockHead *InsertMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *target,
                                       NNSiFndExpHeapMBlockHead *prev);
NNSiFndExpHeapMBlockHead *RemoveMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block);
void GetRegionOfMBlock(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block);
