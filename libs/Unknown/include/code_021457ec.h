#pragma once

#include "types.h"

// Returns the first word of the request block: the result of the last request, 0 when it succeeded.
u32 CARD_GetResultCode(void);
// Returns 1 when value 4 of the flag word at +0x114 is clear, else 0.
int IsTransferIdle(void);
// With interrupts off, waits on the queue at +0x10c while value 4 of the flag word at +0x114 is set. Returns 1 when
// the first word of the request block is 0, else 0.
int WaitForTransferEnd(void);
// Stores the enable flag.
void CARD_Enable(u32 arg0);
