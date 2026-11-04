#pragma once

#include "types.h"
#include "Main/Unknown/code_02102674.h"

// Object written by func_0210340c.
typedef struct {
    /* 00 */ void *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0210340c;

#include "Main/Unknown/code_021035ac.h"

// The two objects func_0210340c fills (func_02103554 and func_02103468); data_0217c64c picks one.
extern Unk0210340c data_0217c664;
extern Unk0210340c data_0217c684;

void func_021031f4(Unk02102674 *p);
void func_0210340c(Unk0210340c *p, Unk020e6488 *q);
void func_02103468(void);
void func_02103544(u32 a, u32 b);
void func_02103554(const char *a);
void func_02103890(int idx);
void func_021038f0(u32 param_1, u32 param_2);
void func_02103900(s32 idx, s32 n, s32 flag);
void func_02103db0(s32 idx, Unk021035ac_Pair param_2, s32 param_3);
u8 func_02104000(s32 a, s32 b);
void func_02104118(void);
void func_02104144(Unk0210340c *p);
void func_02104368(void);
void func_0210449c(Unk021035ac *p);
void func_021045a4(Unk021035ac *p);
void func_0210465c(Unk021035ac *p);
void func_02104970(void);
void func_021049a4(void);
