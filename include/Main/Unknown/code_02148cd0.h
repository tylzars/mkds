#pragma once

#include "types.h"

// Returns the total byte size of the banks whose bits (0 to 8) are set in a: 0x20000 each for bits 0-3, 0x10000 for bit
// 4, 0x4000 for bits 5, 6 and 8, 0x8000 for bit 7.
u32 ComputeVramBankSize(u32 arg0);
