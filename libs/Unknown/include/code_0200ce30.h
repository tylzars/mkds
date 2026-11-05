#pragma once

#include "types.h"

// Sets bit 0x80 of the halfword at 0x04000204. OS_UnlockCartridge runs it before it releases the lock word at
// 0x027fffe8.
u32 SetCartridgeSlotAccessBit(void);
// Clears bit 0x80 of the halfword at 0x04000204. OS_TryLockCartridge runs it once the lock word at 0x027fffe8 is
// taken.
u32 ClearCartridgeSlotAccessBit(void);
