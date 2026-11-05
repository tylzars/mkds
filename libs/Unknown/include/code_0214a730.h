#pragma once

#include "types.h"

// Copies 32 halfwords (64 bytes) from the argument to 0x4000380.
void G3X_SetToonTable(const u16 *arg0);
