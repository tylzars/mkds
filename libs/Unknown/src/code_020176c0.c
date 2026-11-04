#include "code_020176c0.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"

Unk020176c0 *ExpHeapInit(Unk020176c0 *a, u32 b, u16 c) {
    Unk020179d4 *p;
    ExpHeapRange r;
    ExpHeapBlock *v;

    p = &a->mUnk_24;
    HeapInitAndLink(&a->mUnk_00, 0x45585048, (u32) (p + 1), b, c);
    p->mUnk_10 = 0;
    p->mUnk_12 = 0;
    p->mUnk_12 &= ~1;
    r.mStart = a->mUnk_00.mRangeStart;
    r.mEnd = a->mUnk_00.mRangeEnd;
    v = ExpHeapBlockInit(&r, 0x4652);
    p->mFreeList.mHead = v;
    p->mFreeList.mTail = v;
    p->mUsedList.mHead = 0;
    p->mUsedList.mTail = 0;
    return a;
}

void *ExpHeapAllocFromFreeBlock(Unk020179d4 *a, ExpHeapBlock *b, void *c, u32 d, u16 e) {
    ExpHeapRange r1;
    ExpHeapRange r2;
    ExpHeapRange r3;
    ExpHeapBlock *p;
    ExpHeapBlock *q;
    u32 n;

    ExpHeapBlockGetRange(&r1, b);
    q = (ExpHeapBlock *) ((u32) c - 0x10);
    r2.mEnd = r1.mEnd;
    r1.mEnd = (u32) q;
    r2.mStart = d + (u32) c;
    p = ExpHeapBlockListRemove(&a->mFreeList, b);
    if (r1.mEnd - r1.mStart < 0x10) {
        r1.mEnd = r1.mStart;
    } else {
        p = ExpHeapBlockListInsertAfter(&a->mFreeList, ExpHeapBlockInit(&r1, 0x4652), p);
    }
    if (r2.mEnd - r2.mStart < 0x10) {
        r2.mStart = r2.mEnd;
    } else {
        ExpHeapBlockListInsertAfter(&a->mFreeList, ExpHeapBlockInit(&r2, 0x4652), p);
    }
    n = r2.mStart - r1.mEnd;
    {
        volatile u32 z;

        if ((u16) (*(u32 *) ((u8 *) a - 4) & 0xff) & 1) {
            z = 0;
            MemFillWords(z, (void *) r1.mEnd, n);
        }
    }
    r3.mStart = (u32) q;
    r3.mEnd = r2.mStart;
    p = ExpHeapBlockInit(&r3, 0x5544);
    p->mUnk_02 &= ~0x8000;
    p->mUnk_02 |= (e & 1) << 15;
    {
        u32 t = (u32) p - r1.mEnd;

        p->mUnk_02 &= ~0x7f00;
        p->mUnk_02 |= ((u16) t & 0x7f) << 8;
    }
    {
        u8 g = a->mUnk_10;

        p->mUnk_02 &= ~0xff;
        p->mUnk_02 |= g;
    }
    ExpHeapBlockListInsertAfter(&a->mUsedList, p, a->mUsedList.mTail);
    return c;
}

void *ExpHeapAllocFront(Unk020176c0 *a, u32 b, u32 c) {
    Unk020179d4 *p;
    ExpHeapBlock *q;
    ExpHeapBlock *b0;
    u32 a0;
    u32 v0;
    u32 v1;
    int bestaddr;
    u32 m;
    u32 f;

    p = &a->mUnk_24;
    f = (u16) (p->mUnk_12 & 1) == 0 ? 1 : 0;
    q = p->mFreeList.mHead;
    b0 = 0;
    bestaddr = 0;
    v1 = -1;
    if (q != 0) {
        m = c - 1;
        do {
            a0 = (m + ((u32) (q + 1))) & ~m;
            v0 = q->mSize;
            if (v0 >= b + (a0 - ((u32) (q + 1))) && v1 > v0) {
                b0 = q;
                v1 = v0;
                bestaddr = a0;
                if (f != 0) {
                    break;
                }
                if (v0 == b) {
                    break;
                }
            }
            q = q->mNext;
        } while (q != 0);
    }
    if (b0 == 0) {
        return 0;
    }
    return ExpHeapAllocFromFreeBlock(p, b0, (void *) bestaddr, b, 0);
}

void *ExpHeapAllocBack(Unk020176c0 *a, u32 b, u32 c) {
    int v0;
    u32 m;
    u32 a0;
    ExpHeapBlock *q;
    ExpHeapBlock *b0;
    u32 v1;
    Unk020179d4 *p;
    int g0;
    int bestaddr;
    u32 f;

    p = &a->mUnk_24;
    f = (u16) (p->mUnk_12 & 1) == 0 ? 1 : 0;
    v1 = -1;
    b0 = 0;
    q = p->mFreeList.mTail;
    bestaddr = 0;
    if (q != 0) {
        m = ~(c - 1);
        do {
            u32 t = q->mSize;

            v0 = t;
            a0 = (v0 + ((u32) (q + 1)) - b) & m;
            g0 = a0 - ((u32) (q + 1));
            if (g0 >= 0 && v1 > v0) {
                b0 = q;
                v1 = (u32) v0;
                bestaddr = a0;
                if (f != 0) {
                    break;
                }
                if (v0 == b) {
                    break;
                }
            }
            q = q->mPrev;
        } while (q != 0);
    }
    if (b0 == 0) {
        return 0;
    }
    return ExpHeapAllocFromFreeBlock(p, b0, (void *) bestaddr, b, 1);
}

