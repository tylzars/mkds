#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// 0x38-byte entries from 0xa4 of Unk020a3fa8; func_020a3fa8 walks the first data_021759c0->mUnk_3d0 of them.
typedef struct Unk020a3fa8_a4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ Balloon *mUnk_10[8];
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ s32 mUnk_34;
} Unk020a3fa8_a4;

// Object passed to func_020a3fa8 as its second argument: a MapObject at 0x00.
typedef struct Unk020a3fa8 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ Unk020a3fa8_a4 mUnk_0a4[8];
    /* 264 */ s32 mUnk_264[8][8];
} Unk020a3fa8;

void func_020a3fa8(void *b, Unk020a3fa8 *c);
