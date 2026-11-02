#pragma once

#include "types.h"
#include "00/code_021a4654.h"

// List of values and their count; filled by the callback at mUnk_094 of an Unk021a4a08.
typedef struct Unk021a3fc8 {
    /* 000 */ u8 mUnk_000[0x100];
    /* 100 */ s32 mUnk_100;
} Unk021a3fc8;

typedef void (*Unk021a4a08Func88)(u8 a, Unk021a471c *b, void *c);
typedef void (*Unk021a4a08Func8c)(u8 a, s32 b, Unk021a471c *c, void *d);
typedef void (*Unk021a4a08Func94)(s32 a, Unk021a3fc8 *b, void *c);
typedef s32 (*Unk021a4a08Func98)(s32 a, void *b);
typedef void (*Unk021a4a08Func9c)(s32 a, const u8 *b, void *c);
typedef void (*Unk021a4a08Funca8)(u32 a, u16 b, void *c);

// 0x110 bytes; func_ov000_021a4a08 fills it, data_ov000_021b426c points at the one in use.
typedef struct Unk021a4a08 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x40];
    /* 044 */ u8 mUnk_044[0x40];
    /* 084 */ u8 mUnk_084[4];
    /* 088 */ Unk021a4a08Func88 mUnk_088;
    /* 08c */ Unk021a4a08Func8c mUnk_08c;
    /* 090 */ Unk021a4a08Func8c mUnk_090;
    /* 094 */ Unk021a4a08Func94 mUnk_094;
    /* 098 */ Unk021a4a08Func98 mUnk_098;
    /* 09c */ Unk021a4a08Func9c mUnk_09c;
    /* 0a0 */ u32 mUnk_0a0;
    /* 0a4 */ u32 mUnk_0a4;
    /* 0a8 */ Unk021a4a08Funca8 mUnk_0a8;
    /* 0ac */ u32 mUnk_0ac;
    /* 0b0 */ u32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ Unk021a4654 mUnk_0cc;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8[10];
    /* 100 */ s32 mUnk_100;
    /* 104 */ u32 mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10c */ void *mUnk_10c;
} Unk021a4a08;

extern Unk021a4a08 data_ov000_021b4278;
extern s8 data_ov000_021b5e10[];
extern s8 data_ov000_021b5e50[];

s32 func_ov000_021a4a08(Unk021a4a08 **a, s32 b, s32 c, const u8 *d, const u8 *e, s32 f, s32 g, Unk021a4a08Func88 h,
                        Unk021a4a08Func8c i, Unk021a4a08Func8c j, Unk021a4a08Func94 k, Unk021a4a08Func98 l,
                        Unk021a4a08Func9c m, void *n);
