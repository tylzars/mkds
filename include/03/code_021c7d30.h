#pragma once

#include "types.h"

// Object returned by func_ov003_021cdb6c, from its offset 0x400 on.
typedef struct Unk021cdb6c {
    /* 00 */ u8 mUnk_00[0x40];
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41[0x7f];
    /* c0 */ u8 mUnk_c0[4];
    /* c4 */ u8 mUnk_c4[4];
    /* c8 */ u8 mUnk_c8[4];
    /* cc */ u8 mUnk_cc[4];
    /* d0 */ u8 mUnk_d0[0x20];
    /* f0 */ u8 mUnk_f0[4];
    /* f4 */ u8 mUnk_f4;
    /* f5 */ u8 mUnk_f5;
    /* f6 */ u8 mUnk_f6;
} Unk021cdb6c;

// Table of bytes func_ov003_021c81b8 reads.
typedef struct Unk021d73d0 {
    /* 00 */ u8 mUnk_00[0xe];
} Unk021d73d0;

#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/types_021d299c.h"

extern u8 data_ov003_021d6430[];
extern u8 data_ov003_021d6460[];
extern Unk021d299c data_ov003_021d649c[];
extern Unk021d299c data_ov003_021d64b4[];
extern u8 data_ov003_021d73cc[];
extern Unk021d73d0 data_ov003_021d73d0;

void func_ov003_021c7d30(u8 param_1);
void func_ov003_021c7d3c(void);
void func_ov003_021c7d58(void);
u32 func_ov003_021c7d8c(void);
void func_ov003_021c7e20(void);
void func_ov003_021c7e8c(void);
void func_ov003_021c7ec4(void);
void func_ov003_021c7eec(s32 param_0);
void func_ov003_021c8100(u32 param_0);
void func_ov003_021c812c(void);
void func_ov003_021c81b8(void);
void func_ov003_021c824c(void);
void func_ov003_021c82b4(u32 param_0);
void func_ov003_021c8320(u32 param_0);
int func_ov003_021c83b0(int param_1);
int func_ov003_021c83cc(int param_1);
u32 func_ov003_021c8400(void);
