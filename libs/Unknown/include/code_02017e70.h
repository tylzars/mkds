#pragma once

#include "types.h"

// Block of 16 bytes followed by mUnk_04 bytes, linked through mUnk_08 and mUnk_0c; func_02017e70 sets it up over a
// range. Halfword 2 holds a byte, seven bits and a flag.
typedef struct Unk02017e70 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ struct Unk02017e70 *mUnk_08;
    /* 0c */ struct Unk02017e70 *mUnk_0c;
} Unk02017e70;

// Two addresses: func_02017ef8 writes the start of a block (minus its offset) and the end of its data.
typedef struct Unk02017ef8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02017ef8;

Unk02017e70 *func_02017e70(Unk02017ef8 *a, u16 b);
