#include "code_020176c0.h"
#include "code_02134420.h"
#include "Main/Unknown/code_0214d000.h"

Unk020176c0 *func_02017dec(Unk020176c0 *a, u32 b, u16 c) {
    Unk020179d4 *p;
    Unk02017ef8 r;
    Unk02017e70 *v;

    p = &a->mUnk_24;
    func_02017584(&a->mUnk_00, 0x45585048, (u32) (p + 1), b, c);
    p->mUnk_10 = 0;
    p->mUnk_12 = 0;
    p->mUnk_12 &= ~1;
    r.mUnk_00 = a->mUnk_00.mUnk_18;
    r.mUnk_04 = a->mUnk_00.mUnk_1c;
    v = func_02017e70(&r, 0x4652);
    p->mUnk_00.mUnk_00 = v;
    p->mUnk_00.mUnk_04 = v;
    p->mUnk_08.mUnk_00 = 0;
    p->mUnk_08.mUnk_04 = 0;
    return a;
}

void *func_02017c58(Unk020179d4 *a, Unk02017e70 *b, void *c, u32 d, u16 e) {
    Unk02017ef8 r1;
    Unk02017ef8 r2;
    Unk02017ef8 r3;
    Unk02017e70 *p;
    Unk02017e70 *q;
    u32 n;

    func_02017ef8(&r1, b);
    q = (Unk02017e70 *) ((u32) c - 0x10);
    r2.mUnk_04 = r1.mUnk_04;
    r1.mUnk_04 = (u32) q;
    r2.mUnk_00 = d + (u32) c;
    p = func_02017ed0(&a->mUnk_00, b);
    if (r1.mUnk_04 - r1.mUnk_00 < 0x10) {
        r1.mUnk_04 = r1.mUnk_00;
    } else {
        p = func_02017ea0(&a->mUnk_00, func_02017e70(&r1, 0x4652), p);
    }
    if (r2.mUnk_04 - r2.mUnk_00 < 0x10) {
        r2.mUnk_00 = r2.mUnk_04;
    } else {
        func_02017ea0(&a->mUnk_00, func_02017e70(&r2, 0x4652), p);
    }
    n = r2.mUnk_00 - r1.mUnk_04;
    {
        volatile u32 z;

        if ((u16) (*(u32 *) ((u8 *) a - 4) & 0xff) & 1) {
            z = 0;
            func_0214d018(z, (void *) r1.mUnk_04, n);
        }
    }
    r3.mUnk_00 = (u32) q;
    r3.mUnk_04 = r2.mUnk_00;
    p = func_02017e70(&r3, 0x5544);
    p->mUnk_02 &= ~0x8000;
    p->mUnk_02 |= (e & 1) << 15;
    {
        u32 t = (u32) p - r1.mUnk_04;

        p->mUnk_02 &= ~0x7f00;
        p->mUnk_02 |= ((u16) t & 0x7f) << 8;
    }
    {
        u8 g = a->mUnk_10;

        p->mUnk_02 &= ~0xff;
        p->mUnk_02 |= g;
    }
    func_02017ea0(&a->mUnk_08, p, a->mUnk_08.mUnk_04);
    return c;
}

void *func_02017b90(Unk020176c0 *a, u32 b, u32 c) {
    Unk020179d4 *p;
    Unk02017e70 *q;
    Unk02017e70 *b0;
    u32 a0;
    u32 v0;
    u32 v1;
    int bestaddr;
    u32 m;
    u32 f;

    p = &a->mUnk_24;
    f = (u16) (p->mUnk_12 & 1) == 0 ? 1 : 0;
    q = p->mUnk_00.mUnk_00;
    b0 = 0;
    bestaddr = 0;
    v1 = -1;
    if (q != 0) {
        m = c - 1;
        do {
            a0 = (m + ((u32) (q + 1))) & ~m;
            v0 = q->mUnk_04;
            if (v0 >= b + (a0 - ((u32) (q + 1))) && v1 > v0) {
                b0 = q;
                v1 = v0;
                bestaddr = a0;
                if (f != 0) {
                    break;
                }
                if (v0 == b) {
                    break;
                }
            }
            q = q->mUnk_0c;
        } while (q != 0);
    }
    if (b0 == 0) {
        return 0;
    }
    return func_02017c58(p, b0, (void *) bestaddr, b, 0);
}

void *func_02017acc(Unk020176c0 *a, u32 b, u32 c) {
    int v0;
    u32 m;
    u32 a0;
    Unk02017e70 *q;
    Unk02017e70 *b0;
    u32 v1;
    Unk020179d4 *p;
    int g0;
    int bestaddr;
    u32 f;

    p = &a->mUnk_24;
    f = (u16) (p->mUnk_12 & 1) == 0 ? 1 : 0;
    v1 = -1;
    b0 = 0;
    q = p->mUnk_00.mUnk_04;
    bestaddr = 0;
    if (q != 0) {
        m = ~(c - 1);
        do {
            u32 t = q->mUnk_04;

            v0 = t;
            a0 = (v0 + ((u32) (q + 1)) - b) & m;
            g0 = a0 - ((u32) (q + 1));
            if (g0 >= 0 && v1 > v0) {
                b0 = q;
                v1 = (u32) v0;
                bestaddr = a0;
                if (f != 0) {
                    break;
                }
                if (v0 == b) {
                    break;
                }
            }
            q = q->mUnk_08;
        } while (q != 0);
    }
    if (b0 == 0) {
        return 0;
    }
    return func_02017c58(p, b0, (void *) bestaddr, b, 1);
}

