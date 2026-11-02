#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

struct Unk021a7064;

typedef s32 (*Unk021a7064Func)(struct Unk021a7064 *param_1);

// Entry of the queue behind data_ov000_021b5fdc.
typedef struct Unk021a7064 {
    /* 00 */ Unk021a7064Func mUnk_00;
    /* 04 */ Unk021a6fa8 *mUnk_04;
    /* 08 */ Unk0200eb90 *mUnk_08;
    /* 0c */ s8 mUnk_0c;
    /* 0d */ s8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 *mUnk_14;
    /* 18 */ u32 *mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0xc];
} Unk021a7064;

#include "00/unk_021b5000.h"
#include "00/unk_021b4000.h"

s32 func_ov000_021a6fb4(Unk021a6fa8 *param_1, Unk021a7064 *param_2);
s32 func_ov000_021a6fc0(Unk021a7154 *param_1, Unk021a7064 *param_2);
s32 func_ov000_021a7008(Unk021a7154 *param_1, Unk021a7064 *param_2);
void func_ov000_021a7048(Unk021a7064 *param_1);
Unk021a7064 *func_ov000_021a7064(Unk021a7064Func param_1, Unk021a6fa8 *param_2, s32 param_3);
Unk021a7064 *func_ov000_021a7088(s32 param_1);
s32 func_ov000_021a70b0(void);
s32 func_ov000_021a70ec(s32 param_1);
u8 *func_ov000_021a7154(u8 *param_1, Unk021a7154 *param_2, Unk021a72a4 *param_3);
u8 *func_ov000_021a71a4(u8 *param_1, Unk021a71a4 *param_2, s32 param_3);
u8 *func_ov000_021a71c0(Unk021a6fa8 *param_1, Unk021b49b8 *param_2);
int func_ov000_021a72a4(Unk021a72a4 *param_1);
