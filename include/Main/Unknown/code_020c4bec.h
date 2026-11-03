#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c06c4.h"
#include "code_02022030.h"

// Object behind gRaceStartGp, 0x41c bytes, allocated by InitRaceStartGp.
typedef struct RaceStartGp {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Nclr *mRaceStartGpMONclr;
    /* 08 */ Ncgr *mRaceStartGpMONcgr;
    /* 0c */ Unk02021e40 *mRaceStartGpMNcerEntries[3];
    /* 18 */ Unk020c06c4 mUnk_18;
} RaceStartGp;

void func_020c525c(void);
void func_020c4f08(Unk020c06c4 *a);
void func_020c4e48(void);
void InitRaceStartGp(void);
