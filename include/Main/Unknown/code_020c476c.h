#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c06c4.h"

// Object behind gRaceStartGp, 0x41c bytes, allocated by InitRaceStartGp.
typedef struct RaceStartGp {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Nclr *mRaceStartGpMONclr;
    /* 08 */ Ncgr *mRaceStartGpMONcgr;
    /* 0c */ Unk020224e0_c *mRaceStartGpMNcerEntries[3];
    /* 18 */ Unk020c06c4 mUnk_18;
} RaceStartGp;

void InitRaceStartGp(void);

extern const Vec3 data_02156880;

u32 func_020c476c(void);
void func_020c4780(void);
void func_020c4a04(s32 a);
void func_020c4ab8(s32 a);
void func_020c4ae8(void);
u16 func_020c4bb0(void);
void func_020c4e48(void);
void func_020c4f08(Unk020c06c4 *a);
void func_020c525c(void);
u32 func_020c53b0(void);
