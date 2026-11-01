#include "Main/Unknown/code_020708a4.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212c6ac.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

static inline s32 func_020708a4_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return func_02039860(v, n);
}

void func_020708a4(Unk0206bcb0 *p) {
    Unk0206ceb4 *s;
    u16 i;
    s32 d;
    s32 k;
    s32 t;
    u32 w;
    Vec3 a;
    Vec3 b;
    Vec3 n;
    Vec3 c;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 h;
    Vec3 l;
    Unk02012f58 m2;
    s32 m1[9];
    Vec3 q;

    b = data_02154f94;
    i = *data_02175620->mUnk_fc;
    a.x = data_02175620->mUnk_34[i].mUnk_00.x;
    a.y = data_02175620->mUnk_34[i].mUnk_00.y;
    a.z = data_02175620->mUnk_34[i].mUnk_00.z;
    b.x = data_02175620->mUnk_34[*data_02175620->mUnk_fc].mUnk_0c.x;
    b.y = data_02175620->mUnk_34[*data_02175620->mUnk_fc].mUnk_0c.y;
    b.z = data_02175620->mUnk_34[*data_02175620->mUnk_fc].mUnk_0c.z;
    k = (u16) (((s64) b.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    func_02146d44(m1, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
    func_02146d78(&data_02154f70, m1, &e);
    func_021035ac(p->mUnk_74);

    w = p->mUnk_4c;
    if (!(w & 0x20000) && (w & 0x8000000)) {
        s = &p->mUnk_538;
        if (s->mUnk_1c <= 0x190) {
            s->mUnk_1c = 0x190;
            p->mUnk_4c |= 0x20000;
            func_02079f70(p->mUnk_590, func_0207a134(), func_0207a11c(), func_0207a104());
        }
    }
    if (p->mUnk_4c & 0x8000000) {
        func_02069134(p);
    }
    w = p->mUnk_4c;
    if (w & 0x10000000) {
        func_0206938c(p);
    } else {
        if (w & 0x80) {
            func_0206a354(p);
        }
        if (p->mUnk_4c & 0x10000) {
            func_02069f6c(p);
        }
        if (p->mUnk_7c & 0x402000) {
            func_0206988c(p);
        }
    }

    if (p->mUnk_4c & 0x2000) {
        s = &p->mUnk_538;
        if (p->mUnk_7c & 1) {
            func_0210ddf4(&data_0217d26c, func_02086080(p->mUnk_74), func_020718c8, p, 0xa3);
        }
        s->mUnk_0a++;
        if (s->mUnk_0a > 0xb4 && (p->mUnk_4c & 0x2000)) {
            p->mUnk_4c &= ~0x2000;
            p->mUnk_d8 = 0x1000;
            if (!(p->mUnk_4c & 0x8000000)) {
                func_0207b0d0(p);
            }
            func_02080ee4(p);
        }
    }

    if (p->mUnk_4c & 0x40) {
        s = &p->mUnk_538;
        func_0208181c(p->mUnk_74);
        if ((p->mUnk_7c & 0x10) && p->mUnk_590->mUnk_008->mUnk_1a == 0) {
            func_02068a64(p, 2, 1);
        }
        s->mUnk_06++;
        if (s->mUnk_06 > 0x1c2) {
            p->mUnk_4c &= ~0x40;
            func_0207b1a8(p);
            p->mUnk_29c = 0;
            func_020817b8(p->mUnk_74);
            func_02068a64(p, 0, 1);
            if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
                func_02106dc8();
            }
            if (p->mUnk_4c & 0x2000) {
                func_0207b13c(p);
            }
        }
    }

    data_0217566a[p->mUnk_78].mUnk_00 = 0xe04;
    func_020397a8(&data_02154f7c, &e, &f);
    func_021484d0(&p->mUnk_80, &a, &g);
    g.y = 0;
    func_02147fd8(func_02039828(&f, &g), &f, &a, &a);
    func_02039828(&f, &g);
    func_021484d0(&a, &p->mUnk_80, &c);
    d = func_020708a4_inline(&c, &c);

    if (func_02039828(&c, &e) <= 0) {
        func_02055c5c();
        p->mUnk_48 &= ~0x10000;
        func_01ffa11c(p, &p->mUnk_244);
        p->mUnk_48 &= ~0x40000;
        p->mUnk_3e8 = (s16) ((s32) (((s64) b.x * 0x4000) >> 12) >> 12) + 0x32;
        if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00 == 0x13) {
            func_0212c6f0(func_02108e6c(7), 0x14);
        }
    } else {
        if (d > 0x64000) {
            p->mUnk_50 = c;
        }
        h = p->mUnk_50;
        h.y = 0;
        p->mUnk_3a8 = 0x1000;
        func_020708a4_inline(&h, &h);
        p->mUnk_236 = (s32) (((s64) func_02148538(h.x, h.z) * 0x28be60d) >> 12) >> 12;
        q = data_02165524;
        func_01ffd190(&q, p->mUnk_236, (Vec4 *) &p->mUnk_e0);
        func_020397a8(&data_02154f7c, &p->mUnk_50, &l);
        func_020397a8(&p->mUnk_50, &l, &n);
        if (p->mUnk_234 > -5000) {
            p->mUnk_234 -= 300;
            if (p->mUnk_234 < -5000) {
                p->mUnk_234 = -5000;
            }
        }
        func_02146f98(&m2, &p->mUnk_120, data_0215d4b4[((u16) p->mUnk_234 >> 4) * 2],
                      data_0215d4b4[((u16) p->mUnk_234 >> 4) * 2 + 1]);
        func_02146d78(&n, &m2.mUnk_00.x, &n);
        p->mUnk_244 = n;
        func_01ff9f60(p, &n);
    }

    p->mUnk_2a8 = 0x1e000;
    t = p->mUnk_2a8;
    m2.mUnk_24.x = ((s64) p->mUnk_50.x * t) >> 12;
    m2.mUnk_24.y = ((s64) p->mUnk_50.y * t) >> 12;
    m2.mUnk_24.z = ((s64) p->mUnk_50.z * t) >> 12;
    p->mUnk_68 = p->mUnk_50;
    if (d < 0x3e8000) {
        t = (s32) (((s64) d * 0x29) >> 12) + 0x14000;
        if (p->mUnk_2a8 > t) {
            p->mUnk_2a8 = t;
        }
    }
    p->mUnk_a4 = m2.mUnk_24;
    func_02148504(&p->mUnk_80, &p->mUnk_a4, &p->mUnk_80);
}
