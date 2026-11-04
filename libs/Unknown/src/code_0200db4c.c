#include "code_0200db4c.h"

#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200f7a0.h"
#include "code_0200c914.h"
#include "code_0200e688.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "00/code_02188720.h"

u32 func_0200e670(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &data_0216ff4c;
    value0 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (value0) + (1u);
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}

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

    s = IrqDisable();
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
    MemFillWords(z, l + 4, n - 8);
    func_0200db5c(t, 0);
    t->mUnk_78 = 0;
    t->mUnk_80 = 0;
    t->mUnk_7c = t->mUnk_80;
    t->mUnk_b0 = 0;
    IrqRestore(s);
}

void func_0200e260(void) {
    IrqDisable();
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
        IrqDisable();
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

    s = IrqDisable();
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
    IrqRestore(s);
    func_0200de50();
}

void func_0200e0c0(Unk0200db5c *arg0) {
    u32 value0 = (u32) arg0;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) * (const u32 *) ((value0) + (176));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    func_0200f8b8((Unk0200fb08 *) value0);
}

void func_0200e084(Unk0200db5c *t) {
    u32 s;

    s = IrqDisable();
    if (t->mUnk_64 != 2) {
        func_0200e01c(&t->mUnk_9c);
    }
    IrqRestore(s);
}

s32 func_0200e070(Unk0200db5c *t) {
    return t->mUnk_64 == 2;
}

void func_0200e01c(Unk0200df9c *q) {
    u32 s;
    Unk0200db5c *t;

    s = IrqDisable();
    t = *data_0216ff54;
    if (q != 0) {
        t->mUnk_78 = q;
        func_0200e5f8(q, t);
    }
    t->mUnk_64 = 0;
    func_0200de50();
    IrqRestore(s);
}

void func_0200df9c(Unk0200df9c *q) {
    u32 s;
    Unk0200db5c *t;

    s = IrqDisable();
    if (q->mUnk_00 != 0) {
        while (q->mUnk_00 != 0) {
            t = func_0200e5c4(q);
            t->mUnk_64 = 1;
            t->mUnk_78 = 0;
            t->mUnk_80 = 0;
            t->mUnk_7c = t->mUnk_80;
        }
        q->mUnk_04 = 0;
        q->mUnk_00 = q->mUnk_04;
        func_0200de50();
    }
    IrqRestore(s);
}

void func_0200df68(Unk0200db5c *t) {
    u32 s;

    s = IrqDisable();
    t->mUnk_64 = 1;
    func_0200de50();
    IrqRestore(s);
}

Unk0200db5c *func_0200df3c(void) {
    Unk0200db5c *p;

    p = data_0216ff5c.mUnk_08;
    while (p != 0 && p->mUnk_64 != 1) {
        p = p->mUnk_68;
    }
    return p;
}

void func_0200de50(void) {
    Unk0200dce0 *s;
    Unk0200db5c *a;
    Unk0200db5c *b;

    s = &data_0216ff5c;
    if (data_0216ff48 != 0) {
        return;
    }
    if (s->mUnk_02 != 0 || func_0200fcf8() == 0x12) {
        s->mUnk_00 = 1;
        return;
    }
    a = *data_0216ff54;
    b = func_0200df3c();
    if (a == b) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (a->mUnk_64 != 2) {
        if (func_0200e6ec(a) != 0) {
            return;
        }
    }
    if (data_0216ff50 != 0) {
        data_0216ff50(a, b);
    }
    if (s->mUnk_0c != 0) {
        s->mUnk_0c(a, b);
    }
    data_0216ff5c.mUnk_04 = b;
    func_0200e738(b);
}

