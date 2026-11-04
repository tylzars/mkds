#pragma once

#include "types.h"

typedef struct Unk021b5df4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk021b5df4;

// Local of func_ov000_021a3910, filled with zeros and then with two function addresses and two bytes.
typedef struct Unk021a3910 {
    /* 00 */ void *(*mUnk_00)(u32 a, u32 b);
    /* 04 */ void (*mUnk_04)(u32 a, u32 b, u32 c);
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 pad_0a[2];
} Unk021a3910;

#include "00/code_021a3a18.h"

extern Unk021b5df4 *data_ov000_021b5df4;

u32 func_ov000_021a3760(void);
BOOL func_ov000_021a377c(void);
void func_ov000_021a37dc(void);
u32 func_ov000_021a3810(void);
void func_ov000_021a3884(void);
u32 func_ov000_021a38d8(void);
void func_ov000_021a3910(void);
void func_ov000_021a397c(s32 a);
void func_ov000_021a39c4(void *a);
void func_ov000_021a39d8(Unk021b5df4 *a, u16 b, u32 c, u32 d);
