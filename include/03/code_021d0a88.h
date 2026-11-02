#pragma once

#include "types.h"

typedef struct Unk021d1358 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18;
} Unk021d1358;

#include "03/unk_021da000.h"

u32 func_ov003_021d0a88(void);
void func_ov003_021d0ab8(void);
void func_ov003_021d0acc(void);
void func_ov003_021d0c58(void);
void func_ov003_021d0c84(void);
void *func_ov003_021d0e90(void);
void func_ov003_021d0e9c(u8 *param_1, u8 *param_2);
void func_ov003_021d0ee0(void);
u32 func_ov003_021d11a0(void);
u32 func_ov003_021d11d4(void);
void func_ov003_021d1218(void);
u32 func_ov003_021d1290(void);
void func_ov003_021d1358(Unk021da2ac *param_1, Unk021d1358 *param_2);
