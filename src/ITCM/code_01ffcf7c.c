#include "ITCM/code_01ffcf7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"

void func_01ffdb70(void) {
    s32 i = 0;
    s32 k = 0;
    s32 n;
    s32 t;
    Unk0217b5b8 *e;
    Vec3 *v;
    s32 r;
    u16 f;
    Unk0217b5b4 *x;
    Unk0217b5b4 *y;
    u32 w;
    Unk0217b5b4 *v1;
    Unk0217b5b4 *pa;
    Unk0217b5b4 *pb;
    if (data_0217b5b0 > 0) {
        do {
            e = &data_0217b5b8[i];
            v = e->mUnk_0c;
            r = e->mUnk_10;
            if (v != NULL) {
                f = e->mUnk_14;
                if (f & 0x600) {
                    if (f & 0x100) {
                        e->mUnk_14 = f & ~0x100;
                    } else {
                        k++;
                        goto next;
                    }
                }
                k++;
                e->mUnk_04 = v->z + r;
                e->mUnk_08 = v->z - r;
                data_0217b5b4[e->mUnk_00].mUnk_02 = (v->x + r) >> 11;
                data_0217b5c0[e->mUnk_02].mUnk_02 = (v->x - r) >> 11;
            }
        next:
            i++;
        } while (k < data_0217b5b0);
    }
    for (i = 1; i < data_0217b5b0; i++) {
        k = i;
        while ((x = &data_0217b5b4[k], y = &data_0217b5b4[k - 1], y->mUnk_02 > x->mUnk_02) && k >= 1) {
            w = *(u32 *) x;
            *(u32 *) x = *(u32 *) y;
            *(u32 *) y = w;
            v1 = data_0217b5c0;
            pa = &v1[x->mUnk_00];
            pb = &v1[y->mUnk_00];
            pa->mUnk_00++;
            pb->mUnk_00--;
            data_0217b5b8[pa->mUnk_01].mUnk_00++;
            data_0217b5b8[pb->mUnk_01].mUnk_00--;
            if (x->mUnk_01 == y->mUnk_00) {
                t = x->mUnk_01;
                do {
                    t++;
                } while (data_0217b5c0[t].mUnk_00 < k);
                x->mUnk_01 = t;
            }
            if (y->mUnk_01 > x->mUnk_00) {
                y->mUnk_01 = x->mUnk_00;
            }
            k--;
        }
    }
    for (i = 1; i < data_0217b5b0; i++) {
        k = i;
        while ((x = &data_0217b5c0[k], y = &data_0217b5c0[k - 1], y->mUnk_02 > x->mUnk_02) && k >= 1) {
            w = *(u32 *) x;
            *(u32 *) x = *(u32 *) y;
            *(u32 *) y = w;
            data_0217b5b4[x->mUnk_00].mUnk_00++;
            data_0217b5b4[y->mUnk_00].mUnk_00--;
            data_0217b5b8[x->mUnk_01].mUnk_02++;
            data_0217b5b8[y->mUnk_01].mUnk_02--;
            if (x->mUnk_00 > y->mUnk_00) {
                for (n = x->mUnk_00; n > y->mUnk_00 && data_0217b5b4[n].mUnk_01 == k - 1; n--) {
                    data_0217b5b4[n].mUnk_01++;
                }
            } else {
                n = y->mUnk_00;
                while (n > x->mUnk_00 && data_0217b5b4[n].mUnk_01 == k) {
                    data_0217b5b4[n--].mUnk_01--;
                }
            }
            k--;
        }
    }
}

void func_01ffd900(s32 a, s32 b) {
    Unk0217b5b8 *e;
    s32 c;
    s32 t;
    s32 q;
    s32 u;
    s32 s;
    s32 d;
    s32 f;
    Unk0217b5b4 *y;
    s32 p;
    Unk0217b5b4 *x;
    s32 m;
    s32 h;
    s16 l;
    u32 i;
    Unk0217b5b8 *o;
    u16 g;
    if (a < 0 || a >= 0x100) {
        return;
    }
    e = &data_0217b5b8[(s16) a];
    p = e->mUnk_00;
    u = e->mUnk_02;
    q = u;
    x = data_0217b5b4;
    y = data_0217b5c0;
    s = data_0217b5b0 - 1;
    c = x[p].mUnk_02;
    t = y[u].mUnk_02;
    d = e->mUnk_04;
    f = e->mUnk_08;
    if (e->mUnk_0c == NULL) {
        data_0217b5a8 = 0;
        return;
    }
    data_0217b5a8 = 0;
    while (p > 7 && x[p - 8].mUnk_02 >= t) {
        p -= 8;
    }
    while (p > 0 && x[p - 1].mUnk_02 >= t) {
        p--;
    }
    m = s - 7;
    while (q < m && y[q + 8].mUnk_02 <= c) {
        q += 8;
    }
    while (q < s && y[q + 1].mUnk_02 <= c) {
        q++;
    }
    h = (s16) q;
    i = x[p].mUnk_01;
    l = i;
    if (h < l) {
        return;
    }
    for (;;) {
        if (data_0217b5c0[h].mUnk_00 >= p && h != u) {
            o = &data_0217b5b8[data_0217b5c0[h].mUnk_01];
            g = o->mUnk_14;
            if (o->mUnk_04 < f || o->mUnk_08 > d || !(g & b) || (g & 0x200)) {
                goto next;
            }
            data_0217b5cc[data_0217b5a8] = data_0217b5c0[h].mUnk_01;
            data_0217b5bc[data_0217b5a8] = g;
            data_0217b5c4[data_0217b5a8] = o->mUnk_18;
            data_0217b5a8++;
            if (data_0217b5a8 == 0x80) {
                return;
            }
        }
        if (h == 0) {
            return;
        }
    next:
        h--;
        if (h < l) {
            break;
        }
    }
}

