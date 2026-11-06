#pragma once

#include "types.h"

// Optionally clears the bits irqFlags of the IRQ check flag, then sleeps the thread until one of them is set.
void OS_WaitIrq(u32 clear, u32 irqFlags);
