#pragma once

#include "types.h"
#include "Main/Unknown/code_020d50ec.h" // Unk020d634c

// Object func_020d6538 fills from 0x5c on; only the words it writes are seen.
typedef struct Unk020d6538_a {
    /* 00 */ u8 pad_00[0x5c];
    /* 5c */ u32 mUnk_5c;
    /* 60 */ u8 pad_60[4];
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ u32 mUnk_6c;
} Unk020d6538_a;

void func_020d6538(Unk020d6538_a *p0, Unk020d634c *p1);
