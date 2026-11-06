#include "code_02017f24.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"

// Sets up a frame heap over startAddress to endAddress with nothing allocated.
NNSiFndHeapHead *InitFrameHeap(void *startAddress, void *endAddress, u16 optFlag) {
    NNSiFndHeapHead *heap;
    NNSiFndFrmHeapHead *frmHeap;

    heap = startAddress;
    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    NNSi_FndInitHeapHead(heap, 0x46524d48, frmHeap + 1, endAddress, optFlag);
    frmHeap->mHeadAllocator = heap->mHeapStart;
    frmHeap->mTailAllocator = heap->mHeapEnd;
    frmHeap->mState = 0;
    return heap;
}

// Takes size bytes from the front of the free memory, aligned to alignment, and returns them or NULL.
void *AllocFromHead_(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment) {
    u32 mask;
    u32 start;
    u32 end;
    u32 oldHead;
    u32 clearSize;

    oldHead = (u32) frmHeap->mHeadAllocator;
    mask = alignment - 1;
    start = (mask + oldHead) & ~mask;
    end = size + start;
    if (end > (u32) frmHeap->mTailAllocator) {
        return 0;
    }
    clearSize = end - oldHead;
    {
        volatile u32 zero;

        if ((u16) (((NNSiFndHeapHead *) frmHeap - 1)->mAttribute & 0xff) & 1) {
            zero = 0;
            MIi_CpuClear32(zero, (void *) oldHead, clearSize);
        }
    }
    frmHeap->mHeadAllocator = (void *) end;
    return (void *) start;
}

// Takes size bytes from the end of the free memory, aligned to alignment, and returns them or NULL.
void *AllocFromTail_(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment) {
    u32 mask;
    u32 oldTail;
    u32 start;
    u32 clearSize;

    oldTail = (u32) frmHeap->mTailAllocator;
    mask = alignment - 1;
    start = (oldTail - size) & ~mask;
    if (start < (u32) frmHeap->mHeadAllocator) {
        return 0;
    }
    clearSize = oldTail - start;
    {
        volatile u32 zero;

        if ((u16) (((NNSiFndHeapHead *) frmHeap - 1)->mAttribute & 0xff) & 1) {
            zero = 0;
            MIi_CpuClear32(zero, (void *) start, clearSize);
        }
    }
    frmHeap->mTailAllocator = (void *) start;
    return (void *) start;
}

// Frees everything taken from the front of the heap and drops the recorded states.
void FreeHead(NNSiFndHeapHead *heap) {
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    frmHeap->mHeadAllocator = heap->mHeapStart;
    frmHeap->mState = 0;
}

// Frees everything taken from the back of the heap, also in the recorded states.
void FreeTail(NNSiFndHeapHead *heap) {
    NNSiFndFrmHeapState *state;
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    state = frmHeap->mState;
    if (state != 0) {
        do {
            state->mTailAllocator = heap->mHeapEnd;
            state = state->mPrevState;
        } while (state != 0);
    }
    frmHeap->mTailAllocator = heap->mHeapEnd;
}

// Sets up a frame heap in the memory of size bytes at startAddress, or returns NULL when it is too small.
NNSFndHeapHandle NNS_FndCreateFrmHeapEx(void *startAddress, u32 size, u16 optFlag) {
    void *bufferEnd;

    bufferEnd = (void *) ((size + (u32) startAddress) & ~3);
    startAddress = (void *) (((u32) startAddress + 3) & ~3);
    if (startAddress > bufferEnd || (u32) bufferEnd - (u32) startAddress < 0x30) {
        return 0;
    }
    return InitFrameHeap(startAddress, bufferEnd, optFlag);
}

// Takes the heap out of the heap list; its memory stays with the caller.
void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap) {
    NNSi_FndFinalizeHeap(heap);
}

// Allocates size bytes, rounded up to a multiple of 4 and at least 4, from the front of the heap, or from the back when
// alignment is negative.
void *NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment) {
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;
    if (alignment >= 0) {
        return AllocFromHead_(frmHeap, size, alignment);
    }
    return AllocFromTail_(frmHeap, size, -alignment);
}

// Frees the front of the heap for bit 0 of mode and the back for bit 1.
void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode) {
    if (mode & 1) {
        FreeHead(heap);
    }
    if (mode & 2) {
        FreeTail(heap);
    }
}

// Returns the size of the largest block that can be allocated with the given alignment (its sign is ignored).
u32 NNS_FndGetAllocatableSizeForFrmHeapEx(NNSFndHeapHandle heap, int alignment) {
    u32 mask;
    u32 start;
    u32 tail;
    NNSiFndFrmHeapHead *frmHeap;

    mask = Abs(alignment);
    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    tail = (u32) frmHeap->mTailAllocator;
    start = ((mask - 1) + (u32) frmHeap->mHeadAllocator) & ~(mask - 1);
    if (start > tail) {
        return 0;
    }
    return tail - start;
}

// Records both allocation positions under tagName in a 16-byte entry taken from the front; returns 0 when there is no
// room for it.
BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tagName) {
    u32 oldHead;
    NNSiFndFrmHeapState *state;
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    oldHead = (u32) frmHeap->mHeadAllocator;
    state = AllocFromHead_(frmHeap, 0x10, 4);
    if (state == 0) {
        return 0;
    }
    state->mTagName = tagName;
    state->mHeadAllocator = (void *) oldHead;
    state->mTailAllocator = frmHeap->mTailAllocator;
    state->mPrevState = frmHeap->mState;
    frmHeap->mState = state;
    return 1;
}

// Goes back to the state recorded under tagName, or to the newest one when tagName is 0; returns 0 when there is none.
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName) {
    NNSiFndFrmHeapState *state;
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    state = frmHeap->mState;
    if (tagName != 0 && state != 0) {
        do {
            if (state->mTagName == tagName) {
                break;
            }
            state = state->mPrevState;
        } while (state != 0);
    }
    if (state == 0) {
        return 0;
    }
    frmHeap->mHeadAllocator = state->mHeadAllocator;
    frmHeap->mTailAllocator = state->mTailAllocator;
    frmHeap->mState = state->mPrevState;
    return 1;
}

// Cuts the end of the heap back to the allocated front and returns the new size of the heap; returns 0 when memory is
// allocated from the back.
u32 NNS_FndAdjustFrmHeap(NNSFndHeapHandle heap) {
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = (NNSiFndFrmHeapHead *) (heap + 1);
    if ((u32) heap->mHeapEnd - (u32) frmHeap->mTailAllocator != 0) {
        return 0;
    }
    heap->mHeapEnd = frmHeap->mHeadAllocator;
    frmHeap->mTailAllocator = heap->mHeapEnd;
    return (u32) heap->mHeapEnd - (u32) heap;
}
