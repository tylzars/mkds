#pragma once

#include "types.h"
#include "code_0214e308.h"

typedef struct Unk021d299c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021d299c;

typedef struct Unk021da2d4Input {
    /* 00 */ Unk0214e334_b mUnk_00[5];
    /* 28 */ u16 mUnk_28;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ union {
        u8 mUnk_38;
        struct {
            u8 mBit_0 : 1;
            u8 mBit_1 : 1;
            u8 mBit_2 : 1;
            u8 mBit_3 : 1;
            u8 mOther : 4;
        } mBits;
    };
} Unk021da2d4Input;
