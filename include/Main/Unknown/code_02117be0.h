#pragma once

#include "types.h"

// Waits until IsSelectReturnState2NoState3Or4Request returns non-zero, then requests state 3.
void AdvanceSelectCupGridState2(void);
