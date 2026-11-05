#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

s32 func_02063b70(Kart *a);
void DrawKart(Kart *a);
// Slot 2 of the other Karts: stores the squared distance in the sound source and passes it to mUnk_518, which keeps its
// change since the previous call.
void SetKartSoundDistanceSquaredAndChange(Kart *a);
