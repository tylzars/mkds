#pragma once

#include "types.h"

typedef struct Unk0218f960 Unk0218f960;

// Zeroed by func_ov000_0218f15c and passed to the callback.
typedef struct Unk0218f15cArg {
    /* 00 */ u32 mUnk_00[8];
} Unk0218f15cArg;

typedef void (*Unk0218f15cCb)(Unk0218f960 *a, Unk0218f15cArg *b, u32 c);

u32 func_ov000_0218f15c(Unk0218f960 *a, s8 *b, s8 *c, s32 d, s32 e, Unk0218f15cCb f, u32 g);
u32 func_ov000_0218f21c(Unk0218f960 *a, s32 b, void (*c)(void *a, void *b, u32 c), u32 d);
u32 func_ov000_0218f268(Unk0218f960 *a);
void func_ov000_0218f2a0(Unk0218f960 *a);
u32 func_ov000_0218f2b8(Unk0218f960 *a, s32 b, s32 c);
int func_ov000_0218f2e8(void *a, int b);
u32 func_ov000_0218f408(Unk0218f960 *a);
u32 func_ov000_0218f654(Unk0218f960 *a);
