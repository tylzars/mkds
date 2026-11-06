#pragma once

#include "types.h"

// Waits for the answer to the confirmation message: answer 0 stores the choice, sets mResult to 1 and requests state
// 11; answers -1 and 1 go back to state 3.
void AdvanceSelectCupGridState7(void);
