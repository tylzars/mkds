#pragma once

#include "types.h"
#include "code_02152490.h"
#include "code_02152500.h"
#include "00/code_0218f960.h"

typedef struct Unk021b565c {
    /* 00 */ Unk0218f960 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ void (*mUnk_18)();
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk02152500 *mUnk_20;
    /* 24 */ u8 pad_24[4];
    /* 28 */ void *mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ u64 mUnk_38;
    /* 40 */ Unk02152490 mUnk_40;
    /* 4c */ char mUnk_4c[0x100];
    /* 14c */ char mUnk_14c[0x100];
    /* 24c */ char mUnk_24c[9];
    /* 255 */ char mUnk_255[0xf];
} Unk021b565c;

extern Unk021b565c *data_ov000_021b565c;

void func_ov000_0219c93c(void);
