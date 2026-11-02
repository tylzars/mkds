#pragma once

#include "types.h"

typedef struct Unk0218afac {
    /* 00 */ const s8 *mName;
} Unk0218afac;

#include "00/unk_021b4000.h"
#include "00/code_0218a9bc.h"

int func_ov000_0218aea4(int *param_1);
void func_ov000_0218aec4(int *param_1, int param_2);
void func_ov000_0218aedc(int *param_1, int param_2);
u32 func_ov000_0218aefc(int param_1);
u8 func_ov000_0218af10(int param_1);
void func_ov000_0218af14(int param_1, u8 param_2);
void func_ov000_0218af18(int param_1, u32 param_2);
void func_ov000_0218af1c(int param_1, u32 param_2, u16 param_3);
void func_ov000_0218af24(int param_1, s32 param_2);
Unk0218af28 *func_ov000_0218af28(Unk021b4d24 *a, u32 b, u16 c);
u32 func_ov000_0218af9c(int param_1);
s32 func_ov000_0218afa0(const u8 *const *first, const u8 *const *second);
u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus);
void func_ov000_0218afb8(u32 *param_1);
