#pragma once

#include "types.h"

// Local of func_ov000_021a3910, filled with zeros and then with two function addresses and two bytes.
typedef struct Unk021a3910 {
    /* 00 */ void *(*mUnk_00)(u32 a, u32 b);
    /* 04 */ void (*mUnk_04)(u32 a, u32 b, u32 c);
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 pad_0a[2];
} Unk021a3910;

#include "00/code_02188000.h"

void func_ov000_021a37dc(void);
u32 func_ov000_021a3810(void);
void func_ov000_021a3884(void);
u32 func_ov000_021a38d8(void);
void func_ov000_021a3910(void);
void func_ov000_021a397c(s32 a);
void func_ov000_021a39c4(void *a);
