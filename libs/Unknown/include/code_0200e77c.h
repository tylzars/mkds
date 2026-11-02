#pragma once

#include "types.h"

struct Unk0200db5c;

// Two Unk0200db5c pointers; func_0200e5f8 and func_0200e5c4 link the objects through their mUnk_80 and mUnk_7c.
// func_0200df9c and func_0200e01c take it.
typedef struct Unk0200df9c {
    /* 00 */ struct Unk0200db5c *mUnk_00;
    /* 04 */ struct Unk0200db5c *mUnk_04;
} Unk0200df9c;

// 0x18 bytes; func_0200edc0 clears mUnk_00 to mUnk_0c. func_0200ebe4 and func_0200ebc0 link it through mUnk_10 and
// mUnk_14 into the Unk0200e594 at mUnk_88 of an Unk0200db5c.
typedef struct Unk0200edc0 {
    /* 00 */ Unk0200df9c mUnk_00;
    /* 08 */ struct Unk0200db5c *mUnk_08; // set by func_0200ec08 and func_0200ed34
    /* 0c */ u32 mUnk_0c;                 // raised by func_0200ec08 and func_0200ed34, lowered by func_0200ecc4
    /* 10 */ struct Unk0200edc0 *mUnk_10;
    /* 14 */ struct Unk0200edc0 *mUnk_14;
} Unk0200edc0;

typedef struct Unk0200e594 {
    /* 00 */ Unk0200edc0 *mUnk_00;
    /* 04 */ Unk0200edc0 *mUnk_04;
} Unk0200e594;

// Set up by func_0200eb90. func_0200eae8 stores a word at mUnk_10[(mUnk_18 + mUnk_1c) % mUnk_14] and raises mUnk_1c;
// func_0200ea3c reads mUnk_10[mUnk_18], advances mUnk_18 modulo mUnk_14 and lowers mUnk_1c. Each calls
// func_0200e01c on one of mUnk_00 and mUnk_08 and func_0200df9c on the other.
typedef struct Unk0200eb90 {
    /* 00 */ Unk0200df9c mUnk_00;
    /* 08 */ Unk0200df9c mUnk_08;
    /* 10 */ void **mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0200eb90;

extern u32 data_021617cc;

u32 func_0200e77c(void);
u32 func_0200e7b0(void);
u32 func_0200e884(void);
u32 func_0200e8fc(void);
s32 func_0200e904(Unk0200eb90 *q, void **p, s32 f);
s32 func_0200e988(Unk0200eb90 *q, void *v, s32 f);
s32 func_0200ea3c(Unk0200eb90 *q, void **p, s32 f);
s32 func_0200eae8(Unk0200eb90 *q, void *v, s32 f);
void func_0200eb90(Unk0200eb90 *q, void **p, s32 n);
void func_0200ebc0(struct Unk0200db5c *t, Unk0200edc0 *n);
void func_0200ebe4(struct Unk0200db5c *t, Unk0200edc0 *n);
// p is used as an Unk0200edc0: these three write +0x08 and +0x0c, func_0200ebe4 and func_0200ebc0 (called with p) write
// +0x10 and +0x14, and func_0200e01c and func_0200df9c (given p) write +0x00 and +0x04. data_0217eadc passes
// elements 0x14 bytes apart, so +0x14 of one element is +0x00 of the next.
s32 func_0200ec08(void *p);
void func_0200ec7c(struct Unk0200db5c *t);
void func_0200ecc4(void *p);
void func_0200ed34(void *p);
