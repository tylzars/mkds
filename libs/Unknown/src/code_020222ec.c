#include "code_020222ec.h"
#include "code_02021e8c.h"
#include "code_0214cfe4.h"
#include "code_02022a60.h"
#include "code_020220b0.h"
#include "code_020222e0.h"
#include "Main/Unknown/unk_02153000.h"
#include "code_0202210c.h"

static inline u32 func_0202294c_inline(const Unk02022030 *a) {
    return a->mUnk_34 != -1;
}

void func_0202294c(Unk02022030 *a) {
    Unk020229c8 *r;
    Unk02021dc8 *h;
    u32 m;
    Unk02021e40 *t;
    u32 n;
    Unk02021e40 *u;

    if (((Unk02022188 *) a->mUnk_00)->mUnk_04 == 0) {
        return;
    }
    r = func_020222e0(a);
    h = a->mUnk_30;
    a->mUnk_2c = func_02021f1c(h, r->mUnk_00);
    m = a->mUnk_18->mUnk_04 & 0xff;
    func_02022474(&a->mUnk_38, 1);
    if (m != 0) {
        if (m == 2) {
            func_020224c0(&a->mUnk_38, ((Unk020229b4 *) r)->mUnk_04, ((Unk020229b4 *) r)->mUnk_06);
        } else {
            func_02022484(&a->mUnk_38, r->mUnk_04, r->mUnk_08);
            func_020224a4(&a->mUnk_38, r->mUnk_02);
            func_020224c0(&a->mUnk_38, r->mUnk_0c, r->mUnk_0e);
        }
    }
    t = h->mUnk_0c;
    n = t != 0;
    if (n == 0) {
        return;
    }
    n = func_0202294c_inline(a);
    if (n == 0) {
        return;
    }
    u = &((Unk02021e40 *) t->mUnk_04)[r->mUnk_00];
    func_02022a60(a->mUnk_34, u->mUnk_00, u->mUnk_04);
}

void func_02022904(Unk02022030 *a, Unk02021dc8 *b, Unk02021dc8 *c) {
    a->mUnk_30 = c;
    a->mUnk_34 = -1;
    func_02022474(&a->mUnk_38, 1);
    func_020220b0(a);
    func_020228e8(a, b);
}

void func_020228e8(Unk02022030 *a, Unk02021dc8 *b) {
    func_02022030(a, b);
    func_0202294c(a);
}

void func_020228c0(Unk02022030 *a, s32 b) {
    if (func_0202212c(a, b) == 0) {
        return;
    }
    func_0202294c(a);
}

void func_02022898(Unk02022030 *a, u16 b) {
    if (func_0202210c(a, b) == 0) {
        return;
    }
    func_0202294c(a);
}

void func_02022890(Unk02022030 *a, s32 b) {
    a->mUnk_10 = b;
}

static inline u32 func_020224e0_inline2(u32 w) {
    u32 m = w & 0x300;
    return (m == 0x100 || m == 0x300) ? m : (m | (w & 0x30000000));
}

static inline void func_020224e0_inline(const s32 *m, const s32 *in, s32 *out) {
    s32 tmp[2];
    s32 *o;

    o = out;
    if (in == out) {
        o = tmp;
    }
    o[0] = (s32) (((s64) m[2] * in[1] + 0x1000 + (s64) m[0] * in[0]) >> 12);
    o[1] = (s32) (((s64) m[3] * in[1] + 0x1000 + (s64) m[1] * in[0]) >> 12);
    if (o == tmp) {
        out[0] = tmp[0];
        out[1] = tmp[1];
    }
}

