#pragma once

#include "types.h"
#include "Main/Unknown/code_020dc474.h"
#include "Main/Unknown/code_020dd8b0.h"
#include "Main/Unknown/code_020e66e4.h"

// Object of func_020de000: a vector at 0x04, a vector at 0x1c, a word at 0x68, the Wanwan it was set up from at
// 0xa0, an Unk020dd950 at 0xa4 and a word at 0xf4.
typedef struct Unk020de000 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ u8 mUnk_28[0x40];
    /* 68 */ s32 mUnk_68;
    /* 6c */ u8 mUnk_6c[0x34];
    /* a0 */ Wanwan *mUnk_a0;
    /* a4 */ Unk020dd950 mUnk_a4;
    /* f0 */ u8 mUnk_f0[4];
    /* f4 */ BOOL mUnk_f4;
} Unk020de000;

extern const u16 data_021583d4;

void func_020de184(Unk020de000 *o);
void CreateWanwanChainAndWanwanKui(void);
void func_020de000(Unk020de000 *o, void *a, Wanwan *p);
void func_020ddb44(Unk020dd950 *a, Vec3 *b, Vec3 *v);
void func_020ddaa0(Unk020dd950 *a, Unk020e6488 *b, s32 c, u16 e);
void func_020dda38(Unk020dd950 *a, Unk020e6488 *b, Vec3 *c, s32 d, u16 e);
