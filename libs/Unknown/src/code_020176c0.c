#include "code_020176c0.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"

// Sets up an Exp heap over startAddress to endAddress with one free block covering all its memory.
NNSiFndHeapHead *InitExpHeap(void *startAddress, void *endAddress, u16 optFlag) {
    NNSiFndHeapHead *heap;
    NNSiFndExpHeapHead *expHeap;
    NNSiMemRegion range;
    NNSiFndExpHeapMBlockHead *block;

    heap = startAddress;
    expHeap = (NNSiFndExpHeapHead *) (heap + 1);
    NNSi_FndInitHeapHead(heap, 0x45585048, expHeap + 1, endAddress, optFlag);
    expHeap->mGroupID = 0;
    expHeap->mFeature = 0;
    expHeap->mFeature &= ~1;
    range.mStart = heap->mHeapStart;
    range.mEnd = heap->mHeapEnd;
    block = InitMBlock(&range, 0x4652);
    expHeap->mMbFreeList.mHead = block;
    expHeap->mMbFreeList.mTail = block;
    expHeap->mMbUsedList.mHead = 0;
    expHeap->mMbUsedList.mTail = 0;
    return heap;
}

// Cuts a used block of size bytes with its data at mblock out of freeBlock, putting what is left in front of and behind
// it back on the free list, and links the used block to the end of the used list.
void *AllocUsedBlockFromFreeBlock(NNSiFndExpHeapHead *expHeap, NNSiFndExpHeapMBlockHead *freeBlock, void *mblock,
                                  u32 size, u16 direction) {
    NNSiMemRegion freeRegion;
    NNSiMemRegion rightRegion;
    NNSiMemRegion usedRegion;
    NNSiFndExpHeapMBlockHead *prev;
    NNSiFndExpHeapMBlockHead *usedBlock;
    u32 clearSize;

    GetRegionOfMBlock(&freeRegion, freeBlock);
    usedBlock = (NNSiFndExpHeapMBlockHead *) ((u32) mblock - 0x10);
    rightRegion.mEnd = freeRegion.mEnd;
    freeRegion.mEnd = usedBlock;
    rightRegion.mStart = (void *) (size + (u32) mblock);
    prev = RemoveMBlock(&expHeap->mMbFreeList, freeBlock);
    if ((u32) freeRegion.mEnd - (u32) freeRegion.mStart < 0x10) {
        freeRegion.mEnd = freeRegion.mStart;
    } else {
        prev = InsertMBlock(&expHeap->mMbFreeList, InitMBlock(&freeRegion, 0x4652), prev);
    }
    if ((u32) rightRegion.mEnd - (u32) rightRegion.mStart < 0x10) {
        rightRegion.mStart = rightRegion.mEnd;
    } else {
        InsertMBlock(&expHeap->mMbFreeList, InitMBlock(&rightRegion, 0x4652), prev);
    }
    clearSize = (u32) rightRegion.mStart - (u32) freeRegion.mEnd;
    {
        volatile u32 zero;

        if ((u16) (((NNSiFndHeapHead *) expHeap - 1)->mAttribute & 0xff) & 1) {
            zero = 0;
            MIi_CpuClear32(zero, freeRegion.mEnd, clearSize);
        }
    }
    usedRegion.mStart = usedBlock;
    usedRegion.mEnd = rightRegion.mStart;
    usedBlock = InitMBlock(&usedRegion, 0x5544);
    usedBlock->mAttribute &= ~0x8000;
    usedBlock->mAttribute |= (direction & 1) << 15;
    {
        u32 offset = (u32) usedBlock - (u32) freeRegion.mEnd;

        usedBlock->mAttribute &= ~0x7f00;
        usedBlock->mAttribute |= ((u16) offset & 0x7f) << 8;
    }
    {
        u8 id = expHeap->mGroupID;

        usedBlock->mAttribute &= ~0xff;
        usedBlock->mAttribute |= id;
    }
    InsertMBlock(&expHeap->mMbUsedList, usedBlock, expHeap->mMbUsedList.mTail);
    return mblock;
}

// Takes size bytes from the start of a free block, aligned to alignment, and returns them or NULL. In the first-fit
// allocation mode the first block that fits is used, otherwise the smallest one.
void *AllocFromHead(NNSiFndHeapHead *heap, u32 size, int alignment) {
    NNSiFndExpHeapHead *expHeap;
    NNSiFndExpHeapMBlockHead *block;
    NNSiFndExpHeapMBlockHead *bestBlock;
    u32 start;
    u32 blockSize;
    u32 bestSize;
    int bestStart;
    u32 mask;
    u32 firstFit;

    expHeap = (NNSiFndExpHeapHead *) (heap + 1);
    firstFit = (u16) (expHeap->mFeature & 1) == 0 ? 1 : 0;
    block = expHeap->mMbFreeList.mHead;
    bestBlock = 0;
    bestStart = 0;
    bestSize = -1;
    if (block != 0) {
        mask = alignment - 1;
        do {
            start = (mask + ((u32) (block + 1))) & ~mask;
            blockSize = block->mBlockSize;
            if (blockSize >= size + (start - ((u32) (block + 1))) && bestSize > blockSize) {
                bestBlock = block;
                bestSize = blockSize;
                bestStart = start;
                if (firstFit != 0) {
                    break;
                }
                if (blockSize == size) {
                    break;
                }
            }
            block = block->mMBHeadNext;
        } while (block != 0);
    }
    if (bestBlock == 0) {
        return 0;
    }
    return AllocUsedBlockFromFreeBlock(expHeap, bestBlock, (void *) bestStart, size, 0);
}

