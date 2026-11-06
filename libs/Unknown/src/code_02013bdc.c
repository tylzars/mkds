#include "code_02013bdc.h"
#include "code_02013740.h"
#include "code_02013b3c.h"
#include "code_02147cd8.h"
#include "code_02013bbc.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"

void func_02015e6c(Unk020152bc *a, void *b, Unk020152bc_c *c) {
    u32 i;

    a->mUnk_0c = data_021617d4;
    a->mUnk_19 = c->mUnk_17;
    a->mUnk_08 = b;
    for (i = 0; i < a->mUnk_19; i++) {
        a->mUnk_1a[i] = i | 0x100;
    }
}

void func_02015e28(u32 *a, Unk02015e28 *b, u32 c) {
    Unk02015e28_b *p;
    u32 n;

    p = b->mUnk_08;
    n = (b->mUnk_00 >> 12) * p->mUnk_06 + c;
    *a = p->mUnk_0c[n >> 5] & (1 << (n & 0x1f));
}

void func_02015d68(Unk020152bc *a, Unk02015d68_b *b, Unk02015428_c *c) {
    volatile u16 v;
    u8 *r;
    u8 *tab;
    s32 k;
    u32 i;

    r = (u8 *) c + c->mUnk_08;
    a->mUnk_0c = data_021617e0;
    a->mUnk_19 = c->mUnk_18;
    a->mUnk_08 = b;
    v = 0;
    MIi_CpuClear16(v, a->mUnk_1a, a->mUnk_19 * 2);
    for (i = 0; i < b->mUnk_0d; i++) {
        tab = (u8 *) b + 0xc + b->mUnk_12;
        k = func_02013754(r + 4, (const u32 *) (tab + *(u16 *) (tab + 2) + i * 16));
        if (k >= 0) {
            a->mUnk_1a[k] = i | 0x100;
        }
    }
}

void func_02015c7c(Unk02015b9c_o *a, const u32 *b, Unk02015b9c *c) {
    const Unk02015c7c_e *e;
    u32 v;
    u32 m;
    s32 x;
    s32 y;

    e = func_020138b4((u8 *) a + 0x3c, b);
    v = c->mUnk_10;
    if ((e->mUnk_00 & 0x1c000000) != 0x14000000) {
        m = a->mUnk_08 & 0xffff;
    } else {
        m = a->mUnk_18 & 0xffff;
    }
    c->mUnk_10 = v & 0xc00f0000;
    c->mUnk_10 = c->mUnk_10 | (e->mUnk_00 + m);
    c->mUnk_2c = e->mUnk_04 & 0x7ff;
    c->mUnk_2e = (e->mUnk_04 & 0x3ff800) >> 11;
    x = e->mUnk_04 & 0x7ff;
    y = 0x7ff & (e->mUnk_04 >> 11);
    if (x == c->mUnk_2c) {
        x = 0x1000;
    } else {
        x = FX_Div(x << 12, c->mUnk_2c << 12);
    }
    c->mUnk_30 = x;
    if (y == c->mUnk_2e) {
        y = 0x1000;
    } else {
        y = FX_Div(y << 12, c->mUnk_2e << 12);
    }
    c->mUnk_34 = y;
}

void func_02015c24(Unk02015b9c_o *a, const u32 *b, Unk02015b9c *c) {
    const Unk02015c24_e *e;
    u32 v;
    u32 w;

    e = func_020138b4((u8 *) a + a->mUnk_34, b);
    v = (u16) a->mUnk_2c;
    w = e->mUnk_00;
    if (!(e->mUnk_02 & 1)) {
        w = (u16) (w >> 1);
        v = (u16) (v >> 1);
    }
    c->mUnk_14 = w + v;
}

void func_02015b9c(Unk02015b9c *a, Unk02015b9c_b *b, u32 c) {
    Unk02013b3c_t *p;
    void *r;

    r = b->mUnk_08;
    p = func_02013b3c(r, c, (u32) (b->mUnk_00 << 4) >> 16);
    func_02015c7c(b->mUnk_14, func_02013bcc(r, p->mUnk_02), a);
    if (p->mUnk_03 == 0xff) {
        return;
    }
    func_02015c24(b->mUnk_14, func_02013bbc(r, p->mUnk_03), a);
}

s32 func_02015aa0(const void *a, u32 b, s32 c, u32 d) {
    const u8 *p;
    u32 n;
    u32 k;
    s32 x;
    s32 y;

    if (b & 0x20000000) {
        return c;
    }
    p = a;
    p += c;
    if (b & 0xc0000000) {
        n = b & 0xffff;
        if (b & 0x40000000) {
            if (d & 1) {
                if (d > n) {
                    d = (n >> 1) + 1;
                    goto single;
                }
                d >>= 1;
                goto half;
            }
            d >>= 1;
            goto single;
        }
        if (d & 3) {
            if (d > n) {
                d = (d & 3) + (n >> 2);
                goto single;
            }
            if (d & 1) {
                if (d & 2) {
                    d >>= 2;
                    k = d + 1;
                } else {
                    k = d >> 2;
                    d = k + 1;
                }
                if (b & 0x10000000) {
                    x = ((const s16 *) p)[k];
                    y = ((const s16 *) p)[d];
                } else {
                    x = ((const s32 *) p)[k];
                    y = ((const s32 *) p)[d];
                }
                return (x * 3 + y) >> 2;
            }
            d >>= 2;
            goto half;
        }
        d >>= 2;
    }
single:
    if (b & 0x10000000) {
        return ((const s16 *) p)[d];
    }
    return ((const s32 *) p)[d];
half:
    if (b & 0x10000000) {
        x = ((const s16 *) p)[d];
        y = (&((const s16 *) p)[d])[1];
    } else {
        x = ((const s32 *) p)[d];
        y = (&((const s32 *) p)[d])[1];
    }
    return (x + y) >> 1;
}

