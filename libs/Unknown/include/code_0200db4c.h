#pragma once

#include "types.h"

typedef struct ThreadQueue ThreadQueue;

#include "code_0200e77c.h"
#include "code_0200f790.h"

// Linked through mUnk_68 from data_0216ff5c.mUnk_08 in increasing mUnk_70 (ThreadListInsert); set up by ThreadInit.
typedef struct Thread {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ void (*mUnk_3c)(void);
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u8 mUnk_48[0x1c]; // its address goes to the functions called by ThreadSaveContext and ThreadLoadContext
    /* 64 */ u32 mUnk_64;
    /* 68 */ struct Thread *mListNext;
    /* 6c */ u32 mUnk_6c;
    /* 70 */ u32 mSortKey;
    /* 74 */ u32 mUnk_74;
    /* 78 */ ThreadQueue *mWaitQueue;
    /* 7c */ struct Thread *mQueuePrev;
    /* 80 */ struct Thread *mQueueNext;
    /* 84 */ ThreadLock *mUnk_84; // set by ThreadLockWait around its call to ThreadWait
    /* 88 */ ThreadLockList mLockList;
    /* 90 */ u8 *mStackLow;
    /* 94 */ u8 *mStackHigh;
    /* 98 */ u32 mUnk_98;
    /* 9c */ ThreadQueue mEndQueue;
    /* a4 */ u8 mUnk_a4[0xc];
    /* b0 */ Unk0200fb08 *mUnk_b0;
    /* b4 */ void (*mUnk_b4)(void *);
} Thread;

// Object at data_0216ff5c; ThreadSystemInit stores the address of mUnk_04 in data_0216ff54.
typedef struct ThreadSystem {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Thread *mCurrentThread;
    /* 08 */ Thread *mListHead;
    /* 0c */ void (*mSwitchCallback)(Thread *, Thread *);
} ThreadSystem;

void (*ThreadSetSwitchCallback(void (*arg0)(Thread *, Thread *)))(Thread *, Thread *);

u32 ThreadSystemIsInit(void);
void func_0200db5c(Thread *t, void (*f)(void *));
u32 ThreadSwitchEnable(void);
u32 ThreadSwitchDisable(void);
void func_0200dbd4(void *a);
void func_0200dc1c(Thread **arg0);
void func_0200dc3c(u32 n);
u32 ThreadGetSortKey(Thread *t);
s32 ThreadSetSortKey(Thread *t, u32 v);
void ThreadMoveCurrentAfterEqualSortKeys(void);
void ThreadSwitch(void);
Thread *ThreadFindFirstRunnable(void);
void ThreadSetRunnable(Thread *t);
void ThreadQueueSetAllRunnable(ThreadQueue *q);
void ThreadWait(ThreadQueue *q);
s32 ThreadHasEnded(Thread *t);
void ThreadWaitForEnd(Thread *t);
void func_0200e0c0(Thread *arg0);
void ThreadEnd(Thread *t);
void ThreadEndCurrent(void);
void func_0200e1ac(void *a);
void func_0200e1f0(Thread *t, void *a);
void func_0200e260(void);
void ThreadInit(Thread *t, void (*f)(void *), void *a, u8 *p, u32 n, u32 v);
void ThreadSystemInit(void);
void ThreadListRemove(Thread *t);
void ThreadListInsert(Thread *t);
ThreadLock *ThreadLockListRemoveFront(ThreadLockList *q);
Thread *ThreadQueueRemoveFront(ThreadQueue *q);
void ThreadQueueInsert(ThreadQueue *q, Thread *t);
u32 func_0200e670(void);
