#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d6dc0.h"

// Object at 0x1d8 of Wanwan: a word at 0xa8.
typedef struct Unk020dc474_1d8 {
    /* 00 */ u8 mUnk_00[0xa8];
    /* a8 */ s32 mUnk_a8;
} Unk020dc474_1d8;

// Object of kinds 0x196 (with chain post kind 0x197) and 0x1a5 (mUnk_fc is 0 or 1) of Wanwan; func_020dc474,
// func_020dc608 and the functions after it up to func_020dd860: vectors at 0x04, 0x10 and 0xa0, ring of four vector
// pointers at 0x160, words at 0xe8, 0xec, 0xf0 and 0x1fc.
typedef struct Wanwan {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ Vec3 mUnk_a0;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ Unk020d7b88 mUnk_b4;
    /* c4 */ Unk020d7b88 mUnk_c4;
    /* d4 */ Unk020d7b88 mUnk_d4;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mUnk_fc;
    /* 100 */ Unk020d849c mUnk_100;
    /* 160 */ Vec3 *mUnk_160[4];
    /* 170 */ Vec3 mUnk_170[4];
    /* 1a0 */ Unk020d84e4 mUnk_1a0;
    /* 1d8 */ Unk020dc474_1d8 *mUnk_1d8;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ Vec3 mUnk_1e0;
    /* 1ec */ s32 mUnk_1ec;
    /* 1f0 */ Vec3 *mUnk_1f0;
    /* 1f4 */ Vec3 *mUnk_1f4;
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ s16 mUnk_1fa;
    /* 1fc */ s32 mUnk_1fc;
    /* 200 */ Vec3 mUnk_200;
} Wanwan;

void func_020dc474(Wanwan *p);
