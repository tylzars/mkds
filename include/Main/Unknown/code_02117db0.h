#pragma once

#include "types.h"

void RequestSelectCupGridState10(void);
// Requests state 11: stores mNextState = 11 and zeroes mStateFrames; the next AdvanceSelectCupGrid call copies it to
// mState and runs AdvanceSelectCupGridState11.
void RequestSelectCupGridState11(void);
// Builds the cup chooser: makes its heap and object, loads the cup files, builds the cells and sets the first state. a
// is the parent heap, d the mode (0, 1 or 2 to 4 by the screen that opened it).
void InitSelectCupGrid(void *a, void *b, void *c, s32 d);
// Releases the cup chooser: writes the layer enable bits 0x1800 of the display control register when mResult is 2 (or 1
// in mode 0), releases the file helpers, destroys the heap and clears gSelectCupGrid.
void ReleaseSelectCupGrid(void);
