#pragma once

#include "types.h"
#include "Main/Unknown/code_020ffc4c.h"

// The 0x40-byte object func_02100004 allocates and zeroes.
typedef struct Unk02100004 {
    /* 00 */ s32 mUnk_00[16];
} Unk02100004;

extern Unk02100004 data_0215a068;

// The 0x2c-byte object func_020fff4c allocates (behind data_0217c62c, written from data_0215a100).
typedef struct Unk020fff4c {
    /* 00 */ s32 mUnk_00[11];
} Unk020fff4c;

extern Unk020fff4c *data_0217c62c;

extern Unk020fff4c data_0215a100;

// The 0x28-byte object func_020fffa8 allocates (behind data_0217c624, written from data_0215a12c).
typedef struct Unk020fffa8 {
    /* 00 */ s32 mUnk_00[10];
} Unk020fffa8;

extern Unk020fffa8 *data_0217c624;

extern Unk020fffa8 data_0215a12c;

Unk02100004 *func_02100004(void);
Unk020fff4c *func_020fff4c(void);
Unk020fffa8 *func_020fffa8(void);
void DrawDram(void *a, Dram *e, void *c, s32 d);
void func_020ffdd4(Unk020e6fd4 *v1);
