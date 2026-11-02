#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a6fb4.h"

// An Unk021a7064 entry as func_ov000_021a7eec and the functions after it see it.
typedef struct Unk021a7eec {
    /* 00 */ Unk021a7064Func mUnk_00;
    /* 04 */ Unk021a6fa8 *mUnk_04;
    /* 08 */ Unk0200eb90 *mUnk_08;
    /* 0c */ s8 mUnk_0c;
    /* 0d */ s8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u8 *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 *mUnk_28;
} Unk021a7eec;

u8 *func_ov000_021a7bfc(Unk021a6fa8 *a, s32 *b, u16 *c, u16 *d, u32 *e);
s32 func_ov000_021a7c4c(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e);
s32 func_ov000_021a7d14(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f);
s32 func_ov000_021a7d68(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f, s32 g);
unsigned int func_ov000_021a7de0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                                 unsigned int f);
s32 func_ov000_021a7eec(const void *a, s32 b, Unk021a7eec *c);
s32 func_ov000_021a7f48(Unk021a7064 *a);
s32 func_ov000_021a8014(Unk021a6fa8 *a, u8 *b, s32 c, s32 d, u16 e, u16 *f, s32 g);
s32 func_ov000_021a8118(Unk021a6fa8 *a);
s32 func_ov000_021a813c(Unk021a6fa8 *a, s32 b, s32 c, u32 *d, s32 e);
s32 func_ov000_021a81a8(Unk021a6fa8 *a, u8 *b, s32 c, u16 d, u16 *e, s32 f);
u32 func_ov000_021a8268(u32 a, u32 b, u32 c, u16 d, u32 e, u32 f);
s32 func_ov000_021a8344(Unk021a7064 *a);
s32 func_ov000_021a836c(s32 a);
void func_ov000_021a8424(void);
void func_ov000_021a8454(Unk021a7154 *a);
void func_ov000_021a84c4(Unk021a6fa8 *a);
s32 func_ov000_021a8580(Unk021a7064 *a);
s32 func_ov000_021a8604(s32 a);
