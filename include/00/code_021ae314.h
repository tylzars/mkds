#pragma once

#include "types.h"
#include "00/unk_021b6380.h"

// Frame start: two addresses and a type word.
typedef struct Unk021ae3a4 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mUnk_0c;
} Unk021ae3a4;

typedef struct Unk021ae3f0 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk021ae3f0;

typedef struct Unk021ae724 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021ae724;

typedef struct Unk021ae87c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u8 pad_10[4];
} Unk021ae87c;

extern u16 data_ov000_021b6374;

u32 func_ov000_021ae314(void);
u16 func_ov000_021ae340(void);
void func_ov000_021ae3a4(void);
void func_ov000_021ae3f0(Unk021ae3f0 *a, u32 f);
Unk021ae3f0 *func_ov000_021ae51c(Unk021ae3f0 *r, u32 *s);
void func_ov000_021ae724(Unk021ae3f0 *a, Unk021ae724 *b, u32 c);
void func_ov000_021ae87c(Unk021ae3f0 *a, Unk021ae87c *b, u32 c);
