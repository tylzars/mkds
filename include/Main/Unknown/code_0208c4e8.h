#pragma once

#include "types.h"

typedef struct KartTurnEffects KartTurnEffects;

// Calls mShowEffects: shows every present effect object of the Kart set again.
void ShowKartTurnEffects(KartTurnEffects *p0);
// Calls mHideEffects: hides every present effect object of the Kart set.
void HideKartTurnEffects(KartTurnEffects *p0);
// Asks AdvanceKartLevel4Effects to restart the level 4 group: sets mLevel4RestartFrames to 0 and
// mLevel4RestartRequested to 1.
void RequestKartLevel4EffectsRestart(KartTurnEffects *p0);
