#pragma once

#include "types.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

// Object returned by func_ov003_021cdb6c.
typedef struct Unk021c8a60 {
    /* 00 */ u8 mUnk_00[0x40];
    /* 40 */ u8 mUnk_40[0x80];
    /* c0 */ u8 mUnk_c0[4];
    /* c4 */ u8 mUnk_c4[4];
    /* c8 */ u8 mUnk_c8[8];
    /* d0 */ u8 mUnk_d0;
    /* d1 */ u8 mUnk_d1[0x15];
    /* e6 */ u8 mUnk_e6_0 : 2;
    /* e6 */ u8 mUnk_e6_2 : 6;
    /* e7 */ u8 mUnk_e7;
    /* e8 */ u8 mUnk_e8[8];
    /* f0 */ u8 mUnk_f0[4];
    /* f4 */ u8 mUnk_f4;
    /* f5 */ u8 mUnk_f5;
    /* f6 */ u8 mUnk_f6;
} Unk021c8a60;

// Declared here until the code that defines them is decompiled.
void func_ov003_021d2094(void *e, s32 f, u32 g, u32 h, s32 l, u16 *m, s32 n);
void func_ov003_021cce78(void);
void func_ov003_021c6e38(void);
void func_ov003_021c7748(void);

void func_ov003_021c85a0(void);
void func_ov003_021c8718(const u8 *b, int c);
void func_ov003_021c876c(const u8 *g, int h);
void func_ov003_021c8838(int d, int e, int f);
u32 func_ov003_021c8904(u32 a);
void func_ov003_021c8974(u32 a, int b);
void func_ov003_021c8a60(u32 a, int b);
void func_ov003_021c8b94(void);
void func_ov003_021c8c14(void);
