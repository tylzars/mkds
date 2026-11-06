#pragma once

#include "types.h"

// Two halfwords passed and stored as one value (rows of Unk021035ac, func_02103db0's second argument).
typedef union {
    u32 mWord;
    struct {
        /* 00 */ s16 mUnk_00;
        /* 02 */ s16 mUnk_02;
    } mHalf;
} Unk021035ac_Pair;

// Row of the 0x34-byte table addressed by data_0217c654.
typedef struct Unk021035ac Unk021035ac;

struct Unk021035ac {
    /* 00 */ s16 mUnk_00[4][2];
    /* 10 */ s16 mUnk_10[4][2];
    /* 20 */ s16 mUnk_20[2];
    /* 24 */ void (*mUnk_24)(Unk021035ac *p);
    /* 28 */ u32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
};

void func_021035ac(int b2);
void func_0210366c(Unk021035ac *p);
