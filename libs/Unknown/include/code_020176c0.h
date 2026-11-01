#pragma once

#include "types.h"
#include "code_02017550.h" // Unk02017584
#include "code_02017e70.h" // Unk02017e70
#include "code_02017ea0.h" // Unk02017ea0

// Two Unk02017ea0 followed by two halfwords.
typedef struct Unk020179d4 {
    /* 00 */ Unk02017ea0 mUnk_00;
    /* 08 */ Unk02017ea0 mUnk_08;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk020179d4;

// Unk02017584 followed by an Unk020179d4.
typedef struct Unk020176c0 {
    /* 00 */ Unk02017584 mUnk_00;
    /* 24 */ Unk020179d4 mUnk_24;
} Unk020176c0;

u32 func_020176c0(Unk020176c0 *a, u32 b);
u32 func_02017748(Unk020176c0 *a);
void func_02017770(Unk020176c0 *a, void *b);
u32 func_020177b0(Unk020176c0 *a, void *b, u32 c);
void *func_02017938(Unk020176c0 *a, u32 b, s32 c);
void func_0201797c(Unk02017584 *a);
Unk020176c0 *func_02017988(void *a, u32 b, u16 c);
u32 func_020179d4(Unk020179d4 *a, Unk02017ef8 *b);
void *func_02017acc(Unk020176c0 *a, u32 b, u32 c);
void *func_02017b90(Unk020176c0 *a, u32 b, u32 c);
void *func_02017c58(Unk020179d4 *a, Unk02017e70 *b, void *c, u32 d, u16 e);
Unk020176c0 *func_02017dec(Unk020176c0 *a, u32 b, u16 c);
