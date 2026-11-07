#pragma once

#include "types.h"

typedef struct Unk020de6a8 Unk020de6a8;

// Second argument of CollideKartWithItemBox: a halfword at 0x74 and a word at 0x7c.
typedef struct Unk020dea50_1 {
    /* 00 */ u8 mUnk_00[0x74];
    /* 74 */ u16 mUnk_74;
    /* 76 */ u8 mUnk_76[6];
    /* 7c */ u32 mUnk_7c;
} Unk020dea50_1;

u8 CollideKartWithItemBox(Unk020de6a8 *a, Unk020dea50_1 *b, void *c, u8 *d);
u32 func_020de9f8(Unk020de6a8 *a);
