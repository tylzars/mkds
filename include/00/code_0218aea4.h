#pragma once

#include "types.h"

typedef struct Unk0218afac {
    /* 00 */ const s8 *mName;
} Unk0218afac;

#include "00/unk_021b4000.h"
#include "00/code_0218a9bc.h"

int func_ov000_0218aea4(int *a);
void func_ov000_0218aec4(int *a, int b);
void func_ov000_0218aedc(int *a, int b);
u32 func_ov000_0218aefc(int a);
u8 func_ov000_0218af10(int a);
void func_ov000_0218af14(int a, u8 b);
void func_ov000_0218af18(int a, u32 b);
void func_ov000_0218af1c(int a, u32 b, u16 c);
void func_ov000_0218af24(int a, s32 b);
Unk0218af28 *func_ov000_0218af28(Unk021b4d24 *a, u32 b, u16 c);
u32 func_ov000_0218af9c(int a);
s32 func_ov000_0218afa0(const u8 *const *first, const u8 *const *second);
u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus);
void func_ov000_0218afb8(u32 *a);
