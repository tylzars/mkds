#pragma once

#include "types.h"

s32 func_020a1048(u16 a);
BOOL IsKartEliminated(int a);
void AddBalloonsLeftToMake(u16 a, s32 b);
// TRUE when the kart's mTeamId equals Standings.mWinnerTeamId and mEndTimer is below 0, the end being reached.
s32 IsKartOnWinningTeamAtEnd(s32 a);
