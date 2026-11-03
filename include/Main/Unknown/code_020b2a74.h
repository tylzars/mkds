#pragma once

#include "types.h"

// Object at 0x48 in an element of data_02175628.
typedef struct Unk020b2a94 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u16 mHasPair;
    /* 06 */ u8 pad_06[6];
    /* 0c */ u16 mPrevHasPair;
    /* 0e */ u8 pad_0e[2];
    /* 10 */ u16 mNoPairCount;
} Unk020b2a94;

u32 func_020b2a74(s32 a);
u32 func_020b2a94(Unk020b2a94 *p);
u32 func_020b2ac8(Unk020b2a94 *p);
u32 func_020b2aec(Unk020b2a94 *p);
