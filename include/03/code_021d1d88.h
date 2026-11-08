#pragma once

#include "types.h"

typedef struct PointerStack {
    /* 00 */ u16 mSlotCount;
    /* 02 */ u8 mBottomIndex;
    /* 03 */ u8 mTopIndex;
    /* 04 */ void *mPointers[1];
} PointerStack;

PointerStack *CreatePointerStack(u32 count);
