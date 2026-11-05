#pragma once

#include "types.h"

// Busy wait: calls func_0200fd10 with 0x1000 (1024 passes). Used between lock tries and while waiting for the
// halfword at 0x027ffff6 to become 0.
void WaitByLoop4096(void);
