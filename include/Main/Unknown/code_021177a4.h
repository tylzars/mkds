#pragma once

#include "types.h"

// Runs AdvanceSelectCupGridShownCourse and waits until IsSelectChoisesState1NoState0Request returns non-zero (after the
// request of state 8, func_02118088, opened a message with StartSelectChoises), then requests state 9.
void AdvanceSelectCupGridState8(void);
