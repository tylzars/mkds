#include "Main/Unknown/code_021001ac.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f81b8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02100700.h"
#include "Main/Unknown/code_02100704.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02100b78.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02100b84.h"
#include "Main/Unknown/code_02100dd8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6a74.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021025d8.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_021a2034.h"

void func_02102668(Unk02102668 *p0) {
    p0->mUnk_170 = 0x1u;
}

void func_021025d8(Unk021025d8 *a) {
    UnkFunc *const *v1;
    a->mUnk_154 = 0x13;
    a->mUnk_158 = 0;
    v1 = (UnkFunc *const *) data_0216c77c;
    a->mUnk_15c = 0;
    a->mUnk_160 = 0xe;
    func_02046be8(a->mUnk_12c, v1, 7, a);
    a->mUnk_140 = 8;
    a->mUnk_144 = 0;
    func_020f9c40((int) a);
    a->mUnk_24c = 0;
    a->mUnk_250 = 0xffffffff;
    a->mUnk_254 = 0x12;
    a->mUnk_258 = 0xffffffff;
    a->mUnk_25c = 0x12;
    a->mUnk_260 = 0xffffffff;
    a->mUnk_264 = 0xffffffff;
    a->mUnk_268 = 0;
    a->mUnk_26c = 0;
    a->mUnk_270 = 0;
}

static inline u32 func_02101f7c_inline_2(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return (u32) (b->mUnk_00 >> 32);
    }
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline s32 func_02101f7c_inline(Unk020ee684 *v1, Unk021759c0 *o, s32 a, u16 k) {
    Unk020ee684 *e;
    Unk0206bcb0 *q;
    s32 v2;
    s32 l;

    l = 1;
    v2 = 1;
    e = &v1[k];
    q = e->mUnk_1fc;
    if (q->mUnk_180 < 4 && (q->mUnk_7c & 0x400020) == 0) {
        v2 = 0;
    }
    if (v2 == 0 && (q->mUnk_4c & 0x10000800) == 0) {
        l = 0;
    }
    if (l | ((q->mUnk_4c & 0x40) ? 1 : 0)) {
        v2 = 0;
    } else if (a != -1 && a == o->mUnk_68[k].mUnk_08.mUnk_04) {
        v2 = 0;
    } else {
        v2 = 0;
        if (e->mUnk_030.mUnk_00 != 0x13 && e->mUnk_030.mUnk_20 == 0) {
            v2 = e->mUnk_030.mUnk_00 != 0x10;
        }
    }
    return v2;
}

