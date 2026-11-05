#include "Main/Unknown/code_020f1d70.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "code_02147cd8.h"

void func_020f2b94(void *a0, void *b0, s32 c, s32 d, s32 e, s32 f) {
    Unk020f1d70 *a;
    Unk020eda5c *b;
    s32 n;
    s32 t;
    s32 u;

    a = a0;
    b = b0;
    if (d != 0) {
        a->mUnk_12c = func_020edc9c(b, f, 0x1000, 0x3800, &a->mUnk_130);
    } else {
        Vec3 *p = &a->mUnk_130;
        a->mUnk_12c = func_020edb8c(b, 0x3000, 0x1000, 0x4000, p);
    }
    a->mUnk_13c = a->mUnk_130;
    t = -a->mUnk_130.z;
    u = a->mUnk_130.x;
    a->mUnk_148.z = u;
    a->mUnk_148.x = t;
    a->mUnk_148.y = 0;
    a->mUnk_000.mUnk_5c.x = (s32) (((s64) a->mUnk_130.x * a->mUnk_12c) >> 12);
    a->mUnk_000.mUnk_5c.z = (s32) (((s64) a->mUnk_130.z * a->mUnk_12c) >> 12);
    if (d == 0) {
        Vec3Add(&a->mUnk_000.mUnk_5c, &b->mUnk_010->mUnk_1fc, &a->mUnk_000.mUnk_5c);
    }
    if (b->mUnk_010->mUnk_48 & 1) {
        n = Vec3Dot((const Vec3 *) &b->mUnk_02c.mUnk_0c, &a->mUnk_000.mUnk_5c);
        {
            s32 x, y, z;

            x = (s32) (((s64) b->mUnk_02c.mUnk_0c.x * n) >> 12);
            y = (s32) (((s64) b->mUnk_02c.mUnk_0c.y * n) >> 12);
            z = (s32) (((s64) b->mUnk_02c.mUnk_0c.z * n) >> 12);
            a->mUnk_000.mUnk_5c.x = (s32) (a->mUnk_000.mUnk_5c.x - x);
            a->mUnk_000.mUnk_5c.y -= y;
            a->mUnk_000.mUnk_5c.z -= z;
        }
        Vec3AddScaled(-0x1000, (const Vec3 *) &b->mUnk_02c.mUnk_0c, &a->mUnk_000.mUnk_5c, &a->mUnk_000.mUnk_5c);
    }
    if (a->mUnk_000.mUnk_68.z < 0xccd) {
        a->mUnk_000.mUnk_68.x = 0xccd;
        a->mUnk_000.mUnk_68.y = 0xccd;
        a->mUnk_000.mUnk_68.z = 0xccd;
        if (d != 0) {
            a->mUnk_000.mUnk_50 = b->mUnk_010->mUnk_1b8;
            Vec3AddScaled(a->mUnk_000.mUnk_68.z * 10, (const Vec3 *) &b->mUnk_02c.mUnk_18, &a->mUnk_000.mUnk_50,
                          &a->mUnk_000.mUnk_50);
        }
    }
    if (c < 0) {
        a->mUnk_154 = 0;
        a->mUnk_15c = FALSE;
    } else {
        a->mUnk_154 = c;
        a->mUnk_15c = TRUE;
    }
    a->mUnk_000.mUnk_124 = (void (*)(Unk020f41c4_A *, Vec3 *, Vec3 *)) func_020f1f98;
    a->mUnk_160 = TRUE;
    a->mUnk_158 = e;
    a->mUnk_164 = 4;
}

void func_020f2a6c(Vec3 *a, Vec3 *b, Vec3 *c) {
    s32 n;

    n = b->y * b->y;
    if (n < 0x10) {
        c->x = -a->x;
        c->y = -a->y;
        c->z = -a->z;
        return;
    }
    c->x = b->x >> 2;
    c->y = b->y >> 2;
    c->z = b->z >> 2;
    c->x = a->x - c->x;
    c->z = a->z - c->z;
    n = (s32) (((s64) a->x * b->x) >> 12) + (s32) (((s64) a->z * b->z) >> 12);
    c->y = -(n + c->y);
    c->y = DivFixed12(c->y, b->y);
    if ((s64) c->x * c->x + (s64) c->y * c->y + (s64) c->z * c->z >= 0x10) {
        func_02039860((const Vec3 *) c, c);
    }
}

