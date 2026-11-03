#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020e516c.h"

// Second argument of func_020de6a8: a Vec3 at 0x00 and halfwords at 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30 and 0x34.
typedef struct Unk020de6a8_1 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0x1a];
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[2];
    /* 34 */ s16 mUnk_34;
} Unk020de6a8_1;

// Object of 0x108 or more bytes handled by func_020de6a8.
typedef struct Unk020de6a8 {
    /* 000 */ Unk020e71a0 mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u16 mUnk_0a2;
    /* 0a4 */ u16 mUnk_0a4;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s16 mUnk_0b0;
    /* 0b2 */ u8 mUnk_0b2[2];
    /* 0b4 */ Unk020e516c mUnk_0b4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec;
    /* 0f0 */ u16 mUnk_0f0;
    /* 0f2 */ u16 mUnk_0f2;
    /* 0f4 */ u16 mUnk_0f4;
    /* 0f6 */ u8 mUnk_0f6[2];
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ Vec3 *mUnk_0fc;
    /* 100 */ UnkFunc *mUnk_100;
    /* 104 */ void *mUnk_104;
    /* 108 */ Unk020d84e4 mUnk_108;
} Unk020de6a8;

void func_020de84c(void);
void func_020de6a8(Unk020de6a8 *a, Unk020de6a8_1 *b);
Unk020de390 *func_020de658(void);
Unk020de334 *func_020de5fc(void);
Unk020de2d8 *func_020de5a0(void);
void func_020de588(void);
