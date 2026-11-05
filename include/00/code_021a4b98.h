#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_0200f790.h"

// Event the function at mUnk_227c is called with; built by func_ov000_021a586c.
typedef struct Unk021a586c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021a586c;

// 0xd0 bytes. Entry of the list at mUnk_2270 of an Unk021b5f50.
typedef struct Unk021b5f50_2270_0c {
    /* 00 */ u8 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ struct Unk021b5f50_2270_0c *mUnk_08;
    /* 0c */ struct Unk021b5f50_2270_0c *mUnk_0c;
    /* 10 */ u8 mUnk_10[0xc0];
} Unk021b5f50_2270_0c;

// Header of the list at mUnk_2270 of an Unk021b5f50: count, first and last entry, then the entries.
typedef struct Unk021b5f50_2270 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk021b5f50_2270_0c *mUnk_04;
    /* 08 */ Unk021b5f50_2270_0c *mUnk_08;
    /* 0c */ Unk021b5f50_2270_0c mUnk_0c[1];
} Unk021b5f50_2270;

// 0x2300 bytes; the word data_ov000_021b5f50 points to it.
typedef struct Unk021b5f50 {
    /* 0000 */ u8 mUnk_0000[0xf00];
    /* 0f00 */ u8 mUnk_0f00[0x600];
    /* 1500 */ u8 mUnk_1500[0xc40];
    /* 2140 */ u8 mUnk_2140[4];
    /* 2144 */ u8 mUnk_2144[6];
    /* 214a */ u16 mUnk_214a;
    /* 214c */ u8 mUnk_214c[0x22];
    /* 216e */ u16 mUnk_216e;
    /* 2170 */ u16 mUnk_2170;
    /* 2172 */ u8 mUnk_2172[0x8e];
    /* 2200 */ u8 mUnk_2200[0x50];
    /* 2250 */ u8 mUnk_2250;
    /* 2251 */ u8 mUnk_2251;
    /* 2252 */ u8 mUnk_2252[0xe];
    /* 2260 */ s32 mUnk_2260;
    /* 2264 */ u32 mUnk_2264;
    /* 2268 */ u16 mUnk_2268;
    /* 226a */ u8 mUnk_226a;
    /* 226b */ u8 mUnk_226b;
    /* 226c */ u32 mUnk_226c;
    /* 2270 */ Unk021b5f50_2270 *mUnk_2270;
    /* 2274 */ u32 mUnk_2274;
    /* 2278 */ u32 mUnk_2278;
    /* 227c */ void (*mUnk_227c)(Unk021a586c *);
    /* 2280 */ s16 mUnk_2280;
    /* 2282 */ u16 mUnk_2282;
    /* 2284 */ s32 mUnk_2284;
    /* 2288 */ Unk021438f0 mUnk_2288;
    /* 22c0 */ u8 mUnk_22c0[0xc];
    /* 22cc */ Unk0200fb08 mUnk_22cc;
    /* 22f8 */ u16 mUnk_22f8;
    /* 22fa */ u8 mUnk_22fa[6];
} Unk021b5f50;

// Event of the callbacks func_ov000_021a5088 and func_ov000_021a52b0 take.
typedef struct Unk021a5088 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u8 *mUnk_10[16];
    /* 50 */ u16 mUnk_50[16];
} Unk021a5088;

// Declared here until the code that defines them is decompiled.
void func_ov000_021a54b0(Unk021425e8 *event);

u32 func_ov000_021a4b98(u32 a);
u32 func_ov000_021a4bbc(u32 a);
void func_ov000_021a4bc4(Unk021425e8 *event);
void func_ov000_021a4e28(Unk021425e8 *event);
void func_ov000_021a4f10(Unk021425e8 *event);
void func_ov000_021a4fe0(Unk021425e8 *event);
void func_ov000_021a5088(Unk021a5088 *event);
void func_ov000_021a524c(Unk021425e8 *event);
void func_ov000_021a52b0(Unk021a5088 *event);
u32 func_ov000_021a5bfc(void);
s32 func_ov000_021a5db0(void);
s32 func_ov000_021a6024(void);
s32 func_ov000_021a61e4(void);
