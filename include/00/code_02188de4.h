#pragma once

#include "types.h"

struct Unk02188ec0;

// Bytes handed out by func_ov000_02188de4: a leading byte, then the payload.
typedef struct Unk02188de4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x50];
} Unk02188de4;

// One of the 0x100-byte entries at the start of Unk02188ec0.
typedef struct Unk02188db0 {
    /* 00 */ u8 pad_00[0x40];
    /* 40 */ u8 mUnk_40[0x20];
    /* 60 */ u8 mUnk_60[0x20];
    /* 80 */ u8 mUnk_80[0x40];
    /* c0 */ u8 mUnk_c0[4];
    /* c4 */ u8 mUnk_c4[4];
    /* c8 */ u8 mUnk_c8[4];
    /* cc */ u8 mUnk_cc[4];
    /* d0 */ u8 mUnk_d0;
    /* d1 */ u8 mUnk_d1[0x14];
    /* e5 */ u8 pad_e5;
    /* e6 */ u8 mUnk_e6 : 2;
    /* e7 */ u8 mUnk_e7;
    /* e8 */ u8 pad_e8[0x18];
} Unk02188db0;

// Declared here until the code that defines it is decompiled.

u32 func_ov000_02188de4(struct Unk02188ec0 *object, u32 a, Unk02188de4 *out);
