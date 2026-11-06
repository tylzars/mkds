#pragma once

#include "types.h"

// Empties the queue of threads waiting for an interrupt, the list at the start of the data TCM.
void OS_InitIrqTable(void);
