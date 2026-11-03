#include "code_0201c528.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02173000.h"
#include "registers.h"

void func_0201e540(Vec3 *v) {
    v->x = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    v->y = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    v->z = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    func_0214818c(v, v);
}

void func_0201e4e4(Vec3 *v) {
    v->x = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    v->y = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    v->z = 0;
    func_0214818c(v, v);
}

void func_0201e494(Unk0201e494 *l0, Unk0201e3c8 *p) {
    if (l0->mUnk_00 == 0) {
        l0->mUnk_00 = p;
        l0->mUnk_08 = p;
        p->mUnk_00 = 0;
        p->mUnk_04 = p->mUnk_00;
    } else {
        p->mUnk_00 = l0->mUnk_00;
        p->mUnk_04 = 0;
        l0->mUnk_00->mUnk_04 = p;
        l0->mUnk_00 = p;
    }
    l0->mUnk_04++;
}

Unk0201e3c8 *func_0201e448(Unk0201e494 *l0) {
    Unk0201e3c8 *a;
    Unk0201e3c8 *b;

    b = 0;
    a = l0->mUnk_00;
    if (a != 0) {
        b = a;
        l0->mUnk_00 = a->mUnk_00;
        if (l0->mUnk_00 != 0) {
            a->mUnk_00->mUnk_04 = 0;
        } else {
            l0->mUnk_00 = 0;
            l0->mUnk_08 = 0;
        }
        l0->mUnk_04--;
    }
    return b;
}

Unk0201e3c8 *func_0201e3c8(Unk0201e494 *l0, Unk0201e3c8 *p) {
    Unk0201e3c8 *a;

    a = p->mUnk_00;
    if (a == 0) {
        if (l0->mUnk_00 == p) {
            l0->mUnk_00 = 0;
            l0->mUnk_08 = 0;
        } else {
            p->mUnk_04->mUnk_00 = 0;
            l0->mUnk_08 = l0->mUnk_08->mUnk_04;
        }
    } else {
        if (l0->mUnk_00 == p) {
            l0->mUnk_00 = a;
            l0->mUnk_00->mUnk_04 = 0;
        } else {
            a->mUnk_04 = p->mUnk_04;
            p->mUnk_04->mUnk_00 = p->mUnk_00;
        }
    }
    l0->mUnk_04--;
    return p;
}

void func_0201e394(const Unk02148038 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q) {
    v->x = v->x + a->mUnk_00;
    v->y = v->y + a->mUnk_02;
    v->z = v->z + a->mUnk_04;
}

void func_0201e2cc(const Unk0201e2cc *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q) {
    if (p->mUnk_26 % a->mUnk_06 != 0) {
        return;
    }
    v->x =
        v->x +
        ((a->mUnk_00 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) - (a->mUnk_00 << 8)) >>
         8);
    v->y =
        v->y +
        ((a->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) - (a->mUnk_02 << 8)) >>
         8);
    v->z =
        v->z +
        ((a->mUnk_04 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) - (a->mUnk_04 << 8)) >>
         8);
}

void func_0201e248(const Unk0201e248 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q) {
    v->x = v->x + ((a->mUnk_0c * (a->mUnk_00.x - p->mUnk_08.x - p->mUnk_14.x)) >> 12);
    v->y = v->y + ((a->mUnk_0c * (a->mUnk_00.y - p->mUnk_08.y - p->mUnk_14.y)) >> 12);
    v->z = v->z + ((a->mUnk_0c * (a->mUnk_00.z - p->mUnk_08.z - p->mUnk_14.z)) >> 12);
}

void func_0201e170(const Unk0201e170 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q) {
    s32 buf[9];

    switch (a->mUnk_02) {
        case 0:
            func_02146d28(buf, data_0215d4b4[(a->mUnk_00 >> 4) * 2], data_0215d4b4[(a->mUnk_00 >> 4) * 2 + 1]);
            break;
        case 1:
            func_02146d44(buf, data_0215d4b4[(a->mUnk_00 >> 4) * 2], data_0215d4b4[(a->mUnk_00 >> 4) * 2 + 1]);
            break;
        case 2:
            func_02146d60(buf, data_0215d4b4[(a->mUnk_00 >> 4) * 2], data_0215d4b4[(a->mUnk_00 >> 4) * 2 + 1]);
            break;
    }
    func_02146d78(&p->mUnk_08, buf, &p->mUnk_08);
}

