#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

void SetInputSlotRepeat(InputSlot *slot, unsigned int mask, unsigned int delayLimit, unsigned int intervalLimit);
