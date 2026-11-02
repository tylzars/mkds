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

s32 func_ov000_0218dc44(void *b);
void func_ov000_0218dc48(void *c);
void *func_ov000_0218dc94(s32 b, s32 c, void (*d)(void *));
void func_ov000_0218dd18(Unk0218dc94 *a, const void *b, s32 c);
void func_ov000_0218dd38(Unk0218dc94 *a);
void func_ov000_0218dd74(void *b, s32 c);
