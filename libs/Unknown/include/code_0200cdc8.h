#pragma once

#include "types.h"

// Sets bit 0x800 of the halfword at 0x04000204. OS_UnlockCard runs it before it releases the lock word at
// 0x027fffe0.
u32 SetCardSlotAccessBit(void);
// Clears bit 0x800 of the halfword at 0x04000204. OS_LockCard runs it once the lock word at 0x027fffe0 is taken.
u32 ClearCardSlotAccessBit(void);
