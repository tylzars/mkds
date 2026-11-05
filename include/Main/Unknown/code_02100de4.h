#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"

// Element of data_027e00cc[11]: 0x274 bytes (the size in data_0217bc34[11]), handled by the functions of
// this file and of code_021001ac.c, code_02100704.c and code_02100b84.c.
typedef struct Unk02101c84 {
    /* 000 */ Unk020f41c4_A mUnk_000;
    /* 12c */ u8 mUnk_12c[4];
    /* 130 */ u32 mUnk_130;
    /* 134 */ u8 mUnk_134[0x6];
    /* 13a */ u16 mUnk_13a;
    /* 13c */ u16 mUnk_13c;
    /* 13e */ u16 mUnk_13e;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ s32 mUnk_160;
    /* 164 */ s16 mUnk_164;
    /* 166 */ u8 mUnk_166[0x2];
    /* 168 */ Kart *mUnk_168;
    /* 16c */ s32 mUnk_16c;
    /* 170 */ s32 mUnk_170;
    /* 174 */ s32 mUnk_174;
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ Vec3 mUnk_184;
    /* 190 */ Vec3 mUnk_190;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ s32 mUnk_1a0;
    /* 1a4 */ Unk020f3fa8 mUnk_1a4;
    /* 248 */ s32 mUnk_248;
    /* 24c */ s32 mUnk_24c;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ s32 mUnk_258;
    /* 25c */ s32 mUnk_25c;
    /* 260 */ s32 mUnk_260;
    /* 264 */ u32 mUnk_264;
    /* 268 */ s32 mUnk_268;
    /* 26c */ s32 mUnk_26c;
    /* 270 */ s32 mUnk_270;
} Unk02101c84;

// First argument of func_02101d18: objects at 0x0c and 0x10.
typedef struct Unk02101d18 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ struct Unk020ee684 *mUnk_0c;
    /* 10 */ Kart *mUnk_10;
} Unk02101d18;

s32 func_02101014(Unk02101c84 *p);
void func_02101178(Unk02101c84 *p);
s32 func_021014a0(Unk02101c84 *p, s32 param_2, s32 param_3);
BOOL func_02101618(Unk02101c84 *p, s32 param_2, s32 param_3);
void func_0210174c(Unk02101c84 *p);
void func_021018a0(Unk02101c84 *p);
void func_02101964(Unk02101c84 *p, s32 param_2);
void func_0210140c(Unk02101c84 *p);
void func_021013bc(Unk02101c84 *p);
void func_0210136c(Unk02101c84 *p);
void func_02101d90(Unk02101c84 *p, s32 param_2);
void func_02101f7c(Unk02101c84 *p, s32 param_2);
void func_02100de4(Unk02101c84 *p);
void func_02101c84(Unk02101c84 *p);
void func_02101d18(Unk02101d18 *x, Unk02101c84 *p);
