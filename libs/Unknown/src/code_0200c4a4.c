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
        InitCartridgeState();
        PxiInit();
        while (PxiCallbackBitIsSet(13, 1) == 0) {
        }
        PxiCallbackSet(13, (UnkFunc *) ReceiveCartridgeHeaderReply);
        InitCartridgeHeaderCopy();
        PxiCallbackSet(13, 0);
        PxiCallbackSet(13, (UnkFunc *) ReceiveCartridgeRemovalMessage);
        gCartridgeRemovalCallback = 0;
    }
}

void InitCartridgeHeaderCopy(void) {
    u32 v;
    u16 w;
    Unk0200c4a4 a;
    Unk0200c4a4 b;
    s32 c;
    s32 i;
    Unk027ffc30 *s;
    Unk0216fe20 *d;

    if (gHeaderCopyStarted != 0) {
        return;
    }
    gHeaderCopyStarted = 1;
    if ((*(u16 *) 0x04000300 & 1) == 0) {
        return;
    }
    v = OS_SetIrqMask(0x40000);
    w = reg_OS_IME;
    reg_OS_IME = 1;
    LockCartridgeAndDisableIrq(gCartridgeState.mLockId, &a);
    c = (*(u16 *) 0x04000204 & 0x8000) >> 15;
    SaveAndSetExMemControlBits(&b);
    *(u16 *) 0x04000204 = *(u16 *) 0x04000204 & ~0x8000;
    DC_InvalidateRange(((u8 *) &gCartridgeHeaderCopy + 0x80), 0x40);
    MI_DmaCopy16(1, (const void *) 0x08000080, ((u8 *) &gCartridgeHeaderCopy + 0x80), 0x40);
    *(u16 *) 0x04000204 = (*(u16 *) 0x04000204 & ~0x8000) | (c << 15);
    RestoreExMemControlBits(&b);
    UnlockCartridgeAndRestoreIrq(gCartridgeState.mLockId, &a);
    d = &gCartridgeHeaderCopy;
    s = (Unk027ffc30 *) 0x027ffc30;
    s->mIdHalfword = gCartridgeHeaderCopy.mHeaderTailCopy.mUnk_3e;
    for (i = 0; i < 3; i++) {
        ((u8 *) 0x027ffc32)[i] = d->mHeaderTailCopy.mUnk_35[i];
    }
    s->mUnk_06 = d->mHeaderTailCopy.mUnk_30;
    s->mIdWord = d->mHeaderTailCopy.mUnk_2c;
    MemCopyWords((void *) 0xffff0020, gCartridgeHeaderCopy.mUnk_04, 0x9c);
    DC_FlushAll();
    SendTag13WordUntilAccepted(((((u32) &gCartridgeHeaderCopy - 0x02000000) >> 5) << 6) | 1);
    while (gCartridgeState.mReplyReceived != 1) {
        WaitByLoop(1);
    }
    reg_OS_IME;
    reg_OS_IME = w;
    OS_SetIrqMask(v);
}

void ReceiveCartridgeHeaderReply(u32 a, u32 b) {
    if ((b & 0x3f) == 1) {
        gCartridgeState.mReplyReceived = 1;
    } else {
        IrqDisableLoopForever();
    }
}

void ReceiveCartridgeRemovalMessage(u32 a, u32 b) {
    s32 r;

    if ((b & 0x3f) == 0x11) {
        r = 0;
        if (gCartridgeRemovalCallback != 0) {
            r = gCartridgeRemovalCallback();
        }
        if (r != 0) {
            CTRDG_TerminateForPulledOut();
            return;
        }
    } else {
        IrqDisableLoopForever();
    }
}

void CTRDG_TerminateForPulledOut(void) {
    SendTag13WordUntilAccepted(2);
    IrqDisableLoopForever();
}

void InitCartridgeState(void) {
    u32 v;

    v = 0;
    CpuSet(&v, &gCartridgeState, 0x05000001);
    gCartridgeState.mLockId = IdAlloc();
}

s32 CTRDG_IsExisting(void) {
    s32 ret;
    Unk0200c4a4 a;
    Unk0200c4a4 b;
    Unk027ffc30 *s;
    Unk08000000 *c;

    s = (Unk027ffc30 *) 0x027ffc30;
    c = (Unk08000000 *) 0x08000000;
    ret = 1;
    if (s->mIdHalfword == 0xffff) {
        return 0;
    }
    if (s->mUnk_05_1 == 1) {
        return 0;
    }
    LockCartridgeAndDisableIrq(gCartridgeState.mLockId, &a);
    SaveAndSetExMemControlBits(&b);
    if ((c->mIdSelector == 0x96 && s->mIdHalfword != c->mIdHalfword) ||
        (c->mIdSelector != 0x96 && s->mIdHalfword != *(u16 *) 0x0801fffe) ||
        (s->mIdWord != c->mIdWord && s->mUnk_05_0)) {
        s->mUnk_05_1 = 1;
        ret = 0;
    }
    RestoreExMemControlBits(&b);
    UnlockCartridgeAndRestoreIrq(gCartridgeState.mLockId, &a);
    return ret;
}

void SaveAndSetExMemControlBits(Unk0200c4a4 *p) {
    p->mUnk_00 = (reg_MI_EXMEMCNT & 0xc) >> 2;
    p->mUnk_04 = (reg_MI_EXMEMCNT & 0x10) >> 4;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | 0xc;
    reg_MI_EXMEMCNT &= ~0x10;
}

void RestoreExMemControlBits(Unk0200c4a4 *p) {
    u32 a;
    u32 b;

    a = p->mUnk_00;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | (a << 2);
    b = p->mUnk_04;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0x10) | (b << 4);
}

void LockCartridgeAndDisableIrq(u32 a, Unk0200c4a4 *p) {
    for (;;) {
        p->mUnk_04 = IrqDisable();
        p->mUnk_00 = SwapLockGetHolderId((SwapLockSlot *) 0x027fffe8) & 0x40;
        if (p->mUnk_00 != 0) {
            break;
        }
        if (OS_TryLockCartridge(a) == 0) {
            break;
        }
        IrqRestore(p->mUnk_04);
        WaitByLoop(1);
    }
}

void UnlockCartridgeAndRestoreIrq(u32 a, Unk0200c4a4 *p) {
    if (p->mUnk_00 == 0) {
        OS_UnLockCartridge(a);
    }
    IrqRestore(p->mUnk_04);
}
