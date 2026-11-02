#pragma once

#include "types.h"

// Local of func_ov000_021a31e8, filled by a copy of eight bytes.
typedef struct Unk021a31e8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
} Unk021a31e8;

s32 func_ov000_021a31d4(s32 value);
u16 func_ov000_021a31e8(const void *a);
void func_ov000_021a321c(u32 *param_1, u16 param_2, u32 param_3);
void func_ov000_021a323c(void (*arg0)(u32, void *, u32));
void func_ov000_021a3250(u32 (*arg0)(void));
