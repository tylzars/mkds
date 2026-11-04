#pragma once

#include "types.h"

typedef struct SbServerList SbServerList;
typedef struct SbServer SbServer;
typedef struct Unk0218ae68 Unk0218ae68;

typedef struct Unk0218afac {
    /* 00 */ const s8 *mName;
} Unk0218afac;

SbServer *func_ov000_0218aea4(Unk0218ae68 *a);
void func_ov000_0218aec4(Unk0218ae68 *a, SbServer *b);
void func_ov000_0218aedc(Unk0218ae68 *a, SbServer *b);
u32 func_ov000_0218aefc(SbServer *a);
u8 func_ov000_0218af10(SbServer *a);
void func_ov000_0218af14(SbServer *a, u8 b);
void func_ov000_0218af18(SbServer *a, u32 b);
void func_ov000_0218af1c(SbServer *a, u32 b, u16 c);
void func_ov000_0218af24(SbServer *a, s32 b);
SbServer *func_ov000_0218af28(SbServerList *a, u32 b, u16 c);
u32 func_ov000_0218af9c(SbServer *a);
s32 func_ov000_0218afa0(const char *const *first, const char *const *second);
u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus);
void func_ov000_0218afb8(u32 *a);
