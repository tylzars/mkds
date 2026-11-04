#include "code_0200f7a0.h"

#include "code_0200c914.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200f790.h"
#include "code_0200f580.h"

u16 data_0217025c;
Unk02170260 data_02170260;

void func_0200fb80(Unk0200fb08 *n) {
    u64 t;
    s64 d;
    u16 v;

    t = func_0200f5ac();
    *(vu16 *) 0x4000106 = 0;
    d = n->mUnk_0c - t;
    func_0200cb50(1, func_0200f790, 0);
    if (d < 0) {
        v = 0xfffe;
    } else if (d < 0x10000) {
        v = ~d;
    } else {
        v = 0;
    }
    *(vu16 *) 0x4000104 = v;
    *(vu16 *) 0x4000106 = 0xc1;
    InterruptEnableSetBits(0x10);
}

void func_0200fb28(void) {
    if (data_0217025c != 0) {
        return;
    }
    data_0217025c = 1;
    func_0200f580(1);
    data_02170260.mUnk_00 = 0;
    data_02170260.mUnk_04 = 0;
    InterruptEnableClearBits(0x10);
}

u32 func_0200fb18(void) {
    u32 value0;
    value0 = (u32) &data_0217025c;
    value0 = (u32) * (const u16 *) ((value0) + (0));
    return value0;
}

void func_0200fb08(Unk0200fb08 *n) {
    n->mUnk_00 = 0;
    n->mUnk_08 = 0;
}

void func_0200f9c8(Unk0200fb08 *n, u64 t) {
    Unk0200fb08 *p;
    u64 c;

    if (n->mUnk_1c != 0) {
        c = func_0200f5ac();
        t = n->mUnk_24;
        if (t < c) {
            t = t + n->mUnk_1c * ((c - t) / n->mUnk_1c + 1);
        }
    }
    n->mUnk_0c = t;
    for (p = data_02170260.mUnk_00; p != 0; p = p->mUnk_18) {
        if ((s64) (t - p->mUnk_0c) < 0) {
            n->mUnk_14 = p->mUnk_14;
            p->mUnk_14 = n;
            n->mUnk_18 = p;
            if (n->mUnk_14 != 0) {
                n->mUnk_14->mUnk_18 = n;
                return;
            }
            data_02170260.mUnk_00 = n;
            func_0200fb80(n);
            return;
        }
    }
    n->mUnk_18 = 0;
    p = data_02170260.mUnk_04;
    data_02170260.mUnk_04 = n;
    n->mUnk_14 = p;
    if (p != 0) {
        p->mUnk_18 = n;
        return;
    }
    data_02170260.mUnk_04 = n;
    data_02170260.mUnk_00 = n;
    func_0200fb80(n);
}

void func_0200f950(Unk0200fb08 *n, u64 a, void (*f)(void *), void *p) {
    u32 s;

    if (n == 0 || n->mUnk_00 != 0) {
        func_0200fd1c();
    }
    s = IrqDisable();
    n->mUnk_1c = 0;
    n->mUnk_00 = f;
    n->mUnk_04 = p;
    func_0200f9c8(n, a + func_0200f5ac());
    IrqRestore(s);
}

void func_0200f8b8(Unk0200fb08 *n) {
    u32 s;
    Unk0200fb08 *next;

    s = IrqDisable();
    if (n->mUnk_00 == 0) {
        IrqRestore(s);
        return;
    }
    next = n->mUnk_18;
    if (next == 0) {
        data_02170260.mUnk_04 = n->mUnk_14;
    } else {
        next->mUnk_14 = n->mUnk_14;
    }
    if (n->mUnk_14 != 0) {
        n->mUnk_14->mUnk_18 = next;
    } else {
        data_02170260.mUnk_00 = next;
        if (next != 0) {
            func_0200fb80(next);
        }
    }
    n->mUnk_00 = 0;
    n->mUnk_1c = 0;
    IrqRestore(s);
}

void func_0200f7a0(void) {
    Unk0200fb08 *n;
    Unk0200fb08 *next;
    void (*f)(void *);
    u64 c;

    *(vu16 *) 0x4000106 = 0;
    InterruptEnableClearBits(0x10);
    *(u32 *) ((u8 *) &data_027e0000 + 0x3ff8) |= 0x10;
    c = func_0200f5ac();
    n = data_02170260.mUnk_00;
    if (n == 0) {
        return;
    }
    if (c < n->mUnk_0c) {
        func_0200fb80(n);
        return;
    }
    next = n->mUnk_18;
    data_02170260.mUnk_00 = next;
    if (next == 0) {
        data_02170260.mUnk_04 = 0;
    } else {
        next->mUnk_14 = 0;
    }
    f = n->mUnk_00;
    if (n->mUnk_1c == 0) {
        n->mUnk_00 = 0;
    }
    if (f != 0) {
        f(n->mUnk_04);
    }
    if (n->mUnk_1c != 0) {
        n->mUnk_00 = f;
        func_0200f9c8(n, 0);
    }
    if (data_02170260.mUnk_00 != 0) {
        func_0200fb80(data_02170260.mUnk_00);
    }
}
