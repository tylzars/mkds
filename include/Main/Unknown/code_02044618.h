#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h"

// The 0x1e8 bytes at the start of the object behind data_021759c0, taken from 0x1e8.
typedef struct Unk02044940_block {
    /* 000 */ u32 mUnk_000[0x7a];
} Unk02044940_block;

u16 func_02044618(void);
void func_0204465c(void);
void func_020446e0(void);
void func_02044940(void);
BOOL func_02044bf8(s32 a, s32 b);
s32 func_02044d4c(s32 a, s32 b);
s32 func_02044e9c(s32 a, s32 b);
void func_02044fc0(void);
void func_02045084(s32 a);
void func_02045590(void);
