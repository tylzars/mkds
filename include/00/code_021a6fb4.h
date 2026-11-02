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

s32 func_ov000_021a6fb4(Unk021a6fa8 *a, Unk021a7064 *b);
s32 func_ov000_021a6fc0(Unk021a7154 *d, Unk021a7064 *e);
s32 func_ov000_021a7008(Unk021a7154 *b, Unk021a7064 *c);
void func_ov000_021a7048(Unk021a7064 *a);
Unk021a7064 *func_ov000_021a7064(Unk021a7064Func b, Unk021a6fa8 *c, s32 d);
Unk021a7064 *func_ov000_021a7088(s32 a);
s32 func_ov000_021a70b0(void);
s32 func_ov000_021a70ec(s32 e);
u8 *func_ov000_021a7154(u8 *b, Unk021a7154 *c, Unk021a72a4 *d);
u8 *func_ov000_021a71a4(u8 *a, Unk021a71a4 *b, s32 c);
u8 *func_ov000_021a71c0(Unk021a6fa8 *d, Unk021b49b8 *e);
int func_ov000_021a72a4(Unk021a72a4 *a);
