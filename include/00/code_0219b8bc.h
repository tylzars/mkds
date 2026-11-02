#pragma once

#include "types.h"

typedef struct Unk021b5550 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021b5550;

// Declared here until the code that defines them is decompiled.

#include "00/code_0219887c.h"
#include "00/code_0219b580.h"

extern void *data_ov000_021b54d0[32];
extern Unk021b5550 data_ov000_021b5550[32];

BOOL func_ov000_0219b8bc(u32 a);
Unk021b5550 *func_ov000_0219b8f0(s32 index);
void **func_ov000_0219b8fc(u32 a, s32 b);
void **func_ov000_0219b958(s32 index);
void func_ov000_0219b964(void);
s32 func_ov000_0219b998(void);
u32 func_ov000_0219b9b4(Unk0219887c *object);
u8 func_ov000_0219b9c4(Unk0219887c *object);
u32 func_ov000_0219b9d4(u32 a);
s32 func_ov000_0219ba20(void);
u32 func_ov000_0219bab4(void);
s32 func_ov000_0219bac8(u32 a);
s32 func_ov000_0219bb04(u8 **a);
