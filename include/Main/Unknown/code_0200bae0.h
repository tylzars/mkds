#pragma once

#include "types.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "code_02142eac.h"

// Object behind data_0216fdec; the members are the ones the code reads.
typedef struct Unk0216fdec {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u16 mUnk_20;
} Unk0216fdec;

// Two halfwords that are passed on to the function at mUnk_00 of an Unk0216fdec.
typedef struct Unk0200bd34 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk0200bd34;

// Declared here until the code that defines it is decompiled.
void func_020092a4(void);

void func_0200bae0(void);
void func_0200bb98(Unk0216fde8 *a, void *b);
void func_0200bc0c(void);
void func_0200bc1c(Unk021425e8 *a);
s32 func_0200bc78(u32 a, u16 b, u8 *c);
void func_0200bcd8(Unk021425e8 *a);
u32 func_0200bd0c(void);
void func_0200bd34(Unk021425e8 *a);
void func_0200bd7c(void);
void func_0200bdb4(Unk021425e8 *a);
void func_0200be00(void);
void func_0200be44(Unk021425e8 *a);
void func_0200bef8(void *a, u8 *b);
void func_0200bf90(Unk021425e8 *a);
void func_0200c008(u8 *a);
