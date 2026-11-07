#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam

// Object func_0210f090 and func_0210f130 take, 0x420 bytes: func_0210f130 zeroes 0x400 bytes and sets up the words
// at 0x400..0x418; func_0210f090 steps a signed number at 0x41c to 0x1e and then resets it.
typedef struct Unk0210f090 {
    /* 000 */ u8 mUnk_000[0x400];
    /* 400 */ MICAutoParam mUnk_400;
    /* 41c */ s32 mUnk_41c;
} Unk0210f090;

u32 func_0210f090(Unk0210f090 *p);
