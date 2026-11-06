#pragma once

#include "types.h"

// Starts at offset 0x24 of an entry of Unk0216f3dc; 0x44 bytes (see func_020062f4).
typedef struct Unk0200628c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 *mUnk_14;
    /* 18 */ u8 *mUnk_18;
    /* 1c */ u8 mUnk_1c[0x28];
} Unk0200628c;

// Entry of Unk0216f3dc; 0x68 bytes.
typedef struct Unk0216f3dc_68 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u8 *mUnk_20;
    /* 24 */ Unk0200628c mUnk_24;
} Unk0216f3dc_68;

struct Unk0216f3dc_9c;

// Block of 0x9c bytes; Unk0216f3dc holds three of them.
typedef struct Unk0216f3dc_9c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ void (*mUnk_10)(struct Unk0216f3dc_9c *);
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c[16];
    /* 5c */ void *mUnk_5c[16];
} Unk0216f3dc_9c;

// Object at data_0216f3dc; 0x854 bytes.
typedef struct Unk0216f3dc {
    /* 000 */ Unk0216f3dc_9c mUnk_000;
    /* 09c */ Unk0216f3dc_9c mUnk_09c;
    /* 138 */ Unk0216f3dc_9c mUnk_138;
    /* 1d4 */ Unk0216f3dc_68 mUnk_1d4[16];
} Unk0216f3dc;

s32 func_0200589c(Unk0216f3dc *a, u8 *b, s32 c);
s32 func_02005a30(Unk0216f3dc *a, u8 *b, s32 c);
s32 func_02005b18(Unk0216f3dc *a, s32 b, u8 *c, s32 d);
s32 func_02005b80(Unk0216f3dc *a, s32 b, u8 *c, s32 d);
s32 func_02005bec(Unk0216f3dc *a, s32 b, u8 *c, s32 d);
s32 func_02005cc8(Unk0216f3dc *a, s32 b, u8 *c, s32 d);
s32 func_02005d08(Unk0216f3dc *a, s32 b, u8 *c, s32 d);
s32 func_02005d4c(Unk0216f3dc *a, s32 b, u8 *c, s32 d);
u32 func_02005dac(Unk0216f3dc *a, s32 b, const u8 *c, s32 d);
void func_02006144(Unk0216f3dc *a, s32 b, s32 c);
void func_020061d8(Unk0216f3dc *a, s32 b, s32 c, u32 d);
BOOL func_0200628c(Unk0200628c *a, s32 b, const u8 *c);
s32 func_020062f4(Unk0200628c *a);
