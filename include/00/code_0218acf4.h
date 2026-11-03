#pragma once

#include "types.h"

typedef struct Unk0218af28 Unk0218af28;
typedef struct Unk0218a9bc Unk0218a9bc;

typedef struct Unk021b2148 {
    /* 00 */ u8 mUnk_00[13];
} Unk021b2148;

typedef struct Unk021b2158 {
    /* 0 */ u8 mUnk_00[8];
} Unk021b2158;

typedef struct Unk0218ad44 {
    /* 0 */ u8 mUnk_00[4];
} Unk0218ad44;

extern Unk021b2148 data_ov000_021b2188;
extern Unk021b2158 data_ov000_021b2198;

void func_ov000_0218acf4(Unk0218a9bc *p, s32 a, u32 b, s32 c, UnkFunc *f, void *g);
void func_ov000_0218ad44(Unk0218a9bc *p, Unk0218af28 *e);
