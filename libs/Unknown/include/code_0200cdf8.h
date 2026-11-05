#pragma once

#include "types.h"

// Releases the lock word at 0x027fffe0 when id a holds it, else returns -2. Sets bit 0x800 of 0x04000204, clears the
// owner id and the lock word with IRQ disabled, returns 0.
s32 OS_UnlockCard(u32 a);
// Takes the lock word at 0x027fffe0 for id a, retrying (with WaitByLoop4096 between tries) until it succeeds, with
// IRQ disabled during each try; clears bit 0x800 of 0x04000204 once it is taken. Returns the result of the last try,
// 0 when taken.
s32 OS_LockCard(u32 a);
