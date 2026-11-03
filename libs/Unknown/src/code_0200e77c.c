#include "code_0200cd1c.h"
#include "code_0200e77c.h"

#include "code_0200cdc0.h"
#include "code_0200ce60.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"

// With t = data_0216ff5c.mUnk_04: when n->mUnk_08 is 0 it is set to t, mUnk_0c is raised and func_0200ebe4 links n
// to t; when it is t only mUnk_0c is raised; otherwise t->mUnk_84 is set to n around func_0200e01c on n->mUnk_00,
// and the test repeats.
void func_0200ed34(void *p) {
    Unk0200edc0 *n;
    u32 s;
    Unk0200db5c *t;

    n = p;
    s = func_0200fca0();
    t = data_0216ff5c.mUnk_04;
    while (1) {
        if (n->mUnk_08 == 0) {
            n->mUnk_08 = t;
            n->mUnk_0c = n->mUnk_0c + 1;
            func_0200ebe4(t, n);
            break;
        } else if (n->mUnk_08 == t) {
            n->mUnk_0c = n->mUnk_0c + 1;
            break;
        } else {
            t->mUnk_84 = n;
            func_0200e01c(&n->mUnk_00);
            t->mUnk_84 = 0;
        }
    }
    func_0200fcb4(s);
}

// When n->mUnk_08 is data_0216ff5c.mUnk_04, lowers mUnk_0c; at 0 calls func_0200ebc0, clears mUnk_08 and calls
// func_0200df9c on n->mUnk_00.
void func_0200ecc4(void *p) {
    Unk0200edc0 *n;
    u32 s;
    Unk0200db5c *t;

    n = p;
    s = func_0200fca0();
    t = data_0216ff5c.mUnk_04;
    if (n->mUnk_08 == t) {
        n->mUnk_0c = n->mUnk_0c - 1;
        if (n->mUnk_0c == 0) {
            func_0200ebc0(t, n);
            n->mUnk_08 = 0;
            func_0200df9c(&n->mUnk_00);
        }
    }
    func_0200fcb4(s);
}

// While t->mUnk_88.mUnk_00 is not 0, takes an object from t->mUnk_88 (func_0200e594), clears its mUnk_08 and
// mUnk_0c and calls func_0200df9c on its mUnk_00.
void func_0200ec7c(struct Unk0200db5c *t) {
    Unk0200edc0 *n;

    if (t->mUnk_88.mUnk_00 == 0) {
        return;
    }
    do {
        n = func_0200e594(&t->mUnk_88);
        n->mUnk_0c = 0;
        n->mUnk_08 = 0;
        func_0200df9c(&n->mUnk_00);
    } while (t->mUnk_88.mUnk_00 != 0);
}

// When n->mUnk_08 is 0 it is set to data_0216ff5c.mUnk_04, mUnk_0c is raised and func_0200ebe4 links n; when it
// is that object only mUnk_0c is raised. Returns 1 in those cases, else 0.
s32 func_0200ec08(void *p) {
    Unk0200edc0 *n;
    u32 s;
    s32 r;
    Unk0200db5c *t;

    n = p;
    s = func_0200fca0();
    t = data_0216ff5c.mUnk_04;
    if (n->mUnk_08 == 0) {
        n->mUnk_08 = t;
        n->mUnk_0c = n->mUnk_0c + 1;
        func_0200ebe4(t, n);
        r = 1;
    } else if (n->mUnk_08 == t) {
        n->mUnk_0c = n->mUnk_0c + 1;
        r = 1;
    } else {
        r = 0;
    }
    func_0200fcb4(s);
    return r;
}

// Links n after t->mUnk_88.mUnk_04 (through mUnk_10 and mUnk_14) and stores it there.
void func_0200ebe4(struct Unk0200db5c *t, Unk0200edc0 *n) {
    Unk0200edc0 *a;

    a = t->mUnk_88.mUnk_04;
    if (a == 0) {
        t->mUnk_88.mUnk_00 = n;
    } else {
        a->mUnk_10 = n;
    }
    n->mUnk_14 = a;
    n->mUnk_10 = 0;
    t->mUnk_88.mUnk_04 = n;
}

