#include "code_02017550.h"
#include "code_020172d0.h"
#include "code_0201750c.h"

Unk02017584 *HeapFindInnermostInList(LinkedList *a, u32 b) {
    Unk02017584 *p;
    Unk02017584 *r;

    p = ListGetNext(a, 0);
    while (p != 0) {
        if (p->mRangeStart <= b && b < p->mRangeEnd) {
            r = HeapFindInnermostInList(&p->mUnk_0c, b);
            if (r == 0) {
                r = p;
            }
            return r;
        }
        p = ListGetNext(a, p);
    }
    return 0;
}

LinkedList *HeapFindList(u32 a) {
    LinkedList *l;
    Unk02017584 *p;

    l = &gHeapList;
    p = HeapFindInnermostInList(l, a);
    if (p != 0) {
        l = &p->mUnk_0c;
    }
    return l;
}

void HeapInitAndLink(Unk02017584 *a, u32 b, u32 c, u32 d, u16 e) {
    a->mTag = b;
    a->mRangeStart = c;
    a->mRangeEnd = d;
    a->mUnk_20 = 0;
    a->mUnk_20 &= ~0xff;
    a->mUnk_20 |= e & 0xff;
    ListInit(&a->mUnk_0c, 4);
    if (gHeapListInitialized == 0) {
        ListInit(&gHeapList, 4);
        gHeapListInitialized = 1;
    }
    ListAppend(HeapFindList((u32) a), a);
}

void HeapUnlink(Unk02017584 *a) {
    ListRemove(HeapFindList((u32) a), a);
}

void *HeapFindInnermost(void *a) {
    return HeapFindInnermostInList(&gHeapList, (u32) a);
}
