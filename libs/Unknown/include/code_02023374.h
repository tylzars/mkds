#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h" // Unk02180728
#include "code_02022aa8.h" // Unk02022aa8
#include "code_020245a4.h" // Unk020247fc

// Two pointers, passed by address to the function at 0x14 of Unk02023374.
typedef struct Unk02023374_24 {
    /* 00 */ Unk02022c80 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
} Unk02023374_24;

// 0x20-byte object set up by func_02023374 and func_02023408: a buffer of 8 x 8 blocks of mUnk_0c * 8 bytes and the
// functions that draw into it.
typedef struct Unk02023374 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ void (*mUnk_14)(struct Unk02023374 *, Unk02022aa8 *, s32, s32, u32, Unk02023374_24 *);
    /* 18 */ void (*mUnk_18)(struct Unk02023374 *, u32);
    /* 1c */ void (*mUnk_1c)(struct Unk02023374 *, u32, s32, s32, s32, s32);
} Unk02023374;

// Argument of func_02023d84, built on the stack by func_020239a8 and func_02023bcc.
typedef struct Unk02023d84 {
    /* 00 */ u32 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u32 mUnk_24;
} Unk02023d84;

void func_02023510(Unk02023374 *a, void *b, s32 c, s32 d, u32 e,
                   void (*f)(Unk02023374 *, Unk02022aa8 *, s32, s32, u32, Unk02023374_24 *),
                   void (*g)(Unk02023374 *, u32), void (*h)(Unk02023374 *, u32, s32, s32, s32, s32), u32 i);
void func_02023548(Unk02023374 *a, u32 b, s32 c, s32 d, s32 e, s32 f);
void func_02023764(Unk02023374 *a, u32 b, s32 c, s32 d, s32 e, s32 f);
void func_02023944(Unk02023374 *a, u32 b);
void func_020239a8(Unk02023374 *a, Unk02022aa8 *b, s32 c, s32 d, u32 e, Unk02023374_24 *f);
void func_02023bcc(Unk02023374 *a, Unk02022aa8 *b, s32 c, s32 d, u32 e, Unk02023374_24 *f);
void func_02023d84(Unk02023d84 *a);
void func_02024000(u8 *a, s32 b, s32 c, s32 d, s32 e, u32 f, s32 g);
u32 func_02024168(const u8 *a);
void func_020243f0(Unk02180728 *a, s32 b, s32 c, s32 d, u32 e, u32 f, u16 *g);
void func_020244f4(Unk02180728 *a, s32 b, s32 c, u32 d, u16 *e, u16 **f);
void func_02023374(void *a, void *b, s32 c, s32 d, s32 e);
void func_02023408(void *p0, void *p1, u32 p2, u32 p3, u32 p4);
s32 func_02023450(Unk02023374 *a, Unk02022aa8 *b, s32 c, s32 d, u32 e, u16 f);
u32 func_02024184(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_0202428c(Unk02180728 *a, s32 b, s32 c, s32 d, s32 e, s32 f, u32 g, u16 *h);
u32 func_02024340(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f);
