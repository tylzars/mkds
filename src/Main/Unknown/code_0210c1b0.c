#include "Main/Unknown/code_0210c1b0.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_0212c668.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210bc14.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0210bce0.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "code_0212c478.h"
#include "code_0212c6ac.h"
#include "code_0212d254.h"

// non-matching: the parameter is in r6 here and r5 in the original, the loop pointer in r5 and r4, and
// the hoisted address of data_0217d054 in r4 and r6; the instructions are otherwise identical.
void func_0210cc3c(Unk0210bfbc *p) {
    Unk0210bf24 *a;
    u32 v;
    u32 f;

    v = 0;
    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    if ((p->mUnk_34 & 1) == 0) {
        if (p->mUnk_34 & 2) {
            func_0210c238(p, 0);
        }
        p->mUnk_34 &= ~2;
        if ((p->mUnk_34 & 4) == 0) {
            return;
        }
        if ((p->mUnk_34 & 1) == 0) {
            p->mUnk_34 |= 1;
        } else {
            p->mUnk_34 &= ~1;
        }
        p->mUnk_34 &= ~4;
        return;
    }
    p->mUnk_34 |= 2;
    if (p->mUnk_34 & 4) {
        if ((p->mUnk_34 & 1) == 0) {
            p->mUnk_34 |= 1;
        } else {
            p->mUnk_34 &= ~1;
        }
        p->mUnk_34 &= ~4;
    }
    a = (Unk0210bf24 *) p->mUnk_0c.mUnk_00;
    while (a != 0) {
        f = (a->mUnk_19 & 8) != 0;
        a->mUnk_19 &= ~8;
        if (a->mUnk_00 != 0) {
            if (a->mUnk_19 & 4) {
                if (f == 0) {
                    v = (u32) a;
                    a = (Unk0210bf24 *) func_0201733c(&p->mUnk_0c, a);
                    func_0212c6f0((Unk0212c400 **) v, 0);
                    ((Unk0210bf24 *) v)->mUnk_19 &= ~4;
                    ((Unk0210bf24 *) v)->mUnk_19 &= ~8;
                    ((Unk0210bf24 *) v)->mUnk_19 &= ~2;
                    func_0210bc54(&p->mUnk_0c, (u8 *) v);
                    v = 1;
                    continue;
                }
            } else if (a->mUnk_19 & 1) {
                if (p->mUnk_18 == 3) {
                    func_0210bc8c((int) data_0217d054, (int) p);
                    p->mUnk_18 = 1;
                }
            }
        } else if ((a->mUnk_19 & 2) == 0) {
            v = (u32) a;
            a = (Unk0210bf24 *) func_0201733c(&p->mUnk_0c, a);
            func_0212c6f0((Unk0212c400 **) v, 0);
            ((Unk0210bf24 *) v)->mUnk_19 &= ~4;
            ((Unk0210bf24 *) v)->mUnk_19 &= ~8;
            ((Unk0210bf24 *) v)->mUnk_19 &= ~2;
            func_0210bc54(&p->mUnk_0c, (u8 *) v);
            v = 1;
            continue;
        }
        a = (Unk0210bf24 *) func_0201733c(&p->mUnk_0c, a);
    }
    if (v == 0) {
        return;
    }
    v = 3;
    for (a = (Unk0210bf24 *) p->mUnk_0c.mUnk_00; a != 0; a = (Unk0210bf24 *) func_0201733c(&p->mUnk_0c, a)) {
        if (a->mUnk_19 & 2) {
            v = 0;
            break;
        }
        if (a->mUnk_19 & 8 || a->mUnk_19 & 1) {
            v = 1;
        }
    }
    if (p->mUnk_18 != v) {
        if (p->mUnk_18 != 3) {
            func_0210bc54((Unk02017328 *) (data_0217d048 + p->mUnk_18 * 0xc), (u8 *) p);
            p->mUnk_18 = 3;
        }
        if (v != 3) {
            func_0210bc8c((int) (data_0217d048 + v * 0xc), (int) p);
            p->mUnk_18 = v;
        }
    }
}

