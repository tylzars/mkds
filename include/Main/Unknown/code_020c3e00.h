#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"

s32 func_020c3e00(void);
Unk020b47d8 *func_020c3e14(unsigned int p0);
// Two pointers; the elements of 8 bytes at member 0xb8 of the object behind gRaceGoalS.
typedef struct Unk020c3e2c {
    /* 00 */ Unk020b4a44 *mUnk_00;
    /* 04 */ Unk020b4934 *mUnk_04;
} Unk020c3e2c;

Unk020c3e2c *func_020c3e2c(unsigned int p0);
