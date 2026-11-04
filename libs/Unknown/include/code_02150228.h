#pragma once

#include "types.h"

// 0x58 bytes: four words at 0x00, a 64-bit count at 0x10 and a 0x40-byte buffer at 0x18 whose last two words are
// also written as mUnk_50 and mUnk_54.
typedef struct Hash16State {
    /* 00 */ u32 mWords[4];
    /* 10 */ u64 mByteCount;
    /* 18 */ u8 mBlock[0x38];
    /* 50 */ u32 mBitCountLow;
    /* 54 */ u32 mBitCountHigh;
} Hash16State;

extern u32 data_0216f0ac[48];
extern u32 data_0216f16c[64];

void Hash16Block(Hash16State *q);
void Hash16Final(u8 *out, Hash16State *ctx);
void Hash16Update(Hash16State *ctx, const u8 *src, u32 n);
