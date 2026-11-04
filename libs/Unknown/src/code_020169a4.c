#include "code_020169a4.h"

RangeEntry *RangeEntryPoolInit(RangeEntry *p, u32 n) {
    u32 i;
    RangeEntry *q;
    u32 m;

    m = n - 1;
    i = 0;
    if (m != 0) {
        q = p;
        do {
            p[i].mNext = &p[i + 1];
            p[i + 1].mPrev = q;
            i++;
            q++;
        } while (i < m);
    }
    p->mPrev = 0;
    (p + n)[-1].mNext = 0;
    return p;
}

s32 RangeListAdd(RangeEntry **a, RangeEntry **b, u32 c, u32 d) {
    RangeEntry *n;

    n = *b;
    if (n != 0) {
        *b = n->mNext;
    }
    if (n != 0) {
        n->mStart = c;
        n->mSize = d;
        n->mPrev = 0;
        n->mNext = 0;
        if (*a != 0) {
            (*a)->mPrev = n;
        }
        n->mNext = *a;
        n->mPrev = 0;
        *a = n;
        return 1;
    }
    return 0;
}

s32 RangeListAlloc(RangeEntry **a, RangeEntry **b, u32 *c, u32 d) {
    return RangeListAllocAligned(a, b, c, d, 0);
}

s32 RangeListAllocAligned(RangeEntry **a, RangeEntry **b, u32 *c, u32 d, u32 e) {
    u32 addr;
    u32 need;
    u32 pad;
    RangeEntry *best;
    RangeEntry *n;
    RangeEntry *t;
    RangeEntry *prev;
    RangeEntry *next;

    best = 0;
    for (n = *a; n != 0; n = n->mNext) {
        if (e > 1) {
            addr = (n->mStart + (e - 1)) & ~(e - 1);
            pad = addr - n->mStart;
            need = d + pad;
        } else {
            addr = n->mStart;
            pad = 0;
            need = d;
        }
        if (n->mSize >= need) {
            best = n;
            break;
        }
    }
    if (best == 0) {
        goto fail;
    }
    if (pad != 0) {
        t = *b;
        if (t != 0) {
            *b = t->mNext;
        }
        if (t == 0) {
            goto fail;
        }
        t->mStart = best->mStart;
        t->mSize = pad;
        t->mPrev = 0;
        t->mNext = 0;
        if (*a != 0) {
            (*a)->mPrev = t;
        }
        t->mNext = *a;
        t->mPrev = 0;
        *a = t;
    }
    best->mSize -= need;
    best->mStart += need;
    if (best->mSize == 0) {
        prev = best->mPrev;
        next = best->mNext;
        if (prev != 0) {
            prev->mNext = next;
        } else {
            *a = next;
        }
        if (next != 0) {
            next->mPrev = prev;
        }
        if (*b != 0) {
            (*b)->mPrev = best;
        }
        best->mNext = *b;
        best->mPrev = 0;
        *b = best;
    }
    *c = addr;
    return 1;
fail:
    *c = 0;
    return 0;
}

s32 RangeListFree(RangeEntry **a, RangeEntry **b, u32 c, u32 d) {
    u32 r[4];
    u32 *rp;
    RangeEntry *n;
    RangeEntry *next;
    RangeEntry *t;
    RangeEntry *prev;

    r[0] = c;
    r[1] = c + d;
    r[2] = c;
    r[3] = c + d;
    rp = r;
    for (n = *a; n != 0; n = next) {
        next = n->mNext;
        if (n->mStart == rp[1]) {
            r[3] = n->mStart + n->mSize;
            prev = n->mPrev;
            if (prev != 0) {
                prev->mNext = next;
            } else {
                *a = next;
            }
            if (next != 0) {
                next->mPrev = prev;
            }
            if (*b != 0) {
                (*b)->mPrev = n;
            }
            n->mNext = *b;
            n->mPrev = 0;
            *b = n;
        }
        if (n->mStart + n->mSize == rp[0]) {
            RangeEntry *p2;
            RangeEntry *q2;

            r[2] = n->mStart;
            p2 = n->mPrev;
            q2 = n->mNext;
            if (p2 != 0) {
                p2->mNext = q2;
            } else {
                *a = q2;
            }
            if (q2 != 0) {
                q2->mPrev = p2;
            }
            if (*b != 0) {
                (*b)->mPrev = n;
            }
            n->mNext = *b;
            n->mPrev = 0;
            *b = n;
        }
    }
    t = *b;
    if (t != 0) {
        *b = t->mNext;
    }
    if (t == 0) {
        return 0;
    }
    t->mStart = r[2];
    t->mSize = r[3] - r[2];
    t->mPrev = 0;
    t->mNext = 0;
    if (*a != 0) {
        (*a)->mPrev = t;
    }
    t->mNext = *a;
    t->mPrev = 0;
    *a = t;
    return 1;
}
