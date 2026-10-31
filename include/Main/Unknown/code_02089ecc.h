#pragma once

#include "types.h"

typedef struct Unk02089ecc {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x2];
    /* 08 */ u32 mUnk_08;
} Unk02089ecc;

void func_02089ecc(Unk02089ecc *p0);
