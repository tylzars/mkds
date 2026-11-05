#include "Main/Unknown/code_0210bcf4.h"
#include "code_0212d214.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210bce0.h"
#include "Main/Unknown/code_0210d078.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "code_0201750c.h"

void func_0210c134(Unk0210bfbc *a, u32 b) {
    void *v1;
    void *v2;
    ListInit(&a->mUnk_0c, 8);
    v1 = (void *) func_0210d0b4;
    a->mUnk_38 = 1;
    v2 = (void *) func_0210d078;
    a->mUnk_2c = v1;
    a->mUnk_30 = v2;
    a->mUnk_34 = 0;
    a->mUnk_28 = b;
    a->mUnk_18 = 3;
    func_0210bce0((u32 *) a->mUnk_1c);
    func_0210bce0((u32 *) a);
    func_0210bc8c((int) &data_0217d028, (int) a);
}

void func_0210c0bc(Unk0210bfbc *p) {
    void *a;

    func_0210c238(p, 0);
    for (a = p->mUnk_0c.mHead; a != NULL; a = p->mUnk_0c.mHead) {
        func_0210bc54(&p->mUnk_0c, (u8 *) a);
    }
    if (p->mUnk_18 != 3) {
        func_0210bc54(&data_0217d048[p->mUnk_18], (u8 *) p);
        p->mUnk_18 = 3;
    }
}

void func_0210c084(Unk0210bf24 *p, u32 b) {
    func_0212c6f0((Unk0212c400 **) p, b);
    p->mUnk_19 &= ~4;
    p->mUnk_19 &= ~8;
    p->mUnk_19 &= ~2;
}

void func_0210bfbc(Unk0210bfbc *p) {
    Unk0210bf24 *a;
    u32 v;
    u8 f;

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

void func_0210bf24(u32 a, u32 b, u32 c, u32 d) {
    Unk0210bf24 *v;
    LinkedList *w;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    v = func_0210e128((Unk0217c7c4 *) data_0217d034);
    func_0210c084(v, 0);
    w = v->mUnk_10;
    if (w != NULL) {
        func_0210bc54(w, (u8 *) v);
        func_0210bfbc((Unk0210bfbc *) (w - 1));
    }
    func_0210cfe8((u32) v);
    func_0210bcf4(a, b, c, (u32) v, d);
}

u32 func_0210bee8(u32 a, u32 b, u32 c, u32 d, u32 e) {
    if (data_0217d084.mUnk_10 == 0) {
        return a;
    }
    return func_0210bcf4(a, b, c, d, e);
}

u32 func_0210bcf4(u32 a, u32 b, u32 c, u32 d, u32 e) {
    Unk0210bcf4 st;
    u32 v;
    u32 ok;
    u32 t;
    s32 n;
    s32 k;

    v = 0;
    ok = v;
    if (data_0217d084.mUnk_04 == 4) {
        return v;
    }
    if (data_0217d084.mUnk_04 == 0) {
        return v;
    }
    if (((Unk0210bf24 *) d)->mUnk_00 == NULL) {
        v = 1;
        ok = v;
    } else {
        t = data_0217d024[0];
        data_0217d024[0] = t + 1;
        if ((t & 3) == data_0217d010[0]) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return ok;
    }
    st.mUnk_00 = NULL;
    st.mUnk_04 = c;
    st.mUnk_20 = (Unk0210bcf4_20 *) e;
    st.mUnk_14 = 0;
    st.mUnk_1c = 0;
    st.mUnk_18 = 0;
    if (c == 0) {
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
        if (((Unk0210bf24 *) d)->mUnk_00 == NULL) {
            return (u32) ((Unk0210bf24 *) d)->mUnk_00;
        }
        return func_0212c6f0((Unk0212c400 **) d, 0);
    }
    k = st.mUnk_1c;
    n = k + (func_0212d580(a, b)->mUnk_04 - 0x40);
    if (n > 0) {
        if (n >= 0x7f) {
            n = 0x7f;
        }
    } else {
        n = 0;
    }
    if (v != 0) {
        data_0216cb1c[0]((void *) d, a, b, n);
    }
    func_0212c678((Unk0212c400 **) d, st.mUnk_14);
    func_0212c5f4((Unk0212c400 **) d, n);
    return func_0212c4f4((Unk0212c400 **) d, data_0216cb20, st.mUnk_18);
}
