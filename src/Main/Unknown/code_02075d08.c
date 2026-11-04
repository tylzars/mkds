#include "Main/Unknown/code_02075d08.h"
#include "Main/Unknown/code_02039860.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_02010c84.h"
#include "code_02147cd8.h"

static inline s32 func_020760ec_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return func_02039860(v, n);
}

void func_02075d08(s32 a) {
    Unk020748b8_218 *q;
    Unk02061808 *p = data_0217acbc;
    Unk020f41c4_B *r;
    Vec3 v;
    s32 s;

    if (p->mUnk_218 == NULL) {
        return;
    }
    if (a != 0 && p->mUnk_218->mUnk_3e != 5 && p->mUnk_218->mUnk_3e != 6) {
        return;
    }
    p->mUnk_230 = a;
    if (a == 0) {
        return;
    }
    if (p->mUnk_228 == 0) {
        return;
    }
    p->mUnk_228 = 0;
    func_0207a948(&v, p->mUnk_210);
    s = func_020411e4(&v);
    if (s < 0) {
        return;
    }
    q = (Unk020748b8_218 *) &gCourseMap->mUnk_7c[(u16) s];
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
    if (func_0203c880(func_0207a974(data_021759c0->mUnk_62)->mIndex) != 0) {
        r = &data_0217561c->mUnk_498;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    }
    data_0217aca8 = 1;
}

void func_02075eb8(void) {
    Unk02061808 *p = data_0217acbc;
    Unk020748b8_218 *q;
    Unk020f41c4_B *r;

    q = (Unk020748b8_218 *) gCourseMap->mUnk_cc;
    if (q == NULL) {
        return;
    }
    p->mUnk_228 = 1;
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
    if (func_0203c880(func_0207a974(data_021759c0->mUnk_62)->mIndex) != 0) {
        r = &data_0217561c->mUnk_498;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    }
    data_0217aca8 = 1;
}

void func_02075fe0(Unk02061808 *a, Unk0206bcb0 *b, Vec3 *c) {
    s32 e = -0x2d000;
    s32 j;
    s32 g = 0;
    s32 f = 0x11f;
    u32 d = b->mUnk_48;
    s32 h;

    if (d & 0x10000) {
        e = -0x3c000;
    }
    if (b->mUnk_3e8 > 0) {
        f = 0x52;
    }
    if ((b->mUnk_44 & 0x10) || (d & 0x10000)) {
        if ((h = c->y) > 0) {
            g = (s32) (((s64) h * e) >> 12);
        } else if (h + 0x4cd < 0) {
            g = (s32) (((s64) h * -0xf000) >> 12);
        }
    }
    if (d & 0x40000000) {
        a->mUnk_168 = a->mUnk_168 + (s32) (((s64) -a->mUnk_168 * f + 0x800) >> 12);
        return;
    }
    j = g - a->mUnk_168;
    a->mUnk_168 = a->mUnk_168 + (s32) (((s64) j * f + 0x800) >> 12);
}

