#include "code_02017ea0.h"

void ExpHeapBlockGetRange(ExpHeapRange *a, ExpHeapBlock *b) {
    a->mStart = (u32) b - (u16) ((b->mUnk_02 >> 8) & 0x7f);
    a->mEnd = b->mSize + (u32) (b + 1);
}

ExpHeapBlock *ExpHeapBlockListRemove(ExpHeapBlockList *a, ExpHeapBlock *b) {
    ExpHeapBlock *p;
    ExpHeapBlock *n;

    p = b->mPrev;
    n = b->mNext;
    if (p != 0) {
        p->mNext = n;
    } else {
        a->mHead = n;
    }
    if (n != 0) {
        n->mPrev = p;
    } else {
        a->mTail = p;
    }
    return p;
}

ExpHeapBlock *ExpHeapBlockListInsertAfter(ExpHeapBlockList *a, ExpHeapBlock *b, ExpHeapBlock *c) {
    ExpHeapBlock *n;

    b->mPrev = c;
    if (c != 0) {
        n = c->mNext;
        c->mNext = b;
    } else {
        n = a->mHead;
        a->mHead = b;
    }
    b->mNext = n;
    if (n != 0) {
        n->mPrev = b;
    } else {
        a->mTail = b;
    }
    return b;
}
