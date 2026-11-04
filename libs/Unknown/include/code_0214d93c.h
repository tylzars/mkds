#pragma once

#include "types.h"

// 0x24 bytes. func_0214d93c waits while mUnk_00 is 1; func_0214dfbc and func_0214e07c set it, set mUnk_14 and store
// their arguments in mUnk_08, mUnk_04 and mUnk_10; func_0214d9e8 calls mUnk_04 and mUnk_1c and clears mUnk_00 and
// mUnk_18.
typedef struct Unk0214d93c {
    /* 00 */ vu32 mUnk_00;
    /* 04 */ UnkFunc *mUnk_04;
    /* 08 */ u32 *mUnk_08;
    /* 0c */ u32 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ UnkFunc *mUnk_1c;
    /* 20 */ u32 mUnk_20;
} Unk0214d93c;

// Fixed-address word that func_0214d9e8 reads.
typedef struct Unk027ffde8 {
    /* 00 */ u32 mUnk_00_0 : 8;
    /* 00 */ u32 mUnk_00_8 : 5;
    /* 00 */ u32 : 3;
    /* 00 */ u32 mUnk_00_16 : 6;
    /* 00 */ u32 : 2;
    /* 00 */ u32 mUnk_00_24 : 3;
    /* 00 */ u32 : 5;
} Unk027ffde8;

// Fixed-address halfword that func_0214d9e8 reads and changes.
typedef struct Unk027ffdea {
    /* 00 */ u16 mUnk_00_0 : 4;
    /* 00 */ u16 : 2;
    /* 00 */ u16 mUnk_00_6 : 1;
    /* 00 */ u16 : 9;
} Unk027ffdea;

// Fixed-address word as func_0214d9e8 reads it for mUnk_14 values 1 and 2.
typedef struct Unk027ffdec {
    /* 00 */ u32 mUnk_00_0 : 6;
    /* 00 */ u32 : 2;
    /* 00 */ u32 mUnk_00_8 : 7;
    /* 00 */ u32 : 1;
    /* 00 */ u32 mUnk_00_16 : 7;
    /* 00 */ u32 : 9;
} Unk027ffdec;

// The word of Unk027ffdec as func_0214d9e8 reads it for mUnk_14 value 8.
typedef struct Unk027ffdec_b {
    /* 00 */ u32 mUnk_00_0 : 3;
    /* 00 */ u32 : 4;
    /* 00 */ u32 mUnk_00_7 : 1;
    /* 00 */ u32 mUnk_00_8 : 6;
    /* 00 */ u32 : 1;
    /* 00 */ u32 mUnk_00_15 : 1;
    /* 00 */ u32 mUnk_00_16 : 7;
    /* 00 */ u32 mUnk_00_23 : 1;
    /* 00 */ u32 : 8;
} Unk027ffdec_b;

u32 DecimalNibblesToValue(u32 x);

extern u16 data_021803ac;
extern Unk0214d93c data_021803b0;

void func_0214d93c(void);
void func_0214d954(u32 arg0);
void func_0214d9e8(u32 a, u32 b, s32 c);
u32 func_0214df78(u32 *a);
u32 func_0214dfbc(u32 *a, UnkFunc *b, u32 c);
u32 func_0214e038(u32 *a);
u32 func_0214e07c(u32 *a, UnkFunc *b, u32 c);
void func_0214e0f4(void);
s32 func_0214e17c(u32 a);
s32 func_0214e1b0(void);
s32 func_0214e1c0(void);
s32 func_0214e1d0(void);
