#include "code_0200e0ec.h"
#include "code_0200c914.h"
#include "code_0200db5c.h"
#include "code_0200dc3c.h"
#include "code_0200e688.h"
#include "code_0200e77c.h"
#include "code_0200dbe8.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200e0c0.h"
#include "code_0200e670.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "00/code_02188720.h"

void func_0200e5f8(Unk0200df9c *q, Unk0200db5c *t) {
    Unk0200db5c *p;
    Unk0200db5c *b;

    p = q->mUnk_00;
    while (p != 0 && p->mUnk_70 <= t->mUnk_70) {
        if (p == t) {
            return;
        }
        p = p->mUnk_80;
    }
    if (p == 0) {
        b = q->mUnk_04;
        if (b == 0) {
            q->mUnk_00 = t;
        } else {
            b->mUnk_80 = t;
        }
        t->mUnk_7c = b;
        t->mUnk_80 = 0;
        q->mUnk_04 = t;
    } else {
        b = p->mUnk_7c;
        if (b == 0) {
            q->mUnk_00 = t;
        } else {
            b->mUnk_80 = t;
        }
        t->mUnk_7c = b;
        t->mUnk_80 = p;
        p->mUnk_7c = t;
    }
}

Unk0200db5c *func_0200e5c4(Unk0200df9c *q) {
    Unk0200db5c *h;
    Unk0200db5c *n;

    h = q->mUnk_00;
    if (h != 0) {
        n = h->mUnk_80;
        q->mUnk_00 = n;
        if (n != 0) {
            n->mUnk_7c = 0;
        } else {
            q->mUnk_04 = 0;
            h->mUnk_78 = 0;
        }
    }
    return h;
}

Unk0200edc0 *func_0200e594(Unk0200e594 *q) {
    Unk0200edc0 *h;
    Unk0200edc0 *n;

    h = q->mUnk_00;
    if (h != 0) {
        n = h->mUnk_10;
        q->mUnk_00 = n;
        if (n != 0) {
            n->mUnk_14 = 0;
        } else {
            q->mUnk_04 = 0;
        }
    }
    return h;
}

void func_0200e52c(Unk0200db5c *t) {
    Unk0200db5c *p;
    Unk0200db5c *b;
    Unk0200db5c *h;

    b = 0;
    h = data_0216ff5c.mUnk_08;
    p = h;
    while (p != 0 && p->mUnk_70 < t->mUnk_70) {
        b = p;
        p = p->mUnk_68;
    }
    if (b == 0) {
        t->mUnk_68 = h;
        data_0216ff5c.mUnk_08 = t;
    } else {
        t->mUnk_68 = b->mUnk_68;
        b->mUnk_68 = t;
    }
}

void func_0200e4e4(Unk0200db5c *t) {
    Unk0200db5c *p;
    Unk0200db5c *b;

    b = 0;
    p = data_0216ff5c.mUnk_08;
    while (p != 0 && p != t) {
        b = p;
        p = p->mUnk_68;
    }
    if (b == 0) {
        data_0216ff5c.mUnk_08 = t->mUnk_68;
    } else {
        b->mUnk_68 = t->mUnk_68;
    }
}

