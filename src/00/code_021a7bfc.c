#include "00/code_021a7bfc.h"
#include "00/code_021a8000.h"
#include "00/code_021ae314.h"
#include "00/code_021a6d6c.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a7048.h"
#include "00/code_021a78a4.h"
#include "00/code_021a7bc8.h"
#include "00/code_021a8db8.h"
#include "00/code_021a911c.h"
#include "00/code_021a8a5c.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a8ae8.h"
#include "00/code_021ae258.h"
#include "00/code_021ae2f4.h"
#include "00/code_02186d7c.h"
#include "00/code_021ae000.h"
#include "00/unk_021b5000.h"
#include "00/unk_021b6000.h"
#include "code_0200dc3c.h"
#include "code_0200db5c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

static inline s32 func_ov000_021a7c4c_inline(Unk021a6fa8 *a) {
    s32 b = 1;
    if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
        b = 0;
    }
    return b;
}

static inline s32 func_ov000_021a7de0_inline(Unk021a6fa8 *a) {
    s32 b = 0;
    if (a != 0) {
        b = (a->mUnk_70 & 1) != 0;
    }
    return b;
}

u8 *func_ov000_021a7bfc(Unk021a6fa8 *a, s32 *b, u16 *c, u16 *d, u32 *e) {
    Unk021a71c0 *f = a->mUnk_64;
    Unk021a6fa8 *g = *(Unk021a6fa8 **) f->mUnk_00.mUnk_20.mUnk_a4;
    s32 h = f->mUnk_f8;
    s32 i = g->mUnk_44 - h;
    if (i >= 0) {
        *c = g->mUnk_0a;
        *d = g->mUnk_18;
        *e = g->mUnk_1c;
        *b = i;
        if (i == 0 && g->mUnk_08 != 4) {
            return 0;
        }
    } else {
        *b = -1;
        return 0;
    }
    return g->mUnk_3c.mUnk_04 + h;
}

s32 func_ov000_021a7c4c(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e) {
    u32 f = func_0200fca0();
    u16 g[2];
    s32 h;
    u32 i;
    u8 *j;
    s32 k;
    j = func_ov000_021a7bfc(a, &h, &g[0], &g[1], &i);
    if (j != 0) {
        k = h;
        if (k == 0) {
            k = -6;
        } else {
            if (c > k) {
                c = k;
            }
            if (func_ov000_021a7c4c_inline(a) != 0) {
                k = c;
            }
            func_0214d1fc(j, b, c);
            if (((Unk021a71c0 *) a->mUnk_64)->mUnk_fe == 0) {
                ((Unk021a71c0 *) a->mUnk_64)->mUnk_f8 = ((Unk021a71c0 *) a->mUnk_64)->mUnk_f8 + k;
            }
        }
    } else {
        if (h == 0) {
            k = 0;
        } else {
            k = -0x1c;
        }
        a->mUnk_70 &= ~6;
    }
    if (k >= 0) {
        if (d != 0 && e != 0) {
            *d = g[1];
            *e = i;
        }
        if (a->mUnk_74 == 0) {
            a->mUnk_74 = g[0];
        }
    }
    func_0200fcb4(f);
    return k;
}

s32 func_ov000_021a7d14(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f) {
    s32 g;
    if (a->mUnk_73 == 4) {
        return func_ov000_021a7bc8((u32) a, (u32) b, (u32) c, (u32) d, (u32) e);
    }
    g = func_ov000_021a7c4c(a, b, c, d, e);
    if (g == -6 && f == 1) {
        g = func_ov000_021a7bc8((u32) a, (u32) b, (u32) c, (u32) d, (u32) e);
    }
    return g;
}

s32 func_ov000_021a7d68(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f, s32 g) {
    Unk021a71c0 *h = a->mUnk_64;
    s32 i;
    s32 j;
    s32 k;
    if ((g & 2) != 0 && h != 0) {
        k = 1;
    } else {
        k = 0;
    }
    if (k != 0) {
        i = h->mUnk_fe;
        h->mUnk_fe = 1;
    }
    if (a->mUnk_73 == 1) {
        j = func_ov000_021a797c(a, b, c, d, e, f);
    } else {
        j = func_ov000_021a7d14(a, b, c, d, e, f);
        if (j >= 0) {
            func_ov000_021a7aa8(a);
        }
    }
    if (k != 0) {
        h->mUnk_fe = i;
    }
    return j;
}

