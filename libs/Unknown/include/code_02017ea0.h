#pragma once

#include "types.h"
#include "code_02017e70.h" // Unk02017e70, Unk02017ef8

// First and last entries of a chain linked through mUnk_08 and mUnk_0c of Unk02017e70.
typedef struct Unk02017ea0 {
    /* 00 */ Unk02017e70 *mUnk_00;
    /* 04 */ Unk02017e70 *mUnk_04;
} Unk02017ea0;

Unk02017e70 *func_02017ea0(Unk02017ea0 *a, Unk02017e70 *b, Unk02017e70 *c);
Unk02017e70 *func_02017ed0(Unk02017ea0 *a, Unk02017e70 *b);
void func_02017ef8(Unk02017ef8 *a, Unk02017e70 *b);
