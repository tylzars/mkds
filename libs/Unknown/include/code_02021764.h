#pragma once

#include "types.h"

typedef struct Unk020217b4_20 {
    /* 00 */ s16 mUnk_00[16];
    /* 20 */ u32 mUnk_20;
} Unk020217b4_20;

// 0x280 bytes.
typedef struct Unk020217b4 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u16 mUnk_008;
    /* 00a */ u16 mUnk_00a;
    /* 00c */ u8 mUnk_00c[0x14];
    /* 020 */ Unk020217b4_20 mUnk_020[16];
    /* 260 */ s16 mUnk_260[16];
} Unk020217b4;

extern Unk020217b4 *data_02174e00;

u32 func_02021764(u32 arg0);
void func_02021784(void);
void func_020217b4(Unk020217b4 *p);
u32 func_02021834(void);
s16 func_02021868(s32 a, s32 b);
u32 func_020218bc(void);
