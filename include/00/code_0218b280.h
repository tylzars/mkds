#pragma once

#include "types.h"

typedef struct Unk0218af28 Unk0218af28;

typedef struct Unk0218b30c {
    /* 0 */ const u8 *mUnk_00;
} Unk0218b30c;

extern u8 data_ov000_021b21c8[];
extern u8 data_ov000_021b21d0[];
extern u8 data_ov000_021b21d8[];
extern u8 data_ov000_021b21e4[];

// Declared here until the code that defines it is decompiled.

double func_ov000_0218b280(Unk0218af28 *e, const u8 *key, double d);
s32 func_ov000_0218b2a8(Unk0218af28 *e, const u8 *key, s32 d);
u8 *func_ov000_0218b30c(Unk0218af28 *e, const u8 *key, u8 *d);
void func_ov000_0218b358(Unk0218af28 *e, const u8 *key, u32 c);
void func_ov000_0218b380(Unk0218af28 *e, const u8 *key, const u8 *value);
