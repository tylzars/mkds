#pragma once

#include "types.h"
#include "Main/Unknown/code_0209219c.h"

// Object func_0209297c reads: a halfword at 0x74 and a vector at 0x80.
typedef struct Unk0209297c {
    /* 00 */ u8 mUnk_00[0x74];
    /* 74 */ u16 mUnk_74;
    /* 76 */ u8 mUnk_76[10];
    /* 80 */ Vec3 mUnk_80;
} Unk0209297c;

void func_020924d8(void *a, Unk0209219c *b);
void func_0209280c(void *a, Unk0209219c *b);
void func_02092928(void *a);
void CreateBasabasa(void *a);
u8 func_0209297c(Unk0209219c *a, Unk0209297c *b, void *c, u8 *d);
