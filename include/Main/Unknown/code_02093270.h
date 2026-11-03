#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "Main/Unknown/code_020e6fd4.h" // MapObject, Unk020e6fd4

// Object of func_02093270: after the shared part, a counter at 0xa0, a halfword at 0xa4, a value at 0xa8, a
// state at 0xac, a Unk020e0144 at 0xb0 and a table of countdowns at 0xd4.
typedef struct Unk02093270 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ u16 mUnk_a4;
    /* a6 */ u8 mUnk_a6[2];
    /* a8 */ s32 mUnk_a8;
    /* ac */ u32 mUnk_ac;
    /* b0 */ Unk020e0144 mUnk_b0;
    /* d4 */ s32 mUnk_d4[8];
} Unk02093270;

// Object of func_02093708: a word at 0x1c.
typedef struct Unk02093708 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk02093708;

void func_02093270(void *a, Unk02093270 *p);
void func_02093484(Unk020e6fd4 *p);
void func_020935fc(void *a, Unk02093270 *p);
void func_020936f0(void *a);
void func_02093708(Unk02093708 *p);
u8 func_02093754(Unk02093270 *a, Unk0206bcb0 *b, u8 *c, u8 *d);
