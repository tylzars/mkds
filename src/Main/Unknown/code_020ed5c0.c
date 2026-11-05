#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/unk_0216c000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020be000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f5000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "code_02147cd8.h"

BOOL func_020ee528(Unk020eda5c *a) {
    Kart *p;
    Vec3 v;
    s32 s;

    p = a->mUnk_010;
    a->mUnk_02c = *(Unk020eda5c_02c *) &p->mUnk_150;
    a->mUnk_050 = p->mUnk_98;
    a->mUnk_05c = p->mVelocity;
    a->mUnk_068 = p->mVelocityLength;
    a->mUnk_078 = (s32) (((s64) p->mUnk_2cc->mUnk_08 * p->mUnk_bc.z + 0x800) >> 12);
    a->mUnk_07c = p->mUnk_2bc;
    a->mUnk_080 = func_02039828(&a->mUnk_02c.mUnk_18, &a->mUnk_05c) > 0;
    Vec3Sub(&a->mUnk_050, &p->mPrevPos, &a->mUnk_06c);
    v.x = (s32) (((s64) p->mUnk_41c.x * p->mUnk_428.x) >> 12);
    v.y = (s32) (((s64) p->mUnk_41c.y * p->mUnk_428.y) >> 12);
    v.z = (s32) (((s64) p->mUnk_41c.z * p->mUnk_428.z) >> 12);
    s = (a->mUnk_084.x == v.x && a->mUnk_084.y == v.y && a->mUnk_084.z == v.z) ? 1 : 0;
    if (s == 0) {
        a->mUnk_084 = v;
        return TRUE;
    }
    return FALSE;
}

void func_020ee2e4(Unk020eda5c *a, Unk020f40dc *b) {
    void (*f1)(void *);
    s32 t;
    s32 k;
    void (*f2)(void *, void *);
    BOOL s;
    Unk020f41c4_A **v;
    s32 n;
    Unk020f41c4_A *q;
    s32 i;
    u16 *r;
    s32 u;

    k = b->mUnk_00;
    t = data_0217bc48[k].mUnk_14;
    s = data_021759c0->mMode == 5;
    if (b->mUnk_0c != 0) {
        if (b->mUnk_10 > b->mUnk_12) {
            return;
        }
    }
    f1 = data_0216c634[t];
    f2 = data_0217bc48[k].mUnk_18;
    if (!s) {
        func_020be8e4(a->mUnk_028, k, b->mUnk_08);
    }
    if (t == 0) {
        if (f1 != NULL) {
            f1(a);
        }
        if (f2 != NULL) {
            f2(a, b);
        }
        func_02071894(a->mUnk_010);
        return;
    }
    a->mUnk_000 = data_0217bc48[k].mUnk_08;
    a->mUnk_020 = data_0217bc48[k].mUnk_0c;
    a->mUnk_008 = t;
    a->mUnk_004 = k;
    a->mUnk_170 = NULL;
    a->mUnk_0e8 = data_0217bc48[k].mUnk_08 == 8 ? 0xb400 : 0x4333;
    u = *(vs32 *) &a->mUnk_000;
    func_020f1048(&data_027e00cc[u], a->mUnk_020, a->mUnk_014, a->mUnk_010->mIndex, &a->mUnk_050);
    func_020ee528(a);
    if (f1 != NULL) {
        f1(a);
    }
    if (f2 != NULL) {
        f2(a, b);
    }
    func_0206c11c(a->mUnk_010);
    func_020f4718(b);
    if (a->mUnk_170 != NULL) {
        func_020f81b8(a->mUnk_00c, a->mUnk_004);
    }
    v = a->mUnk_014;
    r = &a->mUnk_010->mKartModelsEntry->mUnk_040;
    n = a->mUnk_020;
    for (i = 0; i < n; i++) {
        q = v[i];
        q->mUnk_11c = 0;
        q->mUnk_0e4 = q->mUnk_50;
        q->mUnk_5c = a->mUnk_05c;
        func_020f9f08(q, a->mUnk_084.x, a->mUnk_084.y);
        q->mUnk_90 = r;
        q->mUnk_74 |= 0x1000;
    }
}

