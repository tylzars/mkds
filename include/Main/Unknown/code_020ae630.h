#pragma once

#include "types.h"

// Element of 8 bytes of Unk020ae630.mUnk_00.
typedef struct Unk020ae630_00 {
    /* 00 */ union {
        u32 mUnk_00;
        u8 mUnk_00_0;
    };
    /* 04 */ u32 mUnk_04;
} Unk020ae630_00;

// Object of 0x404 bytes: 0x80 elements of 8 bytes, then two halfwords.
typedef struct Unk020ae630 {
    /* 000 */ Unk020ae630_00 mUnk_00[0x80];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} Unk020ae630;

void func_020ae630(void *mainOam, void *subOam);
void ClearOamListCounts(void *mainOam, void *subOam);
void ResetOamLists(void *mainOam, void *subOam);
