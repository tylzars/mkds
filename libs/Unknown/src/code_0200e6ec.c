#include "code_0200e6ec.h"

#include "code_02146bb8.h"
#include "code_0200cd1c.h"
#include "code_0200e77c.h"
#include "code_0200cdc0.h"
#include "code_0200ce60.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200edc0.h"

// Clears OSMutex.mQueue, OSMutex.mHolder and OSMutex.mLockCount.
void OS_InitMutex(OSMutex *mutex) {
    mutex->mQueue.mTail = 0;
    mutex->mQueue.mHead = mutex->mQueue.mTail;
    mutex->mHolder = 0;
    mutex->mLockCount = 0;
}

// Takes the mutex for the current thread, or raises OSMutex.mLockCount when it already holds it. Another holder makes
// the thread sleep on OSMutex.mQueue until the mutex is free.
void OS_LockMutex(OSMutex *mutex) {
    u32 enabled;
    OSThread *current;

    enabled = IrqDisable();
    current = data_0216ff5c.mCurrentThread;
    while (1) {
        if (mutex->mHolder == 0) {
            mutex->mHolder = current;
            mutex->mLockCount = mutex->mLockCount + 1;
            OSi_EnqueueTail(current, mutex);
            break;
        } else if (mutex->mHolder == current) {
            mutex->mLockCount = mutex->mLockCount + 1;
            break;
        } else {
            current->mMutex = mutex;
            OS_SleepThread(&mutex->mQueue);
            current->mMutex = 0;
        }
    }
    IrqRestore(enabled);
}

// Lowers OSMutex.mLockCount for the holding thread; at 0 the mutex is unlinked, released and its waiters wake up.
void OS_UnlockMutex(OSMutex *mutex) {
    u32 enabled;
    OSThread *current;

    enabled = IrqDisable();
    current = data_0216ff5c.mCurrentThread;
    if (mutex->mHolder == current) {
        mutex->mLockCount = mutex->mLockCount - 1;
        if (mutex->mLockCount == 0) {
            OSi_DequeueItem(current, mutex);
            mutex->mHolder = 0;
            OS_WakeupThread(&mutex->mQueue);
        }
    }
    IrqRestore(enabled);
}

// Releases every mutex in the mutex list of thread and wakes the threads waiting on them.
void OSi_UnlockAllMutex(struct OSThread *thread) {
    OSMutex *mutex;

    if (thread->mMutexQueue.mHead == 0) {
        return;
    }
    do {
        mutex = OSi_RemoveMutexLinkFromQueue(&thread->mMutexQueue);
        mutex->mLockCount = 0;
        mutex->mHolder = 0;
        OS_WakeupThread(&mutex->mQueue);
    } while (thread->mMutexQueue.mHead != 0);
}

// Takes the mutex for the current thread like OS_LockMutex but returns 0 instead of sleeping; returns 1 when the
// thread holds it.
BOOL OS_TryLockMutex(OSMutex *mutex) {
    u32 enabled;
    BOOL locked;
    OSThread *current;

    enabled = IrqDisable();
    current = data_0216ff5c.mCurrentThread;
    if (mutex->mHolder == 0) {
        mutex->mHolder = current;
        mutex->mLockCount = mutex->mLockCount + 1;
        OSi_EnqueueTail(current, mutex);
        locked = 1;
    } else if (mutex->mHolder == current) {
        mutex->mLockCount = mutex->mLockCount + 1;
        locked = 1;
    } else {
        locked = 0;
    }
    IrqRestore(enabled);
    return locked;
}

// Links mutex at the tail of the mutex list of thread.
void OSi_EnqueueTail(struct OSThread *thread, OSMutex *mutex) {
    OSMutex *tail;

    tail = thread->mMutexQueue.mTail;
    if (tail == 0) {
        thread->mMutexQueue.mHead = mutex;
    } else {
        tail->mNext = mutex;
    }
    mutex->mPrev = tail;
    mutex->mNext = 0;
    thread->mMutexQueue.mTail = mutex;
}

