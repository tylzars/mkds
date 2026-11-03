#pragma once

#include "types.h"

typedef struct Unk020487fc Unk020487fc;

// Object func_0203bf04 reads: the first 0x30 bytes and the 0xdcc bytes from 0x30.
typedef struct Unk0203bf04_a {
    /* 000 */ u8 mUnk_000[0x30];
    /* 030 */ u8 mUnk_030[0xdcc];
} Unk0203bf04_a;

// Object func_0203bf04 fills: a word at 0x08, two bits at 0x2f, 0x200 bytes at 0x30 and 0xdcc bytes from 0x230.
typedef struct Unk0203bf04_b {
    /* 000 */ u8 mUnk_000[0x8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u8 mUnk_00c[0x23];
    /* 02f */ union {
        u8 mUnk_02f;
        struct {
            u8 mUnk_02f_0 : 2;
        };
    };
    /* 030 */ u8 mUnk_030[0x200];
    /* 230 */ u8 mUnk_230[0xdcc];
} Unk0203bf04_b;

// Three words that func_0203bfc4 fills.
typedef struct Unk0203bfc4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0203bfc4;

void func_0203be88(u8 *a, u32 b, u32 c);
void func_0203bea4(u8 *a, u32 b, u32 c);
void func_0203bec0(u8 *a);
u8 *func_0203bedc(void *a);
void func_0203bf04(Unk0203bf04_a *a, Unk0203bf04_b *b);
void func_0203bfc4(Unk0203bfc4 *a);
void func_0203bfec(s32 *a);
u32 func_0203c018(Unk020487fc *a);
void func_0203c060(s32 a);
