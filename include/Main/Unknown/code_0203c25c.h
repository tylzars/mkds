#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"

// Declared here until the code that defines them is decompiled.

// The lap count it compares with is unnamed.
BOOL IsKartOnLastLap(u16 a);
// Removes kart a from the race: if it had not ended, gives it the lowest rank still in the race, moves the karts ranked
// below it up by one and counts it as removed (RaceProgress.mUnk_000[0].mRemovedCount); sets its status to 4; in Battle
// also calls func_020a16d0; calls func_02069044 for the kart and func_020b1cdc(a, 1); then runs the end handler of the
// mode when IsRaceEndConditionMet holds.
void RemoveRaceProgressKart(u16 a);
u16 LookupRankPoints(u8 a);
