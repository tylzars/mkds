#include "code_0200c4a4.h"
#include "code_0200c914.h"
#include "code_0200cd1c.h"
#include "code_0200cdc0.h"
#include "code_0200ce60.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "code_0200c46c.h"
#include "code_0214c778.h"
#include "registers.h"
#include "Main/Unknown/code_0200007e.h"

#pragma thumb on

Unk0216fe04 gCartridgeState;
s32 gCartridgeInitStarted;
s32 gHeaderCopyStarted;
Unk0216fe20 gCartridgeHeaderCopy;
s32 (*gCartridgeRemovalCallback)(void);
s32 data_0216fe14;
s32 data_0216fe18;
s32 data_0216fe1c;

void CTRDG_Init(void) {
    if (gCartridgeInitStarted == 0) {
        gCartridgeInitStarted = 1;
        CTRDGi_InitCommon();
        PXI_Init();
        while (PXI_IsCallbackReady(13, 1) == 0) {
        }
        PXI_SetFifoRecvCallback(13, CTRDGi_CallbackForInitModuleInfo);
        CTRDGi_InitModuleInfo();
        PXI_SetFifoRecvCallback(13, 0);
        PXI_SetFifoRecvCallback(13, CTRDGi_PulledOutCallback);
        gCartridgeRemovalCallback = 0;
    }
}

// Runs once. Copies the cartridge header under the cartridge lock, fills the module info record from it, and sends the
// address of the header buffer on tag 13, then waits for the reply.
void CTRDGi_InitModuleInfo(void) {
    u32 savedIrqMask;
    u16 savedMasterEnable;
    Unk0200c4a4 lockInfo;
    Unk0200c4a4 romCycle;
    s32 priority;
    s32 i;
    Unk027ffc30 *idInfo;
    Unk0216fe20 *chb;

    if (gHeaderCopyStarted != 0) {
        return;
    }
    gHeaderCopyStarted = 1;
    if ((*(u16 *) 0x04000300 & 1) == 0) {
        return;
    }
    savedIrqMask = OS_SetIrqMask(0x40000);
    savedMasterEnable = reg_OS_IME;
    reg_OS_IME = 1;
    CTRDGi_LockByProcessor(gCartridgeState.mLockId, &lockInfo);
    priority = (reg_MI_EXMEMCNT & 0x8000) >> 15;
    CTRDGi_ChangeLatestAccessCycle(&romCycle);
    reg_MI_EXMEMCNT = reg_MI_EXMEMCNT & ~0x8000;
    DC_InvalidateRange(((u8 *) &gCartridgeHeaderCopy + 0x80), 0x40);
    MI_DmaCopy16(1, (const void *) 0x08000080, ((u8 *) &gCartridgeHeaderCopy + 0x80), 0x40);
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0x8000) | (priority << 15);
    CTRDGi_RestoreAccessCycle(&romCycle);
    CTRDGi_UnlockByProcessor(gCartridgeState.mLockId, &lockInfo);
    chb = &gCartridgeHeaderCopy;
    idInfo = (Unk027ffc30 *) 0x027ffc30;
    idInfo->mIdHalfword = gCartridgeHeaderCopy.mHeaderTailCopy.mUnk_3e;
    for (i = 0; i < 3; i++) {
        ((u8 *) 0x027ffc32)[i] = chb->mHeaderTailCopy.mUnk_35[i];
    }
    idInfo->mUnk_06 = chb->mHeaderTailCopy.mUnk_30;
    idInfo->mIdWord = chb->mHeaderTailCopy.mUnk_2c;
    MIi_CpuCopy32((void *) 0xffff0020, gCartridgeHeaderCopy.mUnk_04, 0x9c);
    DC_FlushAll();
    CTRDGi_SendtoPxi(((((u32) &gCartridgeHeaderCopy - 0x02000000) >> 5) << 6) | 1);
    while (gCartridgeState.mReplyReceived != 1) {
        WaitByLoop(1);
    }
    reg_OS_IME;
    reg_OS_IME = savedMasterEnable;
    OS_SetIrqMask(savedIrqMask);
}

