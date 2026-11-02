#pragma once

#include "types.h"

// Object behind data_ov003_021da25c.
typedef struct Unk021da25c {
    /* 000 */ u32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x600];
    /* 604 */ u8 mUnk_604;
} Unk021da25c;

#include "03/unk_021da000.h"

void func_ov003_021cc8d4(u32 param_1);
void func_ov003_021cc900(u32 param_1);
void func_ov003_021cc924(u32 param_1);
void func_ov003_021cc948(u8 *param_1, u32 param_2, u32 param_3);
void func_ov003_021cc97c(void);
void func_ov003_021cc9c0(int param_1, int param_2, int param_3, int param_4);
void func_ov003_021cc9fc(void);
void func_ov003_021cca10(void);
void func_ov003_021cca30(const void *param_1);
