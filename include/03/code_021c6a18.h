#pragma once

#include "types.h"
#include "03/code_021d1fd0.h"

// Object at 0x04 of Unk021da1f8.
typedef struct Unk021da1f8_04 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021da1f8_04;

// Object behind data_ov003_021da1f8.
typedef struct Unk021da1f8 {
    /* 00 */ Unk021d2188 *mUnk_00;
    /* 04 */ Unk021da1f8_04 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mUnk_29;
    /* 2a */ u8 mUnk_2a;
} Unk021da1f8;

#include "03/unk_021da000.h"

extern u8 data_ov003_021d7278[];

// Declared here until the code that defines them is decompiled.
BOOL func_ov003_021c6764(void);
void func_ov003_021c6914(void);
void func_ov003_021c696c(void);
void func_ov003_021c6a18(void);
void func_ov003_021c6acc(void);
void func_ov003_021c6b58(void);
void func_ov003_021c6b80(void);
void func_ov003_021c6b9c(void);
void func_ov003_021c6ba0(void);
void func_ov003_021c6cdc(void);
void func_ov003_021c6cf0(void);
void func_ov003_021c6d0c(void);
void func_ov003_021c6d68(void);
void func_ov003_021c6da4(void);
void func_ov003_021c6e38(void);
