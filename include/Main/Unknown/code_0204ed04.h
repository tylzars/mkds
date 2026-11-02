#pragma once

#include "types.h"

typedef struct Unk0204ed04 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ void *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk0204ed04;

void func_0204ed04(Unk0204ed04 *a);
void func_0204ed84(void);
u32 func_0204ee30(void);
u32 func_0204ee4c(u32 arg0, u32 arg1);