s32 func_01ffd778(Vec3 *a, s32 b, s32 c, s32 d, u16 e) {
    s32 r;
    s32 x;
    s32 y;
    s32 z;
    s32 q;
    s32 f;
    s32 g;
    c = (c + b) >> 12;
    z = (a->z - data_0217b4f8.mUnk_08.z) >> 12;
    x = (a->x - data_0217b4f8.mUnk_08.x) >> 12;
    f = x * x;
    q = z * z + f;
    r = q & ~0xc000001f;
    if (q > d) {
        r |= data_021568f4;
    }
    if (q > c * c) {
        if (e <= 1) {
            return r | 3;
        }
        r |= data_usa_021568f8;
    }
    y = (a->y - data_0217b4f8.mUnk_08.y) >> 12;
    if (x * data_0217b4f8.mUnk_14.x + y * data_0217b4f8.mUnk_14.y + z * data_0217b4f8.mUnk_14.z <
        data_0217b4f8.mUnk_00 - b) {
        return r | 2;
    }
    if (x * data_0217b4f8.mUnk_20.x + y * data_0217b4f8.mUnk_20.y + z * data_0217b4f8.mUnk_20.z > b) {
        return r | 2;
    }
    if (x * data_0217b4f8.mUnk_2c.x + y * data_0217b4f8.mUnk_2c.y + z * data_0217b4f8.mUnk_2c.z > b) {
        return r | 2;
    }
    if (x * data_0217b4f8.mUnk_38.x + y * data_0217b4f8.mUnk_38.y + z * data_0217b4f8.mUnk_38.z > b) {
        return r | 2;
    }
    g = x * data_0217b4f8.mUnk_44.x;
    if (z * data_0217b4f8.mUnk_44.z + (y * data_0217b4f8.mUnk_44.y + g) > b) {
        r |= 2;
    }
    return r;
}

static inline s32 func_01ffd648_inline(Unk0217b4f8 *g) {
    return g->mUnk_20.y;
}

s32 func_01ffd648(Vec3 *a, s32 b, s32 c, s32 d, u16 e) {
    Vec3 v;
    s32 r;
    s32 q;
    s32 h;
    c = (c + b) >> 12;
    Vec3Sub(a, &data_0217b4f8.mUnk_08, &v);
    v.x = (a->x - data_0217b4f8.mUnk_08.x) >> 12;
    v.z = (a->z - data_0217b4f8.mUnk_08.z) >> 12;
    q = v.x * v.x + v.z * v.z;
    r = q & ~0xc000001f;
    if (q > d) {
        r |= data_021568f4;
    }
    if (q > c * c) {
        if (e <= 1) {
            return r | 3;
        }
        r |= data_usa_021568f8;
    }
    v.y = (a->y - data_0217b4f8.mUnk_08.y) >> 12;
    h = ((const Vec3 *) &v)->x;
    if (v.y * func_01ffd648_inline(&data_0217b4f8) + v.x * data_0217b4f8.mUnk_20.x + v.z * data_0217b4f8.mUnk_20.z >
        b) {
        return r | 2;
    }
    if (h * data_0217b4f8.mUnk_2c.x + v.y * data_0217b4f8.mUnk_2c.y + v.z * data_0217b4f8.mUnk_2c.z > b) {
        r |= 2;
    }
    return r;
}

