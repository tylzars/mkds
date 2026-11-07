#pragma once

#include "types.h"

// Object with a pointer at 0x0 to an array of pointers, each with a u16 at 0x0, and a u16 at 0x4.
typedef struct Unk02100094 {
    /* 00 */ void **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02100094;

s32 func_02100094(Unk02100094 *list);
