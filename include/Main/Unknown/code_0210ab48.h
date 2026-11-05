#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"

// Object behind data_0217ccc0: eight objects, a value for each of them, eight words, then four words.
typedef struct Unk0217ccc0 {
    /* 00 */ Kart *mUnk_00[8];
    /* 20 */ s32 mUnk_20[8];
    /* 40 */ u32 mUnk_40[8];
    /* 60 */ s32 mUnk_60;
    /* 64 */ BOOL mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
} Unk0217ccc0;

extern Unk0217ccc0 data_0217ccc0;

void func_0210b4e0(Kart *a, s32 b, s32 c, s32 d);
void func_0210b2a8(Kart *a, s32 b, s32 c, s32 d, u32 e);
void func_0210b234(Kart *a, s32 b, s32 c, s32 d, s32 f);
void func_0210b198(s32 a, s32 b, u32 c, s32 d, s32 e);
void func_0210b12c(Kart *a, s32 b, s16 d);
void func_0210af40(Kart *a, s32 b, s32 c);
void func_0210aefc(void);
void func_0210add4(void);
void func_0210ad58(Kart *a, s32 b);
void func_0210abf4(Kart *a, s32 b, s32 c, s32 d);
void func_0210ab48(s32 a, s32 b);
