#pragma once

#include "types.h"

struct Thread;

// Two Thread pointers; ThreadQueueInsert and ThreadQueueRemoveFront link the objects through their mQueueNext and
// mQueuePrev. ThreadQueueSetAllRunnable and ThreadWait take it.
typedef struct ThreadQueue {
    /* 00 */ struct Thread *mHead;
    /* 04 */ struct Thread *mTail;
} ThreadQueue;

// 0x18 bytes; OS_InitMutex clears mQueue to mLockCount. OSi_EnqueueTail and OSi_DequeueItem link it through
// mNext and mPrev into the ThreadLockList at mLockList of a Thread.
typedef struct OSMutex {
    /* 00 */ ThreadQueue mQueue;
    /* 08 */ struct Thread *mHolder; // set by OS_TryLockMutex and OS_LockMutex
    /* 0c */ u32 mLockCount; // raised by OS_TryLockMutex and OS_LockMutex, lowered by OS_UnlockMutex
    /* 10 */ struct OSMutex *mNext;
    /* 14 */ struct OSMutex *mPrev;
} OSMutex;

typedef struct ThreadLockList {
    /* 00 */ OSMutex *mHead;
    /* 04 */ OSMutex *mTail;
} ThreadLockList;

// Set up by OS_InitMessageQueue. OS_SendMessage stores a word at mBuffer[(mHeadIndex + mCount) % mCapacity] and raises
// mCount; OS_ReceiveMessage reads mBuffer[mHeadIndex], advances mHeadIndex modulo mCapacity and lowers mCount. Each
// calls ThreadWait on one of mFullWaiters and mEmptyWaiters and ThreadQueueSetAllRunnable on the other.
typedef void *OSMessage;

typedef struct OSMessageQueue {
    /* 00 */ ThreadQueue mFullWaiters;
    /* 08 */ ThreadQueue mEmptyWaiters;
    /* 10 */ OSMessage *mBuffer;
    /* 14 */ s32 mCapacity;
    /* 18 */ s32 mHeadIndex;
    /* 1c */ s32 mCount;
} OSMessageQueue;

// Value OS_GetConsoleType builds on its first call; 0xffffffff until then.
extern u32 gConsoleType;

u32 func_0200e77c(void);
// Gets an id, then repeats under IrqDisable until it has either seen that the holder of the lock word at 0x027fffe8
// has bit 0x40 set or taken the lock: compares the words at 0x08000000 and 0x08000004 with 0x544e494e and 0x4f444e45
// (the text NINTENDO) and returns 0x01000000 when both match, else 0x02000000. Releases the lock again when it took
// it.
u32 ReadCartridgeMarkerBits(void);
// On the first call builds the value from ReadCartridgeMarkerBits (bit 24 or bit 25), adds 0x10000000 when
// OS_IsRunOnEmulator is nonzero, else 0x40000000 when func_0200e77c is nonzero, else 0x20000000 when bit 24 is set,
// else 0x80000000, ors in the halfword at 0x027ffffa and stores it in gConsoleType. Returns the stored value.
u32 OS_GetConsoleType(void);
// Returns 0. OS_GetConsoleType tests it first (nonzero adds 0x10000000); func_02020eb0 reads the register at 0x04fff200
// only when it is nonzero; func_02039cbc and func_0204b9ac skip work when it is nonzero.
u32 OS_IsRunOnEmulator(void);
BOOL OS_ReadMessage(OSMessageQueue *queue, OSMessage *message, s32 flags);
BOOL OS_JamMessage(OSMessageQueue *queue, OSMessage message, s32 flags);
BOOL OS_ReceiveMessage(OSMessageQueue *queue, OSMessage *message, s32 flags);
BOOL OS_SendMessage(OSMessageQueue *queue, OSMessage message, s32 flags);
void OS_InitMessageQueue(OSMessageQueue *queue, OSMessage *messages, s32 count);
void OSi_DequeueItem(struct Thread *thread, OSMutex *mutex);
void OSi_EnqueueTail(struct Thread *thread, OSMutex *mutex);
BOOL OS_TryLockMutex(OSMutex *mutex);
void OSi_UnlockAllMutex(struct Thread *thread);
void OS_UnlockMutex(OSMutex *mutex);
void OS_LockMutex(OSMutex *mutex);
