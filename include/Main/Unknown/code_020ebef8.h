#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// First argument of func_020ebef8.
typedef struct Unk020ebef8 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ Vec3 mUnk_0a0;
    /* 0ac */ u16 mUnk_0ac;
    /* 0ae */ u16 mUnk_0ae;
    /* 0b0 */ Vec3 mUnk_0b0;
    /* 0bc */ Vec3 mUnk_0bc;
    /* 0c8 */ u16 mUnk_0c8;
    /* 0ca */ u8 mUnk_0ca[2];
    /* 0cc */ Vec3 mUnk_0cc;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ u16 mUnk_0f0;
    /* 0f2 */ u8 mUnk_0f2[2];
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ Vec3 mUnk_100;
    /* 10c */ u16 mUnk_10c;
    /* 10e */ u16 mUnk_10e;
    /* 110 */ u16 mUnk_110;
    /* 112 */ u8 mUnk_112[2];
    /* 114 */ u8 mUnk_114[4];
} Unk020ebef8;

extern Unk020ebef8 *data_0217bbf0;

// Argument of func_020ec194.
typedef struct Unk020ec194 {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ Vec3 mUnk_010;
    /* 01c */ u8 mUnk_01c[0xc];
    /* 028 */ u8 mUnk_028[0x88];
    /* 0b0 */ Vec3 mUnk_0b0;
    /* 0bc */ u8 mUnk_0bc[0xc];
    /* 0c8 */ u16 mUnk_0c8;
} Unk020ec194;

void func_020ebef8(Unk020ebef8 *c, Vec3 *d);
void func_020ec194(Unk020ec194 *a);
