#pragma once

#include "types.h"
#include "code_0212f788.h" // Unk0212f7c8

// 0x54 bytes, data_0217ddd0. func_0212ccd4 sets it up and passes it to func_0212c9d4; mUnk_34 is called by
// func_0212c9d4 with the two buffers, mUnk_14, mUnk_08 and mUnk_38.
typedef struct Unk0212ccd4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ u8 *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ void (*mUnk_34)(u8 *a, u8 *b, u32 c, u32 d, void *e);
    /* 38 */ void *mUnk_38;
    /* 3c */ Unk0212f7c8 mUnk_3c;
    /* 4c */ u32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
} Unk0212ccd4;

// 0x14 bytes; func_0212c9d4 fills the elements of data_0217de24 in turn.
typedef struct Unk0212c9d4 {
    /* 00 */ Unk0212ccd4 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ u8 *mUnk_10;
} Unk0212c9d4;

s32 func_0212ccd4(u32 a, u8 *b, u8 *c, u32 d, u32 e, u32 f, u32 g, u32 h, s32 i, u32 j, u32 k, u32 l, u32 m, UnkFunc *n,
                  void *o);

void func_0212c9d4(Unk0212ccd4 *p);
void func_0212cad8(void);
void func_0212cb78(void);
void func_0212cbd8(void);
void func_0212d03c(void);
u32 func_0212d0ec(void);
void func_0212d10c(void);
s32 func_0212d154(u8 *a, u32 b, u32 c, u32 d, u32 e, UnkFunc *f, void *g);
