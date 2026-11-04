#pragma once

#include "types.h"

// Word of two bit-fields and a 26-bit field that func_0214d5c4 and PxiSendFifoWord pack and unpack.
typedef struct Unk0214d5c4 {
    /* 00 */ u32 mUnk_00_0 : 5;
    /* 00 */ u32 mUnk_00_5 : 1;
    /* 00 */ u32 mUnk_00_6 : 26;
} Unk0214d5c4;

// Fixed-address object; func_0214d79c and func_0214d7c4 read and write the words at mUnk_388.
typedef struct Unk027ffc00 {
    /* 000 */ u8 mUnk_000[0x388];
    /* 388 */ u32 mUnk_388[2];
} Unk027ffc00;

extern UnkFunc *data_0218032c[32];
extern u16 data_02180328;

void func_0214d5b8(void);
void func_0214d5c4(void);
s32 PxiSendFifoWord(u32 a, u32 b, u32 c);
s32 func_0214d79c(u32 a, u32 b);
void func_0214d7c4(u32 a, UnkFunc *fn);
void func_0214d830(void);
