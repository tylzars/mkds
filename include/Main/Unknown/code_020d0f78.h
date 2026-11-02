#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind data_0217b4a4: three pointers that LoadNclrData, LoadNcgrData and LoadNscrData fill from
// the three buffers at 0x10, 0x238 and 0x1038, then a word at 0xc.
typedef struct Unk0217b4a4 {
    /* 0000 */ Unk020b4a44 *mUnk_00;
    /* 0004 */ Unk020b4934 *mUnk_04;
    /* 0008 */ Unk020b47d8 *mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ u8 mUnk_10[0x228];
    /* 0238 */ u8 mUnk_238[0xe00];
    /* 1038 */ u8 mUnk_1038[0x824];
} Unk0217b4a4;

void func_020d10fc(void);
void func_020d1080(void);
void func_020d0ffc(void);
void func_020d0f78(void);