u32 func_ov000_021a7de0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *g = (Unk021a6fa8 *) a;
    Unk021a71c0 *h;
    s32 i;
    v = g;
    if (func_ov000_021a8a80(g) != 0) {
        return -0x1c;
    }
    if ((f & 4) != 0 || g->mUnk_72 == 0) {
        if (g->mUnk_73 == 4) {
            return -0x1c;
        }
        i = 0;
    } else {
        if (func_0200fcf8() == 0x12) {
            return -0x1c;
        }
        i = 1;
    }
    if (func_ov000_021a7de0_inline(g) == 0) {
        return -0x27;
    }
    if (func_ov000_021a7c4c_inline(g) != 0) {
        if ((v->mUnk_70 & 4) == 0 || (v->mUnk_70 & 8) != 0) {
            return -0x38;
        }
    }
    h = g->mUnk_64;
    if (i == 0) {
        if (func_0200ec08(&h->mUnk_00.mUnk_e0) == 0) {
            return -6;
        }
    } else {
        func_0200ed34(&h->mUnk_00.mUnk_e0);
    }
    i = func_ov000_021a7d68(g, (void *) b, c, (u16 *) d, (u32 *) e, i, f);
    func_0200ecc4(&h->mUnk_00.mUnk_e0);
    return i;
}

s32 func_ov000_021a7eec(const void *a, s32 b, Unk021a7eec *c) {
    s32 d = c->mUnk_14;
    s32 e = c->mUnk_1c;
    if (d > b) {
        d = b;
        e = 0;
    } else if (e > b - d) {
        e = b - d;
    }
    if (d > 0) {
        func_0214d1fc(c->mUnk_10, a, d);
        c->mUnk_10 += d;
        c->mUnk_14 -= d;
    }
    if (e > 0) {
        func_0214d1fc(c->mUnk_18, (u8 *) a + d, e);
        c->mUnk_18 += e;
        c->mUnk_1c -= e;
    }
    return d + e;
}

s32 func_ov000_021a7f48(Unk021a7064 *param_1) {
    Unk021a7eec *a = (Unk021a7eec *) param_1;
    Unk021a6fa8 *b = a->mUnk_04;
    Unk021a722a *c = b->mUnk_68;
    s32 e;
    u8 *f;
    s32 d = 0;
    s32 g;
    s32 h;
    if (func_ov000_021a7c4c_inline(b) == 0 || (b->mUnk_70 & 4) != 0) {
        if (a->mUnk_28 != 0) {
            func_ov000_021ae290(a->mUnk_24, a->mUnk_26, (int) a->mUnk_28);
        }
        if (func_ov000_021a7c4c_inline(b) != 0) {
            e = 0x36;
        } else {
            e = 0x2a;
        }
        f = b->mUnk_48.mUnk_04 + e;
        g = b->mUnk_48.mUnk_00 - e;
        for (;;) {
            h = func_ov000_021a7eec(f, g, a);
            if (h <= 0) {
                break;
            }
            h = func_ov000_021adbf4(f, h);
            if (h <= 0) {
                if (func_ov000_021a7c4c_inline(b) != 0) {
                    b->mUnk_70 &= ~0xe;
                }
                d = -0x4c;
                break;
            }
            d += h;
        }
    } else {
        d = -0x4c;
    }
    c->mUnk_102 = a->mUnk_20;
    func_0200df9c((Unk0200df9c *) &c->mUnk_104);
    return d;
}

s32 func_ov000_021a8014(Unk021a6fa8 *a, u8 *b, s32 c, s32 d, u16 e, u16 *f, s32 g) {
    Unk021a722a *h = a->mUnk_68;
    Unk021a7eec *i;
    s32 j;
    u8 *k;
    s32 l;
    s32 m;
    i = (Unk021a7eec *) func_ov000_021a7064(func_ov000_021a7f48, h->mUnk_10c, g);
    if (i == 0) {
        return -0x21;
    }
    i->mUnk_0d = 0;
    j = 0;
    k = h->mUnk_f8.mUnk_04;
    l = h->mUnk_f8.mUnk_00;
    m = d + c;
    if (m < l) {
        i->mUnk_10 = k + d;
        i->mUnk_14 = c;
        i->mUnk_18 = (u8 *) j;
        i->mUnk_1c = j;
        d = m;
    } else {
        i->mUnk_10 = k + d;
        i->mUnk_14 = l - d;
        i->mUnk_18 = k;
        i->mUnk_1c = c - i->mUnk_14;
        d = i->mUnk_1c;
        func_0214d1fc(b + i->mUnk_14, i->mUnk_18, d);
    }
    func_0214d1fc(b, i->mUnk_10, i->mUnk_14);
    i->mUnk_20 = d;
    h->mUnk_100 = i->mUnk_20;
    if (a->mUnk_73 == 1) {
        if (a->mUnk_74 == 0) {
            a->mUnk_74 = func_ov000_021ae340();
            a->mUnk_0a = a->mUnk_74;
        }
        i->mUnk_24 = a->mUnk_74;
        if (a->mUnk_78 == 0 || f != 0) {
            i->mUnk_28 = f;
            i->mUnk_26 = e;
        } else {
            i->mUnk_28 = a->mUnk_78;
            i->mUnk_26 = a->mUnk_76;
        }
    } else {
        i->mUnk_28 = 0;
    }
    if (func_ov000_021a6fa8(h->mUnk_10c, i) != 0) {
        c = 0;
    }
    return c;
}

