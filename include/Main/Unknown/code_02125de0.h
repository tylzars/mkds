#pragma once

#include "types.h"

// Argument block of func_02125de0 (ten words read from it).
typedef struct Unk02125de0Arg {
    /* 00 */ BOOL mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ BOOL mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ BOOL mUnk_1c;
    /* 20 */ BOOL mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk02125de0Arg;

void func_02125de0(void *heap, Unk02125de0Arg *config);
