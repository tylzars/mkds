#pragma once

#include "types.h"

// Waits until AreBrightnessFadesClear returns non-zero, then requests state 1 (the first state after InitSelectCupGrid:
// mState is 0 from the allocation).
void AdvanceSelectCupGridState0(void);
