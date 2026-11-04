#pragma once

#include "types.h"

typedef struct Unk020c06c4 Unk020c06c4;

#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"

// Object behind data_0217b49c.
typedef struct Unk0217b49c {
    /* 00 */ Unk020ae7c4 mUnk_00;
    /* 1c */ Unk020ae7c4 mUnk_1c[5];
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk0217b49c;

// Argument of func_020d029c and func_020d06b8: 0x80 elements of 8 bytes, then a halfword.
typedef struct Unk020d029c {
    /* 000 */ Unk020224e0_o mUnk_000[0x80];
    /* 400 */ u16 mUnk_400;
} Unk020d029c;

void func_020cffd0(Unk020c06c4 *a);
void func_020cffec(void);
s32 func_020d011c(void);
void func_020d0134(void *a);
void func_020d0150(void);
void func_020d026c(void);
s32 func_020d0280(void);
void func_020d029c(Unk020d029c *a, s32 b, s32 d, Unk020ae7c4 *e, s32 f);
void func_020d06b8(Unk020d029c *a);
void func_020d0a18(void);
u32 func_020d0bbc(void);
void func_020d0bd0(void);
void func_020d0cbc(void *a);
void func_020d0cd8(void);
void func_020d0e28(void);
