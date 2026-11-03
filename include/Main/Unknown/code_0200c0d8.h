#pragma once

#include "types.h"

// Six bytes that func_0200c0d8 fills and func_0200c3a4 writes out.
typedef struct Unk0200c0d8 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u16 mUnk_04;
} Unk0200c0d8;

// 0x14 bytes that func_0200c16c writes out and func_0200c2e0 fills; the bytes from 3 or 4 on are moved from or to
// the entry in the word at data_0216fdf8.
typedef struct Unk0200c16c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x10];
} Unk0200c16c;

// 0x20-byte entry that func_0200c12c copies.
typedef struct Unk0200c12c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x16];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d[3];
} Unk0200c12c;

u8 *func_0200c0d8(Unk0200c0d8 *a, u8 *b);
u8 func_0200c12c(void *a, void *b);
u8 *func_0200c16c(Unk0200c16c *a, u8 *b);
u32 func_0200c20c(u32 a);
u8 *func_0200c25c(Unk0200c16c *a, u32 b);
u8 *func_0200c2e0(u8 *a, Unk0200c16c *b, u32 c);
u8 *func_0200c3a4(u8 *param_1, u8 *param_2);
