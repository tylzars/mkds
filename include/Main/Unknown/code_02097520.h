#pragma once

#include "types.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_02156000.h"

typedef struct Unk02097520 {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk02097520;

typedef struct Unk0209753c {
    /* 00 */ u8 mUnk_00[0xebc];
    /* ebc */ u32 mUnk_ebc;
} Unk0209753c;

void func_02097520(Unk02097520 *p0);
u32 func_0209753c(u32 param_1);
