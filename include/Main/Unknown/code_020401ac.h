#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"

// Writes mNextHeader.mUnk_5c; shuffles the respawn slots in mode 2.
void InitRaceProgress(void);
void InitRaceProgressKart(RaceProgressKart *raceProgressKart, s32 kartIndex);
s16 ComputeRaceProgressKartScore(s32 kartIndex);
void ComputeGrandPrixScoreTerms(RaceProgressScoreTerms *scoreTerms, s32 kartIndex);
BOOL func_02040bc0(void);
s64 ComputeDotOfPairsRoundedS64(const UnkPair020b502c *first, const UnkPair020b502c *second);
s32 ComputeDotOfPairsRounded(const UnkPair020b502c *first, const UnkPair020b502c *second);
PointLink *GetKeyedPlacementBattlePointLink(u32 key);
