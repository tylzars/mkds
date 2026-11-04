#pragma once

#include "types.h"

// List header of 12 bytes: first and last element, number of elements, and the offset of the links in an element.
typedef struct LinkedList {
    /* 00 */ void *mHead;
    /* 04 */ void *mTail;
    /* 08 */ u16 mCount;
    /* 0a */ u16 mLinkOffset;
} LinkedList;

// 16 bytes: mUnk_04 lists 20-byte elements whose links are at 0x0c (HeapStackInit sets that offset); HeapStackPushLevel
// adds an element and func_0212da1c clears it as a list with offset 0.
typedef struct HeapStack {
    /* 00 */ void *mHeap;
    /* 04 */ LinkedList mLevels;
} HeapStack;

// Block of 0x20 bytes before the memory HeapStackAlloc returns; an element (links at 0) of the list that starts each
// element of HeapStack. mUnk_0c is called with the memory after the block, mUnk_08, mUnk_10 and mUnk_14.
typedef struct Unk0212db7c {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ UnkFunc *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[8];
} Unk0212db7c;

// Position in the entries of an Unk02021968, set by func_02021bc8 and advanced by func_020219f0.
typedef struct Unk02021bc8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02021bc8;

// Record func_020219f0 writes.
typedef struct Unk020219f0 {
    /* 00 */ u8 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk020219f0;

// Entry of 8 bytes in the table at 0x18 of an Unk02021968: func_02021be8 clears the entries of a chain linked through
// mUnk_04, func_02021c34 and func_02021cd4 move entries between the chains of two objects.
typedef struct Unk02021be8 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
} Unk02021be8;

// Object with two tables of mUnk_38 words from 0x3c. func_02021968 and func_020219b0 read and write the first;
// func_0212de34 reads the second, whose words b and b + 1 bound a block (the last block ends at mUnk_08).
typedef struct Unk02021968 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ Unk02021be8 mUnk_18[4];
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c[1];
} Unk02021968;

void HeapStackRestore(HeapStack *a, s32 n);
s32 HeapStackSave(HeapStack *a);
void *HeapStackAlloc(HeapStack *a, u32 size, UnkFunc *f, void *p, u32 v);
void HeapStackReset(HeapStack *a);
void HeapStackDestroy(HeapStack *a);
HeapStack *HeapStackCreate(void *base, u32 size);
u32 func_0212dd64(Unk02021968 *a, Unk02021968 *b, u32 c, u32 d, HeapStack *e);
u32 func_0212de34(Unk02021968 *a, u32 b, u32 c, HeapStack *d);
void func_0212df28(void *buf, u32 size, void *p, u32 idx);
