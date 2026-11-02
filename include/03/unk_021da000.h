#pragma once

#include "03/code_021be610.h"
#include "03/code_021d1fd0.h"
#include "03/code_021c209c.h"
#include "03/code_021c4ad4.h"
#include "03/code_021d079c.h"
#include "types.h"
#include "03/code_021d1770.h" // Unk021d1770
#include "03/code_021d1d88.h"
#include "03/code_021d1da8.h"
#include "code_02003024.h" // Unk02003a6c
#include "03/code_021bf098.h"
#include "03/code_021c2530.h"
#include "03/code_021c25e0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"

// Object behind data_ov003_021da214.
typedef struct Unk021da214 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ u16 *mUnk_08;
    /* 0c */ void *mUnk_0c[2];
    /* 14 */ Unk021d2188 *mUnk_14;
    /* 18 */ Unk021da104_04 *mUnk_18[7];
    /* 34 */ Unk021da104_04 *mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41;
    /* 42 */ u8 mUnk_42;
    /* 43 */ u8 mUnk_43;
    /* 44 */ u8 mUnk_44;
    /* 45 */ u8 mUnk_45;
    /* 46 */ u8 mUnk_46;
    /* 47 */ u8 mUnk_47;
} Unk021da214;

// Objects whose layout isn't known yet.
typedef struct Unk021da280 Unk021da280;
typedef struct Unk021cf260 Unk021cf260;
extern Unk021da108 *data_ov003_021da108;
extern u8 data_ov003_021da10c;
extern u8 data_ov003_021da150[];
// 8-byte object returned by func_ov003_021d1c18: bits 0-7 and bits 16-24 of the word at 0x00 are two coordinates.
typedef struct Unk021bf920 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021bf920;

// Object behind data_ov003_021da158.
typedef struct Unk021da158 {
    /* 00 */ Unk021bf920 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s8 mUnk_08;
} Unk021da158;

extern Unk021da158 *data_ov003_021da158;

// Object behind data_ov003_021da15c.
typedef struct Unk021da15c {
    /* 000 */ void *mUnk_000[3][4];
    /* 030 */ Unk021bf920 *mUnk_030[0x2f];
    /* 0ec */ Unk021bf920 *mUnk_0ec[4];
    /* 0fc */ Unk021d1770 *mUnk_0fc[2];
    /* 104 */ void *mUnk_104[4];
    /* 114 */ Unk021d1770 *mUnk_114;
    /* 118 */ Unk021d34e0 *mUnk_118;
    /* 11c */ u8 mUnk_11c;
    /* 11d */ u8 mUnk_11d;
    /* 11e */ s8 mUnk_11e;
    /* 11f */ s8 mUnk_11f;
    /* 120 */ s8 mUnk_120;
    /* 121 */ s8 mUnk_121;
    /* 122 */ u8 mUnk_122;
    /* 123 */ u8 mUnk_123;
    /* 124 */ u8 mUnk_124;
    /* 125 */ u8 mUnk_125;
} Unk021da15c;

extern Unk021da15c *data_ov003_021da15c;
struct Unk021da160;
extern struct Unk021da160 *data_ov003_021da160;
extern u8 data_ov003_021da164[];
struct Unk021b94c4;
extern struct Unk021b94c4 *data_ov003_021da168;
extern u8 data_ov003_021da16c[];
extern u8 data_ov003_021da170[];
extern void *data_ov003_021da174;
extern u8 data_ov003_021da1a8;
extern u8 data_ov003_021da1b0[];
extern u8 data_ov003_021da1bc[];
extern u8 data_ov003_021da1c0;
extern u8 data_ov003_021da1c4;
extern u8 data_ov003_021da1c8[];
extern u8 data_ov003_021da1cc;
extern u8 data_ov003_021da1d4;
extern u8 data_ov003_021da1d8;
extern u8 data_ov003_021da1dc;
extern u8 data_ov003_021da1e8[];
extern u8 data_ov003_021da1f0[];
struct Unk021c5c68State;
extern struct Unk021c5c68State *data_ov003_021da1f4;
struct Unk021da1f8;
extern struct Unk021da1f8 *data_ov003_021da1f8;
struct Unk021da1fc;
extern struct Unk021da1fc *data_ov003_021da1fc;
extern u8 data_ov003_021da200[];
extern u8 data_ov003_021da204[];
extern u8 data_ov003_021da208[];
extern u8 data_ov003_021da20c[];
extern u8 data_ov003_021da210[];
extern Unk021da214 *data_ov003_021da214;
extern u8 data_ov003_021da218;
extern u8 data_ov003_021da21c;
extern u8 data_ov003_021da220[];
extern u8 data_ov003_021da224;
extern u8 data_ov003_021da228[];
extern u16 data_ov003_021da22c;
extern u8 data_ov003_021da230[];
struct Unk021da234;
extern struct Unk021da234 *data_ov003_021da234;
extern s8 data_ov003_021da238;
extern s8 data_ov003_021da23c;
extern u8 data_ov003_021da240[];
extern u8 *data_ov003_021da244;
extern u8 data_ov003_021da248;
extern u8 data_ov003_021da24c[];
extern u8 data_ov003_021da250;
extern u8 data_ov003_021da254;
extern u8 data_ov003_021da258;
struct Unk021da25c;
extern struct Unk021da25c *data_ov003_021da25c;
extern u8 data_ov003_021da260[];
struct Unk021cca74;
extern struct Unk021cca74 *data_ov003_021da268;
struct Unk021da26c;
extern struct Unk021da26c *data_ov003_021da26c;
struct Unk021cd5e0;
extern struct Unk021cd5e0 *data_ov003_021da270;
struct Unk021cdc4c;
extern struct Unk021cdc4c *data_ov003_021da274;
extern void *data_ov003_021da278;
struct Unk021ce0f0;
extern struct Unk021ce0f0 *data_ov003_021da27c;
extern Unk021da280 *data_ov003_021da280;
// Object behind data_ov003_021da284: func_ov003_021ceaf8 passes 0x00 to func_ov003_021d1770 and reads the byte at
// 0x1e; func_ov003_021cef80 reads the byte at 0x1b.
typedef struct Unk021da284 {
    /* 00 */ Unk021d1770 *mUnk_00;
    /* 04 */ Unk021d1770 *mUnk_04;
    /* 08 */ Unk021d1770 *mUnk_08[2];
    /* 10 */ void *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ s8 mUnk_1a;
    /* 1b */ s8 mUnk_1b;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
} Unk021da284;

