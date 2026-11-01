#pragma once

#include "types.h"
#include "00/code_0219de4c.h"

// Five bytes at data_ov000_021b40bc; the first member of Unk021a0a40 starts with them.
typedef struct Unk021b40bc {
    /* 0 */ char mUnk_00[5];
} Unk021b40bc;

// Local of func_ov000_021a0a40, passed on to func_ov000_0218b530.
typedef struct Unk021a0a40 {
    /* 00 */ char mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
} Unk021a0a40;

// The twelve bytes at Unk021b566c::mUnk_18c.
typedef struct Unk021a0c30 {
    /* 00 */ u8 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk021a0c30;

// Declared here until the code that defines them is decompiled.
void func_ov000_0219b110(void);

s32 func_ov000_021a0958(u8 *a, const u8 *b, s32 c);
s32 func_ov000_021a09d0(struct Unk0218f960 *a, u32 b, u32 c, const u8 *d);
u32 func_ov000_021a0a40(u32 a, u32 b, u32 c, u32 *d, u32 e);
u32 func_ov000_021a0ae8(u32 a, u32 b, u32 c, u32 d, void *e, s32 f);
u32 func_ov000_021a0c30(Unk021a0c30 *a);
u32 func_ov000_021a0cac(s32 a, s32 b, u32 c);
s32 func_ov000_021a0ed8(u8 *a, s32 b, s32 c, s32 d);
u32 func_ov000_021a0f20(u32 a);
void func_ov000_021a104c(void);
