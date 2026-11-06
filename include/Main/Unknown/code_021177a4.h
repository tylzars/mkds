#pragma once

#include "types.h"

// Runs AdvanceSelectCupGridShownCourse and waits until func_021277c8 returns non-zero (after the request of state 8,
// func_02118088, opened a message with func_021277f8), then requests state 9.
void AdvanceSelectCupGridState8(void);
