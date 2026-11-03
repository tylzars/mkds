#pragma once

#include "types.h"
#include "code_020219e8.h" // Unk02021a5c

// 3 bytes: func_02022bbc adds the first two, or reads the third.
typedef struct Unk02022c80 {
    /* 00 */ s8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ s8 mUnk_02;
} Unk02022c80;

// Entry of the chain at 0x0c of an Unk02022ce4: a range of mUnk_00..mUnk_02 with 8 bytes of header, then
// entries of mUnk_0a (of the object) bytes.
typedef struct Unk02022c80_n {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ struct Unk02022c80_n *mUnk_04;
} Unk02022c80_n;

// Halfword number, then pairs of halfwords.
typedef struct Unk02022dd8_s {
    /* 00 */ u16 mUnk_00;
    /* 02 */ Unk02021a5c mUnk_02[1];
} Unk02022dd8_s;

// Entry of the chain at 0x10 of an Unk02022ce4: a range of mUnk_00..mUnk_02 and a kind (0: base number in
// mUnk_0c, 1: halfwords from 0x0c, 2: mUnk_0c pairs from 0x0e).
typedef struct Unk02022dd8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ struct Unk02022dd8 *mUnk_08;
    /* 0c */ Unk02022dd8_s mUnk_0c;
} Unk02022dd8;

// Object behind Unk02022ce4::mUnk_08: a byte at 0x01, a halfword at 0x02 and bytes from 0x08 (func_020aad9c).
typedef struct Unk02022ce4_08 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ u8 mUnk_08[1];
} Unk02022ce4_08;

typedef struct Unk02022ce4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ s8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Unk02022c80 mUnk_04;
    /* 07 */ u8 mUnk_07;
    /* 08 */ Unk02022ce4_08 *mUnk_08;
    /* 0c */ Unk02022c80_n *mUnk_0c;
    /* 10 */ Unk02022dd8 *mUnk_10;
} Unk02022ce4;

// Called with the address of a pointer to halfwords (func_02024960); returns a u16.
typedef u16 Unk02022aa8_f();

typedef struct Unk02022aa8 {
    /* 00 */ Unk02022ce4 *mUnk_00;
    /* 04 */ Unk02022aa8_f *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk02022aa8;

// Width and height written by func_02022aa8.
typedef struct Unk02022b10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk02022b10;

#include "Main/Unknown/code_02124094.h" // Unk02022eb0

#include "code_02021f9c.h" // Unk02021f9c

void func_02022aa8(Unk02022b10 *a, Unk02022aa8 *b, s32 c, s32 d, u8 *e);
s32 func_02022b44(Unk02022aa8 *a, s32 b, u8 *c);
s32 func_02022bbc(Unk02022aa8 *a, s32 b, u8 *c, u8 **d);
Unk02022c80 *func_02022c80(Unk02022aa8 *a, u32 b);
u32 func_02022ce4(Unk02022aa8 *a, u32 b);
void func_02022d44(Unk02022aa8 *a, Unk02021f9c *b);
void func_02022d88(Unk02022aa8 *a, Unk02021f9c *b);
u32 func_02022dd8(Unk02022dd8 *a, u32 b);
u32 func_020231e4(u32 a, u32 b);
void func_02023244(u16 *a, s32 b, s32 c, s32 d, s32 e, u32 f);
void func_020232b0(u16 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u32 h);
u32 func_02024168(const u8 *a);
