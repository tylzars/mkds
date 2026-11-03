#pragma once

#include "types.h"

typedef struct Unk0206bcb0 Unk0206bcb0;

// Second argument of func_0210a5a8: a word callback at 0x3c.
typedef struct Unk0210a5a8 {
    /* 00 */ u8 mUnk_00[0x3c];
    /* 3c */ UnkWordFunc *mUnk_3c;
} Unk0210a5a8;

void func_0210a5a8(Unk0206bcb0 *a, Unk0210a5a8 *b);
void func_0210a598(Unk0206bcb0 *a, s32 b);
