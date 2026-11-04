#include "code_02017f24.h"
#include "code_02134420.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"

Unk02017f24 *FrmHeapInit(Unk02017f24 *a, u32 b, u16 c) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    HeapInitAndLink(&a->mUnk_00, 0x46524d48, (u32) (p + 1), b, c);
    a->mUnk_24.mFrontAddr = a->mUnk_00.mRangeStart;
    p->mBackAddr = a->mUnk_00.mRangeEnd;
    p->mSavedList = 0;
    return a;
}

void *FrmHeapAllocFront(Unk02018174 *a, u32 b, u32 c) {
    u32 m;
    u32 s;
    u32 e;
    u32 lo;
    u32 n;

    lo = a->mFrontAddr;
    m = c - 1;
    s = (m + lo) & ~m;
    e = b + s;
    if (e > a->mBackAddr) {
        return 0;
    }
    n = e - lo;
    {
        volatile u32 z;

        if ((u16) (*(u32 *) ((u8 *) a - 4) & 0xff) & 1) {
            z = 0;
            MemFillWords(z, (void *) lo, n);
        }
    }
    a->mFrontAddr = e;
    return (void *) s;
}

u32 FrmHeapAllocBack(Unk02018174 *a, u32 b, u32 c) {
    u32 m;
    u32 hi;
    u32 s;
    u32 n;

    hi = a->mBackAddr;
    m = c - 1;
    s = (hi - b) & ~m;
    if (s < a->mFrontAddr) {
        return 0;
    }
    n = hi - s;
    {
        volatile u32 z;

        if ((u16) (*(u32 *) ((u8 *) a - 4) & 0xff) & 1) {
            z = 0;
            MemFillWords(z, (void *) s, n);
        }
    }
    a->mBackAddr = s;
    return s;
}

void FrmHeapFreeFront(Unk02017f24 *a) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    p->mFrontAddr = a->mUnk_00.mRangeStart;
    p->mSavedList = 0;
}

void FrmHeapFreeBack(Unk02017f24 *a) {
    Unk02017f58 *n;
    Unk02018174 *p;

    p = &a->mUnk_24;
    n = p->mSavedList;
    if (n != 0) {
        do {
            n->mBackAddr = a->mUnk_00.mRangeEnd;
            n = n->mNext;
        } while (n != 0);
    }
    p->mBackAddr = a->mUnk_00.mRangeEnd;
}

Unk02017f24 *FrmHeapCreate(void *a, u32 b, u16 c) {
    u32 e;

    e = (b + (u32) a) & ~3;
    a = (void *) (((u32) a + 3) & ~3);
    if ((u32) a > e || e - (u32) a < 0x30) {
        return 0;
    }
    return FrmHeapInit(a, e, c);
}

void FrmHeapDestroy(Unk02017584 *a) {
    HeapUnlink(a);
}

void *FrmHeapAlloc(Unk02017f24 *a, u32 b, s32 c) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    if (b == 0) {
        b = 1;
    }
    b = (b + 3) & ~3;
    if (c >= 0) {
        return FrmHeapAllocFront(p, b, c);
    }
    return (void *) FrmHeapAllocBack(p, b, -c);
}

void FrmHeapFree(Unk02017f24 *a, u32 b) {
    if (b & 1) {
        FrmHeapFreeFront(a);
    }
    if (b & 2) {
        FrmHeapFreeBack(a);
    }
}

u32 FrmHeapGetMaxAllocSize(Unk02017f24 *a, u32 b) {
    u32 n;
    u32 s;
    u32 t;
    Unk02018174 *p;

    n = func_02134420(b);
    p = &a->mUnk_24;
    t = p->mBackAddr;
    s = ((n - 1) + p->mFrontAddr) & ~(n - 1);
    if (s > t) {
        return 0;
    }
    return t - s;
}

u32 FrmHeapSaveFrontBack(Unk02017f24 *a, u32 b) {
    u32 lo;
    Unk02017f58 *n;
    Unk02018174 *p;

    p = &a->mUnk_24;
    lo = a->mUnk_24.mFrontAddr;
    n = FrmHeapAllocFront(p, 0x10, 4);
    if (n == 0) {
        return 0;
    }
    n->mKey = b;
    n->mFrontAddr = lo;
    n->mBackAddr = p->mBackAddr;
    n->mNext = p->mSavedList;
    p->mSavedList = n;
    return 1;
}

u32 FrmHeapRestoreFrontBack(Unk02017f24 *a, u32 b) {
    Unk02017f58 *n;
    Unk02018174 *p;

    p = &a->mUnk_24;
    n = p->mSavedList;
    if (b != 0 && n != 0) {
        do {
            if (n->mKey == b) {
                break;
            }
            n = n->mNext;
        } while (n != 0);
    }
    if (n == 0) {
        return 0;
    }
    p->mFrontAddr = n->mFrontAddr;
    p->mBackAddr = n->mBackAddr;
    p->mSavedList = n->mNext;
    return 1;
}

u32 FrmHeapShrink(Unk02017f24 *a) {
    Unk02018174 *p;

    p = &a->mUnk_24;
    if (a->mUnk_00.mRangeEnd - p->mBackAddr != 0) {
        return 0;
    }
    a->mUnk_00.mRangeEnd = p->mFrontAddr;
    p->mBackAddr = a->mUnk_00.mRangeEnd;
    return a->mUnk_00.mRangeEnd - (u32) a;
}
