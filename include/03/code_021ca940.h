#pragma once

#include "types.h"
#include "03/unk_021da000.h"

// Object behind data_ov003_021da234.
typedef struct Unk021da234 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk021d1770 *mUnk_04[3];
    /* 10 */ Unk021d1770 *mUnk_10[3];
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
} Unk021da234;

void func_ov003_021ca940(void);
void func_ov003_021ca9c8(void);
void func_ov003_021ca9e8(void);
void func_ov003_021caae0(void);
void func_ov003_021cab4c(int a);
void func_ov003_021caca8(void);
void func_ov003_021cacfc(void);
void func_ov003_021cae28(void);
void func_ov003_021cae88(void);
void func_ov003_021caeb8(void);
void func_ov003_021cafa0(void);
void func_ov003_021cafa4(void);
void func_ov003_021cb06c(void);
void func_ov003_021cb084(void);
void func_ov003_021cb0b0(void);
void func_ov003_021cb0e0(void);
void func_ov003_021cc948(u8 *a, u32 b, u32 c);
// Declared here until the code that defines them is decompiled.
u32 func_ov003_021cd1c4(void);
void func_ov003_021d1890(Unk021d1770 *param_1, s32 param_2, u32 param_3, u32 param_4);
