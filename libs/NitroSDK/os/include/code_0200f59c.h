#pragma once

#include "types.h"

// Returns the timer 0 count register (0x04000100) as a u16.
u32 OS_GetTickLo(void);