u32 func_02015994(const void *a, u32 b, u32 c, u32 d) {
    const u8 *p;
    u32 n;
    u32 k;
    s32 x;
    s32 y;
    s32 u;
    s32 v;

    if (b & 0x20000000) {
        return c;
    }
    p = a;
    p += c;
    if (b & 0xc0000000) {
        n = b & 0xffff;
        if (b & 0x40000000) {
            if (d & 1) {
                if (d > n) {
                    d = (n >> 1) + 1;
                    goto single;
                }
                k = d >> 1;
                goto half;
            }
            d >>= 1;
            goto single;
        }
        if (d & 3) {
            if (d > n) {
                d = (d & 3) + (n >> 2);
                goto single;
            }
            if (d & 1) {
                if (d & 2) {
                    n = d >> 2;
                    k = n + 1;
                } else {
                    k = d >> 2;
                    n = k + 1;
                }
                x = ((const Unk0201456c_16 *) p)[k].mUnk_00;
                y = ((const Unk0201456c_16 *) p)[n].mUnk_00;
                u = ((const Unk0201456c_16 *) p)[k].mUnk_02;
                v = ((const Unk0201456c_16 *) p)[n].mUnk_02;
                x = x * 3 + y;
                u = u * 3 + v;
                return (x >> 2 & 0xffff) | (u >> 2 << 16);
            }
            k = d >> 2;
            goto half;
        }
        d >>= 2;
    }
single:
    return ((const u32 *) p)[d];
half:
    x = ((const Unk0201456c_16 *) p)[k].mUnk_00;
    y = ((const Unk0201456c_16 *) p + k)[1].mUnk_00;
    u = ((const Unk0201456c_16 *) p + k)->mUnk_02;
    v = ((const Unk0201456c_16 *) p + k)[1].mUnk_02;
    return (((x + y) >> 1) & 0xffff) | ((u + v) >> 1 << 16);
}

void func_02015894(const Unk02015894_a *a, u16 b, u32 c, Unk02015788 *d) {
    const u8 *t;
    const Unk02015894_e *e;
    u32 f;
    s32 x;
    s32 y;
    u32 z;

    t = (const u8 *) a + 8 + a->mUnk_0e;
    e = (const Unk02015894_e *) (t + 4 + *(u16 *) t * b);
    f = d->mUnk_00;
    x = func_02015aa0((const u8 *) a, e->mUnk_18, e->mUnk_1c, c);
    y = func_02015aa0((const u8 *) a, e->mUnk_20, e->mUnk_24, c);
    if (x == 0 && y == 0) {
        f |= 4;
    } else {
        d->mUnk_24 = x;
        d->mUnk_28 = y;
        f &= ~4;
    }
    z = func_02015994((const u8 *) a, e->mUnk_10, e->mUnk_14, c);
    if (z == 0x10000000) {
        f |= 2;
    } else {
        d->mUnk_20 = z;
        d->mUnk_22 = z >> 16;
        f &= ~2;
    }
    x = func_02015aa0((const u8 *) a, e->mUnk_00, e->mUnk_04, c);
    y = func_02015aa0((const u8 *) a, e->mUnk_08, e->mUnk_0c, c);
    if (x == 0x1000 && y == 0x1000) {
        f |= 1;
    } else {
        d->mUnk_18 = x;
        d->mUnk_1c = y;
        f &= ~1;
    }
    d->mUnk_00 = f;
}

void func_020157d8(Unk020152bc *a, Unk02015428_b *b, Unk02015428_c *c) {
    volatile u16 v;
    u8 *r;
    u8 *tab;
    s32 k;
    u32 i;

    r = (u8 *) c + c->mUnk_08;
    a->mUnk_0c = data_021617dc;
    a->mUnk_19 = c->mUnk_18;
    v = 0;
    MIi_CpuClear16(v, a->mUnk_1a, a->mUnk_19 * 2);
    for (i = 0; i < b->mUnk_09; i++) {
        tab = (u8 *) b + 8 + b->mUnk_0e;
        k = func_02013754(r + 4, (const u32 *) (tab + *(u16 *) (tab + 2) + i * 16));
        if (k >= 0) {
            a->mUnk_1a[k] = i | 0x100;
        }
    }
}

void func_02015788(Unk02015788 *a, Unk02015788_s *b, u32 c) {
    func_02015894(b->mUnk_08, c, b->mUnk_00 >> 12, a);
    a->mUnk_10 &= ~0xc0000000;
    a->mUnk_10 |= 0x40000000;
    a->mUnk_00 |= 8;
}

