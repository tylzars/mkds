#pragma once

#include "types.h"

// Runs AdvanceSelectCupGridShownCourse and waits until GetSelectChoisesDone returns non-zero, then requests state 7.
void AdvanceSelectCupGridState6(void);
// Runs AdvanceSelectCupGridShownCourse and waits until IsSelectChoisesState1NoState0Request returns non-zero (after the
// request of state 5, func_02118148, opened a message with StartSelectChoises), then requests state 6.
void AdvanceSelectCupGridState5(void);
