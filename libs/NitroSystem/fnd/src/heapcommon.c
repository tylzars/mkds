#include "heapcommon.h"
#include "code_020172d0.h"
#include "code_0201750c.h"

// Returns the innermost heap in list whose memory contains memBlock, looking into the child lists first.
NNSiFndHeapHead *FindContainHeap(NNSFndList *list, const void *memBlock) {
    NNSiFndHeapHead *candidate;
    NNSiFndHeapHead *child;

    candidate = NNS_FndGetNextListObject(list, 0);
    while (candidate != 0) {
        if (candidate->mHeapStart <= memBlock && memBlock < candidate->mHeapEnd) {
            child = FindContainHeap(&candidate->mChildList, memBlock);
            if (child == 0) {
                child = candidate;
            }
            return child;
        }
        candidate = NNS_FndGetNextListObject(list, candidate);
    }
    return 0;
}

// Returns the child list of the heap that contains heap, or the root list.
NNSFndList *FindListContainHeap(NNSiFndHeapHead *heap) {
    NNSFndList *list;
    NNSiFndHeapHead *container;

    list = &gHeapList;
    container = FindContainHeap(list, heap);
    if (container != 0) {
        list = &container->mChildList;
    }
    return list;
}

// Fills in the heap header and links the heap into the child list of the heap that contains it.
void NNSi_FndInitHeapHead(NNSiFndHeapHead *heap, u32 signature, void *heapStart, void *heapEnd, u16 optFlag) {
    heap->mSignature = signature;
    heap->mHeapStart = heapStart;
    heap->mHeapEnd = heapEnd;
    heap->mAttribute = 0;
    heap->mAttribute &= ~0xff;
    heap->mAttribute |= optFlag & 0xff;
    NNS_FndInitList(&heap->mChildList, 4);
    if (gHeapListInitialized == 0) {
        NNS_FndInitList(&gHeapList, 4);
        gHeapListInitialized = 1;
    }
    NNS_FndAppendListObject(FindListContainHeap(heap), heap);
}

// Removes the heap from the list of the heap that contains it.
void NNSi_FndFinalizeHeap(NNSiFndHeapHead *heap) {
    NNS_FndRemoveListObject(FindListContainHeap(heap), heap);
}

// Returns the innermost heap whose memory contains memBlock.
NNSFndHeapHandle NNS_FndFindContainHeap(const void *memBlock) {
    return FindContainHeap(&gHeapList, memBlock);
}
