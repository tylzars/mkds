#include "code_021458c4.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02000000.h"
#include "code_021457ec.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146a00.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217f000.h"
#include "code_0200c914.h"
#include "code_0200db4c.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "code_0214d3d8.h"
#include "code_0214d5b8.h"
#include "registers.h"
#include "code_02146af4.h"

Unk021458b4 gRequestBlock;
u32 gRomBaseOffset;
Unk02146154 gRomReadState;

void WorkerTaskLoop(void *a) {
    Unk021458c4 *p;
    u32 s;

    p = &gAccessState;
    for (;;) {
        s = IrqDisable();
        while ((p->mUnk_114 & 8) == 0) {
            p->mUnk_104 = &p->mUnk_44;
            ThreadWait(0);
        }
        IrqRestore(s);
        p->mUnk_40(p);
    }
}

int SendRequestWithRetries(Unk021458c4 *p, s32 a, s32 b) {
    u32 s;
    s32 v;
    Unk021458b4 *q;

    if (!(p->mUnk_114 & 2)) {
        p->mUnk_114 |= 2;
        if (PxiCallbackBitIsSet(11, 1) == 0) {
            do {
                func_0200fd10(100);
            } while (PxiCallbackBitIsSet(11, 1) == 0);
        }
        SendRequestWithRetries(p, 0, 1);
    }
    DC_FlushRange(p->mUnk_00, 0x40);
    DC_WaitWriteBufferEmpty();
    do {
        p->mUnk_04 = a;
        p->mUnk_114 |= 0x20;
        while (PxiSendFifoWord(11, a, 1) < 0) {
        }
        if (a == 0) {
            q = p->mUnk_00;
            while (PxiSendFifoWord(11, (u32) q, 1) < 0) {
            }
        }
        s = IrqDisable();
        while (p->mUnk_114 & 0x20) {
            ThreadWait(0);
        }
        IrqRestore(s);
        v = p->mUnk_00->mUnk_00;
    } while (v == 4 && --b > 0);
    return v == 0;
}

int CopyFromRomPageBuffer(Unk02146154 *p) {
    Unk021458c4 *d;
    u32 a;
    u32 n;
    u32 m;

    d = &gAccessState;
    a = d->mUnk_1c & -0x200;
    if (a == p->mUnk_08) {
        m = d->mUnk_1c - a;
        n = 0x200 - m;
        if (n > d->mUnk_24) {
            n = d->mUnk_24;
        }
        MemCopy((u8 *) p->mUnk_20 + m, (void *) d->mUnk_20, n);
        d->mUnk_1c += n;
        d->mUnk_20 += n;
        d->mUnk_24 -= n;
    }
    return d->mUnk_24 != 0;
}

void WriteRomCommandBytes(u32 a, u32 b) {
    while (reg_MI_MCCNT1 & 0x80000000) {
    }
    *(vu8 *) 0x040001a1 = 0xc0;
    *(vu8 *) 0x040001a8 = a >> 24;
    *(vu8 *) 0x040001a9 = a >> 16;
    *(vu8 *) 0x040001aa = a >> 8;
    *(vu8 *) 0x040001ab = a;
    *(vu8 *) 0x040001ac = b >> 24;
    *(vu8 *) 0x040001ad = b >> 16;
    *(vu8 *) 0x040001ae = b >> 8;
    *(vu8 *) 0x040001af = b;
}

void StartRomPageDma(void) {
    Unk021458c4 *d;

    d = (Unk021458c4 *) (u32) &gAccessState;
    StartCardDmaCopy(d->mUnk_28, (void *) 0x04100010, (void *) d->mUnk_20, 0x200);
    WriteRomCommandBytes((d->mUnk_1c >> 8) | 0xb7000000, d->mUnk_1c << 24);
    reg_MI_MCCNT1 = gRomReadState.mUnk_04;
}

