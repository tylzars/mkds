#include "code_02004dc0.h"
#include "code_02003be0.h"
#include "code_02004270.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_02004238.h"
#include "Main/Unknown/code_02004d80.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fd1c.h"
#include "code_0214578c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"
#include "code_02150808.h"
#include "code_02150dc8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"
#include "Main/Unknown/unk_02152000.h"

u32 data_0216f350;
u32 data_0216f354;
u32 data_0216f358;
Unk02005704 data_0216f35c;
Unk02005704 data_0216f364;
Unk02003a6c data_0216f36c;

u8 data_02161764[4] = "rom";
void *data_02161768 = data_02152b80;
u32 data_0216176c = 0x40;

s32 func_02005880(Unk020055f0 *p) {
    if (p->mUnk_1c.b[3] & 1) {
        return p->mUnk_1c.f.mUnk_00_0;
    }
    return p->mUnk_08;
}

void func_0200583c(Unk020055f0 *p) {
    u8 *b;
    s32 n;
    s32 a;

    n = p->mUnk_08;
    a = n + p->mUnk_0c;
    b = p->mUnk_04;
    func_0200eea4(b, a);
    func_0200ee3c(b, a);
    func_0214d168(b + n, 0, a - n);
}

void func_02005814(Unk02005814 *dst, Unk020055f0 *src) {
    Unk02005814 tmp;

    tmp.mUnk_00 = &data_0216f36c;
    tmp.mUnk_04 = src->mUnk_18;
    *dst = tmp;
}

u32 func_02005704(Unk020055f0 *dst, u32 sel, u32 idx, Unk02003a6c *owner, u8 *base0, u32 size0, u8 *base1, u32 size1) {
    Unk02003024 o;
    Unk02005814 s;
    u32 off;
    u8 *base;
    u32 size;

    if (sel == 0) {
        size = size0;
        base = base0;
    } else {
        size = size1;
        base = base1;
    }
    off = idx << 5;
    if (off >= size) {
        return 0;
    }
    func_02004d80(&o);
    if (func_02004afc(&o, owner, (u32) (base + off), (u32) (base + size), -1) == 0) {
        return 0;
    }
    if (func_020048ac(&o, dst, 0x20) != 0x20) {
        func_020049e8(&o);
        return 0;
    }
    func_020049e8(&o);
    dst->mUnk_20 = sel;
    func_02005814(&s, dst);
    if (func_02004a80(&o, s) == 0) {
        return 0;
    }
    dst->mUnk_24 = o.mUnk_20.p.mUnk_04;
    dst->mUnk_28 = o.mUnk_20.p.mUnk_08 - o.mUnk_20.p.mUnk_04;
    func_020049e8(&o);
    return 1;
}

u32 func_020055f0(Unk020055f0 *dst, u32 sel, u32 idx) {
    Unk02003024 o;
    Unk02005814 s;
    Unk02005704 *tab;
    Unk02005704 *x;
    Unk02005704 *y;

    if (sel == 0) {
        tab = &data_0216f35c;
    } else {
        tab = &data_0216f364;
    }
    if (tab->mUnk_00 != 0) {
        if (idx * 32 >= tab->mUnk_04) {
            return 0;
        }
        func_0214d1fc(tab->mUnk_00 + idx * 32, dst, 0x20);
        dst->mUnk_20 = sel;
        func_02004d80(&o);
        func_02005814(&s, dst);
        if (func_02004a80(&o, s) == 0) {
            return 0;
        }
        dst->mUnk_24 = o.mUnk_20.p.mUnk_04;
        dst->mUnk_28 = o.mUnk_20.p.mUnk_08 - o.mUnk_20.p.mUnk_04;
        func_020049e8(&o);
        return 1;
    }
    x = (Unk02005704 *) 0x27ffe50;
    y = (Unk02005704 *) 0x27ffe58;
    return func_02005704(dst, sel, idx, &data_0216f36c, x->mUnk_00, x->mUnk_04, y->mUnk_00, y->mUnk_04);
}