BOOL func_020ee284(Unk020f41c4_A *p, Vec3 *v, s32 d) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    t = d + p->mUnk_e0;
    x = p->mUnk_50.x - v->x;
    y = p->mUnk_50.y - v->y;
    z = p->mUnk_50.z - v->z;
    return (s64) x * x + (s64) y * y + (s64) z * z < (s64) t * t;
}

void func_020ee160(Unk020f41c4_A *a, Unk020f41c4_A *b) {
    Vec3 v;
    s32 n;
    s32 m;

    if ((b->mUnk_74 & 0x1000) != 0) {
        if (a->mUnk_48 > b->mUnk_48) {
            return;
        }
    }
    if (func_020ee284(a, &b->mUnk_50, b->mUnk_e0) == FALSE) {
        if (func_020ee284(a, &b->mUnk_0e4, b->mUnk_e0) == FALSE) {
            return;
        }
        if (func_020ee284(b, &a->mUnk_0e4, a->mUnk_e0) == FALSE) {
            return;
        }
    }
    v = a->mUnk_5c;
    n = func_020f7ea8(a, b);
    m = func_020f7ea8(b, a);
    func_020f77f8(a, n, &b->mUnk_50, &b->mUnk_5c, NULL);
    func_020f77f8(b, m, &a->mUnk_50, &v, NULL);
    if (b->mUnk_44 != 1) {
        return;
    }
    func_020f5614(b, m, a);
}

void func_020edf10(Unk020eda5c *p) {
    Unk020f41c4_A **d;
    s32 n;
    Unk020f41c4_A *q;
    s32 i;
    s32 a;
    s32 b;
    s32 j;
    enum { K0 } idx;

    d = p->mUnk_014;
    n = p->mUnk_020;
    a = func_0206c0a8(p->mUnk_010);
    b = func_0206c094(p->mUnk_010);
    for (i = 0; i < n; i++) {
        q = d[i];
        q->mUnk_11c = q->mUnk_11c + 1;
        Vec3Sub(&q->mUnk_50, &q->mUnk_0e4, &q->mUnk_5c);
        q->mUnk_0e4 = q->mUnk_50;
        if (p->mUnk_024 == 0) {
            q->mUnk_f0 = p->mUnk_02c.mUnk_0c;
            if (q->mUnk_f0.y < 0xff4) {
                q->mUnk_74 |= 0x80;
            }
        }
        if (a != 0) {
            q->mUnk_74 |= 0x40000;
        } else {
            q->mUnk_74 &= ~0x40000;
        }
        if (b != 0) {
            q->mUnk_74 |= 0x10000;
        } else {
            q->mUnk_74 &= ~0x10000;
        }
    }
    for (j = n - 1; j >= 0; j--) {
        q = d[j];
        if (q->mUnk_da == -1) {
            if (func_020f91e0(q) != 0) {
                idx = q->mUnk_44;
                if (data_0217bc34[idx].mUnk_68 != 0) {
                    func_020f9ca8(q);
                }
            }
            continue;
        }
        func_01ffd900(q->mUnk_da, 0x6000);
        for (i = 0; i < data_0217b5a8; i++) {
            if ((data_0217b5bc[i] & 0x4000) != 0) {
                Unk020f41c4_A *e = data_0217b5c4[i];
                if (e->mUnk_da == -1) {
                    continue;
                }
                if ((e->mUnk_78 & 0x4000) != 0 && p->mUnk_028 == (u16) (e->mUnk_78 & ~0xff00)) {
                    continue;
                }
                func_020ee160(q, e);
            } else if ((data_0217b5bc[i] & 0x2000) != 0) {
                MapObject *e = data_0217b5c4[i];
                if (func_020d2234(e, q) == 0) {
                    continue;
                }
                func_020f944c(q, e);
            }
            if (q->mUnk_da == -1) {
                break;
            }
        }
    }
}

