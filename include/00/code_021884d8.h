#pragma once

#include "types.h"

// Object behind data_ov000_021b4d10.
typedef struct Unk021884e4 {
    /* 00 */ void *(*mUnk_00)();
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 pad_10[4];
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} Unk021884e4;

u8 func_ov000_021884d8(u8 value);
void func_ov000_021884e4(u8 value);
u32 func_ov000_021884fc(void);
void func_ov000_02188508(u32 arg0);
u8 func_ov000_02188528(void);
void func_ov000_02188534(u8 a);
u32 func_ov000_02188584(u32 a);
void func_ov000_021885ec(void);
