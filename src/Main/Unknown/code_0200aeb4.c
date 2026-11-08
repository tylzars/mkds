#include "Main/Unknown/code_0200aeb4.h"

#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200b1b0.h"

#pragma thumb on

u32 func_0200b15c(u32 entryIndex, ScanBlock *scanBlock, u16 c, u16 d, u32 e, u32 f) {
    u32 bit8;
    u32 bit4;
    if (func_0200b1b0(entryIndex, (struct Unk0217aa00_24 *) scanBlock) == 0) {
        return 0;
    }
    scanBlock->mUnk_3c = 0x10;
    scanBlock->mUnk_4a = 0;
    scanBlock->mUnk_4c = c;
    scanBlock->mUnk_4e = d;
    bit8 = 0;
    if (f != 0) {
        bit8 = 8;
    }
    if (e != 0) {
        bit4 = 4;
    } else {
        bit4 = 0;
    }
    scanBlock->mUnk_4b = bit4 | bit8 | 1;
    return 1;
}

void RunWorkerTasks(void *argument) {
    WorkerQueue *workerQueue;
    WorkerTask *task;
    u32 v2;
    u32 savedInterrupts;
    void (*doneFunction)(WorkerTask *);
    u32 currentPriority;
    u32 priorityWhenEmpty;
    workerQueue = argument;
    priorityWhenEmpty = 0;
    for (;;) {
        v2 = OS_DisableInterrupts();
        while (workerQueue->mFirstTask == NULL) {
            OS_SetThreadPriority(&workerQueue->mThread, priorityWhenEmpty);
            OS_SleepThread(NULL);
        }
        task = workerQueue->mFirstTask;
        workerQueue->mFirstTask = workerQueue->mFirstTask->mNext;
        OS_SetThreadPriority(&workerQueue->mThread, task->mPriority);
        OS_RestoreInterrupts(v2);
        if (task->mRun != NULL) {
            ((void (*)(WorkerTask *)) task->mRun)(task);
        }
        savedInterrupts = OS_DisableInterrupts();
        doneFunction = (void (*)(WorkerTask *)) task->mDone;
        currentPriority = OS_GetThreadPriority(&workerQueue->mThread);
        if (workerQueue->mFirstTask == NULL) {
            v2 = priorityWhenEmpty;
        } else if (currentPriority < workerQueue->mFirstTask->mPriority) {
            v2 = workerQueue->mFirstTask->mPriority;
        } else {
            v2 = currentPriority;
        }
        if (v2 != currentPriority) {
            OS_SetThreadPriority(&workerQueue->mThread, v2);
        }
        task->mNext = NULL;
        task->mInUse = 0;
        if (doneFunction != NULL) {
            doneFunction(task);
        }
        if (task == &workerQueue->mStopTask) {
            break;
        }
        OS_RestoreInterrupts(savedInterrupts);
    }
    OS_ExitThread();
}

void StartWorkerThread(WorkerQueue *workerQueue, u32 totalSize) {
    u32 savedInterrupts;
    u32 stackSize;
    savedInterrupts = OS_DisableInterrupts();
    if (gWorkerQueue == NULL) {
        gWorkerQueue = workerQueue;
        func_0200b00c(&workerQueue->mStopTask);
        workerQueue->mFirstTask = NULL;
        stackSize = (totalSize - 0xe4) & ~3;
        OS_CreateThread(&workerQueue->mThread, RunWorkerTasks, workerQueue, (u8 *) workerQueue + 0xe4 + stackSize,
                        stackSize, 0);
        OS_WakeupThreadDirect(&workerQueue->mThread);
    }
    OS_RestoreInterrupts(savedInterrupts);
}

#pragma thumb off

#pragma thumb on

u32 IsWorkerActive(void) {
    if (gWorkerQueue != NULL) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_0200b00c(void *arg0) {
    void *value0 = arg0;
    u32 fillValue;
    u32 byteCount;
    u32 value3;
    fillValue = 0u;
    byteCount = 32u;
    MI_CpuFill8(value0, fillValue, byteCount);
}
#pragma thumb off

#pragma thumb on

u32 IsWorkerTaskInUse(WorkerTask *task) {
    if (task->mInUse != 0) {
        return 1;
    }
    return 0;
}

void QueueWorkerTask(WorkerTask *task, void *run, void *done, u32 priority) {
    WorkerQueue *workerQueue;
    u32 threadPriority;
    u32 savedInterrupts;
    WorkerTask *previous;
    WorkerTask *next;
    workerQueue = gWorkerQueue;
    if (IsWorkerActive() == 0) {
        OS_Terminate();
    }
    if (task->mInUse != 0) {
        OS_Terminate();
    }
    if (priority > 31) {
        threadPriority = OS_GetThreadPriority(&workerQueue->mThread);
        if (priority == 32) {
            if (threadPriority != 0) {
                priority = threadPriority - 1;
            } else {
                priority = 0;
            }
        } else if (priority == 33) {
            if (threadPriority < 31) {
                priority = threadPriority + 1;
            } else {
                priority = 31;
            }
        } else if (priority == 34) {
            priority = threadPriority;
        } else {
            priority = 31;
        }
    }
    savedInterrupts = OS_DisableInterrupts();
    task->mInUse = 1;
    task->mPriority = priority;
    task->mRun = run;
    task->mDone = done;
    if (workerQueue->mFirstTask == NULL) {
        if (task == &workerQueue->mStopTask) {
            gWorkerQueue = NULL;
        }
        workerQueue->mFirstTask = task;
        OS_WakeupThreadDirect(&workerQueue->mThread);
    } else {
        previous = workerQueue->mFirstTask;
        if (task == &workerQueue->mStopTask) {
            if (previous->mNext != NULL) {
                do {
                    previous = previous->mNext;
                } while (previous->mNext != NULL);
            }
            previous->mNext = task;
            gWorkerQueue = NULL;
        } else if (previous->mPriority > priority) {
            workerQueue->mFirstTask = task;
            task->mNext = previous;
        } else {
            while ((next = previous->mNext) != NULL && next->mPriority <= priority) {
                previous = next;
            }
            task->mNext = next;
            previous->mNext = task;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
}

#pragma thumb off

#pragma thumb on

void RequestWorkerStop(void *done) {
    u32 savedInterrupts;
    int workerActive;
    savedInterrupts = ((s64) OS_DisableInterrupts());
    workerActive = IsWorkerActive();
    if (workerActive != 0) {
        QueueWorkerTask(&gWorkerQueue->mStopTask, NULL, done, 0);
    }
    OS_RestoreInterrupts(savedInterrupts);
}

#pragma thumb off