u16 func_020155d8(const void *a, u32 b, u32 c) {
    u32 x;
    u32 d;
    u32 k;
    u32 y;
    const u16 *h;
    const u8 *p;
    u32 n;

    if (b & 0x20000000) {
        return b;
    }
    p = a;
    h = (const u16 *) (p + (b & 0xffff));
    if (!(b & 0xc0000000)) {
        return h[c];
    }
    n = (b & 0x1fff0000) >> 16;
    if (b & 0x40000000) {
        if (c & 1) {
            if (c > n) {
                return (&h[n >> 1])[1];
            }
            k = c >> 1;
            goto half;
        }
        return h[c >> 1];
    }
    if (c & 3) {
        if (c > n) {
            return (&h[n >> 2])[c & 3];
        }
        if (c & 1) {
            if (c & 2) {
                d = c >> 2;
                c = d + 1;
            } else {
                c >>= 2;
                d = c + 1;
            }
            x = h[c];
            return ((x & 0x7c1f) * 3 + ((u32) h[d] & 0x7c1f)) >> 2 & 0x7c1f |
                   ((x & 0x3e0) * 3 + ((u32) h[d] & 0x3e0)) >> 2 & 0x3e0;
        }
        k = c >> 2;
        goto half;
    }
    return h[c >> 2];
half:
    x = h[k];
    y = (&h[k])[1];
    return ((x & 0x7c1f) + (y & 0x7c1f)) >> 1 & 0x7c1f | ((x & 0x3e0) + (y & 0x3e0)) >> 1 & 0x3e0;
}

u16 func_020154e4(const void *a, u32 b, u32 c) {
    const u8 *p;
    u32 d;
    u32 n;

    if (b & 0x20000000) {
        return b;
    }
    p = a;
    p += b & 0xffff;
    if (!(b & 0xc0000000)) {
        return p[c];
    }
    n = (b & 0x1fff0000) >> 16;
    if (b & 0x40000000) {
        if (c & 1) {
            if (c > n) {
                return (&p[n >> 1])[1];
            }
            return (p[c >> 1] + (&p[c >> 1])[1]) >> 1;
        }
        return p[c >> 1];
    }
    if (c & 3) {
        if (c > n) {
            return (&p[n >> 2])[c & 3];
        }
        if (c & 1) {
            if (c & 2) {
                d = c >> 2;
                c = d + 1;
            } else {
                c >>= 2;
                d = c + 1;
            }
            n = p[d];
            c = p[c];
            return (c * 3 + n) >> 2;
        }
        return (p[c >> 2] + (&p[c >> 2])[1]) >> 1;
    }
    return p[c >> 2];
}

void func_02015428(Unk020152bc *a, Unk02015428_b *b, Unk02015428_c *c) {
    u8 *r;
    u32 i;
    volatile u16 v;
    s32 k;
    u8 *tab;

    r = (u8 *) c + c->mUnk_08;
    a->mUnk_0c = data_021617e4;
    a->mUnk_19 = c->mUnk_18;
    v = 0;
    MIi_CpuClear16(v, a->mUnk_1a, a->mUnk_19 * 2);
    for (i = 0; i < b->mUnk_09; i++) {
        tab = (u8 *) b + 8 + b->mUnk_0e;
        k = func_02013754(r + 4, (const u32 *) (tab + *(u16 *) (tab + 2) + i * 16));
        if (k >= 0) {
            a->mUnk_1a[k] = i | 0x100;
        }
    }
}

void func_02015358(Unk02015358 *a, Unk02015358_s *b, u32 c) {
    u32 x;
    u8 *t;
    Unk02015358_b *p;
    u32 f;
    Unk02015358_e *e;

    p = b->mUnk_08;
    f = b->mUnk_00 >> 12;
    t = (u8 *) p + 8 + p->mUnk_0e;
    e = (Unk02015358_e *) (t + 4 + *(u16 *) t * (u16) c);
    x = func_020155d8(p, e->mUnk_00, f);
    a->mUnk_04 = (a->mUnk_04 & 0x8000) | x | (func_020155d8(p, e->mUnk_04, f) << 16);
    x = func_020155d8(p, e->mUnk_0c, f);
    a->mUnk_08 = (a->mUnk_08 & 0x8000) | func_020155d8(p, e->mUnk_08, f) | (x << 16);
    a->mUnk_0c = (a->mUnk_0c & ~0x1f0000) | (func_020154e4(p, e->mUnk_10, f) << 16);
}

void func_020152bc(Unk020152bc *a, Unk02014c5c *b, Unk020152bc_c *c) {
    volatile u16 v;
    u32 i;
    u16 *q;

    a->mUnk_08 = b;
    a->mUnk_0c = data_021617d8;
    a->mUnk_19 = c->mUnk_17;
    v = 0;
    MIi_CpuClear16(v, a->mUnk_1a, a->mUnk_19 * 2);
    q = b->mUnk_14;
    for (i = 0; i < b->mUnk_06; i++) {
        a->mUnk_1a[i] = (*(u32 *) ((u8 *) b + q[i]) >> 24) | 0x100;
    }
}

void func_02015274(Unk02014c5c_out *a, Unk02015274 *b, int c) {
    s32 t;
    s32 n;

    t = b->mUnk_00;
    n = b->mUnk_08->mUnk_04 << 12;
    if (t >= n) {
        t = n - 1;
    } else if (t < 0) {
        t = 0;
    }
    func_02014c5c(b->mUnk_08, c, t, a);
}

void func_0201520c(Unk02014c5c_out *o) {
    Unk02170500 *d;
    Unk02170500_d4 *b;
    u8 *t;
    Unk02015044_e *e;
    const u32 *r;

    d = data_02170500;
    b = d->mUnk_d4;
    t = (u8 *) b + b->mUnk_06;
    e = (Unk02015044_e *) ((u8 *) b + *(u32 *) (t + *(u16 *) t * d->mUnk_00[1] + 4));
    if (e->mUnk_00 & 1) {
        o->mUnk_00 |= 4;
        return;
    }
    r = (const u32 *) e->mUnk_04;
    o->mUnk_4c[0] = r[0];
    o->mUnk_4c[1] = r[1];
    o->mUnk_4c[2] = r[2];
}

