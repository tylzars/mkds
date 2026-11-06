#pragma once

#include "types.h"

// Busy wait used between lock tries and while waiting for the lock word extension to become 0.
void OSi_WaitByLoop(void);
