#include "code_0200cd1c.h"
#include "code_0200e77c.h"

#include "code_0200cdc0.h"
#include "code_0200ce60.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"

// With t = data_0216ff5c.mUnk_04: when n->mUnk_08 is 0 it is set to t, mUnk_0c is raised and ThreadLockListAppend links
// n to t; when it is t only mUnk_0c is raised; otherwise t->mUnk_84 is set to n around ThreadWait on n->mUnk_00, and
// the test repeats.
void ThreadLockWait(void *p) {
    ThreadLock *n;
    u32 s;
    Unk0200db5c *t;

    n = p;
    s = IrqDisable();
    t = data_0216ff5c.mCurrentThread;
    while (1) {
        if (n->mHolder == 0) {
            n->mHolder = t;
            n->mLockCount = n->mLockCount + 1;
            ThreadLockListAppend(t, n);
            break;
        } else if (n->mHolder == t) {
            n->mLockCount = n->mLockCount + 1;
            break;
        } else {
            t->mUnk_84 = n;
            ThreadWait(&n->mQueue);
            t->mUnk_84 = 0;
        }
    }
    IrqRestore(s);
}

// When n->mUnk_08 is data_0216ff5c.mUnk_04, lowers mUnk_0c; at 0 calls ThreadLockListRemove, clears mUnk_08 and calls
// ThreadQueueSetAllRunnable on n->mUnk_00.
void ThreadLockUnlock(void *p) {
    ThreadLock *n;
    u32 s;
    Unk0200db5c *t;

    n = p;
    s = IrqDisable();
    t = data_0216ff5c.mCurrentThread;
    if (n->mHolder == t) {
        n->mLockCount = n->mLockCount - 1;
        if (n->mLockCount == 0) {
            ThreadLockListRemove(t, n);
            n->mHolder = 0;
            ThreadQueueSetAllRunnable(&n->mQueue);
        }
    }
    IrqRestore(s);
}

// While t->mUnk_88.mUnk_00 is not 0, takes an object from t->mUnk_88 (ThreadLockListRemoveFront), clears its mUnk_08
// and mUnk_0c and calls ThreadQueueSetAllRunnable on its mUnk_00.
void ThreadUnlockAll(struct Unk0200db5c *t) {
    ThreadLock *n;

    if (t->mLockList.mHead == 0) {
        return;
    }
    do {
        n = ThreadLockListRemoveFront(&t->mLockList);
        n->mLockCount = 0;
        n->mHolder = 0;
        ThreadQueueSetAllRunnable(&n->mQueue);
    } while (t->mLockList.mHead != 0);
}

// When n->mUnk_08 is 0 it is set to data_0216ff5c.mUnk_04, mUnk_0c is raised and ThreadLockListAppend links n; when it
// is that object only mUnk_0c is raised. Returns 1 in those cases, else 0.
s32 ThreadLockTry(void *p) {
    ThreadLock *n;
    u32 s;
    s32 r;
    Unk0200db5c *t;

    n = p;
    s = IrqDisable();
    t = data_0216ff5c.mCurrentThread;
    if (n->mHolder == 0) {
        n->mHolder = t;
        n->mLockCount = n->mLockCount + 1;
        ThreadLockListAppend(t, n);
        r = 1;
    } else if (n->mHolder == t) {
        n->mLockCount = n->mLockCount + 1;
        r = 1;
    } else {
        r = 0;
    }
    IrqRestore(s);
    return r;
}

// Links n after t->mUnk_88.mUnk_04 (through mUnk_10 and mUnk_14) and stores it there.
void ThreadLockListAppend(struct Unk0200db5c *t, ThreadLock *n) {
    ThreadLock *a;

    a = t->mLockList.mTail;
    if (a == 0) {
        t->mLockList.mHead = n;
    } else {
        a->mNext = n;
    }
    n->mPrev = a;
    n->mNext = 0;
    t->mLockList.mTail = n;
}

// Takes n out of the links of t->mUnk_88 (mUnk_10 and mUnk_14).
void ThreadLockListRemove(struct Unk0200db5c *t, ThreadLock *n) {
    ThreadLock *a;
    ThreadLock *b;

    b = n->mNext;
    a = n->mPrev;
    if (b == 0) {
        t->mLockList.mTail = a;
    } else {
        b->mPrev = a;
    }
    if (a == 0) {
        t->mLockList.mHead = b;
    } else {
        a->mNext = b;
    }
}

// Clears mUnk_00 and mUnk_08, stores p and n in mUnk_10 and mUnk_14 and clears mUnk_18 and mUnk_1c.
void RingQueueInit(RingQueue *q, void **p, s32 n) {
    q->mFullWaiters.mTail = 0;
    q->mFullWaiters.mHead = q->mFullWaiters.mTail;
    q->mEmptyWaiters.mTail = 0;
    q->mEmptyWaiters.mHead = q->mEmptyWaiters.mTail;
    q->mBuffer = p;
    q->mCapacity = n;
    q->mHeadIndex = 0;
    q->mCount = 0;
}

// Stores v at mUnk_10[(mUnk_18 + mUnk_1c) % mUnk_14], raises mUnk_1c and calls ThreadQueueSetAllRunnable on mUnk_08.
// While mUnk_1c is at least mUnk_14 it calls ThreadWait on mUnk_00, or returns 0 when bit 0 of f is clear.
s32 RingQueueAppend(RingQueue *q, void *v, s32 f) {
    u32 s;

    s = IrqDisable();
    if (q->mCapacity <= q->mCount) {
        do {
            if ((f & 1) == 0) {
                IrqRestore(s);
                return 0;
            }
            ThreadWait(&q->mFullWaiters);
        } while (q->mCapacity <= q->mCount);
    }
    q->mBuffer[(q->mHeadIndex + q->mCount) % q->mCapacity] = v;
    q->mCount = q->mCount + 1;
    ThreadQueueSetAllRunnable(&q->mEmptyWaiters);
    IrqRestore(s);
    return 1;
}

