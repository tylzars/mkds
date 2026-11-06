#include "code_02020eb0.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200e77c.h"
#include "code_0214d5b8.h"
#include "code_02021764.h"

u32 data_021732cc;
u32 data_021732e8;
PxiCommand *data_021732d8;
PxiCommand *data_021732d0;
PxiCommand *data_021732c8;
PxiCommand *data_021732d4;
s32 data_021732dc;
s32 data_021732e0;
s32 data_021732e4;
PxiCommand *data_021732ec[13];
Unk020217b4 data_02173320;
PxiCommand data_021735a0[256];

u8 PxiCommandCallbackSet(s32 a, UnkFunc *b, void *c) {
    Unk02021734 *e;

    e = &data_02174da0[a];
    e->mUnk_00 = b;
    e->mUnk_04 = c;
    e->mUnk_08++;
    return e->mUnk_08;
}

void PxiCommandCallbackRun(s32 a) {
    Unk02021734 *e;

    e = &data_02174da0[a & 0xff];
    if (((a >> 8) & 0xff) != e->mUnk_08) {
        return;
    }
    if (e->mUnk_00 == 0) {
        return;
    }
    e->mUnk_00(e->mUnk_04);
}

void SND_CommandInit(void) {
    s32 i;
    PxiCommand *p;

    func_02020f84();
    data_021732c8 = data_021735a0;
    for (i = 0; i < 255; i++) {
        data_021735a0[i].mNext = &data_021735a0[i + 1];
    }
    data_021735a0[255].mNext = 0;
    data_021732d8 = &data_021735a0[255];
    data_021732d0 = 0;
    data_021732d4 = 0;
    data_021732e4 = 0;
    data_021732dc = 0;
    data_021732e0 = 0;
    data_021732e8 = 1;
    data_021732cc = 0;
    data_02174e00 = &data_02173320;
    func_020217b4(&data_02173320);
    p = PxiCommandAlloc(1);
    if (p == 0) {
        return;
    }
    p->mUnk_04 = 0x1d;
    p->mUnk_08 = (u32) data_02174e00;
    PxiCommandPendingAppend(p);
    PxiCommandSendPending(1);
}

PxiCommand *PxiCommandReclaim(u32 a) {
    u32 s;
    PxiCommand *p;
    PxiCommand *q;
    s32 i;

    s = OS_DisableInterrupts();
    if ((a & 1) != 0) {
        while (data_021732cc == func_02021834()) {
            OS_RestoreInterrupts(s);
            OS_SpinWait(0x64);
            s = OS_DisableInterrupts();
        }
    } else if (data_021732cc == func_02021834()) {
        OS_RestoreInterrupts(s);
        return 0;
    }
    i = data_021732dc;
    p = data_021732ec[i];
    data_021732dc = i + 1;
    if (data_021732dc > 8) {
        data_021732dc = 0;
    }
    q = p;
    while (q->mNext != 0) {
        q = q->mNext;
    }
    if (data_021732d8 != 0) {
        data_021732d8->mNext = p;
    } else {
        data_021732c8 = p;
    }
    data_021732d8 = q;
    data_021732e4--;
    data_021732cc++;
    OS_RestoreInterrupts(s);
    return p;
}

PxiCommand *PxiCommandAlloc(u32 a) {
    PxiCommand *p;

    if (func_02020eb0() == 0) {
        return 0;
    }
    p = PxiCommandPoolRemoveHead();
    if (p != 0) {
        return p;
    }
    if ((a & 1) == 0) {
        return 0;
    }
    if (SND_CountWaitingCommand() > 0) {
        while (PxiCommandReclaim(0) != 0) {
        }
        p = PxiCommandPoolRemoveHead();
        if (p != 0) {
            return p;
        }
    } else {
        PxiCommandSendPending(1);
    }
    func_02020f50();
    do {
        PxiCommandReclaim(1);
        p = PxiCommandPoolRemoveHead();
    } while (p == 0);
    return p;
}

void PxiCommandPendingAppend(PxiCommand *p) {
    u32 s;
    PxiCommand *t;

    s = OS_DisableInterrupts();
    t = data_021732d4;
    if (t == 0) {
        data_021732d4 = p;
        data_021732d0 = p;
    } else {
        t->mNext = p;
        data_021732d4 = p;
    }
    p->mNext = 0;
    OS_RestoreInterrupts(s);
}