void func_02101f7c(Unk02101c84 *p, s32 a) {
    u16 acc[7];
    u16 b2[7];
    u32 lim;
    Unk0217561c *m;
    u32 j;
    u16 k;
    u16 v;
    Unk020f41c4_B *b;
    u16 i;
    s32 c;
    u16 s;
    u16 *t;
    u32 n;
    Unk020ee684 *v2;
    Unk021759c0 *v3;
    Unk020ee684 *v1;
    Unk021759c0 *o;

    lim = data_021759c0->mUnk_3d0;
    s = c = 0;
    t = data_0215a154;
    j = n = func_0203c8dc((u16) ((p->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (p->mUnk_000.mUnk_78 & ~0xff00) : 8));
    if (p->mUnk_148 != 0) {
        m = data_0217561c;
        v1 = data_027e00c8;
        o = data_021759c0;
        do {
            if (n > 1) {
                n = (u16) (n - 1);
                k = (u16) m->mUnk_474[(u8) n - 1];
                if (func_02101f7c_inline(v1, o, a, k) != 0) {
                    s = (u16) (s + *t);
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
            if (j < lim) {
                j = (u16) (j + 1);
                k = (u16) m->mUnk_474[(u8) j - 1];
                if (func_02101f7c_inline(v1, o, a, k) != 0) {
                    s = (u16) (s + *t);
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
        } while (j < lim || n > 1);
    } else {
        m = data_0217561c;
        v2 = data_027e00c8;
        v3 = data_021759c0;
        do {
            if (j < lim) {
                j = (u16) (j + 1);
                k = (u16) m->mUnk_474[(u8) j - 1];
                if (func_02101f7c_inline(v2, v3, a, k) != 0) {
                    s = (u16) (s + *t);
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
            if (n > 1) {
                n = (u16) (n - 1);
                k = (u16) m->mUnk_474[(u8) n - 1];
                if (func_02101f7c_inline(v2, v3, a, k) != 0) {
                    s = (u16) (s + *t);
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
        } while (j < lim || n > 1);
    }
    b = &m->mUnk_47c;
    v = (u16) (s == 0 ? 0 : func_02101f7c_inline_2(b, s));
    for (i = 0; i < c; i++) {
        if (v < acc[i]) {
            p->mUnk_140 = b2[i];
            return;
        }
    }
}

void func_02101d90(Unk02101c84 *p, s32 a) {
    Unk0217561c *m;
    Unk020f41c4_B *b;
    s32 end;
    s32 i;
    u32 lim;
    s32 b3;
    Unk020ee684 *v1;
    Unk021759c0 *o;
    s32 k;
    Unk020ee684 *e;
    Unk0206bcb0 *q;
    s32 l;
    s32 n;
    u8 *row;

    m = data_0217561c;
    b = &m->mUnk_47c;
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    o = data_021759c0;
    i = (u16) (((u64) (u32) (b->mUnk_00 >> 32) * 8) >> 32);
    end = i + 8;
    lim = o->mUnk_3d0;
    b3 = (u16) ((p->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (p->mUnk_000.mUnk_78 & ~0xff00) : 8);
    if (i >= end) {
        return;
    }
    v1 = data_027e00c8;
    row = &data_0215a164[i];
    do {
        k = *row;
        if (k < lim && k != b3) {
            e = &v1[k];
            q = e->mUnk_1fc;
            n = l = 1;
            if (q->mUnk_180 < 4 && (q->mUnk_7c & 0x400020) == 0) {
                n = 0;
            }
            if (n == 0 && (q->mUnk_4c & 0x10000800) == 0) {
                l = 0;
            }
            if (l | ((q->mUnk_4c & 0x40) ? 1 : 0)) {
                l = 0;
            } else if (a != -1 && a == o->mUnk_68[k].mUnk_08.mUnk_04) {
                l = 0;
            } else {
                l = 0;
                if (e->mUnk_030.mUnk_00 != 0x13 && e->mUnk_030.mUnk_20 == 0) {
                    l = e->mUnk_030.mUnk_00 != 0x10;
                }
            }
            if (l != 0) {
                p->mUnk_140 = k;
                return;
            }
        }
        i++;
        row++;
    } while (i < end);
}

void func_02101d18(Unk02101d18 *x, Unk02101c84 *p) {
    Unk0206bcb0 *q;

    q = x->mUnk_10;
    func_02069aa0(q);
    func_020f8e3c((u32) q, 0xf6);
    func_020f81b8((u32) x->mUnk_0c, 0x10);
    func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
    if (*(u16 *) (x->mUnk_0c + 0x1ec) & 0x20) {
        p->mUnk_148 = 0;
    } else {
        p->mUnk_148 = 1;
    }
    func_02046bcc(p->mUnk_12c, 0);
    p->mUnk_24c = 1;
}

void func_02101c84(Unk02101c84 *p) {
    Unk0206bcb0 *q;
    Vec3 *w;
    Vec3 v;

    func_02046b40((void *) p->mUnk_12c);
    func_021484d0(&p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_0e4, &p->mUnk_000.mUnk_5c);
    if (p->mUnk_000.mUnk_d0 != &p->mUnk_000.mUnk_0c4) {
        return;
    }
    q = p->mUnk_168;
    if (q == 0) {
        return;
    }
    w = &q->mUnk_98;
    func_021484d0(&p->mUnk_000.mUnk_50, w, &v);
    func_02146d78(&v, (s32 *) func_020e6b38(), &v);
    func_02148504(w, &v, &p->mUnk_000.mUnk_0c4);
}

void func_02101964(Unk02101c84 *p, s32 a) {
    Unk0206bcb0 *q;
    Vec3 *v;
    s32 *g;
    s32 *w;
    s32 d[3];
    s32 k;
    s32 m;
    s32 s;
    s32 c;
    s32 t;
    s32 n;

    q = p->mUnk_168;
    g = (s32 *) func_02061808();
    v = &p->mUnk_000.mUnk_50;
    k = m = 1;
    if (q->mUnk_180 < 4 && (q->mUnk_7c & 0x400020) == 0) {
        k = 0;
    }
    if (k == 0 && (q->mUnk_4c & 0x10000800) == 0) {
        m = 0;
    }
    if (m != 0) {
        if (p->mUnk_144 == 0 && (p->mUnk_000.mUnk_74 & 0x8000000) && p->mUnk_24c != 0) {
            p->mUnk_144 = 1;
            func_020fe694(0xb, p->mUnk_000.mUnk_4e, 1, p->mUnk_13a & 0xff);
        } else {
            p->mUnk_144 = 1;
        }
    }
    ((Vec3 *) d)->x = v->x - (&p->mUnk_000.mUnk_5c)->x;
    d[2] = v->z - (&p->mUnk_000.mUnk_5c)->z;
    if (p->mUnk_144 != 0) {
        func_02148504((Vec3 *) &p->mUnk_184, (Vec3 *) &p->mUnk_190, (Vec3 *) &p->mUnk_184);
        p->mUnk_190.x = (s32) (((s64) p->mUnk_190.x * 0xeb8) >> 12);
        p->mUnk_190.y = (s32) (((s64) p->mUnk_190.y * 0xeb8) >> 12);
        p->mUnk_190.z = (s32) (((s64) p->mUnk_190.z * 0xeb8) >> 12);
        *v = p->mUnk_184;
    } else {
        *v = q->mUnk_98;
        func_021484d0(v, (Vec3 *) &p->mUnk_184, (Vec3 *) &p->mUnk_190);
        p->mUnk_184 = *v;
        v->y -= q->mUnk_2bc;
    }
    func_02148504(v, (Vec3 *) &p->mUnk_16c, v);
    w = g + 3;
    if (p->mUnk_15c != 0) {
        s = 0xccd;
        c = 0x800;
    } else {
        s = 0x800;
        c = 0x400;
    }
    if (a != 0) {
        n = (s32) (((s64) * (s32 *) q->mUnk_2cc * q->mUnk_bc.z + 0x800) >> 12);
        v->x += (s32) (((s64) -n * w[0]) >> 12);
        v->z += (s32) (((s64) -n * w[2]) >> 12);
    }
    d[0] -= v->x;
    d[2] -= v->z;
    t = (s32) (((s64) w[0] * d[0] + (s64) w[2] * d[2]) >> 12);
    d[0] = (s32) (((s64) w[0] * t) >> 12);
    d[2] = (s32) (((s64) w[2] * t) >> 12);
    d[0] = (s32) (((s64) d[0] * s) >> 12);
    d[2] = (s32) (((s64) d[2] * s) >> 12);
    if (d[0] > c) {
        d[0] = c;
    } else if (d[0] < -c) {
        d[0] = -c;
    }
    if (d[2] > c) {
        d[2] = c;
    } else if (d[2] < -c) {
        d[2] = -c;
    }
    p->mUnk_16c = d[0] + (s32) p->mUnk_16c;
    p->mUnk_174 = d[2] + (s32) p->mUnk_174;
}

void func_021018a0(Unk02101c84 *p) {
    p->mUnk_168 = func_0207a974((u16) (p->mUnk_000.mUnk_78 & ~0xff00));
    p->mUnk_184 = p->mUnk_168->mUnk_98;
    p->mUnk_190 = p->mUnk_168->mUnk_a4;
    *(Vec3 *) &p->mUnk_16c =
        (Vec3){0, (s32) (((s64) * (s32 *) p->mUnk_168->mUnk_2cc * p->mUnk_168->mUnk_bc.z + 0x800) >> 12), 0};
    p->mUnk_17c = 0;
    p->mUnk_000.mUnk_d8 = 0x1f;
    if (p->mUnk_168->mUnk_48 & 1) {
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_0c4;
    }
}

void func_0210174c(Unk02101c84 *p) {
    Vec3 v;
    Vec3 s;
    Vec3 *q;

    if (p->mUnk_248 >= 0xb) {
        return;
    }
    if (func_020d849c(&p->mUnk_1a4.mUnk_00) != 0) {
        do {
            p->mUnk_248++;
            if (p->mUnk_248 >= 0xb) {
                return;
            }
        } while (func_020f3fa8(&p->mUnk_1a4, &data_0215a1c0[p->mUnk_248]) != 0);
    }
    func_020d8488((u32) &p->mUnk_1a4, (u32) &s);
    func_020d84c0(&p->mUnk_1a4.mUnk_00, s.y);
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        v = (Vec3){s.x};
    } else {
        s32 f = s.x;

        q = (Vec3 *) func_020e6b28();
        v.x = (s32) (((s64) q->x * f) >> 12);
        v.y = (s32) (((s64) q->y * f) >> 12);
        v.z = (s32) (((s64) q->z * f) >> 12);
    }
    v.y += s.z;
    func_021484d0(&v, (Vec3 *) &p->mUnk_16c, &s);
    func_02147fd8(0x4f6, &s, (Vec3 *) &p->mUnk_16c, (Vec3 *) &p->mUnk_16c);
}

s32 func_02101618(Unk02101c84 *p, s32 a, s32 b) {
    s32 n;
    s32 m;
    s32 d;

    n = p->mUnk_130;
    if (p->mUnk_15c != 0) {
        m = -7;
        d = func_02061f90() > 2;
        func_0210174c(p);
    } else {
        if (b < 7) {
            p->mUnk_17c += 0x133;
            m = 0x1c;
            d = 6;
        } else {
            m = 0x14;
            d = 2;
            if (p->mUnk_17c < 0) {
                p->mUnk_17c += 0x2cd;
            } else {
                p->mUnk_17c += 0x8f;
            }
        }
        p->mUnk_170 += p->mUnk_17c;
    }
    func_02101964(p, a);
    if (n > m) {
        if (p->mUnk_000.mUnk_d8 > 0) {
            p->mUnk_000.mUnk_d8 -= d;
        }
        if (n >= (p->mUnk_15c != 0 ? 0x37 : 0x28)) {
            if (b < 7) {
                if (p->mUnk_13a == 0) {
                    p->mUnk_14c = p->mUnk_170;
                    p->mUnk_150 = p->mUnk_17c;
                }
                p->mUnk_13c = b;
                p->mUnk_13e = 1;
            }
            return 1;
        }
    }
    return 0;
}

s32 func_021014a0(Unk02101c84 *p, s32 a, s32 b) {
    s32 n;
    u16 k;

    n = p->mUnk_130;
    if (p->mUnk_15c != 0) {
        func_0210174c(p);
    } else if (p->mUnk_26c != 0) {
        k = data_0217c630[n];
        p->mUnk_16c = (s32) (((s64) p->mUnk_16c * k) >> 12);
        p->mUnk_174 = (s32) (((s64) p->mUnk_174 * k) >> 12);
    } else {
        p->mUnk_170 += p->mUnk_17c;
        p->mUnk_17c += 0x133;
        k = data_0217c630[n];
        p->mUnk_16c = (s32) (((s64) p->mUnk_16c * k) >> 12);
        p->mUnk_174 = (s32) (((s64) p->mUnk_174 * k) >> 12);
    }
    func_02101964(p, a);
    if (n > 7) {
        if (p->mUnk_000.mUnk_d8 < 0x1f) {
            p->mUnk_000.mUnk_d8 += 6;
        }
        if (n == 0x27) {
            if (p->mUnk_15c == 0) {
                p->mUnk_178 = p->mUnk_16c;
                p->mUnk_180 = p->mUnk_174;
            }
        } else if (n == 0x28) {
            if (p->mUnk_15c == 0) {
                p->mUnk_178 = p->mUnk_16c - p->mUnk_178;
                p->mUnk_180 = p->mUnk_174 - p->mUnk_180;
            }
            p->mUnk_13c = b;
            p->mUnk_13e = 1;
            p->mUnk_26c = 0;
        }
    }
    return n;
}

void func_0210140c(Unk02101c84 *p) {
    func_02101618(p, 0, (p->mUnk_000.mUnk_74 & 0x8000000) ? 1 : 2);
    if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != 0) {
        return;
    }
    if (p->mUnk_144 != 0) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 0 || p->mUnk_264 == 7) {
        p->mUnk_144 = 1;
        p->mUnk_264 = -1;
    }
}

void func_021013bc(Unk02101c84 *p) {
    if (p->mUnk_24c == 0) {
        return;
    }
    func_02101f7c(p, -1);
    func_020fe694(0xb, p->mUnk_000.mUnk_4e, 0, p->mUnk_140 & 0xff);
    p->mUnk_250 = p->mUnk_140;
    p->mUnk_24c = 0;
}

void func_0210136c(Unk02101c84 *p) {
    s32 n;

    if (p->mUnk_250 == 0xffffffff) {
        return;
    }
    n = p->mUnk_130;
    if (p->mUnk_24c == 0 && n < 0x28) {
        return;
    }
    p->mUnk_268 = n - 0x28;
    p->mUnk_140 = p->mUnk_250;
    p->mUnk_13c = 2;
    p->mUnk_13e = 1;
}

void func_02101178(Unk02101c84 *p) {
    s32 *v;
    Unk02061808 *g;
    Unk021759c0 *o;
    void (*f)(Unk02101c84 *, s32);
    int i;

    v = &p->mUnk_16c;
    g = func_02061808();
    if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
        o = data_021759c0;
        f = (o->mUnk_08 == 2) ? func_02101d90 : func_02101f7c;
        if (o->mUnk_58 != 0) {
            if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
                i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
            } else {
                i = 8;
            }
            f(p, o->mUnk_68[(u16) i].mUnk_08.mUnk_04);
            if (p->mUnk_140 == 8) {
                f(p, -1);
            }
        } else {
            f(p, -1);
        }
    }
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        p->mUnk_000.mUnk_50 = p->mUnk_000.mUnk_0c4;
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_50;
    }
    if (p->mUnk_140 < 8) {
        p->mUnk_168 = func_0207a974(p->mUnk_140);
        p->mUnk_184 = p->mUnk_168->mUnk_98;
        p->mUnk_190 = p->mUnk_168->mUnk_a4;
        p->mUnk_144 = 0;
        func_020f8e3c((u32) p->mUnk_168, 0xf4);
        if (p->mUnk_168->mUnk_48 & 1) {
            p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_0c4;
        }
    }
    v[0] = (s32) (((s64) g->mUnk_00c.x * -0xa000) >> 12);
    v[2] = (s32) (((s64) g->mUnk_00c.z * -0xa000) >> 12);
    v[0] += (s32) (((s64) g->mUnk_15c.x * -0x11000) >> 12);
    v[2] += (s32) (((s64) g->mUnk_15c.z * -0x11000) >> 12);
    p->mUnk_17c = -p->mUnk_17c;
    p->mUnk_270 = 0;
}

s32 func_02101014(Unk02101c84 *p) {
    Unk020ee684 *e;
    Unk0206bcb0 *q;
    Unk020f40dc *r;
    s32 a;
    s32 b;
    enum { K0 } k;

    e = &data_027e00c8[(u16) p->mUnk_140];
    q = e->mUnk_1fc;
    r = &e->mUnk_030;
    if (r->mUnk_00 == 0x13 || r->mUnk_20 != 0) {
        return 0xf;
    }
    if (r->mUnk_00 == 0x10) {
        return 0xf;
    }
    if (p->mUnk_144 != 0) {
        return 0xf;
    }
    a = b = 1;
    if (q->mUnk_180 < 4 && (q->mUnk_7c & 0x400020) == 0) {
        a = 0;
    }
    if (a == 0 && (q->mUnk_4c & 0x10000800) == 0) {
        b = 0;
    }
    if (b | ((q->mUnk_4c & 0x40) ? 1 : 0)) {
        return 0xf;
    }
    if (p->mUnk_000.mUnk_74 & 0x8000000) {
        p->mUnk_154 = r->mUnk_00;
        p->mUnk_158 = r->mUnk_08;
        func_0205a5b0(((u8 *) data_0217aa18)[p->mUnk_140 & 0xff]);
    } else {
        func_020f413c(r, &p->mUnk_154, &p->mUnk_158);
    }
    func_02068a10(q);
    k = p->mUnk_154;
    return data_0217bc48[k].mUnk_08;
}

void func_02100de4(Unk02101c84 *p) {
    u32 n;
    s32 k;

    if (p->mUnk_140 == 8) {
        if (p->mUnk_130 > 0x6e) {
            p->mUnk_160 = 0xf;
            p->mUnk_13c = (p->mUnk_000.mUnk_74 & 0x8000000) ? 4 : 5;
            p->mUnk_13e = 1;
        }
    } else {
        n = 0x28 - func_021014a0(p, 1, 3);
        if (p->mUnk_160 == 0xe) {
            if (p->mUnk_24c != 0) {
                if (n == 0xa) {
                    p->mUnk_160 = func_02101014(p);
                    p->mUnk_164 = 0;
                    if (p->mUnk_000.mUnk_74 & 0x8000000) {
                        func_020fe694(0xb, p->mUnk_000.mUnk_4e, 2, ((p->mUnk_154 << 2) | p->mUnk_158) & 0xff);
                    }
                }
            } else if (n <= 0xa) {
                if (p->mUnk_258 != -1) {
                    p->mUnk_154 = p->mUnk_254;
                    p->mUnk_158 = p->mUnk_258;
                    p->mUnk_254 = 0x12;
                    p->mUnk_258 = -1;
                    if (p->mUnk_154 == 0x13) {
                        p->mUnk_160 = 0xf;
                    } else {
                        p->mUnk_160 = data_0217bc48[p->mUnk_154].mUnk_08;
                        func_0205a5b0(((u8 *) data_0217aa18)[p->mUnk_140 & 0xff]);
                    }
                    p->mUnk_164 = 0;
                    k = 1;
                } else {
                    k = 0;
                }
                if (k == 0 && n == 1) {
                    p->mUnk_130--;
                    p->mUnk_26c = 1;
                    p->mUnk_270++;
                    if (p->mUnk_270 > 0x3c) {
                        p->mUnk_254 = 0x13;
                        p->mUnk_258 = 0;
                    }
                }
            }
        }
    }
    if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != 0) {
        return;
    }
    if (p->mUnk_144 != 0) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 2 || p->mUnk_264 == 7) {
        p->mUnk_144 = 1;
        p->mUnk_264 = -1;
    }
}

void func_02100dd8(Unk02100dd8 *p0) {
    p0->mUnk_19c = 0x0u;
}

void func_02100bf0(Unk02101c84 *p) {
    if (p->mUnk_164 < 0x1f) {
        p->mUnk_164 += 5;
    }
    p->mUnk_178 = (s32) (((s64) p->mUnk_178 * 0xf85) >> 12);
    p->mUnk_180 = (s32) (((s64) p->mUnk_180 * 0xf85) >> 12);
    if (p->mUnk_130 == 0x12) {
        if (p->mUnk_19c == 0) {
            p->mUnk_19c = -0x1ae;
            p->mUnk_1a0 = p->mUnk_17c;
        }
        p->mUnk_17c += p->mUnk_19c;
        p->mUnk_170 += p->mUnk_17c;
        func_02101964(p, 1);
        if (p->mUnk_19c >= 0 && p->mUnk_17c >= p->mUnk_1a0) {
            return;
        }
        p->mUnk_130--;
        if (p->mUnk_19c >= 0) {
            return;
        }
        if (p->mUnk_17c < -0xc00) {
            p->mUnk_19c = 0x133;
            return;
        }
        if (p->mUnk_17c <= 0) {
            return;
        }
        if (p->mUnk_17c >= -p->mUnk_19c) {
            return;
        }
        func_020f8e3c((u32) p->mUnk_168, 0xf5);
    } else {
        p->mUnk_16c += p->mUnk_178;
        p->mUnk_174 += p->mUnk_180;
        func_02101618(p, 1, (p->mUnk_000.mUnk_74 & 0x8000000) ? 4 : 5);
        if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        if (p->mUnk_24c != 0) {
            return;
        }
        if (p->mUnk_144 != 0) {
            return;
        }
        if (p->mUnk_264 == 0xffffffff) {
            return;
        }
        if (p->mUnk_264 - 2 <= 1) {
            p->mUnk_144 = 1;
            p->mUnk_264 = -1;
        }
    }
}

void func_02100bc8(Unk02101c84 *p) {
    p->mUnk_268 = ((p->mUnk_000.mUnk_74 & 0x10000000) ? 0xf : 0) - p->mUnk_268;
    p->mUnk_24c = 0;
}

void func_02100b84(Unk02101c84 *p) {
    p->mUnk_268--;
    if (p->mUnk_268 >= 0) {
        return;
    }
    p->mUnk_24c = (p->mUnk_000.mUnk_74 & 0x10000000) == 0;
    p->mUnk_13c = 5;
    p->mUnk_13e = 1;
}

void func_02100b78(Unk02101c84 *p0) {
    p0->mUnk_000.mUnk_d0 = &p0->mUnk_000.mUnk_0c4;
}

void func_02100b54(Unk02101c84 *p) {
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        p->mUnk_000.mUnk_50 = p->mUnk_000.mUnk_0c4;
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_50;
    }
}

void func_021009fc(Unk02101c84 *p) {
    int i;
    Unk020ee684 *e;
    void (*f)(Unk02101c84 *);

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &(data_027e00c8)[(u16) i];
    p->mUnk_168 = e->mUnk_1fc;
    p->mUnk_144 = 0;
    if (p->mUnk_24c != 0) {
        if (e->mUnk_014 == 0x10) {
            p->mUnk_184 = p->mUnk_168->mUnk_98;
            p->mUnk_190 = p->mUnk_168->mUnk_a4;
            p->mUnk_16c = 0;
            p->mUnk_174 = 0;
        } else {
            p->mUnk_144 = 1;
            if (p->mUnk_000.mUnk_74 & 0x8000000) {
                func_020fe694(0xb, p->mUnk_000.mUnk_4e, 1, 5);
            }
            p->mUnk_16c = 0;
            p->mUnk_174 = 0;
        }
    }
    if (p->mUnk_160 == 0xf) {
        func_020f4020(&p->mUnk_1a4, data_0215a1c0, data_0215a1c0[0].y);
        p->mUnk_248 = 3;
        p->mUnk_15c = 1;
    } else {
        p->mUnk_17c = -p->mUnk_150;
        p->mUnk_170 = p->mUnk_14c;
    }
    if (p->mUnk_144 == 0) {
        func_020f8e3c((u32) p->mUnk_168, 0xf7);
    }
    p->mUnk_270 = 0;
    f = (p->mUnk_168->mUnk_48 & 1) ? func_02100b78 : func_02100b54;
    f(p);
}

void func_02100704(Unk02101c84 *p) {
    s32 i;
    Unk020ee684 *e;
    u32 n;
    s32 k;
    s32 a0;
    s32 a1;

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &(data_027e00c8)[(u16) i];
    if (p->mUnk_24c != 0 && e->mUnk_014 != 0x10 && p->mUnk_158 != -0x40) {
        p->mUnk_144 = 1;
        if (p->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe694(0xb, p->mUnk_000.mUnk_4e, 1, 5);
        }
    } else {
        n = 0x28 - func_021014a0(p, p->mUnk_15c == 0 ? 1 : 0, 6);
        if (n < 7) {
            if (p->mUnk_164 > 0) {
                p->mUnk_164 -= 5;
            }
            if (n == 1) {
                if (p->mUnk_24c == 0) {
                    if (p->mUnk_260 == -1) {
                        k = 0;
                    } else {
                        p->mUnk_154 = p->mUnk_25c;
                        p->mUnk_158 = p->mUnk_260;
                        p->mUnk_25c = 0x12;
                        p->mUnk_260 = -1;
                        k = 1;
                    }
                    if (k == 0) {
                        p->mUnk_130--;
                        p->mUnk_26c = 1;
                        p->mUnk_270++;
                        if (p->mUnk_270 > 0x3c) {
                            p->mUnk_25c = 0x13;
                            p->mUnk_260 = -0x40;
                            p->mUnk_160 = 0xe;
                        }
                        goto skip;
                    }
                }
                e->mUnk_014 = 0x13;
                if (p->mUnk_154 != 0x13) {
                    if (p->mUnk_24c == 0) {
                        func_0205a548(((u8 *) data_0217aa18)[e->mUnk_1f8 & 0xff], p->mUnk_154, p->mUnk_158);
                    } else {
                        func_020f40dc(&e->mUnk_030, p->mUnk_154, p->mUnk_158);
                    }
                    p->mUnk_154 = 0x13;
                    p->mUnk_158 = -0x40;
                    p->mUnk_160 = 0xe;
                    func_020f8e3c((u32) e->mUnk_1fc, 0xf8);
                } else {
                    p->mUnk_158 = -0x40;
                    p->mUnk_160 = 0xe;
                }
                if ((p->mUnk_000.mUnk_74 & 0x8000000) && p->mUnk_24c != 0) {
                    func_020fe694(0xb, p->mUnk_000.mUnk_4e, 3,
                                  ((e->mUnk_030.mUnk_00 << 2) | e->mUnk_030.mUnk_08) & 0xff);
                }
            }
        }
    }
skip:
    if (p->mUnk_15c == 0 && p->mUnk_144 != 0) {
        a0 = p->mUnk_16c;
        a1 = p->mUnk_174;
        func_021014a0(p, 1, 6);
        p->mUnk_178 = p->mUnk_16c - a0;
        p->mUnk_180 = p->mUnk_174 - a1;
        p->mUnk_13c = 6;
        p->mUnk_13e = 1;
        p->mUnk_26c = 0;
    }
    if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != 0) {
        return;
    }
    if (p->mUnk_144 != 0) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 5 || p->mUnk_264 == 7) {
        p->mUnk_144 = 1;
        p->mUnk_264 = -1;
    }
}