void func_020151a4(Unk02014c5c_out *o) {
    u32 f;
    Unk02170500_d4 *b;
    u8 *t;
    Unk02170500 *d;
    u32 off;
    u8 *q;
    u8 *m;

    d = data_02170500;
    b = d->mUnk_d4;
    m = d->mUnk_00;
    t = (u8 *) b + b->mUnk_06;
    off = *(u32 *) (t + *(u16 *) t * m[1] + 4);
    f = *(u16 *) ((u8 *) b + off);
    q = (u8 *) b + off + 4;
    if (!(f & 1)) {
        q += 0xc;
    }
    if (!(f & 2)) {
        if (f & 8) {
            q += 4;
        } else {
            q += 0x10;
        }
    }
    d->mUnk_e8(o, q, m, f);
}

void func_02015044(Unk02014c5c_out *o) {
    s32 x;
    Unk02170500 *d;
    s32 y;
    u8 *t;
    Unk02170500_d4 *b;
    s32 i;
    Unk02015044_e *e;
    const s16 *q;

    d = data_02170500;
    b = d->mUnk_d4;
    t = (u8 *) b + b->mUnk_06;
    e = (Unk02015044_e *) ((u8 *) b + *(u32 *) (t + *(u16 *) t * d->mUnk_00[1] + 4));
    q = e->mUnk_04;
    if (!(e->mUnk_00 & 1)) {
        q += 6;
    }
    if (!(e->mUnk_00 & 2)) {
        if (e->mUnk_00 & 8) {
            i = (e->mUnk_00 & 0xf0) >> 4;
            x = q[0];
            y = q[1];
            MI_Zero36B(o->mUnk_28);
            o->mUnk_28[i] = (e->mUnk_00 & 0x100) ? -0x1000 : 0x1000;
            o->mUnk_28[data_02152c30[i][0]] = x;
            o->mUnk_28[data_02152c31[i][0]] = y;
            if (e->mUnk_00 & 0x200) {
                y = -y;
            }
            o->mUnk_28[data_02152c32[i][0]] = y;
            if (e->mUnk_00 & 0x400) {
                x = -x;
            }
            o->mUnk_28[data_02152c33[i][0]] = x;
        } else {
            o->mUnk_28[0] = e->mUnk_02;
            o->mUnk_28[1] = q[0];
            o->mUnk_28[2] = q[1];
            o->mUnk_28[3] = q[2];
            o->mUnk_28[4] = q[3];
            o->mUnk_28[5] = q[4];
            o->mUnk_28[6] = q[5];
            o->mUnk_28[7] = q[6];
            o->mUnk_28[8] = q[7];
        }
    } else {
        o->mUnk_00 |= 2;
    }
}

void func_02014c5c(Unk02014c5c *obj, int idx, s32 a, Unk02014c5c_out *o) {
    s32 t[3][2];
    s32 m[2][3];
    int use;
    u32 flags;
    const u32 *p;
    const u32 *q;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 x4;
    s32 x5;

    q = (const u32 *) ((u8 *) obj + obj->mUnk_14[idx]);
    flags = q[0];
    if (flags & 1) {
        o->mUnk_00 = 7;
    } else {
        p = q + 1;
        if ((a & 0xfff) && (obj->mUnk_08 & 1)) {
            use = 1;
        } else {
            use = 0;
        }
        o->mUnk_00 = 0;
        if (!(flags & 6)) {
            if (!(flags & 8)) {
                if (use) {
                    func_02014954(&o->mUnk_4c[0], a, p, obj);
                } else {
                    func_02014ad0(&o->mUnk_4c[0], a, p, obj);
                }
                p += 2;
            } else {
                o->mUnk_4c[0] = *p++;
            }
            if (!(flags & 0x10)) {
                if (use) {
                    func_02014954(&o->mUnk_4c[1], a, p, obj);
                } else {
                    func_02014ad0(&o->mUnk_4c[1], a, p, obj);
                }
                p += 2;
            } else {
                o->mUnk_4c[1] = *p++;
            }
            if (!(flags & 0x20)) {
                if (use) {
                    func_02014954(&o->mUnk_4c[2], a, p, obj);
                } else {
                    func_02014ad0(&o->mUnk_4c[2], a, p, obj);
                }
                p += 2;
            } else {
                o->mUnk_4c[2] = *p++;
            }
        } else if (flags & 2) {
            o->mUnk_00 |= 4;
        } else {
            func_0201520c(o);
        }
        if (!(flags & 0xc0)) {
            if (!(flags & 0x100)) {
                if (use) {
                    func_02013e18(o->mUnk_28, a, p, obj);
                } else {
                    func_02014164(o->mUnk_28, a, p, obj);
                }
                p += 2;
            } else {
                if (func_02013c78(o->mUnk_28, (const s16 *) ((u8 *) obj + obj->mUnk_0c),
                                  (const s16 *) ((u8 *) obj + obj->mUnk_10), *p)) {
                    x5 = o->mUnk_28[5];
                    x0 = o->mUnk_28[0];
                    x3 = o->mUnk_28[3];
                    x2 = o->mUnk_28[2];
                    x1 = o->mUnk_28[1];
                    x4 = o->mUnk_28[4];
                    o->mUnk_28[6] = (x1 * x5 - x2 * x4) >> 12;
                    o->mUnk_28[7] = (x2 * x3 - x0 * x5) >> 12;
                    o->mUnk_28[8] = (x0 * x4 - x1 * x3) >> 12;
                }
                p += 1;
            }
        } else if (flags & 0x40) {
            o->mUnk_00 |= 2;
        } else {
            func_02015044(o);
        }
        if (!(flags & 0x600)) {
            if (!(flags & 0x800)) {
                if (use) {
                    func_0201456c(t[0], a, p, obj);
                } else {
                    func_02014724(t[0], a, p, obj);
                }
                m[0][0] = t[0][0];
                m[1][0] = t[0][1];
            } else {
                m[0][0] = p[0];
                m[1][0] = p[1];
            }
            if (!(flags & 0x1000)) {
                if (use) {
                    func_0201456c(t[1], a, p + 2, obj);
                } else {
                    func_02014724(t[1], a, p + 2, obj);
                }
                m[0][1] = t[1][0];
                m[1][1] = t[1][1];
            } else {
                m[0][1] = p[2];
                m[1][1] = p[3];
            }
            if (!(flags & 0x2000)) {
                if (use) {
                    func_0201456c(t[2], a, p + 4, obj);
                } else {
                    func_02014724(t[2], a, p + 4, obj);
                }
                m[0][2] = t[2][0];
                m[1][2] = t[2][1];
            } else {
                m[0][2] = p[4];
                m[1][2] = p[5];
            }
        } else if (flags & 0x200) {
            o->mUnk_00 |= 1;
        } else {
            func_020151a4(o);
            return;
        }
    }
    data_02170500->mUnk_e8(o, m, data_02170500->mUnk_00, (o->mUnk_00 & 1) ? 4 : 0);
}

