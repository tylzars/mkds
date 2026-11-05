#pragma once

#include "types.h"

// Stores 0 in gCameraEntryChanged and gEntryCameraUpdateRan. UpdateRace calls it once per call before the camera steps.
u32 ClearCameraEntryFlags(void);
