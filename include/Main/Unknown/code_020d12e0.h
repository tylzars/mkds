#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind gEndingStaffRoll.
typedef struct Unk0217b4ac {
    /* 000 */ s32 mUnk_00;
    /* 004 */ Unk020b4a44 *mUnk_04;
    /* 008 */ Unk020b4934 *mUnk_08;
    /* 00c */ Unk020224e0_c *mUnk_0c;
    /* 010 */ Unk020d029c mUnk_10;
} Unk0217b4ac;

u16 func_020d13f8(void);
void func_020d12e0(void);
