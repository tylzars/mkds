#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3fa8.h" // KartBalloons

void SetStandingsKartOffsetCallback(void (*p0)(s32, s32));
void SetStandingsEndCallback(void (*a)(void));
void SetStandingsKartEliminatedCallback(void (*p0)(u16 a));
void SetStandingsKartHitCallback(s32 (*p0)(u16 a, u16 b));
void SetStandingsKartsHitEachOtherCallback(void (*p0)(s32, s32));
void SetStandingsKartHitByKartCallback(s32 (*p0)(s32, s32));
// Returns Standings.mKartBalloons, the pointer stored by SetStandingsKartBalloons.
KartBalloons *GetStandingsKartBalloons(void);
// Stores the pointer to the KartBalloons array of the balloon object in Standings.mKartBalloons.
void SetStandingsKartBalloons(KartBalloons *p0);
