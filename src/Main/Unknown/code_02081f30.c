#include "Main/Unknown/code_02081f30.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02074874.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "code_02147cd8.h"

void func_02082aec(void) {
    s32 x;
    s32 m;

    m = data_021759c0->mUnk_010;
    x = 0x1000;
    switch (m) {
        case 1:
            x = 0xd9a;
            break;
        case 0:
            x = 0xb33;
            break;
    }
    data_0217ae9c = func_02147f34(0x1000, (s32) (((s64) x * 0x779a + 0x800) >> 12));
    data_0217ae88 = 0;
    data_0217ae78 = 0;
    switch (data_021759c0->mUnk_00) {
        case 0x25: {
            Unk0201ca6c *p;

            if (data_021759c0->mUnk_00c == 0) {
                p = func_0208b7bc(0x24, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_02082750;
                p = func_0208b7bc(0x27, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_02082a10;
            } else if (func_02062ec4() != 0) {
                p = func_0208b7bc(0x3d, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020824d0;
                p = func_0208b7bc(0x3f, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_0208266c;
            } else {
                p = func_0208b7bc(0x3c, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020824d0;
                p = func_0208b7bc(0x3f, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_0208266c;
            }
            break;
        }
        case 0x10: {
            Unk0201ca6c *p;

            if (func_02062ec4() != 0) {
                p = func_0208b7bc(0x3e, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_02082034;
            } else if (data_021759c0->mUnk_00c == 0) {
                p = func_0208b7bc(0x29, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020821cc;
                p = func_0208b7bc(0x25, &data_02155a14);
                data_0217ae88 = p;
                p->mUnk_90 = func_02082368;
            } else {
                p = func_0208b7bc(0x29, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_02082034;
            }
            break;
        }
    }
}

void func_02082a10(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;

    if (a != 0) {
        return;
    }
    g = (Unk020748a8 *) func_020748a8();
    v = g->mUnk_15c;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    func_02147fd8(0x5800, &v, &g->mUnk_9c, &u);
    u.y = 0x1f400;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082750(Unk0201ca6c *p, s32 a) {
    Unk02148038 h;
    Vec3 v;
    Vec3 x;
    Vec3 u;
    Unk02146dfc m;
    Vec3 y;
    Unk020748a8 *g;
    Unk0206bcb0 *q;
    s32 t;
    s32 k;
    s32 s;
    u16 i;

    if (a != 0) {
        return;
    }
    g = (Unk020748a8 *) func_020748a8();
    q = func_0207a974(data_021759c0->mUnk_62);
    v = g->mUnk_15c;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    func_021483a0(&data_02155a08, &v, &x);
    t = (s32) (((s64) q->mUnk_2a4 * data_0217ae9c + 0x800) >> 12);
    y = data_02165984;
    k = 0;
    if (t > 0x1000) {
        t = 0x1000;
    }
    if (q->mUnk_44 & 0x100) {
        t = t * 0xffffffff;
        k = data_02165938;
    }
    i = (s32) (((s64) t * 0x38e3 + 0x800) >> 12);
    func_02146f98((Unk02012f58 *) &m, &x, data_0215d4b4[(i >> 4) * 2], data_0215d4b4[(i >> 4) * 2 + 1]);
    func_02146d78(&y, m.mUnk_00, &y);
    h.mUnk_00 = y.x;
    h.mUnk_02 = y.y;
    h.mUnk_04 = y.z;
    p->mUnk_68 = (s16) ((s32) (((s64) (0x1000 - t) * 0x800 + 0x800) >> 12) + 0x800);
    p->mUnk_50 = h;
    s = data_02165954 + k;
    func_02147fd8(data_02165938 + (s32) (((s64) s * (s64) t + 0x800) >> 12), &v, &g->mUnk_9c, &u);
    u.y = func_0207a974(data_021759c0->mUnk_62)->mUnk_508->y >> 4;
    u.y = u.y - (s32) (((s64) data_02165934 * t + 0x800) >> 12);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_0208266c(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk02061808 *g;

    if (a != 0) {
        return;
    }
    g = func_02061808();
    v = g->mUnk_15c;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    func_02147fd8(data_02165958, &v, &g->mUnk_09c, &u);
    u.y = 0x1f400;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_020824d0(Unk0201ca6c *p, s32 a) {
    Unk02148038 h;
    Vec3 v;
    Vec3 x;
    Vec3 u;
    Vec3 w;
    Unk02061808 *g;

    if (a != 0) {
        return;
    }
    g = func_02061808();
    func_0207a974(data_021759c0->mUnk_62);
    v = g->mUnk_15c;
    w = data_02155a08;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    func_021483a0(&data_02155a08, &v, &x);
    w.y = w.y * 0xffffffff;
    h.mUnk_00 = w.x;
    h.mUnk_02 = w.y;
    h.mUnk_04 = w.z;
    p->mUnk_68 = 0x1000;
    p->mUnk_50 = h;
    func_02147fd8(data_02165964, &v, &g->mUnk_09c, &u);
    u.y = u.y + (data_02165968 + (s32) (((s64) g->mUnk_15c.y * data_02165960 + 0x800) >> 12));
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_02082368(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;
    Unk0206bcb0 *q;
    s32 t;

    if (a != 0) {
        return;
    }
    g = (Unk020748a8 *) func_020748a8();
    q = func_0207a974(data_021759c0->mUnk_62);
    v = g->mUnk_15c;
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    func_02147fd8(0x5800, &v, &g->mUnk_9c, &u);
    u.y = func_0207a974(data_021759c0->mUnk_62)->mUnk_508->y >> 4;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    t = (s32) (((s64) q->mUnk_2a4 * data_0217ae9c + 0x800) >> 12);
    if (t > 0x1000) {
        t = 0x1000;
    }
    p->mUnk_58 = (s32) (((s64) (0x1000 - t) * 0x400 + 0x800) >> 12);
}

void func_020821cc(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Unk020748a8 *g;
    s32 k;
    Unk0206bcb0 *q;
    s32 t;

    if (a != 0) {
        return;
    }
    g = (Unk020748a8 *) func_020748a8();
    q = func_0207a974(data_021759c0->mUnk_62);
    v = g->mUnk_15c;
    t = (s32) (((s64) q->mUnk_2a4 * data_0217ae9c + 0x800) >> 12);
    k = 0;
    v.y = 0;
    if (t > 0x1000) {
        t = 0x1000;
    }
    if (q->mUnk_44 & 0x100) {
        k = -0x5800;
    }
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    k = k * 3;
    func_02147fd8((s32) (((s64) k * (s64) t + 0x800) >> 12) + 0x5800, &v, &g->mUnk_9c, &u);
    u.y = func_0207a974(data_021759c0->mUnk_62)->mUnk_508->y >> 4;
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_58 = (s32) (((s64) 0x800 * t + 0x800) >> 12);
}

void func_02082034(Unk0201ca6c *p, s32 a) {
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Unk02061808 *g;

    if (a != 0) {
        return;
    }
    g = func_02061808();
    v = g->mUnk_15c;
    w = data_02155a14;
    if (func_0203c5e4() != 0) {
        func_02148714(g->mUnk_068, g->mUnk_06a);
        func_021484d0(&g->mUnk_024, &g->mUnk_134, &w);
        w.x = w.x >> 4;
        w.y = w.y >> 4;
        w.z = w.z >> 4;
    }
    v.y = 0;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
    }
    func_02147fd8(data_02165958, &v, &g->mUnk_09c, &u);
    u.y = u.y + (data_0216595c + (s32) (((s64) g->mUnk_15c.y * data_02165940 + 0x800) >> 12));
    func_02148504(&u, &w, &u);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_58 = 0x800;
}

void func_02081f30(void) {
    Unk0201ca6c *p;

    switch (data_021759c0->mUnk_00) {
        case 0x25:
            if (data_0217ae78 != 0) {
                func_0208b710(data_0217ae78);
                p = func_0208b7bc(0x3c, &data_02155a14);
                data_0217ae78 = p;
                p->mUnk_90 = func_020824d0;
            }
            if (data_0217ae88 == 0) {
                return;
            }
            func_0208b710(data_0217ae88);
            p = func_0208b7bc(0x3f, &data_02155a14);
            data_0217ae88 = p;
            p->mUnk_90 = func_0208266c;
            break;
        case 0x10:
            if (data_0217ae78 != 0) {
                data_0217ae78->mUnk_90 = func_02082034;
            }
            if (data_0217ae88 == 0) {
                return;
            }
            func_0208b710(data_0217ae88);
            data_0217ae88 = 0;
            break;
    }
}
