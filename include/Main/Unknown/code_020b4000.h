#pragma once

#include "types.h"

#include "Main/Unknown/unk_0217b000.h"
#include "code_02021db0.h" // Unk02021dc8

// Objects stored through the first parameter: Nscr by LocateNscr and LoadNscrData, Ncgr by
// LocateNcgr, LoadNcgrData, LocateNcgr2 and LoadNcgrData2, Nclr by LocateNclr and LoadNclrData,
// Unk02021dc8 by LoadNanrData, LocateNcer and LoadNcerData (LoadNanrData passes it to NNS_G2dUnpackNAN,
// LoadNcerData to NNS_G2dUnpackNCE; LocateNcer looks up the same block tag as LoadNcerData).
typedef struct Ncgr {
    /* 0000 */ u16 mUnk_00;
    /* 0002 */ u16 mUnk_02;
    /* 0004 */ u8 mUnk_04[0xc];
    /* 0010 */ u32 mDataSize;
    /* 0014 */ u16 *mData;
} Ncgr;

typedef struct Nscr {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 mData[1];
} Nscr;

typedef struct Nclr {
    /* 0000 */ u8 pad_00[4];
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 *mData;
} Nclr;

// One stack word whose address the functions above store different pointer types through.
typedef union Unk02111684_v {
    Ncgr *mNcgr;
    Nscr *mNscr;
    Nclr *mNclr;
    Unk02021dc8 *mNcer;
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
void *func_020b4024(u32 arg0);
#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_020b4e0c.h"
