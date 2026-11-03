#pragma once

#include "types.h"

// Object at a fixed address in func_0200f4f0, which sets its word at 0xfdc.
typedef struct Unk0200f4f0 {
    /* 000 */ u8 mUnk_000[0xfdc];
    /* fdc */ UnkFunc *mUnk_fdc;
} Unk0200f4f0;

void func_0200f3f4(u32 a);
void func_0200f484(void);
void func_0200f4f0(void);
