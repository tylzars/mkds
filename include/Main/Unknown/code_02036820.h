#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Uses the enclosing heap as an Exp heap (no tag check); if NNS_FndAdjustFrmHeap returns 0 because back allocations
// exist, the block is resized to 0.
void FrmHeapShrinkInParent(void *a);
void *CreateFrmHeapFromBack(void *a, u32 b);
void *CreateFrmHeapFromFront(void *a, u32 b);
void *CreateFrmHeapFromMaxFree(void *a);
void *CreateExpHeapFromMaxFree(void *a);
void HeapDestroy(NNSiFndHeapHead *a);
void HeapFree(void *a, void *b);
// A negative alignment takes the block from the back end of the heap.
void *HeapAllocAligned(void *a, u32 b, s32 c);
void *HeapAlloc(void *a, u32 b);
