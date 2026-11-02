#pragma once

#include "types.h"

// Object at 0x08 of Unk02194934: func_ov000_0218f960 reads its 0x00 and passes its 0x08, its 0x0c and the object
// to func_ov000_021a3668.
typedef struct Unk02194934_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk02194934_08;

// Object behind the pointer whose address func_ov000_0218f960 passes to func_ov000_02194934; func_ov000_021947e4
// returns 1 when 0x08, 0x0c, 0x10 and 0x18 are 0.
typedef struct Unk02194934 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ Unk02194934_08 *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void *mUnk_18;
} Unk02194934;

u32 func_ov000_021947e4(Unk02194934 *a);
