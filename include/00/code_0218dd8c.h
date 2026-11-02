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

Unk0218e004 *func_ov000_0218e004(s32 param_1, s32 param_2, s32 param_3, s32 (*param_4)(void *, s32),
                                 s32 (*param_5)(void *, void *), void (*param_6)(void *));

int func_ov000_0218dd8c(int *param_1, int param_2, u32 param_3);
void func_ov000_0218dddc(Unk0218e004 *param_1, void (*param_2)(void *, void *), void *param_3);
void *func_ov000_0218de28(Unk0218e004 *param_1, void *param_2);
s32 func_ov000_0218de8c(Unk0218e004 *param_1, void *param_2);
void func_ov000_0218def0(Unk0218e004 *param_1, void *param_2);
s32 func_ov000_0218df5c(Unk0218e004 *param_1);
void func_ov000_0218dfb4(void *param_1);