// Takes n out of the links of t->mUnk_88 (mUnk_10 and mUnk_14).
void func_0200ebc0(struct Unk0200db5c *t, Unk0200edc0 *n) {
    Unk0200edc0 *a;
    Unk0200edc0 *b;

    b = n->mUnk_10;
    a = n->mUnk_14;
    if (b == 0) {
        t->mUnk_88.mUnk_04 = a;
    } else {
        b->mUnk_14 = a;
    }
    if (a == 0) {
        t->mUnk_88.mUnk_00 = b;
    } else {
        a->mUnk_10 = b;
    }
}

// Clears mUnk_00 and mUnk_08, stores p and n in mUnk_10 and mUnk_14 and clears mUnk_18 and mUnk_1c.
void func_0200eb90(Unk0200eb90 *q, void **p, s32 n) {
    q->mUnk_00.mUnk_04 = 0;
    q->mUnk_00.mUnk_00 = q->mUnk_00.mUnk_04;
    q->mUnk_08.mUnk_04 = 0;
    q->mUnk_08.mUnk_00 = q->mUnk_08.mUnk_04;
    q->mUnk_10 = p;
    q->mUnk_14 = n;
    q->mUnk_18 = 0;
    q->mUnk_1c = 0;
}

// Stores v at mUnk_10[(mUnk_18 + mUnk_1c) % mUnk_14], raises mUnk_1c and calls func_0200df9c on mUnk_08. While
// mUnk_1c is at least mUnk_14 it calls func_0200e01c on mUnk_00, or returns 0 when bit 0 of f is clear.
s32 func_0200eae8(Unk0200eb90 *q, void *v, s32 f) {
    u32 s;

    s = func_0200fca0();
    if (q->mUnk_14 <= q->mUnk_1c) {
        do {
            if ((f & 1) == 0) {
                func_0200fcb4(s);
                return 0;
            }
            func_0200e01c(&q->mUnk_00);
        } while (q->mUnk_14 <= q->mUnk_1c);
    }
    q->mUnk_10[(q->mUnk_18 + q->mUnk_1c) % q->mUnk_14] = v;
    q->mUnk_1c = q->mUnk_1c + 1;
    func_0200df9c(&q->mUnk_08);
    func_0200fcb4(s);
    return 1;
}

// Stores mUnk_10[mUnk_18] to *p when p is not 0, advances mUnk_18 modulo mUnk_14, lowers mUnk_1c and calls
// func_0200df9c on mUnk_00. While mUnk_1c is 0 it calls func_0200e01c on mUnk_08, or returns 0 when bit 0 of f is
// clear.
s32 func_0200ea3c(Unk0200eb90 *q, void **p, s32 f) {
    u32 s;

    s = func_0200fca0();
    if (q->mUnk_1c == 0) {
        do {
            if ((f & 1) == 0) {
                func_0200fcb4(s);
                return 0;
            }
            func_0200e01c(&q->mUnk_08);
        } while (q->mUnk_1c == 0);
    }
    if (p != 0) {
        *p = q->mUnk_10[q->mUnk_18];
    }
    q->mUnk_18 = (q->mUnk_18 + 1) % q->mUnk_14;
    q->mUnk_1c = q->mUnk_1c - 1;
    func_0200df9c(&q->mUnk_00);
    func_0200fcb4(s);
    return 1;
}