void AdvanceRomDmaRead(void) {
    Unk021458c4 *p;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    MI_StopDma(gAccessState.mUnk_28);
    gAccessState.mUnk_1c += 0x200;
    gAccessState.mUnk_20 += 0x200;
    gAccessState.mUnk_24 -= 0x200;
    if (gAccessState.mUnk_24 == 0) {
        InterruptEnableClearBits(0x80000);
        InterruptFlagWrite(0x80000);
        p = (Unk021458c4 *) (u32) &gAccessState;
        p->mUnk_00->mUnk_00 = 0;
        cb = p->mUnk_38;
        arg = p->mUnk_3c;
        s = IrqDisable();
        p->mUnk_114 &= ~0x4c;
        ThreadQueueSetAllRunnable(&p->mUnk_10c);
        if (p->mUnk_114 & 0x10) {
            ThreadSetRunnable(&p->mUnk_44);
        }
        IrqRestore(s);
        if (cb != 0) {
            cb(arg);
        }
    } else {
        StartRomPageDma();
    }
}

int TryStartRomDmaRead(Unk02146154 *p) {
    u32 v;
    int t;
    Unk021458c4 *d;
    u32 addr;
    u32 len;
    int r;
    int b;
    int c;
    u32 end;
    u32 s;
    u32 rem;

    d = &gAccessState;
    r = 0;
    b = 0;
    c = 0;
    addr = d->mUnk_20;
    len = d->mUnk_24;
    if ((addr & 3) == 0 && d->mUnk_28 <= 3) {
        int a;
        v = OS_GetDTCMAddress();
        end = addr + len;
        t = 1;
        a = 0;
        if (end > 0x01ff8000) {
            if (addr < 0x02000000) {
                a = 1;
            } else {
                a = 0;
            }
        }
        if (a == 0) {
            if (v >= end || v + 0x4000 <= addr) {
                t = 0;
            }
        }
        if (t == 0) {
            c = 1;
        }
    }
    if (c != 0) {
        if (((d->mUnk_1c | len) & 0x1ff) == 0) {
            b = 1;
        }
    }
    if (b != 0 && len != 0) {
        r = 1;
    }
    p->mUnk_04 = (*(u32 *) 0x027ffe60 & ~0x07000000) | 0xa1000000;
    if (r != 0) {
        s = IrqDisable();
        IC_InvalidateRange((void *) addr, len);
        rem = addr & 31;
        if (rem != 0) {
            addr -= rem;
            DC_StoreRange((void *) addr, 32);
            DC_StoreRange((void *) (addr + len), 32);
            len += 32;
        }
        DC_InvalidateRange((void *) addr, len);
        DC_WaitWriteBufferEmpty();
        InterruptHandlerSet(0x80000, AdvanceRomDmaRead);
        InterruptFlagWrite(0x80000);
        InterruptEnableSetBits(0x80000);
        IrqRestore(s);
        StartRomPageDma();
    }
    return r;
}

void ReadRomPagesByCpu(Unk02146154 *p) {
    Unk021458c4 *d;
    u32 *buf;
    u32 *q;
    u32 a;
    u32 n;
    u32 s;
    u32 w;

    d = &gAccessState;
    q = p->mUnk_20;
    for (;;) {
        a = d->mUnk_1c & -0x200;
        if (a != d->mUnk_1c || (((u32) (buf = (u32 *) d->mUnk_20)) & 3) != 0 || d->mUnk_24 < 0x200) {
            buf = q;
            p->mUnk_08 = a;
        }
        WriteRomCommandBytes((a >> 8) | 0xb7000000, a << 24);
        reg_MI_MCCNT1 = p->mUnk_04;
        n = 0;
        do {
            s = reg_MI_MCCNT1;
            if (s & 0x800000) {
                w = reg_MI_MCD1;
                if (n < 0x200) {
                    buf[n] = w;
                    n++;
                }
            }
        } while (s & 0x80000000);
        if ((u32) buf == d->mUnk_20) {
            gAccessState.mUnk_1c += 0x200;
            gAccessState.mUnk_20 += 0x200;
            gAccessState.mUnk_24 -= 0x200;
            if (gAccessState.mUnk_24 == 0) {
                return;
            }
        } else if (CopyFromRomPageBuffer(p) == 0) {
            return;
        }
    }
}