void func_02014ad0(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj) {
    s32 x;
    u32 n;
    const u8 *tab;
    u32 w;
    u32 k;
    u32 i;
    s32 y;
    u32 j;

    i = a >> 12;
    tab = (const u8 *) obj + p[1];
    w = p[0];
    if (w & 0xc0000000) {
        n = (w & 0x1fff0000) >> 16;
        if (w & 0x40000000) {
            if (i & 1) {
                if (i > n) {
                    i = (n >> 1) + 1;
                    goto single;
                }
                k = i >> 1;
            } else {
                i >>= 1;
                goto single;
            }
        } else {
            if (i & 3) {
                if (i > n) {
                    i = (i & 3) + (n >> 2);
                    goto single;
                }
                if (i & 1) {
                    if (i & 2) {
                        j = i >> 2;
                        k = j + 1;
                    } else {
                        k = i >> 2;
                        j = k + 1;
                    }
                    if (w & 0x20000000) {
                        x = ((const s16 *) tab)[k];
                        y = ((const s16 *) tab)[j];
                        *out = (x + x + x + y) >> 2;
                    } else {
                        x = ((const s32 *) tab)[k];
                        y = ((const s32 *) tab)[j];
                        *out = (s32) (((s64) x + x + x + y) >> 2);
                    }
                    return;
                }
                k = i >> 2;
            } else {
                i >>= 2;
                goto single;
            }
        }
        if (w & 0x20000000) {
            x = ((const s16 *) tab)[k];
            y = (&((const s16 *) tab)[k])[1];
            *out = (x + y) >> 1;
        } else {
            x = ((const s32 *) tab)[k];
            y = (&((const s32 *) tab)[k])[1];
            *out = (x >> 1) + (y >> 1);
        }
        return;
    }
single:
    if (w & 0x20000000) {
        *out = ((const s16 *) tab)[i];
    } else {
        *out = ((const s32 *) tab)[i];
    }
}

void func_02014954(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj) {
    u32 n;
    const u8 *tab;
    s32 q;
    s32 y;
    s32 sh;
    u32 w;
    s32 m;
    u32 i;
    s32 x;

    i = a >> 12;
    tab = (const u8 *) obj + p[1];
    w = p[0];
    if (i == obj->mUnk_04 - 1) {
        if (w & 0xc0000000) {
            if (w & 0x40000000) {
                i = (i & 1) + (i >> 1);
            } else {
                i = (i & 3) + (i >> 2);
            }
        }
        if (obj->mUnk_08 & 2) {
            sh = a & 0xfff;
            if (w & 0x20000000) {
                x = ((const s16 *) tab)[i];
                q = ((const s16 *) tab)[0];
            } else {
                x = ((const s32 *) tab)[i];
                q = ((const s32 *) tab)[0];
            }
            *out = x + ((sh * (q - x)) >> 12);
        } else {
            if (w & 0x20000000) {
                *out = ((const s16 *) tab)[i];
            } else {
                *out = ((const s32 *) tab)[i];
            }
        }
        return;
    }
    if (w & 0xc0000000) {
        n = (w & 0x1fff0000) >> 16;
        if (w & 0x40000000) {
            if (i >= n) {
                i = n >> 1;
                goto last;
            }
            i >>= 1;
            q = a & 0x1fff;
            m = 2;
            sh = 1;
        } else {
            if (i >= n) {
                i = (i & 3) + (i >> 2);
                goto last;
            }
            i >>= 2;
            q = a & 0x3fff;
            m = 4;
            sh = 2;
        }
    } else {
    last:
        q = a & 0xfff;
        m = 1;
        sh = 0;
    }
    if (w & 0x20000000) {
        x = ((const s16 *) tab)[i];
        y = (&((const s16 *) tab)[i])[1];
    } else {
        x = ((const s32 *) tab)[i];
        y = (&((const s32 *) tab)[i])[1];
    }
    *out = (x * m + ((q * (y - x)) >> 12)) >> sh;
}

