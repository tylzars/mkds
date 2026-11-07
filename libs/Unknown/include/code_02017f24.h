#pragma once

#include "types.h"
#include "code_02017550.h" // NNSiFndHeapHead, NNSFndHeapHandle

// Entry of 16 bytes that NNS_FndRecordStateForFrmHeap takes from the front of the heap: the tag name and both
// allocation positions of the moment, chained through mPrevState.
typedef struct NNSiFndFrmHeapState {
    /* 00 */ u32 mTagName;
    /* 04 */ u8 *mHeadAllocator;
    /* 08 */ u8 *mTailAllocator;
    /* 0c */ struct NNSiFndFrmHeapState *mPrevState;
} NNSiFndFrmHeapState;

// Follows the NNSiFndHeapHead of a frame heap: the two addresses that AllocFromHead_ and AllocFromTail_ move towards
// each other, and the newest recorded state.
typedef struct NNSiFndFrmHeapHead {
    /* 00 */ u8 *mHeadAllocator;
    /* 04 */ u8 *mTailAllocator;
    /* 08 */ NNSiFndFrmHeapState *mState;
} NNSiFndFrmHeapHead;

u32 NNS_FndAdjustFrmHeap(NNSFndHeapHandle heap);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName);
BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tagName);
u32 NNS_FndGetAllocatableSizeForFrmHeapEx(NNSFndHeapHandle heap, int alignment);
void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode);
void *NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap);
NNSFndHeapHandle NNS_FndCreateFrmHeapEx(void *startAddress, u32 size, u16 optFlag);
void FreeTail(NNSiFndHeapHead *heap);
// Also clears the recorded states.
void FreeHead(NNSiFndHeapHead *heap);
void *AllocFromTail_(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment);
void *AllocFromHead_(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment);
NNSiFndHeapHead *InitFrameHeap(void *startAddress, void *endAddress, u16 optFlag);