u32 func_02005558(Unk020055f0 *rec, Unk02003024 *o) {
    Unk02005814 s;
    s32 n;

    func_02004d80(o);
    func_02005814(&s, rec);
    if (func_02004a80(o, s) == 0) {
        return 0;
    }
    n = func_02005880(rec);
    func_0200583c(rec);
    if (n == func_020048bc(o, rec->mUnk_04, n)) {
        return 1;
    }
    func_020049e8(o);
    return 0;
}

u32 func_020054b8(Unk020055f0 *rec) {
    Unk02005814 s;
    Unk02003024 o;
    s32 n;

    func_02004d80(&o);
    func_02005814(&s, rec);
    if (func_02004a80(&o, s) == 0) {
        return 0;
    }
    n = func_02005880(rec);
    func_0200583c(rec);
    if (n != func_020048ac(&o, rec->mUnk_04, n)) {
        func_020049e8(&o);
        return 0;
    }
    func_020049e8(&o);
    return 1;
}

u32 func_02005414(const u8 *expected, const u8 *data, u32 n) {
    u8 d[0x14];
    u8 k[0x40];
    u32 i;

    func_0214d168(d, 0, 0x14);
    func_0214d1fc(data_02161768, k, data_0216176c);
    func_02150808(d, data, n, k, data_0216176c);
    for (i = 0; i < 0x14; i += 4) {
        if (*(u32 *) (d + i) != *(u32 *) (expected + i)) {
            break;
        }
    }
    return i == 0x14;
}

void func_02005314(Unk020055f0 *rec) {
    u32 n;
    u32 ok;
    void (**p)(void);
    void (**end)(void);

    n = func_02005880(rec);
    if (*(u16 *) 0x27ffc40 == 2) {
        ok = 0;
        if (rec->mUnk_1c.b[3] & 2) {
            if (rec->mUnk_00 < ((u8 *) &data_0216f340 - (u8 *) OverlaySignatures) / 20) {
                ok = func_02005414(OverlaySignatures[rec->mUnk_00], rec->mUnk_04, n);
            }
        }
        if (ok == 0) {
            func_0214d168(rec->mUnk_04, 0, n);
            func_0200fd1c();
            return;
        }
    }
    if (rec->mUnk_1c.b[3] & 1) {
        func_02000934(rec->mUnk_04 + n);
    }
    func_0200ee74(rec->mUnk_04, rec->mUnk_08);
    p = rec->mUnk_10;
    end = rec->mUnk_14;
    if (p >= end) {
        return;
    }
    do {
        if (*p != 0) {
            (*p)();
        }
        p++;
    } while (p < end);
}

void func_02005210(Unk020055f0 *rec) {
    Unk02005210 *prev;
    Unk02005210 *head;
    Unk02005210 *cur;
    Unk02005210 *next;
    Unk02005210 *found;
    Unk02005210 *last;
    u32 lo;
    u32 hi;
    u32 irq;
    u32 x;
    void *y;

    for (;;) {
        lo = (u32) rec->mUnk_04;
        hi = lo + (rec->mUnk_08 + rec->mUnk_0c);
        found = 0;
        last = 0;
        irq = func_0200fca0();
        prev = 0;
        head = data_0217eeb0;
        cur = head;
        if (head != 0) {
            do {
                y = cur->mUnk_08;
                next = cur->mUnk_00;
                x = (u32) cur->mUnk_04;
                if ((y == 0 && x >= lo && x < hi) || ((u32) y >= lo && (u32) y < hi)) {
                    if (last != 0) {
                        last->mUnk_00 = cur;
                    } else {
                        found = cur;
                    }
                    if (head == cur) {
                        data_0217eeb0 = next;
                        head = next;
                    }
                    cur->mUnk_00 = 0;
                    last = cur;
                    if (prev != 0) {
                        prev->mUnk_00 = next;
                    }
                } else {
                    prev = cur;
                }
                cur = next;
            } while (cur != 0);
        }
        func_0200fcb4(irq);
        if (found == 0) {
            return;
        }
        do {
            next = found->mUnk_00;
            if (found->mUnk_04 != 0) {
                found->mUnk_04(found->mUnk_08);
            }
            found = next;
        } while (found != 0);
    }
}