// Takes size bytes from the end of a free block, aligned to alignment, and returns them or NULL. In the first-fit
// allocation mode the first block that fits is used, otherwise the smallest one.
void *AllocFromTail(NNSiFndHeapHead *heap, u32 size, int alignment) {
    int blockSize;
    u32 mask;
    u32 start;
    NNSiFndExpHeapMBlockHead *block;
    NNSiFndExpHeapMBlockHead *bestBlock;
    u32 bestSize;
    NNSiFndExpHeapHead *expHeap;
    int offset;
    int bestStart;
    u32 firstFit;

    expHeap = (NNSiFndExpHeapHead *) (heap + 1);
    firstFit = (u16) (expHeap->mFeature & 1) == 0 ? 1 : 0;
    bestSize = -1;
    bestBlock = 0;
    block = expHeap->mMbFreeList.mTail;
    bestStart = 0;
    if (block != 0) {
        mask = ~(alignment - 1);
        do {
            u32 size0 = block->mBlockSize;

            blockSize = size0;
            start = (blockSize + ((u32) (block + 1)) - size) & mask;
            offset = start - ((u32) (block + 1));
            if (offset >= 0 && bestSize > blockSize) {
                bestBlock = block;
                bestSize = (u32) blockSize;
                bestStart = start;
                if (firstFit != 0) {
                    break;
                }
                if (blockSize == size) {
                    break;
                }
            }
            block = block->mMBHeadPrev;
        } while (block != 0);
    }
    if (bestBlock == 0) {
        return 0;
    }
    return AllocUsedBlockFromFreeBlock(expHeap, bestBlock, (void *) bestStart, size, 1);
}

// Puts the region back on the free list, merged with a free block right before or behind it. Returns 0 when what is
// left is smaller than a block header.
BOOL RecycleRegion(NNSiFndExpHeapHead *expHeap, const NNSiMemRegion *region) {
    NNSiMemRegion merged;
    NNSiFndExpHeapMBlockHead *block;
    NNSiFndExpHeapMBlockHead *prev;

    merged = *region;
    prev = 0;
    block = expHeap->mMbFreeList.mHead;
    if (block != 0) {
        do {
            if ((void *) block < region->mStart) {
                prev = block;
            } else {
                if ((void *) block == region->mEnd) {
                    merged.mEnd = (void *) (block->mBlockSize + ((u32) (block + 1)));
                    RemoveMBlock(&expHeap->mMbFreeList, block);
                }
                break;
            }
            block = block->mMBHeadNext;
        } while (block != 0);
    }
    if (prev != 0) {
        u32 end = prev->mBlockSize + ((u32) (prev + 1));

        if (end == (u32) region->mStart) {
            merged.mStart = prev;
            prev = RemoveMBlock(&expHeap->mMbFreeList, prev);
        }
    }
    if ((u32) merged.mEnd - (u32) merged.mStart < 0x10) {
        return 0;
    }
    InsertMBlock(&expHeap->mMbFreeList, InitMBlock(&merged, 0x4652), prev);
    return 1;
}

// Sets up an Exp heap in the memory of size bytes at startAddress, or returns NULL when it is too small.
NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag) {
    void *bufferEnd;

    bufferEnd = (void *) ((size + (u32) startAddress) & ~3);
    startAddress = (void *) (((u32) startAddress + 3) & ~3);
    if (startAddress > bufferEnd || (u32) bufferEnd - (u32) startAddress < 0x4c) {
        return 0;
    }
    return InitExpHeap(startAddress, bufferEnd, optFlag);
}

// Takes the heap out of the heap list; its memory stays with the caller.
void NNS_FndDestroyExpHeap(NNSFndHeapHandle heap) {
    NNSi_FndFinalizeHeap(heap);
}

// Allocates size bytes, rounded up to a multiple of 4 and at least 4, from the front of the heap, or from the back when
// alignment is negative.
void *NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle heap, u32 size, int alignment) {
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;
    if (alignment >= 0) {
        return AllocFromHead(heap, size, alignment);
    }
    return AllocFromTail(heap, size, -alignment);
}

