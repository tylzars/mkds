#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list func_02100138(0x70): the shared MapObject part, then the words and the pointer func_020ac5e4
// sets.
typedef struct ShineBalloonObject {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mTimer;
    /* ac */ Unk0206bcb0 *mUnk_ac;
    /* b0 */ s32 mState;
} ShineBalloonObject;

void *func_020ac524(s32 a);
void func_020ac588(u32 a, s32 b, void *c);
void func_020ac5e4(Unk0206bcb0 *a);
void *func_020ac63c(void);
void *func_020ac658(void);
