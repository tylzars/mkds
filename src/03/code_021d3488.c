#include "03/code_021d3488.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d1d60.h"
#include "03/code_021d3000.h"

#include "03/code_021d27d8.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "03/code_021d2e68.h"
#include "code_0200c914.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d2eb8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2ecc.h"
#include "03/unk_021d6000.h"

void InitTasks(void) {
    s32 i;
    u8 *countPtr;

    gTaskLists = AllocExpHeapBlock(0x78, 4);
    i = 0;
    countPtr = data_ov003_021d67f0;
    do {
        gTaskLists[i].mCapacity = *countPtr;
        gTaskLists[i].mEntryStorage = AllocExpHeapBlock(*countPtr * 0x14, 4);
        gTaskLists[i].mFreeEntries = CreateFilledPointerStack(*countPtr, gTaskLists[i].mEntryStorage, 0x14);
        gTaskLists[i].mResource = CreatePointerStack(*countPtr);
        gTaskLists[i].mList = CreateNodeList();
        gTaskLists[i].mListStart.mPriority = 0;
        gTaskLists[i].mListEnd.mPriority = 0xff;
        func_ov003_021d2e50(gTaskLists[i].mList, &gTaskLists[i].mListStart);
        func_ov003_021d2e5c(gTaskLists[i].mList, &gTaskLists[i].mListEnd);
        countPtr++;
        i++;
    } while (i < 2);
}

void ReleaseTasks(void) {
    int listIndex;
    listIndex = 0;
    do {
        func_ov003_021d2eb8(gTaskLists[listIndex].mList);
        func_ov003_021d1d4c(gTaskLists[listIndex].mFreeEntries);
        listIndex = listIndex + 1;
    } while (2 > listIndex);
    FreeExpHeapBlockAndClearPointer(&gTaskLists);
}

void RunTasksAndRemoveRequested(int listIndex) {
    TaskEntry *entry;
    s32 removedCount;
    u32 queuedEntry;

    entry = gTaskLists[listIndex].mListStart.mNext;
    if (entry != &gTaskLists[listIndex].mListEnd) {
        do {
            entry->mCallback(entry, entry->mArg);
            entry = entry->mNext;
        } while (entry != &gTaskLists[listIndex].mListEnd);
    }
    removedCount = 0;
    if (gTaskLists[listIndex].mCapacity > 0) {
        do {
            queuedEntry = (u32) PopPointerStack(gTaskLists[listIndex].mResource);
            if (queuedEntry == 0) {
                break;
            }
            RemoveTaskEntry(listIndex, queuedEntry);
            removedCount++;
        } while (removedCount < gTaskLists[listIndex].mCapacity);
    }
}

u32 AddTask(u32 listIndex, void *function, void *arg, u32 priority) {
    return (u32) AddTaskEx(listIndex, (void (*)(TaskEntry *, u32))(function), (u32) arg, priority, 0x0u);
}

TaskEntry *AddTaskEx(u32 listIndex, void (*function)(TaskEntry *listIndex, u32 function), u32 arg, u32 priority,
                     u8 freesArg) {
    TaskEntry *entry;
    TaskEntry *following;
    u32 savedIrqMask;

    entry = PopPointerStack(gTaskLists[listIndex].mFreeEntries);
    entry->mCallback = function;
    entry->mArg = arg;
    entry->mPriority = priority;
    entry->mFreesArg = freesArg;
    savedIrqMask = OS_DisableIrqMask(1);
    following = gTaskLists[listIndex].mListStart.mNext;
    while (1) {
        if (priority < following->mPriority) {
            AddNodeBefore((u32) following, (u32) entry);
            break;
        }
        following = following->mNext;
    }
    OS_EnableIrqMask(savedIrqMask);
    return entry;
}

void SetTaskCallback(TaskEntry *taskEntry, UnkFunc *function) {
    taskEntry->mCallback = function;
}

void RequestTaskRemoval(u32 listIndex, u32 entry) {
    PushPointerStack(gTaskLists[listIndex].mResource, (void *) entry);
}

void RemoveTaskEntryWrapper(u32 listIndex, u32 entry) {
    u32 listIndexCopy = listIndex;
    u32 entryCopy = entry;
    u32 unused;
    RemoveTaskEntry(listIndexCopy, entryCopy);
}

void RemoveTaskEntry(int listIndex, int entry) {
    if (*OFFSET_PTR(u8, entry, 0x11) != 0) {
        FreeExpHeapBlockAndClearPointer(OFFSET_PTR(s32, entry, 0xc));
    }
    RemoveNodeFromList(entry);
    PushPointerStack(gTaskLists[listIndex].mFreeEntries, (void *) entry);
}
