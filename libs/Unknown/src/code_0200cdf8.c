#include "code_0200cdf8.h"
#include "code_0200ce60.h"
#include "code_0200cdc8.h"

s32 func_0200ce14(u32 a) {
    return SwapLockSpin(a, (SwapLockSlot *) 0x027fffe0, func_0200cde0);
}

s32 func_0200cdf8(u32 a) {
    return SwapLockUnlock(a, (SwapLockSlot *) 0x027fffe0, func_0200cdc8);
}
