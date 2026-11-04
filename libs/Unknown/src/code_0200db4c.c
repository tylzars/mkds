#include "code_0200db4c.h"

#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200f790.h"
#include "code_0200c914.h"
#include "code_0200e688.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "00/code_02188720.h"

u32 func_0200e670(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &data_0216ff4c;
    value0 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (value0) + (1u);
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}

void ThreadQueueInsert(ThreadQueue *q, Thread *t) {
    Thread *p;
    Thread *b;

    p = q->mHead;
    while (p != 0 && p->mSortKey <= t->mSortKey) {
        if (p == t) {
            return;
        }
        p = p->mQueueNext;
    }
    if (p == 0) {
        b = q->mTail;
        if (b == 0) {
            q->mHead = t;
        } else {
            b->mQueueNext = t;
        }
        t->mQueuePrev = b;
        t->mQueueNext = 0;
        q->mTail = t;
    } else {
        b = p->mQueuePrev;
        if (b == 0) {
            q->mHead = t;
        } else {
            b->mQueueNext = t;
        }
        t->mQueuePrev = b;
        t->mQueueNext = p;
        p->mQueuePrev = t;
    }
}

Thread *ThreadQueueRemoveFront(ThreadQueue *q) {
    Thread *h;
    Thread *n;

    h = q->mHead;
    if (h != 0) {
        n = h->mQueueNext;
        q->mHead = n;
        if (n != 0) {
            n->mQueuePrev = 0;
        } else {
            q->mTail = 0;
            h->mWaitQueue = 0;
        }
    }
    return h;
}

ThreadLock *ThreadLockListRemoveFront(ThreadLockList *q) {
    ThreadLock *h;
    ThreadLock *n;

    h = q->mHead;
    if (h != 0) {
        n = h->mNext;
        q->mHead = n;
        if (n != 0) {
            n->mPrev = 0;
        } else {
            q->mTail = 0;
        }
    }
    return h;
}

void ThreadListInsert(Thread *t) {
    Thread *p;
    Thread *b;
    Thread *h;

    b = 0;
    h = data_0216ff5c.mListHead;
    p = h;
    while (p != 0 && p->mSortKey < t->mSortKey) {
        b = p;
        p = p->mListNext;
    }
    if (b == 0) {
        t->mListNext = h;
        data_0216ff5c.mListHead = t;
    } else {
        t->mListNext = b->mListNext;
        b->mListNext = t;
    }
}

void ThreadListRemove(Thread *t) {
    Thread *p;
    Thread *b;

    b = 0;
    p = data_0216ff5c.mListHead;
    while (p != 0 && p != t) {
        b = p;
        p = p->mListNext;
    }
    if (b == 0) {
        data_0216ff5c.mListHead = t->mListNext;
    } else {
        b->mListNext = t->mListNext;
    }
}

void ThreadSystemInit(void) {
    s32 n;
    u8 *l;
    u8 *h;

    if (data_0216ff58 != 0) {
        return;
    }
    data_0216ff58 = 1;
    data_0216ff54 = &data_0216ff5c.mCurrentThread;
    data_0217002c.mSortKey = 0x10;
    data_0217002c.mUnk_6c = 0;
    data_0217002c.mUnk_64 = 1;
    data_0217002c.mListNext = 0;
    data_0217002c.mUnk_74 = 0;
    data_0216ff5c.mListHead = &data_0217002c;
    data_0216ff5c.mCurrentThread = &data_0217002c;
    n = (s32) data_00002800;
    if (n <= 0) {
        l = (u8 *) 0x27e00e0 - n;
    } else {
        l = (u8 *) &data_027e0000 + 0x3f80 - (u32) data_00000c00 - n;
    }
    h = (u8 *) &data_027e0000 + 0x3f80 - (u32) data_00000c00;
    data_0217002c.mStackHigh = h;
    data_0217002c.mStackLow = l;
    data_0217002c.mUnk_98 = 0;
    *(u32 *) (h - 4) = 0xfddb597d;
    *(u32 *) data_0217002c.mStackLow = 0x7bf9dd5b;
    data_0217002c.mEndQueue.mTail = 0;
    data_0217002c.mEndQueue.mHead = 0;
    data_0216ff5c.mUnk_00 = 0;
    data_0216ff5c.mUnk_02 = 0;
    *(ThreadSystem **) 0x027fffa0 = &data_0216ff5c;
    ThreadSetSwitchCallback(0);
    ThreadInit(&data_0216ff6c, func_0200dbd4, 0, (u8 *) &data_021701b4, 0xc8, 0x1f);
    data_0216ff6c.mSortKey = 0x20;
    data_0216ff6c.mUnk_64 = 1;
}

