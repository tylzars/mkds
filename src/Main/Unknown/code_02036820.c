#include "Main/Unknown/code_02036820.h"
#include "code_020176c0.h"
#include "code_02017f24.h"
#include "code_02017550.h"
#include "code_0200fc8c.h"

void *HeapAlloc(void *a, u32 b) {
    Unk02017584 *h = a;
    void *c = NULL;
    switch (h->mTag) {
        case 0x45585048:
            c = ExpHeapAlloc(a, b, 4);
            break;
        case 0x46524d48:
            c = FrmHeapAlloc(a, b, 4);
            break;
    }
    return c;
}

void *HeapAllocAligned(void *a, u32 b, s32 c) {
    Unk02017584 *h = a;
    void *d = NULL;
    u32 e;
    switch (h->mTag) {
        case 0x45585048:
            d = ExpHeapAlloc(a, b, c);
            break;
        case 0x46524d48:
            e = IrqDisable();
            d = FrmHeapAlloc(a, b, c);
            IrqRestore(e);
            break;
    }
    return d;
}

void HeapFree(void *a, void *b) {
    Unk02017584 *h = a;
    switch (h->mTag) {
        case 0x45585048:
            ExpHeapFree(a, b);
            break;
        case 0x46524d48:
            break;
    }
}

void HeapDestroy(void *a) {
    Unk02017584 *h = a;
    Unk020176c0 *p;
    switch (h->mTag) {
        case 0x45585048:
            ExpHeapDestroy(a);
            break;
        case 0x46524d48:
            FrmHeapDestroy(a);
            break;
    }
    p = HeapFindInnermost(a);
    if (p == NULL) {
        return;
    }
    switch (p->mUnk_00.mTag) {
        case 0x45585048:
            ExpHeapFree(p, a);
            break;
        case 0x46524d48:
            break;
    }
}

void *CreateExpHeapFromMaxFree(void *a) {
    Unk02017584 *h = a;
    u32 b = 0;
    void *c;
    switch (h->mTag) {
        case 0x45585048:
            b = ExpHeapGetMaxAllocSize(a, 4);
            break;
        case 0x46524d48:
            b = FrmHeapGetMaxAllocSize(a, 4);
            break;
    }
    c = NULL;
    switch (h->mTag) {
        case 0x45585048:
            c = ExpHeapAlloc(a, b, 4);
            break;
        case 0x46524d48:
            c = FrmHeapAlloc(a, b, 4);
            break;
    }
    return ExpHeapCreate(c, b, 1);
}

void *CreateFrmHeapFromMaxFree(void *a) {
    Unk02017584 *h = a;
    u32 b = 0;
    void *c;
    switch (h->mTag) {
        case 0x45585048:
            b = ExpHeapGetMaxAllocSize(a, 4);
            break;
        case 0x46524d48:
            b = FrmHeapGetMaxAllocSize(a, 4);
            break;
    }
    c = NULL;
    switch (h->mTag) {
        case 0x45585048:
            c = ExpHeapAlloc(a, b, 4);
            break;
        case 0x46524d48:
            c = FrmHeapAlloc(a, b, 4);
            break;
    }
    return FrmHeapCreate(c, b, 1);
}

void *CreateFrmHeapFromFront(void *a, u32 b) {
    Unk02017584 *h = a;
    void *c = NULL;
    switch (h->mTag) {
        case 0x45585048:
            c = ExpHeapAlloc(a, b, 4);
            break;
        case 0x46524d48:
            c = FrmHeapAlloc(a, b, 4);
            break;
    }
    return FrmHeapCreate(c, b, 1);
}

void *CreateFrmHeapFromBack(void *a, u32 b) {
    Unk02017584 *h = a;
    void *c = NULL;
    u32 d;
    switch (h->mTag) {
        case 0x45585048:
            c = ExpHeapAlloc(a, b, -4);
            break;
        case 0x46524d48:
            d = IrqDisable();
            c = FrmHeapAlloc(a, b, -4);
            IrqRestore(d);
            break;
    }
    return FrmHeapCreate(c, b, 1);
}

void FrmHeapShrinkInParent(void *a) {
    u32 b = FrmHeapShrink(a);
    ExpHeapResizeBlock(HeapFindInnermost(a), a, b);
}
