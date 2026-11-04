#pragma once

#include "types.h"

struct Unk0200db5c;

// Two Unk0200db5c pointers; ThreadQueueInsert and ThreadQueueRemoveFront link the objects through their mUnk_80 and
// mUnk_7c. ThreadQueueSetAllRunnable and ThreadWait take it.
typedef struct ThreadQueue {
    /* 00 */ struct Unk0200db5c *mHead;
    /* 04 */ struct Unk0200db5c *mTail;
} ThreadQueue;

// 0x18 bytes; ThreadLockInit clears mUnk_00 to mUnk_0c. ThreadLockListAppend and ThreadLockListRemove link it through
// mUnk_10 and mUnk_14 into the ThreadLockList at mUnk_88 of an Unk0200db5c.
typedef struct ThreadLock {
    /* 00 */ ThreadQueue mQueue;
    /* 08 */ struct Unk0200db5c *mHolder; // set by ThreadLockTry and ThreadLockWait
    /* 0c */ u32 mLockCount; // raised by ThreadLockTry and ThreadLockWait, lowered by ThreadLockUnlock
    /* 10 */ struct ThreadLock *mNext;
    /* 14 */ struct ThreadLock *mPrev;
} ThreadLock;

typedef struct ThreadLockList {
    /* 00 */ ThreadLock *mHead;
    /* 04 */ ThreadLock *mTail;
} ThreadLockList;

// Set up by RingQueueInit. RingQueueAppend stores a word at mUnk_10[(mUnk_18 + mUnk_1c) % mUnk_14] and raises mUnk_1c;
// RingQueueRemoveFront reads mUnk_10[mUnk_18], advances mUnk_18 modulo mUnk_14 and lowers mUnk_1c. Each calls
// ThreadWait on one of mUnk_00 and mUnk_08 and ThreadQueueSetAllRunnable on the other.
typedef struct RingQueue {
    /* 00 */ ThreadQueue mFullWaiters;
    /* 08 */ ThreadQueue mEmptyWaiters;
    /* 10 */ void **mBuffer;
    /* 14 */ s32 mCapacity;
    /* 18 */ s32 mHeadIndex;
    /* 1c */ s32 mCount;
} RingQueue;

extern u32 data_021617cc;

u32 func_0200e77c(void);
u32 func_0200e7b0(void);
u32 func_0200e884(void);
u32 func_0200e8fc(void);
s32 RingQueuePeekFront(RingQueue *q, void **p, s32 f);
s32 RingQueuePrepend(RingQueue *q, void *v, s32 f);
s32 RingQueueRemoveFront(RingQueue *q, void **p, s32 f);
s32 RingQueueAppend(RingQueue *q, void *v, s32 f);
void RingQueueInit(RingQueue *q, void **p, s32 n);
void ThreadLockListRemove(struct Unk0200db5c *t, ThreadLock *n);
void ThreadLockListAppend(struct Unk0200db5c *t, ThreadLock *n);
// p is used as an ThreadLock: these three write +0x08 and +0x0c, ThreadLockListAppend and ThreadLockListRemove (called
// with p) write +0x10 and +0x14, and ThreadWait and ThreadQueueSetAllRunnable (given p) write +0x00 and +0x04.
// data_0217eadc passes elements 0x14 bytes apart, so +0x14 of one element is +0x00 of the next.
s32 ThreadLockTry(void *p);
void ThreadUnlockAll(struct Unk0200db5c *t);
void ThreadLockUnlock(void *p);
void ThreadLockWait(void *p);