void func_0201e054(const Unk0201e054 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q) {
    s32 lim;
    s32 y;

    lim = a->mUnk_00;
    if (q->mUnk_74 != 0x80000000) {
        lim = q->mUnk_74;
    }
    switch (a->mUnk_06_0) {
        case 0:
            y = p->mUnk_38.y;
            if (y < lim) {
                if (y + p->mUnk_08.y > lim) {
                    p->mUnk_08.y = lim - y;
                    p->mUnk_26 = p->mUnk_24;
                    return;
                }
            }
            if (y >= lim) {
                if (y + p->mUnk_08.y < lim) {
                    p->mUnk_08.y = lim - y;
                    p->mUnk_26 = p->mUnk_24;
                }
            }
            break;
        case 1:
            y = p->mUnk_38.y;
            if (y < lim && y + p->mUnk_08.y > lim) {
                p->mUnk_08.y = lim - y;
                p->mUnk_14.y = -(s32) (((s64) p->mUnk_14.y * a->mUnk_04 + 0x800) >> 12);
            } else if (y >= lim && y + p->mUnk_08.y < lim) {
                p->mUnk_08.y = lim - y;
                p->mUnk_14.y = -(s32) (((s64) p->mUnk_14.y * a->mUnk_04 + 0x800) >> 12);
            }
            break;
    }
}

void func_0201dfc0(const Unk0201e248 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q) {
    p->mUnk_08.x = p->mUnk_08.x + (s32) (((s64) a->mUnk_0c * (a->mUnk_00.x - p->mUnk_08.x) + 0x800) >> 12);
    p->mUnk_08.y = p->mUnk_08.y + (s32) (((s64) a->mUnk_0c * (a->mUnk_00.y - p->mUnk_08.y) + 0x800) >> 12);
    p->mUnk_08.z = p->mUnk_08.z + (s32) (((s64) a->mUnk_0c * (a->mUnk_00.z - p->mUnk_08.z) + 0x800) >> 12);
}

void func_0201df30(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v) {
    Unk0201ca6c_20_04 *t;
    s32 a;
    s32 lo;
    s32 hi;

    t = q->mUnk_04;
    lo = t->mUnk_06;
    hi = t->mUnk_07;
    if (v < lo) {
        a = t->mUnk_00;
        p->mUnk_34 = a + (v * (t->mUnk_02 - a)) / lo;
        return;
    }
    if (v < hi) {
        p->mUnk_34 = t->mUnk_02;
        return;
    }
    a = t->mUnk_04;
    p->mUnk_34 = a + ((v - 0xff) * (a - t->mUnk_02)) / (0xff - hi);
}

void func_0201dd64(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v) {
    Unk0201ca6c_20_08 *t;
    Unk0201ca6c_20_00 *d;
    s32 lo;
    s32 mid;
    s32 hi;
    s32 br;
    s32 ar;
    s32 bg;
    s32 ag;
    s32 ab;
    s32 bb;
    s32 n;
    s32 m;

    t = q->mUnk_08;
    d = q->mUnk_00;
    lo = t->mUnk_04;
    mid = t->mUnk_05;
    hi = t->mUnk_06;
    if (v < lo) {
        p->mUnk_36 = t->mUnk_00;
        return;
    }
    if (v < mid) {
        ar = t->mUnk_00 & 0x1f;
        ag = (t->mUnk_00 >> 5) & 0x1f;
        ab = (t->mUnk_00 >> 10) & 0x1f;
        br = d->mUnk_22 & 0x1f;
        bg = (d->mUnk_22 >> 5) & 0x1f;
        bb = (d->mUnk_22 >> 10) & 0x1f;
        if (t->mUnk_08_2 == 0) {
            p->mUnk_36 = br | (bg << 5) | (bb << 10);
            return;
        }
        n = v - lo;
        m = mid - lo;
        p->mUnk_36 =
            (ar + (n * (br - ar)) / m) | ((ag + (n * (bg - ag)) / m) << 5) | ((ab + (n * (bb - ab)) / m) << 10);
        return;
    }
    if (v < hi) {
        s32 cb; // PERM
        s32 er; // PERM
        s32 cr; // PERM
        s32 eg; // PERM
        s32 cg; // PERM
        s32 eb; // PERM
        er = d->mUnk_22 & 0x1f;
        eg = (d->mUnk_22 >> 5) & 0x1f;
        eb = (d->mUnk_22 >> 10) & 0x1f;
        cr = t->mUnk_02 & 0x1f;
        cg = (t->mUnk_02 >> 5) & 0x1f;
        cb = (t->mUnk_02 >> 10) & 0x1f;
        if (t->mUnk_08_2 == 0) {
            p->mUnk_36 = cr | (cg << 5) | (cb << 10);
            return;
        }
        n = v - mid;
        m = hi - mid;
        p->mUnk_36 =
            (er + (n * (cr - er)) / m) | ((eg + (n * (cg - eg)) / m) << 5) | ((eb + (n * (cb - eb)) / m) << 10);
        return;
    }
    p->mUnk_36 = t->mUnk_02;
}

