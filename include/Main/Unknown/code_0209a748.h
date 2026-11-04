#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Block of eight words at 0xb0 and 0xd0 of Unk0209a7dc: the u16 at 0x00 grows by 0x18 each step, 0x14 and 0x1c move
// 0x10 and 0x18 towards zero.
typedef struct Unk0209a7dc_b0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0209a7dc_b0;

// Object of func_0209a7dc, one state per value of mUnk_114.
typedef struct Unk0209a7dc {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u16 mUnk_0a2;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ Unk0209a7dc_b0 mUnk_0b0;
    /* 0d0 */ Unk0209a7dc_b0 mUnk_0d0;
    /* 0f0 */ Unk020e0144 mUnk_0f0;
    /* 114 */ s32 mUnk_114;
} Unk0209a7dc;

// Table of object pointers with a halfword count behind it.
typedef struct Unk0209af98 {
    /* 00 */ Unk0209a7dc **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209af98;

void *func_0209a748(void);
void *func_0209a768(void);
void func_0209a78c(void);
void func_0209a7dc(void *a, Unk0209a7dc *b);
s32 func_0209af64(s32 a, s32 b);
s16 func_0209af80(s32 a);
void func_0209af98(Unk0209af98 *p);
void func_0209b088(void *a, Unk0209a7dc *b);
unsigned int func_0209b1f8(unsigned int p0);