void func_020eddb4(Unk020eda5c *p) {
    s32 id;
    s32 n;
    s32 m;
    Unk020f41c4_A *q;
    Kart *o;
    enum { K0 } k;

    id = p->mUnk_008;
    if (func_020ee528(p) != FALSE) {
        m = p->mUnk_020;
        for (n = 0; n < m; n++) {
            func_020f9f08(p->mUnk_014[n], p->mUnk_084.x, p->mUnk_084.y);
        }
    }
    if (data_0216c620[id] != NULL) {
        data_0216c620[id](p);
    }
    func_020edf10(p);
    if (p->mUnk_020 == 0) {
        func_020ee6a8(p);
    }
    if (p->mUnk_024 <= 0) {
        return;
    }
    p->mUnk_024 = p->mUnk_024 - 1;
    if (p->mUnk_024 != 8 && p->mUnk_024 != 4 && p->mUnk_024 != 0) {
        return;
    }
    p->mUnk_020 = p->mUnk_020 - 1;
    n = p->mUnk_020;
    o = p->mUnk_010;
    q = p->mUnk_014[n];
    func_020efb84(p, q);
    func_020f6630(q, n + 1, &o->mUnk_98, &o->mVelocity, &o->mUnk_244);
    k = q->mUnk_44;
    if (data_0217bc34[k].mUnk_38 != NULL) {
        data_0217bc34[k].mUnk_38(q);
    }
    if (p->mUnk_020 != 0) {
        return;
    }
    func_020ee6a8(p);
}

s32 func_020edc9c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d) {
    Vec3 v;
    s32 n;
    s32 r;

    n = Vec3Length(&p->mUnk_06c);
    if (p->mUnk_080 != 0) {
        r = a + (s32) (((s64) n * b) >> 12);
        Vec3AddScaled(c, &p->mUnk_02c.mUnk_18, &p->mUnk_06c, &v);
    } else {
        Vec3 *t;

        t = &p->mUnk_010->mUnk_1fc;
        if ((s64) t->x * t->x + (s64) t->y * t->y + (s64) t->z * t->z >= 0x10) {
            r = a + (s32) (((s64) n * b) >> 12);
            Vec3AddScaled(c, &p->mUnk_02c.mUnk_18, t, &v);
        } else {
            r = a - n;
            v = p->mUnk_02c.mUnk_18;
        }
    }
    if ((p->mUnk_010->mUnk_48 & 1) == 0) {
        v.y = 0;
    }
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
        func_02039860(&v, d);
    }
    return r;
}

s32 func_020edb8c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d) {
    Vec3 v;
    s32 n;

    n = Vec3Length(&p->mUnk_06c);
    if (p->mUnk_080 != 0) {
        a -= n;
        Vec3Sub(&p->mUnk_06c, &p->mUnk_010->mUnk_1fc, &v);
        Vec3AddScaled(c, &p->mUnk_02c.mUnk_18, &v, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    } else {
        a += (s32) (((s64) n * b) >> 12);
        v.x = -p->mUnk_02c.mUnk_18.x;
        v.y = -p->mUnk_02c.mUnk_18.y;
        v.z = -p->mUnk_02c.mUnk_18.z;
    }
    if ((p->mUnk_010->mUnk_48 & 1) == 0) {
        v.y = 0;
    }
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
        func_02039860(&v, d);
    }
    return a;
}

void func_020edb00(Unk020eda5c *p) {
    while (p->mUnk_020 > 0) {
        p->mUnk_020--;
        func_020f0f70(&data_027e00cc[p->mUnk_014[p->mUnk_020]->mUnk_44], p->mUnk_014[p->mUnk_020]);
    }
    func_020ee6a8(p);
    if (p->mUnk_170 != NULL) {
        p->mUnk_00c->mUnk_014 = 0x13;
        p->mUnk_170 = NULL;
    }
}

