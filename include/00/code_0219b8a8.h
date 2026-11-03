#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "00/code_021a31a4.h"

typedef struct Unk021b54c8 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void (*mUnk_04)();
    /* 08 */ void (*mUnk_08)();
    /* 0c */ s32 (*mUnk_0c)();
    /* 10 */ void (*mUnk_10)();
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ GpConnection mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ char mUnk_34[0x20];
    /* 54 */ char *mUnk_54;
    /* 58 */ char *mUnk_58;
    /* 5c */ void (*mUnk_5c)(s32 param_1);
    /* 60 */ u32 mUnk_60;
    /* 64 */ void (*mUnk_64)();
    /* 68 */ void *mUnk_68;
    /* 6c */ void (*mUnk_6c)(u32 a, u32 b, void *c);
    /* 70 */ void *mUnk_70;
    /* 74 */ void (*mUnk_74)(u32 a, u32 b, u32 c, u32 d, u32 e, void *f);
    /* 78 */ void *mUnk_78;
    /* 7c */ void (*mUnk_7c)(s32 a, s32 b, s32 c, u32 d, u32 e, void *f);
    /* 80 */ void *mUnk_80;
    /* 84 */ Unk021b565c mUnk_84;
    /* 2e8 */ Unk021b5664 mUnk_2e8;
    /* 33c */ Unk021b566c mUnk_33c;
    /* 7a0 */ Unk021b5dd0 mUnk_7a0;
} Unk021b54c8;

extern Unk021b54c8 *data_ov000_021b54c8;

void func_ov000_0219b8a8(s32 value);
