#pragma once

#include "types.h"

// Rows of 25 words (100 bytes), indexed by a byte value read by NNSi_G3dFuncSbc_NODEMIX.
extern s32 data_02171904[][25];
extern s32 data_02171944[][25];

// 0x18-byte entries of the array at data_usa_021712f0: three words, then twelve bytes not read yet.
typedef struct Unk021712f0 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0xc];
} Unk021712f0;

extern Unk021712f0 data_usa_021712f0[];
