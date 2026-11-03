#pragma once

#include "types.h"

typedef struct Unk0218af28 Unk0218af28;

typedef struct Unk021b21ac {
    /* 0 */ const u8 *mUnk_00[2];
} Unk021b21ac;

typedef struct Unk0218b010 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u8 mUnk_02[0x86];
} Unk0218b010;

extern u8 data_ov000_021b21bc[];
extern s8 data_ov000_021b21c4[];
extern Unk021b21ac data_ov000_021b21ac;
extern s8 *data_ov000_021b4d14;

u32 func_ov000_0218afd4(const s8 *name, u32 modulus);
void func_ov000_0218b010(Unk0218af28 *e, s8 *buf, s32 n);
void func_ov000_0218b148(Unk0218af28 *e, s8 *buf);
s8 *func_ov000_0218b19c(s8 *s, s32 c);
u32 func_ov000_0218b1e0(const u8 *s);
