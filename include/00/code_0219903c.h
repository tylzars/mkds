#pragma once

#include "types.h"

typedef struct Unk021990f8Entry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ u32 mUnk_0c;
} Unk021990f8Entry;

#include "00/code_02197e8c.h"

int func_ov000_0219903c(Unk02197fe8 *a, u32 b, int c, int *d);
u32 func_ov000_021990f8(Unk02197fe8 *a, u16 b, s32 c);
u32 func_ov000_0219914c(Unk02197e8c *a);
u32 func_ov000_0219922c(int a, u32 b, u32 c);
