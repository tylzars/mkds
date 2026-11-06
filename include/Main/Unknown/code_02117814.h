#pragma once

#include "types.h"

// Runs AdvanceSelectCupGridShownCourse and waits until func_02127788 returns non-zero, then requests state 7.
void AdvanceSelectCupGridState6(void);
// Runs AdvanceSelectCupGridShownCourse and waits until func_021277c8 returns non-zero (after the request of state 5,
// func_02118148, opened a message with func_021277f8), then requests state 6.
void AdvanceSelectCupGridState5(void);