// non-matching: the parameter is in sl here and r5 in the original and the loop pointer in r9 and r4; the load of
// st.mUnk_1c is scheduled after the func_0212d580 call here and before it in the original.
u32 func_0210ca4c(Unk0210bfbc *p) {
    Unk0210bcf4 st;
    s32 n;
    void *a;

    st.mUnk_00 = p;
    st.mUnk_04 = p->mUnk_28;
    st.mUnk_20 = 0;
    st.mUnk_14 = 0;
    st.mUnk_1c = 0;
    st.mUnk_18 = 0;
    if (st.mUnk_04 == 0) {
        st.mUnk_10 = 0;
        st.mUnk_14 = 0x7f;
        st.mUnk_1c = 0x7f;
        st.mUnk_18 = 0;
    } else {
        st.mUnk_10 = (*(u32(*)(void *)) * (u32 *) data_0217d018)(&st);
        st.mUnk_1c = st.mUnk_14 = (*(u32(*)(void *)) * (u32 *) data_0217d014)(&st);
        st.mUnk_18 = (*(u32(*)(void *)) * (u32 *) data_0217d01c)(&st);
    }
    if (st.mUnk_14 <= 0) {
        func_0210c0bc(p);
        return 0;
    }
    for (a = p->mUnk_0c.mUnk_00; a != 0; a = func_0201733c(&p->mUnk_0c, a)) {
        n = -1;
        if (((Unk0210bf24 *) a)->mUnk_19 & 2) {
            n = st.mUnk_1c +
                (func_0212d580(((Unk0210bf24 *) a)->mUnk_18, ((Unk0210bf24 *) a)->mUnk_16)->mUnk_04 - 0x40);
            if (n > 0) {
                if (n >= 0x7f) {
                    n = 0x7f;
                }
            } else {
                n = 0;
            }
            p->mUnk_2c(p, a, n);
            ((Unk0210bf24 *) a)->mUnk_19 &= ~2;
        }
        if (((Unk0210bf24 *) a)->mUnk_00 != 0) {
            if (n == -1) {
                n = st.mUnk_1c +
                    (func_0212d580(((Unk0210bf24 *) a)->mUnk_18, ((Unk0210bf24 *) a)->mUnk_16)->mUnk_04 - 0x40);
                if (n > 0) {
                    if (n >= 0x7f) {
                        n = 0x7f;
                    }
                } else {
                    n = 0;
                }
            }
            func_0212c678((Unk0212c400 **) a, st.mUnk_14);
            func_0212c5f4((Unk0212c400 **) a, n);
            func_0212c4f4((Unk0212c400 **) a, data_0216cb20, st.mUnk_18);
            p->mUnk_30(p, a, &st);
        }
    }
    return 1;
}

Unk0210bf24 *func_0210c86c(Unk0210bfbc *a, u32 b, u32 c, u32 d, s16 e) {
    Unk0210bf24 *v;
    void *w;
    Unk02017328 *u;
    u32 f;

    v = 0;
    if (data_0217d084.mUnk_10 == 0) {
        return v;
    }
    if ((a->mUnk_34 & 1) == 0) {
        return v;
    }
    for (w = a->mUnk_0c.mUnk_00; w != 0; w = func_0201733c(&a->mUnk_0c, w)) {
        f = (((Unk0210bf24 *) w)->mUnk_16 == c) && (((Unk0210bf24 *) w)->mUnk_18 == b);
        if (f) {
            func_0210c450(a, (Unk0210bf24 *) w, 0);
            func_0210e328((Unk0210bf24 *) w);
            func_0210bce0(&((Unk0210bf24 *) w)->mUnk_08);
            ((Unk0210bf24 *) w)->mUnk_18 = 0;
            ((Unk0210bf24 *) w)->mUnk_16 = 0;
            ((Unk0210bf24 *) w)->mUnk_19 = 0;
            ((Unk0210bf24 *) w)->mUnk_14 = 0;
            ((Unk0210bf24 *) w)->mUnk_1a = 0x7f;
            v = (Unk0210bf24 *) w;
            break;
        }
    }
    if (v == 0) {
        v = (Unk0210bf24 *) func_0210e128((Unk0217c7c4 *) data_0217d034);
        func_0210c084(v, 0);
        u = v->mUnk_10;
        if (u != 0) {
            func_0210bc54(u, (u8 *) v);
            func_0210bfbc((Unk0210bfbc *) (u - 1));
        }
        func_0210cfe8((u32) v);
    }
    func_0210e328(v);
    func_0210bce0(&v->mUnk_08);
    v->mUnk_18 = 0;
    v->mUnk_16 = 0;
    v->mUnk_19 = 0;
    v->mUnk_14 = 0;
    v->mUnk_1a = 0x7f;
    v->mUnk_18 = b;
    v->mUnk_16 = c;
    v->mUnk_19 |= 2;
    v->mUnk_1a = d;
    v->mUnk_14 = e;
    func_0210bc8c((int) &a->mUnk_0c, (int) v);
    if (a->mUnk_18 != 0) {
        if (a->mUnk_18 != 3) {
            func_0210bc54((Unk02017328 *) (data_0217d048 + a->mUnk_18 * 0xc), (u8 *) a);
            a->mUnk_18 = 3;
        }
        func_0210bc8c((int) data_0217d048, (int) a);
        a->mUnk_18 = 0;
    }
    return v;
}

