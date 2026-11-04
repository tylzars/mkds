#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Unk0210bcf4 Unk0210bcf4;

// Five words of constant data used by func_02109468.
typedef struct Unk02109468 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk02109468;

void func_0210a53c(Kart *a);
void func_02109468(void);
s32 func_021092b0(Unk0210bcf4 *p);
s32 func_0210920c(Unk0210bcf4 *p);
u32 func_02109184(Unk0210bcf4 *p);
