#pragma once

#include "types.h"
#include "code_0200e0ec.h"
#include "00/code_02186628.h"

// Three words: a function called with (name, size) that returns a block, a function called with (name, block, 0) that
// releases it, and a word.
typedef struct Unk02188114 {
    /* 00 */ void *(*mUnk_00)();
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u32 mUnk_08;
} Unk02188114;

// Object behind data_ov000_021b4cb0.
typedef struct Unk02187490 {
    /* 000 */ u32 mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ Unk021868a4Entry mUnk_08[0x20];
    /* 108 */ Unk02188114 mUnk_108;
    /* 114 */ void *mUnk_114;
    /* 118 */ void *mUnk_118;
    /* 11c */ Unk0200db5c mUnk_11c;
    /* 1d4 */ u8 pad_1d4[8];
    /* 1dc */ Unk0200edc0 mUnk_1dc;
    /* 1f4 */ u8 pad_1f4[0x100c];
    /* 1200 */ u8 mUnk_1200[0x1000];
} Unk02187490;

void func_ov000_02187490(u32 param_0);
