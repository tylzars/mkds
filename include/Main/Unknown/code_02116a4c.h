#pragma once

#include "types.h"

// First argument of func_02116a4c.
typedef struct Unk02116a4c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
} Unk02116a4c;

// First argument of func_02116b98.
typedef struct Unk02116b98 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk02116b98;

typedef s16 Unk0215c5b4[2][7];

extern const Unk0215c5b4 data_0215c5b4;

void func_02116a4c(Unk02116a4c *a, u16 *b);
void func_02116b50(u32 a, u16 *b);
void func_02116b80(void *in, void *out);
void func_02116b8c(void *a, u16 *b);
void func_02116b98(Unk02116b98 *a, u16 *b, s32 c);
void func_02116cb0(u16 *a, s32 b);
void func_02116ccc(u16 *a, s32 b);
void func_02116ce8(s32 a, u16 *b, s32 c);
s16 func_02116d10(s32 a, s32 b);
