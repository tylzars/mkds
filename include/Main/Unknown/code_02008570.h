#pragma once

#include "types.h"

extern u32 *data_usa_02161788;
extern u8 data_usa_0216178c[];

typedef struct FSFile FSFile;

typedef struct Unk02008570Header {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[0x4];
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u8 mUnk_40[0x20];
    /* 60 */ u32 mUnk_60;
    /* 64 */ u8 mUnk_64[0x1c];
    /* 80 */ u32 mUnk_80;
} Unk02008570Header;

int func_02008570(FSFile *param_1, void *param_2, u32 param_3);
