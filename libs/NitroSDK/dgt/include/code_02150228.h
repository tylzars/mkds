#pragma once

#include "types.h"

// 0x58 bytes: the four MD5 state words, the 64-bit count of bytes taken so far and the 0x40-byte block being filled.
// The last two words of the block are also written as mBitCountLow and mBitCountHigh (the bit count).
typedef struct DGTHash1Context {
    /* 00 */ u32 mState[4];
    /* 10 */ u64 mLength;
    /* 18 */ u8 mBuffer8[0x38];
    /* 50 */ u32 mBitCountLow;
    /* 54 */ u32 mBitCountHigh;
} DGTHash1Context;

extern u32 data_0216f0ac[48];
extern u32 data_0216f16c[64];

// Runs the 64 MD5 steps over the block in ctx and adds the result to the state.
void ProcessBlock(DGTHash1Context *ctx);
// Pads the data to a multiple of 64 bytes with the bit count, writes the 16 digest bytes to digest and clears ctx.
void DGT_Hash1GetDigest_R(void *digest, DGTHash1Context *ctx);
// Adds length bytes from input to the data being hashed, processing each full block.
void DGT_Hash1SetSource(DGTHash1Context *ctx, const void *input, u32 length);
