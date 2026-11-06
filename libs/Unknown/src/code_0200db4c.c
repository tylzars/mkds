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
#include "code_0200e6ec.h"

// Adds 1 to the thread id counter and returns the new value.
u32 OSi_GetUnusedThreadId(void) {
    gThreadIdCount = gThreadIdCount + 1;
    return gThreadIdCount;
}

// Inserts thread into queue behind the threads of equal or lower OSThread.mPriority value, and does nothing when it is
// already in it.
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread) {
    OSThread *next;
    OSThread *prev;

    next = queue->mHead;
    while (next != 0 && next->mPriority <= thread->mPriority) {
        if (next == thread) {
            return;
        }
        next = next->mLinkNext;
    }
    if (next == 0) {
        prev = queue->mTail;
        if (prev == 0) {
            queue->mHead = thread;
        } else {
            prev->mLinkNext = thread;
        }
        thread->mLinkPrev = prev;
        thread->mLinkNext = 0;
        queue->mTail = thread;
    } else {
        prev = next->mLinkPrev;
        if (prev == 0) {
            queue->mHead = thread;
        } else {
            prev->mLinkNext = thread;
        }
        thread->mLinkPrev = prev;
        thread->mLinkNext = next;
        next->mLinkPrev = thread;
    }
}

// Takes the first thread out of queue and returns it, or returns 0 when the queue is empty.
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue) {
    OSThread *thread;
    OSThread *next;

    thread = queue->mHead;
    if (thread != 0) {
        next = thread->mLinkNext;
        queue->mHead = next;
        if (next != 0) {
            next->mLinkPrev = 0;
        } else {
            queue->mTail = 0;
            thread->mQueue = 0;
        }
    }
    return thread;
}

// Takes the first mutex out of queue and returns it, or returns 0 when the queue is empty.
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue) {
    OSMutex *mutex;
    OSMutex *next;

    mutex = queue->mHead;
    if (mutex != 0) {
        next = mutex->mNext;
        queue->mHead = next;
        if (next != 0) {
            next->mPrev = 0;
        } else {
            queue->mTail = 0;
        }
    }
    return mutex;
}

// Links thread into the thread list in increasing OSThread.mPriority.
void OSi_InsertThreadToList(OSThread *thread) {
    OSThread *current;
    OSThread *prev;
    OSThread *head;

    prev = 0;
    head = data_0216ff5c.mListHead;
    current = head;
    while (current != 0 && current->mPriority < thread->mPriority) {
        prev = current;
        current = current->mNext;
    }
    if (prev == 0) {
        thread->mNext = head;
        data_0216ff5c.mListHead = thread;
    } else {
        thread->mNext = prev->mNext;
        prev->mNext = thread;
    }
}

// Unlinks thread from the thread list.
void OSi_RemoveThreadFromList(OSThread *thread) {
    OSThread *current;
    OSThread *prev;

    prev = 0;
    current = data_0216ff5c.mListHead;
    while (current != 0 && current != thread) {
        prev = current;
        current = current->mNext;
    }
    if (prev == 0) {
        data_0216ff5c.mListHead = thread->mNext;
    } else {
        prev->mNext = thread->mNext;
    }
}

// Sets up the thread system once: the main thread record and the idle thread.
void OS_InitThread(void) {
    s32 stackSize;
    u8 *stackTop;
    u8 *stackBottom;

    if (data_0216ff58 != 0) {
        return;
    }
    data_0216ff58 = 1;
    data_0216ff54 = &data_0216ff5c.mCurrentThread;
    data_0217002c.mPriority = 0x10;
    data_0217002c.mId = 0;
    data_0217002c.mState = 1;
    data_0217002c.mNext = 0;
    data_0217002c.mProfiler = 0;
    data_0216ff5c.mListHead = &data_0217002c;
    data_0216ff5c.mCurrentThread = &data_0217002c;
    stackSize = (s32) data_00002800;
    if (stackSize <= 0) {
        stackTop = (u8 *) 0x27e00e0 - stackSize;
    } else {
        stackTop = (u8 *) &data_027e0000 + 0x3f80 - (u32) data_00000c00 - stackSize;
    }
    stackBottom = (u8 *) &data_027e0000 + 0x3f80 - (u32) data_00000c00;
    data_0217002c.mStackBottom = stackBottom;
    data_0217002c.mStackTop = stackTop;
    data_0217002c.mStackWarningOffset = 0;
    *(u32 *) (stackBottom - 4) = 0xfddb597d;
    *(u32 *) data_0217002c.mStackTop = 0x7bf9dd5b;
    data_0217002c.mJoinQueue.mTail = 0;
    data_0217002c.mJoinQueue.mHead = 0;
    data_0216ff5c.mUnk_00 = 0;
    data_0216ff5c.mUnk_02 = 0;
    *(ThreadSystem **) 0x027fffa0 = &data_0216ff5c;
    OS_SetSwitchThreadCallback(0);
    OS_CreateThread(&data_0216ff6c, OSi_IdleThreadProc, 0, (u8 *) &data_021701b4, 0xc8, 0x1f);
    data_0216ff6c.mPriority = 0x20;
    data_0216ff6c.mState = 1;
}

