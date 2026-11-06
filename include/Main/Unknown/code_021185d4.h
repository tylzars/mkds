#pragma once

#include "types.h"

// Returns 1 while the cell slide that follows a change of mIndex is running (mIndexChangeTimer is non-zero), else 0;
// changes nothing.
u32 IsSelectCupGridIndexChangeRunning(void);
