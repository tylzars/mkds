#include "code_02017e70.h"

// Sets up an empty block header at the start of the region, sized to the rest of the region.
NNSiFndExpHeapMBlockHead *InitMBlock(const NNSiMemRegion *region, u16 signature) {
    NNSiFndExpHeapMBlockHead *block;

    block = region->mStart;
    block->mSignature = signature;
    block->mAttribute = 0;
    block->mBlockSize = (u32) region->mEnd - (u32) (block + 1);
    block->mMBHeadPrev = 0;
    block->mMBHeadNext = 0;
    return block;
}
