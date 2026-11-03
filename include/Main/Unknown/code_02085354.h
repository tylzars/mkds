#pragma once

#include "types.h"

typedef struct Unk0201290c Unk0201290c;

// Object whose pointer at 0x04 is passed to func_0201290c.
typedef struct Unk02085360 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0201290c *mUnk_04;
} Unk02085360;

void func_02085354(void *a);
void func_02085360(Unk02085360 *a);
