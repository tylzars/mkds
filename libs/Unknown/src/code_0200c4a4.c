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

Unk0216fe04 data_0216fe04;
s32 data_0216fe0c;
s32 data_0216fe08;
Unk0216fe20 data_0216fe20;
s32 (*data_0216fe10)(void);
s32 data_0216fe14;
s32 data_0216fe18;
s32 data_0216fe1c;

void func_0200c7f4(void) {
    if (data_0216fe0c == 0) {
        data_0216fe0c = 1;
        func_0200c620();
        PxiInit();
        while (PxiCallbackBitIsSet(13, 1) == 0) {
        }
        PxiCallbackSet(13, (UnkFunc *) func_0200c690);
        func_0200c6b8();
        PxiCallbackSet(13, 0);
        PxiCallbackSet(13, (UnkFunc *) func_0200c65c);
        data_0216fe10 = 0;
    }
}

void func_0200c6b8(void) {
    u32 v;
    u16 w;
    Unk0200c4a4 a;
    Unk0200c4a4 b;
    s32 c;
    s32 i;
    Unk027ffc30 *s;
    Unk0216fe20 *d;

    if (data_0216fe08 != 0) {
        return;
    }
    data_0216fe08 = 1;
    if ((*(u16 *) 0x04000300 & 1) == 0) {
        return;
    }
    v = InterruptEnableWrite(0x40000);
    w = reg_OS_IME;
    reg_OS_IME = 1;
    func_0200c4c0(data_0216fe04.mUnk_02, &a);
    c = (*(u16 *) 0x04000204 & 0x8000) >> 15;
    func_0200c534(&b);
    *(u16 *) 0x04000204 = *(u16 *) 0x04000204 & ~0x8000;
    func_0200ee3c(((u8 *) &data_0216fe20 + 0x80), 0x40);
    MI_DmaCopy16(1, (const void *) 0x08000080, ((u8 *) &data_0216fe20 + 0x80), 0x40);
    *(u16 *) 0x04000204 = (*(u16 *) 0x04000204 & ~0x8000) | (c << 15);
    func_0200c508(&b);
    func_0200c4a4(data_0216fe04.mUnk_02, &a);
    d = &data_0216fe20;
    s = (Unk027ffc30 *) 0x027ffc30;
    s->mUnk_00 = data_0216fe20.mUnk_80.mUnk_3e;
    for (i = 0; i < 3; i++) {
        ((u8 *) 0x027ffc32)[i] = d->mUnk_80.mUnk_35[i];
    }
    s->mUnk_06 = d->mUnk_80.mUnk_30;
    s->mUnk_08 = d->mUnk_80.mUnk_2c;
    MemCopyWords((void *) 0xffff0020, data_0216fe20.mUnk_04, 0x9c);
    func_0200ee08();
    func_0200c46c(((((u32) &data_0216fe20 - 0x02000000) >> 5) << 6) | 1);
    while (data_0216fe04.mUnk_00 != 1) {
        WaitByLoop(1);
    }
    reg_OS_IME;
    reg_OS_IME = w;
    InterruptEnableWrite(v);
}

void func_0200c690(u32 a, u32 b) {
    if ((b & 0x3f) == 1) {
        data_0216fe04.mUnk_00 = 1;
    } else {
        IrqDisableLoopForever();
    }
}

void func_0200c65c(u32 a, u32 b) {
    s32 r;

    if ((b & 0x3f) == 0x11) {
        r = 0;
        if (data_0216fe10 != 0) {
            r = data_0216fe10();
        }
        if (r != 0) {
            func_0200c648();
            return;
        }
    } else {
        IrqDisableLoopForever();
    }
}

void func_0200c648(void) {
    func_0200c46c(2);
    IrqDisableLoopForever();
}

void func_0200c620(void) {
    u32 v;

    v = 0;
    CpuSet(&v, &data_0216fe04, 0x05000001);
    data_0216fe04.mUnk_02 = IdAlloc();
}

s32 func_0200c568(void) {
    s32 ret;
    Unk0200c4a4 a;
    Unk0200c4a4 b;
    Unk027ffc30 *s;
    Unk08000000 *c;

    s = (Unk027ffc30 *) 0x027ffc30;
    c = (Unk08000000 *) 0x08000000;
    ret = 1;
    if (s->mUnk_00 == 0xffff) {
        return 0;
    }
    if (s->mUnk_05_1 == 1) {
        return 0;
    }
    func_0200c4c0(data_0216fe04.mUnk_02, &a);
    func_0200c534(&b);
    if ((c->mUnk_b2 == 0x96 && s->mUnk_00 != c->mUnk_be) || (c->mUnk_b2 != 0x96 && s->mUnk_00 != *(u16 *) 0x0801fffe) ||
        (s->mUnk_08 != c->mUnk_ac && s->mUnk_05_0)) {
        s->mUnk_05_1 = 1;
        ret = 0;
    }
    func_0200c508(&b);
    func_0200c4a4(data_0216fe04.mUnk_02, &a);
    return ret;
}

void func_0200c534(Unk0200c4a4 *p) {
    p->mUnk_00 = (reg_MI_EXMEMCNT & 0xc) >> 2;
    p->mUnk_04 = (reg_MI_EXMEMCNT & 0x10) >> 4;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | 0xc;
    reg_MI_EXMEMCNT &= ~0x10;
}

void func_0200c508(Unk0200c4a4 *p) {
    u32 a;
    u32 b;

    a = p->mUnk_00;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | (a << 2);
    b = p->mUnk_04;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0x10) | (b << 4);
}

void func_0200c4c0(u32 a, Unk0200c4a4 *p) {
    for (;;) {
        p->mUnk_04 = IrqDisable();
        p->mUnk_00 = SwapLockGetHolderId((SwapLockSlot *) 0x027fffe8) & 0x40;
        if (p->mUnk_00 != 0) {
            break;
        }
        if (func_0200ce60(a) == 0) {
            break;
        }
        IrqRestore(p->mUnk_04);
        WaitByLoop(1);
    }
}

void func_0200c4a4(u32 a, Unk0200c4a4 *p) {
    if (p->mUnk_00 == 0) {
        func_0200cd1c(a);
    }
    IrqRestore(p->mUnk_04);
}
