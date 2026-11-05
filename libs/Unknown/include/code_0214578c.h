#pragma once

#include "types.h"

// Releases access target 2 for the lock id.
void CARD_UnlockBackup(u16 a);
// Takes access target 2 for the lock id.
void CARD_LockBackup(u16 a);
// Calls OS_UnlockCard with the id, then releases access target 1 for the id.
void CARD_UnlockRom(u16 a);
// Takes access target 1 for the lock id, then calls OS_LockCard with the id.
void CARD_LockRom(u16 a);
