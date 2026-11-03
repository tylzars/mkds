#pragma once

#include "types.h"

typedef struct Unk0218a71c {
    /* 000 */ u8 mUnk_000[256];
    /* 100 */ u8 mUnk_100[5];
} Unk0218a71c;

u8 func_ov000_0218a71c(Unk0218a71c *p, u8 x);
void func_ov000_0218a7bc(Unk0218a71c *p, const u8 *key, u32 n);
void func_ov000_0218a854(Unk0218a71c *p);
u8 func_ov000_0218a898(Unk0218a71c *p, u32 n, const u8 *key, u32 m, u8 *j, u32 *k);
