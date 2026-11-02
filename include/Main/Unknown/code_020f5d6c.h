#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f504c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

// Element of data_027e00cc[0]: 0x188 bytes (the size in data_0217bc34[0]), handled by func_020f5ffc to
// func_020f6220: the Unk020f1d70 part, a word at 0x168 and a Unk0210b7ec at 0x16c.
typedef struct Unk020f6150 {
    /* 000 */ Unk020f1d70 mUnk_000;
    /* 168 */ s32 mUnk_168;
    /* 16c */ Unk0210b7ec mUnk_16c;
    /* 17c */ u8 mUnk_17c[0xc];
} Unk020f6150;

s32 func_020f5d6c(Unk020eda5c *a, Unk020f5d6c *b);
void func_020f5f7c(Unk020f5d6c *a, Vec3 *b, Vec3 *c);
void func_020f5fb8(void *a0, s32 b);
void func_020f5ffc(Unk020f6150 *a);
void *func_020f6038(void *a, Unk020f6150 *b, void *c);
void func_020f60d0(Unk020f6150 *a);
BOOL func_020f6150(Unk020eda5c *a, Unk020f6150 *b);
void func_020f6220(void *a0, s32 b);
void func_020f6264(Unk020eda5c *a, Unk020f40dc *b);
void func_020f62b0(Unk020eda5c *a, Unk020f40dc *b);
void func_020f6388(Unk020f41c4_A *a, Vec3 *b, Vec3 *c);
void func_020f63cc(Unk020f41c4_A *a);
void func_020f65c4(Unk020f41c4_A *a);
void func_020f6630(void *a0, s32 b, Vec3 *c, Vec3 *d, Vec3 *e);
void func_020f6830(Unk020f41c4_A *a, Vec3 *b, Vec3 *c);
void func_020f68b0(Unk020f41c4_A *a);
void func_020f6a6c(Unk020f41c4_A *a, void *b);
