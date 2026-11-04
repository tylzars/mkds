#pragma once

#include "types.h"

typedef struct Unk02174e14 Unk02174e14;

// Halfword, hour and minute, as func_0202dcf4 fills them.
typedef struct Unk0202de00_g {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0202de00_g;

unsigned int func_0202dd9c(void);
unsigned int func_0202ddb0(void);
unsigned int func_0202ddc4(void);
unsigned int func_0202ddd8(void);
void *func_0202ddec(void);
void func_0202de00(Unk02174e14 *a, s16 (*b)[4], void *c, s32 d, s32 e, s32 f, Unk0202de00_g *g);
void func_0202dec8(void);
void func_0202defc(void);
void func_0202df34(s32 a);
void func_0202dfd4(void *a);
