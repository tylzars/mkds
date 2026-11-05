#pragma once

#include "types.h"

// Returns when the enable flag is not 0, otherwise calls IrqDisableLoopForever.
void CARD_CheckEnabled(void);
