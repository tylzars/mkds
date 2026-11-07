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
    OSLockWord *lockWord;
    volatile u32 zero;

    if (gLockInitialized != 0) {
        return;
    }
    gLockInitialized = 1;
    ((OSLockWord *) 0x027ffff0)->mLockFlag = 0;
    OS_LockByWord(0x7e, (OSLockWord *) 0x027ffff0, 0);
    lockWord = (OSLockWord *) 0x027ffff0;
    if (lockWord->mExtension != 0) {
        do {
            OSi_WaitByLoop();
        } while (lockWord->mExtension != 0);
    }
    *(u32 *) 0x027fffb0 = 0xffffffff;
    *(u32 *) 0x027fffb4 = 0xffff0000;
    zero = 0;
    MIi_CpuClear32(zero, (void *) 0x027fffc0, 0x28);
    reg_MI_EXMEMCNT |= 0x800;
    reg_MI_EXMEMCNT |= 0x80;
    OS_UnlockByWord(0x7e, (OSLockWord *) 0x027ffff0, 0);
    OS_LockByWord(0x7f, (OSLockWord *) 0x027ffff0, 0);
}

s32 OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    s32 lastLockFlag;

    lastLockFlag = OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFiq);
    while (lastLockFlag > 0) {
        OSi_WaitByLoop();
        lastLockFlag = OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFiq);
    }
    return lastLockFlag;
}

s32 OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoLockByWord(lockID, lockp, ctrlFuncp, 0);
}

s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    u32 lastInterrupts;

    if (lockID != lockp->mOwnerID) {
        return -2;
    }
    if (disableFiq != 0) {
        lastInterrupts = OS_DisableInterrupts_IrqAndFiq();
    } else {
        lastInterrupts = OS_DisableInterrupts();
    }
    lockp->mOwnerID = 0;
    if (ctrlFuncp != 0) {
        ctrlFuncp();
    }
    lockp->mLockFlag = 0;
    if (disableFiq != 0) {
        OS_RestoreInterrupts_IrqAndFiq(lastInterrupts);
    } else {
        OS_RestoreInterrupts(lastInterrupts);
    }
    return 0;
}

s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, 0);
}

s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    u32 lastInterrupts;
    s32 lastLockFlag;

    if (disableFiq != 0) {
        lastInterrupts = OS_DisableInterrupts_IrqAndFiq();
    } else {
        lastInterrupts = OS_DisableInterrupts();
    }
    lastLockFlag = MI_SwapWord(lockID, &lockp->mLockFlag);
    if (lastLockFlag == 0) {
        if (ctrlFuncp != 0) {
            ctrlFuncp();
        }
        lockp->mOwnerID = lockID;
    }
    if (disableFiq != 0) {
        OS_RestoreInterrupts_IrqAndFiq(lastInterrupts);
    } else {
        OS_RestoreInterrupts(lastInterrupts);
    }
    return lastLockFlag;
}

s32 OS_UnlockCartridge(u16 lockID) {
    return OSi_DoUnlockByWord(lockID, (OSLockWord *) 0x027fffe8, OSi_FreeCartridgeBus, 1);
}

s32 OS_TryLockCartridge(u16 lockID) {
    return OSi_DoTryLockByWord(lockID, (OSLockWord *) 0x027fffe8, OSi_AllocateCartridgeBus, 1);
}
