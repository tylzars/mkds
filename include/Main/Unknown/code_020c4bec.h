#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c06c4.h"
#include "code_02022030.h"

// Object behind gRaceStartGp, 0x41c bytes, allocated by InitRaceStartGp.
typedef struct Unk0217b3e8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk020b4a44 *mRaceStartGpMONclr;
    /* 08 */ Unk020b4934 *mRaceStartGpMONcgr;
    /* 0c */ Unk02021e40 *mUnk_0c[3];
    /* 18 */ Unk020c06c4 mUnk_18;
} Unk0217b3e8;

void func_020c525c(void);
void func_020c4f08(Unk020c06c4 *a);
void func_020c4e48(void);
void InitRaceStartGp(void);
