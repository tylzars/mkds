#include "Main/Unknown/code_0210bcf4.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210bc14.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0212c668.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "code_0212c478.h"
#include "code_0212c6ac.h"
#include "code_0212d254.h"

void func_0210c0bc(Unk0210bfbc *p) {
    void *a;

    func_0210c238(p, 0);
    for (a = p->mUnk_0c.mUnk_00; a != 0; a = p->mUnk_0c.mUnk_00) {
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
    for (a = p->mUnk_0c.mUnk_00; a != 0; a = func_0201733c(&p->mUnk_0c, a)) {
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
            func_0210bc8c((int) &data_0217d048[v], (int) p);
            p->mUnk_18 = v;
        }
    }
}

void func_0210bf24(u32 a, u32 b, u32 c, u32 d) {
    Unk0210bf24 *v;
    Unk02017328 *w;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    v = func_0210e128((Unk0217c7c4 *) data_0217d034);
    func_0210c084(v, 0);
    w = v->mUnk_10;
    if (w != 0) {
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
    if (((Unk0210bf24 *) d)->mUnk_00 == 0) {
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
    st.mUnk_00 = 0;
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
        st.mUnk_10 = (*(u32(*)(void *)) * (u32 *) data_0217d018)(&st);
        st.mUnk_1c = st.mUnk_14 = (*(u32(*)(void *)) * (u32 *) data_0217d014)(&st);
        st.mUnk_18 = (*(u32(*)(void *)) * (u32 *) data_0217d01c)(&st);
    }
    if (st.mUnk_14 <= 0) {
        if (((Unk0210bf24 *) d)->mUnk_00 == 0) {
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
