#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;

void func_0203e74c(u16 param_1);
// Ends kart a with end kind b (0 goal reached, other values the other ends) unless it has already ended or its end wait
// runs: stops the race clock, stores the time in the kart's lap time slot 5, for the entry flagged local records the
// kind and starts its end wait (flag 0x10 for kind 0, 0x20 otherwise), calls FinishRaceProgressKart(kart, b == 0) and
// runs the end handler of the mode when IsRaceEndConditionMet holds.
void FinishRaceProgressKartWithEndKind(s32 a, s32 b);
// b is goal reached; b == 0 ends the entry without the goal (status 3). Also tells the input source and the HUD.
void FinishRaceProgressKart(RaceProgressKart *a, s32 b);
void FinishRemainingMissionRunKarts(void);
void func_0203ecf0(void);
// Finishes every kart that has neither ended nor been removed, without the goal, with its time from the race clock
// (scaled by its race progress in Grand Prix), and sets the finished count to the kart count; the end handler of the
// modes without their own.
void FinishRemainingRaceProgressKarts(void);
// Returns non-zero when the end condition of the current mode holds: Grand Prix when every entry whose mKind is 0, 2 or
// 3 has status 1 to 3; Time Attack when entry 0 has ended; Battle when every such entry is eliminated; mode 5 and
// Versus by the counts of finished and removed karts; mission run when RaceSetup.mUnk_2f is 6 and a kart has
// finished; changes nothing.
s32 IsRaceEndConditionMet(void);