void func_020f29e8(u32 a) {
    Unk020f1d70 *b;
    Vec3 *p;
    s32 n;

    b = (Unk020f1d70 *) a;
    n = 0;
    p = &b->mUnk_000.mUnk_f0;
    if ((s64) b->mUnk_000.mUnk_5c.x * b->mUnk_000.mUnk_5c.x + (s64) b->mUnk_000.mUnk_5c.y * b->mUnk_000.mUnk_5c.y +
            (s64) b->mUnk_000.mUnk_5c.z * b->mUnk_000.mUnk_5c.z >=
        0x10) {
        n = func_02039860(&b->mUnk_000.mUnk_5c, &b->mUnk_130);
    }
    b->mUnk_12c = n;
    func_020f2a6c(&b->mUnk_130, p, &b->mUnk_13c);
    func_020397a8(&b->mUnk_13c, p, &b->mUnk_148);
    b->mUnk_000.mUnk_124 = (void (*)(Unk020f41c4_A *, Vec3 *, Vec3 *)) func_020f1f98;
}

void func_020f288c(Unk020f1d70 *a, Vec3 *b) {
    Vec3 v;
    Vec3 *p;
    Vec3 *q;
    s32 n;

    p = &a->mUnk_13c;
    q = &a->mUnk_130;
    n = Vec3Dot(b, p);
    v.x = (s32) (((s64) b->x * n) >> 12);
    v.y = (s32) (((s64) b->y * n) >> 12);
    v.z = (s32) (((s64) b->z * n) >> 12);
    a->mUnk_13c.x -= v.x;
    p->y -= v.y;
    p->z -= v.z;
    if (a->mUnk_160 != FALSE) {
        Vec3Sub((const Vec3 *) p, &v, p);
    }
    if ((s64) p->x * p->x + (s64) p->y * p->y + (s64) p->z * p->z >= 0x10) {
        func_02039860((const Vec3 *) p, p);
    }
    n = p->z;
    q->x = p->x;
    q->y = 0;
    q->z = n;
    if ((s64) q->x * q->x + (s64) q->y * q->y + (s64) q->z * q->z >= 0x10) {
        func_02039860((const Vec3 *) q, q);
    }
    func_020397a8((const Vec3 *) q, &a->mUnk_000.mUnk_f0, &a->mUnk_148);
    func_021090c4(&a->mUnk_000.mUnk_00, 0xd5, 0x7f, 0);
}

void func_020f2768(Unk020f1d70 *a, Vec3 *b, Vec3 *c) {
    Vec3 v;
    Vec3 *p;
    s32 n;

    p = &a->mUnk_130;
    n = Vec3Dot(b, p);
    v.x = (s32) (((s64) b->x * n) >> 12);
    v.y = (s32) (((s64) b->y * n) >> 12);
    v.z = (s32) (((s64) b->z * n) >> 12);
    a->mUnk_130.x -= v.x;
    p->y -= v.y;
    p->z -= v.z;
    if (a->mUnk_160 != FALSE) {
        Vec3Sub((const Vec3 *) p, &v, p);
    }
    if ((s64) p->x * p->x + (s64) p->y * p->y + (s64) p->z * p->z >= 0x10) {
        func_02039860((const Vec3 *) p, p);
    }
    a->mUnk_13c = *p;
    func_020397a8((const Vec3 *) p, &a->mUnk_000.mUnk_f0, &a->mUnk_148);
    a->mUnk_000.mUnk_f0.y += 1;
    func_021090c4(&a->mUnk_000.mUnk_00, 0xd5, 0x7f, 0);
}

