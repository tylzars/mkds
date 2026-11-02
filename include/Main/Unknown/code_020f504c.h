#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

// Element of data_027e00cc[1]: 0x274 bytes (the size in data_0217bc34[1]), handled by func_020f5324 to
// func_020f5824 of this file, func_020f5d6c to func_020f5fb8, the state functions in data_0216c648 and
// func_020f1180 to func_020f14a0: the Unk020ec8bc part, the owner at 0x228, a vector at 0x22c, a counter at 0x238,
// the state machine of func_02046be8 at 0x23c, words at 0x250 and 0x254 and a Unk0210b7ec at 0x258.
typedef struct Unk020f5d6c {
    /* 000 */ Unk020ec8bc mUnk_000;
    /* 228 */ struct Unk020ee684 *mUnk_228;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ s32 mUnk_238;
    /* 23c */ Unk020e005c_080 mUnk_23c;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ Unk0210b7ec mUnk_258;
    /* 268 */ u8 mUnk_268[0xc];
} Unk020f5d6c;

// Element of data_027e00cc[2]: 0x134 bytes (the size in data_0217bc34[2]), handled by func_020f50b4 to
// func_020f5240: the Unk020f2df0 part and a word at 0x130.
typedef struct Unk020f5240 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
} Unk020f5240;

void func_020f504c(Unk020eda5c *a, Unk020f40dc *b);
void func_020f50b4(Unk020f5240 *a);
void *func_020f5108(void *a, Unk020f5240 *b, void *c);
void func_020f518c(Unk020f5240 *a);
s32 func_020f5240(Unk020eda5c *a, Unk020f5240 *b);
BOOL func_020f5324(void *a0, s32 b);
void func_020f53d0(Unk020f5d6c *a);
void *func_020f5550(void *a, Unk020f5d6c *b, void *c);
void func_020f5614(void *a0, s32 b, void *c0);
void func_020f56d0(Unk020f5d6c *a);
void func_020f572c(Unk020f5d6c *a);
void func_020f5824(Unk020f5d6c *a);
