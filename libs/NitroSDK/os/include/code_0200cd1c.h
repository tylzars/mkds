#pragma once

#include "types.h"

// Jumps to OS_UnlockCartridge with its argument unchanged.
s32 OS_UnLockCartridge(u16 lockID);
// Takes a free lock id out of the lock id table and returns it, or -3 when none is left.
s32 OS_GetLockID(void);
// Puts a lock id back into the lock id table.
void OS_ReleaseLockID(u16 lockID);