// Sets up thread to run func with arg on the given stack at priority prio, and links it into the thread list.
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, u8 *stack, u32 stackSize, u32 prio) {
    u32 enabled;
    u32 id;
    u8 *stackTop;
    volatile u32 fill;

    enabled = OS_DisableInterrupts();
    id = OSi_GetUnusedThreadId();
    thread->mPriority = prio;
    thread->mId = id;
    thread->mState = 0;
    thread->mProfiler = 0;
    OSi_InsertThreadToList(thread);
    thread->mStackBottom = stack;
    stackTop = stack - stackSize;
    thread->mStackTop = stackTop;
    thread->mStackWarningOffset = 0;
    *(u32 *) (thread->mStackBottom - 4) = 0xfddb597d;
    *(u32 *) thread->mStackTop = 0x7bf9dd5b;
    thread->mJoinQueue.mTail = 0;
    thread->mJoinQueue.mHead = thread->mJoinQueue.mTail;
    ThreadInitContext(thread, func, (u32) stack - 4);
    thread->mUnk_04 = arg;
    thread->mUnk_3c = OS_ExitThread;
    fill = 0;
    MemFillWords(fill, stackTop + 4, stackSize - 8);
    OS_SetThreadDestructor(thread, 0);
    thread->mQueue = 0;
    thread->mLinkNext = 0;
    thread->mLinkPrev = thread->mLinkNext;
    thread->mAlarmForSleep = 0;
    OS_RestoreInterrupts(enabled);
}

// Ends the current thread.
void OS_ExitThread(void) {
    OS_DisableInterrupts();
    OSi_ExitThread_ArgSpecified(data_0216ff5c.mCurrentThread, 0);
}

// When data_0216ff44 is set, restarts thread on that stack in OSi_ExitThread with arg; otherwise calls OSi_ExitThread.
void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg) {
    if (data_0216ff44 != 0) {
        ThreadInitContext(thread, OSi_ExitThread, data_0216ff44);
        thread->mUnk_04 = arg;
        thread->mUnk_00 = thread->mUnk_00 | 0x80;
        thread->mState = 1;
        OS_LoadContext(thread);
    } else {
        OSi_ExitThread(arg);
    }
}

// Runs and clears OSThread.mDestructor of the current thread with arg, then ends the thread.
void OSi_ExitThread(void *arg) {
    OSThread *current;
    OSThreadDestructor destructor;

    current = *data_0216ff54;
    destructor = current->mDestructor;
    if (destructor != 0) {
        current->mDestructor = 0;
        destructor(arg);
        OS_DisableInterrupts();
    }
    OSi_ExitThread_Destroy();
}

// Releases the mutexes of the current thread, unlists it, marks it terminated, wakes the threads joining it and
// switches away for good.
void OSi_ExitThread_Destroy(void) {
    OSThread *current;

    current = *data_0216ff54;
    OS_DisableScheduler();
    OSi_UnlockAllMutex(current);
    OSi_RemoveThreadFromList(current);
    current->mState = 2;
    OS_WakeupThread(&current->mJoinQueue);
    OS_EnableScheduler();
    OSi_RescheduleThread();
    OS_Terminate();
}

