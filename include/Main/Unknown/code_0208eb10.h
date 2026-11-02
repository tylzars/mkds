#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"

// Element of the lists behind data_0217b08c, which has a list of elements at 0x08 of its own.
typedef struct Unk0208ec64_08 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ Vec3 mUnk_10;
} Unk0208ec64_08;

// Entry func_0208ec64 takes from the list at 0x0c of data_0217b08c.
typedef struct Unk0208ec64 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk02017328 mUnk_08;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
} Unk0208ec64;

void func_0208eb10(unsigned int p0);
Unk0208ec64 *func_0208eb1c(s32 a);
s32 func_0208ec64(u32 a);
