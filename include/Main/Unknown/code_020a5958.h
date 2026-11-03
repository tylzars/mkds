#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object reached through func_02100138(0x6a), set up by func_020a5744 and updated by func_020a5958: the shared
// MapObject part, then words up to 0xe8. func_020a5958 switches on the word at 0xe0 (0 to 6).
typedef struct Unk020a5958 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ u8 mUnk_ac[4];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ u16 mUnk_c8;
    /* ca */ u16 mUnk_ca;
    /* cc */ Vec3 mUnk_cc;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ void *mUnk_e4;
    /* e8 */ s32 mUnk_e8;
} Unk020a5958;

void func_020a5958(void *a, Unk020a5958 *p);
