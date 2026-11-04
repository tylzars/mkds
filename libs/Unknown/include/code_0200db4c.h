#pragma once

#include "types.h"

typedef struct ThreadQueue ThreadQueue;

#include "code_0200e77c.h"
#include "code_0200f790.h"

// Linked through mUnk_68 from data_0216ff5c.mUnk_08 in increasing mUnk_70 (ThreadListInsert); set up by ThreadInit.
typedef struct Unk0200db5c {
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
    /* 68 */ struct Unk0200db5c *mListNext;
    /* 6c */ u32 mUnk_6c;
    /* 70 */ u32 mSortKey;
    /* 74 */ u32 mUnk_74;
    /* 78 */ ThreadQueue *mWaitQueue;
    /* 7c */ struct Unk0200db5c *mQueuePrev;
    /* 80 */ struct Unk0200db5c *mQueueNext;
    /* 84 */ ThreadLock *mUnk_84; // set by ThreadLockWait around its call to ThreadWait
    /* 88 */ ThreadLockList mLockList;
    /* 90 */ u8 *mStackLow;
    /* 94 */ u8 *mStackHigh;
    /* 98 */ u32 mUnk_98;
    /* 9c */ ThreadQueue mEndQueue;
    /* a4 */ u8 mUnk_a4[0xc];
    /* b0 */ Unk0200fb08 *mUnk_b0;
    /* b4 */ void (*mUnk_b4)(void *);
} Unk0200db5c;

// Object at data_0216ff5c; ThreadSystemInit stores the address of mUnk_04 in data_0216ff54.
typedef struct ThreadSystem {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Unk0200db5c *mCurrentThread;
    /* 08 */ Unk0200db5c *mListHead;
    /* 0c */ void (*mSwitchCallback)(Unk0200db5c *, Unk0200db5c *);
} ThreadSystem;

void (*ThreadSetSwitchCallback(void (*arg0)(Unk0200db5c *, Unk0200db5c *)))(Unk0200db5c *, Unk0200db5c *);

u32 ThreadSystemIsInit(void);
void func_0200db5c(Unk0200db5c *t, void (*f)(void *));
u32 ThreadSwitchEnable(void);
u32 ThreadSwitchDisable(void);
void func_0200dbd4(void *a);
void func_0200dc1c(Unk0200db5c **arg0);
void func_0200dc3c(u32 n);
u32 ThreadGetSortKey(Unk0200db5c *t);
s32 ThreadSetSortKey(Unk0200db5c *t, u32 v);
void ThreadMoveCurrentAfterEqualSortKeys(void);
void ThreadSwitch(void);
Unk0200db5c *ThreadFindFirstRunnable(void);
void ThreadSetRunnable(Unk0200db5c *t);
void ThreadQueueSetAllRunnable(ThreadQueue *q);
void ThreadWait(ThreadQueue *q);
s32 ThreadHasEnded(Unk0200db5c *t);
void ThreadWaitForEnd(Unk0200db5c *t);
void func_0200e0c0(Unk0200db5c *arg0);
void ThreadEnd(Unk0200db5c *t);
void ThreadEndCurrent(void);
void func_0200e1ac(void *a);
void func_0200e1f0(Unk0200db5c *t, void *a);
void func_0200e260(void);
void ThreadInit(Unk0200db5c *t, void (*f)(void *), void *a, u8 *p, u32 n, u32 v);
void ThreadSystemInit(void);
void ThreadListRemove(Unk0200db5c *t);
void ThreadListInsert(Unk0200db5c *t);
ThreadLock *ThreadLockListRemoveFront(ThreadLockList *q);
Unk0200db5c *ThreadQueueRemoveFront(ThreadQueue *q);
void ThreadQueueInsert(ThreadQueue *q, Unk0200db5c *t);
u32 func_0200e670(void);
