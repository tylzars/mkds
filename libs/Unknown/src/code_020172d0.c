#include "code_020172d0.h"
#include "code_0201750c.h"

void ListAppend(LinkedList *a, void *p) {
    u32 o;

    if (a->mHead == 0) {
        ListAppendToEmpty(a, (u32) p);
        return;
    }
    o = a->mLinkOffset;
    *(void **) ((u8 *) p + o) = a->mTail;
    *(void **) ((u8 *) p + o + 4) = 0;
    *(void **) ((u8 *) a->mTail + a->mLinkOffset + 4) = p;
    a->mTail = p;
    a->mCount++;
}

void ListPrepend(LinkedList *a, void *p) {
    u32 o;

    if (a->mHead == 0) {
        ListAppendToEmpty(a, (u32) p);
        return;
    }
    o = a->mLinkOffset;
    *(void **) ((u8 *) p + o) = 0;
    *(void **) ((u8 *) p + o + 4) = a->mHead;
    *(void **) ((u8 *) a->mHead + a->mLinkOffset) = p;
    a->mHead = p;
    a->mCount++;
}

void ListInsertBefore(LinkedList *a, Unk0212c400 *p, Unk0212c400 *q) {
    u32 o;
    u8 *l;
    void *n;

    if (p == 0) {
        ListAppend(a, q);
        return;
    }
    if (p == a->mHead) {
        ListPrepend(a, q);
        return;
    }
    o = a->mLinkOffset;
    l = (u8 *) q + o;
    n = *(void **) ((u8 *) p + o);
    *(void **) l = n;
    *(void **) (l + 4) = p;
    *(void **) ((u8 *) n + o + 4) = q;
    *(void **) ((u8 *) p + a->mLinkOffset) = q;
    a->mCount++;
}

void ListRemove(LinkedList *a, void *p) {
    u32 o;
    u8 *l;
    void *x;

    o = a->mLinkOffset;
    x = *(void **) ((u8 *) p + o);
    l = (u8 *) p + o;
    if (x == 0) {
        a->mHead = *(void **) (l + 4);
    } else {
        *(void **) ((u8 *) x + o + 4) = *(void **) (l + 4);
    }
    x = *(void **) (l + 4);
    if (x == 0) {
        a->mTail = *(void **) l;
    } else {
        *(void **) ((u8 *) x + a->mLinkOffset) = *(void **) l;
    }
    *(void **) l = 0;
    *(void **) (l + 4) = 0;
    a->mCount--;
}

void *ListGetNext(LinkedList *a, void *p) {
    if (p == 0) {
        return a->mHead;
    }
    return *(void **) ((u8 *) p + a->mLinkOffset + 4);
}

void *ListGetPrev(LinkedList *a, void *p) {
    if (p == 0) {
        return a->mTail;
    }
    return *(void **) ((u8 *) p + a->mLinkOffset);
}

void *ListGetNth(LinkedList *a, s32 b) {
    s32 i;
    void *p;

    i = 0;
    p = ListGetNext(a, 0);
    while (p != 0) {
        if (i == b) {
            return p;
        }
        i++;
        p = ListGetNext(a, p);
    }
    return 0;
}

s32 func_020172d0(s32 a) {
    return a << 4;
}