void func_02014724(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj) {
    u32 w;
    const u8 *tab;
    u32 k;
    s32 y;
    u32 n;
    s32 x;
    const Unk0201456c_16 *e16;
    const Unk0201456c_32 *e32;
    u32 i;

    i = a >> 12;
    tab = (const u8 *) obj + p[1];
    w = p[0];
    if (w & 0xc0000000) {
        n = (w & 0x1fff0000) >> 16;
        if (w & 0x40000000) {
            if (i & 1) {
                if (i > n) {
                    i = (n >> 1) + 1;
                    goto single;
                }
                k = i >> 1;
                goto half;
            }
            i >>= 1;
            goto single;
        }
        if (i & 3) {
            if (i > n) {
                i = (i & 3) + (n >> 2);
                goto single;
            }
            if (i & 1) {
                if (i & 2) {
                    i >>= 2;
                    k = i + 1;
                } else {
                    k = i >> 2;
                    i = k + 1;
                }
                if (w & 0x20000000) {
                    e16 = (const Unk0201456c_16 *) tab + k;
                    x = ((const Unk0201456c_16 *) tab)[k].mUnk_00;
                    y = ((const Unk0201456c_16 *) tab)[i].mUnk_00;
                    out[0] = (x + (x << 1) + y) >> 2;
                    x = e16->mUnk_02;
                    y = ((const Unk0201456c_16 *) tab + i)->mUnk_02;
                    out[1] = (x + (x << 1) + y) >> 2;
                } else {
                    e32 = (const Unk0201456c_32 *) tab + k;
                    x = ((const Unk0201456c_32 *) tab)[k].mUnk_00;
                    y = ((const Unk0201456c_32 *) tab)[i].mUnk_00;
                    out[0] = (s32) (((s64) x + x + x + y) >> 2);
                    x = e32->mUnk_04;
                    y = ((const Unk0201456c_32 *) tab + i)->mUnk_04;
                    out[1] = (s32) (((s64) x + x + x + y) >> 2);
                }
                return;
            }
            k = i >> 2;
            goto half;
        }
        i >>= 2;
    }
single:
    if (w & 0x20000000) {
        out[0] = ((const Unk0201456c_16 *) tab)[i].mUnk_00;
        out[1] = ((const Unk0201456c_16 *) tab)[i].mUnk_02;
    } else {
        out[0] = ((const Unk0201456c_32 *) tab)[i].mUnk_00;
        out[1] = ((const Unk0201456c_32 *) tab)[i].mUnk_04;
    }
    return;
half:
    if (w & 0x20000000) {
        e16 = (const Unk0201456c_16 *) tab + k;
        out[0] = (e16->mUnk_00 + e16[1].mUnk_00) >> 1;
        out[1] = (e16->mUnk_02 + e16[1].mUnk_02) >> 1;
    } else {
        e32 = (const Unk0201456c_32 *) tab + k;
        out[0] = (e32->mUnk_00 + e32[1].mUnk_00) >> 1;
        out[1] = (e32->mUnk_04 + e32[1].mUnk_04) >> 1;
    }
}

void func_0201456c(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj) {
    const u8 *tab;
    u32 w;
    s32 y0;
    u32 i;
    u32 j;
    s32 q;
    s32 m;
    s32 sh;
    s32 y1;
    s32 x0;
    s32 x1;
    u32 n;

    i = a >> 12;
    tab = (const u8 *) obj + p[1];
    w = p[0];
    if (i == obj->mUnk_04 - 1) {
        if (w & 0xc0000000) {
            if (w & 0x40000000) {
                i = (i & 1) + (i >> 1);
            } else {
                i = (i & 3) + (i >> 2);
            }
        }
        if (obj->mUnk_08 & 2) {
            j = 0;
            goto last;
        }
        if (w & 0x20000000) {
            out[0] = ((const Unk0201456c_16 *) tab)[i].mUnk_00;
            out[1] = ((const Unk0201456c_16 *) tab)[i].mUnk_02;
        } else {
            out[0] = ((const Unk0201456c_32 *) tab)[i].mUnk_00;
            out[1] = ((const Unk0201456c_32 *) tab)[i].mUnk_04;
        }
        return;
    }
    if (w & 0xc0000000) {
        n = (w & 0x1fff0000) >> 16;
        if (w & 0x40000000) {
            if (i >= n) {
                i = n >> 1;
                j = i + 1;
                goto last;
            }
            i >>= 1;
            j = i + 1;
            q = a & 0x1fff;
            m = 2;
            sh = 1;
        } else {
            if (i >= n) {
                i = (i & 3) + (i >> 2);
                j = i + 1;
                goto last;
            }
            i >>= 2;
            j = i + 1;
            q = a & 0x3fff;
            m = 4;
            sh = 2;
        }
    } else {
        j = i + 1;
    last:
        q = a & 0xfff;
        m = 1;
        sh = 0;
    }
    if (w & 0x20000000) {
        x0 = ((const Unk0201456c_16 *) tab)[i].mUnk_00;
        x1 = ((const Unk0201456c_16 *) tab)[i].mUnk_02;
        y0 = ((const Unk0201456c_16 *) tab)[j].mUnk_00;
        y1 = ((const Unk0201456c_16 *) tab)[j].mUnk_02;
    } else {
        x0 = ((const Unk0201456c_32 *) tab)[i].mUnk_00;
        x1 = ((const Unk0201456c_32 *) tab)[i].mUnk_04;
        y0 = ((const Unk0201456c_32 *) tab)[j].mUnk_00;
        y1 = ((const Unk0201456c_32 *) tab)[j].mUnk_04;
    }
    out[0] = (x0 * m + ((q * (y0 - x0)) >> 12)) >> sh;
    out[1] = (x1 * m + ((q * (y1 - x1)) >> 12)) >> sh;
}