u32 func_020051f4(Unk020055f0 *rec) {
    func_02005210(rec);
    return 1;
}

u32 func_02005198(u32 sel, u32 idx) {
    Unk020055f0 rec;

    if (func_020055f0(&rec, sel, idx) == 0 || func_020054b8(&rec) == 0) {
        return 0;
    }
    func_02005314(&rec);
    return 1;
}

u32 func_02005144(u32 sel, u32 idx) {
    Unk020055f0 rec;

    if (func_020055f0(&rec, sel, idx) == 0 || func_020051f4(&rec) == 0) {
        return 0;
    }
    return 1;
}

void func_020050c0(u32 sel, u8 *data, u32 n) {
    Unk02005704 *dst;
    u32 irq;

    if (data != 0 && sel == 0) {
        irq = func_02150dc8(1);
        if (func_02005414(data_0216f2dc, data, n) == 0) {
            func_0200fd1c();
        }
        func_02150dc8(irq);
    }
    if (sel == 0) {
        dst = &data_0216f35c;
    } else {
        dst = &data_0216f364;
    }
    irq = func_0200fca0();
    dst->mUnk_00 = data;
    dst->mUnk_04 = n;
    func_0200fcb4(irq);
}

void func_020050b0(Unk02003a6c *p) {
    func_02003be0(p, 0);
}

s32 func_02005064(Unk02003a6c *p, void *buf, u32 off, u32 n) {
    func_021461d8(data_0216f358, off, (u32) buf, n, func_020050b0, (u32) p, 1);
    return 6;
}

s32 func_0200505c(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    return 1;
}

s32 func_02004fcc(Unk02003024 *p, u32 cmd) {
    switch (cmd) {
        case 9:
            func_021457cc(data_0216f354);
            return 0;
        case 10:
            func_021457ac(data_0216f354);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}

s32 func_02004fc4(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    return 1;
}

s32 func_02004fbc(Unk02003024 *p0, u32 p1) {
    return 4;
}

void func_02004e1c(u32 arg) {
    enum { K0 } x, y;

    data_0216f358 = arg;
    data_0216f354 = func_0200cd28();
    data_0216f35c.mUnk_00 = 0;
    data_0216f35c.mUnk_04 = 0;
    data_0216f364.mUnk_00 = 0;
    data_0216f364.mUnk_04 = 0;
    func_02146154();
    func_02004238(&data_0216f36c);
    func_02004128(&data_0216f36c, data_02161764, 3);
    if (*(u16 *) 0x27ffc40 == 2) {
        data_0216f35c.mUnk_00 = (u8 *) -1;
        data_0216f35c.mUnk_04 = 0;
        data_0216f364.mUnk_00 = (u8 *) -1;
        data_0216f364.mUnk_04 = 0;
        func_02003c60(&data_0216f36c, func_02004fbc, -1);
        func_02004018(&data_0216f36c, 0, 0, 0, 0, 0, func_02004fc4, func_0200505c);
        return;
    }
    x = 0x27ffe40;
    y = 0x27ffe48;
    func_02003c60(&data_0216f36c, func_02004fcc, 0x602);
    if (((Unk02005704 *) x)->mUnk_00 == (u8 *) -1) {
        return;
    }
    if (((Unk02005704 *) x)->mUnk_00 == 0) {
        return;
    }
    if (((Unk02005704 *) y)->mUnk_00 == (u8 *) -1) {
        return;
    }
    if (((Unk02005704 *) y)->mUnk_00 == 0) {
        return;
    }
    func_02004018(&data_0216f36c, 0, (u32) ((Unk02005704 *) y)->mUnk_00, ((Unk02005704 *) y)->mUnk_04,
                  (u32) ((Unk02005704 *) x)->mUnk_00, ((Unk02005704 *) x)->mUnk_04, func_02005064, func_0200505c);
}

u32 func_02004dfc(u32 a, u32 b) {
    return func_02003e24(&data_0216f36c, a, b);
}

void func_02004dc0(u32 arg) {
    if (data_0216f350 != 0) {
        return;
    }
    data_0216f350 = 1;
    func_02004e1c(arg);
}
