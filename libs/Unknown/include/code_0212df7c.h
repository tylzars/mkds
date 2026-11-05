#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"

// Entry from func_0212d3f0: a number in the low 24 bits, and bit 0 of the byte at 3 is tested.
typedef struct Unk0212e490 {
    /* 00 */ u32 mUnk_00 : 24;
    /* 03 */ u32 mUnk_03 : 8;
} Unk0212e490;

// Entry from func_0212d454: a number at 0 and four halfwords from 4; func_0212e538 skips the ones equal to 0xffff.
typedef struct Unk0212e538 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04[4];
} Unk0212e538;

// Entry of 8 bytes in the table from func_0212d328 (a count, then the entries): the byte at 0 (0 to 3) selects the
// function called with the word at 4 and the byte at 1.
typedef struct Unk0212e7b4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u32 mUnk_04;
} Unk0212e7b4;

// Record of 12 bytes: func_0212f788 and func_0212d51c return one. func_0212e708 reads the number at 0 and the
// halfword at 4, func_0212ed58 passes the halfword at 4 and the bytes at 8 and 9 to func_0212eaf8, and func_0212ea28
// and func_0212eaf8 read the bytes at 6 and 7.
typedef struct Unk0212ea28 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[2];
} Unk0212ea28;

// Entry func_0212edac reads: byte at 0x00, halfword at 0x02, word at 0x04.
typedef struct Unk0212edac {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk0212edac;

extern u8 data_0217dec8[0x3c];

void func_0212df7c(u8 *a, u32 b, Unk0212d5f8 *c, u32 d);
void func_0212dfa0(u8 *a, u32 b, Unk0212d5f8 *c, u32 d);
void func_0212dfdc(u8 *a, u32 b, Unk0212d5f8 *c, u32 d);
void func_0212e018(u8 *a, u32 b, Unk0212d5f8 *c, u32 d);
void func_0212e04c(void *a, Unk0212d5f8 *b, u32 c);
Unk02021968 *func_0212e0b8(u32 a, HeapStack *b, u32 c);
Unk02021968 *func_0212e1ec(u32 a, HeapStack *b, u32 c);
void *func_0212e268(u32 a, HeapStack *b, u32 c);
void *func_0212e2e4(u32 a, HeapStack *b, u32 c);
void *func_0212e360(u32 a, HeapStack *b, u32 c);
void *func_0212e3dc(u32 a, UnkFunc *f, Unk0212d5f8 *p, u32 d, HeapStack *e);
u32 func_0212e490(s32 a, u32 b, HeapStack *c, u32 d, Unk02021968 **out);
u32 func_0212e538(s32 a, u32 b, HeapStack *c, u32 d, Unk02021968 **out);
u32 func_0212e698(s32 a, u32 b, HeapStack *c, u32 d, Unk0212f788 **out);
u32 func_0212e708(s32 a, u32 b, HeapStack *c, u32 d, Unk0212f788 **out);
u32 func_0212e7b4(s32 a, HeapStack *b);
u32 func_0212e8f4(s32 a, u32 b, HeapStack *c);
u32 func_0212e924(s32 a, HeapStack *b);
u32 func_0212e95c(s32 a, HeapStack *b);
u32 func_0212e994(s32 a, HeapStack *b);
u32 func_0212e9cc(s32 a, HeapStack *b);
u32 func_0212ea04(s32 a, HeapStack *b);
s32 func_0212ea28(Unk0212c400 **a, s32 b, s32 c, s32 d, Unk0212ea28 *e, Unk0212f788 *f, u32 g, u32 h);
s32 func_0212eaf8(Unk0212c400 **a, s32 b, s32 c, s32 d, Unk0212ea28 *e, u32 f);
s32 func_0212ec04(Unk0212c400 **a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 func_0212ecc0(const void *a, u32 b, u32 c);
s32 func_0212ed58(void *a, s32 b);
u32 func_0212edac(HeapStack *a);
