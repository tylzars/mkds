#pragma once

#include "types.h"

typedef struct Unk0208ffd8 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
} Unk0208ffd8;

void SetItemBitsEveryCall(Unk0208ffd8 *itemUse);
