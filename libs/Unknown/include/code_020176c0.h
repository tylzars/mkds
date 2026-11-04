#pragma once

#include "types.h"
#include "code_02017550.h" // Unk02017584
#include "code_02017e70.h" // ExpHeapBlock
#include "code_02017ea0.h" // ExpHeapBlockList

// Two ExpHeapBlockList followed by two halfwords.
typedef struct Unk020179d4 {
    /* 00 */ ExpHeapBlockList mFreeList;
    /* 08 */ ExpHeapBlockList mUsedList;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk020179d4;

// Unk02017584 followed by an Unk020179d4.
typedef struct Unk020176c0 {
    /* 00 */ Unk02017584 mUnk_00;
    /* 24 */ Unk020179d4 mUnk_24;
} Unk020176c0;

u32 ExpHeapGetMaxAllocSize(Unk020176c0 *a, u32 b);
u32 ExpHeapGetTotalFreeSize(Unk020176c0 *a);
void ExpHeapFree(Unk020176c0 *a, void *b);
u32 ExpHeapResizeBlock(Unk020176c0 *a, void *b, u32 c);
void *ExpHeapAlloc(Unk020176c0 *a, u32 b, s32 c);
// Only unlinks the heap.
void ExpHeapDestroy(Unk02017584 *a);
Unk020176c0 *ExpHeapCreate(void *a, u32 b, u16 c);
u32 ExpHeapAddFreeRange(Unk020179d4 *a, ExpHeapRange *b);
// ExpHeapAllocBack and ExpHeapAllocFront take the first block that fits: bit 0 of mUnk_12 is only ever cleared
// (code_020176c0.c), so the best-fit branch never runs.
void *ExpHeapAllocBack(Unk020176c0 *a, u32 b, u32 c);
void *ExpHeapAllocFront(Unk020176c0 *a, u32 b, u32 c);
void *ExpHeapAllocFromFreeBlock(Unk020179d4 *a, ExpHeapBlock *b, void *c, u32 d, u16 e);
Unk020176c0 *ExpHeapInit(Unk020176c0 *a, u32 b, u16 c);
