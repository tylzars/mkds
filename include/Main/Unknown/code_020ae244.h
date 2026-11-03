#pragma once

#include "types.h"

typedef struct Unk02175628_48 Unk02175628_48;

// Four halfwords passed by value to func_020ae244.
typedef struct Unk020ae244 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk020ae244;

u32 func_020ae244(u32 a, Unk020ae244 b);
u32 func_020ae290(u32 a);
u32 func_020ae2b0(Unk02175628_48 *a);
u32 func_020ae2e4(Unk02175628_48 *a);
u32 func_020ae308(Unk02175628_48 *a);
