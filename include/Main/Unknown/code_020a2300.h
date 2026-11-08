#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3fa8.h" // KartBalloons

void SetStandingsKartOffsetCallback(void (*callback)(s32, s32));
void SetStandingsEndCallback(void (*callback)(void));
void SetStandingsKartEliminatedCallback(void (*callback)(u16 a));
void SetStandingsKartHitCallback(s32 (*callback)(u16 a, u16 b));
void SetStandingsKartsHitEachOtherCallback(void (*callback)(s32, s32));
void SetStandingsKartHitByKartCallback(s32 (*callback)(s32, s32));
// Returns Standings.mKartBalloons, the pointer stored by SetStandingsKartBalloons.
KartBalloons *GetStandingsKartBalloons(void);
// Stores the pointer to the KartBalloons array of the balloon object in Standings.mKartBalloons.
void SetStandingsKartBalloons(KartBalloons *kartBalloons);
