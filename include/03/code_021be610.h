#pragma once

#include "types.h"
#include "03/code_021bf098.h"
#include "03/unk_021d8000.h"
#include "00/code_021a5b3c.h"
#include "00/code_021a669c.h"

// Object at the start of the Unk021da104 allocation: the word at 0x00 and the halfword at 0x04 are written bit by
// bit.
typedef struct Unk021da104_04 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021da104_04;

// 0xc bytes allocated by func_ov003_021beef8.
typedef struct Unk021da104 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk021da104_04 *mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
} Unk021da104;

// Message passed to func_ov003_021bea3c.
typedef struct Unk021bea3c {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021bea3c;

extern Unk021da104 *data_ov003_021da104;
extern u8 data_usa_ov000_021b0788[];
extern u8 data_usa_ov000_021b0790[];

// Declared here until the code that defines them is decompiled.

u32 func_ov003_021be610(void (*param_0)(u32, u32), void *param_1, u32 param_2);
u32 func_ov003_021be708(void *param_0, void *param_1, u32 param_2);
u32 func_ov003_021be7b8(void);
u32 func_ov003_021be820(void);
u32 func_ov003_021be860(u8 *param_0, u8 *param_1, s32 param_2, u32 param_3);
s32 func_ov003_021be96c(u8 *param_0, s32 param_1);
u32 func_ov003_021be9b8(void);
void func_ov003_021bea3c(Unk021bea3c *param_0);
void func_ov003_021bee24(void);
void func_ov003_021beecc(void);
void func_ov003_021beef8(int param_1);
void func_ov003_021befa4(u32 param_0);
void func_ov003_021bf048(u32 param_0);
