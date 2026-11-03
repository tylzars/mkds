#pragma once

#include "types.h"

typedef struct Unk021b4d24 Unk021b4d24;
typedef struct Unk0218af28 Unk0218af28;
typedef struct Unk0218ae68 Unk0218ae68;

typedef struct Unk0218afac {
    /* 00 */ const s8 *mName;
} Unk0218afac;

Unk0218af28 *func_ov000_0218aea4(Unk0218ae68 *a);
void func_ov000_0218aec4(Unk0218ae68 *a, Unk0218af28 *b);
void func_ov000_0218aedc(Unk0218ae68 *a, Unk0218af28 *b);
u32 func_ov000_0218aefc(Unk0218af28 *a);
u8 func_ov000_0218af10(Unk0218af28 *a);
void func_ov000_0218af14(Unk0218af28 *a, u8 b);
void func_ov000_0218af18(Unk0218af28 *a, u32 b);
void func_ov000_0218af1c(Unk0218af28 *a, u32 b, u16 c);
void func_ov000_0218af24(Unk0218af28 *a, s32 b);
Unk0218af28 *func_ov000_0218af28(Unk021b4d24 *a, u32 b, u16 c);
u32 func_ov000_0218af9c(Unk0218af28 *a);
s32 func_ov000_0218afa0(const char *const *first, const char *const *second);
u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus);
void func_ov000_0218afb8(u32 *a);
