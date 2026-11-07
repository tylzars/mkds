#pragma once

#include "types.h"

typedef struct Unk020df85c {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk020df85c;

void EnterMkdEfBubbleState1(Unk020df85c *bubble);
