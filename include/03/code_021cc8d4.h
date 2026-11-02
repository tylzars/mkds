#pragma once

#include "types.h"

// Object behind data_ov003_021da25c.
typedef struct Unk021da25c {
    /* 000 */ u32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x600];
    /* 604 */ u8 mUnk_604;
} Unk021da25c;

#include "03/unk_021da000.h"

void func_ov003_021cc8d4(u32 a);
void func_ov003_021cc900(u32 a);
void func_ov003_021cc924(u32 a);
void func_ov003_021cc948(u8 *a, u32 b, u32 c);
void func_ov003_021cc97c(void);
void func_ov003_021cc9c0(int a, int b, int c, int d);
void func_ov003_021cc9fc(void);
void func_ov003_021cca10(void);
void func_ov003_021cca30(const void *b);
