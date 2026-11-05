#pragma once

#include "types.h"

// Sets both words of the list head at 0x027e0000 to 0. The interrupt wait function sleeps on that list.
void OS_InitIrqTable(void);
