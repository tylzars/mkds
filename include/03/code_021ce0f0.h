#pragma once

#include "types.h"

typedef struct Unk021d1770 Unk021d1770;

typedef struct Unk021ce0f0 {
    /* 00 */ Unk021d1770 *mUnk_00[5];
    /* 14 */ u32 mTask;
    /* 18 */ u8 mUnk_18;
} Unk021ce0f0;

void func_ov003_021ce0f0(u32 task);
