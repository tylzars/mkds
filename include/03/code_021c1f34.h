#pragma once

#include "types.h"

// 0x104 bytes moved as one value.
typedef struct Unk021c1fc8_02 {
    /* 000 */ u16 mUnk_00[0x82];
} Unk021c1fc8_02;

// Stack object of func_ov003_021c1fc8.
typedef struct Unk021c1fc8 {
    /* 000 */ u16 mUnk_00;
    /* 002 */ u8 mUnk_02;
    /* 003 */ u8 pad_03;
    /* 004 */ u16 mUnk_04;
    /* 006 */ u8 mUnk_06[0x100];
} Unk021c1fc8;

u32 func_ov003_021c1f34(void);
void func_ov003_021c1f84(int a);
void func_ov003_021c1fc8(void);
