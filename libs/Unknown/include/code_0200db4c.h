#pragma once

#include "types.h"

#include "code_0200e77c.h"
#include "code_0200f790.h"

// The thread control block. The threads are linked through OSThread.mNext from data_0216ff5c.mListHead in increasing
// OSThread.mPriority; OS_CreateThread sets one up.
typedef struct OSThread {
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
    /* 64 */ u32 mState; // 0 waiting, 1 ready, 2 terminated
    /* 68 */ struct OSThread *mNext;
    // The id OSi_GetUnusedThreadId gives (0 for the first thread); the game tests it against 0 and the C library code
    // keeps a copy of the first thread's value in data_0217ea94 and compares it later.
    /* 6c */ u32 mId;
    /* 70 */ u32 mPriority;
    /* 74 */ u32 mProfiler;
    /* 78 */ OSThreadQueue *mQueue;
    /* 7c */ struct OSThread *mLinkPrev;
    /* 80 */ struct OSThread *mLinkNext;
    /* 84 */ OSMutex *mMutex; // set by OS_LockMutex around its call to OS_SleepThread
    /* 88 */ OSMutexQueue mMutexQueue;
    /* 90 */ u8 *mStackTop;
    /* 94 */ u8 *mStackBottom;
    /* 98 */ u32 mStackWarningOffset;
    /* 9c */ OSThreadQueue mJoinQueue;
    /* a4 */ u8 mUnk_a4[0xc];
    // The alarm of the OS_Sleep call the thread is in, 0 otherwise; OS_CreateThread and OSi_SleepAlarmCallback set it
    // to 0, OS_Sleep sets it, OSi_CancelThreadAlarmForSleep cancels it.
    /* b0 */ Unk0200fb08 *mAlarmForSleep;
    // What OS_SetThreadDestructor stores; OSi_ExitThread clears it and calls it with the exit argument.
    /* b4 */ void (*mDestructor)(void *);
} OSThread;

// The thread switch callback type.
typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

// Object at data_0216ff5c; OS_InitThread stores the address of mCurrentThread in data_0216ff54.
typedef struct ThreadSystem {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ OSThread *mCurrentThread;
    /* 08 */ OSThread *mListHead;
    /* 0c */ OSSwitchThreadCallback mSwitchCallback;
} ThreadSystem;

typedef void (*OSThreadDestructor)(void *);

OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback);

u32 OS_IsThreadAvailable(void);
// Stores dtor in OSThread.mDestructor.
void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor dtor);
u32 OS_EnableScheduler(void);
u32 OS_DisableScheduler(void);
// Thread function of the idle thread: enables interrupts, then halts in an endless loop.
void OSi_IdleThreadProc(void *arg);
// Alarm callback of OS_Sleep: wakes the thread that arg points to and clears OSThread.mAlarmForSleep.
void OSi_SleepAlarmCallback(OSThread **arg);
// Sleeps the current thread for msec milliseconds with an alarm.
void OS_Sleep(u32 msec);
u32 OS_GetThreadPriority(OSThread *thread);
s32 OS_SetThreadPriority(OSThread *thread, u32 prio);
void OS_YieldThread(void);
void OSi_RescheduleThread(void);
OSThread *OS_SelectThread(void);
void OS_WakeupThreadDirect(OSThread *thread);
void OS_WakeupThread(OSThreadQueue *queue);
void OS_SleepThread(OSThreadQueue *queue);
s32 OS_IsThreadTerminated(OSThread *thread);
void OS_JoinThread(OSThread *thread);
// Cancels OSThread.mAlarmForSleep when it is set; does not clear it.
void OSi_CancelThreadAlarmForSleep(OSThread *thread);
void OS_DestroyThread(OSThread *thread);
void OSi_ExitThread_Destroy(void);
// Calls the thread's destructor with arg when it has one, then ends the current thread.
void OSi_ExitThread(void *arg);
// Ends thread, running OSi_ExitThread on a separate stack when data_0216ff44 is set.
void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg);
// Ends the current thread; OS_CreateThread stores it as the return address of every new thread.
void OS_ExitThread(void);
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, u8 *stack, u32 stackSize, u32 prio);
void OS_InitThread(void);
void OSi_RemoveThreadFromList(OSThread *thread);
void OSi_InsertThreadToList(OSThread *thread);
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue);
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
// Adds 1 to the thread id counter and returns the new value.
u32 OSi_GetUnusedThreadId(void);
