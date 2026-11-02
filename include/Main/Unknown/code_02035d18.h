#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h"

// Object behind data_02174e6c, 0x654 bytes: the halfwords from 0x34 are 32 per row.
typedef struct Unk02174e6c {
    /* 000 */ void *mUnk_000;
    /* 004 */ u8 mUnk_004[0x20];
    /* 024 */ Unk02180728 mUnk_024;
    /* 034 */ u16 mUnk_034[0x300];
    /* 634 */ void *mUnk_634;
    /* 638 */ void *mUnk_638;
    /* 63c */ u8 mUnk_63c[4];
    /* 640 */ s32 mUnk_640;
    /* 644 */ u8 mUnk_644[8];
    /* 64c */ s32 mUnk_64c;
    /* 650 */ void *mUnk_650;
} Unk02174e6c;

#include "Main/Unknown/unk_02174000.h"

void func_02035d18(void);
void func_02035d20(void);
void func_02035d48(u32 a, int b);
void func_02035d74(int arg0);
void func_02035d90(void);
s32 func_02035db4(u32 a);
void func_02035e30(unsigned int p0, unsigned int p1);
void func_02035e38(void);
