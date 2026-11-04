#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h" // Ncgr, Nclr
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30
#include "Main/Unknown/code_020302a0.h"

// Object behind data_02174e54, 0x40 bytes.
typedef struct Unk02174e54 {
    /* 00 */ Ncgr *mUnk_00;
    /* 04 */ Nclr *mUnk_04;
    /* 08 */ struct Unk02021dc8 *mUnk_08;
    /* 0c */ Unk0201ea30 *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk0201ea30 *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ void *mHeap;
} Unk02174e54;

void func_0203003c(s32 a);
void func_02030200(void);
s32 func_0203023c(void);
s32 func_02030274(s32 a, s32 b);
