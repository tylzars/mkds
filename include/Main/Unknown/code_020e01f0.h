#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

// Object holding a pointer at 0x0 and two vectors.
typedef struct Unk020e04b0 {
    /* 00 */ Unk020e005c *mUnk_00;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
} Unk020e04b0;

// Object holding a pointer at 0x0 and a vector at 0x4.
typedef struct Unk020e0448 {
    /* 00 */ Unk020e3ef4 *mUnk_00;
    /* 04 */ Vec3 mUnk_04;
} Unk020e0448;

void func_020e01f0(void *a0, Unk020e005c *a1);
void *func_020e0340(void);
void *func_020e039c(void);
void *func_020e03f8(void);
s32 func_020e0448(Unk020e0448 *a);
BOOL func_020e04b0(Unk020e04b0 *a, Vec3 *b, Vec3 *c);
void func_020e0538(Unk020e04b0 *a, Vec3 *b);
void func_020e0584(Unk020e005c *a, Vec3 *b, Vec3 *c, Unk020e04b0 *d);