void ThreadInit(Thread *t, void (*f)(void *), void *a, u8 *p, u32 n, u32 v) {
    u32 s;
    u32 k;
    u8 *l;
    volatile u32 z;

    s = IrqDisable();
    k = func_0200e670();
    t->mSortKey = v;
    t->mUnk_6c = k;
    t->mUnk_64 = 0;
    t->mUnk_74 = 0;
    ThreadListInsert(t);
    t->mStackHigh = p;
    l = p - n;
    t->mStackLow = l;
    t->mUnk_98 = 0;
    *(u32 *) (t->mStackHigh - 4) = 0xfddb597d;
    *(u32 *) t->mStackLow = 0x7bf9dd5b;
    t->mEndQueue.mTail = 0;
    t->mEndQueue.mHead = t->mEndQueue.mTail;
    ThreadInitContext(t, f, (u32) p - 4);
    t->mUnk_04 = a;
    t->mUnk_3c = func_0200e260;
    z = 0;
    MemFillWords(z, l + 4, n - 8);
    func_0200db5c(t, 0);
    t->mWaitQueue = 0;
    t->mQueueNext = 0;
    t->mQueuePrev = t->mQueueNext;
    t->mUnk_b0 = 0;
    IrqRestore(s);
}

void func_0200e260(void) {
    IrqDisable();
    func_0200e1f0(data_0216ff5c.mCurrentThread, 0);
}

void func_0200e1f0(Thread *t, void *a) {
    if (data_0216ff44 != 0) {
        ThreadInitContext(t, func_0200e1ac, data_0216ff44);
        t->mUnk_04 = a;
        t->mUnk_00 = t->mUnk_00 | 0x80;
        t->mUnk_64 = 1;
        ThreadLoadContext(t);
    } else {
        func_0200e1ac(a);
    }
}

void func_0200e1ac(void *a) {
    Thread *t;
    void (*f)(void *);

    t = *data_0216ff54;
    f = t->mUnk_b4;
    if (f != 0) {
        t->mUnk_b4 = 0;
        f(a);
        IrqDisable();
    }
    ThreadEndCurrent();
}

void ThreadEndCurrent(void) {
    Thread *t;

    t = *data_0216ff54;
    ThreadSwitchDisable();
    ThreadUnlockAll(t);
    ThreadListRemove(t);
    t->mUnk_64 = 2;
    ThreadQueueSetAllRunnable(&t->mEndQueue);
    ThreadSwitchEnable();
    ThreadSwitch();
    IrqDisableLoopForever();
}

void ThreadEnd(Thread *t) {
    u32 s;

    s = IrqDisable();
    if (data_0216ff5c.mCurrentThread == t) {
        ThreadEndCurrent();
    }
    ThreadSwitchDisable();
    ThreadUnlockAll(t);
    func_0200e0c0(t);
    ThreadListRemove(t);
    t->mUnk_64 = 2;
    ThreadQueueSetAllRunnable(&t->mEndQueue);
    ThreadSwitchEnable();
    IrqRestore(s);
    ThreadSwitch();
}

void func_0200e0c0(Thread *arg0) {
    u32 value0 = (u32) arg0;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) * (const u32 *) ((value0) + (176));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    func_0200f8b8((Unk0200fb08 *) value0);
}

void ThreadWaitForEnd(Thread *t) {
    u32 s;

    s = IrqDisable();
    if (t->mUnk_64 != 2) {
        ThreadWait(&t->mEndQueue);
    }
    IrqRestore(s);
}

s32 ThreadHasEnded(Thread *t) {
    return t->mUnk_64 == 2;
}

void ThreadWait(ThreadQueue *q) {
    u32 s;
    Thread *t;

    s = IrqDisable();
    t = *data_0216ff54;
    if (q != 0) {
        t->mWaitQueue = q;
        ThreadQueueInsert(q, t);
    }
    t->mUnk_64 = 0;
    ThreadSwitch();
    IrqRestore(s);
}

void ThreadQueueSetAllRunnable(ThreadQueue *q) {
    u32 s;
    Thread *t;

    s = IrqDisable();
    if (q->mHead != 0) {
        while (q->mHead != 0) {
            t = ThreadQueueRemoveFront(q);
            t->mUnk_64 = 1;
            t->mWaitQueue = 0;
            t->mQueueNext = 0;
            t->mQueuePrev = t->mQueueNext;
        }
        q->mTail = 0;
        q->mHead = q->mTail;
        ThreadSwitch();
    }
    IrqRestore(s);
}

void ThreadSetRunnable(Thread *t) {
    u32 s;

    s = IrqDisable();
    t->mUnk_64 = 1;
    ThreadSwitch();
    IrqRestore(s);
}

Thread *ThreadFindFirstRunnable(void) {
    Thread *p;

    p = data_0216ff5c.mListHead;
    while (p != 0 && p->mUnk_64 != 1) {
        p = p->mListNext;
    }
    return p;
}

