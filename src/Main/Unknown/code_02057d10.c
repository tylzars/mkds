#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_020364e0.h"
#include "os_irqHandler.h"
#include "os_thread.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

void RunQueuedThreadFunctions(void *threadArgument) {
    for (;;) {
        if (gThreadFunctionQueue->mRunRequested != 0) {
            void (*queuedFunction)(void) = func_02057f8c(gThreadFunctionQueue);
            if (queuedFunction == NULL) {
                gThreadFunctionQueue->mRunRequested = 0;
            } else {
                queuedFunction();
            }
        }
        OS_Sleep(2);
    }
}

u32 QueueThreadFunction(void (*function)(void)) {
    s32 checkedCount;
    s32 searchIndex;
    ThreadFunctionQueue *queue = gThreadFunctionQueue;
    u8 slotIndex;
    void (*slotFunction)(void);
    if (queue->mRunRequested != 0) {
        return 0;
    }
    searchIndex = queue->mNewestIndex;
    checkedCount = 0;
    do {
        slotIndex = searchIndex % 10;
        slotFunction = queue->mFunctions[slotIndex];
        if (slotFunction == NULL) {
            break;
        }
        checkedCount++;
        searchIndex++;
    } while (checkedCount < 10);
    if (slotFunction != NULL) {
        return 0;
    }
    queue->mFunctions[slotIndex] = function;
    queue->mNewestIndex = slotIndex;
    return 1;
}

void WaitThreadFunctionsDone(void) {
    while (gThreadFunctionQueue->mRunRequested != 0) {
        OS_WaitIrq(1, 1);
    }
}

void InitLogoSceneCallback(void) {
    InitLogoScene(GetHeap(GetCurrentHeapCall()));
}

void ApplySavedSoundModeCallback(void) {
    ApplySavedSoundMode();
}

void WriteLogoSceneRegistersCallback(void) {
    WriteLogoSceneRegisters();
}

void UpdateLogoSceneCallback(void *sceneNumbers) {
    UpdateLogoScene(sceneNumbers);
}

s32 RunLogoScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gLogoSceneCallbacks;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}
