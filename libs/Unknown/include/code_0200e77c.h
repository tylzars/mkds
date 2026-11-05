#pragma once

#include "types.h"

struct Thread;

// Two Thread pointers; ThreadQueueInsert and ThreadQueueRemoveFront link the objects through their mQueueNext and
// mQueuePrev. ThreadQueueSetAllRunnable and ThreadWait take it.
typedef struct ThreadQueue {
    /* 00 */ struct Thread *mHead;
    /* 04 */ struct Thread *mTail;
} ThreadQueue;

// 0x18 bytes; ThreadLockInit clears mQueue to mLockCount. ThreadLockListAppend and ThreadLockListRemove link it through
// mNext and mPrev into the ThreadLockList at mLockList of a Thread.
typedef struct ThreadLock {
    /* 00 */ ThreadQueue mQueue;
    /* 08 */ struct Thread *mHolder; // set by ThreadLockTry and ThreadLockWait
    /* 0c */ u32 mLockCount; // raised by ThreadLockTry and ThreadLockWait, lowered by ThreadLockUnlock
    /* 10 */ struct ThreadLock *mNext;
    /* 14 */ struct ThreadLock *mPrev;
} ThreadLock;

typedef struct ThreadLockList {
    /* 00 */ ThreadLock *mHead;
    /* 04 */ ThreadLock *mTail;
} ThreadLockList;

// Set up by RingQueueInit. RingQueueAppend stores a word at mBuffer[(mHeadIndex + mCount) % mCapacity] and raises
// mCount; RingQueueRemoveFront reads mBuffer[mHeadIndex], advances mHeadIndex modulo mCapacity and lowers mCount. Each
// calls ThreadWait on one of mFullWaiters and mEmptyWaiters and ThreadQueueSetAllRunnable on the other.
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
void ThreadLockListRemove(struct Thread *t, ThreadLock *n);
void ThreadLockListAppend(struct Thread *t, ThreadLock *n);
// p is used as an ThreadLock: these three write +0x08 and +0x0c, ThreadLockListAppend and ThreadLockListRemove (called
// with p) write +0x10 and +0x14, and ThreadWait and ThreadQueueSetAllRunnable (given p) write +0x00 and +0x04.
// data_0217eadc passes elements 0x14 bytes apart, so +0x14 of one element is +0x00 of the next.
s32 ThreadLockTry(void *p);
void ThreadUnlockAll(struct Thread *t);
void ThreadLockUnlock(void *p);
void ThreadLockWait(void *p);
