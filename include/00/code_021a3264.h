#pragma once

#include "types.h"

// State of the generator in func_ov000_021a3448.
typedef struct Unk021b5dd4 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk021b5dd4;

extern Unk021b5dd4 data_ov000_021b5dd4;

BOOL func_ov000_021a3264(u32 a, void *b, s32 c);
BOOL func_ov000_021a32a0(u32 a, void *b, s32 c);
BOOL func_ov000_021a3310(u16 a, u32 b, u8 *c, s32 d);
BOOL func_ov000_021a33e4(u32 a, s32 b);
u32 func_ov000_021a3448(u32 a);
u64 func_ov000_021a350c(void);
s32 func_ov000_021a3530(const char *a, char *b, const char *c, int d);
u32 func_ov000_021a360c(void *param_1, void *param_2, void *param_3, u32 param_4);
u32 func_ov000_021a363c(void *param_1, void *param_2, void *param_3, u32 param_4);
