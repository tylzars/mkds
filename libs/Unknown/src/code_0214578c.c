#include "code_0214578c.h"
#include "code_0200cdf8.h"
#include "code_021458c4.h"

// Takes the ROM target for the lock id, then OS_LockCard.
void CARD_LockRom(u16 lockId) {
    CARDi_LockResource(lockId, 1);
    OS_LockCard(lockId);
}

// Calls OS_UnlockCard, then gives the ROM target back.
void CARD_UnlockRom(u16 lockId) {
    OS_UnlockCard(lockId);
    CARDi_UnlockResource(lockId, 1);
}

// Takes the backup target for the lock id.
void CARD_LockBackup(u16 lockId) {
    CARDi_LockResource(lockId, 2);
}

// Gives the backup target back.
void CARD_UnlockBackup(u16 lockId) {
    CARDi_UnlockResource(lockId, 2);
}