void CTRDGi_CallbackForInitModuleInfo(u32 tag, u32 data) {
    if ((data & 0x3f) == 1) {
        gCartridgeState.mReplyReceived = 1;
    } else {
        OS_Terminate();
    }
}

void CTRDGi_PulledOutCallback(u32 tag, u32 data) {
    s32 terminateNow;

    if ((data & 0x3f) == 0x11) {
        terminateNow = 0;
        if (gCartridgeRemovalCallback != 0) {
            terminateNow = gCartridgeRemovalCallback();
        }
        if (terminateNow != 0) {
            CTRDG_TerminateForPulledOut();
            return;
        }
    } else {
        OS_Terminate();
    }
}

void CTRDG_TerminateForPulledOut(void) {
    CTRDGi_SendtoPxi(2);
    OS_Terminate();
}

void CTRDGi_InitCommon(void) {
    u32 zero;

    zero = 0;
    CpuSet(&zero, &gCartridgeState, 0x05000001);
    gCartridgeState.mLockId = OS_GetLockID();
}

s32 CTRDG_IsExisting(void) {
    s32 exists;
    Unk0200c4a4 lockInfo;
    Unk0200c4a4 romCycle;
    Unk027ffc30 *idInfo;
    Unk08000000 *romHeader;

    idInfo = (Unk027ffc30 *) 0x027ffc30;
    romHeader = (Unk08000000 *) 0x08000000;
    exists = 1;
    if (idInfo->mIdHalfword == 0xffff) {
        return 0;
    }
    if (idInfo->mUnk_05_1 == 1) {
        return 0;
    }
    CTRDGi_LockByProcessor(gCartridgeState.mLockId, &lockInfo);
    CTRDGi_ChangeLatestAccessCycle(&romCycle);
    if ((romHeader->mIdSelector == 0x96 && idInfo->mIdHalfword != romHeader->mIdHalfword) ||
        (romHeader->mIdSelector != 0x96 && idInfo->mIdHalfword != *(u16 *) 0x0801fffe) ||
        (idInfo->mIdWord != romHeader->mIdWord && idInfo->mUnk_05_0)) {
        idInfo->mUnk_05_1 = 1;
        exists = 0;
    }
    CTRDGi_RestoreAccessCycle(&romCycle);
    CTRDGi_UnlockByProcessor(gCartridgeState.mLockId, &lockInfo);
    return exists;
}

void CTRDGi_ChangeLatestAccessCycle(Unk0200c4a4 *r) {
    r->mUnk_00 = (reg_MI_EXMEMCNT & 0xc) >> 2;
    r->mUnk_04 = (reg_MI_EXMEMCNT & 0x10) >> 4;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | 0xc;
    reg_MI_EXMEMCNT &= ~0x10;
}

void CTRDGi_RestoreAccessCycle(Unk0200c4a4 *r) {
    u32 cycle1;
    u32 cycle2;

    cycle1 = r->mUnk_00;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | (cycle1 << 2);
    cycle2 = r->mUnk_04;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0x10) | (cycle2 << 4);
}

void CTRDGi_LockByProcessor(u16 lockID, Unk0200c4a4 *info) {
    for (;;) {
        info->mUnk_04 = OS_DisableInterrupts();
        info->mUnk_00 = OS_ReadOwnerOfLockWord((OSLockWord *) 0x027fffe8) & 0x40;
        if (info->mUnk_00 != 0) {
            break;
        }
        if (OS_TryLockCartridge(lockID) == 0) {
            break;
        }
        OS_RestoreInterrupts(info->mUnk_04);
        WaitByLoop(1);
    }
}

void CTRDGi_UnlockByProcessor(u16 lockID, Unk0200c4a4 *info) {
    if (info->mUnk_00 == 0) {
        OS_UnLockCartridge(lockID);
    }
    OS_RestoreInterrupts(info->mUnk_04);
}
