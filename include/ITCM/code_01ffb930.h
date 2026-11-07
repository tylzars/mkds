#pragma once

#include "types.h"

typedef struct Kart Kart;

// Takes up to 0x1ec / 0x1000 of the speed *a off in proportion to the size of mTurnRatio, on the ground outside a
// drift.
void ReduceKartSpeedByTurnRatio(s32 *a, Kart *p);
// Adds mGravity to mVerticalSpeed.
void ApplyKartGravity(Kart *p);
void func_01ffb9e0(Kart *p);
