#pragma once

#include "types.h"

// Object behind data_0217d344 (0x34 bytes, allocated by func_021115b0); mUnk_18 is five words.
typedef struct Unk0217d344_18 {
    /* 00 */ void (*mUnk_00)(void *);
    /* 04 */ void (*mUnk_04)(void);
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ void (*mUnk_0c)(void);
    /* 10 */ void (*mUnk_10)(void);
} Unk0217d344_18;

typedef struct Unk0217d344 {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s16 mUnk_14;
    /* 16 */ s16 mUnk_16;
    /* 18 */ Unk0217d344_18 mUnk_18;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s16 mUnk_30;
    /* 32 */ s16 mUnk_32;
} Unk0217d344;

void func_021114cc(void);
