#pragma once

#include "types.h"

// Argument of func_02034370: it sets the halfword at 0x04.
typedef struct Unk02034370 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02034370;

// What func_0202ddd8 returns points to one: func_02034370 sets bit 0 of the word at 0x08.
typedef struct Unk0202ddd8 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08_0 : 1;
    /* 08 */ u32 mUnk_08_1 : 31;
} Unk0202ddd8;

void func_0203434c(void);
s32 func_02034370(Unk02034370 *a);
