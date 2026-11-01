#pragma once

#include "types.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

// Object behind data_0216fde8; the members are the ones the code reads.
typedef struct Unk0216fde8 {
    /* 0000 */ u8 mUnk_0000[0x20];
    /* 0020 */ u8 mUnk_0020[0x480];
    /* 04a0 */ u8 mUnk_04a0[0x20];
    /* 04c0 */ u8 mUnk_04c0[0xc0];
    /* 0580 */ Unk02143a78 mUnk_0580;
    /* 0590 */ u8 mUnk_0590[0x10];
    /* 05a0 */ u8 mUnk_05a0[0x24];
    /* 05c4 */ u8 mUnk_05c4[0x18];
    /* 05dc */ void (*mUnk_05dc)(u32, void *);
    /* 05e0 */ void (*mUnk_05e0)(u32, void *);
    /* 05e4 */ u32 mUnk_05e4;
    /* 05e8 */ u8 mUnk_05e8[0x5ee - 0x5e8];
    /* 05ee */ u16 mUnk_05ee;
    /* 05f0 */ u8 mUnk_05f0[0x5ef8 - 0x5f0];
    /* 5ef8 */ u32 mUnk_5ef8;
    /* 5efc */ u32 mUnk_5efc;
    /* 5f00 */ u32 mUnk_5f00;
    /* 5f04 */ u32 mUnk_5f04;
    /* 5f08 */ u32 mUnk_5f08;
    /* 5f0c */ u16 mUnk_5f0c;
    /* 5f0e */ u16 mUnk_5f0e;
} Unk0216fde8;

void func_0200ba44(u32 a, u32 b);
