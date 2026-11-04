#pragma once

#include "types.h"
#include "code_02017e70.h" // ExpHeapBlock, ExpHeapRange

// First and last entries of a chain linked through mUnk_08 and mUnk_0c of ExpHeapBlock.
typedef struct ExpHeapBlockList {
    /* 00 */ ExpHeapBlock *mHead;
    /* 04 */ ExpHeapBlock *mTail;
} ExpHeapBlockList;

ExpHeapBlock *ExpHeapBlockListInsertAfter(ExpHeapBlockList *a, ExpHeapBlock *b, ExpHeapBlock *c);
ExpHeapBlock *ExpHeapBlockListRemove(ExpHeapBlockList *a, ExpHeapBlock *b);
void ExpHeapBlockGetRange(ExpHeapRange *a, ExpHeapBlock *b);