Unk0210bf24 *func_0210c610(Unk0210bfbc *a, u32 b, u32 c, u32 d, s16 e) {
    Unk0210bf24 *v;
    void *w;
    Unk02017328 *u;
    u32 f;

    v = 0;
    if (data_0217d084.mUnk_10 == 0) {
        return v;
    }
    if ((a->mUnk_34 & 1) == 0) {
        return v;
    }
    for (w = a->mUnk_0c.mUnk_00; w != 0; w = func_0201733c(&a->mUnk_0c, w)) {
        if (((Unk0210bf24 *) w)->mUnk_19 & 4) {
            f = (((Unk0210bf24 *) w)->mUnk_16 == c) && (((Unk0210bf24 *) w)->mUnk_18 == b);
            if (f) {
                if (((Unk0210bf24 *) w)->mUnk_00 != 0) {
                    ((Unk0210bf24 *) w)->mUnk_19 |= 8;
                    ((Unk0210bf24 *) w)->mUnk_1a = d;
                    ((Unk0210bf24 *) w)->mUnk_14 = e;
                    if (a->mUnk_18 == 3) {
                        func_0210bc8c((int) data_0217d054, (int) a);
                        a->mUnk_18 = 1;
                    }
                    return (Unk0210bf24 *) w;
                }
                func_0210c450(a, (Unk0210bf24 *) w, 0);
                func_0210e328((Unk0210bf24 *) w);
                func_0210bce0(&((Unk0210bf24 *) w)->mUnk_08);
                ((Unk0210bf24 *) w)->mUnk_18 = 0;
                ((Unk0210bf24 *) w)->mUnk_16 = 0;
                ((Unk0210bf24 *) w)->mUnk_19 = 0;
                ((Unk0210bf24 *) w)->mUnk_14 = 0;
                ((Unk0210bf24 *) w)->mUnk_1a = 0x7f;
                v = (Unk0210bf24 *) w;
                break;
            }
        }
    }
    if (v == 0) {
        v = (Unk0210bf24 *) func_0210e128((Unk0217c7c4 *) data_0217d034);
        func_0210c084(v, 0);
        u = v->mUnk_10;
        if (u != 0) {
            func_0210bc54(u, (u8 *) v);
            func_0210bfbc((Unk0210bfbc *) (u - 1));
        }
        func_0210cfe8((u32) v);
    }
    func_0210e328(v);
    func_0210bce0(&v->mUnk_08);
    v->mUnk_18 = 0;
    v->mUnk_16 = 0;
    v->mUnk_19 = 0;
    v->mUnk_14 = 0;
    v->mUnk_1a = 0x7f;
    v->mUnk_18 = b;
    v->mUnk_16 = c;
    v->mUnk_19 |= 2;
    v->mUnk_1a = d;
    v->mUnk_14 = e;
    v->mUnk_19 |= 4;
    v->mUnk_19 |= 8;
    func_0210bc8c((int) &a->mUnk_0c, (int) v);
    if (a->mUnk_18 != 0) {
        if (a->mUnk_18 != 3) {
            func_0210bc54((Unk02017328 *) (data_0217d048 + a->mUnk_18 * 0xc), (u8 *) a);
            a->mUnk_18 = 3;
        }
        func_0210bc8c((int) data_0217d048, (int) a);
        a->mUnk_18 = 0;
    }
    return v;
}

static inline u32 func_0210c558_inline(Unk0210bf24 *p, u32 b, u32 c) {
    return p->mUnk_16 == c && p->mUnk_18 == b;
}

void func_0210c558(Unk0210bfbc *a, u32 b, u32 c, u32 d) {
    void *v;
    u32 f;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    v = a->mUnk_0c.mUnk_00;
    while (v != 0) {
        f = (((Unk0210bf24 *) v)->mUnk_00 != 0) && func_0210c558_inline((Unk0210bf24 *) v, b, c);
        if (f) {
            func_0210c450(a, (Unk0210bf24 *) v, d);
            return;
        }
        v = func_0201733c(&a->mUnk_0c, v);
    }
}