void RunRomRead(Unk021458c4 *a) {
    Unk021458c4 *p;
    Unk02146154 *q;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    q = &gRomReadState;
    if (CopyFromRomPageBuffer(q) != 0) {
        q->mUnk_00(q);
    }
    p = (Unk021458c4 *) (u32) &gAccessState;
    p->mUnk_00->mUnk_00 = 0;
    cb = p->mUnk_38;
    arg = p->mUnk_3c;
    s = IrqDisable();
    p->mUnk_114 &= ~0x4c;
    ThreadQueueSetAllRunnable(&p->mUnk_10c);
    if (p->mUnk_114 & 0x10) {
        ThreadSetRunnable(&p->mUnk_44);
    }
    IrqRestore(s);
    if (cb != 0) {
        cb(arg);
    }
}

void StartRomRead(u32 a, u32 b, u32 c, u32 d, UnkFunc *e, u32 f, u32 g) {
    Unk021458c4 *p;
    Unk02146154 *q;
    u32 s;

    p = (Unk021458c4 *) (u32) &gAccessState;
    q = &gRomReadState;
    CARD_CheckEnabled();
    s = IrqDisable();
    while (p->mUnk_114 & 4) {
        ThreadWait(&p->mUnk_10c);
    }
    p->mUnk_114 |= 4;
    p->mUnk_38 = e;
    p->mUnk_3c = f;
    IrqRestore(s);
    p->mUnk_28 = a;
    p->mUnk_1c = b + gRomBaseOffset;
    p->mUnk_20 = c;
    p->mUnk_24 = d;
    if (a <= 3) {
        MI_StopDma(a);
    }
    if (TryStartRomDmaRead(q) != 0) {
        if (g == 0) {
            CARD_WaitRomAsync();
        }
    } else if (g != 0) {
        StartWorkerTask(RunRomRead);
    } else {
        p->mUnk_104 = data_0216ff5c.mCurrentThread;
        RunRomRead(p);
    }
}

void CARD_Init(void) {
    Unk021458c4 *p;

    p = &gAccessState;
    if (p->mUnk_114 != 0) {
        return;
    }
    p->mUnk_114 = 1;
    p->mUnk_1c = p->mUnk_20 = p->mUnk_24 = 0;
    p->mUnk_28 = -1;
    p->mUnk_38 = 0;
    p->mUnk_3c = 0;
    gRomBaseOffset = 0;
    InitBackupAndRomAccess();
    gRomReadState.mUnk_00 = GetRomPageReader();
    CARD_InitPulledOutCallback();
}

int CARD_WaitRomAsync(void) {
    return WaitForTransferEnd();
}

UnkFunc *GetRomPageReader(void) {
    return (UnkFunc *) ReadRomPagesByCpu;
}

void RunBackupTransfer(Unk021458c4 *p) {
    u32 a;
    u32 b;
    u32 c;
    u32 n;
    u32 *buf;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    a = p->mUnk_2c;
    b = p->mUnk_34;
    c = p->mUnk_30;
    func_02000b44((u32) (BuildInfo + 0x24));
    do {
        n = p->mUnk_24;
        if (n > 0x100) {
            n = 0x100;
        }
        p->mUnk_00->mUnk_14 = n;
        if (p->mUnk_114 & 0x40) {
            p->mUnk_114 &= ~0x40;
            p->mUnk_00->mUnk_00 = 7;
            break;
        }
        if (b == 0) {
            DC_InvalidateRange(p->mUnk_120, n);
            p->mUnk_00->mUnk_0c = p->mUnk_1c;
            p->mUnk_00->mUnk_10 = (u32) p->mUnk_120;
        } else {
            MemCopy((void *) p->mUnk_1c, p->mUnk_120, n);
            DC_FlushRange(p->mUnk_120, n);
            DC_WaitWriteBufferEmpty();
            p->mUnk_00->mUnk_0c = (s32) p->mUnk_120;
            p->mUnk_00->mUnk_10 = p->mUnk_20;
        }
        if (SendRequestWithRetries(p, a, c) == 0) {
            break;
        }
        if (b == 2) {
            if (SendRequestWithRetries(p, 9, 1) == 0) {
                break;
            }
        } else if (b == 0) {
            MemCopy(p->mUnk_120, (void *) p->mUnk_20, n);
        }
        p->mUnk_1c += n;
        p->mUnk_20 += n;
        p->mUnk_24 -= n;
    } while (p->mUnk_24 != 0);
    cb = p->mUnk_38;
    arg = p->mUnk_3c;
    s = IrqDisable();
    p->mUnk_114 &= ~0x4c;
    ThreadQueueSetAllRunnable(&p->mUnk_10c);
    if (p->mUnk_114 & 0x10) {
        ThreadSetRunnable(&p->mUnk_44);
    }
    IrqRestore(s);
    if (cb != 0) {
        cb(arg);
    }
}