// Ends thread: the current thread exits; any other one has its mutexes released and its sleep alarm cancelled, is
// unlisted and marked terminated, and the threads joining it wake up.
void OS_DestroyThread(OSThread *thread) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (data_0216ff5c.mCurrentThread == thread) {
        OSi_ExitThread_Destroy();
    }
    OS_DisableScheduler();
    OSi_UnlockAllMutex(thread);
    OSi_CancelThreadAlarmForSleep(thread);
    OSi_RemoveThreadFromList(thread);
    thread->mState = 2;
    OS_WakeupThread(&thread->mJoinQueue);
    OS_EnableScheduler();
    OS_RestoreInterrupts(enabled);
    OSi_RescheduleThread();
}

// Cancels OSThread.mAlarmForSleep when it is set.
void OSi_CancelThreadAlarmForSleep(OSThread *thread) {
    if (thread->mAlarmForSleep != 0) {
        OS_CancelAlarm(thread->mAlarmForSleep);
    }
}

// Sleeps until thread is terminated.
void OS_JoinThread(OSThread *thread) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (thread->mState != 2) {
        OS_SleepThread(&thread->mJoinQueue);
    }
    OS_RestoreInterrupts(enabled);
}

// Returns whether OSThread.mState of thread is terminated.
s32 OS_IsThreadTerminated(OSThread *thread) {
    return thread->mState == 2;
}

// Puts the current thread to sleep, on queue when there is one, and switches to another thread.
void OS_SleepThread(OSThreadQueue *queue) {
    u32 enabled;
    OSThread *current;

    enabled = OS_DisableInterrupts();
    current = *data_0216ff54;
    if (queue != 0) {
        current->mQueue = queue;
        OSi_InsertLinkToQueue(queue, current);
    }
    current->mState = 0;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(enabled);
}

// Makes every thread on queue ready and empties the queue.
void OS_WakeupThread(OSThreadQueue *queue) {
    u32 enabled;
    OSThread *thread;

    enabled = OS_DisableInterrupts();
    if (queue->mHead != 0) {
        while (queue->mHead != 0) {
            thread = OSi_RemoveLinkFromQueue(queue);
            thread->mState = 1;
            thread->mQueue = 0;
            thread->mLinkNext = 0;
            thread->mLinkPrev = thread->mLinkNext;
        }
        queue->mTail = 0;
        queue->mHead = queue->mTail;
        OSi_RescheduleThread();
    }
    OS_RestoreInterrupts(enabled);
}

// Makes thread ready.
void OS_WakeupThreadDirect(OSThread *thread) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    thread->mState = 1;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(enabled);
}

// Returns the first ready thread of the thread list, or 0.
OSThread *OS_SelectThread(void) {
    OSThread *thread;

    thread = data_0216ff5c.mListHead;
    while (thread != 0 && thread->mState != 1) {
        thread = thread->mNext;
    }
    return thread;
}

// Switches to the first ready thread when that is not the current one. Inside an interrupt, or with the scheduler
// disabled, it only notes that a switch is due.
void OSi_RescheduleThread(void) {
    ThreadSystem *system;
    OSThread *current;
    OSThread *next;

    system = &data_0216ff5c;
    if (data_0216ff48 != 0) {
        return;
    }
    if (system->mUnk_02 != 0 || OS_GetProcMode() == 0x12) {
        system->mUnk_00 = 1;
        return;
    }
    current = *data_0216ff54;
    next = OS_SelectThread();
    if (current == next) {
        return;
    }
    if (next == 0) {
        return;
    }
    if (current->mState != 2) {
        if (OS_SaveContext(current) != 0) {
            return;
        }
    }
    if (data_0216ff50 != 0) {
        data_0216ff50(current, next);
    }
    if (system->mSwitchCallback != 0) {
        system->mSwitchCallback(current, next);
    }
    data_0216ff5c.mCurrentThread = next;
    OS_LoadContext(next);
}

