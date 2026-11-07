#pragma once

#include "types.h"

typedef struct Kart Kart;

// Second argument of InitKartSoundCallbacks: a word callback at 0x3c.
typedef struct Unk0210a5a8 {
    /* 00 */ u8 mUnk_00[0x3c];
    /* 3c */ UnkWordFunc *mUnk_3c;
} Unk0210a5a8;

void InitKartSoundCallbacks(Kart *kart, Unk0210a5a8 *b);
void func_0210a598(Kart *kart, s32 soundIndex);