// Grows or shrinks the used block at memBlock to size bytes and returns its new size, or 0 when it cannot grow.
u32 NNS_FndResizeForMBlockExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size) {
    NNSiMemRegion freeRegion;
    u32 freeStart;
    NNSiFndExpHeapMBlockHead *freeBlock;
    NNSiFndExpHeapMBlockHead *prev;
    NNSiMemRegion cutRegion;
    u32 oldSize;
    NNSiFndExpHeapHead *expHeap;
    NNSiFndExpHeapMBlockHead *block;
    u32 newEnd;
    u32 blockEnd;
    u32 clearSize;

    block = (NNSiFndExpHeapMBlockHead *) ((u8 *) memBlock - 0x10);
    oldSize = block->mBlockSize;
    size = (size + 3) & ~3;
    expHeap = (NNSiFndExpHeapHead *) (heap + 1);
    if (size == oldSize) {
        return size;
    }
    if (size > oldSize) {
        freeBlock = expHeap->mMbFreeList.mHead;
        blockEnd = oldSize + ((u32) (block + 1));
        if (freeBlock != 0) {
            do {
                if ((u32) freeBlock == blockEnd) {
                    break;
                }
                freeBlock = freeBlock->mMBHeadNext;
            } while (freeBlock != 0);
        }
        if (freeBlock == 0 || size > oldSize + 0x10 + freeBlock->mBlockSize) {
            return 0;
        }
        GetRegionOfMBlock(&freeRegion, freeBlock);
        prev = RemoveMBlock(&expHeap->mMbFreeList, freeBlock);
        newEnd = size + (u32) memBlock;
        freeStart = (u32) freeRegion.mStart;
        freeRegion.mStart = (void *) newEnd;
        if ((u32) freeRegion.mEnd - newEnd < 0x10) {
            freeRegion.mStart = freeRegion.mEnd;
        }
        block->mBlockSize = (u32) freeRegion.mStart - (u32) memBlock;
        if ((u32) freeRegion.mEnd - (u32) freeRegion.mStart >= 0x10) {
            InsertMBlock(&expHeap->mMbFreeList, InitMBlock(&freeRegion, 0x4652), prev);
        }
        clearSize = (u32) freeRegion.mStart - freeStart;
        {
            volatile u32 zero;

            if ((u16) (heap->mAttribute & 0xff) & 1) {
                zero = 0;
                MIi_CpuClear32(zero, (void *) freeStart, clearSize);
            }
        }
    } else {
        cutRegion.mStart = (void *) (size + (u32) memBlock);
        cutRegion.mEnd = (void *) (block->mBlockSize + ((u32) (block + 1)));
        block->mBlockSize = size;
        if (RecycleRegion(expHeap, &cutRegion) == 0) {
            block->mBlockSize = oldSize;
        }
    }
    return block->mBlockSize;
}

// Returns the used block at memBlock to the free list.
void NNS_FndFreeToExpHeap(NNSFndHeapHandle heap, void *memBlock) {
    NNSiFndExpHeapHead *expHeap;
    NNSiFndExpHeapMBlockHead *block;
    NNSiMemRegion range;

    block = (NNSiFndExpHeapMBlockHead *) ((u8 *) memBlock - 0x10);
    expHeap = (NNSiFndExpHeapHead *) (heap + 1);
    GetRegionOfMBlock(&range, block);
    RemoveMBlock(&expHeap->mMbUsedList, block);
    RecycleRegion(expHeap, &range);
}

// Returns the sum of the sizes of all free blocks.
u32 NNS_FndGetTotalFreeSizeForExpHeap(NNSFndHeapHandle heap) {
    NNSiFndExpHeapMBlockHead *block;
    u32 total;

    block = ((NNSiFndExpHeapHead *) (heap + 1))->mMbFreeList.mHead;
    total = 0;
    if (block == 0) {
        return total;
    }
    do {
        total += block->mBlockSize;
        block = block->mMBHeadNext;
    } while (block != 0);
    return total;
}

// Returns the size of the largest block that can be allocated with the given alignment (its sign is ignored).
u32 NNS_FndGetAllocatableSizeForExpHeapEx(NNSFndHeapHandle heap, int alignment) {
    u32 mask;
    u32 bestSize;
    u32 bestOffset;
    NNSiFndExpHeapMBlockHead *block;
    u32 blockStart;
    u32 blockEnd;
    u32 alignedStart;
    u32 fitSize;
    u32 offset;

    mask = Abs(alignment);
    bestSize = 0;
    bestOffset = -1;
    for (block = ((NNSiFndExpHeapHead *) (heap + 1))->mMbFreeList.mHead; block != 0; block = block->mMBHeadNext) {
        blockStart = (u32) (block + 1);
        alignedStart = ((u32) (mask - 1) + blockStart) & ~(mask - 1);
        blockEnd = block->mBlockSize + blockStart;
        if (alignedStart < blockEnd) {
            fitSize = blockEnd - alignedStart;
            offset = alignedStart - blockStart;
            if (bestSize < fitSize || (bestSize == fitSize && bestOffset > offset)) {
                bestSize = fitSize;
                bestOffset = offset;
            }
        }
    }
    return bestSize;
}
