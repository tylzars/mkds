#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // Unk020f2df0
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"

struct Unk0208e490;

// Element of gItemPools[9]: 0x1a4 bytes (the size in gItemKinds[9]), handled by the functions of this file
// and of code_020fd264.c, code_020fe16c.c and code_020fe268.c.
typedef struct Unk020fdae8 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ struct Unk0208e490 *mUnk_138;
    /* 13c */ u8 mUnk_13c[0x30];
    /* 16c */ BOOL mUnk_16c;
    /* 170 */ s32 mUnk_170;
    /* 174 */ s32 mUnk_174;
    /* 178 */ u16 mUnk_178;
    /* 17a */ u8 mUnk_17a[2];
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ u8 mUnk_184[4];
    /* 188 */ s32 mUnk_188;
    /* 18c */ u8 mUnk_18c[6];
    /* 192 */ u16 mUnk_192;
    /* 194 */ u16 mUnk_194;
    /* 196 */ u16 mUnk_196;
    /* 198 */ Unk021052fc *mUnk_198;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ BOOL mUnk_1a0;
} Unk020fdae8;

void func_020fd83c(Unk020fdae8 *e);
int func_020fd8b0(Unk020fdae8 *e);
void func_020fd938(Unk020fdae8 *e, Vec3 *a, Unk020e6488 *b);
void func_020fd9d8(Unk020fdae8 *e);
void *func_020fda50(void *a, Unk020fdae8 *b, void *c);
void func_020fdae8(Unk020fdae8 *e);
void func_020fdc08(Unk020fdae8 *e, Unk020fdae8 *b, Unk021052fc *c);
void func_020fdd78(Unk020fdae8 *e);
void func_020fde18(Unk020fdae8 *e);
void func_020fdf64(Unk020fdae8 *e);
void func_020fe00c(Unk020fdae8 *e);
void func_020fe120(Unk020fdae8 *e);
