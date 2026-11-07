#pragma once

#include "types.h"

// 0x68 bytes: five words at 0x00, a 64-bit count in the words at 0x14 and 0x18, a byte count at 0x1c and a 0x40-byte
// buffer at 0x20.
typedef struct Hash20State {
    /* 00 */ u32 mWords[5];
    /* 14 */ u32 mBitCountLow;
    /* 18 */ u32 mBitCountHigh;
    /* 1c */ int mBufferLen;
    /* 20 */ u8 mBlock[0x40];
    /* 60 */ u8 mUnk_60[8];
} Hash20State;

typedef struct Hash20State Hash20State;

// Function pointer that DGT_SetOverlayTableMode switches between DGTi_Hash2ProcessMessageBlock and func_02150e1c.
extern void (*data_0216f26c)(Hash20State *ctx, u8 *source, int length);

void DGT_Hash2CalcHmac(u8 *digest, const u8 *bin, u32 binLen, const u8 *key, s32 keyLen);
void DGTi_Hash2ProcessMessageBlock(Hash20State *ctx, u8 *source, int length);
void DGT_Hash2GetDigest(Hash20State *ctx, u8 *digest, ...);
void DGT_Hash2SetSource(Hash20State *ctx, const u8 *input, u32 length);
void DGT_Hash2Reset(Hash20State *ctx);
u32 DGT_SetOverlayTableMode(u32 flag);