// Lowers mUnk_18 by one modulo mUnk_14, stores v at mUnk_10[mUnk_18], raises mUnk_1c and calls func_0200df9c on
// mUnk_08. While mUnk_1c is at least mUnk_14 it calls func_0200e01c on mUnk_00, or returns 0 when bit 0 of f is
// clear.
s32 func_0200e988(Unk0200eb90 *q, void *v, s32 f) {
    u32 s;

    s = func_0200fca0();
    if (q->mUnk_14 <= q->mUnk_1c) {
        do {
            if ((f & 1) == 0) {
                func_0200fcb4(s);
                return 0;
            }
            func_0200e01c(&q->mUnk_00);
        } while (q->mUnk_14 <= q->mUnk_1c);
    }
    q->mUnk_18 = (q->mUnk_18 + q->mUnk_14 - 1) % q->mUnk_14;
    q->mUnk_10[q->mUnk_18] = v;
    q->mUnk_1c = q->mUnk_1c + 1;
    func_0200df9c(&q->mUnk_08);
    func_0200fcb4(s);
    return 1;
}

// Stores mUnk_10[mUnk_18] to *p when p is not 0. While mUnk_1c is 0 it calls func_0200e01c on mUnk_08, or returns
// 0 when bit 0 of f is clear.
s32 func_0200e904(Unk0200eb90 *q, void **p, s32 f) {
    u32 s;

    s = func_0200fca0();
    if (q->mUnk_1c == 0) {
        do {
            if ((f & 1) == 0) {
                func_0200fcb4(s);
                return 0;
            }
            func_0200e01c(&q->mUnk_08);
        } while (q->mUnk_1c == 0);
    }
    if (p != 0) {
        *p = q->mUnk_10[q->mUnk_18];
    }
    func_0200fcb4(s);
    return 1;
}

u32 data_021617cc = 0xffffffff;

u32 func_0200e8fc(void) {
    return 0;
}

// On the first call stores func_0200e7b0's result with one bit added in the top bits (0x10000000 when
// func_0200e8fc is nonzero, else 0x40000000 when func_0200e77c is nonzero, else 0x20000000 when bit 24 of the
// result is set, else 0x80000000), or-ed with a halfword read from a fixed address. The stored value is -1 until
// then.
u32 func_0200e884(void) {
    u32 a;

    if (data_021617cc == 0xffffffff) {
        a = func_0200e7b0();
        if (func_0200e8fc() != 0) {
            a |= 0x10000000;
        } else if (func_0200e77c() != 0) {
            a |= 0x40000000;
        } else if (a & 0x1000000) {
            a |= 0x20000000;
        } else {
            a |= 0x80000000;
        }
        data_021617cc = a | *(u16 *) 0x27ffffa;
    }
    return data_021617cc;
}

// Repeats, each pass between func_0200fca0 and func_0200fcb4, until func_0200ce80 has been called (it is when
// func_0200ce60 returns 0). The result has bit 24 set when two words at fixed addresses are 0x544e494e and
// 0x4f444e45, else bit 25.
u32 func_0200e7b0(void) {
    u32 a;
    s32 d;
    u32 h;
    s32 v;
    u32 s;

    d = 0;
    h = (u16) func_0200cd28();
    a = 0;
    do {
        v = -1;
        s = func_0200fca0();
        if ((func_0200cdc0((Unk0200ce60 *) 0x27fffe8) & 0x40) != 0 || (v = func_0200ce60(h)) == 0) {
            if (*(u32 *) 0x8000000 == 0x544e494e && *(u32 *) 0x8000004 == 0x4f444e45) {
                a = 0x1000000;
            } else {
                a = 0x2000000;
            }
            if (v == 0) {
                func_0200ce80(h);
                d = 1;
            }
        }
        func_0200fcb4(s);
    } while (d == 0);
    return a;
}

// 1 when a halfword is 1; which of two fixed addresses it is read from depends on whether another halfword is 0.
u32 func_0200e77c(void) {
    u16 *p;

    if (*(u16 *) 0x27ffc10 == 0) {
        p = (u16 *) 0x27ff814;
    } else {
        p = (u16 *) 0x27ffc14;
    }
    return *p == 1;
}
