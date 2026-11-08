#pragma once

#include "types.h"
#include "03/unk_021da000.h"

typedef struct Ap {
    /* 00 */ void *mYbBgStep11Ncl;
    /* 04 */ OamRange *mUnk_04[3];
    /* 10 */ OamRange *mUnk_10[3];
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
} Ap;

void func_ov003_021ca940(void);
void func_ov003_021ca9c8(void);
void func_ov003_021ca9e8(void);
void func_ov003_021caae0(void);
void MoveApSelection(int a);
void func_ov003_021caca8(void);
void func_ov003_021cacfc(void);
void func_ov003_021cae28(void);
void func_ov003_021cae88(void);
void func_ov003_021caeb8(void);
void func_ov003_021cafa0(void);
void UpdateApInput(void);
void UpdateAp(void);
void func_ov003_021cb084(void);
void func_ov003_021cb0b0(void);
void func_ov003_021cb0e0(void);
// Declared here until the code that defines them is decompiled.
