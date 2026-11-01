#pragma once

#include "types.h"
#include "00/code_02185984.h"

// Object behind data_ov000_021b4c90; the bytes at 0x3bc are passed to func_0200ed34 and func_0200ecc4.
typedef struct Unk021b4c90 {
    /* 000 */ u8 pad_000[4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 pad_008[0x3b4];
    /* 3bc */ u8 mUnk_3bc[4];
} Unk021b4c90;

void func_ov000_0218592c(void *a);
void func_ov000_02185954(s32 a);
