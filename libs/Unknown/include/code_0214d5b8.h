#pragma once

#include "types.h"

// Word of two bit-fields and a 26-bit field that PxiReceiveDispatch and PxiSendFifoWord pack and unpack.
typedef struct PxiWord {
    /* 00 */ u32 mUnk_00_0 : 5;
    /* 00 */ u32 mUnk_00_5 : 1;
    /* 00 */ u32 mUnk_00_6 : 26;
} PxiWord;

// Fixed-address object; PxiCallbackBitIsSet and PxiCallbackSet read and write the words at mUnk_388.
typedef struct Unk027ffc00 {
    /* 000 */ u8 mUnk_000[0x388];
    /* 388 */ u32 mUnk_388[2];
} Unk027ffc00;

extern UnkFunc *data_0218032c[32];
extern u16 data_02180328;

void PxiInit(void);
void PxiReceiveDispatch(void);
s32 PxiSendFifoWord(u32 a, u32 b, u32 c);
s32 PxiCallbackBitIsSet(u32 a, u32 b);
void PxiCallbackSet(u32 a, UnkFunc *fn);
void PxiInitOnce(void);
