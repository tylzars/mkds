#pragma once

#include "types.h"
#include "00/code_02188de4.h"

// Eleven entries of 0xc0 bytes at 0x470 of Unk02188ec0.
typedef struct Unk02188ee0 {
    /* 00 */ u8 pad_00[0xa];
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 pad_17[0x15];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 pad_2e[8];
    /* 36 */ u16 mUnk_36;
    /* 38 */ u8 pad_38[0x88];
} Unk02188ee0;

// Entries of 0x24 bytes at 0x300 of Unk02188ec0.
typedef struct Unk02188ec0_300 {
    /* 00 */ u8 mUnk_00_lo : 4;
    /* 00 */ u8 mUnk_00_hi : 4;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04[0x20];
} Unk02188ec0_300;

// Entries of 4 bytes at 0x444 of Unk02188ec0.
typedef struct Unk02188ec0_444 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 pad_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk02188ec0_444;

typedef struct Unk02188ec0 {
    /* 000 */ Unk02188db0 mUnk_000[3];
    /* 300 */ Unk02188ec0_300 mUnk_300[9];
    /* 444 */ Unk02188ec0_444 mUnk_444[11];
    /* 470 */ Unk02188ee0 mUnk_470[11];
    /* cb0 */ u64 mUnk_cb0;
    /* cb8 */ Unk02188de4 mUnk_cb8;
    /* d0a */ u8 mUnk_d0a;
    /* d0b */ u8 mUnk_d0b : 2;
    /* d0b */ u8 mUnk_d0b_2 : 2;
    /* d0b */ u8 mUnk_d0b_4 : 4;
    /* d0c */ u8 mUnk_d0c : 4;
    /* d0c */ u8 mUnk_d0c_4 : 2;
    /* d0c */ u8 mUnk_d0c_6 : 2;
    /* d0d */ u8 mUnk_d0d;
    /* d0e */ u8 mUnk_d0e;
    /* d0f */ u8 mUnk_d0f;
    /* d10 */ u8 mUnk_d10;
    /* d11 */ s8 mUnk_d11;
    /* d12 */ u8 mUnk_d12;
    /* d13 */ u8 mUnk_d13;
    /* d14 */ u8 mUnk_d14;
    /* d15 */ u8 mUnk_d15;
    /* d16 */ u16 mUnk_d16;
} Unk02188ec0;

u32 func_ov000_02188ec0(Unk02188ec0 *object);
