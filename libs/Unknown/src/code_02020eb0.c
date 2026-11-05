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

void func_020215bc(void) {
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

    s = IrqDisable();
    if ((a & 1) != 0) {
        while (data_021732cc == func_02021834()) {
            IrqRestore(s);
            func_0200fd10(0x64);
            s = IrqDisable();
        }
    } else if (data_021732cc == func_02021834()) {
        IrqRestore(s);
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
    IrqRestore(s);
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
    if (func_02021020() > 0) {
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

    s = IrqDisable();
    t = data_021732d4;
    if (t == 0) {
        data_021732d4 = p;
        data_021732d0 = p;
    } else {
        t->mNext = p;
        data_021732d4 = p;
    }
    p->mNext = 0;
    IrqRestore(s);
}

u32 PxiCommandSendPending(u32 a) {
    u32 s;

    s = IrqDisable();
    if (data_021732d0 == 0) {
        IrqRestore(s);
        return 1;
    }
    if (data_021732e4 >= 8) {
        if ((a & 1) == 0) {
            IrqRestore(s);
            return 0;
        }
        do {
            PxiCommandReclaim(1);
        } while (data_021732e4 >= 8);
    }
    DC_FlushRange(data_021735a0, 0x1800);
    if (PxiSendFifoWord(7, (u32) data_021732d0, 0) < 0) {
        if ((a & 1) == 0) {
            IrqRestore(s);
            return 0;
        }
        if (PxiSendFifoWord(7, (u32) data_021732d0, 0) < 0) {
            do {
                IrqRestore(s);
                func_0200fd10(0x64);
                s = IrqDisable();
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
    IrqRestore(s);
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

u32 func_02021114(void) {
    u32 s;
    u32 v;

    s = IrqDisable();
    if (data_021732d0 == 0) {
        v = data_021732cc;
    } else {
        v = data_021732e8;
    }
    IrqRestore(s);
    return v;
}

u32 PxiCommandSequenceReached(u32 a) {
    u32 s;
    u32 c;
    u32 r;

    s = IrqDisable();
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
    IrqRestore(s);
    return r;
}

s32 func_02021080(void) {
    u32 s;
    PxiCommand *p;
    s32 n;

    s = IrqDisable();
    n = 0;
    for (p = data_021732c8; p != 0; p = p->mNext) {
        n++;
    }
    IrqRestore(s);
    return n;
}

s32 func_02021040(void) {
    u32 s;
    PxiCommand *p;
    s32 n;

    s = IrqDisable();
    n = 0;
    for (p = data_021732d0; p != 0; p = p->mNext) {
        n++;
    }
    IrqRestore(s);
    return n;
}

s32 func_02021020(void) {
    s32 a;

    a = func_02021080();
    return 0x100 - a - func_02021040();
}

void func_02020ff0(u32 a, u32 b) {
    u32 s;

    s = IrqDisable();
    PxiCommandCallbackRun(b);
    IrqRestore(s);
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
        func_0200fd10(0x64);
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

    s = IrqDisable();
    p = data_021732c8;
    if (p == 0) {
        IrqRestore(s);
        return 0;
    }
    n = p->mNext;
    data_021732c8 = n;
    if (n == 0) {
        data_021732d8 = 0;
    }
    IrqRestore(s);
    return p;
}

u32 func_02020eb0(void) {
    u32 s;
    u32 v;

    if (func_0200e8fc() == 0) {
        return 1;
    }
    s = IrqDisable();
    *(vu32 *) 0x04fff200 = 0x10;
    v = *(vu32 *) 0x04fff200;
    IrqRestore(s);
    return v != 0;
}
