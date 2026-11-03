#include "code_0200f7a0.h"
#include "code_0200c914.h"
#include "code_0200f5ac.h"
#include "code_0200fb28.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"

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
    s = func_0200fca0();
    n->mUnk_1c = 0;
    n->mUnk_00 = f;
    n->mUnk_04 = p;
    func_0200f9c8(n, a + func_0200f5ac());
    func_0200fcb4(s);
}

void func_0200f8b8(Unk0200fb08 *n) {
    u32 s;
    Unk0200fb08 *next;

    s = func_0200fca0();
    if (n->mUnk_00 == 0) {
        func_0200fcb4(s);
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
    func_0200fcb4(s);
}

void func_0200f7a0(void) {
    Unk0200fb08 *n;
    Unk0200fb08 *next;
    void (*f)(void *);
    u64 c;

    *(vu16 *) 0x4000106 = 0;
    func_0200ca9c(0x10);
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
