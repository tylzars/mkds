#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "code_02021db0.h" // Unk02021e40

// 16-byte element of the table at 0x7dc of an Unk0217b3c4.
typedef struct RaceNclrNcgr {
    /* 00 */ Nclr *mNclr;
    /* 04 */ Ncgr *mNcgr;
    /* 08 */ u8 mUnk_08[8];
} RaceNclrNcgr;

// 0x88c bytes, allocated by func_020b8624; the pointer to it is held in data_0217b3c4.
typedef struct Unk0217b3c4 {
    /* 000 */ Unk02021e40 *mRaceMNcerEntries[0x38];
    /* 0e0 */ Unk02021e40 *mRaceGoalMNcerEntries[0x44];
    /* 1f0 */ Unk02021e40 *mRaceTaMNcerEntries[0xf];
    /* 22c */ Unk02021e40 *mRaceBattleMNcerEntries[0xd];
    /* 260 */ Unk02021e40 *mRaceMrMNcerEntries[0x16];
    /* 2b8 */ Unk02021e40 *mRaceGoalMrMNcerEntries[8];
    /* 2d8 */ Unk02021e40 *mRaceSNcerEntries[0xc9];
    /* 5fc */ Unk02021e40 *mRaceGoalSNcerEntries[0x2c];
    /* 6ac */ Unk02021e40 *mRaceGoalTeamSNcerEntries[0x28];
    /* 74c */ Unk02021e40 *mRaceNewRecordTaSNcerEntries[0x21];
    /* 7d0 */ Unk02021e40 *mRaceStartBattleMNcerEntries[3];
    /* 7dc */ RaceNclrNcgr mNclrNcgrPairs[11];
} Unk0217b3c4;

void func_020b8624(void);

#include "00/code_021832d8.h"
