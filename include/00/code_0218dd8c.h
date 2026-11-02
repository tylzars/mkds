#pragma once

#include "types.h"
#include "00/code_0218dc44.h"

// 0x14 bytes. Table of Unk0218dc94 arrays: the array of buckets, its length, the per-element callback and the
// functions that pick a bucket and compare two elements.
typedef struct Unk0218e004 {
    /* 00 */ Unk0218dc94 **mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void (*mUnk_08)(void *);
    /* 0c */ s32 (*mUnk_0c)(void *, s32);
    /* 10 */ s32 (*mUnk_10)(void *, void *);
} Unk0218e004;

Unk0218e004 *func_ov000_0218e004(s32 c, s32 d, s32 e, s32 (*f)(void *, s32), s32 (*g)(void *, void *),
                                 void (*h)(void *));

int func_ov000_0218dd8c(int *a, int b, u32 c);
void func_ov000_0218dddc(Unk0218e004 *b, void (*c)(void *, void *), void *d);
void *func_ov000_0218de28(Unk0218e004 *c, void *d);
s32 func_ov000_0218de8c(Unk0218e004 *c, void *d);
void func_ov000_0218def0(Unk0218e004 *c, void *d);
s32 func_ov000_0218df5c(Unk0218e004 *c);
void func_ov000_0218dfb4(void *c);
