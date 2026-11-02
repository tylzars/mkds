#pragma once

#include "types.h"

// Object of func_0203ba84 and func_0203bc64: flag bytes at 0 and 1, two arrays of eight words and a pointer at 0x44.
typedef struct Unk0203ba84 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04[8];
    /* 24 */ s32 mUnk_24[8];
    /* 44 */ struct Unk0205fd2c *mUnk_44;
} Unk0203ba84;

void func_0203ba84(u8 *b);
void func_0203bc64(u8 *b);
