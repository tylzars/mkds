#pragma once

#include "types.h"

typedef struct Unk02003024 Unk02003024;

// Entries of 0x20 bytes after a count word; func_0204d28c reads and rewrites the word at 0x18.
typedef struct Unk0204d28c_20 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[4];
} Unk0204d28c_20;

void func_0204d28c(void);
void func_0204d5bc(void);
u32 func_0204d610(u32 *a);
void func_0204d6f4(Unk02003024 *a, s32 b);
s32 func_0204dab8(Unk02003024 *a, u32 b);
