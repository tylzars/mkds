#pragma once

#include "types.h"

typedef struct Unk021a998c_0c Unk021a998c_0c;

// Six length and pointer pairs.
typedef struct Unk021aa880 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ const u8 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ const u8 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ const u8 *mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ const u8 *mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ const u8 *mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ const u8 *mUnk_2c;
} Unk021aa880;

void func_ov000_021aa7f8(u8 *a, const u8 *b, Unk021a998c_0c *c);
void func_ov000_021aa880(u8 *a, const u8 *b, Unk021aa880 *c);
void func_ov000_021aa9ec(Unk021a998c_0c *a, const u8 *b);
void func_ov000_021aaa58(Unk021a998c_0c *a, u8 *b);
