#include "Main/Unknown/code_02036820.h"
#include "code_020176c0.h"
#include "frameheap.h"
#include "heapcommon.h"
#include "code_0200fc8c.h"

void *HeapAlloc(void *a, u32 b) {
    NNSiFndHeapHead *h = a;
    void *c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return c;
}

void *HeapAllocAligned(void *a, u32 b, s32 c) {
    NNSiFndHeapHead *h = a;
    void *d = NULL;
    u32 e;
    switch (h->mSignature) {
        case 0x45585048:
            d = NNS_FndAllocFromExpHeapEx(a, b, c);
            break;
        case 0x46524d48:
            e = OS_DisableInterrupts();
            d = NNS_FndAllocFromFrmHeapEx(a, b, c);
            OS_RestoreInterrupts(e);
            break;
    }
    return d;
}

void HeapFree(void *a, void *b) {
    NNSiFndHeapHead *h = a;
    switch (h->mSignature) {
        case 0x45585048:
            NNS_FndFreeToExpHeap(a, b);
            break;
        case 0x46524d48:
            break;
    }
}

void HeapDestroy(NNSiFndHeapHead *a) {
    NNSiFndHeapHead *h = a;
    NNSiFndHeapHead *p;
    switch (h->mSignature) {
        case 0x45585048:
            NNS_FndDestroyExpHeap(a);
            break;
        case 0x46524d48:
            NNS_FndDestroyFrmHeap(a);
            break;
    }
    p = NNS_FndFindContainHeap(a);
    if (p == NULL) {
        return;
    }
    switch (p->mSignature) {
        case 0x45585048:
            NNS_FndFreeToExpHeap(p, a);
            break;
        case 0x46524d48:
            break;
    }
}

void *CreateExpHeapFromMaxFree(void *a) {
    NNSiFndHeapHead *h = a;
    u32 b = 0;
    void *c;
    switch (h->mSignature) {
        case 0x45585048:
            b = NNS_FndGetAllocatableSizeForExpHeapEx(a, 4);
            break;
        case 0x46524d48:
            b = NNS_FndGetAllocatableSizeForFrmHeapEx(a, 4);
            break;
    }
    c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return NNS_FndCreateExpHeapEx(c, b, 1);
}

void *CreateFrmHeapFromMaxFree(void *a) {
    NNSiFndHeapHead *h = a;
    u32 b = 0;
    void *c;
    switch (h->mSignature) {
        case 0x45585048:
            b = NNS_FndGetAllocatableSizeForExpHeapEx(a, 4);
            break;
        case 0x46524d48:
            b = NNS_FndGetAllocatableSizeForFrmHeapEx(a, 4);
            break;
    }
    c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(c, b, 1);
}

void *CreateFrmHeapFromFront(void *a, u32 b) {
    NNSiFndHeapHead *h = a;
    void *c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(c, b, 1);
}

void *CreateFrmHeapFromBack(void *a, u32 b) {
    NNSiFndHeapHead *h = a;
    void *c = NULL;
    u32 d;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, -4);
            break;
        case 0x46524d48:
            d = OS_DisableInterrupts();
            c = NNS_FndAllocFromFrmHeapEx(a, b, -4);
            OS_RestoreInterrupts(d);
            break;
    }
    return NNS_FndCreateFrmHeapEx(c, b, 1);
}

void FrmHeapShrinkInParent(void *a) {
    u32 b = NNS_FndAdjustFrmHeap(a);
    NNS_FndResizeForMBlockExpHeap(NNS_FndFindContainHeap(a), a, b);
}
