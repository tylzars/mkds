#pragma once

#include "types.h"

// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseKeyboardScene(void);
