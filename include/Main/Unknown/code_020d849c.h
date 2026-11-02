#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_02042044.h"

// Object of 0x38 bytes whose first 0x24 bytes are an Unk020e0144 (func_020d84e4, func_020d859c, func_020d8620).
typedef struct Unk020d84e4 {
    /* 00 */ Unk020e0144 mUnk_00;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk020d84e4;

// An Unk020e0144_00_0 (func_020d80e4 and func_020d91dc), then three words.
typedef struct Unk020d849c {
    /* 00 */ Unk020e0144_00_0 mUnk_00;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
} Unk020d849c;

void func_020d8620(Unk020e0144 *p);
void func_020d859c(Unk020d84e4 *p, u16 a, s32 b);
s32 func_020d84e4(Unk020d84e4 *p);
void func_020d84c0(Unk020d849c *p, s32 a);
BOOL func_020d849c(Unk020d849c *p);
