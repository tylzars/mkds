#pragma once

#include "types.h"

typedef struct PointerStack PointerStack;

typedef struct TaskEntry {
    /* 00 */ struct TaskEntry *mPrev;
    /* 04 */ struct TaskEntry *mNext;
    /* 08 */ void (*mCallback)(struct TaskEntry *a, u32 b);
    /* 0c */ u32 mArg;
    /* 10 */ u8 mPriority;
    /* 11 */ u8 mFreesArg;
    /* 12 */ u8 mUnk_12[2];
} TaskEntry;

typedef struct TaskList {
    /* 00 */ PointerStack *mFreeEntries;
    /* 04 */ struct PointerStack *mResource;
    /* 08 */ void *mList;
    /* 0c */ TaskEntry mListStart;
    /* 20 */ TaskEntry mListEnd;
    /* 34 */ s32 mCapacity;
    /* 38 */ TaskEntry *mEntryStorage;
} TaskList;

void RemoveTaskEntry(int listIndex, int entry);
void RemoveTaskEntryWrapper(u32 listIndex, u32 entry);
void RequestTaskRemoval(u32 listIndex, u32 entry);
void SetTaskCallback(TaskEntry *taskEntry, UnkFunc *function);
TaskEntry *AddTaskEx(u32 listIndex, void (*function)(TaskEntry *listIndex, u32 function), u32 arg, u32 priority,
                     u8 freesArg);
unsigned int AddTask(unsigned int listIndex, void *function, void *arg, unsigned int priority);
void RunTasksAndRemoveRequested(int listIndex);
void ReleaseTasks(void);
void InitTasks(void);