u32 func_020179d4(Unk020179d4 *a, Unk02017ef8 *b) {
    Unk02017ef8 r;
    Unk02017e70 *p;
    Unk02017e70 *q;

    r = *b;
    q = 0;
    p = a->mUnk_00.mUnk_00;
    if (p != 0) {
        do {
            if ((u32) p < b->mUnk_00) {
                q = p;
            } else {
                if ((u32) p == b->mUnk_04) {
                    r.mUnk_04 = p->mUnk_04 + ((u32) (p + 1));
                    func_02017ed0(&a->mUnk_00, p);
                }
                break;
            }
            p = p->mUnk_0c;
        } while (p != 0);
    }
    if (q != 0) {
        u32 s = q->mUnk_04 + ((u32) (q + 1));

        if (s == b->mUnk_00) {
            r.mUnk_00 = (u32) q;
            q = func_02017ed0(&a->mUnk_00, q);
        }
    }
    if (r.mUnk_04 - r.mUnk_00 < 0x10) {
        return 0;
    }
    func_02017ea0(&a->mUnk_00, func_02017e70(&r, 0x4652), q);
    return 1;
}

Unk020176c0 *func_02017988(void *a, u32 b, u16 c) {
    u32 e;

    e = (b + (u32) a) & ~3;
    a = (void *) (((u32) a + 3) & ~3);
    if ((u32) a > e || e - (u32) a < 0x4c) {
        return 0;
    }
    return func_02017dec(a, e, c);
}

void func_0201797c(Unk02017584 *a) {
    func_02017568(a);
}

void *func_02017938(Unk020176c0 *a, u32 b, s32 c) {
    if (b == 0) {
        b = 1;
    }
    b = (b + 3) & ~3;
    if (c >= 0) {
        return func_02017b90(a, b, c);
    }
    return func_02017acc(a, b, -c);
}

u32 func_020177b0(Unk020176c0 *a, void *b, u32 c) {
    Unk02017ef8 r1;
    u32 start;
    Unk02017e70 *r;
    Unk02017e70 *prev;
    Unk02017ef8 r2;
    u32 sz;
    Unk020179d4 *p;
    Unk02017e70 *q;
    u32 e;
    u32 t;
    u32 n;

    q = (Unk02017e70 *) ((u8 *) b - 0x10);
    sz = q->mUnk_04;
    c = (c + 3) & ~3;
    p = &a->mUnk_24;
    if (c == sz) {
        return c;
    }
    if (c > sz) {
        r = p->mUnk_00.mUnk_00;
        t = sz + ((u32) (q + 1));
        if (r != 0) {
            do {
                if ((u32) r == t) {
                    break;
                }
                r = r->mUnk_0c;
            } while (r != 0);
        }
        if (r == 0 || c > sz + 0x10 + r->mUnk_04) {
            return 0;
        }
        func_02017ef8(&r1, r);
        prev = func_02017ed0(&p->mUnk_00, r);
        e = c + (u32) b;
        start = r1.mUnk_00;
        r1.mUnk_00 = e;
        if (r1.mUnk_04 - e < 0x10) {
            r1.mUnk_00 = r1.mUnk_04;
        }
        q->mUnk_04 = r1.mUnk_00 - (u32) b;
        if (r1.mUnk_04 - r1.mUnk_00 >= 0x10) {
            func_02017ea0(&p->mUnk_00, func_02017e70(&r1, 0x4652), prev);
        }
        n = r1.mUnk_00 - start;
        {
            volatile u32 z;

            if ((u16) (a->mUnk_00.mUnk_20 & 0xff) & 1) {
                z = 0;
                func_0214d018(z, (void *) start, n);
            }
        }
    } else {
        r2.mUnk_00 = c + (u32) b;
        r2.mUnk_04 = q->mUnk_04 + ((u32) (q + 1));
        q->mUnk_04 = c;
        if (func_020179d4(&a->mUnk_24, &r2) == 0) {
            q->mUnk_04 = sz;
        }
    }
    return q->mUnk_04;
}

void func_02017770(Unk020176c0 *a, void *b) {
    Unk020179d4 *p;
    Unk02017e70 *q;
    Unk02017ef8 r;

    q = (Unk02017e70 *) ((u8 *) b - 0x10);
    p = &a->mUnk_24;
    func_02017ef8(&r, q);
    func_02017ed0(&p->mUnk_08, q);
    func_020179d4(p, &r);
}

u32 func_02017748(Unk020176c0 *a) {
    Unk02017e70 *p;
    u32 n;

    p = a->mUnk_24.mUnk_00.mUnk_00;
    n = 0;
    if (p == 0) {
        return n;
    }
    do {
        n += p->mUnk_04;
        p = p->mUnk_0c;
    } while (p != 0);
    return n;
}

u32 func_020176c0(Unk020176c0 *a, u32 b) {
    u32 m;
    u32 b0;
    u32 off;
    Unk02017e70 *p;
    u32 s;
    u32 e;
    u32 n;
    u32 l;
    u32 d;

    m = func_02134420(b);
    b0 = 0;
    off = -1;
    for (p = a->mUnk_24.mUnk_00.mUnk_00; p != 0; p = p->mUnk_0c) {
        {
            s = (u32) (p + 1);
            n = ((u32) (m - 1) + s) & ~(m - 1);
            e = p->mUnk_04 + s;
            if (n < e) {
                l = e - n;
                d = n - s;
                if (b0 < l || (b0 == l && off > d)) {
                    b0 = l;
                    off = d;
                }
            }
        }
    }
    return b0;
}