void func_0201dc88(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v) {
    Unk0201ca6c_20_0c *t;
    s32 a;
    s32 lo;
    s32 hi;

    t = q->mUnk_0c;
    lo = t->mUnk_04;
    hi = t->mUnk_05;
    if (v < lo) {
        a = t->mUnk_00_0 + (v * (t->mUnk_00_5 - t->mUnk_00_0)) / lo;
    } else if (v < hi) {
        a = t->mUnk_00_5;
    } else {
        a = t->mUnk_00_10 + ((v - 0xff) * (t->mUnk_00_10 - t->mUnk_00_5)) / (0xff - hi);
    }
    p->mUnk_2e_5 =
        (a *
         (0xff - ((t->mUnk_02_0 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 8))) >>
        8;
}

// non-matching: the original saves r4, r5, lr and reserves 4 more stack bytes (three callee-saved registers); this
// build saves r4, lr (0x5c bytes vs 0x64)
void func_0201dc24(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v) {
    Unk0201ca6c_20_10 *t;
    s32 i;
    s32 n;
    s32 w;
    s32 s;

    t = q->mUnk_10;
    n = t->mUnk_08_0;
    if (n <= 0) {
        return;
    }
    w = t->mUnk_08_8;
    s = 0;
    for (i = 0; i < n; i++) {
        if (v < s + w) {
            p->mUnk_2c = t->mUnk_00[i];
            return;
        }
        s += w;
    }
}

void func_0201dbd8(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v) {
    s32 a;

    a = q->mUnk_14->mUnk_04;
    p->mUnk_34 = a + ((a - 0x1000) * (v - 0xff)) / 0xff;
}

void func_0201db80(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v) {
    p->mUnk_2e_5 = ((0xff - v) * 0x1f) / 0xff;
}

void func_0201d8f8(Unk0201ca6c *p) {
    Unk02148038 a;
    Unk02148038 b;
    s32 d;

    a = data_02161ad0;
    switch (p->mUnk_20->mUnk_00->mUnk_00.mUnk_00_6) {
        case 2:
            b.mUnk_00 = 0x1000;
            b.mUnk_02 = 0;
            b.mUnk_04 = 0;
            break;
        case 1:
            b.mUnk_00 = 0;
            b.mUnk_02 = 0x1000;
            b.mUnk_04 = 0;
            break;
        case 0:
            b.mUnk_00 = 0;
            b.mUnk_02 = 0;
            b.mUnk_04 = 0x1000;
            break;
        default:
            func_02148038(&p->mUnk_50, &b);
            break;
    }
    d = func_0214843c(&a, &b);
    if (d == 0x1000 || d == -0x1000) {
        a.mUnk_00 = 0x1000;
        a.mUnk_02 = 0;
        a.mUnk_04 = 0;
    }
    p->mUnk_84.mUnk_00 =
        (s32) (((s64) b.mUnk_02 * a.mUnk_04 + 0x800) >> 12) - (s32) (((s64) b.mUnk_04 * a.mUnk_02 + 0x800) >> 12);
    p->mUnk_84.mUnk_02 =
        (s32) (((s64) b.mUnk_04 * a.mUnk_00 + 0x800) >> 12) - (s32) (((s64) b.mUnk_00 * a.mUnk_04 + 0x800) >> 12);
    p->mUnk_84.mUnk_04 =
        (s32) (((s64) b.mUnk_00 * a.mUnk_02 + 0x800) >> 12) - (s32) (((s64) b.mUnk_02 * a.mUnk_00 + 0x800) >> 12);
    p->mUnk_8a.mUnk_00 = (s32) (((s64) b.mUnk_02 * p->mUnk_84.mUnk_04 + 0x800) >> 12) -
                         (s32) (((s64) b.mUnk_04 * p->mUnk_84.mUnk_02 + 0x800) >> 12);
    p->mUnk_8a.mUnk_02 = (s32) (((s64) b.mUnk_04 * p->mUnk_84.mUnk_00 + 0x800) >> 12) -
                         (s32) (((s64) b.mUnk_00 * p->mUnk_84.mUnk_04 + 0x800) >> 12);
    p->mUnk_8a.mUnk_04 = (s32) (((s64) b.mUnk_00 * p->mUnk_84.mUnk_02 + 0x800) >> 12) -
                         (s32) (((s64) b.mUnk_02 * p->mUnk_84.mUnk_00 + 0x800) >> 12);
    func_02148038(&p->mUnk_84, &p->mUnk_84);
    func_02148038(&p->mUnk_8a, &p->mUnk_8a);
}

void func_0201d798(Vec3 *out, const Vec3 *v, Unk0201ca6c *p) {
    Unk02148038 a;

    func_02148334(&p->mUnk_84, &p->mUnk_8a, &a);
    func_02148038(&a, &a);
    out->x = (s32) (((s64) v->z * a.mUnk_00 + 0x800) >> 12) + ((s32) (((s64) v->x * p->mUnk_84.mUnk_00 + 0x800) >> 12) +
                                                               (s32) (((s64) v->y * p->mUnk_8a.mUnk_00 + 0x800) >> 12));
    out->y = (s32) (((s64) v->z * a.mUnk_02 + 0x800) >> 12) + ((s32) (((s64) v->x * p->mUnk_84.mUnk_02 + 0x800) >> 12) +
                                                               (s32) (((s64) v->y * p->mUnk_8a.mUnk_02 + 0x800) >> 12));
    out->z = (s32) (((s64) v->z * a.mUnk_04 + 0x800) >> 12) + ((s32) (((s64) v->x * p->mUnk_84.mUnk_04 + 0x800) >> 12) +
                                                               (s32) (((s64) v->y * p->mUnk_8a.mUnk_04 + 0x800) >> 12));
}

void func_0201ca6c(Unk0201ca6c *p, Unk0201e494 *l0) {
    Unk0201ca6c_20 *c;
    Unk0201ca6c_20_00 *d;
    Unk0201e3c8 *n0;
    s32 i;
    s32 n;
    s32 t;
    s32 s1;
    s32 s2;
    s32 acc;
    Vec3 v2;
    Vec3 v3;
    Vec3 v5;
    Unk02148038 a8;
    Vec3 v8;
    Unk02148038 a9;
    Vec3 v9;
    Vec3 v6;
    Vec3 v7;
    u16 ch[3];
    Vec3 u;
    Vec3 w;

    c = p->mUnk_20;
    t = p->mUnk_58 + p->mUnk_4e;
    d = c->mUnk_00;
    p->mUnk_4e = t & 0xfff;
    n = t >> 12;
    if (d->mUnk_00.mUnk_00_0 == 2 || d->mUnk_00.mUnk_00_0 == 3 || d->mUnk_00.mUnk_00_0 == 5 ||
        d->mUnk_00.mUnk_00_0 == 6 || d->mUnk_00.mUnk_00_0 == 7 || d->mUnk_00.mUnk_00_0 == 8 ||
        d->mUnk_00.mUnk_00_0 == 9) {
        func_0201d8f8(p);
    }
    i = 0;
    if (i < n) {
        acc = 0;
        do {
            n0 = func_0201e448(l0);
            if (n0 == 0) {
                return;
            }
            func_0201e494(&p->mUnk_08, n0);
            switch (d->mUnk_00.mUnk_00_0) {
                case 0:
                    n0->mUnk_08.x = n0->mUnk_08.y = n0->mUnk_08.z = 0;
                    break;
                case 1:
                    func_0201e540(&n0->mUnk_08);
                    n0->mUnk_08.x = (s32) (((s64) n0->mUnk_08.x * p->mUnk_5c + 0x800) >> 12);
                    n0->mUnk_08.y = (s32) (((s64) n0->mUnk_08.y * p->mUnk_5c + 0x800) >> 12);
                    n0->mUnk_08.z = (s32) (((s64) n0->mUnk_08.z * p->mUnk_5c + 0x800) >> 12);
                    break;
                case 2: {
                    func_0201e4e4(&v2);
                    v2.x = (s32) (((s64) v2.x * p->mUnk_5c + 0x800) >> 12);
                    v2.y = (s32) (((s64) v2.y * p->mUnk_5c + 0x800) >> 12);
                    v2.z = 0;
                    func_0201d798(&n0->mUnk_08, &v2, p);
                    break;
                }
                case 3: {
                    s32 k;
                    s32 a;
                    s32 b;
                    k = acc / n;
                    acc += 0x10000;
                    k >>= 4;
                    a = data_0215d4b4[k * 2];
                    b = data_0215d4b4[k * 2 + 1];
                    v3.x = (s32) (((s64) a * p->mUnk_5c + 0x800) >> 12);
                    v3.y = (s32) (((s64) b * p->mUnk_5c + 0x800) >> 12);
                    v3.z = 0;
                    func_0201d798(&n0->mUnk_08, &v3, p);
                    break;
                }
                case 4: {
                    func_0201e540(&n0->mUnk_08);
                    n0->mUnk_08.x =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_08.x * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    n0->mUnk_08.y =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_08.y * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    n0->mUnk_08.z =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_08.z * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    break;
                }
                case 5: {
                    func_0201e4e4(&v5);
                    v5.x =
                        (s32) (((s64) (s32) (((s64) v5.x * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    v5.y =
                        (s32) (((s64) (s32) (((s64) v5.y * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    func_0201d798(&n0->mUnk_08, &v5, p);
                    break;
                }
                case 8: {
                    func_0201e540(&n0->mUnk_08);
                    func_02148334(&p->mUnk_84, &p->mUnk_8a, &a8);
                    v8.x = a8.mUnk_00;
                    v8.y = a8.mUnk_02;
                    v8.z = a8.mUnk_04;
                    if (func_0214848c(&v8, &n0->mUnk_08) <= 0) {
                        n0->mUnk_08.x = -n0->mUnk_08.x;
                        n0->mUnk_08.y = -n0->mUnk_08.y;
                        n0->mUnk_08.z = -n0->mUnk_08.z;
                    }
                    n0->mUnk_08.x = (s32) (((s64) n0->mUnk_08.x * p->mUnk_5c + 0x800) >> 12);
                    n0->mUnk_08.y = (s32) (((s64) n0->mUnk_08.y * p->mUnk_5c + 0x800) >> 12);
                    n0->mUnk_08.z = (s32) (((s64) n0->mUnk_08.z * p->mUnk_5c + 0x800) >> 12);
                    break;
                }
                case 9: {
                    func_0201e540(&n0->mUnk_08);
                    func_02148334(&p->mUnk_84, &p->mUnk_8a, &a9);
                    v9.x = a9.mUnk_00;
                    v9.y = a9.mUnk_02;
                    v9.z = a9.mUnk_04;
                    if (func_0214848c(&v9, &n0->mUnk_08) < 0) {
                        n0->mUnk_08.x = -n0->mUnk_08.x;
                        n0->mUnk_08.y = -n0->mUnk_08.y;
                        n0->mUnk_08.z = -n0->mUnk_08.z;
                    }
                    n0->mUnk_08.x =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_08.x * p->mUnk_5c + 0x800) >> 12) *
                                    (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) *
                                                 0x1000 -
                                             0x100000) >>
                                      9) +
                                     0x800) +
                                0x800) >>
                               12);
                    n0->mUnk_08.y =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_08.y * p->mUnk_5c + 0x800) >> 12) *
                                    (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) *
                                                 0x1000 -
                                             0x100000) >>
                                      9) +
                                     0x800) +
                                0x800) >>
                               12);
                    n0->mUnk_08.z =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_08.z * p->mUnk_5c + 0x800) >> 12) *
                                    (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) *
                                                 0x1000 -
                                             0x100000) >>
                                      9) +
                                     0x800) +
                                0x800) >>
                               12);
                    break;
                }
                case 6: {
                    func_0201e4e4(&n0->mUnk_14);
                    v6.x = (s32) (((s64) n0->mUnk_14.x * p->mUnk_5c + 0x800) >> 12);
                    v6.y = (s32) (((s64) n0->mUnk_14.y * p->mUnk_5c + 0x800) >> 12);
                    v6.z = (p->mUnk_60 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                            p->mUnk_60 * 0x100) >>
                           8;
                    func_0201d798(&n0->mUnk_08, &v6, p);
                    break;
                }
                case 7: {
                    func_0201e4e4(&n0->mUnk_14);
                    v7.x =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_14.x * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    v7.y =
                        (s32) (((s64) (s32) (((s64) n0->mUnk_14.y * p->mUnk_5c + 0x800) >> 12) *
                                    ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                            0x100000) >>
                                     8) +
                                0x800) >>
                               12);
                    v7.z = (p->mUnk_60 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                            p->mUnk_60 * 0x100) >>
                           8;
                    func_0201d798(&n0->mUnk_08, &v7, p);
                    break;
                }
            }

            s1 = ((d->mUnk_42 + 0xff -
                   ((d->mUnk_42 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                  p->mUnk_64) >>
                 8;
            s2 = ((d->mUnk_42 + 0xff -
                   ((d->mUnk_42 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                  p->mUnk_68) >>
                 8;

            if (d->mUnk_00.mUnk_00_0 == 6) {
                w.x = (s32) (((s64) n0->mUnk_14.x * p->mUnk_84.mUnk_00 + 0x800) >> 12) +
                      (s32) (((s64) n0->mUnk_14.y * p->mUnk_8a.mUnk_00 + 0x800) >> 12);
                w.y = (s32) (((s64) n0->mUnk_14.x * p->mUnk_84.mUnk_02 + 0x800) >> 12) +
                      (s32) (((s64) n0->mUnk_14.y * p->mUnk_8a.mUnk_02 + 0x800) >> 12);
                w.z = (s32) (((s64) n0->mUnk_14.x * p->mUnk_84.mUnk_04 + 0x800) >> 12) +
                      (s32) (((s64) n0->mUnk_14.y * p->mUnk_8a.mUnk_04 + 0x800) >> 12);
                func_0214818c(&w, &u);
            } else if (n0->mUnk_08.x == 0 && n0->mUnk_08.y == 0 && n0->mUnk_08.z == 0) {
                func_0201e540(&u);
            } else {
                func_0214818c(&n0->mUnk_08, &u);
            }

            n0->mUnk_14.x = p->mUnk_40.x + ((s32) (((s64) u.x * s1 + 0x800) >> 12) +
                                            (s32) (((s64) p->mUnk_50.mUnk_00 * s2 + 0x800) >> 12));
            n0->mUnk_14.y = p->mUnk_40.y + ((s32) (((s64) u.y * s1 + 0x800) >> 12) +
                                            (s32) (((s64) p->mUnk_50.mUnk_02 * s2 + 0x800) >> 12));
            n0->mUnk_14.z = p->mUnk_40.z + ((s32) (((s64) u.z * s1 + 0x800) >> 12) +
                                            (s32) (((s64) p->mUnk_50.mUnk_04 * s2 + 0x800) >> 12));
            n0->mUnk_38 = p->mUnk_28;

            n0->mUnk_30 =
                ((d->mUnk_40 + 0xff -
                  ((d->mUnk_40 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                 p->mUnk_6c) >>
                8;
            n0->mUnk_34 = 0x1000;

            if (d->mUnk_00.mUnk_00_9 && c->mUnk_08->mUnk_08_0) {
                Unk0201ca6c_20_08 *q;
                u32 r;
                r = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20;
                q = c->mUnk_08;
                ch[0] = q->mUnk_00;
                ch[1] = d->mUnk_22;
                ch[2] = q->mUnk_02;
                n0->mUnk_36 = ch[r % 3];
            } else {
                n0->mUnk_36 = d->mUnk_22;
            }

            n0->mUnk_2e_0 = p->mUnk_80_8;
            n0->mUnk_2e_5 = 0x1f;

            if (d->mUnk_00.mUnk_00_13) {
                n0->mUnk_20 = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173);
            } else {
                n0->mUnk_20 = p->mUnk_56;
            }

            if (d->mUnk_00.mUnk_00_12) {
                n0->mUnk_22 =
                    ((d->mUnk_36 - d->mUnk_34) * ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20) +
                     (d->mUnk_34 << 12)) >>
                    12;
            } else {
                n0->mUnk_22 = 0;
            }

            n0->mUnk_24 =
                (((0xff -
                   ((d->mUnk_41 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 8)) *
                  p->mUnk_70) >>
                 8) +
                1;
            n0->mUnk_26 = 0;

            if (d->mUnk_00.mUnk_00_11 && c->mUnk_10->mUnk_08_16) {
                Unk0201ca6c_20_10 *q;
                u32 r;
                r = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20;
                q = c->mUnk_10;
                n0->mUnk_2c = q->mUnk_00[r % q->mUnk_08_0];
            } else if (d->mUnk_00.mUnk_00_11 && !c->mUnk_10->mUnk_08_16) {
                n0->mUnk_2c = c->mUnk_10->mUnk_00[0];
            } else {
                n0->mUnk_2c = d->mUnk_47;
            }

            n0->mUnk_28 = 0xffff / c->mUnk_00->mUnk_48.mUnk_00_0;
            n0->mUnk_2a = 0xffff / n0->mUnk_24;
            n0->mUnk_2d = 0;
            if (d->mUnk_00.mUnk_00_20) {
                n0->mUnk_2d = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24;
            }
        } while (++i < n);
    }
}

// non-matching: the original keeps the address of mUnk_38 of the entry from func_0201e448 in a stack slot and holds the
// table pointer and that entry in r6 and r7 (swapped here); this build is 8 bytes shorter (0x318 vs 0x320)
void func_0201c74c(Unk0201e3c8 *a, Unk0201ca6c *p, Unk0201e494 *l0) {
    Unk0201ca6c_20_14 *e;
    Unk0201e3c8 *n;
    s32 k0;
    s32 i;
    Vec3 *d;

    e = p->mUnk_20->mUnk_14;
    k0 = (s32) (((s64) (e->mUnk_08 << 12) * 16 + 0x800) >> 12);
    for (i = 0; i < e->mUnk_0c; i++) {
        {
            n = func_0201e448(l0);
            if (n == 0) {
                return;
            }
            func_0201e494(&p->mUnk_14, n);
            d = &n->mUnk_38;
            n->mUnk_08 = a->mUnk_08;
            n->mUnk_14.x = (s32) (((s64) a->mUnk_14.x * (s64) k0 + 0x800) >> 12) +
                           ((e->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->mUnk_02 << 8)) >>
                            8);
            n->mUnk_14.y = (s32) (((s64) a->mUnk_14.y * (s64) k0 + 0x800) >> 12) +
                           ((e->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->mUnk_02 << 8)) >>
                            8);
            n->mUnk_14.z = (s32) (((s64) a->mUnk_14.z * (s64) k0 + 0x800) >> 12) +
                           ((e->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->mUnk_02 << 8)) >>
                            8);
            *d = a->mUnk_38;
            n->mUnk_30 = (((a->mUnk_30 * a->mUnk_34) >> 12) * (e->mUnk_09 + 1)) >> 6;
            n->mUnk_34 = 0x1000;
            if (e->mUnk_00_6) {
                n->mUnk_36 = e->mUnk_0a;
            } else {
                n->mUnk_36 = a->mUnk_36;
            }
            n->mUnk_2e_0 = (a->mUnk_2e_0 * (a->mUnk_2e_5 + 1)) >> 5;
            n->mUnk_2e_5 = 0x1f;
            switch (e->mUnk_00_3) {
                case 2:
                    n->mUnk_20 = a->mUnk_20;
                    n->mUnk_22 = a->mUnk_22;
                    break;
                case 1:
                    n->mUnk_20 = a->mUnk_20;
                    n->mUnk_22 = 0;
                    break;
                case 0:
                    n->mUnk_20 = 0;
                    n->mUnk_22 = 0;
                    break;
            }
            n->mUnk_24 = e->mUnk_06;
            n->mUnk_26 = 0;
            n->mUnk_2c = e->mUnk_0f;
            n->mUnk_28 = 0xffff / (a->mUnk_24 >> 1);
            n->mUnk_2a = 0xffff / a->mUnk_24;
            n->mUnk_2d = 0;
        }
    }
}

// non-matching: same instruction sequence; the temporaries sit in different registers (34 words differ)
void func_0201c690(u32 a, u32 b, s32 c, s32 d) {
    u32 e;
    u32 f;
    s32 p;
    s32 q;
    s32 r;
    s32 s;

    e = (a << 8) >> 16;
    f = (b << 8) >> 16;
    reg_G3_BEGIN_VTXS = 1;
    p = ((s16) (d + 0x1000) >> 6) & 0x3ff;
    q = ((s16) (c - 0x1000) >> 6) & 0x3ff;
    r = ((s16) (c + 0x1000) >> 6) & 0x3ff;
    s = ((s16) (d - 0x1000) >> 6) & 0x3ff;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = q | (p << 10);
    reg_G3_TEXCOORD = e;
    reg_G3_VTX_10 = r | (p << 10);
    reg_G3_TEXCOORD = e | (f << 16);
    reg_G3_VTX_10 = r | (s << 10);
    reg_G3_TEXCOORD = f << 16;
    reg_G3_VTX_10 = q | (s << 10);
    reg_G3_END_VTXS = 0;
}

void func_0201c5d4(u32 a, u32 b, s32 c, s32 d) {
    s32 r;
    u32 s;
    u32 e;
    u32 f;
    s32 p;
    s32 q;

    reg_G3_BEGIN_VTXS = 1;
    reg_G3_TEXCOORD = 0;
    q = ((s16) (c - 0x1000) >> 6) & 0x3ff;
    e = (a << 8) >> 16;
    f = (b << 8) >> 16;
    s = ((s16) (d - 0x1000) >> 6) & 0x3ff;
    p = ((s16) (d + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = q | (p << 20);
    reg_G3_TEXCOORD = e;
    r = ((s16) (c + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = r | (p << 20);
    reg_G3_TEXCOORD = e | (f << 16);
    reg_G3_VTX_10 = r | (s << 20);
    reg_G3_TEXCOORD = f << 16;
    reg_G3_VTX_10 = q | (s << 20);
    reg_G3_END_VTXS = 0;
}

void func_0201c528(s32 a, s32 b, Unk02012f58 *m) {
    s32 t1;
    s32 t2;
    s32 x;
    s32 y;
    s32 z;

    t1 = (s32) (((s64) (0x1000 - b) * (s64) 0x555 + 0x800) >> 12);
    t2 = (s32) (((s64) a * (s64) 0x93d + 0x800) >> 12);
    y = t1 + t2;
    z = t1 - t2;
    x = t1 + b;
    m->mUnk_00[0].x = x;
    m->mUnk_00[1].x = y;
    m->mUnk_00[2].x = z;
    m->mUnk_00[3].x = 0;
    m->mUnk_00[0].y = z;
    m->mUnk_00[1].y = x;
    m->mUnk_00[2].y = y;
    m->mUnk_00[3].y = 0;
    m->mUnk_00[0].z = y;
    m->mUnk_00[1].z = z;
    m->mUnk_00[2].z = x;
    m->mUnk_00[3].z = 0;
}
