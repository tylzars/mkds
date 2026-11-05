#pragma once

#include "types.h"

// 16 bytes: an index into data_02152c54 and three words passed to the function it selects.
typedef struct CallQueueEntry {
    /* 00 */ u32 mFuncIndex;
    /* 04 */ const void *mSource;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mSize;
} CallQueueEntry;

typedef struct CallQueueEntry CallQueueEntry;

// Object at data_02173220: a pointer to an array of CallQueueEntry, its length at 04, two indices at 08 and 0a that
// CallQueueNextIndex advances modulo the length, and a count at 0c (CallQueueIsFull compares it with the length,
// CallQueueIsEmpty tests it for zero).
typedef struct CallQueue {
    /* 00 */ CallQueueEntry *mEntries;
    /* 04 */ u32 mCapacity;
    /* 08 */ u16 mHeadIndex;
    /* 0a */ u16 mTailIndex;
    /* 0c */ u16 mCount;
    /* 10 */ u32 mQueuedSize;
} CallQueue;

void CallQueueRunEntry(CallQueueEntry *p);
void func_0201667c(u32 arg0, u32 arg1, u32 arg2);
void func_02016688(u32 arg0, u32 arg1, u32 arg2);
void func_02016694(const void *a, u32 b, u32 c);
void func_020166c4(const void *a, u32 b, u32 c);
void func_020166f4(u32 arg0, u32 arg1, u32 arg2);
void func_02016700(u32 arg0, u32 arg1, u32 arg2);
void func_0201670c(const void *a, u32 b, u32 c);
void func_02016718(u32 arg0, u32 arg1, u32 arg2);
void func_02016724(const void *a, u32 b, u32 c);
void func_02016730(u32 arg0, u32 arg1, u32 arg2);
void func_0201673c(u32 arg0, u32 arg1, u32 arg2);
void func_02016748(const void *a, u32 b, u32 c);
void func_02016754(u32 arg0, u32 arg1, u32 arg2);
void func_02016760(u32 arg0, u32 arg1, u32 arg2);
void func_0201676c(u32 arg0, u32 arg1, u32 arg2);
void func_02016778(const void *a, u32 b, u32 c);
void func_02016784(u32 arg0, u32 arg1, u32 arg2);
void func_02016790(u32 arg0, u32 arg1, u32 arg2);
void func_0201679c(const void *a, u32 b, u32 c);
void func_020167cc(const void *a, u32 b, u32 c);
void func_020167fc(const void *a, u32 b, u32 c);
void func_02016808(u32 arg0, u32 arg1, u32 arg2);
void func_02016814(const void *a, u32 b, u32 c);
void func_02016820(u32 arg0, u32 arg1, u32 arg2);
void func_0201682c(const void *a, u32 b, u32 c);
void func_02016838(u32 arg0, u32 arg1, u32 arg2);
void func_02016844(const void *a, u32 b, u32 c);
void func_02016850(const void *a, u32 b, u32 c);
void func_0201685c(const void *a, u32 b, u32 c);
void func_02016868(const void *a, u32 b, u32 c);
void func_02016874(const void *a, u32 b, u32 c);
void func_02016880(const void *a, u32 b, u32 c);
void func_0201688c(const void *a, u32 b, u32 c);
void func_020168bc(const void *a, u32 b, u32 c);
void func_020168ec(const void *a, u32 b, u32 c);
void func_0201691c(const void *a, u32 b, u32 c);
s32 CallQueueIsEmpty(CallQueue *p);
s32 CallQueueIsFull(CallQueue *p);
u16 CallQueueNextIndex(CallQueue *p, u32 v);
