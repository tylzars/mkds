#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8
#include "code_0212bcac.h"

// 0x28-byte part at 0xa0 and 0xc8 of Unk020a826c: the four words at 0x00 go to func_0210b734 or func_0210b760 with
// the value at 0x1c, 0x0c holds func_020d4ef4's result for the vector at 0x10, 0x24 is set to 0, 1 or 2
// (func_020a826c); func_020a8ed8 writes the vector at 0x10 and the word at 0x20.
typedef struct Unk020a826c_a0 {
    /* 00 */ Unk0210b7a8 mUnk_00;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Unk0212c400 **mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk020a826c_a0;

// Object of func_020a826c: the shared MapObject part, two Unk020a826c_a0 and a value at 0xf0 (0 to 6) that
// selects what func_020a826c does.
typedef struct Unk020a826c {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ Unk020a826c_a0 mUnk_0a0;
    /* 0c8 */ Unk020a826c_a0 mUnk_0c8;
    /* 0f0 */ s32 mUnk_0f0;
} Unk020a826c;

void func_020a826c(void *a, Unk020a826c *p);
