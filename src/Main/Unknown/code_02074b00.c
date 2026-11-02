#include "Main/Unknown/code_02074b00.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_02076cc4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

static inline void func_02074b00_inline(Vec3 *v, const Vec3 *u, s32 s) {
    s32 x = u->x;
    s32 y = u->y;
    s32 z = u->z;
    v->x = (s32) (((s64) x * s) >> 12);
    v->y = (s32) (((s64) y * s) >> 12);
    v->z = (s32) (((s64) z * s) >> 12);
}

// non-matching: same size (0x36c), 42 words differ in register choice and order: the original loads the scale into ip
// before the three components (r2, r1, r0), the 0xfae scaling uses ip/lr/r7 where this uses lr/r7/ip, and the
// interpolation at the end loads mUnk_240 into ip and subtracts both differences before the first multiply
void func_02074b00(Unk02061808 *p) {
    Unk0206bcb0 *o = func_0207a974(p->mUnk_210);
    Unk020748b8_218 *q = p->mUnk_218;
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 m[9];

    p->mUnk_0b4 = p->mUnk_018;
    b = o->mUnk_80;
    func_02147fd8(q->mUnk_00.z, &o->mUnk_120, &o->mUnk_80, &a);
    a.y = 0x1f4000;
    b.y = 0x1f4000;
    c = o->mUnk_138;
    c.y = 0;
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 0x10) {
        func_02039860(&c, &c);
    }
    func_02074b00_inline(&c, &c, q->mUnk_00.x);
    func_02148504(&a, &c, &a);
    func_02148504(&b, &c, &b);
    if (func_02061fb8() < q->mUnk_46) {
        p->mUnk_018 = b;
        p->mUnk_024 = a;
    } else if (p->mUnk_144 < 0x1000) {
        p->mUnk_018 = b;
        p->mUnk_024 = a;
        p->mUnk_144 = p->mUnk_144 + 0x52;
        func_021484d0(&p->mUnk_134, &p->mUnk_024, &p->mUnk_0a8);
        func_021484d0(&p->mUnk_0b4, &p->mUnk_018, &p->mUnk_0b4);
        func_02147fd8(p->mUnk_144, &p->mUnk_0a8, &a, &p->mUnk_024);
        func_02147fd8(p->mUnk_144, &p->mUnk_0b4, &b, &p->mUnk_018);
    }
    func_02076cd0(p);
    func_021484d0(&a, &b, &d);
    if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z >= 0x10) {
        func_02039860(&d, &d);
    }
    func_02146f98((Unk02012f58 *) m, &data_usa_02154fc4, data_0215d4b4[(data_usa_021656a0 >> 4) * 2],
                  data_0215d4b4[(data_usa_021656a0 >> 4) * 2 + 1]);
    func_02146d78(&d, m, &d);
    d.x = (s32) (((s64) d.x * 0xfae) >> 12);
    d.y = (s32) (((s64) d.y * 0xfae) >> 12);
    d.z = (s32) (((s64) d.z * 0xfae) >> 12);
    func_02062254(&d);
    q = p->mUnk_218;
    if (q->mUnk_3c != 0) {
        s32 x0 = q->mUnk_32;
        s32 x1 = q->mUnk_38;
        s32 y0 = q->mUnk_34;
        s32 y1 = q->mUnk_3a;
        s32 t = p->mUnk_240;
        p->mUnk_068 = x0 + (s32) (((s64) (x1 - x0) * t) >> 12);
        p->mUnk_06a = y0 + (s32) (((s64) (y1 - y0) * t) >> 12);
        p->mUnk_240 += q->mUnk_3c;
        if (p->mUnk_240 > 0x1000) {
            p->mUnk_240 = 0x1000;
        }
    } else {
        p->mUnk_068 = q->mUnk_32;
        p->mUnk_06a = q->mUnk_34;
    }
}

