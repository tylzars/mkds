#pragma once

#include "types.h"

// Waits 10 steps after the cup was chosen; in mode 0 it then requests state 5, otherwise it stores the choice, sets
// mResult to 1 and requests state 11.
void AdvanceSelectCupGridState4(void);
// Reads the touch rectangles and the keys: the exit input ends the screen with mResult 2 (in modes 2 to 4 it first
// opens the message of state 8 when data_0217b488.mUnk_08 is 2 or 3), choosing an enabled cup requests state 4,
// touching a disabled cup plays the error sound, and a direction key moves mIndex to the neighbour cup when that cup is
// enabled.
void AdvanceSelectCupGridState3(void);
