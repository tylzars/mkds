#include "code_02017ea0.h"

// Writes the start of the block (before its offset) and the end of its data to region.
void GetRegionOfMBlock(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block) {
    region->mStart = (u8 *) block - (u16) ((block->mAttribute >> 8) & 0x7f);
    region->mEnd = (void *) (block->mBlockSize + (u32) (block + 1));
}

// Unlinks block from list and returns the block before it.
NNSiFndExpHeapMBlockHead *RemoveMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block) {
    NNSiFndExpHeapMBlockHead *prev;
    NNSiFndExpHeapMBlockHead *next;

    prev = block->mMBHeadPrev;
    next = block->mMBHeadNext;
    if (prev != 0) {
        prev->mMBHeadNext = next;
    } else {
        list->mHead = next;
    }
    if (next != 0) {
        next->mMBHeadPrev = prev;
    } else {
        list->mTail = prev;
    }
    return prev;
}

// Links target into list after prev, or at the start when prev is NULL, and returns it.
NNSiFndExpHeapMBlockHead *InsertMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *target,
                                       NNSiFndExpHeapMBlockHead *prev) {
    NNSiFndExpHeapMBlockHead *next;

    target->mMBHeadPrev = prev;
    if (prev != 0) {
        next = prev->mMBHeadNext;
        prev->mMBHeadNext = target;
    } else {
        next = list->mHead;
        list->mHead = target;
    }
    target->mMBHeadNext = next;
    if (next != 0) {
        next->mMBHeadPrev = target;
    } else {
        list->mTail = target;
    }
    return target;
}