void func_020760ec(Unk02061808 *a, Unk0206bcb0 *b, Vec3 *c) {
    Vec3 v = data_usa_02154fdc;
    Vec3 w;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 t;
    u32 j;
    BOOL m = FALSE;
    s32 k;
    s32 l;

    data_usa_0217ac80 = 0;
    a->mUnk_258 = 0;
    if (func_01ffdee4(&a->mUnk_024, (u32 *) &a->mUnk_134, 0, data_usa_021656c0, 2, -2, &v, &w, (s32 *) &x, &j, NULL,
                      NULL, NULL, NULL) != 0 &&
        (j & 0xc00) == 0) {
        if (j & 0x214300) {
            y = b->mUnk_50;
            if (b->mUnk_2a8 <= 0) {
                y.x = -y.x;
                y.y = -y.y;
                y.z = -y.z;
                k = func_020760ec_inline(&v, &z);
                if (k != 0) {
                    if (func_02039828(&z, &x) < 0xf5c) {
                        if (func_02039828(&z, c) > 0xb5c) {
                            a->mUnk_254 = 1;
                        }
                    }
                }
            }
            a->mUnk_258 = 1;
            k = func_02039828(&y, &x);
            m = TRUE;
            l = a->mUnk_254;
            if (l == 1 || (l == 3 && k < -0xd9a && func_02039828(&y, c) < 0)) {
                if (x.y < -0xe66) {
                    a->mUnk_254 = 3;
                    m = FALSE;
                    a->mUnk_258 = 0;
                } else {
                    a->mUnk_170 = Vec3Length(&v);
                    a->mUnk_254 = 1;
                }
            } else if (func_02039828(c, &x) > 0) {
                a->mUnk_254 = 0;
            } else {
                a->mUnk_25c = 1;
                m = FALSE;
            }
        } else if (j & 0x1e34ef) {
            if (data_021759c0->mUnk_08 != 2 || Vec3Dot(&data_usa_02154fc4, &w) < 0xfae ||
                a->mUnk_024.y - b->mUnk_80.y < data_usa_0217ac7c) {
                Vec3Add(&v, &a->mUnk_024, &a->mUnk_024);
            }
        }
    }
    if (a->mUnk_258 == 0) {
        a->mUnk_25c = 0;
    }
    if (m != FALSE && a->mUnk_25c == 0) {
        if (a->mUnk_254 == 0) {
            k = (s32) (((s64) (0x1000 - b->mUnk_2a0) * 0x5000) >> 12) + 0x3000;
            v.x = (s32) (((s64) v.x * k) >> 12);
            v.y = (s32) (((s64) v.y * k) >> 12);
            v.z = (s32) (((s64) v.z * k) >> 12);
            a->mUnk_17c = v;
            a->mUnk_170 = 0;
        }
    } else {
        a->mUnk_170 = 0;
        Vec3Sub(&v, &a->mUnk_17c, &t);
        t.x = (s32) (((s64) t.x * 0x4cd) >> 12);
        t.y = (s32) (((s64) t.y * 0x4cd) >> 12);
        t.z = (s32) (((s64) t.z * 0x4cd) >> 12);
        Vec3Add(&a->mUnk_17c, &t, &a->mUnk_17c);
        a->mUnk_254 = 3;
    }
    a->mUnk_174 = a->mUnk_174 + (s32) (((s64) (a->mUnk_170 - a->mUnk_174) * 0x11f + 0x800) >> 12);
}

static inline void func_02076528_inline(Vec3 *v, s32 k) {
    v->x = (s32) (((s64) v->x * k) >> 12);
    v->y = (s32) (((s64) v->y * k) >> 12);
    v->z = (s32) (((s64) v->z * k) >> 12);
}

void func_02076528(Unk02061808 *a, Unk0206bcb0 *b) {
    Vec3 v = b->mUnk_80;
    Vec3 g;
    Vec3 w;
    Vec3 z;
    Vec3 u;
    Vec3 q;
    Vec3 r;
    s32 s;
    s32 k;
    s32 t;
    s32 n;
    Vec3 *p;

    s = (s32) (((s64) b->mUnk_2bc * 0xcd0) >> 12);
    if (a->mUnk_258 == 0) {
        a->mUnk_134 = a->mUnk_024;
    }
    if (b->mUnk_4c & 0x20000000) {
        u = a->mUnk_260;
        func_02076528_inline(&u, a->mUnk_0f0);
    } else {
        func_02063b10(b, &u);
        func_02076528_inline(&u, a->mUnk_0f0);
    }
    if (b->mUnk_7c & 0x20) {
        if (func_020d3e18() == 0) {
            return;
        }
        t = func_020d3df4(a->mUnk_024.y - 0x5000);
        if (t < 0) {
            a->mUnk_178 = -t;
        } else {
            a->mUnk_178 = 0;
        }
        return;
    }
    Vec3Sub(&b->mUnk_80, &b->mUnk_8c, &w);
    k = 0x19a;
    if (a->mUnk_060 > a->mUnk_064) {
        k = 0xcd;
    }
    t = a->mUnk_064 - a->mUnk_060;
    a->mUnk_060 = a->mUnk_060 + (s32) (((s64) t * k + 0x800) >> 12);
    a->mUnk_068 = data_0215d4b4[((u16) a->mUnk_060 >> 4) * 2];
    a->mUnk_06a = data_0215d4b4[((u16) a->mUnk_060 >> 4) * 2 + 1];
    if (b->mUnk_48 & 0x10000) {
        a->mUnk_0e8 = a->mUnk_0e8 + (s32) (((s64) (0x14cd - a->mUnk_0e8) * 0xcd + 0x800) >> 12);
    } else {
        a->mUnk_0e8 = a->mUnk_0e8 + (s32) (((s64) (0x1000 - a->mUnk_0e8) * 0x19a + 0x800) >> 12);
    }
    w.y = 0;
    func_02063b30(b, &z);
    func_020745d4(&a->mUnk_018, &a->mUnk_0b4, &a->mUnk_0e4, b, s, a->mUnk_0d4);
    v.y = v.y - s;
    g = v;
    func_02075fe0(a, b, &u);
    func_020741a0(&a->mUnk_024, &a->mUnk_0a8, a, b, &g, &u, (s32) (((s64) a->mUnk_174 * 0x3000) >> 12));
    if (func_020d3e18() != 0) {
        t = func_020d3df4(a->mUnk_024.y - 0x5000);
        if (t < 0) {
            a->mUnk_178 = -t;
        } else {
            a->mUnk_178 = 0;
        }
    }
    func_020760ec(a, b, &u);
    p = &b->mUnk_120;
    t = 0;
    if (b->mUnk_44 & 8) {
        t = data_usa_021656c4;
        if (b->mUnk_2c4 > 0) {
            t *= -1;
        }
    }
    a->mUnk_16c = a->mUnk_16c + (s32) (((s64) (t - a->mUnk_16c) * 0xcd + 0x800) >> 12);
    n = a->mUnk_16c;
    a->mUnk_188.x = (s32) (((s64) p->x * n) >> 12);
    a->mUnk_188.y = (s32) (((s64) p->y * n) >> 12);
    a->mUnk_188.z = (s32) (((s64) p->z * n) >> 12);
    if (b->mUnk_48 & 0x40000000) {
        func_02063b30(b, &q);
    } else {
        q = data_usa_02154fc4;
    }
    Vec3Sub(&q, &a->mUnk_0c0, &r);
    r.x = (s32) (((s64) r.x * 0x800) >> 12);
    r.y = (s32) (((s64) r.y * 0x800) >> 12);
    r.z = (s32) (((s64) r.z * 0x800) >> 12);
    Vec3Add(&a->mUnk_0c0, &r, &a->mUnk_0c0);
    if (a->mUnk_248 != 0) {
        a->mUnk_0d4 = a->mUnk_0d4 - 0x1000;
        if (a->mUnk_0d4 < 0x5000) {
            a->mUnk_0d4 = 0x5000;
        }
        if (a->mUnk_0d0 == 0 && b->mUnk_80.y > a->mUnk_0cc) {
            a->mUnk_0d0 = 1;
        }
    } else if (a->mUnk_0d4 < data_usa_0217ac78) {
        a->mUnk_0d4 = a->mUnk_0d4 + 0x1000;
    } else {
        a->mUnk_0d4 = data_usa_0217ac78;
    }
    func_02073eb8(a);
}

