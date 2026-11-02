#pragma once

#include "types.h"

// Object func_02032ac4 reports its result through: the halfword at 0x04.
typedef struct Unk02032ac4 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02032ac4;

void func_02032ab0(void);
void func_02032ac4(Unk02032ac4 *a);
void func_02032f94(void *a, s32 b, s32 c);
