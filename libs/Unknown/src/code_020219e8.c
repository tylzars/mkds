#include "code_020219e8.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02020e3c.h"

void func_02021cd4(Unk02021968 *a, u32 b, Unk02021968 *c) {
    Unk02021968 *n;
    Unk02021be8 *t;
    Unk02021be8 *e;
    Unk02021be8 *h;
    Unk02021be8 *x;

    func_02020e50();
    n = a->mUnk_18[b].mUnk_00;
    if (n != 0) {
        if (c == n) {
            func_02020e3c();
            return;
        }
        t = n->mUnk_18[0].mUnk_00;
        e = &a->mUnk_18[b];
        if (e == t) {
            n->mUnk_18[0].mUnk_00 = a->mUnk_18[b].mUnk_04;
            func_0200ee58(a->mUnk_18[b].mUnk_00, 0x3c);
        } else {
            while (t != 0) {
                x = t->mUnk_04;
                if (e == x) {
                    break;
                }
                t = x;
            }
            t->mUnk_04 = a->mUnk_18[b].mUnk_04;
            func_0200ee58(t, 8);
        }
    }
    h = c->mUnk_18[0].mUnk_00;
    c->mUnk_18[0].mUnk_00 = &a->mUnk_18[b];
    a->mUnk_18[b].mUnk_04 = h;
    a->mUnk_18[b].mUnk_00 = c;
    func_02020e3c();
    func_0200ee58(a, 0x3c);
    func_0200ee58(c, 0x3c);
}

void func_02021c34(Unk02021968 *a) {
    s32 i;
    Unk02021968 *n;
    Unk02021be8 *t;
    Unk02021be8 *e;
    Unk02021be8 *x;

    func_02020e50();
    e = &a->mUnk_18[0];
    for (i = 0; i < 4; i++) {
        n = a->mUnk_18[i].mUnk_00;
        if (n != 0) {
            t = n->mUnk_18[0].mUnk_00;
            if (e == t) {
                n->mUnk_18[0].mUnk_00 = a->mUnk_18[i].mUnk_04;
                func_0200ee58(n, 0x3c);
            } else {
                while (t != 0) {
                    x = t->mUnk_04;
                    if (e == x) {
                        break;
                    }
                    t = x;
                }
                t->mUnk_04 = a->mUnk_18[i].mUnk_04;
                func_0200ee58(t, 8);
            }
        }
        e++;
    }
    func_02020e3c();
}

void func_02021be8(Unk02021968 *a) {
    Unk02021be8 *p;
    Unk02021be8 *n;

    func_02020e50();
    p = a->mUnk_18[0].mUnk_00;
    if (p != 0) {
        do {
            n = p->mUnk_04;
            p->mUnk_00 = 0;
            p->mUnk_04 = 0;
            func_0200ee58(p, 8);
            p = n;
        } while (n != 0);
    }
    func_02020e3c();
}

void func_02021bc8(Unk02021bc8 *a) {
    Unk02021bc8 t;

    t.mUnk_00 = 0;
    t.mUnk_04 = 0;
    *a = t;
}

u32 func_020219f0(Unk02021968 *a, Unk020219f0 *b, Unk02021bc8 *c) {
    u32 w;
    Unk02021a60 *p;
    Unk02021aa8 *q;
    Unk02021b24 *r;

    while (c->mUnk_00 < a->mUnk_38) {
        w = a->mUnk_3c[c->mUnk_00];
        b->mUnk_00 = w;
        switch (b->mUnk_00) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                p = (Unk02021a60 *) ((u8 *) a + (w >> 8));
                *(Unk02021a5c *) &b->mUnk_02 = p->mUnk_00;
                *(Unk02021a5c *) &b->mUnk_06 = p->mUnk_04;
                b->mUnk_0a = p->mUnk_08;
                c->mUnk_00++;
                return 1;
            case 0x10:
                q = (Unk02021aa8 *) ((u8 *) a + (w >> 8));
                while (c->mUnk_04 < q->mUnk_01 - q->mUnk_00 + 1) {
                    *(Unk02021ab0 *) b = q->mUnk_02[c->mUnk_04];
                    c->mUnk_04++;
                    return 1;
                }
                break;
            case 0x11:
                r = (Unk02021b24 *) ((u8 *) a + (w >> 8));
                while (c->mUnk_04 < 8) {
                    if (r->mUnk_00[c->mUnk_04] == 0) {
                        break;
                    }
                    *(Unk02021ab0 *) b = r->mUnk_08[c->mUnk_04];
                    c->mUnk_04++;
                    return 1;
                }
                break;
        }
        c->mUnk_00++;
        c->mUnk_04 = 0;
    }
    return 0;
}

u32 func_020219e8(Unk02021968 *a) {
    return a->mUnk_38;
}
