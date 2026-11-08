#pragma once

#include "types.h"

void WriteSelectCupGridRegisters(void);
void func_021185ec(void);
// Sets up the screen for the cup at mIndex: draws the cup, writes the four messages of the cup
// (gSelectCupGridCupMessageIndices[mIndex]) into the cells, shows the record cells of mode 0 and asks for the cup
// picture; called at InitSelectCupGrid and again by AdvanceSelectCupGridIndexChange.
void SetupSelectCupGridIndex(void);
// Asks for the cup picture of the course that mShownCourseIndex selects and sets mCupPicturePending;
// AdvanceSelectCupGrid queues the picture data when it is ready.
void RequestSelectCupGridCupPicture(void);
void UpdateSelectCupGridCupCells(void);
void func_021188dc(void);
void RefreshSelectCupGridCupsEnabled(void);
