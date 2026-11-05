#include "Main/Unknown/code_0210c1b0.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0210bce0.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"

#pragma opt_loop_invariants off

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
    a = p->mUnk_0c.mHead;
    while (a != NULL) {
        f = (a->mUnk_19 & 8) != 0;
        a->mUnk_19 &= ~8;
        if (a->mUnk_00 != NULL) {
            if (a->mUnk_19 & 4) {
                if (f == 0) {
                    v = (u32) a;
                    a = ListGetNext(&p->mUnk_0c, a);
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
                    func_0210bc8c((s32) data_0217d054, (s32) p);
                    p->mUnk_18 = 1;
                }
            }
        } else if ((a->mUnk_19 & 2) == 0) {
            v = (u32) a;
            a = ListGetNext(&p->mUnk_0c, a);
            func_0212c6f0((Unk0212c400 **) v, 0);
            ((Unk0210bf24 *) v)->mUnk_19 &= ~4;
            ((Unk0210bf24 *) v)->mUnk_19 &= ~8;
            ((Unk0210bf24 *) v)->mUnk_19 &= ~2;
            func_0210bc54(&p->mUnk_0c, (u8 *) v);
            v = 1;
            continue;
        }
        a = ListGetNext(&p->mUnk_0c, a);
    }
    if (v == 0) {
        return;
    }
    v = 3;
    for (a = p->mUnk_0c.mHead; a != NULL; a = ListGetNext(&p->mUnk_0c, a)) {
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
            func_0210bc54(&data_0217d048[p->mUnk_18], (u8 *) p);
            p->mUnk_18 = 3;
        }
        if (v != 3) {
            func_0210bc8c((s32) &data_0217d048[v], (s32) p);
            p->mUnk_18 = v;
        }
    }
}

static inline s32 func_0210ca4c_inline(u32 k, u8 a, u16 b) {
    s32 n = k + (func_0212d580(a, b)->mUnk_04 - 0x40);
    if (n > 0) {
        if (n >= 0x7f) {
            n = 0x7f;
        }
        return n;
    }
    return 0;
}

