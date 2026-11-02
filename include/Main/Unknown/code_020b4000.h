#pragma once

#include "types.h"

#include "Main/Unknown/unk_0217b000.h"
#include "code_02021db0.h" // Unk02021dc8

// Objects stored through the first parameter: Unk020b47d8 by LocateNscr and LoadNscrData, Unk020b4934 by
// LocateNcgr, LoadNcgrData, LocateNcgr2 and LoadNcgrData2, Unk020b4a44 by LocateNclr and LoadNclrData,
// Unk02021dc8 by LoadNanrData, LocateNcer and LoadNcerData (LoadNanrData passes it to func_02021dc8,
// LoadNcerData to func_02021e8c; LocateNcer looks up the same block tag as LoadNcerData).
typedef struct Unk020b4934 {
    /* 0000 */ u16 mUnk_00;
    /* 0002 */ u16 mUnk_02;
    /* 0004 */ u8 mUnk_04[0xc];
    /* 0010 */ u32 mUnk_10;
    /* 0014 */ u16 *mUnk_14;
} Unk020b4934;

typedef struct Unk020b47d8 {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 mUnk_0c[1];
} Unk020b47d8;

typedef struct Unk020b4a44 {
    /* 0000 */ u8 pad_00[4];
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 *mUnk_0c;
} Unk020b4a44;

// One stack word whose address the functions above store different pointer types through.
typedef union Unk02111684_v {
    Unk020b4934 *m4934;
    Unk020b47d8 *m47d8;
    Unk020b4a44 *m4a44;
    Unk02021dc8 *m21dc8;
} Unk02111684_v;

// Declared here until the code that defines them is decompiled.
void *func_020b4000(int param_1);
void *func_020b400c(int param_1);
void *func_020b4018(int param_1);
void *func_020b4030(int param_1);
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b4e70.h"
void *func_020b403c(s32 index);
u32 func_020b4024(u32 arg0);
#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_020b4e0c.h"
