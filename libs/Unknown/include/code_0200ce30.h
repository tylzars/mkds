#pragma once

#include "types.h"

// Hands the cartridge bus to the ARM7 (sets bit 0x80 of the halfword at 0x04000204). OS_UnlockCartridge runs it
// before it releases the cartridge lock word.
void OSi_FreeCartridgeBus(void);
// Hands the cartridge bus to the ARM9 (clears bit 0x80 of the halfword at 0x04000204). OS_TryLockCartridge runs it
// once the cartridge lock word is taken.
void OSi_AllocateCartridgeBus(void);