void func_02076a5c(void) {
    Unk0206bcb0 *q;
    Unk02061808 *p;
    Vec3 m[3];
    Vec3 u;
    s32 t;

    q = func_0207a974(data_021759c0->mUnk_62);
    func_0207729c(data_0217ac94);
    if (data_021759c0->mUnk_08 == 4) {
        if (data_021759c0->mUnk_044 & 0x20) {
            (data_0217ac94)->mUnk_0f0 = -0x1000;
        }
    }
    p = data_0217ac94;
    func_01ffccd0(&m, &q->mUnk_e0);
    t = (s32) (((s64) -data_usa_0217ac90 * p->mUnk_0f0 + 0x800) >> 12);
    u.x = (s32) (((s64) m[2].x * t) >> 12);
    u.y = (s32) (((s64) m[2].y * t) >> 12);
    u.z = (s32) (((s64) m[2].z * t) >> 12);
    Vec3Add(&q->mUnk_80, &u, &p->mUnk_024);
    p->mUnk_024.y = p->mUnk_024.y + data_usa_0217ac7c;
    p->mUnk_0c0 = data_usa_02154fc4;
    p->mUnk_134 = p->mUnk_024;
    p->mUnk_088 = 0x1000;
    (data_0217ac94)->mUnk_248 = 0;
    func_020d4f94((Unk020d4f94 *) &p->mUnk_030);
    func_020d50c4();
    (data_0217ac94)->mUnk_018.y = q->mUnk_80.y + (data_0217ac94)->mUnk_0d4;
}

void func_02076bcc(Unk02061808 *a) {
    Vec3 *b = &a->mUnk_09c;
    Vec3 *c = (Vec3 *) &a->mUnk_090;

    data_021704dc[0] = *b;
    data_021704dc[1] = *(Vec3 *) a;
    data_021704dc[2] = *c;
    func_0214abb4(b, (Vec3 *) a, c, 0, &data_usa_021702c8);
    data_0217029c.mUnk_fc &= ~0xe8;
}

void func_02076c50(Unk02061808 *a, s32 b) {
    s32 c;

    if (b != 0) {
        c = a->mUnk_08c;
    } else {
        c = a->mUnk_074;
    }
    func_0214b048(a->mUnk_078, a->mUnk_07c, a->mUnk_080, a->mUnk_084, a->mUnk_070, c, 0x1000, 0, &data_usa_02170284);
    data_0217029c.mUnk_fc &= ~0x50;
}