void func_0200e388(void) {
    s32 n;
    u8 *l;
    u8 *h;

    if (data_0216ff58 != 0) {
        return;
    }
    data_0216ff58 = 1;
    data_0216ff54 = &data_0216ff5c.mUnk_04;
    data_0217002c.mUnk_70 = 0x10;
    data_0217002c.mUnk_6c = 0;
    data_0217002c.mUnk_64 = 1;
    data_0217002c.mUnk_68 = 0;
    data_0217002c.mUnk_74 = 0;
    data_0216ff5c.mUnk_08 = &data_0217002c;
    data_0216ff5c.mUnk_04 = &data_0217002c;
    n = (s32) data_00002800;
    if (n <= 0) {
        l = (u8 *) 0x27e00e0 - n;
    } else {
        l = (u8 *) &data_027e0000 + 0x3f80 - (u32) data_00000c00 - n;
    }
    h = (u8 *) &data_027e0000 + 0x3f80 - (u32) data_00000c00;
    data_0217002c.mUnk_94 = h;
    data_0217002c.mUnk_90 = l;
    data_0217002c.mUnk_98 = 0;
    *(u32 *) (h - 4) = 0xfddb597d;
    *(u32 *) data_0217002c.mUnk_90 = 0x7bf9dd5b;
    data_0217002c.mUnk_9c.mUnk_04 = 0;
    data_0217002c.mUnk_9c.mUnk_00 = 0;
    data_0216ff5c.mUnk_00 = 0;
    data_0216ff5c.mUnk_02 = 0;
    *(Unk0200dce0 **) 0x027fffa0 = &data_0216ff5c;
    func_0200dbe8(0);
    func_0200e28c(&data_0216ff6c, func_0200dbd4, 0, (u8 *) &data_021701b4, 0xc8, 0x1f);
    data_0216ff6c.mUnk_70 = 0x20;
    data_0216ff6c.mUnk_64 = 1;
}

void func_0200e28c(Unk0200db5c *t, void (*f)(void *), void *a, u8 *p, u32 n, u32 v) {
    u32 s;
    u32 k;
    u8 *l;
    volatile u32 z;

    s = func_0200fca0();
    k = func_0200e670();
    t->mUnk_70 = v;
    t->mUnk_6c = k;
    t->mUnk_64 = 0;
    t->mUnk_74 = 0;
    func_0200e52c(t);
    t->mUnk_94 = p;
    l = p - n;
    t->mUnk_90 = l;
    t->mUnk_98 = 0;
    *(u32 *) (t->mUnk_94 - 4) = 0xfddb597d;
    *(u32 *) t->mUnk_90 = 0x7bf9dd5b;
    t->mUnk_9c.mUnk_04 = 0;
    t->mUnk_9c.mUnk_00 = t->mUnk_9c.mUnk_04;
    func_0200e688(t, f, (u32) p - 4);
    t->mUnk_04 = a;
    t->mUnk_3c = func_0200e260;
    z = 0;
    func_0214d018(z, l + 4, n - 8);
    func_0200db5c(t, 0);
    t->mUnk_78 = 0;
    t->mUnk_80 = 0;
    t->mUnk_7c = t->mUnk_80;
    t->mUnk_b0 = 0;
    func_0200fcb4(s);
}

void func_0200e260(void) {
    func_0200fca0();
    func_0200e1f0(data_0216ff5c.mUnk_04, 0);
}

void func_0200e1f0(Unk0200db5c *t, void *a) {
    if (data_0216ff44 != 0) {
        func_0200e688(t, func_0200e1ac, data_0216ff44);
        t->mUnk_04 = a;
        t->mUnk_00 = t->mUnk_00 | 0x80;
        t->mUnk_64 = 1;
        func_0200e738(t);
    } else {
        func_0200e1ac(a);
    }
}

void func_0200e1ac(void *a) {
    Unk0200db5c *t;
    void (*f)(void *);

    t = *data_0216ff54;
    f = t->mUnk_b4;
    if (f != 0) {
        t->mUnk_b4 = 0;
        f(a);
        func_0200fca0();
    }
    func_0200e160();
}

void func_0200e160(void) {
    Unk0200db5c *t;

    t = *data_0216ff54;
    func_0200db9c();
    func_0200ec7c(t);
    func_0200e4e4(t);
    t->mUnk_64 = 2;
    func_0200df9c(&t->mUnk_9c);
    func_0200db64();
    func_0200de50();
    func_0200fd1c();
}

void func_0200e0ec(Unk0200db5c *t) {
    u32 s;

    s = func_0200fca0();
    if (data_0216ff5c.mUnk_04 == t) {
        func_0200e160();
    }
    func_0200db9c();
    func_0200ec7c(t);
    func_0200e0c0(t);
    func_0200e4e4(t);
    t->mUnk_64 = 2;
    func_0200df9c(&t->mUnk_9c);
    func_0200db64();
    func_0200fcb4(s);
    func_0200de50();
}
