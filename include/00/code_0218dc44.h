#pragma once

#include "types.h"

// 0x18 bytes. Growable array: count, capacity, element size, growth step, per-element callback, element data.
typedef struct Unk0218dc94 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void (*mUnk_10)(void *);
    /* 14 */ u8 *mUnk_14;
} Unk0218dc94;

s32 func_ov000_0218dc44(void *param_1);
void func_ov000_0218dc48(void *param_1);
void *func_ov000_0218dc94(s32 param_1, s32 param_2, void (*param_3)(void *));
void func_ov000_0218dd18(Unk0218dc94 *param_1, const void *param_2, s32 param_3);
void func_ov000_0218dd38(Unk0218dc94 *param_1);
void func_ov000_0218dd74(void *param_1, s32 param_2);