// Takes mutex out of the mutex list of thread.
void OSi_DequeueItem(struct OSThread *thread, OSMutex *mutex) {
    OSMutex *prev;
    OSMutex *next;

    next = mutex->mNext;
    prev = mutex->mPrev;
    if (next == 0) {
        thread->mMutexQueue.mTail = prev;
    } else {
        next->mPrev = prev;
    }
    if (prev == 0) {
        thread->mMutexQueue.mHead = next;
    } else {
        prev->mNext = next;
    }
}

// Clears both thread queues, sets the message array and its length, and empties the queue.
void OS_InitMessageQueue(OSMessageQueue *queue, OSMessage *messages, s32 count) {
    queue->mFullWaiters.mTail = 0;
    queue->mFullWaiters.mHead = queue->mFullWaiters.mTail;
    queue->mEmptyWaiters.mTail = 0;
    queue->mEmptyWaiters.mHead = queue->mEmptyWaiters.mTail;
    queue->mBuffer = messages;
    queue->mCapacity = count;
    queue->mHeadIndex = 0;
    queue->mCount = 0;
}

// Appends message at the end of the queue and wakes the receivers. When it is full, waits for room if bit 0 of flags is
// set, else returns 0.
BOOL OS_SendMessage(OSMessageQueue *queue, OSMessage message, s32 flags) {
    u32 enabled;

    enabled = IrqDisable();
    if (queue->mCapacity <= queue->mCount) {
        do {
            if ((flags & 1) == 0) {
                IrqRestore(enabled);
                return 0;
            }
            OS_SleepThread(&queue->mFullWaiters);
        } while (queue->mCapacity <= queue->mCount);
    }
    queue->mBuffer[(queue->mHeadIndex + queue->mCount) % queue->mCapacity] = message;
    queue->mCount = queue->mCount + 1;
    OS_WakeupThread(&queue->mEmptyWaiters);
    IrqRestore(enabled);
    return 1;
}

// Removes the first message, stores it to *message when message is not 0 and wakes the senders. When the queue is
// empty, waits for a message if bit 0 of flags is set, else returns 0.
BOOL OS_ReceiveMessage(OSMessageQueue *queue, OSMessage *message, s32 flags) {
    u32 enabled;

    enabled = IrqDisable();
    if (queue->mCount == 0) {
        do {
            if ((flags & 1) == 0) {
                IrqRestore(enabled);
                return 0;
            }
            OS_SleepThread(&queue->mEmptyWaiters);
        } while (queue->mCount == 0);
    }
    if (message != 0) {
        *message = queue->mBuffer[queue->mHeadIndex];
    }
    queue->mHeadIndex = (queue->mHeadIndex + 1) % queue->mCapacity;
    queue->mCount = queue->mCount - 1;
    OS_WakeupThread(&queue->mFullWaiters);
    IrqRestore(enabled);
    return 1;
}

// Puts message at the front of the queue and wakes the receivers. When it is full, waits for room if bit 0 of flags is
// set, else returns 0.
BOOL OS_JamMessage(OSMessageQueue *queue, OSMessage message, s32 flags) {
    u32 enabled;

    enabled = IrqDisable();
    if (queue->mCapacity <= queue->mCount) {
        do {
            if ((flags & 1) == 0) {
                IrqRestore(enabled);
                return 0;
            }
            OS_SleepThread(&queue->mFullWaiters);
        } while (queue->mCapacity <= queue->mCount);
    }
    queue->mHeadIndex = (queue->mHeadIndex + queue->mCapacity - 1) % queue->mCapacity;
    queue->mBuffer[queue->mHeadIndex] = message;
    queue->mCount = queue->mCount + 1;
    OS_WakeupThread(&queue->mEmptyWaiters);
    IrqRestore(enabled);
    return 1;
}

