#pragma once

#include "types.h"
#include "00/code_021a377c.h"

typedef struct Unk021a3a18 {
    /* 000 */ u32 mUnk_00;
    /* 004 */ u8 mUnk_04[0x80];
    /* 084 */ s8 mUnk_84[0x18];
    /* 09c */ void (*mUnk_9c)(s8 a, u8 *b, u32 c);
    /* 0a0 */ void (*mUnk_a0)(u32 a, u32 b);
    /* 0a4 */ void (*mUnk_a4)(s8 *a, s32 b, u32 c);
    /* 0a8 */ s32 mUnk_a8;
    /* 0ac */ u32 mUnk_ac;
    /* 0b0 */ u32 mUnk_b0;
    /* 0b4 */ u32 mUnk_b4;
    /* 0b8 */ s32 mUnk_b8;
    /* 0bc */ s32 mUnk_bc;
    /* 0c0 */ u32 mUnk_c0;
    /* 0c4 */ u8 pad_c4[4];
    /* 0c8 */ s32 mUnk_c8;
    /* 0cc */ u8 mUnk_cc[8];
    /* 0d4 */ void (*mUnk_d4)(s8 *a, s32 b, void *c);
    /* 0d8 */ u8 pad_d8[0x2c];
    /* 104 */ u32 mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10a */ u8 pad_10a[2];
    /* 10c */ u32 mUnk_10c;
} Unk021a3a18;

// A buffer and its length, which follows the 0x800 bytes of the buffer.
typedef struct Unk021a4480 {
    /* 000 */ u8 mUnk_000[0x800];
    /* 800 */ s32 mUnk_800;
} Unk021a4480;

void func_ov000_021a39d8(Unk021b5df4 *a, u16 b, u32 c, u32 d);
void func_ov000_021a3a18(Unk021a3a18 *a, s32 b);
void func_ov000_021a3bbc(Unk021a3a18 *a);
void func_ov000_021a3c14(Unk021a3a18 *a, s8 *b, s32 c, void *d);
