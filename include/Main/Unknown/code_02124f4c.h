#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk021243ac_20

// Tag in a run of halfwords: 0x1a, a byte (the number of bytes), a byte (1) and a halfword (0xff).
typedef struct Unk0212513c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u16 mUnk_04;
} Unk0212513c;

// Tag that func_021253f8 and func_021251c4 read through the pointer they pass to the function at member 4 of
// Unk02022aa8: a byte (the number of bytes), a byte, a halfword and a byte.
typedef struct Unk021253f8 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
} Unk021253f8;

// 1 when the halfword is in 0x30..0x39 or 0xff10..0xff19, or is 0x2d; else 0.
static inline s32 func_021253f8_inline(u16 c) {
    if ((c >= 0x30 && c <= 0x39) || (c >= 0xff10 && c <= 0xff19) || c == 0x2d) {
        return 1;
    }
    return 0;
}

void func_0212586c(Unk021243ac_20 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, void *i, s32 j, s8 k, s32 l);
void func_0212583c(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, void *i);
void func_02125808(Unk021243ac_20 *a, s32 b, s32 c, s32 d, s32 e, u32 f, u32 g, u32 h, void *i, s32 j, s8 k);
void func_021257d8(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, void *i);
void func_021253f8(Unk021243ac_20 *a, s32 *b, s32 *c, s32 *d, void *e, u16 *f, s32 g, s32 h);
s32 func_021253ac(u32 a, s32 b, s32 c, s32 d, s32 e);
void func_021251c4(Unk021243ac_20 *a, s32 b, s32 *c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, u32 j, s32 k, void *l,
                   s32 m, s32 n, s32 o);
void func_0212513c(u16 *a, u16 *b, u16 *c, u32 d);
void *func_021250b0(void *a);
void *func_02125028(void *a);
s32 func_02125004(u32 a);
s32 func_02124fac(u32 a, u16 *b);
s32 func_02124f4c(u32 a, u16 *b);
