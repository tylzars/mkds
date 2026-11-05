#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "00/code_021a2ccc.h"

typedef struct Unk021b54c8 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void (*mUnk_04)();
    /* 08 */ void (*mUnk_08)();
    /* 0c */ s32 (*mUnk_0c)();
    /* 10 */ void (*mUnk_10)();
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ GpConnection mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ char mUnk_34[0x20];
    /* 54 */ char *mUnk_54;
    /* 58 */ char *mUnk_58;
    /* 5c */ void (*mUnk_5c)(s32 param_1);
    /* 60 */ u32 mUnk_60;
    /* 64 */ void (*mUnk_64)();
    /* 68 */ void *mUnk_68;
    /* 6c */ void (*mUnk_6c)(u32 a, u32 b, void *c);
    /* 70 */ void *mUnk_70;
    /* 74 */ void (*mUnk_74)(u32 a, u32 b, u32 c, u32 d, u32 e, void *f);
    /* 78 */ void *mUnk_78;
    /* 7c */ void (*mUnk_7c)(s32 a, s32 b, s32 c, u32 d, u32 e, void *f);
    /* 80 */ void *mUnk_80;
    /* 84 */ Unk021b565c mUnk_84;
    /* 2e8 */ Unk021b5664 mUnk_2e8;
    /* 33c */ Unk021b566c mUnk_33c;
    /* 7a0 */ Unk021b5dd0 mUnk_7a0;
} Unk021b54c8;

typedef struct Unk0219887c Unk0219887c;

typedef struct Unk021b5550 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021b5550;

BOOL func_ov000_0219bdec(const s8 *a, void (*b)(s32, s32), void *c, void (*d)(u32, u8), void *e, void (*f)(u32, u32),
                         void *g);

extern Unk021b54c8 *data_ov000_021b54c8;
extern void *data_ov000_021b54d0[32];
extern Unk021b5550 data_ov000_021b5550[32];

s32 func_ov000_0218d574(void);
void func_ov000_0219b580(u32 a, int b);
void func_ov000_0219b5a8(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_ov000_0219b694(u32 a, u32 b);
void func_ov000_0219b6c0(int a, u32 b);
u32 func_ov000_0219b704(u32 a);
int func_ov000_0219b77c(int c);
u32 func_ov000_0219b844(const u8 *values, s32 count);
u32 func_ov000_0219b868(u32 a);
void func_ov000_0219b8a8(s32 value);
BOOL func_ov000_0219b8bc(u32 a);
Unk021b5550 *func_ov000_0219b8f0(s32 index);
void **func_ov000_0219b8fc(u32 a, s32 b);
void **func_ov000_0219b958(s32 index);
void func_ov000_0219b964(void);
s32 func_ov000_0219b998(void);
u32 func_ov000_0219b9b4(Unk0219887c *object);
u8 func_ov000_0219b9c4(Unk0219887c *object);
void *func_ov000_0219b9d4(u32 a);
s32 func_ov000_0219ba20(void);
u32 func_ov000_0219bab4(void);
BOOL func_ov000_0219bac8(u32 a);
s32 func_ov000_0219bb04(u8 **a);
u8 func_ov000_0219bb50(void);
s32 func_ov000_0219bb68(void);
s32 func_ov000_0219bbac(s32 a);
s32 func_ov000_0219bbfc(void);
void func_ov000_0219bc78(void *a, u32 b, u32 c, u32 d, void *e, void *f, u32 g, u32 h);
void func_ov000_0219bd90(u32 a, void *b, void *c, void *d, void *e, u32 f);
void func_ov000_0219bea8(u32 a, u32 b, void (*c)(s32 a), u32 d);
void func_ov000_0219bf10(void);
void func_ov000_0219c0c4(void);
u32 func_ov000_0219c0c8(void);
void func_ov000_0219c0f4(void);
void func_ov000_0219c1e4(void *a, void *b, s32 c, const char *d, const char *e, s32 f, s32 g, void *h, s32 i);
// Declared here until the code that defines it is decompiled.
void func_ov000_0219d734(s32 a, s32 b);
void func_ov000_0219d81c(void);
void func_ov000_021a1430(void);
