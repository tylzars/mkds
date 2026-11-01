#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"

// 8-byte elements of the first table of Unk020c06c4: two words, each with a two-bit part at bit 10.
typedef struct Unk020c06c4_08 {
    /* 0 */ u32 mUnk_00 : 10;
    /* 0 */ u32 mUnk_0a : 2;
    /* 0 */ u32 mUnk_0c : 20;
    /* 4 */ u32 mUnk_04 : 10;
    /* 4 */ u32 mUnk_0e : 2;
    /* 4 */ u32 mUnk_10 : 20;
} Unk020c06c4_08;

// 0x20-byte elements of the first table of Unk020c06c4 (the same bytes as eight-byte elements): a halfword at each of
// 0x06, 0x0e, 0x16 and 0x1e.
typedef struct Unk020c06c4_20 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ s16 mUnk_0e;
    /* 10 */ u8 mUnk_10[6];
    /* 16 */ s16 mUnk_16;
    /* 18 */ u8 mUnk_18[6];
    /* 1e */ s16 mUnk_1e;
} Unk020c06c4_20;

// The first 0x400 bytes of Unk020c06c4.
typedef union Unk020c06c4_000 {
    Unk020c06c4_08 mUnk_00[0x80];
    Unk020c06c4_20 mUnk_20[0x20];
} Unk020c06c4_000;

// Object of 0x402 bytes: a table of 0x400 bytes and a halfword at 0x400.
typedef struct Unk020c06c4 {
    /* 000 */ Unk020c06c4_000 mUnk_000;
    /* 400 */ u16 mUnk_400;
} Unk020c06c4;

void func_020c092c(Unk020c06c4 *a, Unk0217b498 *b, s32 c);
void func_020c06c4(Unk020c06c4 *a, Unk0217b498 *b, s32 c);
