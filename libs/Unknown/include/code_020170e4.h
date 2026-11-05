#pragma once

#include "types.h"

typedef struct RangeEntry RangeEntry;

// Object at data_02173234: three pointers to RangeEntry and four words at 0c to 18 stored by func_02017070.
typedef struct Unk02016d34 {
    /* 00 */ RangeEntry *mUnk_00;
    /* 04 */ RangeEntry *mUnk_04;
    /* 08 */ RangeEntry *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ RangeEntry *mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk02016d34;

// Object at data_02173250: two pointers to RangeEntry at 00 and 04 and three words at 08, 0c and 10.
typedef struct Unk020170e4 {
    /* 00 */ RangeEntry *mUnk_00;
    /* 04 */ RangeEntry *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ RangeEntry *mUnk_0c;
    /* 10 */ u32 mUnk_10;
} Unk020170e4;

// Three words; func_02016d34 keeps four of them, initialised from data_02161a90.
typedef struct Unk02161a90 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk02161a90;

void func_020170e4(void);
s32 func_02017138(u32 v);
u32 func_02017190(u32 a, s32 b);
void func_02017274(u32 a, RangeEntry *b, u32 c, int d);
