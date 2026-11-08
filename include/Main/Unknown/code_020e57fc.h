#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Second parameter of CollideKartWithSecondHand; the word at 0x29c is the only field read.
typedef struct Unk020e57fc {
    /* 000 */ u8 mUnk_000[0x29c];
    /* 29c */ u32 mUnk_29c;
} Unk020e57fc;

void UpdateSecondHandState3(Unk020e43a8 *secondHand);
s32 CollideKartWithSecondHand(Unk020e43a8 *secondHand, Unk020e57fc *kart, s32 a, u8 *b);
