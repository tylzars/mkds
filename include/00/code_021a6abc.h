#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"

typedef struct Unk021a6bb4 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x10];
    /* 18 */ u8 mUnk_18[6];
    /* 1e */ u8 mUnk_1e[0xe];
    /* 2c */ u8 mUnk_2c[1];
} Unk021a6bb4;

u8 *func_ov000_021a6abc(u16 *param_1);
u8 *func_ov000_021a6b10(void);
void func_ov000_021a6b54(void);
void func_ov000_021a6bb4(Unk021a6bb4 *param_1);
void func_ov000_021a6bdc(void);
void func_ov000_021a6c08(u8 param_1);