// Stores the first message to *message when message is not 0 and leaves it in the queue. When the queue is empty, waits
// for a message if bit 0 of flags is set, else returns 0.
BOOL OS_ReadMessage(OSMessageQueue *queue, OSMessage *message, s32 flags) {
    u32 enabled;

    enabled = IrqDisable();
    if (queue->mCount == 0) {
        do {
            if ((flags & 1) == 0) {
                IrqRestore(enabled);
                return 0;
            }
            OS_SleepThread(&queue->mEmptyWaiters);
        } while (queue->mCount == 0);
    }
    if (message != 0) {
        *message = queue->mBuffer[queue->mHeadIndex];
    }
    IrqRestore(enabled);
    return 1;
}

u32 gConsoleType = 0xffffffff;

u32 OS_IsRunOnEmulator(void) {
    return 0;
}

// On the first call stores ReadCartridgeMarkerBits's result with one bit added in the top bits (0x10000000 when
// OS_IsRunOnEmulator is nonzero, else 0x40000000 when func_0200e77c is nonzero, else 0x20000000 when bit 24 of the
// result is set, else 0x80000000), or-ed with a halfword read from a fixed address. The stored value is -1 until
// then.
u32 OS_GetConsoleType(void) {
    u32 type;

    if (gConsoleType == 0xffffffff) {
        type = ReadCartridgeMarkerBits();
        if (OS_IsRunOnEmulator() != 0) {
            type |= 0x10000000;
        } else if (func_0200e77c() != 0) {
            type |= 0x40000000;
        } else if (type & 0x1000000) {
            type |= 0x20000000;
        } else {
            type |= 0x80000000;
        }
        gConsoleType = type | *(u16 *) 0x27ffffa;
    }
    return gConsoleType;
}

// Repeats, each pass between IrqDisable and IrqRestore, until OS_UnlockCartridge has been called (it is when
// OS_TryLockCartridge returns 0). The result has bit 24 set when two words at fixed addresses are 0x544e494e and
// 0x4f444e45, else bit 25.
u32 ReadCartridgeMarkerBits(void) {
    u32 a;
    s32 d;
    u16 h;
    s32 v;
    u32 s;

    d = 0;
    h = OS_GetLockID();
    a = 0;
    do {
        v = -1;
        s = IrqDisable();
        if ((OS_ReadOwnerOfLockWord((OSLockWord *) 0x27fffe8) & 0x40) != 0 || (v = OS_TryLockCartridge(h)) == 0) {
            if (*(u32 *) 0x8000000 == 0x544e494e && *(u32 *) 0x8000004 == 0x4f444e45) {
                a = 0x1000000;
            } else {
                a = 0x2000000;
            }
            if (v == 0) {
                OS_UnlockCartridge(h);
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

// clang-format off
// Calls DivSqrtRegistersSave with the address of mUnk_48, stores the status register and the registers (r0 = 1 saved) into
// the words from 0, the banked sp of mode 0xd3 at 0x44 and the address of the return point at 0x3c, and returns 0.
asm BOOL OS_SaveContext(OSThread *t) {
    stmdb sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =DivSqrtRegistersSave
    blx r1
    ldmia sp!, {r0, lr}
    add r1, r0, #0x0
    mrs r2, cpsr
    str r2, [r1], #0x4
    mov r0, #0xd3
    msr cpsr_c, r0
    str sp, [r1, #0x40]
    msr cpsr_c, r2
    mov r0, #0x1
    stmia r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}
    add r0, pc, #0x8
    str r0, [r1, #0x3c]
    mov r0, #0x0
    bx lr
}

// Calls DivSqrtRegistersRestore with the address of mUnk_48, then switches to mode 0xd3 and restores the registers and the
// status word saved by OS_SaveContext.
asm void OS_LoadContext(OSThread *t) {
    stmdb sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =DivSqrtRegistersRestore
    blx r1
    ldmia sp!, {r0, lr}
    mrs r1, cpsr
    bic r1, r1, #0x1f
    orr r1, r1, #0xd3
    msr cpsr_c, r1
    ldr r1, [r0], #0x4
    msr spsr_fsxc, r1
    ldr sp, [r0, #0x40]
    ldr lr, [r0, #0x3c]
    ldmia r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    mov r0, r0
    subs pc, lr, #0x4
}
// clang-format on
