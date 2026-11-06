#pragma once

#include "types.h"

// Advances the cup chooser by one step: takes mNextState as mState, runs the handler of that state
// (AdvanceSelectCupGridState0 to AdvanceSelectCupGridState11), then updates the cells and the draw lists; returns
// mResult once state 11 has run for 10 steps, else 0.
s32 AdvanceSelectCupGrid(void);
// Slides the cups out over 10 steps (mStateFrames counts the calls); AdvanceSelectCupGrid returns mResult after the
// tenth.
void AdvanceSelectCupGridState11(void);
// Waits for the answer to the message of state 9: answers -1 and 0 go back to state 3, answer 1 sets mResult to 3 and
// requests state 11.
void AdvanceSelectCupGridState10(void);
// Runs AdvanceSelectCupGridShownCourse; when func_02127788 returns non-zero it requests state 10 (and plays sound 0xf
// for answer 1 when the flag at 0x027ffc40 is 2).
void AdvanceSelectCupGridState9(void);