extern Unk021da284 *data_ov003_021da284;
extern Unk021cf260 *data_ov003_021da288;
extern u16 *data_ov003_021da28c[];
extern UnkFunc *data_ov003_021da2a4;
typedef struct Unk021da2ac_100 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x40];
} Unk021da2ac_100;

// Object behind data_ov003_021da2ac.
typedef struct Unk021da2ac {
    /* 000 */ u8 pad_000[0x100];
    /* 100 */ Unk021da2ac_100 mUnk_100[2];
    /* 188 */ u8 pad_188[0x78];
    /* 200 */ u16 mUnk_200;
    /* 202 */ u16 mUnk_202;
    /* 204 */ u32 mUnk_204;
    /* 208 */ u32 mUnk_208[16];
    /* 248 */ u8 pad_248[0x400];
    /* 648 */ u16 mUnk_648;
    /* 64a */ u16 mUnk_64a;
    /* 64c */ u8 mUnk_64c[0x404];
    /* a50 */ u8 mUnk_a50[0x40];
    /* a90 */ u8 mUnk_a90;
    /* a91 */ u8 mUnk_a91;
    /* a92 */ u8 mUnk_a92;
    /* a93 */ u8 mUnk_a93;
    /* a94 */ u32 mUnk_a94;
    /* a98 */ u32 mUnk_a98;
    /* a9c */ u32 mUnk_a9c;
    /* aa0 */ u8 *mUnk_aa0[2];
    /* aa8 */ u8 mUnk_aa8[4];
    /* aac */ u8 mUnk_aac;
    /* aad */ u8 mUnk_aad[3];
    /* ab0 */ Unk021da2ac_100 *mUnk_ab0;
    /* ab4 */ u32 mUnk_ab4;
    /* ab8 */ u32 mUnk_ab8;
    /* abc */ u32 mUnk_abc;
    /* ac0 */ u32 mUnk_ac0;
    /* ac4 */ u32 mUnk_ac4;
    /* ac8 */ u32 mUnk_ac8;
    /* acc */ u8 mUnk_acc;
    /* acd */ u8 mUnk_acd[0x33];
    /* b00 */ u8 mUnk_b00[4];
} Unk021da2ac;

extern Unk021da2ac *data_ov003_021da2ac;
// Object of 0xe8 bytes: a pointer at 0x00, 32 pointers from 0x04, the list of them at 0x84, an Unk02003a6c at 0x88
// and a halfword at 0xe4.
typedef struct Unk021da2b0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04[0x20];
    /* 84 */ Unk021d1d88 *mUnk_84;
    /* 88 */ Unk02003a6c mUnk_88;
    /* e4 */ u16 mUnk_e4;
    /* e6 */ u8 mUnk_e6[2];
} Unk021da2b0;

extern Unk021da2b0 *data_ov003_021da2b0;
// Two objects of 0x228 bytes: 32 objects from 0x000, two list heads at 0x200 and 0x210, a pointer at 0x220 and the
// list of the free objects at 0x224.
typedef struct Unk021da2b4 {
    /* 000 */ Unk021d1770 mUnk_000[0x20];
    /* 200 */ Unk021d1770 mUnk_200;
    /* 210 */ Unk021d1770 mUnk_210;
    /* 220 */ void *mUnk_220;
    /* 224 */ Unk021d1d88 *mUnk_224;
} Unk021da2b4;

extern Unk021da2b4 *data_ov003_021da2b4;
// Eight-byte records at the start of a resource: a number at 0x00 and the offset of a table at 0x04.
typedef struct Unk021da2b8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021da2b8;

extern Unk021da2b8 *data_ov003_021da2b8[];
extern Unk021d1da8 *data_ov003_021da2c0;
extern u8 data_ov003_021da2c4[];
extern u8 data_ov003_021da2cc;
extern u8 data_ov003_021da2d0;
extern Unk021da2d4Input *data_ov003_021da2d4;
extern u8 data_ov003_021da2d8[];
extern UnkFunc *data_ov003_021da2e8;
extern u32 data_ov003_021da2ec;
struct Unk021d2fa0;
extern struct Unk021d2fa0 *data_ov003_021da2f0;
struct Unk021d31b0;
extern struct Unk021d31b0 *data_ov003_021da2f4;
extern u32 data_ov003_021da2f8[];
struct Unk021d34c8;
extern struct Unk021d34c8 *data_ov003_021da32c;