void func_0200dd94(void) {
    Unk0200db5c *t;
    Unk0200db5c *c;
    Unk0200db5c *e;
    Unk0200db5c *p;
    Unk0200db5c *b;
    int n;
    u32 s;

    c = 0;
    e = 0;
    n = 0;
    t = data_0216ff5c.mUnk_04;
    s = IrqDisable();
    b = 0;
    for (p = data_0216ff5c.mUnk_08; p != 0; p = p->mUnk_68) {
        if (p == t) {
            c = b;
        }
        if (t->mUnk_70 == p->mUnk_70) {
            e = p;
            n++;
        }
        b = p;
    }
    if (n <= 1 || e == t) {
        IrqRestore(s);
        return;
    }
    if (c == 0) {
        data_0216ff5c.mUnk_08 = t->mUnk_68;
    } else {
        c->mUnk_68 = t->mUnk_68;
    }
    t->mUnk_68 = e->mUnk_68;
    e->mUnk_68 = t;
    func_0200de50();
    IrqRestore(s);
}

s32 func_0200dce0(Unk0200db5c *t, u32 v) {
    Unk0200db5c *p;
    Unk0200db5c *b;
    u32 s;

    p = data_0216ff5c.mUnk_08;
    b = 0;
    s = IrqDisable();
    while (p != 0 && p != t) {
        b = p;
        p = p->mUnk_68;
    }
    if (p == 0 || p == &data_0216ff6c) {
        IrqRestore(s);
        return 0;
    }
    if (p->mUnk_70 != v) {
        if (b == 0) {
            data_0216ff5c.mUnk_08 = t->mUnk_68;
        } else {
            b->mUnk_68 = t->mUnk_68;
        }
        t->mUnk_70 = v;
        func_0200e52c(t);
        func_0200de50();
    }
    IrqRestore(s);
    return 1;
}

u32 func_0200dcd8(Unk0200db5c *t) {
    return t->mUnk_70;
}

void func_0200dc3c(u32 n) {
    Unk0200db5c *t;
    Unk0200fb08 a;
    u32 s;

    func_0200fb08(&a);
    t = *data_0216ff54;
    s = IrqDisable();
    t->mUnk_b0 = &a;
    func_0200f950(&a, n * 0x82ea >> 6, (void (*)(void *)) func_0200dc1c, &t);
    while (t != 0) {
        func_0200e01c(0);
    }
    IrqRestore(s);
}

void func_0200dc1c(Unk0200db5c **arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    value12 = (u32) &func_0200df68;
    value0 = value2;
    *(u32 *) ((value2) + (176)) = value1;
    func_0200df68((Unk0200db5c *) value0);
}

void (*func_0200dbe8(void (*arg0)(Unk0200db5c *, Unk0200db5c *)))(Unk0200db5c *, Unk0200db5c *) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value0 = (u32) IrqDisable();
    value1 = (u32) &data_0216ff5c;
    value4 = (u32) * (const u32 *) ((value1) + (12));
    *(u32 *) ((value1) + (12)) = value5;
    value0 = (u32) IrqRestore(value0);
    value0 = value4;
    return (void (*)(Unk0200db5c *, Unk0200db5c *)) value0;
}

void func_0200dbd4(void *a) {
    IrqEnable();
    for (;;) {
        func_0200fd04();
    }
}

u32 func_0200db9c(void) {
    u32 s;
    u32 r;

    s = IrqDisable();
    if (data_0216ff48 < 0xffffffff) {
        r = data_0216ff48;
        data_0216ff48 = r + 1;
    }
    IrqRestore(s);
    return r;
}

u32 func_0200db64(void) {
    u32 s;
    u32 r;

    s = IrqDisable();
    r = 0;
    if (data_0216ff48 != 0) {
        r = data_0216ff48;
        data_0216ff48 = r - 1;
    }
    IrqRestore(s);
    return r;
}

void func_0200db5c(Unk0200db5c *t, void (*f)(void *)) {
    t->mUnk_b4 = f;
}

u32 func_0200db4c(void) {
    u32 value0;
    value0 = (u32) &data_0216ff58;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}
