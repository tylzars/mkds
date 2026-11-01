#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "code_0200e77c.h"
#include "code_0200dbe8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f7a0.h"
#include "Main/Unknown/unk_0216f000.h"

void func_0200e084(Unk0200db5c *t) {
    u32 s;

    s = func_0200fca0();
    if (t->mUnk_64 != 2) {
        func_0200e01c(&t->mUnk_9c);
    }
    func_0200fcb4(s);
}

s32 func_0200e070(Unk0200db5c *t) {
    return t->mUnk_64 == 2;
}

void func_0200e01c(Unk0200df9c *q) {
    u32 s;
    Unk0200db5c *t;

    s = func_0200fca0();
    t = *data_0216ff54;
    if (q != 0) {
        t->mUnk_78 = q;
        func_0200e5f8(q, t);
    }
    t->mUnk_64 = 0;
    func_0200de50();
    func_0200fcb4(s);
}

void func_0200df9c(Unk0200df9c *q) {
    u32 s;
    Unk0200db5c *t;

    s = func_0200fca0();
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
    func_0200fcb4(s);
}

void func_0200df68(Unk0200db5c *t) {
    u32 s;

    s = func_0200fca0();
    t->mUnk_64 = 1;
    func_0200de50();
    func_0200fcb4(s);
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
    s = func_0200fca0();
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
        func_0200fcb4(s);
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
    func_0200fcb4(s);
}

s32 func_0200dce0(Unk0200db5c *t, u32 v) {
    Unk0200db5c *p;
    Unk0200db5c *b;
    u32 s;

    p = data_0216ff5c.mUnk_08;
    b = 0;
    s = func_0200fca0();
    while (p != 0 && p != t) {
        b = p;
        p = p->mUnk_68;
    }
    if (p == 0 || p == &data_0216ff6c) {
        func_0200fcb4(s);
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
    func_0200fcb4(s);
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
    s = func_0200fca0();
    t->mUnk_b0 = &a;
    func_0200f950(&a, n * 0x82ea >> 6, (void (*)(void *)) func_0200dc1c, &t);
    while (t != 0) {
        func_0200e01c(0);
    }
    func_0200fcb4(s);
}