u32 ExpHeapAddFreeRange(Unk020179d4 *a, ExpHeapRange *b) {
    ExpHeapRange r;
    ExpHeapBlock *p;
    ExpHeapBlock *q;

    r = *b;
    q = 0;
    p = a->mFreeList.mHead;
    if (p != 0) {
        do {
            if ((u32) p < b->mStart) {
                q = p;
            } else {
                if ((u32) p == b->mEnd) {
                    r.mEnd = p->mSize + ((u32) (p + 1));
                    ExpHeapBlockListRemove(&a->mFreeList, p);
                }
                break;
            }
            p = p->mNext;
        } while (p != 0);
    }
    if (q != 0) {
        u32 s = q->mSize + ((u32) (q + 1));

        if (s == b->mStart) {
            r.mStart = (u32) q;
            q = ExpHeapBlockListRemove(&a->mFreeList, q);
        }
    }
    if (r.mEnd - r.mStart < 0x10) {
        return 0;
    }
    ExpHeapBlockListInsertAfter(&a->mFreeList, ExpHeapBlockInit(&r, 0x4652), q);
    return 1;
}

Unk020176c0 *ExpHeapCreate(void *a, u32 b, u16 c) {
    u32 e;

    e = (b + (u32) a) & ~3;
    a = (void *) (((u32) a + 3) & ~3);
    if ((u32) a > e || e - (u32) a < 0x4c) {
        return 0;
    }
    return ExpHeapInit(a, e, c);
}

void ExpHeapDestroy(Unk02017584 *a) {
    HeapUnlink(a);
}

void *ExpHeapAlloc(Unk020176c0 *a, u32 b, s32 c) {
    if (b == 0) {
        b = 1;
    }
    b = (b + 3) & ~3;
    if (c >= 0) {
        return ExpHeapAllocFront(a, b, c);
    }
    return ExpHeapAllocBack(a, b, -c);
}

u32 ExpHeapResizeBlock(Unk020176c0 *a, void *b, u32 c) {
    ExpHeapRange r1;
    u32 start;
    ExpHeapBlock *r;
    ExpHeapBlock *prev;
    ExpHeapRange r2;
    u32 sz;
    Unk020179d4 *p;
    ExpHeapBlock *q;
    u32 e;
    u32 t;
    u32 n;

    q = (ExpHeapBlock *) ((u8 *) b - 0x10);
    sz = q->mSize;
    c = (c + 3) & ~3;
    p = &a->mUnk_24;
    if (c == sz) {
        return c;
    }
    if (c > sz) {
        r = p->mFreeList.mHead;
        t = sz + ((u32) (q + 1));
        if (r != 0) {
            do {
                if ((u32) r == t) {
                    break;
                }
                r = r->mNext;
            } while (r != 0);
        }
        if (r == 0 || c > sz + 0x10 + r->mSize) {
            return 0;
        }
        ExpHeapBlockGetRange(&r1, r);
        prev = ExpHeapBlockListRemove(&p->mFreeList, r);
        e = c + (u32) b;
        start = r1.mStart;
        r1.mStart = e;
        if (r1.mEnd - e < 0x10) {
            r1.mStart = r1.mEnd;
        }
        q->mSize = r1.mStart - (u32) b;
        if (r1.mEnd - r1.mStart >= 0x10) {
            ExpHeapBlockListInsertAfter(&p->mFreeList, ExpHeapBlockInit(&r1, 0x4652), prev);
        }
        n = r1.mStart - start;
        {
            volatile u32 z;

            if ((u16) (a->mUnk_00.mUnk_20 & 0xff) & 1) {
                z = 0;
                MemFillWords(z, (void *) start, n);
            }
        }
    } else {
        r2.mStart = c + (u32) b;
        r2.mEnd = q->mSize + ((u32) (q + 1));
        q->mSize = c;
        if (ExpHeapAddFreeRange(&a->mUnk_24, &r2) == 0) {
            q->mSize = sz;
        }
    }
    return q->mSize;
}

void ExpHeapFree(Unk020176c0 *a, void *b) {
    Unk020179d4 *p;
    ExpHeapBlock *q;
    ExpHeapRange r;

    q = (ExpHeapBlock *) ((u8 *) b - 0x10);
    p = &a->mUnk_24;
    ExpHeapBlockGetRange(&r, q);
    ExpHeapBlockListRemove(&p->mUsedList, q);
    ExpHeapAddFreeRange(p, &r);
}

u32 ExpHeapGetTotalFreeSize(Unk020176c0 *a) {
    ExpHeapBlock *p;
    u32 n;

    p = a->mUnk_24.mFreeList.mHead;
    n = 0;
    if (p == 0) {
        return n;
    }
    do {
        n += p->mSize;
        p = p->mNext;
    } while (p != 0);
    return n;
}

u32 ExpHeapGetMaxAllocSize(Unk020176c0 *a, u32 b) {
    u32 m;
    u32 b0;
    u32 off;
    ExpHeapBlock *p;
    u32 s;
    u32 e;
    u32 n;
    u32 l;
    u32 d;

    m = Abs(b);
    b0 = 0;
    off = -1;
    for (p = a->mUnk_24.mFreeList.mHead; p != 0; p = p->mNext) {
        {
            s = (u32) (p + 1);
            n = ((u32) (m - 1) + s) & ~(m - 1);
            e = p->mSize + s;
            if (n < e) {
                l = e - n;
                d = n - s;
                if (b0 < l || (b0 == l && off > d)) {
                    b0 = l;
                    off = d;
                }
            }
        }
    }
    return b0;
}
