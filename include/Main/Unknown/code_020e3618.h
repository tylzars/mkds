#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e0680.h"

// Block of eleven words.
typedef struct Unk020e039c {
    /* 00 */ u32 mUnk_00[11];
} Unk020e039c;

// Object func_020e38a0 fills.
typedef struct Unk020e38a0 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ Unk020e38a0_28 mUnk_0a0;
    /* 0c4 */ Unk020e38a0_28 mUnk_0c4;
    /* 0e8 */ Vec3 mUnk_0e8;
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ u8 mUnk_13c[0x8];
    /* 144 */ u16 mUnk_144;
    /* 146 */ u16 mUnk_146;
    /* 148 */ u16 mUnk_148;
    /* 14a */ u16 mUnk_14a;
    /* 14c */ u16 mUnk_14c;
    /* 14e */ u16 mUnk_14e;
    /* 150 */ u16 mUnk_150;
    /* 152 */ u8 mUnk_152[0x2];
    /* 154 */ s32 mUnk_154;
} Unk020e38a0;

BOOL func_020e3af0(u32 a);
void func_020e3a7c(void);
void func_020e38a0(Unk020e38a0 *a, struct Unk020fa294 *b);
void *func_020e3850(void);
void *func_020e37f4(void);
void *func_020e3798(void);
void *func_020e373c(void);
void func_020e3724(void);
void func_020e3618(s32 a, Unk020e1e98 *b, s32 c, u16 d);