void func_020f2228(Unk020f1d70 *a, s32 b) {
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v;
    Vec3 *q;
    Vec3 *p;
    Vec3 *r;
    s32 f;
    s32 n;
    BOOL t;
    Vec3 *w;

    q = &a->mUnk_000.mUnk_50;
    p = &a->mUnk_000.mUnk_5c;
    r = &a->mUnk_130;
    Vec3Add((const Vec3 *) p, q, q);
    n = func_01ffdee4(q, &a->mUnk_000.mUnk_0e4, 0, a->mUnk_000.mUnk_dc, a->mUnk_164, a->mUnk_000.mUnk_da, &v1, &v2,
                      (s32 *) &v3, &a->mUnk_000.mUnk_fc, NULL, NULL, NULL, NULL);
    if (n != 0) {
        f = a->mUnk_000.mUnk_fc & 0x80000;
        if (a->mUnk_158 != 0) {
            if (v1.y > 0) {
                q->y += v1.y;
            }
        } else {
            Vec3Add((const Vec3 *) &v1, q, q);
        }
        if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
            t = v2.x == a->mUnk_000.mUnk_f0.x && v2.y == a->mUnk_000.mUnk_f0.y && v2.z == a->mUnk_000.mUnk_f0.z;
            if (t == FALSE) {
                a->mUnk_000.mUnk_f0 = v2;
                a->mUnk_000.mUnk_74 |= 0x100;
                if (f != 0) {
                    n = Vec3Dot(&v2, &a->mUnk_13c);
                    a->mUnk_13c.x = (s32) (a->mUnk_13c.x - (s32) (((s64) v2.x * n) >> 12));
                    a->mUnk_13c.y -= (s32) (((s64) v2.y * n) >> 12);
                    a->mUnk_13c.z -= (s32) (((s64) v2.z * n) >> 12);
                    if ((s64) a->mUnk_13c.x * a->mUnk_13c.x + (s64) a->mUnk_13c.y * a->mUnk_13c.y +
                            (s64) a->mUnk_13c.z * a->mUnk_13c.z >=
                        0x10) {
                        func_02039860(&a->mUnk_13c, &a->mUnk_13c);
                    }
                    *r = a->mUnk_13c;
                } else {
                    func_020f2a6c(r, &v2, &a->mUnk_13c);
                }
                func_020397a8(&a->mUnk_13c, &v2, &a->mUnk_148);
            }
        }
        if (a->mUnk_000.mUnk_fc & 0x214300) {
            if (a->mUnk_158 != 0) {
                q->x += v1.x;
                q->z += v1.z;
            }
            if (f != 0) {
                Vec3Sub(&v3, &a->mUnk_000.mUnk_f0, &v3);
                func_020f288c(a, &v3);
            } else {
                v3.y = 0;
                func_020f2768(a, &v3, NULL);
            }
            a->mUnk_000.mUnk_78 &= ~0x4000;
            if (a->mUnk_15c != FALSE) {
                a->mUnk_000.mUnk_74 |= 0x20;
                a->mUnk_154 -= 1;
            }
        }
        n = a->mUnk_12c;
        p->x = (s32) (((s64) a->mUnk_13c.x * n) >> 12);
        p->y = (s32) (((s64) a->mUnk_13c.y * n) >> 12);
        p->z = (s32) (((s64) a->mUnk_13c.z * n) >> 12);
        if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
            v1.y = q->y - a->mUnk_000.mUnk_0e4.y;
            if (v1.y > 0x5000 && f == 0) {
                v1.y = 0x5000;
            }
            if (v1.y > p->y) {
                p->y = v1.y;
            }
        }
        if (a->mUnk_154 < 0) {
            p->x = (s32) (((s64) p->x * 0x23d) >> 12);
            p->y = (s32) (((s64) p->y * 0x23d) >> 12);
            p->z = (s32) (((s64) p->z * 0x23d) >> 12);
            func_020f6fc4(a, 1);
            return;
        }
        if ((a->mUnk_000.mUnk_fc & 0x8000) && a->mUnk_000.mUnk_44 != 5) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mUnk_12c += (s32) (((s64) (b - a->mUnk_12c) * 0x29) >> 12);
    w = &a->mUnk_000.mUnk_5c;
    if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
        v.x = a->mUnk_000.mUnk_f0.x >> 2;
        v.y = a->mUnk_000.mUnk_f0.y >> 2;
        v.z = a->mUnk_000.mUnk_f0.z >> 2;
        Vec3Sub((const Vec3 *) w, &v, w);
        return;
    }
    n = w->y;
    if (n > 0) {
        w->y -= 0x6b8;
        if (!(a->mUnk_000.mUnk_74 & 0x20000)) {
            return;
        }
        n = w->y;
        if (n > 0xa000) {
            w->y = w->y >> 3;
            return;
        }
        w->y = (s32) (((s64) n * 0xe66) >> 12);
    } else {
        w->y -= 0x333;
        if (w->y >= -0xa000) {
            return;
        }
        if (a->mUnk_000.mUnk_74 & 0x20000) {
            w->y = -0xa000;
        }
    }
}

void func_020f2150(void *a0) {
    Unk020f41c4_A *a;
    Vec3 *p;
    s32 n;

    a = a0;
    p = &a->mUnk_5c;
    n = p->y;
    if (n > 0) {
        p->y -= 0x6b8;
        if (!(a->mUnk_74 & 0x20000)) {
            return;
        }
        n = p->y;
        if (n > 0xa000) {
            p->y = p->y >> 3;
            return;
        }
        p->y = (s32) (((s64) n * 0xe66) >> 12);
    } else {
        p->y -= 0x333;
        if (p->y >= -0xa000) {
            return;
        }
        if (a->mUnk_74 & 0x20000) {
            p->y = -0xa000;
        }
    }
}

