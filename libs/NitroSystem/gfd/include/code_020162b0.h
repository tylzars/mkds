#pragma once

#include "types.h"

// Free range of palette memory.
typedef struct NNSGfdFrmPlttVramManager {
    /* 00 */ u32 mLoAddr;
    /* 04 */ u32 mHiAddr;
    /* 08 */ u32 mSzTotal;
} NNSGfdFrmPlttVramManager;

void NNS_GfdResetFrmPlttVramState(void);
s32 NNS_GfdFreeFrmPlttVram(u32 plttKey);
u32 NNS_GfdAllocFrmPlttVram(u32 szByte, s32 bPltt4, s32 allocFrom);
void NNS_GfdInitFrmPlttVramManager(u32 szByte, s32 useAsDefault);
