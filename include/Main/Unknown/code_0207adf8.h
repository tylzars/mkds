#pragma once

#include "types.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/unk_02155000.h"

// Object func_0207adf8 works on.
typedef struct Unk0207adf8 {
    /* 00 */ Nsbmd mUnk_00;
    /* 6c */ u16 mUnk_6c;
    /* 6e */ u16 mUnk_6e;
    /* 70 */ u16 mUnk_70;
    /* 72 */ u8 mUnk_72[2];
} Unk0207adf8;

void func_0207adf8(Unk0207adf8 *a, u32 b, u32 c);
