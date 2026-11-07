#pragma once

#include "types.h"

// A function run with a heap of its own; mParent is the call that was running before it.
typedef struct HeapCall {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mFunc;
    /* 08 */ u32 mAfterFunc;
    /* 0c */ void *mHeap;
    /* 10 */ struct HeapCall *mParent;
} HeapCall;

void SetHeapCallFunc(HeapCall *call, u32 func);
void InitHeapCall(HeapCall *call, u32 func);