int StartBackupTransfer(u32 a, u32 b, u32 c, UnkFunc *d, void *e, u32 f, u32 g, u32 h, u32 i) {
    Unk021458c4 *p;
    u32 s;

    p = (Unk021458c4 *) (u32) &gAccessState;
    func_02000b44((u32) (BuildInfo + 0x24));
    s = IrqDisable();
    while (p->mUnk_114 & 4) {
        ThreadWait(&p->mUnk_10c);
    }
    p->mUnk_114 |= 4;
    p->mUnk_38 = d;
    p->mUnk_3c = (u32) e;
    IrqRestore(s);
    p->mUnk_1c = a;
    p->mUnk_20 = b;
    p->mUnk_24 = c;
    p->mUnk_2c = g;
    p->mUnk_30 = h;
    p->mUnk_34 = i;
    if (f != 0) {
        StartWorkerTask(RunBackupTransfer);
        return 1;
    }
    gAccessState.mUnk_104 = data_0216ff5c.mCurrentThread;
    RunBackupTransfer(p);
    return p->mUnk_00->mUnk_00 == 0;
}

int CARD_IdentifyBackup(s32 a) {
    Unk021458c4 *p;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    p = &gAccessState;
    func_02000b44((u32) (BuildInfo + 0x24));
    if (a == 0) {
        IrqDisableLoopForever();
    }
    CARD_CheckEnabled();
    s = IrqDisable();
    while (p->mUnk_114 & 4) {
        ThreadWait(&p->mUnk_10c);
    }
    p->mUnk_114 |= 4;
    p->mUnk_38 = 0;
    p->mUnk_3c = 0;
    IrqRestore(s);
    SetupBackupSpec(a);
    gAccessState.mUnk_104 = data_0216ff5c.mCurrentThread;
    SendRequestWithRetries(p, 2, 1);
    p->mUnk_00->mUnk_0c = 0;
    p->mUnk_00->mUnk_10 = (u32) p->mUnk_120;
    p->mUnk_00->mUnk_14 = 1;
    SendRequestWithRetries(p, 6, 1);
    cb = p->mUnk_38;
    arg = p->mUnk_3c;
    s = IrqDisable();
    p->mUnk_114 &= ~0x4c;
    ThreadQueueSetAllRunnable(&p->mUnk_10c);
    if (p->mUnk_114 & 0x10) {
        ThreadSetRunnable(&p->mUnk_44);
    }
    IrqRestore(s);
    if (cb != 0) {
        cb(arg);
    }
    return p->mUnk_00->mUnk_00 == 0;
}

int CARD_WaitBackupAsync(void) {
    return WaitForTransferEnd();
}

int CARD_TryWaitBackupAsync(void) {
    return IsTransferIdle();
}