u32 PxiCommandSendPending(u32 a) {
    u32 s;

    s = OS_DisableInterrupts();
    if (data_021732d0 == 0) {
        OS_RestoreInterrupts(s);
        return 1;
    }
    if (data_021732e4 >= 8) {
        if ((a & 1) == 0) {
            OS_RestoreInterrupts(s);
            return 0;
        }
        do {
            PxiCommandReclaim(1);
        } while (data_021732e4 >= 8);
    }
    DC_FlushRange(data_021735a0, 0x1800);
    if (PxiSendFifoWord(7, (u32) data_021732d0, 0) < 0) {
        if ((a & 1) == 0) {
            OS_RestoreInterrupts(s);
            return 0;
        }
        if (PxiSendFifoWord(7, (u32) data_021732d0, 0) < 0) {
            do {
                OS_RestoreInterrupts(s);
                OS_SpinWait(0x64);
                s = OS_DisableInterrupts();
            } while (PxiSendFifoWord(7, (u32) data_021732d0, 0) < 0);
        }
    }
    if ((a & 2) != 0) {
        func_02020f50();
    }
    data_021732ec[data_021732e0] = data_021732d0;
    data_021732e0++;
    if (data_021732e0 > 8) {
        data_021732e0 = 0;
    }
    data_021732d0 = 0;
    data_021732d4 = 0;
    data_021732e4++;
    data_021732e8++;
    OS_RestoreInterrupts(s);
    return 1;
}

void PxiCommandWaitForSequence(u32 a) {
    if (PxiCommandSequenceReached(a) != 0) {
        return;
    }
    while (PxiCommandReclaim(0) != 0) {
    }
    if (PxiCommandSequenceReached(a) != 0) {
        return;
    }
    func_02020f50();
    if (PxiCommandSequenceReached(a) != 0) {
        return;
    }
    do {
        PxiCommandReclaim(1);
    } while (PxiCommandSequenceReached(a) == 0);
}

u32 SND_GetCurrentCommandTag(void) {
    u32 s;
    u32 v;

    s = OS_DisableInterrupts();
    if (data_021732d0 == 0) {
        v = data_021732cc;
    } else {
        v = data_021732e8;
    }
    OS_RestoreInterrupts(s);
    return v;
}

u32 PxiCommandSequenceReached(u32 a) {
    u32 s;
    u32 c;
    u32 r;

    s = OS_DisableInterrupts();
    c = data_021732cc;
    if (a > c) {
        if ((a - c) < 0x80000000u) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if ((c - a) < 0x80000000u) {
            r = 1;
        } else {
            r = 0;
        }
    }
    OS_RestoreInterrupts(s);
    return r;
}

s32 SND_CountFreeCommand(void) {
    u32 s;
    PxiCommand *p;
    s32 n;

    s = OS_DisableInterrupts();
    n = 0;
    for (p = data_021732c8; p != 0; p = p->mNext) {
        n++;
    }
    OS_RestoreInterrupts(s);
    return n;
}

s32 SND_CountReservedCommand(void) {
    u32 s;
    PxiCommand *p;
    s32 n;

    s = OS_DisableInterrupts();
    n = 0;
    for (p = data_021732d0; p != 0; p = p->mNext) {
        n++;
    }
    OS_RestoreInterrupts(s);
    return n;
}

s32 SND_CountWaitingCommand(void) {
    s32 a;

    a = SND_CountFreeCommand();
    return 0x100 - a - SND_CountReservedCommand();
}

void func_02020ff0(u32 a, u32 b) {
    u32 s;

    s = OS_DisableInterrupts();
    PxiCommandCallbackRun(b);
    OS_RestoreInterrupts(s);
}

void func_02020f84(void) {
    PxiCallbackSet(7, func_02020ff0);
    if (func_02020eb0() == 0) {
        return;
    }
    if (PxiCallbackBitIsSet(7, 1) != 0) {
        return;
    }
    do {
        OS_SpinWait(0x64);
    } while (PxiCallbackBitIsSet(7, 1) == 0);
}

void func_02020f50(void) {
    while (PxiSendFifoWord(7, 0, 0) < 0) {
    }
}

PxiCommand *PxiCommandPoolRemoveHead(void) {
    u32 s;
    PxiCommand *p;
    PxiCommand *n;

    s = OS_DisableInterrupts();
    p = data_021732c8;
    if (p == 0) {
        OS_RestoreInterrupts(s);
        return 0;
    }
    n = p->mNext;
    data_021732c8 = n;
    if (n == 0) {
        data_021732d8 = 0;
    }
    OS_RestoreInterrupts(s);
    return p;
}

u32 func_02020eb0(void) {
    u32 s;
    u32 v;

    if (OS_IsRunOnEmulator() == 0) {
        return 1;
    }
    s = OS_DisableInterrupts();
    *(vu32 *) 0x04fff200 = 0x10;
    v = *(vu32 *) 0x04fff200;
    OS_RestoreInterrupts(s);
    return v != 0;
}
