#include "Main/Unknown/code_02032f94.h"
#include "00/code_0219bb50.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02033000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020a23a0.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02148ca0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02182fdc.h"
#include "01/code_021804e0.h"
#include "code_0201ea30.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_02032f94_inline(void *p, s32 n) {
    volatile u16 v = 0;
    func_0214cfe4(v, p, n);
}

static inline Unk0217aa1c_144_00 *func_02032f94_inline_2(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

static inline Unk0217aa1c_144 *func_02032f94_inline_3(void) {
    return &data_0217aa1c->mUnk_144[func_0205db28()];
}

void func_02032f94(void *a, s32 b, s32 c) {
    Unk02180774 *r;
    Unk02174e14_00 *s;
    Unk02174e14_00 *q;
    Unk02174e60 *p;
    Unk02174e60_00 *t;
    Unk0201ea30 *u;
    u32 n;
    s32 j;
    s32 k;
    s32 e;
    u16 i;
    u16 m;
    u16 w[11];
    Unk02125de0 v;
    s32 f[8];

    data_02174e60 = func_02036bec(a, 0x154);
    func_0214d05c_inline(data_02174e60, 0x154);
    data_02174e60->mUnk_0b8[0] = b;
    data_02174e60->mUnk_0b8[1] = c;
    data_02174e60->mUnk_0e0 = data_021759d0->mUnk_20;
    if (data_02174e60->mUnk_0e0 == 3) {
        func_02123a48(3);
    }
    func_02062860();
    r = func_02038d88(a, data_021547f0);
    func_02038d58(r->mUnk_28, 3, 0, 0, 0, 0xd, 2, 0);
    func_02038d28(r->mUnk_28, 0, 0, 0, 0, 0xc, 0, 0);
    func_02038d00(r->mUnk_28, 2, 0, 0, 0, 0x1e, 6);
    func_02038cd8(r->mUnk_28, 3, 0, 0, 0, 0x1d, 6);
    func_02038cd8(r->mUnk_70, 3, 0, 0, 0, 1, 6);
    func_02037abc(r);
    v.mUnk_00 = 0;
    v.mUnk_04 = 0;
    v.mUnk_08 = 0;
    v.mUnk_0c = 0;
    v.mUnk_10 = 0;
    v.mUnk_14 = 1;
    v.mUnk_18 = func_020b403c(2);
    v.mUnk_1c = 0;
    v.mUnk_20 = 0;
    v.mUnk_24 = 0;
    func_02125c2c();
    func_02125de0(a, &v);
    func_020629a4();
    data_02174e60->mUnk_0c8 = func_02047a28(data_0216416c);
    switch (data_02174e60->mUnk_0e0) {
        case 0:
            data_02174e60->mUnk_0d0 = 0;
            data_02174e60->mUnk_0d8 = data_021759c0->mUnk_3d0;
            data_02174e60->mUnk_150 = 2;
            break;
        case 1:
        case 2:
            func_0212775c(1, 0xf);
            data_02174e60->mUnk_0d0 =
                data_0217aa00->mUnk_1e52[(u16) (data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0)].mUnk_00;
            data_02174e60->mUnk_0d8 = data_021759c0->mUnk_3d0;
            data_02174e60->mUnk_150 = 0;
            break;
        case 3:
            data_02174e60->mUnk_0d0 = func_02122778(func_ov000_0219bb50());
            data_02174e60->mUnk_0d8 = data_0217d384->mUnk_1f52;
            data_02174e60->mUnk_148 = 1;
            data_02174e60->mUnk_14c = 0x384;
            data_02174e60->mUnk_150 = 2;
            break;
    }
    func_02033e6c();
    if (data_021759c0->mUnk_58 != 0) {
        j = 0;
        k = 0;
        switch (data_021759c0->mUnk_1c) {
            case 1:
                j = func_02032f94_inline_2(0)->mUnk_02;
                k = func_02032f94_inline_2(1)->mUnk_02;
                break;
            case 2:
                j = func_02032f94_inline_3()->mUnk_00[0].mUnk_00;
                k = func_02032f94_inline_3()->mUnk_00[1].mUnk_00;
                break;
        }
        if (j == k) {
            data_02174e60->mUnk_0d4 = data_02174e60->mUnk_0d8;
            data_02174e60->mUnk_0dc = 2;
        } else if (j > k) {
            data_02174e60->mUnk_0d4 = data_021759c0->mUnk_3d2[0];
            data_02174e60->mUnk_0dc = 3;
        } else if (k > j) {
            data_02174e60->mUnk_0d4 = data_021759c0->mUnk_3d2[1];
            data_02174e60->mUnk_0dc = 4;
        }
    } else if (func_02033e24() != 0) {
        data_02174e60->mUnk_0d4 = data_02174e60->mUnk_0d8;
        data_02174e60->mUnk_0dc = 2;
    } else if (data_02174e60->mUnk_0e4[data_02174e60->mUnk_0d0].mUnk_00 == 0) {
        data_02174e60->mUnk_0dc = 0;
    } else {
        data_02174e60->mUnk_0dc = 1;
    }
    func_02025b84(1, &data_02174e60->mUnk_048[2]);
    func_02025b84(0, &data_02174e60->mUnk_048[3]);
    data_02174e60->mUnk_0c0 = func_020b4024(1);
    data_02174e60->mUnk_0c4 = func_020b4024(0);
    t = &data_02174e60->mUnk_000[0];
    func_02025884(t, data_02153f80[data_02174e60->mUnk_0dc][0], data_02153f84[data_02174e60->mUnk_0dc][0],
                  data_02153f8c[data_02174e60->mUnk_0dc][0], 3, func_0204799c);
    func_020b4810(&t->mUnk_14[2], func_0204799c(data_02153f88[data_02174e60->mUnk_0dc][0]));
    func_0214b88c(t->mUnk_00[3]->mUnk_14, 0, t->mUnk_00[3]->mUnk_10);
    func_0214c160(t->mUnk_10->mUnk_0c, 0, 0x140);
    func_0214bc9c(t->mUnk_14[2]->mUnk_0c, 0, t->mUnk_14[2]->mUnk_08);
    func_0214bbcc(t->mUnk_14[3]->mUnk_0c, 0, t->mUnk_14[3]->mUnk_08);
    s = &data_02174e60->mUnk_048[0];
    func_02025abc(s, data_02153f90[data_02174e60->mUnk_0dc][0], data_02153f94[data_02174e60->mUnk_0dc][0],
                  data_02153f98[data_02174e60->mUnk_0dc][0], data_02153f9c[data_02174e60->mUnk_0dc][0],
                  data_02153fa0[data_02174e60->mUnk_0dc][0], 0, func_0204799c);
    func_02025a50(0, a, s);
    switch (data_02174e60->mUnk_0dc) {
        case 0:
            func_02033a0c(a);
            break;
        case 1:
            func_020338f8(a);
            break;
        case 2:
            func_02033840(a);
            break;
        case 3:
        case 4:
            func_020336ec(a);
            break;
    }
    u = s->mUnk_0c;
    for (i = 0; i < u->mUnk_06; i++) {
        func_0201ea30(s->mUnk_0c, i);
    }
    t = &data_02174e60->mUnk_000[1];
    func_02025884(t, data_02164178, data_02164190, data_021641a8, 3, func_0204799c);
    func_0214b824(t->mUnk_00[3]->mUnk_14, 0, t->mUnk_00[3]->mUnk_10);
    func_0214c0f8(t->mUnk_10->mUnk_0c, 0, 0x140);
    func_0214bb64(t->mUnk_14[3]->mUnk_0c, 0, t->mUnk_14[3]->mUnk_08);
    n = func_02148ca0();
    p = data_02174e60;
    q = &p->mUnk_048[1];
    func_02025abc(q, data_021641c4, data_021641e0, data_021641fc, data_02164214, data_0216422c, 0, func_0204799c);
    func_02124ed0(a, q->mUnk_0c, q->mUnk_14, &q->mUnk_18);
    func_0214bea4(((Unk020b4934 *) p->mUnk_048[1].mUnk_00)->mUnk_14, 0,
                  ((Unk020b4934 *) p->mUnk_048[1].mUnk_00)->mUnk_10);
    func_0214c028(((Unk020b4a44 *) q->mUnk_04)->mUnk_0c, 0, ((Unk020b4a44 *) q->mUnk_04)->mUnk_08);
    for (i = 0; i < q->mUnk_14->mUnk_06; i++) {
        n -= func_02025a00(1, a, q, data_02153f00[i], n);
    }
    for (i = 0; i < q->mUnk_0c->mUnk_06; i++) {
        func_021249a8(i, 2, q->mUnk_08, q->mUnk_0c);
    }
    for (i = 0; i < 8; i++) {
        f[i] = 0;
    }
    for (m = 0; m < 8; m++) {
        e = data_02174e60->mUnk_0e4[m].mUnk_08;
        k = data_021759c0->mUnk_68[m].mUnk_08.mUnk_00;
        if ((k == 0 || k == 1 || k == 3) && (data_02174e60->mUnk_0e0 != 3 || data_02174e60->mUnk_0e4[m].mUnk_04 != 0)) {
            func_02033ab8(1, m, e + 0x30, 1);
            func_02032f94_inline(w, 0x16);
            func_020adff0(m, w, 0);
            func_0212426c(1, e, q->mUnk_14, w, q->mUnk_0c, q->mUnk_18);
            func_02033b80(m);
            func_02033c80(m);
            f[e] = 1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (f[i] == 0) {
            q->mUnk_18[i + 0x48].mUnk_00 = 0;
            q->mUnk_18[i + 0x30].mUnk_00 = q->mUnk_18[i + 0x48].mUnk_00;
            q->mUnk_18[i + 0x38].mUnk_00 = q->mUnk_18[i + 0x30].mUnk_00;
            q->mUnk_18[i + 0x28].mUnk_00 = q->mUnk_18[i + 0x38].mUnk_00;
            q->mUnk_18[i + 0x20].mUnk_00 = q->mUnk_18[i + 0x28].mUnk_00;
            q->mUnk_18[i + 0x18].mUnk_00 = q->mUnk_18[i + 0x20].mUnk_00;
            q->mUnk_18[i + 0x10].mUnk_00 = q->mUnk_18[i + 0x18].mUnk_00;
            q->mUnk_18[i + 0x08].mUnk_00 = q->mUnk_18[i + 0x10].mUnk_00;
            q->mUnk_18[i].mUnk_00 = q->mUnk_18[i + 0x08].mUnk_00;
        }
    }
    switch (data_02174e60->mUnk_0dc) {
        case 3:
            if (data_021759c0->mUnk_68[(u16) data_02174e60->mUnk_0d0].mUnk_08.mUnk_04 == 0) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 4:
            if (data_021759c0->mUnk_68[(u16) data_02174e60->mUnk_0d0].mUnk_08.mUnk_04 == 1) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 0:
            k = 0;
            break;
        default:
            k = 7;
            break;
    }
    func_020a269c(8, (u16) k);
}
