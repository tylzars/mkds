#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "os_thread.h"

void (*func_02057f8c(ThreadFunctionQueue *queue))(void) {
    void (**lastFilledSlot)(void) = NULL;
    void (*callback)(void) = NULL;
    s32 filledCount = 0;
    s32 slot;
    u8 startSlot = queue->mNewestIndex;
    do {
        slot = startSlot - filledCount;
        if (slot < 0) {
            slot += 10;
        }
        if (queue->mFunctions[slot] == NULL) {
            break;
        }
        filledCount++;
        lastFilledSlot = &queue->mFunctions[slot];
    } while (filledCount < 10);
    if (lastFilledSlot != NULL) {
        callback = *lastFilledSlot;
        *lastFilledSlot = NULL;
    }
    return callback;
}

void func_02057ed8(void *heap) {
    ThreadFunctionQueue *queue;
    s32 i;
    gThreadFunctionQueue = HeapAlloc(heap, 0xfc);
    gThreadFunctionQueue->mThreadStack = HeapAllocAligned(heap, 0x800, 0x20);
    OS_CreateThread(&gThreadFunctionQueue->mThread, RunQueuedThreadFunctions, NULL,
                    (u8 *) gThreadFunctionQueue->mThreadStack + 0x800, 0x800, 0x11);
    OS_WakeupThreadDirect(&gThreadFunctionQueue->mThread);
    gThreadFunctionQueue->mRunRequested = 0;
    queue = gThreadFunctionQueue;
    for (i = 0; i < 10; i++) {
        queue->mFunctions[i] = NULL;
    }
    queue->mNewestIndex = 0;
}
