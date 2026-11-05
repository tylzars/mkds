#pragma once

#include "types.h"

// Jumps to OS_UnlockCartridge with its argument unchanged.
s32 OS_UnLockCartridge(u32 a);
s32 IdAlloc(void);
void IdFree(s32 a);
