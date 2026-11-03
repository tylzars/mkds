#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Second parameter of func_020e57fc; the word at 0x29c is the only field read.
typedef struct Unk020e57fc {
    /* 000 */ u8 mUnk_000[0x29c];
    /* 29c */ u32 mUnk_29c;
} Unk020e57fc;

void func_020e5830(Unk020e43a8 *p);
s32 func_020e57fc(Unk020e43a8 *p, Unk020e57fc *q, s32 a, u8 *b);