void func_02014164(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj) {
    s32 t[9];
    s32 u[9];
    const s16 *s0;
    const s16 *s1;
    u32 w;
    const u16 *tab;
    u32 i;
    u32 n;
    int k;
    u32 i0;
    u32 i1;
    int f;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 x4;
    s32 x5;

    i = a >> 12;
    s0 = (const s16 *) ((u8 *) obj + obj->mUnk_0c);
    s1 = (const s16 *) ((u8 *) obj + obj->mUnk_10);
    w = p[0];
    tab = (const u16 *) ((u8 *) obj + p[1]);
    if (w & 0xc0000000) {
        n = (w & 0x1fff0000) >> 16;
        if (w & 0x40000000) {
            if (i & 1) {
                if (i > n) {
                    i = (n >> 1) + 1;
                    goto single;
                }
                k = i >> 1;
            } else {
                i >>= 1;
                goto single;
            }
        } else {
            if (i & 3) {
                if (i > n) {
                    i = (i & 3) + (n >> 2);
                    goto single;
                }
                if (i & 1) {
                    f = 0;
                    if (i & 2) {
                        i1 = i >> 2;
                        i0 = i1 + 1;
                    } else {
                        i0 = i >> 2;
                        i1 = i0 + 1;
                    }
                    f |= func_02013c78(out, s0, s1, tab[i0]);
                    f |= func_02013c78(t, s0, s1, tab[i1]);
                    out[0] = out[0] * 3 + t[0];
                    out[1] = out[1] * 3 + t[1];
                    out[2] = out[2] * 3 + t[2];
                    out[3] = out[3] * 3 + t[3];
                    out[4] = out[4] * 3 + t[4];
                    out[5] = out[5] * 3 + t[5];
                    VEC_Normalize((Vec3 *) out, (Vec3 *) out);
                    VEC_Normalize((Vec3 *) (out + 3), (Vec3 *) (out + 3));
                    if (f == 0) {
                        out[6] = out[6] * 3 + t[6];
                        out[7] = out[7] * 3 + t[7];
                        out[8] = out[8] * 3 + t[8];
                        VEC_Normalize((Vec3 *) (out + 6), (Vec3 *) (out + 6));
                    } else {
                        x5 = out[5];
                        x0 = out[0];
                        x3 = out[3];
                        x2 = out[2];
                        x1 = out[1];
                        x4 = out[4];
                        out[6] = (x1 * x5 - x2 * x4) >> 12;
                        out[7] = (x2 * x3 - x0 * x5) >> 12;
                        out[8] = (x0 * x4 - x1 * x3) >> 12;
                    }
                    return;
                }
                k = i >> 2;
            } else {
                i >>= 2;
                goto single;
            }
        }
        f = 0;
        f |= func_02013c78(out, s0, s1, tab[k]);
        f |= func_02013c78(u, s0, s1, *(tab + k + 1));
        out[0] += u[0];
        out[1] += u[1];
        out[2] += u[2];
        out[3] += u[3];
        out[4] += u[4];
        out[5] += u[5];
        VEC_Normalize((Vec3 *) out, (Vec3 *) out);
        VEC_Normalize((Vec3 *) (out + 3), (Vec3 *) (out + 3));
        if (f == 0) {
            out[6] += u[6];
            out[7] += u[7];
            out[8] += u[8];
            VEC_Normalize((Vec3 *) (out + 6), (Vec3 *) (out + 6));
        } else {
            x5 = out[5];
            x0 = out[0];
            x3 = out[3];
            x2 = out[2];
            x1 = out[1];
            x4 = out[4];
            out[6] = (x1 * x5 - x2 * x4) >> 12;
            out[7] = (x2 * x3 - x0 * x5) >> 12;
            out[8] = (x0 * x4 - x1 * x3) >> 12;
        }
        return;
    }
single:
    if (func_02013c78(out, s0, s1, tab[i]) == 0) {
        return;
    }
    x5 = out[5];
    x0 = out[0];
    x3 = out[3];
    x2 = out[2];
    x1 = out[1];
    x4 = out[4];
    out[6] = (x1 * x5 - x2 * x4) >> 12;
    out[7] = (x2 * x3 - x0 * x5) >> 12;
    out[8] = (x0 * x4 - x1 * x3) >> 12;
}