void func_0210c450(Unk0210bfbc *p, Unk0210bf24 *b, u32 c) {
    void *a;
    void *n;
    u32 v;
    u32 f;

    func_0212c6f0((Unk0212c400 **) b, c);
    b->mUnk_19 &= ~4;
    b->mUnk_19 &= ~8;
    b->mUnk_19 &= ~2;
    func_0210bc54(&p->mUnk_0c, (u8 *) b);
    v = 3;
    for (a = p->mUnk_0c.mUnk_00; a != 0; a = func_0201733c(&p->mUnk_0c, a)) {
        f = ((Unk0210bf24 *) a)->mUnk_19;
        if (f & 2) {
            v = 0;
            break;
        }
        if (f & 8 || f & 1) {
            v = 1;
        }
    }
    if (p->mUnk_18 != v) {
        if (p->mUnk_18 != 3) {
            func_0210bc54((Unk02017328 *) (data_0217d048 + p->mUnk_18 * 0xc), (u8 *) p);
            p->mUnk_18 = 3;
        }
        if (v != 3) {
            func_0210bc8c((int) (data_0217d048 + v * 0xc), (int) p);
            p->mUnk_18 = v;
        }
    }
}

void func_0210c3a8(Unk0210bfbc *p) {
    void *a;

    for (a = p->mUnk_0c.mUnk_00; a != 0; a = p->mUnk_0c.mUnk_00) {
        func_0212c6f0((Unk0212c400 **) a, 0);
        ((Unk0210bf24 *) a)->mUnk_19 &= ~4;
        ((Unk0210bf24 *) a)->mUnk_19 &= ~8;
        ((Unk0210bf24 *) a)->mUnk_19 &= ~2;
        func_0210bc54(&p->mUnk_0c, (u8 *) a);
    }
    if (p->mUnk_18 != 3) {
        func_0210bc54((Unk02017328 *) (data_0217d048 + p->mUnk_18 * 0xc), (u8 *) p);
        p->mUnk_18 = 3;
    }
    func_0210c1b0(p);
}

void func_0210c238(Unk0210bfbc *p, u32 b) {
    void *a;
    void *c;
    u32 v;
    u8 f;

    v = 0;
    a = p->mUnk_0c.mUnk_00;
    while (a != 0) {
        if (((Unk0210bf24 *) a)->mUnk_19 & 4) {
            c = a;
            a = func_0201733c(&p->mUnk_0c, a);
            func_0212c6f0((Unk0212c400 **) c, b);
            ((Unk0210bf24 *) c)->mUnk_19 &= ~4;
            ((Unk0210bf24 *) c)->mUnk_19 &= ~8;
            ((Unk0210bf24 *) c)->mUnk_19 &= ~2;
            func_0210bc54(&p->mUnk_0c, (u8 *) c);
            v = 1;
            continue;
        }
        a = func_0201733c(&p->mUnk_0c, a);
    }
    if (v == 0) {
        return;
    }
    v = 3;
    for (a = p->mUnk_0c.mUnk_00; a != 0; a = func_0201733c(&p->mUnk_0c, a)) {
        f = ((Unk0210bf24 *) a)->mUnk_19;
        if (f & 2) {
            v = 0;
            break;
        }
        if (f & 8 || f & 1) {
            v = 1;
        }
    }
    if (p->mUnk_18 != v) {
        if (p->mUnk_18 != 3) {
            func_0210bc54((Unk02017328 *) (data_0217d048 + p->mUnk_18 * 0xc), (u8 *) p);
            p->mUnk_18 = 3;
        }
        if (v != 3) {
            func_0210bc8c((int) (data_0217d048 + v * 0xc), (int) p);
            p->mUnk_18 = v;
        }
    }
}

void func_0210c1b0(Unk0210bfbc *p) {
    void *a;

    func_0210c238(p, 0);
    for (a = p->mUnk_0c.mUnk_00; a != 0; a = p->mUnk_0c.mUnk_00) {
        func_0210bc54(&p->mUnk_0c, (u8 *) a);
    }
    if (p->mUnk_18 != 3) {
        func_0210bc54((Unk02017328 *) (data_0217d048 + p->mUnk_18 * 0xc), (u8 *) p);
        p->mUnk_18 = 3;
    }
    func_0210bc54(&data_0217d028, (u8 *) p);
    p->mUnk_38 = 0;
}