void func_020f2028(Unk020f41c4_A *a) {
    Vec3 *p;
    Vec3 v;
    s32 n;

    p = &a->mUnk_5c;
    if (a->mUnk_fc & 0x1e34ef) {
        v.x = a->mUnk_f0.x >> 2;
        v.y = a->mUnk_f0.y >> 2;
        v.z = a->mUnk_f0.z >> 2;
        Vec3Sub(p, &v, p);
        return;
    }
    n = p->y;
    if (n > 0) {
        p->y -= 0x6b8;
        if (!(a->mUnk_74 & 0x20000)) {
            return;
        }
        n = p->y;
        if (n > 0xa000) {
            p->y = p->y >> 3;
            return;
        }
        p->y = (s32) (((s64) n * 0xe66) >> 12);
    } else {
        p->y -= 0x333;
        if (p->y >= -0xa000) {
            return;
        }
        if (a->mUnk_74 & 0x20000) {
            p->y = -0xa000;
        }
    }
}

void func_020f1f98(Unk020f1d70 *a, Vec3 *b, Vec3 *c) {
    Vec3 v;
    s32 n;

    if (c->y > 0) {
        func_020f2768(a, c, c);
    } else {
        v = *c;
        v.y = 0;
        func_020f2768(a, &v, NULL);
    }
    n = a->mUnk_12c;
    a->mUnk_000.mUnk_5c.x = (s32) (((s64) a->mUnk_13c.x * n) >> 12);
    a->mUnk_000.mUnk_5c.y = (s32) (((s64) a->mUnk_13c.y * n) >> 12);
    a->mUnk_000.mUnk_5c.z = (s32) (((s64) a->mUnk_13c.z * n) >> 12);
}

void func_020f1ea4(void *a0, s32 b, s32 c, s32 d) {
    Unk020f1d70 *a;
    s32 n;
    s32 t;
    s32 u;

    a = a0;
    n = 0;
    if ((s64) a->mUnk_000.mUnk_5c.x * a->mUnk_000.mUnk_5c.x + (s64) a->mUnk_000.mUnk_5c.y * a->mUnk_000.mUnk_5c.y +
            (s64) a->mUnk_000.mUnk_5c.z * a->mUnk_000.mUnk_5c.z >=
        0x10) {
        n = func_02039860(&a->mUnk_000.mUnk_5c, &a->mUnk_130);
    }
    a->mUnk_12c = n;
    if (c != 0) {
        a->mUnk_12c = -a->mUnk_12c;
        a->mUnk_130.x = -a->mUnk_130.x;
        a->mUnk_130.y = -a->mUnk_130.y;
        a->mUnk_130.z = -a->mUnk_130.z;
    }
    a->mUnk_13c = a->mUnk_130;
    t = -a->mUnk_130.z;
    u = a->mUnk_130.x;
    a->mUnk_148.z = u;
    a->mUnk_148.x = t;
    a->mUnk_148.y = 0;
    if (b < 0) {
        a->mUnk_154 = 0;
        a->mUnk_15c = FALSE;
    } else {
        a->mUnk_154 = b;
        a->mUnk_15c = TRUE;
    }
    a->mUnk_000.mUnk_124 = (void (*)(Unk020f41c4_A *, Vec3 *, Vec3 *)) func_020f1f98;
    a->mUnk_160 = TRUE;
    a->mUnk_158 = d;
}

void func_020f1d70(void *a0, const Vec3 *b) {
    Unk020f1d70 *a;
    Vec3 *p;
    Vec3 v;
    s32 t;
    s32 s;

    a = a0;
    a->mUnk_130.x = b->x;
    a->mUnk_130.z = b->z;
    p = &a->mUnk_000.mUnk_f0;
    t = Vec3Dot(p, b);
    v.x = b->x - (s32) (((s64) p->x * t) >> 12);
    v.y = b->y - (s32) (((s64) p->y * t) >> 12);
    v.z = b->z - (s32) (((s64) p->z * t) >> 12);
    a->mUnk_13c.x = p->x >> 2;
    a->mUnk_13c.y = p->y >> 2;
    a->mUnk_13c.z = p->z >> 2;
    Vec3Sub(&v, &a->mUnk_13c, &a->mUnk_13c);
    if ((s64) a->mUnk_13c.x * a->mUnk_13c.x + (s64) a->mUnk_13c.y * a->mUnk_13c.y +
            (s64) a->mUnk_13c.z * a->mUnk_13c.z >=
        0x10) {
        func_02039860(&a->mUnk_13c, &a->mUnk_13c);
    }
    s = a->mUnk_12c;
    a->mUnk_000.mUnk_5c.x = (s32) (((s64) a->mUnk_13c.x * s) >> 12);
    a->mUnk_000.mUnk_5c.z = (s32) (((s64) a->mUnk_13c.z * s) >> 12);
    func_020397a8(b, p, &a->mUnk_148);
}
