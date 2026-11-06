#pragma once

#include "types.h"

// Advances the cell slide that follows a change of mIndex: restarts mIndexChangeTimer at 7 when mIndex differs from
// mShownIndex, rebuilds the cells at 7 (SetupSelectCupGridIndex) and moves them while it counts down to 0.
void AdvanceSelectCupGridIndexChange(void);
void func_02118458(void);
// Counts the calls of the handlers; every 0x4b calls it shows the next of the four courses of the cup: steps
// mShownCourseIndex (wrapping at 4), zeroes mShownCourseFrames and requests the cup picture.
void AdvanceSelectCupGridShownCourse(void);
// Starts the course cycle of the shown cup again: mShownCourseIndex and mShownCourseFrames back to 0.
void ResetSelectCupGridShownCourse(void);
void func_021181fc(void);
// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectCupGrid call copies it to
// mState and runs AdvanceSelectCupGridState1.
void RequestSelectCupGridState1(void);
void func_021181cc(void);
// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceSelectCupGrid call copies it to
// mState and runs AdvanceSelectCupGridState3.
void RequestSelectCupGridState3(void);
void func_02118184(void);
void func_02118148(void);