s32 func_ov000_021a8118(Unk021a6fa8 *a) {
    Unk021a722a *b = a->mUnk_68;
    s32 c = b->mUnk_f8.mUnk_00;
    s32 d = b->mUnk_100;
    d = b->mUnk_102 - d - 1;
    if (d < 0) {
        d += c;
    }
    return d;
}

s32 func_ov000_021a813c(Unk021a6fa8 *a, s32 b, s32 c, u32 *d, s32 e) {
    Unk021a722a *f = a->mUnk_68;
    s32 g;
    u32 h;
    if (c > b) {
        c = b;
    }
    h = func_0200fca0();
    for (;;) {
        g = func_ov000_021a8118(a);
        if (g >= c) {
            if (g >= b) {
                g = b;
            }
            *d = f->mUnk_100;
            break;
        }
        if (e == 0) {
            g = 0;
            break;
        }
        func_0200e01c((Unk0200df9c *) &f->mUnk_104);
    }
    func_0200fcb4(h);
    return g;
}

s32 func_ov000_021a81a8(Unk021a6fa8 *a, u8 *b, s32 c, u16 d, u16 *e, s32 f) {
    s32 h;
    s32 g;
    s32 i;
    u32 j;
    g = 0;
    h = ((Unk021a722a *) a->mUnk_68)->mUnk_10c->mUnk_48.mUnk_00;
    if (a->mUnk_73 == 1) {
        h -= 0x2a;
        if (c > h) {
            return -0x23;
        }
        h = c;
    } else {
        h -= 0x36;
        if (c <= h) {
            h = c;
        }
    }
    while (c > 0) {
        i = func_ov000_021a813c(a, c, h, &j, f);
        if (i > 0) {
            if (func_ov000_021a8014(a, b, i, j, d, e, f) <= 0) {
                return -6;
            }
            b += i;
            c -= i;
            g += i;
        }
        if (f == 0) {
            if (i > 0) {
                break;
            }
            return -6;
        }
    }
    return g;
}

// non-matching: the incoming arguments sit in other registers (original: second in r6, third in r7, fourth at [sp, #8];
// ours: r7, [sp, #8], r6); the volatile view reloads the halfword at 0x70 for each test as the original does; size 0xdc
// against 0xda
u32 func_ov000_021a8268(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *g = (Unk021a6fa8 *) a;
    Unk021a722a *h;
    s32 i;
    s32 j;
    v = g;
    if (func_ov000_021a8a80(g) != 0) {
        return -0x1c;
    }
    if (func_ov000_021a7de0_inline(g) == 0) {
        return -0x27;
    }
    if (func_ov000_021a7c4c_inline(g) != 0) {
        if ((v->mUnk_70 & 4) == 0 || (v->mUnk_70 & 8) != 0) {
            return -0x38;
        }
    }
    h = g->mUnk_68;
    if ((f & 4) != 0 || g->mUnk_72 == 0) {
        if (func_0200ec08(&h->mUnk_00.mUnk_e0) == 0) {
            return -6;
        }
        i = 0;
    } else {
        func_0200ed34(&h->mUnk_00.mUnk_e0);
        i = 1;
    }
    j = func_ov000_021a81a8(g, (u8 *) b, c, d, (u16 *) e, i);
    func_0200ecc4(&h->mUnk_00.mUnk_e0);
    return j;
}

s32 func_ov000_021a8344(Unk021a7064 *a) {
    if (func_ov000_021a7c4c_inline(a->mUnk_04) != 0) {
        func_ov000_021ae094();
    }
    return 0;
}

s32 func_ov000_021a836c(s32 param_1) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    Unk021a722a *b;
    Unk021a7064 *c;
    v = a;
    if (func_ov000_021a8a80(a) != 0) {
        return -0x1c;
    }
    if (func_ov000_021a7de0_inline(a) == 0) {
        return -0x27;
    }
    if ((v->mUnk_70 & 4) == 0 || (v->mUnk_70 & 8) != 0) {
        return -0x38;
    }
    v->mUnk_70 |= 8;
    b = a->mUnk_68;
    if (b != 0 && b->mUnk_10c != 0) {
        c = func_ov000_021a7064(func_ov000_021a8344, b->mUnk_10c, a->mUnk_72);
        if (c == 0) {
            return -0x21;
        }
        return func_ov000_021a6fa8(b->mUnk_10c, c);
    }
    return 0;
}

