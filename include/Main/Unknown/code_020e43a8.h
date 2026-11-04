#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Three vectors, 0x24 bytes.
typedef struct Unk020e43a8_28 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
} Unk020e43a8_28;

// Object read through mUnk_9c; only the s16 at 0x28 is seen.

// Object passed to func_020e43a8 and the functions after it, and to func_020ec1fc and
// func_020ec41c to func_020ec854; the words from 0xa0 to 0xc8 are read two ways.
typedef struct Unk020e43a8 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ union {
        struct {
            /* a0 */ Unk020e43a8_28 mUnk_a0;
            /* c4 */ u16 mUnk_c4;
            /* c6 */ s16 mUnk_c6;
        };
        // As func_020ec1fc, func_020ec538, func_020ec6e4, func_020ec7e8 and func_020ec854 read it:
        // halfwords at 0xac and 0xae, a word at 0xc4.
        struct {
            /* a0 */ s32 mUnk_0a0;
            /* a4 */ s32 mUnk_0a4;
            /* a8 */ u32 mUnk_0a8;
            /* ac */ u16 mUnk_0ac;
            /* ae */ u16 mUnk_0ae;
            /* b0 */ u32 mUnk_0b0;
            /* b4 */ s32 mUnk_0b4;
            /* b8 */ u8 mUnk_0b8[4];
            /* bc */ s32 mUnk_0bc;
            /* c0 */ s32 mUnk_0c0;
            /* c4 */ s32 mUnk_0c4;
        };
    };
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ u8 mUnk_e0[0x14];
    /* f4 */ Vec3 mUnk_f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ u8 mUnk_10c[0x08];
    /* 114 */ u8 mUnk_114[0x04];
    /* 118 */ u8 mUnk_118[0x0c];
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ u8 mUnk_130[0x14];
    /* 144 */ u16 mUnk_144;
    /* 146 */ u16 mUnk_146;
    /* 148 */ u8 mUnk_148[0x02];
    /* 14a */ s16 mUnk_14a;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ u8 mUnk_154[0x08];
    /* 15c */ s32 mUnk_15c;
} Unk020e43a8;

void func_020e43a8(Unk020e43a8 *p);