void SetupBackupSpec(s32 a) {
    Unk021458b4 *p;
    u32 m;
    u32 x;

    p = gAccessState.mUnk_00;
    MemFill(&p->mUnk_18, 0, 0x28);
    p->mUnk_04 = a;
    if (a == 0) {
        return;
    }
    m = 1 << ((a >> 8) & 0xff);
    p->mUnk_18 = m;
    x = a & 0xff;
    if (x == 1) {
        switch (m) {
            case 0x200:
                p->mUnk_20 = 0x10;
                p->mUnk_24 = 1;
                p->mUnk_28 = 0x4f;
                break;
            case 0x2000:
                p->mUnk_20 = 0x20;
                p->mUnk_24 = 2;
                p->mUnk_28 = 0x4f;
                break;
            case 0x10000:
                p->mUnk_20 = 0x80;
                p->mUnk_24 = 2;
                p->mUnk_28 = 0x9e;
                break;
            default:
                goto fail;
        }
    } else if (x == 2) {
        switch (m) {
            case 0x40000:
                p->mUnk_2c = 0x18b;
                p->mUnk_30 = 0x127f;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                p->mUnk_34 = 0x13435;
                break;
            case 0x80000:
            case 0x100000:
                p->mUnk_2c = 0x18b;
                p->mUnk_30 = 0;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                break;
            default:
                goto fail;
        }
        p->mUnk_1c = 0x10000;
        p->mUnk_20 = 0x100;
        p->mUnk_24 = 3;
        p->mUnk_28 = 0x4f;
    } else if (x == 3 && (m == 0x2000 || m == 0x8000)) {
        p->mUnk_20 = m;
        p->mUnk_24 = 2;
    } else {
    fail:
        p->mUnk_04 = 0;
        p->mUnk_18 = 0;
        gAccessState.mUnk_00->mUnk_00 = 3;
        return;
    }
}

void StartWorkerTask(UnkFunc *f) {
    Unk021458c4 *p;

    p = (Unk021458c4 *) (u32) &gAccessState;
    ThreadSetSortKey(&p->mUnk_44, p->mUnk_108);
    p->mUnk_104 = &p->mUnk_44;
    p->mUnk_40 = f;
    p->mUnk_114 |= 8;
    ThreadSetRunnable(&p->mUnk_44);
}

void LockAccessTarget(u32 a, u32 b) {
    Unk021458c4 *p;
    u32 s;

    p = (Unk021458c4 *) (u32) &gAccessState;
    s = IrqDisable();
    if (p->mUnk_08 == a) {
        if (p->mUnk_18 != b) {
            IrqDisableLoopForever();
        }
    } else {
        while (p->mUnk_08 != -3) {
            ThreadWait(&p->mUnk_10);
        }
        p->mUnk_08 = a;
        p->mUnk_18 = b;
    }
    p->mUnk_0c++;
    p->mUnk_00->mUnk_00 = 0;
    IrqRestore(s);
}

void UnlockAccessTarget(u32 a, u32 b) {
    Unk021458c4 *p;
    u32 s;

    p = &gAccessState;
    s = IrqDisable();
    if (p->mUnk_08 != a || p->mUnk_0c == 0) {
        IrqDisableLoopForever();
    } else {
        if (p->mUnk_18 != b) {
            IrqDisableLoopForever();
        }
        p->mUnk_0c--;
        if (p->mUnk_0c == 0) {
            p->mUnk_08 = -3;
            p->mUnk_18 = 0;
            ThreadQueueSetAllRunnable(&p->mUnk_10);
        }
    }
    p->mUnk_00->mUnk_00 = 0;
    IrqRestore(s);
}

void InitBackupAndRomAccess(void) {
    Unk021458c4 *p;

    p = &gAccessState;
    p->mUnk_08 = -3;
    p->mUnk_0c = 0;
    p->mUnk_18 = 0;
    p->mUnk_00 = &gRequestBlock;
    MemFillWordsByBlock_inline(&gRequestBlock, 0x40);
    DC_FlushRange(&gRequestBlock, 0x40);
    if (*(u16 *) 0x027ffc40 != 2) {
        MemCopy((void *) 0x027ffe00, (void *) 0x027ffa80, 0x160);
    }
    p->mUnk_10.mTail = 0;
    p->mUnk_10.mHead = p->mUnk_10.mTail;
    p->mUnk_10c.mTail = 0;
    p->mUnk_10c.mHead = p->mUnk_10c.mTail;
    p->mUnk_108 = 4;
    ThreadInit(&p->mUnk_44, WorkerTaskLoop, 0, (u8 *) &gRomBaseOffset, 0x400, p->mUnk_108);
    ThreadSetRunnable(&p->mUnk_44);
    PxiCallbackSet(11, ReceiveRequestReply);
    if (*(u16 *) 0x027ffc40 != 2) {
        CARD_Enable(1);
    }
}
