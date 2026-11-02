#pragma once

#include "types.h"

// One 0x1e-byte record of Unk021cf260.
typedef struct Unk021cf260_0e {
    /* 00 */ u8 mUnk_00[0x16];
    /* 16 */ u8 mUnk_16[6];
    /* 1c */ u16 mUnk_1c;
} Unk021cf260_0e;

struct Unk021cf260 {
    /* 0000 */ u16 mUnk_00;
    /* 0002 */ u16 mMask;
    /* 0004 */ u16 mUnk_04;
    /* 0006 */ u16 mUnk_06;
    /* 0008 */ u16 mUnk_08;
    /* 000a */ u16 mUnk_0a;
    /* 000c */ u16 mUnk_0c;
    /* 000e */ Unk021cf260_0e mRecords[15];
    /* 01d0 */ u8 mUnk_01d0[0xfe70];
    /* 10040 */ u8 mUnk_10040[0xb100];
    /* 1b140 */ void *mUnk_1b140;
    /* 1b144 */ void *mUnk_1b144;
};

#include "03/unk_021da000.h"
#include "code_02142eac.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009adc.h"

void *func_ov003_021cf260(u32 index);
u32 func_ov003_021cf284(u32 a);
u16 func_ov003_021cf32c(u32 a);
u16 func_ov003_021cf360(void);
void func_ov003_021cf36c(u16 param_1);
void func_ov003_021cf378(u32 a, u32 b, Unk021425e8 *c);
void func_ov003_021cf598(void);