u32 func_02100700(u32 p0) {
    return p0;
}

void func_02100564(Unk02101c84 *p) {
    s32 a;
    s32 i;

    a = p->mUnk_154 != 0x13;
    if (p->mUnk_15c == 0) {
        p->mUnk_178 = (s32) (((s64) p->mUnk_178 * 0xf85) >> 12);
        p->mUnk_180 = (s32) (((s64) p->mUnk_180 * 0xf85) >> 12);
        p->mUnk_16c += p->mUnk_178;
        p->mUnk_174 += p->mUnk_180;
    }
    if (a != 0) {
        if (p->mUnk_164 < 0x1f) {
            p->mUnk_164 += 8;
        }
    }
    if (func_02101618(p, p->mUnk_15c == 0 ? 1 : 0, 7) != 0) {
        if (a != 0) {
            if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
                i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
            } else {
                i = 8;
            }
            ((void (*)(s32 param_1, s32 param_2, s32 param_3)) func_020f40a0)(p->mUnk_154, p->mUnk_158, (u16) i);
        }
        func_020f0f70(data_027e00cc + p->mUnk_000.mUnk_44, &p->mUnk_000);
    }
    if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != 0) {
        return;
    }
    if (p->mUnk_144 != 0) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 - 5 <= 1) {
        p->mUnk_144 = 1;
        p->mUnk_264 = -1;
    }
}

