#pragma once

#include "types.h"

typedef struct Unk0218f960 Unk0218f960;

// Argument block of the search of func_ov000_021948bc.
typedef struct Unk0219488cArg {
    /* 00 */ const u8 *mUnk_00;
    /* 04 */ const u8 *mUnk_04;
    /* 08 */ void **mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0219488cArg;

s32 func_ov000_0219488c(Unk0218f960 *a, const u8 *b, const u8 *c, void **d);
