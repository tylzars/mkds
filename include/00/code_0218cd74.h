#pragma once

#include "types.h"

// Four bytes copied byte by byte (func_ov000_0218ce14_inline in code_0218cdd8.c); the target may be unaligned.
typedef struct Unk0218cd94 {
    /* 0 */ u8 mUnk_00[4];
} Unk0218cd94;

typedef struct Unk021b4d24 Unk021b4d24;

// Object func_ov000_0218ce14 builds.
typedef struct Unk0218ce14 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0218ce14;

// Declared here until the code that defines it is decompiled.

void func_ov000_0218cd74(u8 **arg0, const void *arg1, s32 arg2, s32 *arg3);
void func_ov000_0218cd94(u8 **a, u32 b, s32 *c);
void func_ov000_0218cdc4(u8 **a, u8 b, s32 *c);
void func_ov000_0218cdd8(u8 **a, const char *b, s32 *c);
s32 func_ov000_0218ce14(Unk021b4d24 *p);
u32 func_ov000_0218cef4(const s8 *a, u32 b);
void func_ov000_0218cf30(Unk021b4d24 *p);
void func_ov000_0218cfb8(Unk021b4d24 *p, const char *a, const char *b, const char *c, u32 d, s32 e, UnkFunc *f,
                         void *g);
int func_ov000_0218d0c8(const void *a, int b);
void func_ov000_0218d0e4(Unk021b4d24 *p, u32 key);
void *func_ov000_0218d134(Unk021b4d24 *p, const char *key);
void func_ov000_0218d180(unsigned int p0);
void func_ov000_0218d1a0(Unk021b4d24 *a);
void func_ov000_0218d1dc(Unk021b4d24 *p);
u32 func_ov000_0218d218(Unk021b4d24 *a, u32 b);
u32 func_ov000_0218d22c(Unk021b4d24 *a);
void func_ov000_0218d238(Unk021b4d24 *p, s32 a);
void func_ov000_0218d278(Unk021b4d24 *p, u32 key);
int func_ov000_0218d2a8(Unk021b4d24 *a, int b, int c);
int func_ov000_0218d300(Unk021b4d24 *a, int b);
void func_ov000_0218d340(Unk021b4d24 *p, u32 a);
void func_ov000_0218d374(Unk021b4d24 *p, s32 a, u32 b, u32 c);
s32 func_ov000_0218d3d8(u32 *a, u32 *b);
s32 func_ov000_0218d430(u32 *c, u32 *d);