void func_02074e6c(Unk02061808 *p) {
    Unk020748b8_218 *q = p->mUnk_218;
    Unk0206bcb0 *o;
    Vec3 *v;
    Vec3 a;
    Vec3 d;
    Vec3 t;
    s32 m3[9];
    s32 m2[9];
    s32 m4[9];
    s32 m0[9];
    s32 m6[9];
    s32 m5[9];
    s32 m7[9];
    Vec3 f;
    Vec3 g;
    Vec3 c;
    Vec3 n;
    Vec3 w;
    Vec3 b;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    if (data_021759c0->mUnk_00c == 5) {
        p->mUnk_210 = (q->mUnk_24.z >> 12) - 1;
        func_0207a948(&p->mUnk_018, p->mUnk_210);
        p->mUnk_018.y = p->mUnk_018.y + p->mUnk_218->mUnk_18.y;
    } else {
        func_0207a948(&p->mUnk_018, p->mUnk_210);
        p->mUnk_018.y = p->mUnk_018.y + 0x6000;
    }
    o = func_0207a974(p->mUnk_210);
    a = o->mUnk_138;
    i = (u16) ((s32) (((s64) q->mUnk_18.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    j = (u16) ((s32) (((s64) q->mUnk_18.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    k = (u16) ((s32) (((s64) q->mUnk_24.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    l = (u16) ((s32) (((s64) q->mUnk_24.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    func_02146f98((Unk02012f58 *) m0, &o->mUnk_120, data_0215d4b4[(o->mUnk_2c0 >> 4) * 2],
                  data_0215d4b4[(o->mUnk_2c0 >> 4) * 2 + 1]);
    func_02146d78(&a, m0, &a);
    b = a;
    c = b;
    d = b;
    func_02074b00_inline(&n, &d, -q->mUnk_18.z);
    func_020397a8(&data_usa_02154fc4, &a, &f);
    func_020397a8(&c, &f, &g);
    func_02146f98((Unk02012f58 *) m2, &g, data_0215d4b4[(i >> 4) * 2], data_0215d4b4[(i >> 4) * 2 + 1]);
    func_02146f98((Unk02012f58 *) m3, &f, data_0215d4b4[(j >> 4) * 2], data_0215d4b4[(j >> 4) * 2 + 1]);
    func_02146dfc(m3, m2, m4);
    func_02146d78(&d, m4, &d);
    func_02074b00_inline(&t, &d, q->mUnk_18.z);
    func_02148504(&p->mUnk_018, &t, &p->mUnk_024);
    f.x = -f.x;
    f.y = -f.y;
    f.z = -f.z;
    g.x = -g.x;
    g.y = -g.y;
    g.z = -g.z;
    func_02146f98((Unk02012f58 *) m5, &g, data_0215d4b4[(k >> 4) * 2], data_0215d4b4[(k >> 4) * 2 + 1]);
    func_02146f98((Unk02012f58 *) m6, &f, data_0215d4b4[(l >> 4) * 2], data_0215d4b4[(l >> 4) * 2 + 1]);
    func_02146dfc(m5, m2, m5);
    func_02146dfc(m6, m3, m6);
    func_02146dfc(m6, m5, m7);
    func_02146d78(&n, m7, &n);
    func_02148504(&p->mUnk_024, &n, &p->mUnk_018);
    p->mUnk_018.y = p->mUnk_018.y - o->mUnk_2bc;
    p->mUnk_024.y = p->mUnk_024.y - o->mUnk_2bc;
    if (data_021759c0->mUnk_08 != 4 && data_021759c0->mUnk_08 != 2) {
        if (func_01ffdee4(&p->mUnk_024, (u32 *) &p->mUnk_134, 0, data_usa_021656c0 >> 1, 2, -2, &w, 0, 0, 0, 0, 0, 0,
                          0) != 0) {
            o = func_0207a974(p->mUnk_210);
            v = &o->mUnk_120;
            k = func_0214848c(v, &w);
            w.x = (s32) (((s64) o->mUnk_120.x * k) >> 12);
            w.y = (s32) (((s64) v->y * k) >> 12);
            w.z = (s32) (((s64) v->z * k) >> 12);
            func_02148504(&w, &p->mUnk_024, &p->mUnk_024);
        }
    }
    func_02076cd0(p);
}

void func_02075390(Unk02061808 *p) {
    func_020749a4(p, p->mUnk_218->mUnk_42);
    if (data_021759c0->mUnk_00c == 5) {
        p->mUnk_210 = (p->mUnk_218->mUnk_24.z >> 12) - 1;
        func_0207a948(&p->mUnk_018, p->mUnk_210);
        p->mUnk_018.y = p->mUnk_018.y + p->mUnk_218->mUnk_18.y;
    } else {
        func_0207a948(&p->mUnk_018, p->mUnk_210);
        p->mUnk_018.y = p->mUnk_018.y + 0x6000;
    }
    func_02076cd0(p);
}

static inline void func_02075424_inline(Unk02061808 *p) {
    Unk020748b8_218 *q;

    if (p->mUnk_218->mUnk_48 == -1) {
        q = 0;
    } else {
        q = data_02175620->mUnk_7c + (u16) p->mUnk_218->mUnk_48;
    }
    if (q == 0) {
        data_0217561c->mUnk_4d0 = 1;
        return;
    }
    p->mUnk_23c = 0;
    p->mUnk_218 = q;
    p->mUnk_244 = 0;
    p->mUnk_240 = 0;
    if ((s16) q->mUnk_40 != -1) {
        func_0207be40(&p->mUnk_194, q);
    }
    if (data_021759c0->mUnk_00c == 5) {
        func_0208e808(q->mUnk_4b != 0);
    }
    data_0217aca8 = 1;
}

void func_02075424(Unk02061808 *p) {
    if (p->mUnk_218 == 0) {
        return;
    }
    func_02075900(p);
    p->mUnk_23c = p->mUnk_23c + 1;
    if (p->mUnk_23c != p->mUnk_218->mUnk_46) {
        return;
    }
    func_02075424_inline(p);
    if (p->mUnk_218 == 0) {
        return;
    }
    if (p != data_usa_0217ac98) {
        return;
    }
    if (p->mUnk_24c != 1) {
        return;
    }
    func_02075424_inline(data_usa_0217ac84);
}

Unk02012f58 *func_0207564c(void) {
    func_02075424(data_usa_0217ac98);
    func_02076cd0(data_usa_0217ac98);
    data_0217acb4 = data_usa_0217ac98;
    return &data_usa_0217ac98->mUnk_030;
}

Unk02012f58 *func_02075694(void) {
    if (data_usa_0217ac84->mUnk_218 != 0) {
        if (data_usa_0217ac84->mUnk_218->mUnk_3e == 4) {
            data_usa_0217ac98->mUnk_24c = 1;
            data_usa_0217ac84->mUnk_24c = 2;
        } else {
            data_usa_0217ac84->mUnk_24c = 0;
            data_usa_0217ac98->mUnk_24c = data_usa_0217ac84->mUnk_24c;
        }
    }
    func_02075424(data_usa_0217ac98);
    if (data_usa_0217ac84->mUnk_24c == 2) {
        data_usa_0217ac84->mUnk_068 = data_usa_0217ac98->mUnk_068;
        data_usa_0217ac84->mUnk_06a = data_usa_0217ac98->mUnk_06a;
        data_usa_0217ac84->mUnk_024 = data_usa_0217ac98->mUnk_024;
        data_usa_0217ac84->mUnk_018 = data_usa_0217ac98->mUnk_018;
    } else {
        func_02075424(data_usa_0217ac84);
    }
    if (func_02061f7c() == 0) {
        func_02076cd0(data_usa_0217ac98);
        data_0217acb4 = data_usa_0217ac98;
        return &data_usa_0217ac98->mUnk_030;
    }
    func_02076cd0(data_usa_0217ac84);
    data_0217acb4 = data_usa_0217ac84;
    return &data_usa_0217ac84->mUnk_030;
}

void func_020757d8(void) {
    Unk02061808 *p;
    Unk020748b8_218 *q;
    Unk020f41c4_B *b;

    p = data_0217acbc;
    q = data_02175620->mUnk_d4;

    if (q == 0) {
        return;
    }
    p->mUnk_238 = 1;
    p->mUnk_218 = q;
    p->mUnk_240 = 0;
    p->mUnk_068 = q->mUnk_32;
    p->mUnk_06a = q->mUnk_34;
    p->mUnk_130 = q->mUnk_4b;
    if ((s16) q->mUnk_40 != -1) {
        func_0207be40(&p->mUnk_194, q);
        if (data_021759c0->mUnk_08 == 2) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (func_0203c880(func_0207a974(data_021759c0->mUnk_62)->mUnk_74) != 0) {
        b = &data_0217561c->mUnk_498;
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    }
    data_0217aca8 = 1;
}

// non-matching: 0x18c bytes against 0x194: the original keeps mUnk_32, mUnk_34 and mUnk_240 in r7, r6 and r5 (push of
// r4-r7 and a stack offset of 4), loads all four halfwords and mUnk_240 before the two subtractions and the two
// multiplies, and reads mUnk_3c once more after the stores; the same interpolation in func_02074b00 differs the same
// way
void func_02075900(Unk02061808 *p) {
    switch (p->mUnk_218->mUnk_3e) {
        case 0:
            p->mUnk_024 = p->mUnk_218->mUnk_00;
            if (data_021759c0->mUnk_00c == 5) {
                p->mUnk_210 = (p->mUnk_218->mUnk_24.z >> 12) - 1;
                func_0207a948(&p->mUnk_018, p->mUnk_210);
                p->mUnk_018.y = p->mUnk_018.y + p->mUnk_218->mUnk_18.y;
            } else {
                func_0207a948(&p->mUnk_018, p->mUnk_210);
                p->mUnk_018.y = p->mUnk_018.y + 0x6000;
            }
            func_02076cd0(p);
            break;
        case 1:
            func_02075390(p);
            break;
        case 5:
        case 6:
            func_02074e6c(p);
            break;
        case 2:
            p->mUnk_024 = p->mUnk_218->mUnk_00;
            func_020748b8(p);
            func_02076ed4(p);
            break;
        case 3:
            func_02074978(p);
            break;
    }
    if (p->mUnk_218->mUnk_3c != 0) {
        Unk020748b8_218 *q = p->mUnk_218;

        s32 x0 = q->mUnk_32;
        s32 x1 = q->mUnk_38;
        s32 y0 = q->mUnk_34;
        s32 y1 = q->mUnk_3a;
        s32 t = p->mUnk_240;
        s32 v1 = x1 - x0;
        s32 v2 = y1 - y0;

        p->mUnk_068 = x0 + (s32) (((s64) v1 * t) >> 12);
        p->mUnk_06a = y0 + (s32) (((s64) v2 * t) >> 12);
        p->mUnk_240 += q->mUnk_3c;
        if (p->mUnk_240 > 0x1000) {
            p->mUnk_240 = 0x1000;
        }
    } else {
        p->mUnk_068 = p->mUnk_218->mUnk_32;
        p->mUnk_06a = p->mUnk_218->mUnk_34;
    }
}

s32 func_02075a94(Unk02061808 *p) {
    s32 r = 1;
    Unk020748b8_218 *q;
    Vec3 v;
    s32 i;

    p->mUnk_134 = p->mUnk_024;
    data_0217acac = 1;
    if (data_021759c0->mUnk_00c == 6) {
        func_02074b00(p);
        return 1;
    }
    if (p->mUnk_230 != 0 || p->mUnk_234 != 0) {
        return 0;
    }
    p->mUnk_134 = p->mUnk_024;
    if (p->mUnk_238 != 0) {
        func_02074e6c(p);
        return 1;
    }
    func_0207a948(&v, p->mUnk_210);
    i = func_020411e4(&v);
    if (p->mUnk_228 != 0) {
        if (data_021759c0->mUnk_08 == 2) {
            func_02075900(p);
            return 1;
        }
        p->mUnk_22c = p->mUnk_22c + 1;
        if (p->mUnk_22c >= 300) {
            p->mUnk_228 = 0;
        }
    }
    if (i == -1) {
        r = 0;
    } else {
        Unk020f41c4_B *b;

        q = data_02175620->mUnk_7c + (u16) i;
        if (i != p->mUnk_214) {
            p->mUnk_214 = i;
            if (p->mUnk_228 == 0) {
                p->mUnk_218 = q;
                p->mUnk_240 = 0;
                p->mUnk_068 = q->mUnk_32;
                p->mUnk_06a = q->mUnk_34;
                p->mUnk_130 = q->mUnk_4b;
                if ((s16) q->mUnk_40 != -1) {
                    func_0207be40(&p->mUnk_194, q);
                    if (data_021759c0->mUnk_08 == 2) {
                        func_0207bd6c(&p->mUnk_1d0, q);
                    }
                }
                if (func_0203c880(func_0207a974(data_021759c0->mUnk_62)->mUnk_74) != 0) {
                    b = &data_0217561c->mUnk_498;
                    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
                }
                data_0217aca8 = 1;
            }
        }
        func_02075900(p);
    }
    return r;
}
