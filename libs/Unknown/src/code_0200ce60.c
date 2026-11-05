#include "code_0200ce60.h"
#include "code_0200cdb0.h"
#include "code_0200ce30.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0200fc8c.h"
#include "registers.h"
#include "00/code_02188720.h"

s32 gLockInitialized;

void OS_InitLock(void) {
    SwapLockSlot *p;
    volatile u32 v;

    if (gLockInitialized != 0) {
        return;
    }
    gLockInitialized = 1;
    ((SwapLockSlot *) 0x027ffff0)->mUnk_00 = 0;
    SwapLockSpin(0x7e, (SwapLockSlot *) 0x027ffff0, 0);
    p = (SwapLockSlot *) 0x027ffff0;
    if (p->mUnk_06 != 0) {
        do {
            WaitByLoop4096();
        } while (p->mUnk_06 != 0);
    }
    *(u32 *) 0x027fffb0 = 0xffffffff;
    *(u32 *) 0x027fffb4 = 0xffff0000;
    v = 0;
    MemFillWords(v, (void *) 0x027fffc0, 0x28);
    reg_MI_EXMEMCNT |= 0x800;
    reg_MI_EXMEMCNT |= 0x80;
    SwapLockUnlock(0x7e, (SwapLockSlot *) 0x027ffff0, 0);
    SwapLockSpin(0x7f, (SwapLockSlot *) 0x027ffff0, 0);
}

s32 SwapLockSpinEx(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k) {
    s32 r;

    r = SwapLockTry(a, p, f, k);
    while (r > 0) {
        WaitByLoop4096();
        r = SwapLockTry(a, p, f, k);
    }
    return r;
}

s32 SwapLockSpin(u32 a, SwapLockSlot *p, u32 (*f)(void)) {
    return SwapLockSpinEx(a, p, f, 0);
}

s32 SwapLockUnlockEx(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k) {
    u32 s;

    if (a != p->mHolderId) {
        return -2;
    }
    if (k != 0) {
        s = IrqFiqDisable();
    } else {
        s = IrqDisable();
    }
    p->mHolderId = 0;
    if (f != 0) {
        f();
    }
    p->mUnk_00 = 0;
    if (k != 0) {
        IrqFiqRestore(s);
    } else {
        IrqRestore(s);
    }
    return 0;
}

s32 SwapLockUnlock(u32 a, SwapLockSlot *p, u32 (*f)(void)) {
    return SwapLockUnlockEx(a, p, f, 0);
}

s32 SwapLockTry(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k) {
    u32 s;
    s32 r;

    if (k != 0) {
        s = IrqFiqDisable();
    } else {
        s = IrqDisable();
    }
    r = WordSwap(a, &p->mUnk_00);
    if (r == 0) {
        if (f != 0) {
            f();
        }
        p->mHolderId = a;
    }
    if (k != 0) {
        IrqFiqRestore(s);
    } else {
        IrqRestore(s);
    }
    return r;
}

s32 OS_UnlockCartridge(u32 a) {
    return SwapLockUnlockEx(a, (SwapLockSlot *) 0x027fffe8, SetCartridgeSlotAccessBit, 1);
}

s32 OS_TryLockCartridge(u32 a) {
    return SwapLockTry(a, (SwapLockSlot *) 0x027fffe8, ClearCartridgeSlotAccessBit, 1);
}
