#pragma once

#include "types.h"

typedef struct Bmg Bmg;
typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Three pointers filled in by LoadNclrData, LoadNcgrData2 and LoadNscrData.
typedef struct Unk02001d30 {
    /* 00 */ Nclr *mUnk_00;
    /* 04 */ Ncgr *mUnk_04;
    /* 08 */ Nscr *mUnk_08;
} Unk02001d30;

// The part of Unk021a99c0 from 0x18: a halfword at 0x0e and the halfwords at 0x10 and 0x12.
typedef struct Unk021a99c0_18 {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk021a99c0_18;

// Object behind data_usa_ov001_021a99c0.
typedef struct Unk021a99c0 {
    /* 00 */ Unk02001d30 mUnk_00;
    /* 0c */ Unk02001d30 mUnk_0c;
    /* 18 */ Unk021a99c0_18 mUnk_18;
    /* 2c */ union {
        s32 mUnk_2c;
        struct {
            s32 mUnk_2c_0 : 1;
            u32 mUnk_2c_1 : 1;
        };
    };
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ Bmg *mUnk_38;
} Unk021a99c0;

extern Unk021a99c0 *data_usa_ov001_021a99c0;
extern s32 data_usa_02174e54;

void func_02001000(void);
void func_0200104c(void);
