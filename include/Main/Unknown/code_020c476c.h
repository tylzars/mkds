#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c06c4.h"

// Object behind gRaceStartGp, 0x41c bytes, allocated by InitRaceStartGp.
typedef struct RaceStartGp {
    /* 00 */ s32 mUpdateFrames;
    /* 04 */ Nclr *mRaceStartGpMONclr;
    /* 08 */ Ncgr *mRaceStartGpMONcgr;
    /* 0c */ Unk020224e0_c *mRaceStartGpMNcerEntries[3];
    /* 18 */ Unk020c06c4 mMainOam;
} RaceStartGp;

void InitRaceStartGp(void);

extern const Vec3 gVec3Zero;

u32 ClearRaceTaPositionsPointer(void);
void InitRaceTaPositions(void);
void ResetRaceTaKartPositions(s32 a);
void HideRaceTaKartPositions(s32 a);
void DrawRaceStartGp(void);
u16 UpdateRaceStartGp(void);
void UploadRaceStartGpOam(void);
void DrawRaceLinkLevel(Unk020c06c4 *a);
void UpdateRaceLinkLevel(void);
u32 ClearRaceLinkLevelPointer(void);
