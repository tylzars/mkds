#pragma once

#include "types.h"
#include "code_02003024.h"
#include "code_0200fc8c.h"
#include "fs_file.h"
#include "code_02003be0.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_02008908.h"
#include "Main/Unknown/code_0214d000.h"

// Object func_0200aeec runs func_02007478 on: the member at 0x10 is the entry of DataRangeTable that is read.
typedef struct Unk02007478 {
    /* 00 */ Unk0200aeec mUnk_00;
    /* 10 */ DataRange *mUnk_10;
    /* 14 */ DataRangeTable *mUnk_14;
} Unk02007478;

// Six bytes handed to func_0200c3a4.
typedef struct Unk020074d8_msg {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk020074d8_msg;

extern u8 data_usa_02161784;

void func_02007478(Unk02007478 *a);
u32 func_020074d8(void);
