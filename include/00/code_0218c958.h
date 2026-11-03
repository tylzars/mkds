#pragma once

#include "types.h"

typedef struct Unk021b4d24 Unk021b4d24;

// Two bytes func_ov000_0218ca58 copies; the target may be unaligned.
typedef struct Unk0218ca58 {
    /* 0 */ u8 mUnk_00[2];
} Unk0218ca58;

void func_ov000_0218c958(Unk021b4d24 *p);
void func_ov000_0218c980(Unk021b4d24 *p);
void func_ov000_0218c9d4(Unk021b4d24 *p);
void func_ov000_0218ca1c(Unk021b4d24 *p);
s32 func_ov000_0218ca58(Unk021b4d24 *p, const char *a, const char *b, u32 c, u32 d);
s32 func_ov000_0218cc48(Unk021b4d24 *p, void *a, s32 b);

void func_ov000_0218ccbc(Unk021b4d24 *p);
