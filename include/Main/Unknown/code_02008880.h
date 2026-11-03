#pragma once

#include "types.h"

typedef struct Unk02003024 Unk02003024;

// Two words of the 0x60-byte block that FS_ReadFile reads.
typedef struct Unk02008880 {
    /* 00 */ u8 mUnk_00[0x2c];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u8 mUnk_30[0xc];
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u8 mUnk_40[0x20];
} Unk02008880;

u32 func_02008880(Unk02003024 *a);
u16 func_020088dc(const u16 *a, s32 b);
