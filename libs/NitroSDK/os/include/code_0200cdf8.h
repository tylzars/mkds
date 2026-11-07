#pragma once

#include "types.h"

// Releases the card lock word when lockID holds it, else returns -2. Gives the card bus back to the ARM7, clears the
// owner id and the lock word with IRQ disabled, returns 0.
s32 OS_UnlockCard(u16 lockID);
// Takes the card lock word for lockID, retrying (with OSi_WaitByLoop between tries) until it succeeds, with IRQ
// disabled during each try; gives the card bus to the ARM9 once it is taken. Returns the result of the last try, 0
// when taken.
s32 OS_LockCard(u16 lockID);
