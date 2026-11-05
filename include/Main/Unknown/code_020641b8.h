#pragma once

#include "types.h"

typedef struct Kart Kart;

// Slot 2 of the selected entry's Kart when Unk021759c0.mUnk_00c is not 2: stores the Kart's squared distance in its
// sound source. The value is the one the previous distance pass left in the array at +0x124 of data_0217aed0.
void SetKartSoundDistanceSquared(Kart *a);
