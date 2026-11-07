#pragma once

#include "types.h"

// Hands the card bus to the ARM7 (sets bit 0x800 of the halfword at 0x04000204). OS_UnlockCard runs it before it
// releases the card lock word.
void OSi_FreeCardBus(void);
// Hands the card bus to the ARM9 (clears bit 0x800 of the halfword at 0x04000204). OS_LockCard runs it once the card
// lock word is taken.
void OSi_AllocateCardBus(void);
