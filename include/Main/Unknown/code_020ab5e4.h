#pragma once

#include "types.h"

typedef struct RepeatCounter RepeatCounter;

void SetupRepeatCounter(RepeatCounter *repeatCounter, unsigned int firstFireFrame, unsigned int repeatGap);
void SetupRepeatCounterDefault(RepeatCounter *repeatCounter);
