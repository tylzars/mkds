#pragma once

#include "types.h"

typedef struct Unk021b8760 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 pad_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[1];
} Unk021b8760;

typedef struct Unk021b88c0 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x28];
    /* 30 */ u8 mUnk_30[0x40];
} Unk021b88c0;

typedef struct Unk021b8990 {
    /* 000 */ u8 pad_000[4];
    /* 004 */ u32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x28];
    /* 030 */ u8 mUnk_030[0x40];
    /* 070 */ u8 mUnk_070[0x40];
    /* 0b0 */ u8 mUnk_0b0[0x40];
    /* 0f0 */ u8 mUnk_0f0[0x40];
} Unk021b8990;

typedef struct Unk021b8758 {
    /* 000 */ u8 pad_000[8];
    /* 008 */ Unk021b8990 mUnk_008;
    /* 138 */ Unk021b8990 mUnk_138;
    /* 268 */ Unk021b88c0 mUnk_268;
    /* 2d8 */ Unk021b88c0 mUnk_2d8;
    /* 348 */ u8 pad_348[8];
} Unk021b8758;

#include "03/code_021b94b8.h"

extern u8 data_ov003_021d6800[];

s32 func_ov003_021b8748(u32 value);
s32 func_ov003_021b8758(s32 a, Unk021b8760 *b, s32 c, Unk021b8758 *d, u8 *e);
s32 func_ov003_021b887c(Unk021b8760 *a, u8 *b);
s32 func_ov003_021b88c0(Unk021b8760 *a, Unk021b88c0 *b);
s32 func_ov003_021b8990(Unk021b8760 *a, Unk021b8990 *b);
u32 func_ov003_021b8af4(const u8 *bytes, s32 count);