void ThreadSwitch(void) {
    ThreadSystem *s;
    Thread *a;
    Thread *b;

    s = &data_0216ff5c;
    if (data_0216ff48 != 0) {
        return;
    }
    if (s->mUnk_02 != 0 || ProcessorModeGet() == 0x12) {
        s->mUnk_00 = 1;
        return;
    }
    a = *data_0216ff54;
    b = ThreadFindFirstRunnable();
    if (a == b) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (a->mUnk_64 != 2) {
        if (ThreadSaveContext(a) != 0) {
            return;
        }
    }
    if (data_0216ff50 != 0) {
        data_0216ff50(a, b);
    }
    if (s->mSwitchCallback != 0) {
        s->mSwitchCallback(a, b);
    }
    data_0216ff5c.mCurrentThread = b;
    ThreadLoadContext(b);
}

void ThreadMoveCurrentAfterEqualSortKeys(void) {
    Thread *t;
    Thread *c;
    Thread *e;
    Thread *p;
    Thread *b;
    int n;
    u32 s;

    c = 0;
    e = 0;
    n = 0;
    t = data_0216ff5c.mCurrentThread;
    s = IrqDisable();
    b = 0;
    for (p = data_0216ff5c.mListHead; p != 0; p = p->mListNext) {
        if (p == t) {
            c = b;
        }
        if (t->mSortKey == p->mSortKey) {
            e = p;
            n++;
        }
        b = p;
    }
    if (n <= 1 || e == t) {
        IrqRestore(s);
        return;
    }
    if (c == 0) {
        data_0216ff5c.mListHead = t->mListNext;
    } else {
        c->mListNext = t->mListNext;
    }
    t->mListNext = e->mListNext;
    e->mListNext = t;
    ThreadSwitch();
    IrqRestore(s);
}

s32 ThreadSetSortKey(Thread *t, u32 v) {
    Thread *p;
    Thread *b;
    u32 s;

    p = data_0216ff5c.mListHead;
    b = 0;
    s = IrqDisable();
    while (p != 0 && p != t) {
        b = p;
        p = p->mListNext;
    }
    if (p == 0 || p == &data_0216ff6c) {
        IrqRestore(s);
        return 0;
    }
    if (p->mSortKey != v) {
        if (b == 0) {
            data_0216ff5c.mListHead = t->mListNext;
        } else {
            b->mListNext = t->mListNext;
        }
        t->mSortKey = v;
        ThreadListInsert(t);
        ThreadSwitch();
    }
    IrqRestore(s);
    return 1;
}

u32 ThreadGetSortKey(Thread *t) {
    return t->mSortKey;
}

void func_0200dc3c(u32 n) {
    Thread *t;
    Unk0200fb08 a;
    u32 s;

    func_0200fb08(&a);
    t = *data_0216ff54;
    s = IrqDisable();
    t->mUnk_b0 = &a;
    func_0200f950(&a, n * 0x82ea >> 6, (void (*)(void *)) func_0200dc1c, &t);
    while (t != 0) {
        ThreadWait(0);
    }
    IrqRestore(s);
}

void func_0200dc1c(Thread **arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    value12 = (u32) &ThreadSetRunnable;
    value0 = value2;
    *(u32 *) ((value2) + (176)) = value1;
    ThreadSetRunnable((Thread *) value0);
}

void (*ThreadSetSwitchCallback(void (*arg0)(Thread *, Thread *)))(Thread *, Thread *) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value0 = (u32) IrqDisable();
    value1 = (u32) &data_0216ff5c;
    value4 = (u32) * (const u32 *) ((value1) + (12));
    *(u32 *) ((value1) + (12)) = value5;
    value0 = (u32) IrqRestore(value0);
    value0 = value4;
    return (void (*)(Thread *, Thread *)) value0;
}

void func_0200dbd4(void *a) {
    IrqEnable();
    for (;;) {
        func_0200fd04();
    }
}

u32 ThreadSwitchDisable(void) {
    u32 s;
    u32 r;

    s = IrqDisable();
    if (data_0216ff48 < 0xffffffff) {
        r = data_0216ff48;
        data_0216ff48 = r + 1;
    }
    IrqRestore(s);
    return r;
}

u32 ThreadSwitchEnable(void) {
    u32 s;
    u32 r;

    s = IrqDisable();
    r = 0;
    if (data_0216ff48 != 0) {
        r = data_0216ff48;
        data_0216ff48 = r - 1;
    }
    IrqRestore(s);
    return r;
}

void func_0200db5c(Thread *t, void (*f)(void *)) {
    t->mUnk_b4 = f;
}

u32 ThreadSystemIsInit(void) {
    u32 value0;
    value0 = (u32) &data_0216ff58;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}
