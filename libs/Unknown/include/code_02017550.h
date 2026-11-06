#pragma once

#include "types.h"
#include "code_0212d214.h"

// Header at the start of every heap: mSignature tells the heap type, mLink puts the heap in the child list of the heap
// that contains it, and the heap's own children hang off mChildList (link offset 4). The memory the heap hands out lies
// between mHeapStart and mHeapEnd. The low byte of mAttribute holds the heap's option optFlag.
typedef struct NNSiFndHeapHead {
    /* 00 */ u32 mSignature;
    /* 04 */ NNSFndLink mLink;
    /* 0c */ NNSFndList mChildList;
    /* 18 */ void *mHeapStart;
    /* 1c */ void *mHeapEnd;
    /* 20 */ u32 mAttribute;
} NNSiFndHeapHead;

typedef NNSiFndHeapHead *NNSFndHeapHandle;

extern u32 gHeapListInitialized;
extern NNSFndList gHeapList;

NNSFndHeapHandle NNS_FndFindContainHeap(const void *memBlock);
void NNSi_FndFinalizeHeap(NNSiFndHeapHead *heap);
void NNSi_FndInitHeapHead(NNSiFndHeapHead *heap, u32 signature, void *heapStart, void *heapEnd, u16 optFlag);
NNSFndList *FindListContainHeap(NNSiFndHeapHead *heap);
NNSiFndHeapHead *FindContainHeap(NNSFndList *list, const void *memBlock);