void func_0210050c(Unk02101c84 *p) {
    int i;
    Unk020ee684 *e;

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &(data_027e00c8)[(u16) i];
    if (e->mUnk_014 != 0x10) {
        return;
    }
    if (p->mUnk_158 != -0x40) {
        e->mUnk_014 = 0x13;
    }
}

void func_021004c4(void *p, Unk02101c84 *a, void *b) {
    func_020fecdc(p, a, b);
    if (a == 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    func_020fe8ac(a->mUnk_000.mUnk_44);
}

void func_0210045c(Unk02101c84 *p) {
    int i;

    func_020f8e78(p);
    func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
    func_02046bcc(p->mUnk_12c, 0);
    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    func_020f81b8((u32) & (data_027e00c8)[(u16) i], 0x10);
}

void func_021003e8(Unk02101c84 *p, u32 sel, s32 v1) {
    switch (sel) {
        case 0:
            p->mUnk_250 = v1;
            if (p->mUnk_250 == data_021759c0->mUnk_62) {
                p->mUnk_24c = 1;
            }
            break;
        case 1:
            p->mUnk_264 = v1;
            break;
        case 2:
            p->mUnk_254 = v1 >> 2;
            p->mUnk_258 = v1 & 3;
            break;
        case 3:
            p->mUnk_25c = v1 >> 2;
            p->mUnk_260 = v1 & 3;
            break;
    }
}

void func_021001ac(Unk02101c84 *p, s32 c, Unk020e6488 *q) {
    s32 a;
    s32 n;
    s32 b;
    s32 t;
    s16 d;
    s32 v[3];
    s32 x;
    s32 y;
    s32 z;
    Unk020e6488 *r;
    s32 i;
    s32 b2;

    if (p->mUnk_000.mUnk_d8 <= 0) {
        return;
    }
    a = 0x1e;
    func_01ff9048(0x14, &a, 1);
    func_01ff9048(0x19, func_020e6cf8(p->mUnk_000.mUnk_d0), 0xc);
    z = p->mUnk_000.mUnk_68.z;
    y = p->mUnk_000.mUnk_68.y;
    x = p->mUnk_000.mUnk_68.x;
    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_01ff9048(0x1b, v, 3);
    if (p->mUnk_160 < 0xe && p->mUnk_13a >= 3) {
        r = func_020ed578(p->mUnk_160);
        n = p->mUnk_164;
        b2 = p->mUnk_158;
        if (p->mUnk_000.mUnk_d8 < 0x1f) {
            if (p->mUnk_000.mUnk_d8 < n) {
                n = p->mUnk_000.mUnk_d8;
            }
        }
        if (n > 0x1f) {
            n = 0x1f;
        }
        if (n < 1) {
            n = 1;
        }
        func_01ff9048(0x11, 0, 0);
        r->mUnk_14 = r->mUnk_14 & ~0x1f0000;
        r->mUnk_14 = r->mUnk_14 | ((u16) n << 16);
        func_020e6a18(r);
        i = 0;
        r->mUnk_18 = 0;
        while (i < b2) {
            func_01ff9048(0x1c, &data_0215a190[b2 == 2 ? 1 - i : i + 1], 3);
            t = func_020d3c44();
            r->mUnk_14 = r->mUnk_14 & ~0x3f000000;
            r->mUnk_14 = r->mUnk_14 | (t << 24);
            func_020e6854(r, &p->mUnk_000.mUnk_50, 1, 0x1f);
            i++;
        }
        b = 1;
        func_01ff9048(0x12, &b, 1);
        if (n != 0x1f) {
            r->mUnk_14 = r->mUnk_14 & ~0x1f0000;
            r->mUnk_14 = r->mUnk_14 | 0x1f0000;
        }
    }
    t = func_020d3c44();
    q->mUnk_14 = q->mUnk_14 & ~0x3f000000;
    q->mUnk_14 = q->mUnk_14 | (t << 24);
    d = p->mUnk_000.mUnk_d8;
    q->mUnk_14 = q->mUnk_14 & ~0x1f0000;
    q->mUnk_14 = q->mUnk_14 | ((u16) d << 16);
    func_020ed588(&p->mUnk_000, q);
}
