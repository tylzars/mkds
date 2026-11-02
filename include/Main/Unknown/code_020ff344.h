#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // Unk020f2df0
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020ffdd4.h"

// Object of func_020ff97c: 0x144 bytes.
typedef struct Unk020ff97c {
    /* 000 */ Unk020e71a0 mUnk_00;
    /* 0a0 */ Unk02146dfc mUnk_a0;
    /* 0c4 */ u8 mUnk_c4[0x24];
    /* 0e8 */ Vec3 mUnk_e8;
    /* 0f4 */ Vec3 mUnk_f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ u8 mUnk_140[4];
} Unk020ff97c;

// Element of data_027e00cc[7]: 0x144 bytes (the size in data_0217bc34[7]), handled by the functions of this file
// from func_020ff344 to func_020ff910 and by func_020ff1d8, func_020ff25c and func_020ff2b0.
typedef struct Unk020ff438 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ Vec3 mUnk_130;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ Unk021052fc *mUnk_140;
} Unk020ff438;

void func_020ff344(Unk020ff438 *e);
s32 func_020ff3c4(Unk020ff438 *e);
void func_020ff438(Unk020ff438 *e);
u32 func_020ff538(Unk020eda5c *a, Unk020ff438 *e);
void func_020ff638(Unk020eda5c *a, Unk020ff438 *e);
void func_020ff654(Unk020ff438 *e);
void func_020ff67c(Unk020ff438 *e);
void func_020ff6d8(Unk020ff438 *e, Unk02012f58 *out);
void func_020ff910(Unk020ff438 *e, Unk02012f58 *out);
void func_020ff97c(Unk020ff97c *e);
BOOL func_020ffabc(u32 a);
Unk02100004 *func_020ffacc(void);
void func_020ffb1c(Unk020ffb1c *a, struct Unk020fa294 *b);
void CreateDram(void);
