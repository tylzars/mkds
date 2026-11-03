#pragma once

#include "types.h"

// 0x68 bytes: five words at 0x00, a 64-bit count in the words at 0x14 and 0x18, a byte count at 0x1c and a 0x40-byte
// buffer at 0x20.
typedef struct Unk02150a10 {
    /* 00 */ u32 mUnk_00[5];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ int mUnk_1c;
    /* 20 */ u8 mUnk_20[0x40];
    /* 60 */ u8 mUnk_60[8];
} Unk02150a10;

typedef struct Unk02150a10 Unk02150a10;

// Function pointer that func_02150dc8 switches between func_02150994 and func_02150e1c.
extern void (*data_0216f26c)(Unk02150a10 *ctx, u8 *data, int n);

void func_02150808(u8 *a, const u8 *b, u32 n, const u8 *c, s32 m);
void func_02150994(Unk02150a10 *ctx, u8 *data, int n);
void func_02150a10(Unk02150a10 *ctx, u8 *out, ...);
void func_02150c1c(Unk02150a10 *ctx, u8 *src, u32 n);
void func_02150d78(Unk02150a10 *p0);
u32 func_02150dc8(u32 v);
