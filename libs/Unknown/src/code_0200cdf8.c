#include "code_0200cdf8.h"
#include "code_0200ce60.h"
#include "code_0200cdc8.h"

s32 OS_LockCard(u32 a) {
    return SwapLockSpin(a, (SwapLockSlot *) 0x027fffe0, ClearCardSlotAccessBit);
}

s32 OS_UnlockCard(u32 a) {
    return SwapLockUnlock(a, (SwapLockSlot *) 0x027fffe0, SetCardSlotAccessBit);
}
