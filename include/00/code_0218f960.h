#pragma once

#include "types.h"
#include "00/types_021937c0.h"
#include "00/types_021906e4.h"

struct Unk0218f960;

struct Unk0218f960;

// List at 0x428 of Unk0218f960_00: the object and the number of entries added to it.
typedef struct Unk0218f960_428 {
    /* 00 */ void *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0218f960_428;

// Object behind Unk0218f960.mUnk_00: func_ov000_0218f960 passes the address of 0x1f4 to func_ov000_02190b80 and
// func_ov000_02190b58, reads 0x198 and decrements 0x430.
typedef struct Unk0218f960_00 {
    /* 000 */ u8 mUnk_000[0x100];
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ u8 mUnk_110[0x1f];
    /* 12f */ s8 mUnk_12f[0x15];
    /* 144 */ u8 mUnk_144[0x33];
    /* 177 */ s8 mUnk_177[0x21];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u32 mUnk_19c;
    /* 1a0 */ u32 mUnk_1a0;
    /* 1a4 */ Unk02190ed4Cb mUnk_1a4[6];
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ u8 *mUnk_1dc;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ s32 mUnk_1e4;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ void *mUnk_1ec;
    /* 1f0 */ s32 mUnk_1f0;
    /* 1f4 */ Unk021906e4 mUnk_1f4;
    /* 204 */ s32 mUnk_204;
    /* 208 */ u32 mUnk_208;
    /* 20c */ s32 mUnk_20c;
    /* 210 */ s32 mUnk_210;
    /* 214 */ s32 mUnk_214;
    /* 218 */ u8 mUnk_218[0x100];
    /* 318 */ u8 mUnk_318[0x100];
    /* 418 */ u32 mUnk_418;
    /* 41c */ s32 mUnk_41c;
    /* 420 */ s32 mUnk_420;
    /* 424 */ Unk021937c0Node *mUnk_424;
    /* 428 */ Unk0218f960_428 mUnk_428;
    /* 430 */ s32 mUnk_430;
    /* 434 */ Unk02193f2cNode *mUnk_434;
    /* 438 */ Unk02190ed4Node *mUnk_438;
    /* 43c */ Unk02190ed4Node *mUnk_43c;
    /* 440 */ void *mUnk_440;
    /* 444 */ s32 mUnk_444;
    /* 448 */ s32 mUnk_448;
    /* 44c */ s32 mUnk_44c;
    /* 450 */ void *mUnk_450;
    /* 454 */ s32 mUnk_454;
    /* 458 */ s32 mUnk_458;
    /* 45c */ s32 mUnk_45c;
    /* 460 */ void *mUnk_460;
    /* 464 */ u8 mUnk_464[8];
    /* 46c */ s32 mUnk_46c;
    /* 470 */ s32 mUnk_470;
    /* 474 */ s8 mUnk_474[0x19];
} Unk0218f960_00;

// Object passed to func_ov000_0218f960 as its first argument.
typedef struct Unk0218f960 {
    /* 00 */ Unk0218f960_00 *mUnk_00;
} Unk0218f960;

typedef struct Unk0218fa98 {
    /* 00 */ u8 pad_00[8];
    /* 08 */ s32 *mUnk_08;
} Unk0218fa98;

u32 func_ov000_0218f960(Unk0218f960 *p, u32 b);
s32 func_ov000_0218fa98(void *unused, Unk0218fa98 *object, s32 minimum);
u32 func_ov000_0218faac(Unk0218f960 *a, u32 b);
u32 func_ov000_0218fb3c(Unk0218f960 *a, s32 b, s32 c, const u8 *d);
u32 func_ov000_0218fbe0(Unk0218f960 *a, s32 b, s32 c, const u8 *d);
