#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Zeroed by func_ov000_0218f15c and passed to the callback.
typedef struct Unk0218f15cArg {
    /* 00 */ u32 mUnk_00[8];
} Unk0218f15cArg;

typedef void (*Unk0218f15cCb)(GpConnection *a, Unk0218f15cArg *b, u32 c);

u32 func_ov000_0218f15c(GpConnection *a, s8 *b, s8 *c, s32 d, s32 e, Unk0218f15cCb f, u32 g);
u32 func_ov000_0218f21c(GpConnection *a, s32 b, void (*c)(void *a, void *b, u32 c), u32 d);
u32 GpUpdate(GpConnection *a);
void func_ov000_0218f2a0(GpConnection *a);
u32 GpInitialize(GpConnection *a, s32 b, s32 c);
int GpiUpdateConnection(void *a, int b);
u32 func_ov000_0218f408(GpConnection *a);
u32 GpiResetConnection(GpConnection *a);