void func_02013e18(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj) {
    s32 r;
    s32 x1;
    u32 n;
    s32 t[9];
    s32 u[9];
    u32 f;
    s32 x5;
    s32 x3;
    s32 x4;
    u32 w;
    const s16 *s0;
    s32 h;
    const s16 *s1;
    u32 i;
    s32 q;
    s32 m;
    s32 x0;
    const u16 *tab;
    s32 x2;
    u32 j;

    i = a >> 12;
    s0 = (const s16 *) ((u8 *) obj + obj->mUnk_0c);
    s1 = (const s16 *) ((u8 *) obj + obj->mUnk_10);
    w = p[0];
    tab = (const u16 *) ((u8 *) obj + p[1]);
    if (i == obj->mUnk_04 - 1) {
        if (w & 0xc0000000) {
            if (w & 0x40000000) {
                i = (i & 1) + (i >> 1);
            } else {
                i = (i & 3) + (i >> 2);
            }
        }
        if (obj->mUnk_08 & 2) {
            j = 0;
            goto interp1;
        }
        if (func_02013c78(out, s0, s1, tab[i]) == 0) {
            return;
        }
        x5 = out[5];
        x0 = out[0];
        x3 = out[3];
        x1 = out[1];
        x2 = out[2];
        x4 = out[4];
        out[6] = (x1 * x5 - x2 * x4) >> 12;
        out[7] = (x2 * x3 - x0 * x5) >> 12;
        out[8] = (x0 * x4 - x1 * x3) >> 12;
        return;
    }
    if (w & 0xc0000000) {
        n = (w & 0x1fff0000) >> 16;
        if (w & 0x40000000) {
            if (i >= n) {
                i = n >> 1;
                j = i + 1;
                goto interp1;
            }
            i >>= 1;
            j = i + 1;
            m = 2;
            q = a & 0x1fff;
        } else {
            if (i >= n) {
                i = (i & 3) + (i >> 2);
                j = i + 1;
                goto interp1;
            }
            i >>= 2;
            j = i + 1;
            q = a & 0x3fff;
            m = 4;
        }
        goto interp;
    } else {
        j = i + 1;
    }
interp1:
    m = 1;
    q = a & 0xfff;
interp:
    f = 0;
    f |= func_02013c78(t, s0, s1, tab[i]);
    f |= func_02013c78(u, s0, s1, tab[j]);
    out[0] = t[0] * m + ((q * (u[0] - t[0])) >> 12);
    out[1] = t[1] * m + ((q * (u[1] - t[1])) >> 12);
    out[2] = t[2] * m + ((q * (u[2] - t[2])) >> 12);
    out[3] = t[3] * m + ((q * (u[3] - t[3])) >> 12);
    out[4] = t[4] * m + ((q * (u[4] - t[4])) >> 12);
    out[5] = t[5] * m + ((q * (u[5] - t[5])) >> 12);
    VEC_Normalize((Vec3 *) out, (Vec3 *) out);
    VEC_Normalize((Vec3 *) (out + 3), (Vec3 *) (out + 3));
    if (f == 0) {
        out[6] = t[6] * m + ((q * (u[6] - t[6])) >> 12);
        out[7] = t[7] * m + ((q * (u[7] - t[7])) >> 12);
        r = t[8];
        out[8] = t[8] * m + ((q * (u[8] - r)) >> 12);
        VEC_Normalize((Vec3 *) (out + 6), (Vec3 *) (out + 6));
    } else {
        h = out[5];
        x0 = out[0];
        x2 = out[2];
        x5 = h;
        x3 = out[3];
        x1 = out[1];
        x4 = out[4];
        out[6] = (x1 * x5 - x2 * x4) >> 12;
        out[7] = (x2 * x3 - x0 * x5) >> 12;
        out[8] = (x0 * x4 - x1 * x3) >> 12;
    }
}

int func_02013c78(s32 *out, const s16 *a, const s16 *b, u32 n) {
    s32 x;
    s32 y;
    s32 v;
    const s16 *w;
    s16 t;
    u32 k;
    s32 z;

    if (n & 0x8000) {
        out[0] = out[1] = out[2] = out[3] = out[4] = out[5] = out[6] = out[7] = out[8] = 0;
        n = (n & 0x7fff) * 3;
        w = a + n;
        z = a[n];
        k = z & 0xf;
        x = w[1];
        y = w[2];
        out[k] = (z & 0x10) ? -0x1000 : 0x1000;
        out[data_02152c30[k][0]] = x;
        out[data_02152c31[k][0]] = y;
        if (w[0] & 0x20) {
            y = -y;
        }
        out[data_02152c32[k][0]] = y;
        if (w[0] & 0x40) {
            x = -x;
        }
        out[data_02152c33[k][0]] = x;
        return 0;
    }
    n = (n & 0x7fff) * 5;
    w = b + n;
    v = w[4];
    out[4] = v >> 3;
    t = v & 7;
    v = b[n];
    out[0] = v >> 3;
    t = (t << 3) | (v & 7);
    v = w[1];
    out[1] = v >> 3;
    t = (t << 3) | (v & 7);
    v = w[2];
    out[2] = v >> 3;
    t = (t << 3) | (v & 7);
    v = w[3];
    out[3] = v >> 3;
    t = (t << 3) | (v & 7);
    out[5] = (t << 19) >> 19;
    return 1;
}

void *func_02013c18(Unk020136f0 *a, u32 b, u32 c) {
    u32 i;
    u32 *p;

    if (a->mUnk_00 == b) {
        for (i = 0; i < a->mUnk_0e; i++) {
            p = func_02013740(a, i);
            if (*p == c) {
                return p;
            }
        }
    }
    return 0;
}

void *func_02013bf8(void *a, u32 b) {
    u8 *p;
    u8 *t;

    p = (u8 *) a + 8;
    t = p + *(u16 *) ((u8 *) a + 0xe);
    return (u8 *) a + *(u32 *) (t + *(u16 *) t * b + 4);
}

void *func_02013bdc(void *a) {
    return func_02013c18(a, 0x30415642, 0x30534956);
}