// Stores mUnk_10[mUnk_18] to *p when p is not 0, advances mUnk_18 modulo mUnk_14, lowers mUnk_1c and calls
// ThreadQueueSetAllRunnable on mUnk_00. While mUnk_1c is 0 it calls ThreadWait on mUnk_08, or returns 0 when bit 0 of f
// is clear.
s32 RingQueueRemoveFront(RingQueue *q, void **p, s32 f) {
    u32 s;

    s = IrqDisable();
    if (q->mCount == 0) {
        do {
            if ((f & 1) == 0) {
                IrqRestore(s);
                return 0;
            }
            ThreadWait(&q->mEmptyWaiters);
        } while (q->mCount == 0);
    }
    if (p != 0) {
        *p = q->mBuffer[q->mHeadIndex];
    }
    q->mHeadIndex = (q->mHeadIndex + 1) % q->mCapacity;
    q->mCount = q->mCount - 1;
    ThreadQueueSetAllRunnable(&q->mFullWaiters);
    IrqRestore(s);
    return 1;
}

// Lowers mUnk_18 by one modulo mUnk_14, stores v at mUnk_10[mUnk_18], raises mUnk_1c and calls
// ThreadQueueSetAllRunnable on mUnk_08. While mUnk_1c is at least mUnk_14 it calls ThreadWait on mUnk_00, or returns 0
// when bit 0 of f is clear.
s32 RingQueuePrepend(RingQueue *q, void *v, s32 f) {
    u32 s;

    s = IrqDisable();
    if (q->mCapacity <= q->mCount) {
        do {
            if ((f & 1) == 0) {
                IrqRestore(s);
                return 0;
            }
            ThreadWait(&q->mFullWaiters);
        } while (q->mCapacity <= q->mCount);
    }
    q->mHeadIndex = (q->mHeadIndex + q->mCapacity - 1) % q->mCapacity;
    q->mBuffer[q->mHeadIndex] = v;
    q->mCount = q->mCount + 1;
    ThreadQueueSetAllRunnable(&q->mEmptyWaiters);
    IrqRestore(s);
    return 1;
}

// Stores mUnk_10[mUnk_18] to *p when p is not 0. While mUnk_1c is 0 it calls ThreadWait on mUnk_08, or returns
// 0 when bit 0 of f is clear.
s32 RingQueuePeekFront(RingQueue *q, void **p, s32 f) {
    u32 s;

    s = IrqDisable();
    if (q->mCount == 0) {
        do {
            if ((f & 1) == 0) {
                IrqRestore(s);
                return 0;
            }
            ThreadWait(&q->mEmptyWaiters);
        } while (q->mCount == 0);
    }
    if (p != 0) {
        *p = q->mBuffer[q->mHeadIndex];
    }
    IrqRestore(s);
    return 1;
}

u32 data_021617cc = 0xffffffff;

u32 func_0200e8fc(void) {
    return 0;
}

// On the first call stores func_0200e7b0's result with one bit added in the top bits (0x10000000 when
// func_0200e8fc is nonzero, else 0x40000000 when func_0200e77c is nonzero, else 0x20000000 when bit 24 of the
// result is set, else 0x80000000), or-ed with a halfword read from a fixed address. The stored value is -1 until
// then.
u32 func_0200e884(void) {
    u32 a;

    if (data_021617cc == 0xffffffff) {
        a = func_0200e7b0();
        if (func_0200e8fc() != 0) {
            a |= 0x10000000;
        } else if (func_0200e77c() != 0) {
            a |= 0x40000000;
        } else if (a & 0x1000000) {
            a |= 0x20000000;
        } else {
            a |= 0x80000000;
        }
        data_021617cc = a | *(u16 *) 0x27ffffa;
    }
    return data_021617cc;
}

// Repeats, each pass between IrqDisable and IrqRestore, until func_0200ce80 has been called (it is when
// func_0200ce60 returns 0). The result has bit 24 set when two words at fixed addresses are 0x544e494e and
// 0x4f444e45, else bit 25.
u32 func_0200e7b0(void) {
    u32 a;
    s32 d;
    u32 h;
    s32 v;
    u32 s;

    d = 0;
    h = (u16) IdAlloc();
    a = 0;
    do {
        v = -1;
        s = IrqDisable();
        if ((SwapLockGetHolderId((SwapLockSlot *) 0x27fffe8) & 0x40) != 0 || (v = func_0200ce60(h)) == 0) {
            if (*(u32 *) 0x8000000 == 0x544e494e && *(u32 *) 0x8000004 == 0x4f444e45) {
                a = 0x1000000;
            } else {
                a = 0x2000000;
            }
            if (v == 0) {
                func_0200ce80(h);
                d = 1;
            }
        }
        IrqRestore(s);
    } while (d == 0);
    return a;
}

// 1 when a halfword is 1; which of two fixed addresses it is read from depends on whether another halfword is 0.
u32 func_0200e77c(void) {
    u16 *p;

    if (*(u16 *) 0x27ffc10 == 0) {
        p = (u16 *) 0x27ff814;
    } else {
        p = (u16 *) 0x27ffc14;
    }
    return *p == 1;
}
