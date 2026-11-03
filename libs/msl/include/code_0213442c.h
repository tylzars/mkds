#pragma once

#include "types.h"

typedef int (*Unk0213c94cFunc)(u32 a, u8 *b, u32 *c, u32 d);

// 0x4c bytes. Bit fields of the words at 0x04 and 0x08 are read and written by fwide, func_02134540 and
// fflush; func_0213446c calls mUnk_40 with mUnk_00, mUnk_1c, &mUnk_28 and mUnk_48.
typedef struct Unk0213c94c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04_0 : 2;
    /* 04 */ u32 mUnk_04_2 : 3;
    /* 04 */ u32 mUnk_04_5 : 2;
    /* 04 */ u32 mUnk_04_7 : 3;
    /* 04 */ u32 mUnk_04_10 : 2;
    /* 04 */ u32 mUnk_04_12 : 1;
    /* 04 */ u32 mUnk_04_13 : 19;
    /* 08 */ u32 mUnk_08_0 : 3;
    /* 08 */ u32 mUnk_08_3 : 29;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[10];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 *mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 *mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ Unk0213c94cFunc mUnk_3c;
    /* 40 */ Unk0213c94cFunc mUnk_40;
    /* 44 */ Unk0213c94cFunc mUnk_44;
    /* 48 */ u32 mUnk_48;
} Unk0213c94c;

void func_0213442c(const char *a, const char *b, const char *c, int d);
int func_0213446c(Unk0213c94c *a, u32 *b);
void func_02134508(Unk0213c94c *a);
void func_0213453c(u8 *a, u32 *b);
u32 func_02134540(const char *a, u32 b, u32 c, Unk0213c94c *d);
