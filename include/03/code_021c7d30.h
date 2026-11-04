#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Unk021d299c Unk021d299c;

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

extern u8 data_ov003_021d6430[];
extern u8 data_ov003_021d6460[];
extern Unk021d299c data_ov003_021d649c[];
extern Unk021d299c data_ov003_021d64b4[];
extern u8 data_ov003_021d73cc[];
extern Unk021d73d0 data_ov003_021d73d0;

void func_ov003_021c6e38(void);
void func_ov003_021c7748(void);
void func_ov003_021c7d30(u8 a);
void func_ov003_021c7d3c(void);
void func_ov003_021c7d58(void);
u32 func_ov003_021c7d8c(void);
void func_ov003_021c7e20(void);
void func_ov003_021c7e8c(void);
void func_ov003_021c7ec4(void);
void func_ov003_021c7eec(s32 d);
void func_ov003_021c8100(u32 a);
// Declared here until the code that defines them is decompiled.
void func_ov003_021c812c(void);
void func_ov003_021c81b8(void);
void func_ov003_021c824c(void);
void func_ov003_021c82b4(u32 b);
void func_ov003_021c8320(u32 b);
int func_ov003_021c83b0(int a);
int func_ov003_021c83cc(int a);
u32 func_ov003_021c8400(void);
void func_ov003_021c85a0(void);
void func_ov003_021c8718(const u8 *b, int c);
void func_ov003_021c876c(const u8 *g, int h);
void func_ov003_021c8838(int d, int e, int f);
u32 func_ov003_021c8904(u32 a);
void func_ov003_021c8974(u32 a, int b);
void func_ov003_021c8a60(u32 a, int b);
void func_ov003_021c8b94(void);
void func_ov003_021c8c14(void);
void func_ov003_021c8e48(void);
void func_ov003_021c8e80(void);
void func_ov003_021c8ea0(void);
void func_ov003_021c9058(u32 a);
void func_ov003_021c9084(u32 param_1);
void func_ov003_021c90dc(u32 param_1);
u32 func_ov003_021c91fc(void);
void func_ov003_021c9268(void);
void func_ov003_021c9450(void);
void func_ov003_021c9464(void);
void func_ov003_021c948c(void);
void func_ov003_021c94c8(void);
void func_ov003_021c9500(void);
void func_ov003_021c965c(void);
void func_ov003_021cca30(const void *b);
void func_ov003_021cce78(void);
void func_ov003_021ccea4(u32 a, u32 b, u16 c, u16 d, u32 e);
void func_ov003_021d2094(void *e, s32 f, u32 g, u32 h, s32 l, u16 *m, s32 n);
