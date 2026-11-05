#pragma once

#include "types.h"
#include "00/code_021ab6d4.h"
#include "00/code_021abca0.h"

typedef struct Unk021ab5e4 Unk021ab5e4;
typedef struct Unk021aa880 Unk021aa880;

// Object at 0x454 of Unk021a998c_0c.
typedef struct Unk021aaf38 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 *mUnk_10;
} Unk021aaf38;

// Object behind mUnk_7f4 of Unk021a998c_0c: a length and a pointer.
typedef struct Unk021a998c_0c_7f4 {
    /* 0 */ u32 mUnk_00;
    /* 4 */ u8 *mUnk_04;
} Unk021a998c_0c_7f4;

struct Unk021a998c_0c;
typedef u32 (*Unk021a998c_Func)(u32 a, struct Unk021a998c_0c *b, s32 c);

// Object at 0x0c of the argument of func_ov000_021a998c.
typedef struct Unk021a998c_0c {
    /* 000 */ Unk021ab5e4 *mUnk_000;
    /* 004 */ u8 mUnk_004;
    /* 005 */ u8 mUnk_005;
    /* 006 */ u16 mUnk_006;
    /* 008 */ u8 mUnk_008[0x20];
    /* 028 */ u8 mUnk_028[0x20];
    /* 048 */ u8 mUnk_048[0x48];
    /* 090 */ u8 *mUnk_090;
    /* 094 */ u8 *mUnk_094;
    /* 098 */ u8 *mUnk_098;
    /* 09c */ u8 mUnk_09c[0x104];
    /* 1a0 */ u8 mUnk_1a0[8];
    /* 1a8 */ u8 *mUnk_1a8;
    /* 1ac */ u8 *mUnk_1ac;
    /* 1b0 */ u8 *mUnk_1b0;
    /* 1b4 */ u8 mUnk_1b4[0x104];
    /* 2b8 */ u8 mUnk_2b8[8];
    /* 2c0 */ Unk021abca0 mUnk_2c0;
    /* 31c */ Unk021abca0 mUnk_31c;
    /* 378 */ Unk021ab728 mUnk_378;
    /* 3d0 */ Unk021ab728 mUnk_3d0;
    /* 428 */ u8 mUnk_428;
    /* 429 */ u8 mUnk_429;
    /* 42c */ s32 mUnk_42c;
    /* 430 */ s32 mUnk_430;
    /* 434 */ u8 *mUnk_434;
    /* 438 */ u8 *mUnk_438;
    /* 43c */ u8 mUnk_43c[0x14];
    /* 450 */ s32 mUnk_450;
    /* 454 */ Unk021aaf38 mUnk_454;
    /* 468 */ u8 mUnk_468[0x100];
    /* 568 */ u32 mUnk_568;
    /* 56c */ u8 mUnk_56c[8];
    /* 574 */ u32 mUnk_574;
    /* 578 */ u8 *mUnk_578;
    /* 57c */ s32 mUnk_57c;
    /* 580 */ u8 mUnk_580;
    /* 581 */ u8 mUnk_581;
    /* 582 */ u8 mUnk_582;
    /* 583 */ u8 mUnk_583;
    /* 584 */ s8 mUnk_584[0x100];
    /* 684 */ s8 mUnk_684[0x100];
    /* 784 */ s8 mUnk_784[0x50];
    /* 7d4 */ s8 *mUnk_7d4;
    /* 7d8 */ u8 *mUnk_7d8;
    /* 7dc */ s32 mUnk_7dc;
    /* 7e0 */ u32 mUnk_7e0;
    /* 7e4 */ Unk021a998c_Func mUnk_7e4;
    /* 7e8 */ u32 mUnk_7e8;
    /* 7ec */ u32 mUnk_7ec;
    /* 7f0 */ Unk021aa880 *mUnk_7f0;
    /* 7f4 */ Unk021a998c_0c_7f4 *mUnk_7f4;
    /* 7f8 */ u8 *mUnk_7f8;
    /* 7fc */ u32 mUnk_7fc;
    /* 800 */ u32 mUnk_800;
} Unk021a998c_0c;
