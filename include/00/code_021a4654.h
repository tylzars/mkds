#pragma once

#include "types.h"
#include "00/code_0218e49c.h"

// Output buffer the string writers append to: bytes at mUnk_000, used length at mUnk_800.
typedef struct Unk021a471c {
    /* 000 */ u8 mUnk_000[0x800];
    /* 800 */ s32 mUnk_800;
} Unk021a471c;

// Address record filled by func_ov000_021a4654.
typedef struct Unk021a4654 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021a4654;

// Four-byte entry moved by func_ov000_021a46d4.
typedef struct Unk021a46d4 {
    /* 0 */ u8 mUnk_00[4];
} Unk021a46d4;

extern s32 data_ov000_021b5df8;
extern u8 data_ov000_021b5dfc[5 * 4];

// Declared here until the code that defines it is decompiled.
Unk021a8f84 *func_ov000_021a8f84(const u8 *a);

BOOL func_ov000_021a4654(const u8 *a, u32 b, Unk021a4654 *c, Unk021a8f84 **d);
void func_ov000_021a46d4(void);
void func_ov000_021a471c(Unk021a471c *a, const u8 *b);
void func_ov000_021a4760(Unk021a471c *a, s32 b);