u16 func_020224e0(Unk020224e0_o *a, u16 b, Unk020224e0_c *c, s32 *d, s32 *e, u16 f, s32 g) {
    u16 i;
    u16 n;
    s32 v[2];
    s32 mode;
    s32 sq;
    u32 w;
    s32 w2;
    s32 sh;
    s32 sz;
    Unk020224e0_o *o;
    Unk020224e0_s *s;
    s16 x;
    s16 y;
    s32 w3;
    s32 h3;

    n = c->mUnk_00;
    if (b >= n) {
        b = n;
    }
    for (i = 0; i < b; i++) {
        o = &a[i];
        s = &c->mUnk_04[i];
        o->mUnk_00[0] = s->mUnk_00;
        o->mUnk_00[1] = s->mUnk_02;
        o->mUnk_00[2] = s->mUnk_04;
        if (d != 0 || e != 0) {
            w = *(u32 *) o;
            x = (s16) ((w & 0x1ff0000) >> 16);
            if (x > 0xff) {
                x = x | 0xff00;
            }
            v[0] = x << 12;
            y = (s16) (*(u32 *) o & 0xff);
            if (y > 0x7f) {
                y = y | 0xff00;
            }
            v[1] = y << 12;
            if (d != 0) {
                w = *(u32 *) o;
                if (func_020224e0_inline2(w) == 0x300) {
                    w2 = w & 0xc000c000;
                    sh = (w2 & 0xc000) >> 14;
                    sz = (w2 & 0xc0000000) >> 30;
                    v[0] += data_021530d0[sh][sz] << 11;
                    v[1] += data_021530b8[sh][sz] << 11;
                }
                mode = g != 0 ? 0x300 : 0x100;
                sq = mode == 0x300 ? 1 : 0;
                func_020224e0_inline(d, v, v);
                if (mode != 0x100 && mode != 0x300) {
                    *(u32 *) o = (*(u32 *) o & 0xc1fffcff) | mode;
                } else {
                    *(u32 *) o = ((*(u32 *) o & 0xc1fffcff) | mode) | (f << 25);
                }
                w = *(u32 *) o;
                w2 = w & 0xc000c000;
                sh = (w2 & 0xc000) >> 14;
                sz = (w2 & 0xc0000000) >> 30;
                w3 = data_021530d0[sh][sz] >> 1;
                h3 = data_021530b8[sh][sz] >> 1;
                v[0] += d[0] * w3 + (s32) - (w3 << 12) + d[2] * h3;
                v[1] += d[1] * w3 + (s32) - (h3 << 12) + d[3] * h3;
                if (sq != 0) {
                    v[0] -= w3 << 12;
                    v[1] -= h3 << 12;
                }
            }
            if (e != 0) {
                v[0] += e[0];
                v[1] += e[1];
            }
            *(u32 *) o =
                (*(u32 *) o & 0xfe00ff00) | (((v[1] + 0x800) >> 12) & 0xff) | ((((v[0] + 0x800) >> 12) & 0x1ff) << 16);
        }
    }
    return b;
}

void func_020224c0(Unk02022438 *a, s16 b, s16 c) {
    if (a->mUnk_00 == 1) {
        a->mUnk_12 |= 8;
        a->mUnk_0c = b;
        a->mUnk_0e = c;
    }
}

void func_020224a4(Unk02022438 *a, u16 b) {
    if (a->mUnk_00 == 1) {
        a->mUnk_12 |= 4;
        a->mUnk_10 = b;
    }
}

void func_02022484(Unk02022438 *a, s32 b, s32 c) {
    if (a->mUnk_00 == 1) {
        a->mUnk_12 |= 2;
        a->mUnk_04 = b;
        a->mUnk_08 = c;
    }
}

void func_02022474(Unk02022438 *a, u32 b) {
    a->mUnk_00 = b;
    func_02022438(a);
}

void func_02022438(Unk02022438 *a) {
    volatile u16 z;

    z = 0;
    MemFillHalfwords(z, &a->mUnk_04, 0x18);
    a->mUnk_04 = 0x1000;
    a->mUnk_08 = 0x1000;
}

void func_02022310(Unk02022030 *a) {
    u32 m;
    Unk02021e40 *p;
    Unk02021e40 *q;

    m = a->mUnk_14;
    if (m == 0) {
        m = a->mUnk_18->mUnk_08;
    }
    switch (m) {
        case 3:
        case 4:
            a->mUnk_04 = a->mUnk_04 ^ 1;
            if (a->mUnk_00 <= &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_02] - 1) {
                if (a->mUnk_1c == 1) {
                    a->mUnk_24(a->mUnk_20, a->mUnk_0c);
                }
                m = a->mUnk_14;
                if (m == 0) {
                    m = a->mUnk_18->mUnk_08;
                }
                if (m != 2 && m != 4) {
                    a->mUnk_08 = 0;
                } else {
                    func_02022040(a);
                }
            }
            break;
        default:
            if (a->mUnk_1c == 1) {
                a->mUnk_24(a->mUnk_20, a->mUnk_0c);
            }
            m = a->mUnk_14;
            if (m == 0) {
                m = a->mUnk_18->mUnk_08;
            }
            if (m != 2 && m != 4) {
                a->mUnk_08 = 0;
            } else {
                func_02022040(a);
            }
            break;
    }
    p = a->mUnk_00;
    q = &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_00] - 1;
    if (p > q) {
        a->mUnk_00 = q;
        return;
    }
    if (p < a->mUnk_18->mUnk_0c) {
        a->mUnk_00 = a->mUnk_18->mUnk_0c;
    }
}

u32 func_020222ec(Unk02022030 *a, u32 b) {
    if (b < a->mUnk_18->mUnk_00) {
        a->mUnk_00 = &a->mUnk_18->mUnk_0c[b];
        return 1;
    }
    return 0;
}
