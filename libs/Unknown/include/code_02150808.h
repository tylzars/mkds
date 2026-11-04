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

// Function pointer that func_02150dc8 switches between func_02150994 and func_02150e1c.
extern void (*data_0216f26c)(Hash20State *ctx, u8 *data, int n);

void Hash20Hmac(u8 *a, const u8 *b, u32 n, const u8 *c, s32 m);
void func_02150994(Hash20State *ctx, u8 *data, int n);
void Hash20Final(Hash20State *ctx, u8 *out, ...);
void Hash20Update(Hash20State *ctx, u8 *src, u32 n);
void Hash20Init(Hash20State *p0);
u32 func_02150dc8(u32 v);
