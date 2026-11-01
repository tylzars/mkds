#pragma once

#include "types.h"
#include "00/code_02187490.h"
#include "00/code_021884e4.h"
#include "00/code_021874ec.h"

// Element of the table at 0x300 of an Unk02188408.
typedef struct Unk02188408Entry24 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 pad_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04[0x20];
} Unk02188408Entry24;

// Element of the table at 0x444 of an Unk02188408.
typedef struct Unk02188408Entry4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk02188408Entry4;

// Element of the table at 0x470 of an Unk02188408; also the layout of the block written into it.
typedef struct Unk02188408Entry0xc0 {
    /* 00 */ u8 pad_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[0x20];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 pad_2e[8];
    /* 36 */ u16 mUnk_36;
    /* 38 */ u8 pad_38[0x88];
} Unk02188408Entry0xc0;

// Object behind data_ov000_021b4d00.
typedef struct Unk02188408 {
    /* 000 */ u8 pad_000[0x300];
    /* 300 */ Unk02188408Entry24 mUnk_300[9];
    /* 444 */ Unk02188408Entry4 mUnk_444[11];
    /* 470 */ Unk02188408Entry0xc0 mUnk_470[11];
    /* cb0 */ u8 pad_cb0[0x5a];
    /* d0a */ u8 mUnk_d0a;
    /* d0b */ u8 mUnk_d0b_0 : 2;
    /*     */ u8 mUnk_d0b_2 : 2;
    /*     */ u8 mUnk_d0b_4 : 4;
    /* d0c */ u8 mUnk_d0c_0 : 4;
    /*     */ u8 mUnk_d0c_4 : 2;
    /*     */ u8 mUnk_d0c_6 : 2;
    /* d0d */ u8 mUnk_d0d;
    /* d0e */ u8 pad_d0e;
    /* d0f */ u8 mUnk_d0f;
    /* d10 */ u8 mUnk_d10;
    /* d11 */ s8 mUnk_d11;
    /* d12 */ u8 mUnk_d12;
    /* d13 */ u8 mUnk_d13;
    /* d14 */ u8 mUnk_d14;
    /* d15 */ u8 pad_d15[3];
} Unk02188408;

extern const s8 *data_ov000_021b1488;
extern u8 data_ov000_021b1474[];
extern u8 data_ov000_021b13ac[];
extern u8 data_ov000_021b13d8[];
extern u8 data_ov000_021b147c[];

// Declared here until the code that defines them is decompiled.

void func_ov000_02188008(void);
void func_ov000_02188068(void);
u32 func_ov000_02188114(Unk02188114 *p);
s32 func_ov000_021881d0(const s8 *a, u32 b, u8 *c, u32 d);
s32 func_ov000_021882f8(const u8 *a, u32 b, s8 *c, u32 d);
s32 func_ov000_02188408(void);
void func_ov000_021884a8(void);
