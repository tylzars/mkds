#pragma once

#include "types.h"
#include "Main/Unknown/code_02081618.h"

typedef struct Unk02081e3c {
    /* 00 */ u8 mUnk_00[0x90];
    /* 90 */ u32 mUnk_90;
    /* 94 */ u8 mUnk_94[0x5];
    /* 99 */ u8 mUnk_99;
    /* 9a */ u8 mUnk_9a;
    /* 9b */ u8 mUnk_9b;
} Unk02081e3c;

void func_02081e3c(Unk02081e3c *p0, unsigned int p1, unsigned int p2);
