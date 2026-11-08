#pragma once

#include "types.h"
#include "os_thread.h"

// 0x10-byte object QueueWorkerTask links by the bits above bit 0 of its member 4, in increasing order.
typedef struct WorkerTask {
    /* 00 */ struct WorkerTask *mNext;
    /* 04 */ union {
        u32 mUnk_04;
        struct {
            u32 mInUse : 1;
            u32 mPriority : 31;
        };
    };
    /* 08 */ void *mRun;
    /* 0c */ void *mDone;
} WorkerTask;

// What gWorkerQueue points to: the OSThread, then the first and the last object of the list.
typedef struct WorkerQueue {
    /* 00 */ OSThread mThread;
    /* b8 */ u8 mUnk_b8[8];
    /* c0 */ WorkerTask *volatile mFirstTask;
    /* c4 */ WorkerTask mStopTask;
} WorkerQueue;

typedef struct ScanBlock ScanBlock;
typedef struct WorkerQueue WorkerQueue;

void RequestWorkerStop(void *done);
void QueueWorkerTask(WorkerTask *task, void *run, void *done, u32 priority);
u32 IsWorkerTaskInUse(WorkerTask *task);
void func_0200b00c(void *arg0);
u32 IsWorkerActive(void);
void StartWorkerThread(WorkerQueue *workerQueue, u32 totalSize);
void RunWorkerTasks(void *argument);
u32 func_0200b15c(u32 entryIndex, ScanBlock *scanBlock, u16 c, u16 d, u32 e, u32 f);
