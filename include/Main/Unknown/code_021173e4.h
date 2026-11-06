#pragma once

#include "types.h"

void func_021173e4(void);
void func_021185ec(void);
// Sets up the screen for the cup at mIndex: draws the cup, writes the four messages of the cup (data_0215c91c[mIndex])
// into the cells, shows the record cells of mode 0 and asks for the cup picture; called at InitSelectCupGrid and again
// by AdvanceSelectCupGridIndexChange.
void SetupSelectCupGridIndex(void);
// Asks for the cup picture of the course that mShownCourseIndex selects and sets mCupPicturePending;
// AdvanceSelectCupGrid queues the picture data when it is ready.
void RequestSelectCupGridCupPicture(void);
void func_02118814(void);
void func_021188dc(void);
void func_021189cc(void);