void func_01ffd224(struct Unk020888b4 *p, Vec3 *a, Vec3 *b) {
    Kart *q = p->mKart;
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v6;
    Vec3 v4;
    Vec3 v7;
    Vec3 v5;
    Vec3 v8;
    Vec3 v11;
    Vec3 v10;
    Vec3 v9;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    BOOL r;
    Vec3 *u;
    Kart *o;
    if (q->mState != 0) {
        return;
    }
    if (q->mUnk_44 & 2) {
        return;
    }
    if (q->mUnk_4c & 0x10000000) {
        return;
    }
    r = FALSE;
    func_0208c1d0(&v0, &v1, p);
    if (p->mUnk_a8 == 1) {
        u = &q->mUnk_12c;
        d = Vec3Dot(u, &v1);
        v5.x = v1.x - (s32) (((s64) u->x * d) >> 12);
        v5.y = v1.y - (s32) (((s64) u->y * d) >> 12);
        v5.z = v1.z - (s32) (((s64) u->z * d) >> 12);
        if (func_02039828(&q->mUnk_138, &v5) > -0x333) {
            func_0208c1d0(&v2, &v3, p);
            o = p->mKart;
            r = TRUE;
            Vec3Sub(&o->mPos, &v2, &v9);
            v9.y = 0;
            func_02063b30(o, &v8);
            d = Vec3Dot(&v8, &v3);
            v10.x = v3.x - (s32) (((s64) v8.x * d) >> 12);
            v10.y = v3.y - (s32) (((s64) v8.y * d) >> 12);
            v10.z = v3.z - (s32) (((s64) v8.z * d) >> 12);
            func_020397a8(&v9, &v10, &v11);
            g = func_02039828(&v8, &v11) > 0 ? 1 : -1;
            q->mUnk_236 += g * 200;
            goto end;
        }
    }
    if (p->mUnk_70 > 0x2000) {
        e = ((s64) q->mUnk_2a4 * *data_usa_0217ae40) >> 12;
        if (e > 0x1000) {
            e = 0x1000;
        }
        func_02063b30(q, &v6);
        d = Vec3Dot(&v6, a);
        v7.x = a->x - (s32) (((s64) v6.x * d) >> 12);
        v7.y = a->y - (s32) (((s64) v6.y * d) >> 12);
        v7.z = a->z - (s32) (((s64) v6.z * d) >> 12);
        func_020397a8(b, &v7, &v4);
        q->mUnk_236 += (g = func_02039828(&v6, &v4) > 0 ? 1 : -1) *
                       ((s32) (((s64) ((s32) (((s64) p->mUnk_70 * 0xB60B60B60BLL + 0x80000000LL) >> 32)) *
                                (s32) (((s64) e * 0xa4) >> 12)) >>
                               12) >>
                        12);
        r = TRUE;
    }
    if ((q->mUnk_4c & 0x8000000) && p->mUnk_70 < 0x46000 && (q->mUnk_44 & 0x10) && !(q->mUnk_48 & 0x8020) &&
        q->mUnk_2a4 > 0x3000 && p->mUnk_90 != 2 && p->mUnk_a8 == 0) {
        p->mUnk_c8 += 0x44c;
        p->mUnk_ca = ((s64) gPairsByAngle[(p->mUnk_c8 >> 4) * 2] * 0xfa + 0x800) >> 12;
        q->mUnk_236 += (s16) p->mUnk_ca * p->mUnk_cc;
        r = TRUE;
    } else {
        p->mUnk_ca = 0;
        p->mUnk_c8 = 0;
    }
end:
    if (r == FALSE) {
        return;
    }
    if (g > 0) {
        q->mUnk_48 |= 8;
    } else {
        q->mUnk_48 |= 0x10;
    }
}

void func_01ffd190(const Vec3 *a, s32 b, Vec4 *c) {
    s32 i = (s32) ((u32) (b << 15) >> 16) >> 4;
    s32 s = gPairsByAngle[i * 2];
    c->x = ((s64) a->x * s + 0x800) >> 12;
    c->y = ((s64) a->y * s + 0x800) >> 12;
    c->z = ((s64) a->z * s + 0x800) >> 12;
    c->w = gPairsByAngle[i * 2 + 1];
}

s32 func_01ffd0e8(Vec4 *a, const Vec3 *b, const Vec3 *c) {
    Vec3 v;
    s32 r;
    BOOL k = TRUE;
    Vec3Cross(b, c, &v);
    r = SqrtFixed12((Vec3Dot(b, c) + 0x1000) << 1);
    *a = data_usa_02155194;
    if (r <= 0) {
        k = FALSE;
    } else {
        a->x = DivFixed12(v.x, r);
        a->y = DivFixed12(v.y, r);
        a->z = DivFixed12(v.z, r);
        a->w = r >> 1;
    }
    return k;
}

void func_01ffcf7c(const Vec4 *a, Vec4 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) a->x * a->x;
    w += (s64) a->y * a->y;
    w += (s64) a->z * a->z;
    w += (s64) a->w * a->w;
    *(vu16 *) 0x4000280 = 2;
    *(vu64 *) 0x4000290 = 0x1000000000000LL << 8;
    *(vu64 *) 0x4000298 = w;
    *(vu16 *) 0x40002b0 = 1;
    *(vu64 *) 0x40002b8 = w << 2;
    while (*(vu16 *) 0x40002b0 & 0x8000) {
    }
    r = *(vu32 *) 0x40002b4;
    while (*(vu16 *) 0x4000280 & 0x8000) {
    }
    q = *(vu64 *) 0x40002a0;
    t = q * r;
    b->x = (s32) ((t * a->x + 0x100000000000LL) >> 45);
    b->y = (s32) ((t * a->y + 0x100000000000LL) >> 45);
    b->z = (s32) ((t * a->z + 0x100000000000LL) >> 45);
    b->w = (s32) ((t * a->w + 0x100000000000LL) >> 45);
}
