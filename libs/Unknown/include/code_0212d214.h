#pragma once

#include "types.h"
#include "code_02003024.h"

// What func_0212d580 points at; its bytes at 4 and 5 are read.
typedef struct Unk0212d580 {
    /* 0 */ u8 mUnk_00[4];
    /* 4 */ u8 mUnk_04;
    /* 5 */ u8 mUnk_05;
} Unk0212d580;

// 12-byte records at 0x20 of Unk0212f788; func_0212f788 returns one unless its first word is -1.
typedef struct Unk0212f788 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c; // number of records
    /* 20 */ u32 mUnk_20[3];
} Unk0212f788;

// Entry of 0x10 bytes in the table at mUnk_84 of Unk0212d5f8: func_0212d27c reads up to mUnk_04 bytes from offset
// mUnk_00 through mUnk_34 of Unk0212d5f8, and func_0212d5f8 sets mUnk_08 to its buf + mUnk_00.
typedef struct Unk0212d27c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ Unk0212f788 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0212d27c;

// Table at mUnk_84 of Unk0212d5f8: mUnk_08 entries from 0x0c.
typedef struct Unk0212d254 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk0212d27c mUnk_0c[1];
} Unk0212d254;

// Table at an offset (counted from the start of Unk0212d38c) stored in Unk0212d38c: mUnk_00 offsets from 0x04.
typedef struct Unk0212d328 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04[1];
} Unk0212d328;

// Block at mUnk_8c of Unk0212d5f8: offsets of six tables read by func_0212d328 to func_0212d51c.
typedef struct Unk0212d38c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08[6];
} Unk0212d38c;

// 0x90-byte object: func_0212d5f8 copies its first 0x30 bytes from buf, func_0212d6c4 reads them through
// FS_ReadFile on mUnk_34.
typedef struct Unk0212d5f8 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 mUnk_28[8];
    /* 30 */ u32 mUnk_30;
    /* 34 */ Unk02003024 mUnk_34;
    /* 7c */ Unk02005814 mUnk_7c;
    /* 84 */ Unk0212d254 *mUnk_84;
    /* 88 */ void *mUnk_88;
    /* 8c */ Unk0212d38c *mUnk_8c;
} Unk0212d5f8;

typedef struct Unk0212d5f8 Unk0212d5f8;

// List header of 12 bytes: first and last element, number of elements, and the offset of the links in an element.
typedef struct LinkedList {
    /* 00 */ void *mHead;
    /* 04 */ void *mTail;
    /* 08 */ u16 mCount;
    /* 0a */ u16 mLinkOffset;
} LinkedList;

// 16 bytes: mLevels lists 20-byte elements whose links are at 0x0c (HeapStackInit sets that offset); HeapStackPushLevel
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

void func_0212d214(void *arg0, u32 arg1, Unk0212d5f8 *arg2, u32 arg3);
void func_0212d220(void *arg0, u32 arg1, Unk0212d5f8 *arg2, u32 arg3);
void func_0212d22c(void *arg0, u32 arg1, Unk0212d5f8 *arg2, u32 arg3);
u32 func_0212d238(u32 arg0, Unk02021968 *arg1);
void *func_0212d254(u32 a);
s32 func_0212d27c(u32 a, void *dst, u32 n, u32 off);
u32 func_0212d300(u32 a);
void *func_0212d328(s32 a);
void *func_0212d38c(s32 a);
void *func_0212d3f0(s32 a);
void *func_0212d454(s32 a);
u32 *func_0212d4b8(s32 a);
void *func_0212d51c(s32 a);
Unk0212d580 *func_0212d580(s32 a, s32 b);
struct Unk0212d5f8 *func_0212d5d0(void);
Unk0212d5f8 *func_0212d5e0(Unk0212d5f8 *a);
void func_0212d5f8(Unk0212d5f8 *a, void *buf);
u32 func_0212d6c4(Unk0212d5f8 *a, HeapStack *p, u32 flag);
void func_0212d8e0(Unk0212d5f8 *a, const u8 *path, void *p, u32 flag);
void func_0212da1c(LinkedList *arg0);
u32 func_0212dd64(Unk02021968 *a, Unk02021968 *b, u32 c, u32 d, HeapStack *e);
u32 func_0212de34(Unk02021968 *a, u32 b, u32 c, HeapStack *d);
void func_0212df28(void *buf, u32 size, void *p, u32 idx);
