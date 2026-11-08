#pragma once

#include "types.h"

BOOL func_020a1048(u16 kartIndex);
BOOL IsKartEliminated(int kartIndex);
void AddBalloonsLeftToMake(u16 kartIndex, s32 amount);
// TRUE when the kart's mTeamId equals Standings.mWinnerTeamId and mEndTimer is below 0, the end being reached.
BOOL IsKartOnWinningTeamAtEnd(s32 kartIndex);
