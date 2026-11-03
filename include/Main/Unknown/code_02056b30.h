#pragma once

#include "types.h"

typedef struct Unk0217aa08_08_04 Unk0217aa08_08_04;
typedef struct Unk0217aa08_0c_04 Unk0217aa08_0c_04;

// 0x20 bytes that func_02056bc0 fills and func_02056b30 reads.
typedef struct Unk02056bc0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u16 mUnk_04[10];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mUnk_1a;
    /* 1b */ u8 mUnk_1b;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
    /* 1f */ u8 mUnk_1f;
} Unk02056bc0;

void func_02056b30(Unk0217aa08_08_04 *a, Unk02056bc0 *b);
s32 func_02056bc0(s32 a, s32 b, Unk02056bc0 *c);
void func_02056c0c(Unk0217aa08_0c_04 *a, Unk02056bc0 *b);
