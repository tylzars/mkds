#pragma once

#include "types.h"
#include "code_0200e77c.h"

// Fixed-address object in the data TCM; the code reads and writes words at these offsets.
typedef struct Unk027e0000 {
    /* 0000 */ Unk0200df9c mUnk_0000;
    /* 0008 */ u8 mUnk_0008[0x3380 - 0x8];
    /* 3380 */ u32 mUnk_3380;
    /* 3384 */ u8 mUnk_3384[0x3f7c - 0x3384];
    /* 3f7c */ u32 mUnk_3f7c;
    /* 3f80 */ u8 mUnk_3f80[0x3ff8 - 0x3f80];
    /* 3ff8 */ u32 mUnk_3ff8;
} Unk027e0000;

extern Unk027e0000 data_027e0000;
extern UnkFunc *data_027e0008[22];

// Entry of the table of 8 at data_0216fee0: a function pointer, a word, and the argument the function is called with.
typedef struct Unk0216fee0 {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk0216fee0;

extern Unk0216fee0 data_0216fee0[8];
extern u16 data_021617bc[8];

void func_0200c914(void);
void func_0200c924(void);
void func_0200c934(void);
void func_0200c944(void);
void func_0200c954(void);
void func_0200c964(void);
void func_0200c974(void);
void func_0200c984(void);
void func_0200c994(u32 n);
void func_0200ca30(void);
void func_0200ca34(void);
u32 func_0200ca68(u32 v);
u32 func_0200ca9c(u32 m);
u32 func_0200cae4(u32 m);
u32 func_0200cb1c(u32 v);
void func_0200cb50(u32 n, UnkFunc *f, u32 a);
void func_0200cb9c(u32 n, UnkFunc *f, u32 a);
UnkFunc *func_0200cbe8(u32 m);
void func_0200cc74(u32 m, UnkFunc *f);
