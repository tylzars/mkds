#pragma once

#include "types.h"

typedef struct Unk021a6bb4 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x10];
    /* 18 */ u8 mUnk_18[6];
    /* 1e */ u8 mUnk_1e[0xe];
    /* 2c */ u8 mUnk_2c[1];
} Unk021a6bb4;

void func_ov000_021a6c08(u8 c);
s32 func_ov000_021a6c68(void);
u8 func_ov000_021a6c90(void);