void func_ov000_021a8424(void) {
    u32 a = func_0200fca0();
    while (data_ov000_021b6008 != 0) {
        func_ov000_021a84c4(data_ov000_021b6008);
    }
    func_0200fcb4(a);
}

void func_ov000_021a8454(Unk021a7154 *a) {
    Unk021a7064 *b;
    u32 c;
    if (a != 0) {
        func_0200e084(&a->mUnk_20);
        c = func_0200fca0();
        func_0200db9c();
        if (func_0200ea3c(&a->mUnk_00, (void **) &b, 0) != 0) {
            do {
                if (b != 0) {
                    if (b->mUnk_08 != 0) {
                        func_0200eae8(b->mUnk_08, (void *) -11, 0);
                    }
                    func_ov000_021a7048(b);
                }
            } while (func_0200ea3c(&a->mUnk_00, (void **) &b, 0) != 0);
        }
        func_0200db64();
        func_0200fcb4(c);
        func_0200de50();
    }
}

void func_ov000_021a84c4(Unk021a6fa8 *a) {
    Unk021a78a4 *b;
    Unk021a78a4 *c;
    u32 d;
    if (a != 0) {
        a->mUnk_70 = 0;
        if (func_ov000_021a7c4c_inline(a) != 0) {
            func_ov000_021a8454(a->mUnk_68);
            func_ov000_021a8454(a->mUnk_64);
        } else if (a->mUnk_73 == 1) {
            b = ((Unk021a71c0 *) a->mUnk_64)->mUnk_104;
            while (b != 0) {
                c = b->mUnk_00;
                data_ov000_021b5f94->mUnk_1c(b);
                b = c;
            }
            ((Unk021a71c0 *) a->mUnk_64)->mUnk_108 = 0;
            ((Unk021a71c0 *) a->mUnk_64)->mUnk_100 = 0;
            ((Unk021a71c0 *) a->mUnk_64)->mUnk_104 = 0;
            func_0200df9c(&((Unk021a71c0 *) a->mUnk_64)->mUnk_10c);
            func_ov000_021a8454(a->mUnk_64);
        } else if (a->mUnk_73 == 2) {
            func_ov000_021a8454(a->mUnk_68);
        }
        d = func_0200fca0();
        func_ov000_021a8ae8((u32) a);
        func_ov000_021a8aa8((u32) a);
        data_ov000_021b5f94->mUnk_1c(a);
        func_0200fcb4(d);
    }
}

s32 func_ov000_021a8580(Unk021a7064 *a) {
    Unk021a6fa8 *b = a->mUnk_04;
    void *c;
    u32 d;
    if (func_ov000_021a7c4c_inline(b) != 0) {
        func_0200e084(&((Unk021a722a *) b->mUnk_68)->mUnk_00.mUnk_20);
        func_ov000_021ae094();
        func_ov000_021ae048();
        func_ov000_021ae258();
    }
    func_ov000_021ae2f4();
    b->mUnk_70 &= ~6;
    if (b->mUnk_73 == 2) {
        c = b->mUnk_68;
    } else {
        c = b->mUnk_64;
    }
    func_ov000_021a7008(c, 0);
    d = func_0200fca0();
    func_ov000_021a8ae8((u32) b);
    func_ov000_021a8af8((u32) b);
    func_0200fcb4(d);
    b->mUnk_70 |= 0x20;
    return 0;
}

s32 func_ov000_021a8604(s32 param_1) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    Unk021a7064 *c;
    v = a;
    if (param_1 <= 0) {
        return -0x1c;
    }
    if (func_ov000_021a8a5c((Unk021a8ab8 *) a) != 0) {
        return -0x1a;
    }
    if (func_ov000_021a8a80(a) != 0) {
        return 0;
    }
    if (func_ov000_021a7de0_inline(a) == 0) {
        return -0x27;
    }
    if ((v->mUnk_70 & 0x10) != 0) {
        return -0x1a;
    }
    v->mUnk_70 |= 0x18;
    if (func_ov000_021a7c4c_inline(a) != 0) {
        func_ov000_021a7008(a->mUnk_68, 0);
    }
    c = func_ov000_021a7064(func_ov000_021a8580, a, 1);
    c->mUnk_0d = 0;
    return func_ov000_021a6f84(a, c);
}