// Moves the current thread behind the last thread of equal OSThread.mPriority in the thread list and reschedules.
void OS_YieldThread(void) {
    OSThread *current;
    OSThread *currentPrev;
    OSThread *lastEqual;
    OSThread *thread;
    OSThread *prev;
    int count;
    u32 enabled;

    currentPrev = 0;
    lastEqual = 0;
    count = 0;
    current = data_0216ff5c.mCurrentThread;
    enabled = OS_DisableInterrupts();
    prev = 0;
    for (thread = data_0216ff5c.mListHead; thread != 0; thread = thread->mNext) {
        if (thread == current) {
            currentPrev = prev;
        }
        if (current->mPriority == thread->mPriority) {
            lastEqual = thread;
            count++;
        }
        prev = thread;
    }
    if (count <= 1 || lastEqual == current) {
        OS_RestoreInterrupts(enabled);
        return;
    }
    if (currentPrev == 0) {
        data_0216ff5c.mListHead = current->mNext;
    } else {
        currentPrev->mNext = current->mNext;
    }
    current->mNext = lastEqual->mNext;
    lastEqual->mNext = current;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(enabled);
}

// Gives thread the priority prio and relists it. Returns 0 for the idle thread and for a thread that is not listed.
s32 OS_SetThreadPriority(OSThread *thread, u32 prio) {
    OSThread *current;
    OSThread *prev;
    u32 enabled;

    current = data_0216ff5c.mListHead;
    prev = 0;
    enabled = OS_DisableInterrupts();
    while (current != 0 && current != thread) {
        prev = current;
        current = current->mNext;
    }
    if (current == 0 || current == &data_0216ff6c) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (current->mPriority != prio) {
        if (prev == 0) {
            data_0216ff5c.mListHead = thread->mNext;
        } else {
            prev->mNext = thread->mNext;
        }
        thread->mPriority = prio;
        OSi_InsertThreadToList(thread);
        OSi_RescheduleThread();
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Returns OSThread.mPriority of thread.
u32 OS_GetThreadPriority(OSThread *thread) {
    return thread->mPriority;
}

// Sleeps the current thread for msec milliseconds: an alarm wakes it up again.
void OS_Sleep(u32 msec) {
    OSThread *thread;
    OSAlarm alarm;
    u32 enabled;

    OS_CreateAlarm(&alarm);
    thread = *data_0216ff54;
    enabled = OS_DisableInterrupts();
    thread->mAlarmForSleep = &alarm;
    OS_SetAlarm(&alarm, msec * 0x82ea >> 6, (void (*)(void *)) OSi_SleepAlarmCallback, &thread);
    while (thread != 0) {
        OS_SleepThread(0);
    }
    OS_RestoreInterrupts(enabled);
}

// Alarm callback of OS_Sleep: clears the thread pointer arg points to and the thread's OSThread.mAlarmForSleep, then
// makes the thread ready.
void OSi_SleepAlarmCallback(OSThread **arg) {
    OSThread *thread;

    thread = *arg;
    *arg = 0;
    thread->mAlarmForSleep = 0;
    OS_WakeupThreadDirect(thread);
}

OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback) {
    u32 enabled;
    OSSwitchThreadCallback previous;

    enabled = OS_DisableInterrupts();
    previous = data_0216ff5c.mSwitchCallback;
    data_0216ff5c.mSwitchCallback = callback;
    OS_RestoreInterrupts(enabled);
    return previous;
}

// Thread function of the idle thread: enables interrupts, then halts in an endless loop.
void OSi_IdleThreadProc(void *arg) {
    OS_EnableInterrupts();
    for (;;) {
        OS_Halt();
    }
}

// Raises the scheduler disable count and returns its previous value.
u32 OS_DisableScheduler(void) {
    u32 enabled;
    u32 count;

    enabled = OS_DisableInterrupts();
    if (data_0216ff48 < 0xffffffff) {
        count = data_0216ff48;
        data_0216ff48 = count + 1;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Lowers the scheduler disable count when it is not 0 and returns its previous value.
u32 OS_EnableScheduler(void) {
    u32 enabled;
    u32 count;

    enabled = OS_DisableInterrupts();
    count = 0;
    if (data_0216ff48 != 0) {
        count = data_0216ff48;
        data_0216ff48 = count - 1;
    }
    OS_RestoreInterrupts(enabled);
    return count;
}

// Stores dtor in OSThread.mDestructor.
void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor dtor) {
    thread->mDestructor = dtor;
}

// Returns whether OS_InitThread has run.
u32 OS_IsThreadAvailable(void) {
    return data_0216ff58;
}