u32 func_0210ca4c(Unk0210bfbc *p) {
    Unk0210bcf4 st;
    s32 n;
    Unk0210bf24 *a;

    n = p->mUnk_28;
    st.mUnk_00 = p;
    st.mUnk_04 = n;
    st.mUnk_20 = NULL;
    st.mUnk_14 = 0;
    st.mUnk_1c = 0;
    st.mUnk_18 = 0;
    if (st.mUnk_04 == 0) {
        st.mUnk_10 = 0;
        st.mUnk_14 = 0x7f;
        st.mUnk_1c = 0x7f;
        st.mUnk_18 = 0;
    } else {
        st.mUnk_10 = data_0217d018(&st);
        st.mUnk_1c = st.mUnk_14 = data_0217d014(&st);
        st.mUnk_18 = data_0217d01c(&st);
    }
    if (st.mUnk_14 <= 0) {
        func_0210c0bc(p);
        return 0;
    }
    for (a = p->mUnk_0c.mHead; a != NULL; a = ListGetNext(&p->mUnk_0c, a)) {
        n = -1;
        if (a->mUnk_19 & 2) {
            n = func_0210ca4c_inline(st.mUnk_1c, a->mUnk_18, a->mUnk_16);
            p->mUnk_2c(p, a, n);
            a->mUnk_19 &= ~2;
        }
        if (a->mUnk_00 != NULL) {
            if (n == -1) {
                n = func_0210ca4c_inline(st.mUnk_1c, a->mUnk_18, a->mUnk_16);
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
    Unk0210bf24 *w;
    LinkedList *u;
    u32 f;

    v = NULL;
    if (data_0217d084.mUnk_10 == 0) {
        return v;
    }
    if ((a->mUnk_34 & 1) == 0) {
        return v;
    }
    for (w = a->mUnk_0c.mHead; w != NULL; w = ListGetNext(&a->mUnk_0c, w)) {
        f = (w->mUnk_16 == c) && (w->mUnk_18 == b);
        if (f) {
            func_0210c450(a, w, 0);
            func_0210e328(w);
            func_0210bce0(&w->mUnk_08);
            w->mUnk_18 = 0;
            w->mUnk_16 = 0;
            w->mUnk_19 = 0;
            w->mUnk_14 = 0;
            w->mUnk_1a = 0x7f;
            v = w;
            break;
        }
    }
    if (v == NULL) {
        v = func_0210e128((Unk0217c7c4 *) data_0217d034);
        func_0210c084(v, 0);
        u = v->mUnk_10;
        if (u != NULL) {
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
    func_0210bc8c((s32) &a->mUnk_0c, (s32) v);
    if (a->mUnk_18 != 0) {
        if (a->mUnk_18 != 3) {
            func_0210bc54(&data_0217d048[a->mUnk_18], (u8 *) a);
            a->mUnk_18 = 3;
        }
        func_0210bc8c((s32) data_0217d048, (s32) a);
        a->mUnk_18 = 0;
    }
    return v;
}

Unk0210bf24 *func_0210c610(Unk0210bfbc *a, u32 b, u32 c, u32 d, s16 e) {
    Unk0210bf24 *v;
    Unk0210bf24 *w;
    LinkedList *u;
    u32 f;

    v = NULL;
    if (data_0217d084.mUnk_10 == 0) {
        return v;
    }
    if ((a->mUnk_34 & 1) == 0) {
        return v;
    }
    for (w = a->mUnk_0c.mHead; w != NULL; w = ListGetNext(&a->mUnk_0c, w)) {
        if (w->mUnk_19 & 4) {
            f = (w->mUnk_16 == c) && (w->mUnk_18 == b);
            if (f) {
                if (w->mUnk_00 != NULL) {
                    w->mUnk_19 |= 8;
                    w->mUnk_1a = d;
                    w->mUnk_14 = e;
                    if (a->mUnk_18 == 3) {
                        func_0210bc8c((s32) data_0217d054, (s32) a);
                        a->mUnk_18 = 1;
                    }
                    return w;
                }
                func_0210c450(a, w, 0);
                func_0210e328(w);
                func_0210bce0(&w->mUnk_08);
                w->mUnk_18 = 0;
                w->mUnk_16 = 0;
                w->mUnk_19 = 0;
                w->mUnk_14 = 0;
                w->mUnk_1a = 0x7f;
                v = w;
                break;
            }
        }
    }
    if (v == NULL) {
        v = func_0210e128((Unk0217c7c4 *) data_0217d034);
        func_0210c084(v, 0);
        u = v->mUnk_10;
        if (u != NULL) {
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
    func_0210bc8c((s32) &a->mUnk_0c, (s32) v);
    if (a->mUnk_18 != 0) {
        if (a->mUnk_18 != 3) {
            func_0210bc54(&data_0217d048[a->mUnk_18], (u8 *) a);
            a->mUnk_18 = 3;
        }
        func_0210bc8c((s32) data_0217d048, (s32) a);
        a->mUnk_18 = 0;
    }
    return v;
}

static inline u32 func_0210c558_inline(Unk0210bf24 *p, u32 b, u32 c) {
    return p->mUnk_16 == c && p->mUnk_18 == b;
}

void func_0210c558(Unk0210bfbc *a, u32 b, u32 c, u32 d) {
    Unk0210bf24 *v;
    u32 f;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    v = a->mUnk_0c.mHead;
    while (v != NULL) {
        f = (v->mUnk_00 != NULL) && func_0210c558_inline(v, b, c);
        if (f) {
            func_0210c450(a, v, d);
            return;
        }
        v = ListGetNext(&a->mUnk_0c, v);
    }
}

void func_0210c450(Unk0210bfbc *p, Unk0210bf24 *b, u32 c) {
    Unk0210bf24 *a;
    void *n;
    u32 v;
    u32 f;

    func_0212c6f0((Unk0212c400 **) b, c);
    b->mUnk_19 &= ~4;
    b->mUnk_19 &= ~8;
    b->mUnk_19 &= ~2;
    func_0210bc54(&p->mUnk_0c, (u8 *) b);
    v = 3;
    for (a = p->mUnk_0c.mHead; a != NULL; a = ListGetNext(&p->mUnk_0c, a)) {
        f = a->mUnk_19;
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
            func_0210bc54(&data_0217d048[p->mUnk_18], (u8 *) p);
            p->mUnk_18 = 3;
        }
        if (v != 3) {
            func_0210bc8c((s32) &data_0217d048[v], (s32) p);
            p->mUnk_18 = v;
        }
    }
}

void func_0210c3a8(Unk0210bfbc *p) {
    Unk0210bf24 *a;

    for (a = p->mUnk_0c.mHead; a != NULL; a = p->mUnk_0c.mHead) {
        func_0212c6f0((Unk0212c400 **) a, 0);
        a->mUnk_19 &= ~4;
        a->mUnk_19 &= ~8;
        a->mUnk_19 &= ~2;
        func_0210bc54(&p->mUnk_0c, (u8 *) a);
    }
    if (p->mUnk_18 != 3) {
        func_0210bc54(&data_0217d048[p->mUnk_18], (u8 *) p);
        p->mUnk_18 = 3;
    }
    func_0210c1b0(p);
}

void func_0210c238(Unk0210bfbc *p, u32 b) {
    Unk0210bf24 *a;
    Unk0210bf24 *c;
    u32 v;
    u8 f;

    v = 0;
    a = p->mUnk_0c.mHead;
    while (a != NULL) {
        if (a->mUnk_19 & 4) {
            c = a;
            a = ListGetNext(&p->mUnk_0c, a);
            func_0212c6f0((Unk0212c400 **) c, b);
            c->mUnk_19 &= ~4;
            c->mUnk_19 &= ~8;
            c->mUnk_19 &= ~2;
            func_0210bc54(&p->mUnk_0c, (u8 *) c);
            v = 1;
            continue;
        }
        a = ListGetNext(&p->mUnk_0c, a);
    }
    if (v == 0) {
        return;
    }
    v = 3;
    for (a = p->mUnk_0c.mHead; a != NULL; a = ListGetNext(&p->mUnk_0c, a)) {
        f = a->mUnk_19;
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
            func_0210bc54(&data_0217d048[p->mUnk_18], (u8 *) p);
            p->mUnk_18 = 3;
        }
        if (v != 3) {
            func_0210bc8c((s32) &data_0217d048[v], (s32) p);
            p->mUnk_18 = v;
        }
    }
}

void func_0210c1b0(Unk0210bfbc *p) {
    void *a;

    func_0210c238(p, 0);
    for (a = p->mUnk_0c.mHead; a != NULL; a = p->mUnk_0c.mHead) {
        func_0210bc54(&p->mUnk_0c, (u8 *) a);
    }
    if (p->mUnk_18 != 3) {
        func_0210bc54(&data_0217d048[p->mUnk_18], (u8 *) p);
        p->mUnk_18 = 3;
    }
    func_0210bc54(&data_0217d028, (u8 *) p);
    p->mUnk_38 = 0;
}
