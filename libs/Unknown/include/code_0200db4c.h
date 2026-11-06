#pragma once

#include "types.h"

typedef struct ThreadQueue ThreadQueue;

#include "code_0200e77c.h"
#include "code_0200f790.h"

// Linked through mUnk_68 from data_0216ff5c.mListHead in increasing mUnk_70 (ThreadListInsert); set up by ThreadInit.
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
    /* 48 */ u8 mUnk_48[0x1c]; // its address goes to the functions called by OS_SaveContext and OS_LoadContext
    /* 64 */ u32 mUnk_64;
    /* 68 */ struct Thread *mListNext;
    // The AllocThreadId result that ThreadInit stores (0 for the first thread); the game tests it against 0 and the
    // C library code keeps a copy of the first thread's value in data_0217ea94 and compares it later.
    /* 6c */ u32 mId;
    /* 70 */ u32 mSortKey;
    /* 74 */ u32 mUnk_74;
    /* 78 */ ThreadQueue *mWaitQueue;
    /* 7c */ struct Thread *mQueuePrev;
    /* 80 */ struct Thread *mQueueNext;
    /* 84 */ OSMutex *mUnk_84; // set by OS_LockMutex around its call to ThreadWait
    /* 88 */ ThreadLockList mLockList;
    /* 90 */ u8 *mStackLow;
    /* 94 */ u8 *mStackHigh;
    /* 98 */ u32 mUnk_98;
    /* 9c */ ThreadQueue mEndQueue;
    /* a4 */ u8 mUnk_a4[0xc];
    // Address of the alarm of the OS_Sleep call the thread is in, 0 otherwise; ThreadInit and WakeSleepingThread
    // set it to 0, OS_Sleep sets it, CancelThreadSleepAlarm cancels it.
    /* b0 */ Unk0200fb08 *mSleepAlarm;
    // The function OS_SetThreadDestructor stores; RunExitCallbackThenEndThread clears it and calls it with the exit
    // argument.
    /* b4 */ void (*mExitCallback)(void *);
} Thread;

// Object at data_0216ff5c; ThreadSystemInit stores the address of mCurrentThread in data_0216ff54.
typedef struct ThreadSystem {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Thread *mCurrentThread;
    /* 08 */ Thread *mListHead;
    /* 0c */ void (*mSwitchCallback)(Thread *, Thread *);
} ThreadSystem;

void (*ThreadSetSwitchCallback(void (*arg0)(Thread *, Thread *)))(Thread *, Thread *);

u32 ThreadSystemIsInit(void);
// Stores f in t->mExitCallback (two instructions). ThreadInit calls it with 0; RunExitCallbackThenEndThread reads the
// member.
void OS_SetThreadDestructor(Thread *t, void (*f)(void *));
u32 ThreadSwitchEnable(void);
u32 ThreadSwitchDisable(void);
// Entry function of the thread that ThreadSystemInit creates last (sort key 0x20): calls IrqEnable, then OS_Halt in
// an endless loop.
void ThreadHaltLoop(void *a);
// The alarm callback of OS_Sleep: takes the thread pointer from *p, sets *p and the thread's mSleepAlarm to 0 and
// calls ThreadSetRunnable on the thread.
void WakeSleepingThread(Thread **arg0);
// Creates an alarm on the stack (OS_CreateAlarm), calls IrqDisable, stores the alarm address in the current thread's
// mSleepAlarm and starts it (OS_SetAlarm) for n * 0x82ea >> 6 ticks with WakeSleepingThread as the callback and the
// address of a local copy of the thread pointer as its argument. Calls ThreadWait(0) until that local is 0, then
// IrqRestore.
void OS_Sleep(u32 n);
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
// Calls OS_CancelAlarm(t->mSleepAlarm) when the member is not 0; does not clear it. Its only caller is ThreadEnd.
void CancelThreadSleepAlarm(Thread *arg0);
void ThreadEnd(Thread *t);
void ThreadEndCurrent(void);
// Takes the current thread, calls its mExitCallback with a when it is not 0 (clearing the member first, and calling
// IrqDisable after), then calls ThreadEndCurrent.
void RunExitCallbackThenEndThread(void *a);
// When the word data_0216ff44 (nothing writes it) is not 0: ThreadInitContext(t, RunExitCallbackThenEndThread, that
// word), stores a at +4 of t, sets bit 0x80 of the first word of t, sets the member at +0x64 to 1 and calls
// OS_LoadContext(t). Otherwise calls RunExitCallbackThenEndThread(a). Its only caller is OS_ExitThread.
void ThreadEndWithArg(Thread *t, void *a);
// Calls IrqDisable and then ThreadEndWithArg(current thread, 0). ThreadInit stores it in the member at +0x3c of every
// new thread, so a thread function that returns ends here; func_0200b08c also calls it.
void OS_ExitThread(void);
void ThreadInit(Thread *t, void (*f)(void *), void *a, u8 *p, u32 n, u32 v);
void ThreadSystemInit(void);
void ThreadListRemove(Thread *t);
void ThreadListInsert(Thread *t);
OSMutex *ThreadLockListRemoveFront(ThreadLockList *q);
Thread *ThreadQueueRemoveFront(ThreadQueue *q);
void ThreadQueueInsert(ThreadQueue *q, Thread *t);
// Adds 1 to gThreadIdCount and returns the new value. ThreadInit stores it in the thread's mId.
u32 AllocThreadId(void);
