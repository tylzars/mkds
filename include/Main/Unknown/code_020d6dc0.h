#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

typedef struct Unk020d84e4 Unk020d84e4;
typedef struct Unk020d849c Unk020d849c;

struct Unk020fa294;

// Four words: func_020d7b88 writes them.
typedef struct Unk020d7b88 {
    /* 00 */ s32 mUnk_00[4];
} Unk020d7b88;

void func_020d7d4c(Unk020d84e4 *m, struct Unk020fa294 *b, s32 c, s32 d);
void func_020d7d18(Unk020d849c *p, s32 a, Vec3 **b, s32 c);
BOOL func_020d7c84(Unk020d849c *p, s32 a, Vec3 **b);
void func_020d7bec(Unk02012f58 *a);
void func_020d7b88(Vec3 *p, void *q);
void func_020d7b34(s32 a, Unk020d7b88 *b);
void func_020d7a3c(void *p, s32 b, void *q);
void func_020d79b0(void *p, u32 b, void *q);
void func_020d7938(Unk020d7b88 *a, Unk020d7b88 *b, Unk020d7b88 *c);
void func_020d788c(Unk020d7b88 *a, s32 b, Unk020d7b88 *c);
void func_020d77e0(void *m, s32 b, void *o);
void func_020d7734(void *m, s32 b, void *o);
void func_020d76a8(Unk020d7b88 *a, s32 b, Unk020d7b88 *c);
void func_020d759c(void *p, void *q, void *r, s32 d);
void func_020d73f0(Unk020d7b88 *a, Unk020d7b88 *b);
void func_020d720c(Vec3 *a, u32 *m);
s32 Vec3NormalizeAndGetLengthOrZero(Vec3 *a, Vec3 *b);
s32 Vec3NormalizeXZAndGetLengthOrZero(Vec3 *a, Vec3 *b);
void func_020d6f20(Vec3 *a, s32 b, Vec3 *c);
void func_020d6df0(Vec3 *a, s32 *b);
u32 func_020d6dc0(s32 a, s32 b, s32 c, s32 d);