void func_020edad8(Unk020eda5c *p) {
    p->mUnk_024 = 0xa;
    if (p->mUnk_170 != NULL) {
        p->mUnk_00c->mUnk_014 = 0x13;
        p->mUnk_170 = NULL;
    }
}

void func_020eda5c(Unk020eda5c *p, Unk020f41c4_A *q) {
    s32 n;
    Unk020f41c4_A *e;
    s32 i;

    e = q;
    n = p->mUnk_020;
    for (i = 0; i < n; i++) {
        if (p->mUnk_014[i] == e) {
            ((void (*)(void *, s32, Unk020f41c4_A *))((void **) data_0216c60c)[p->mUnk_008])(p, i, e);
            if (p->mUnk_020 != 0) {
                return;
            }
            func_020ee6a8(p);
            return;
        }
    }
}

void *func_020ed98c(Unk020f41c4_A *p, Vec3 *v) {
    if (p->mUnk_f0.y < 0xfae || (p->mUnk_74 & 0x80) != 0) {
        p->mUnk_94.mUnk_00[2] = *v;
        func_020397a8(&p->mUnk_f0, &p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0]);
        if ((s64) p->mUnk_94.mUnk_00[0].x * p->mUnk_94.mUnk_00[0].x +
                (s64) p->mUnk_94.mUnk_00[0].y * p->mUnk_94.mUnk_00[0].y +
                (s64) p->mUnk_94.mUnk_00[0].z * p->mUnk_94.mUnk_00[0].z >=
            0x10) {
            func_02039860(&p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[0]);
        }
        func_020397a8(&p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[1]);
        {
            Vec3 *d0;

            d0 = p->mUnk_d0;
            p->mUnk_94.mUnk_00[3].x = d0->x >> 4;
            p->mUnk_94.mUnk_00[3].y = d0->y >> 4;
            p->mUnk_94.mUnk_00[3].z = d0->z >> 4;
        }
        return &p->mUnk_94.mUnk_00[0];
    } else {
        return func_020e6b94(p->mUnk_d0);
    }
}

void func_020ed79c(Unk020ed718 *p, Vec3 *v) {
    s16 d8;
    s32 i;
    Unk020e6488 *d;
    s32 n;
    s32 sel;
    Unk020f41c4_A *q;
    void *r;

    d = data_0217bbfc[p->mUnk_000];
    n = p->mUnk_010;
    sel = p->mUnk_014;
    func_020e6a18(d);
    d->mUnk_14 &= ~0x3f000000;
    d->mUnk_14 |= 0x4000000;
    for (i = 0; i < n; i++) {
        q = p->mUnk_004[i];
        if ((q->mUnk_74 & 0x10000) != 0) {
            continue;
        }
        if ((q->mUnk_74 & 0x1000) != 0) {
            func_0208ab4c(q->mUnk_90);
        } else {
            func_0208ab4c(q->mUnk_7c.mUnk_00);
        }
        if ((d8 = q->mUnk_d8) != 0x1f) {
            d->mUnk_14 &= ~0x1f0000;
            d->mUnk_14 |= (u32) (u16) d8 << 16;
        }
        if (i == sel) {
            d->mUnk_14 &= ~0x3f000000;
            d->mUnk_14 |= 0x3000000;
        }
        if (q->mUnk_f0.y < 0xfae || (q->mUnk_74 & 0x80) != 0) {
            q->mUnk_94.mUnk_00[2] = *v;
            func_020397a8(&q->mUnk_f0, &q->mUnk_94.mUnk_00[2], &q->mUnk_94.mUnk_00[0]);
            if ((s64) q->mUnk_94.mUnk_00[0].x * q->mUnk_94.mUnk_00[0].x +
                    (s64) q->mUnk_94.mUnk_00[0].y * q->mUnk_94.mUnk_00[0].y +
                    (s64) q->mUnk_94.mUnk_00[0].z * q->mUnk_94.mUnk_00[0].z >=
                0x10) {
                func_02039860(&q->mUnk_94.mUnk_00[0], &q->mUnk_94.mUnk_00[0]);
            }
            func_020397a8(&q->mUnk_94.mUnk_00[2], &q->mUnk_94.mUnk_00[0], &q->mUnk_94.mUnk_00[1]);
            {
                Vec3 *d0;

                d0 = q->mUnk_d0;
                q->mUnk_94.mUnk_00[3].x = d0->x >> 4;
                q->mUnk_94.mUnk_00[3].y = d0->y >> 4;
                q->mUnk_94.mUnk_00[3].z = d0->z >> 4;
            }
            r = &q->mUnk_94.mUnk_00[0];
        } else {
            r = func_020e6b94(q->mUnk_d0);
        }
        func_020e67c4(d, r, &q->mUnk_68, 0, 0x1f);
        if ((d8 = q->mUnk_d8) != 0x1f) {
            d->mUnk_14 &= ~0x1f0000;
            d->mUnk_14 |= 0x1f0000;
        }
    }
}

