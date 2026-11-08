#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "code_02022030.h" // Unk020224e0_c

// 16-byte element of the table at 0x7dc of an RaceNcerNclrNcgrTables.
typedef struct RaceNclrNcgr {
    /* 00 */ Nclr *mNclr;
    /* 04 */ Ncgr *mNcgr;
    /* 08 */ u8 mUnk_08[8];
} RaceNclrNcgr;

// 0x88c bytes, allocated by func_020b8624; the pointer to it is held in data_0217b3c4.
typedef struct RaceNcerNclrNcgrTables {
    /* 000 */ Unk020224e0_c *mRaceMNcerEntries[0x38];
    /* 0e0 */ Unk020224e0_c *mRaceGoalMNcerEntries[0x44];
    /* 1f0 */ Unk020224e0_c *mRaceTaMNcerEntries[0xf];
    /* 22c */ Unk020224e0_c *mRaceBattleMNcerEntries[0xd];
    /* 260 */ Unk020224e0_c *mRaceMrMNcerEntries[0x16];
    /* 2b8 */ Unk020224e0_c *mRaceGoalMrMNcerEntries[8];
    /* 2d8 */ Unk020224e0_c *mRaceSNcerEntries[0xc9];
    /* 5fc */ Unk020224e0_c *mRaceGoalSNcerEntries[0x2c];
    /* 6ac */ Unk020224e0_c *mRaceGoalTeamSNcerEntries[0x28];
    /* 74c */ Unk020224e0_c *mRaceNewRecordTaSNcerEntries[0x21];
    /* 7d0 */ Unk020224e0_c *mRaceStartBattleMNcerEntries[3];
    /* 7dc */ RaceNclrNcgr mNclrNcgrPairs[11];
} RaceNcerNclrNcgrTables;

void func_020b8624(void);

#include "00/code_021832d8.h"
