#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/code_0218f960.h"

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
typedef struct Unk02194840Arg {
    /* 00 */ Unk0218f960 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk02194840Arg;

BOOL func_ov000_02194840(Unk0218f960 *a, void *b, void *c);