void func_020ed718(Unk020ed718 *p, void *a, void (*cb)(void *, void *, void *)) {
    s32 n;
    s32 i;
    Unk020f41c4_A *q;

    n = p->mUnk_010;
    for (i = 0; i < n; i++) {
        q = p->mUnk_004[i];
        if ((q->mUnk_74 & 0x10000) != 0) {
            continue;
        }
        if ((q->mUnk_74 & 0x1000) != 0) {
            func_0208ab4c(q->mUnk_90);
        } else {
            func_0208ab4c(q->mUnk_7c.mUnk_00);
        }
        cb(q, a, data_0217bbfc[p->mUnk_000]);
    }
}

void func_020ed5c0(Unk020f41c4_A *p, Unk020e6488 *q, Vec3 *v) {
    s16 d;
    void *r;

    if ((d = p->mUnk_d8) != 0x1f) {
        q->mUnk_14 &= ~0x1f0000;
        q->mUnk_14 |= (u32) (u16) d << 16;
    }
    func_020e6a18(q);
    if (p->mUnk_f0.y < 0xfae || (p->mUnk_74 & 0x80) != 0) {
        p->mUnk_94.mUnk_00[2] = *v;
        func_020397a8(&p->mUnk_f0, &p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0]);
        if ((s64) p->mUnk_94.mUnk_00[0].x * p->mUnk_94.mUnk_00[0].x +
                (s64) p->mUnk_94.mUnk_00[0].y * p->mUnk_94.mUnk_00[0].y +
                (s64) p->mUnk_94.mUnk_00[0].z * p->mUnk_94.mUnk_00[0].z >=
            0x10) {
            func_02039860(&p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[0]);
        }
        func_020397a8(&p->mUnk_94.mUnk_00[2], &p->mUnk_94.mUnk_00[0], &p->mUnk_94.mUnk_00[1]);
        {
            Vec3 *d0;

            d0 = p->mUnk_d0;
            p->mUnk_94.mUnk_00[3].x = d0->x >> 4;
            p->mUnk_94.mUnk_00[3].y = d0->y >> 4;
            p->mUnk_94.mUnk_00[3].z = d0->z >> 4;
        }
        r = &p->mUnk_94.mUnk_00[0];
    } else {
        r = func_020e6b94(p->mUnk_d0);
    }
    func_020e67c4(q, r, &p->mUnk_68, 0, 0x1f);
    if ((d = p->mUnk_d8) != 0x1f) {
        q->mUnk_14 &= ~0x1f0000;
        q->mUnk_14 |= 0x1f0000;
    }
}
