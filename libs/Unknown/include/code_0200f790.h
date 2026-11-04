#pragma once

#include "types.h"

// 0x2c bytes. Entry of a doubly linked list ordered by mUnk_0c; data_02170260 holds the first and last entry.
// func_0200f950 stores its third and fourth arguments at mUnk_00 and mUnk_04; func_0200f8b8 and func_0200f7a0 clear
// mUnk_00 when they unlink the entry.
typedef struct Unk0200fb08 {
    /* 00 */ void (*mUnk_00)(void *); // called with mUnk_04
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u64 mUnk_0c;
    /* 14 */ struct Unk0200fb08 *mUnk_14; // previous entry
    /* 18 */ struct Unk0200fb08 *mUnk_18; // next entry
    /* 1c */ u64 mUnk_1c;
    /* 24 */ u64 mUnk_24;
} Unk0200fb08;

typedef struct Unk02170260 {
    /* 00 */ Unk0200fb08 *mUnk_00;
    /* 04 */ Unk0200fb08 *mUnk_04;
} Unk02170260;

typedef struct Unk0200fb08 Unk0200fb08;

void func_0200f790(void);
void func_0200f7a0(void);
void func_0200f8b8(Unk0200fb08 *a);
void func_0200f950(Unk0200fb08 *a, u64 n, void (*f)(void *), void *p);
void func_0200f9c8(Unk0200fb08 *a, u64 n);
void func_0200fb08(Unk0200fb08 *a);
u32 func_0200fb18(void);
void func_0200fb28(void);
void func_0200fb80(Unk0200fb08 *n);
void func_0200fc1c(void);
