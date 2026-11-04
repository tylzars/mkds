#include "code_02017e70.h"

ExpHeapBlock *ExpHeapBlockInit(ExpHeapRange *a, u16 b) {
    ExpHeapBlock *p;

    p = (ExpHeapBlock *) a->mStart;
    p->mTag = b;
    p->mUnk_02 = 0;
    p->mSize = a->mEnd - (u32) (p + 1);
    p->mPrev = 0;
    p->mNext = 0;
    return p;
}
