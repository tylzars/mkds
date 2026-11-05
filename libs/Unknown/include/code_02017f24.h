#pragma once

#include "types.h"
#include "code_02017550.h" // Unk02017584

// Entry of 16 bytes, linked through mNext.
typedef struct Unk02017f58 {
    /* 00 */ u32 mKey;
    /* 04 */ u32 mFrontAddr;
    /* 08 */ u32 mBackAddr;
    /* 0c */ struct Unk02017f58 *mNext;
} Unk02017f58;

// Two addresses that FrmHeapAllocBack and FrmHeapAllocFront move towards each other, and the entries of an Unk02017f58
// chain.
typedef struct Unk02018174 {
    /* 00 */ u32 mFrontAddr;
    /* 04 */ u32 mBackAddr;
    /* 08 */ Unk02017f58 *mSavedList;
} Unk02018174;

// Unk02017584 followed by an Unk02018174.
typedef struct Unk02017f24 {
    /* 00 */ Unk02017584 mUnk_00;
    /* 24 */ Unk02018174 mUnk_24;
} Unk02017f24;

u32 FrmHeapShrink(Unk02017f24 *a);
u32 FrmHeapRestoreFrontBack(Unk02017f24 *a, u32 b);
u32 FrmHeapSaveFrontBack(Unk02017f24 *a, u32 b);
u32 FrmHeapGetMaxAllocSize(Unk02017f24 *a, u32 b);
void FrmHeapFree(Unk02017f24 *a, u32 b);
void *FrmHeapAlloc(Unk02017f24 *a, u32 b, s32 c);
// Only unlinks the heap.
void FrmHeapDestroy(Unk02017584 *a);
Unk02017f24 *FrmHeapCreate(void *a, u32 b, u16 c);
void FrmHeapFreeBack(Unk02017f24 *a);
// Also clears the saved list.
void FrmHeapFreeFront(Unk02017f24 *a);
u32 FrmHeapAllocBack(Unk02018174 *a, u32 b, u32 c);
void *FrmHeapAllocFront(Unk02018174 *a, u32 b, u32 c);
Unk02017f24 *FrmHeapInit(Unk02017f24 *a, u32 b, u16 c);
