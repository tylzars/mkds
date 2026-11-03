#pragma once

#include "types.h"

// Byte stream at data_usa_021755a0: mUnk_00 to mUnk_04 bound the buffer, mUnk_08 is the position, mUnk_0c the highest
// position written, mUnk_14 the element size, mUnk_18 the mask of bits func_02039230 and func_020392c8 move.
typedef struct Unk02039230 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
} Unk02039230;

extern Unk02039230 data_usa_021755a0;

u32 func_02039230(void);
void func_020392c8(u32 a);
void func_02039378(u32 a, u32 b);
void func_0203940c(void);
void func_02039478(void);
void func_020394cc(void);
