#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207b960.h" // Unk0207b960

#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_02010c84.h"

Unk02012f58 *func_02076cc4(void) {
    return (Unk02012f58 *) data_0217acc0;
}

static inline s32 func_020760ec_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return func_02039860(v, n);
}

static inline void func_02076528_inline(Vec3 *v, s32 k) {
    v->x = (s32) (((s64) v->x * k) >> 12);
    v->y = (s32) (((s64) v->y * k) >> 12);
    v->z = (s32) (((s64) v->z * k) >> 12);
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

void func_02076bcc(Unk02061808 *a) {
    Vec3 *b = &a->mUnk_09c;
    Vec3 *c = (Vec3 *) &a->mUnk_090;

    data_021704dc[0] = *b;
    data_021704dc[1] = *(Vec3 *) a;
    data_021704dc[2] = *c;
    func_0214abb4(b, (Vec3 *) a, c, 0, &data_usa_021702c8);
    data_0217029c.mUnk_fc &= ~0xe8;
}

void func_02076a5c(void) {
    Kart *q;
    Unk02061808 *p;
    Vec3 m[3];
    Vec3 u;
    s32 t;

    q = GetKart(data_021759c0->mEntryIndex);
    func_0207729c(data_0217ac94);
    if (data_021759c0->mMode == 4) {
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
    Vec3Add(&q->mPos, &u, &p->mUnk_024);
    p->mUnk_024.y = p->mUnk_024.y + data_usa_0217ac7c;
    p->mUnk_0c0 = data_usa_02154fc4;
    p->mUnk_134 = p->mUnk_024;
    p->mUnk_088 = 0x1000;
    (data_0217ac94)->mUnk_248 = 0;
    func_020d4f94((Unk020d4f94 *) &p->mUnk_030);
    func_020d50c4();
    (data_0217ac94)->mUnk_018.y = q->mPos.y + (data_0217ac94)->mUnk_0d4;
}

void func_02076528(Unk02061808 *a, Kart *b) {
    Vec3 v = b->mPos;
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
    if (a->mUnk_258 == FALSE) {
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
        if (func_020d3e18() == FALSE) {
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
    Vec3Sub(&b->mPos, &b->mPrevPos, &w);
    k = 0x19a;
    if (a->mUnk_060 > a->mUnk_064) {
        k = 0xcd;
    }
    t = a->mUnk_064 - a->mUnk_060;
    a->mUnk_060 = a->mUnk_060 + (s32) (((s64) t * k + 0x800) >> 12);
    a->mUnk_068 = gPairsByAngle[((u16) a->mUnk_060 >> 4) * 2];
    a->mUnk_06a = gPairsByAngle[((u16) a->mUnk_060 >> 4) * 2 + 1];
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
    if (func_020d3e18() != FALSE) {
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
        if (a->mUnk_0d0 == FALSE && b->mPos.y > a->mUnk_0cc) {
            a->mUnk_0d0 = TRUE;
        }
    } else if (a->mUnk_0d4 < data_usa_0217ac78) {
        a->mUnk_0d4 = a->mUnk_0d4 + 0x1000;
    } else {
        a->mUnk_0d4 = data_usa_0217ac78;
    }
    func_02073eb8(a);
}

void func_020760ec(Unk02061808 *a, Kart *b, Vec3 *c) {
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
    a->mUnk_258 = FALSE;
    if (func_01ffdee4(&a->mUnk_024, (u32 *) &a->mUnk_134, 0, data_usa_021656c0, 2, -2, &v, &w, (s32 *) &x, &j, NULL,
                      NULL, NULL, NULL) != 0 &&
        (j & 0xc00) == 0) {
        if (j & 0x214300) {
            y = b->mUnk_50;
            if (b->mForwardSpeed <= 0) {
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
            a->mUnk_258 = TRUE;
            k = func_02039828(&y, &x);
            m = TRUE;
            l = a->mUnk_254;
            if (l == 1 || (l == 3 && k < -0xd9a && func_02039828(&y, c) < 0)) {
                if (x.y < -0xe66) {
                    a->mUnk_254 = 3;
                    m = FALSE;
                    a->mUnk_258 = FALSE;
                } else {
                    a->mUnk_170 = Vec3Length(&v);
                    a->mUnk_254 = 1;
                }
            } else if (func_02039828(c, &x) > 0) {
                a->mUnk_254 = 0;
            } else {
                a->mUnk_25c = TRUE;
                m = FALSE;
            }
        } else if (j & 0x1e34ef) {
            if (data_021759c0->mMode != 2 || Vec3Dot(&data_usa_02154fc4, &w) < 0xfae ||
                a->mUnk_024.y - b->mPos.y < data_usa_0217ac7c) {
                Vec3Add(&v, &a->mUnk_024, &a->mUnk_024);
            }
        }
    }
    if (a->mUnk_258 == FALSE) {
        a->mUnk_25c = FALSE;
    }
    if (m != FALSE && a->mUnk_25c == FALSE) {
        if (a->mUnk_254 == 0) {
            k = (s32) (((s64) (0x1000 - b->mVelocityLengthRatio) * 0x5000) >> 12) + 0x3000;
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

void func_02075fe0(Unk02061808 *a, Kart *b, Vec3 *c) {
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

void func_02075eb8(void) {
    Unk02061808 *p = data_0217acbc;
    Unk020748b8_218 *q;
    Unk020f41c4_B *r;

    q = (Unk020748b8_218 *) gCourseMap->mUnk_cc;
    if (q == NULL) {
        return;
    }
    p->mUnk_228 = TRUE;
    p->mUnk_218 = q;
    p->mUnk_240 = 0;
    p->mUnk_068 = q->mUnk_32;
    p->mUnk_06a = q->mUnk_34;
    p->mUnk_130 = q->mUnk_4b;
    if ((s16) q->mUnk_40 != -1) {
        func_0207be40(&p->mUnk_194, q);
        if (data_021759c0->mMode == 2) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (func_0203c880(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
        r = &data_0217561c->mUnk_498;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    }
    data_0217aca8 = 1;
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
    if (p->mUnk_228 == FALSE) {
        return;
    }
    p->mUnk_228 = FALSE;
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
        if (data_021759c0->mMode == 2) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (func_0203c880(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
        r = &data_0217561c->mUnk_498;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    }
    data_0217aca8 = 1;
}

u32 func_02075cf0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217acbc;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (564)) = value1;
    return value0;
}

static inline void func_02074b00_inline(Vec3 *v, const Vec3 *u, s32 s) {
    v->x = (s32) (((s64) u->x * s) >> 12);
    v->y = (s32) (((s64) u->y * s) >> 12);
    v->z = (s32) (((s64) u->z * s) >> 12);
}

BOOL func_02075a94(Unk02061808 *p) {
    BOOL r = TRUE;
    Unk020748b8_218 *q;
    Vec3 v;
    s32 i;

    p->mUnk_134 = p->mUnk_024;
    data_0217acac = 1;
    if (data_021759c0->mUnk_00c == 6) {
        func_02074b00(p);
        return TRUE;
    }
    if (p->mUnk_230 != 0 || p->mUnk_234 != 0) {
        return FALSE;
    }
    p->mUnk_134 = p->mUnk_024;
    if (p->mUnk_238 != FALSE) {
        func_02074e6c(p);
        return TRUE;
    }
    func_0207a948(&v, p->mUnk_210);
    i = func_020411e4(&v);
    if (p->mUnk_228 != FALSE) {
        if (data_021759c0->mMode == 2) {
            func_02075900(p);
            return TRUE;
        }
        p->mUnk_22c = p->mUnk_22c + 1;
        if (p->mUnk_22c >= 300) {
            p->mUnk_228 = FALSE;
        }
    }
    if (i == -1) {
        r = FALSE;
    } else {
        Unk020f41c4_B *b;

        q = gCourseMap->mUnk_7c + (u16) i;
        if (i != p->mUnk_214) {
            p->mUnk_214 = i;
            if (p->mUnk_228 == FALSE) {
                p->mUnk_218 = q;
                p->mUnk_240 = 0;
                p->mUnk_068 = q->mUnk_32;
                p->mUnk_06a = q->mUnk_34;
                p->mUnk_130 = q->mUnk_4b;
                if ((s16) q->mUnk_40 != -1) {
                    func_0207be40(&p->mUnk_194, q);
                    if (data_021759c0->mMode == 2) {
                        func_0207bd6c(&p->mUnk_1d0, q);
                    }
                }
                if (func_0203c880(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
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

void func_02075900(Unk02061808 *p) {
    Unk020748b8_218 *a;
    s32 b;
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
    a = p->mUnk_218;
    if (a->mUnk_3c != 0) {
        enum { K0 } t = p->mUnk_240;
        Unk020748b8_218 *q = a;

        s32 x0 = q->mUnk_32;
        s32 y0 = q->mUnk_34;
        s32 y1 = q->mUnk_3a;
        s32 x1 = q->mUnk_38;
        s32 v1 = x1 - x0;
        s32 v2 = y1 - y0;

        b = ((s64) v2 * t) >> 12;
        p->mUnk_068 = x0 + (s32) (((s64) v1 * t) >> 12);
        p->mUnk_06a = y0 + (s32) b;
        p->mUnk_240 += q->mUnk_3c;
        if (p->mUnk_240 > 0x1000) {
            p->mUnk_240 = 0x1000;
        }
    } else {
        p->mUnk_068 = a->mUnk_32;
        p->mUnk_06a = a->mUnk_34;
    }
}

void func_020757d8(void) {
    Unk02061808 *p;
    Unk020748b8_218 *q;
    Unk020f41c4_B *b;

    p = data_0217acbc;
    q = gCourseMap->mUnk_d4;

    if (q == NULL) {
        return;
    }
    p->mUnk_238 = TRUE;
    p->mUnk_218 = q;
    p->mUnk_240 = 0;
    p->mUnk_068 = q->mUnk_32;
    p->mUnk_06a = q->mUnk_34;
    p->mUnk_130 = q->mUnk_4b;
    if ((s16) q->mUnk_40 != -1) {
        func_0207be40(&p->mUnk_194, q);
        if (data_021759c0->mMode == 2) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (func_0203c880(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
        b = &data_0217561c->mUnk_498;
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    }
    data_0217aca8 = 1;
}

static inline void func_02075424_inline(Unk02061808 *p) {
    Unk020748b8_218 *q;

    if (p->mUnk_218->mUnk_48 == -1) {
        q = NULL;
    } else {
        q = gCourseMap->mUnk_7c + (u16) p->mUnk_218->mUnk_48;
    }
    if (q == NULL) {
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

Unk02012f58 *func_02075694(void) {
    if (data_usa_0217ac84->mUnk_218 != NULL) {
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

Unk02012f58 *func_0207564c(void) {
    func_02075424(data_usa_0217ac98);
    func_02076cd0(data_usa_0217ac98);
    data_0217acb4 = data_usa_0217ac98;
    return &data_usa_0217ac98->mUnk_030;
}

void func_02075424(Unk02061808 *p) {
    if (p->mUnk_218 == NULL) {
        return;
    }
    func_02075900(p);
    p->mUnk_23c = p->mUnk_23c + 1;
    if (p->mUnk_23c != p->mUnk_218->mUnk_46) {
        return;
    }
    func_02075424_inline(p);
    if (p->mUnk_218 == NULL) {
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

void func_02074e6c(Unk02061808 *p) {
    Unk020748b8_218 *q = p->mUnk_218;
    Kart *o;
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
    o = GetKart(p->mUnk_210);
    a = o->mUnk_138;
    i = (u16) ((s32) (((s64) q->mUnk_18.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    j = (u16) ((s32) (((s64) q->mUnk_18.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    k = (u16) ((s32) (((s64) q->mUnk_24.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    l = (u16) ((s32) (((s64) q->mUnk_24.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) m0, &o->mUnk_120, gPairsByAngle[(o->mUnk_2c0 >> 4) * 2],
                                           gPairsByAngle[(o->mUnk_2c0 >> 4) * 2 + 1]);
    Vec3MultiplyMatrix3x3(&a, m0, &a);
    b = a;
    c = b;
    d = b;
    func_02074b00_inline(&n, &d, -q->mUnk_18.z);
    func_020397a8(&data_usa_02154fc4, &a, &f);
    func_020397a8(&c, &f, &g);
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) m2, &g, gPairsByAngle[(i >> 4) * 2],
                                           gPairsByAngle[(i >> 4) * 2 + 1]);
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) m3, &f, gPairsByAngle[(j >> 4) * 2],
                                           gPairsByAngle[(j >> 4) * 2 + 1]);
    Matrix3x3Multiply(m3, m2, m4);
    Vec3MultiplyMatrix3x3(&d, m4, &d);
    func_02074b00_inline(&t, &d, q->mUnk_18.z);
    Vec3Add(&p->mUnk_018, &t, &p->mUnk_024);
    f.x = -f.x;
    f.y = -f.y;
    f.z = -f.z;
    g.x = -g.x;
    g.y = -g.y;
    g.z = -g.z;
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) m5, &g, gPairsByAngle[(k >> 4) * 2],
                                           gPairsByAngle[(k >> 4) * 2 + 1]);
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) m6, &f, gPairsByAngle[(l >> 4) * 2],
                                           gPairsByAngle[(l >> 4) * 2 + 1]);
    Matrix3x3Multiply(m5, m2, m5);
    Matrix3x3Multiply(m6, m3, m6);
    Matrix3x3Multiply(m6, m5, m7);
    Vec3MultiplyMatrix3x3(&n, m7, &n);
    Vec3Add(&p->mUnk_024, &n, &p->mUnk_018);
    p->mUnk_018.y = p->mUnk_018.y - o->mUnk_2bc;
    p->mUnk_024.y = p->mUnk_024.y - o->mUnk_2bc;
    if (data_021759c0->mMode != 4 && data_021759c0->mMode != 2) {
        if (func_01ffdee4(&p->mUnk_024, (u32 *) &p->mUnk_134, 0, data_usa_021656c0 >> 1, 2, -2, &w, NULL, NULL, NULL,
                          NULL, NULL, NULL, NULL) != 0) {
            o = GetKart(p->mUnk_210);
            v = &o->mUnk_120;
            k = Vec3Dot(v, &w);
            w.x = (s32) (((s64) o->mUnk_120.x * k) >> 12);
            w.y = (s32) (((s64) v->y * k) >> 12);
            w.z = (s32) (((s64) v->z * k) >> 12);
            Vec3Add(&w, &p->mUnk_024, &p->mUnk_024);
        }
    }
    func_02076cd0(p);
}

void func_02074b00(Unk02061808 *p) {
    Kart *o = GetKart(p->mUnk_210);
    Unk020748b8_218 *q = p->mUnk_218;
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 m[9];

    p->mUnk_0b4 = p->mUnk_018;
    b = o->mPos;
    Vec3AddScaled(q->mUnk_00.z, &o->mUnk_120, &o->mPos, &a);
    a.y = 0x1f4000;
    b.y = 0x1f4000;
    c = o->mUnk_138;
    c.y = 0;
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 0x10) {
        func_02039860(&c, &c);
    }
    func_02074b00_inline(&c, &c, q->mUnk_00.x);
    Vec3Add(&a, &c, &a);
    Vec3Add(&b, &c, &b);
    if (func_02061fb8() < q->mUnk_46) {
        p->mUnk_018 = b;
        p->mUnk_024 = a;
    } else if (p->mUnk_144 < 0x1000) {
        p->mUnk_018 = b;
        p->mUnk_024 = a;
        p->mUnk_144 = p->mUnk_144 + 0x52;
        Vec3Sub(&p->mUnk_134, &p->mUnk_024, &p->mUnk_0a8);
        Vec3Sub(&p->mUnk_0b4, &p->mUnk_018, &p->mUnk_0b4);
        Vec3AddScaled(p->mUnk_144, &p->mUnk_0a8, &a, &p->mUnk_024);
        Vec3AddScaled(p->mUnk_144, &p->mUnk_0b4, &b, &p->mUnk_018);
    }
    func_02076cd0(p);
    Vec3Sub(&a, &b, &d);
    if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z >= 0x10) {
        func_02039860(&d, &d);
    }
    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) m, &data_usa_02154fc4,
                                           gPairsByAngle[(data_usa_021656a0 >> 4) * 2],
                                           gPairsByAngle[(data_usa_021656a0 >> 4) * 2 + 1]);
    Vec3MultiplyMatrix3x3(&d, m, &d);
    d.x = (s32) (((s64) d.x * 0xfae) >> 12);
    d.y = (s32) (((s64) d.y * 0xfae) >> 12);
    d.z = (s32) (((s64) d.z * 0xfae) >> 12);
    func_02062254(&d);
    q = p->mUnk_218;
    if (q->mUnk_3c != 0) {
        s32 r;
        enum { K0 } t = p->mUnk_240;
        s32 x0 = q->mUnk_32;
        s32 y0 = q->mUnk_34;
        s32 y1 = q->mUnk_3a;
        s32 x1 = q->mUnk_38;
        s32 v1 = x1 - x0;
        s32 v2 = y1 - y0;

        r = ((s64) v2 * t) >> 12;
        p->mUnk_068 = x0 + (s32) (((s64) v1 * t) >> 12);
        p->mUnk_06a = y0 + (s32) r;
        p->mUnk_240 += q->mUnk_3c;
        if (p->mUnk_240 > 0x1000) {
            p->mUnk_240 = 0x1000;
        }
    } else {
        p->mUnk_068 = q->mUnk_32;
        p->mUnk_06a = q->mUnk_34;
    }
}

void func_020749a4(Unk02061808 *p, s32 a) {
    Unk020748b8_218 *q = p->mUnk_218;
    u16 n = gCourseMap->mEntryGroups[q->mUnk_40].mEntryCount;
    Unk02042044 *e0;
    Unk02042044 *e1;
    Vec3 v;
    Vec3 d;
    Vec3 s;
    s32 m;

    if (n >= 4) {
        func_0207bc9c(&p->mUnk_024, &p->mUnk_194, q, a);
        return;
    }
    if (n < 2) {
        return;
    }
    e0 = GetCourseMapGroupEntry(q->mUnk_40, 0);
    e1 = GetCourseMapGroupEntry(q->mUnk_40, 1);
    v = e0->mUnk_00;
    Vec3Sub(&e1->mUnk_00, &e0->mUnk_00, &d);
    if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < 0x10) {
        m = 0;
    } else {
        m = func_02039860(&d, &d);
    }
    p->mUnk_194.mUnk_30 += a;
    if (p->mUnk_194.mUnk_30 >= 0x1000) {
        p->mUnk_194.mUnk_30 = 0x1000;
    }
    m = (s32) (((s64) p->mUnk_194.mUnk_30 * m) >> 12);
    s.x = (s32) (((s64) d.x * m) >> 12);
    s.y = (s32) (((s64) d.y * m) >> 12);
    s.z = (s32) (((s64) d.z * m) >> 12);
    Vec3Add(&v, &s, &p->mUnk_024);
}

void func_02074978(Unk02061808 *p) {
    func_020749a4(p, p->mUnk_218->mUnk_42);
    func_020748b8(p);
    func_02076ed4(p);
}

void func_020748b8(Unk02061808 *p) {
    Unk020748b8_218 *q = p->mUnk_218;
    s32 a, b, c;
    s32 d, e, f;
    s32 x, y, z;
    s64 t;

    if (q->mUnk_44 != 0) {
        t = p->mUnk_244;
        a = q->mUnk_18.x;
        d = q->mUnk_24.x - a;
        x = (s32) ((d * t) >> 12);
        b = q->mUnk_18.y;
        e = q->mUnk_24.y - b;
        y = (s32) ((e * t) >> 12);
        c = q->mUnk_18.z;
        f = q->mUnk_24.z - c;
        z = (s32) ((f * t) >> 12);
        p->mUnk_018.x = a + x;
        p->mUnk_018.y = b + y;
        p->mUnk_018.z = c + z;
        p->mUnk_244 += q->mUnk_44;
        if (p->mUnk_244 > 0x1000) {
            p->mUnk_244 = 0x1000;
        }
    } else {
        p->mUnk_018.x = q->mUnk_18.x;
        p->mUnk_018.y = q->mUnk_18.y;
        p->mUnk_018.z = q->mUnk_18.z;
    }
}

void *func_020748a8(void) {
    return data_0217ac94;
}

Unk02061808 *func_02074898(void) {
    return data_0217acbc;
}

Unk02061808 *func_02074888(void) {
    return data_0217acb4;
}

void func_02074874(u32 p0) {
    data_0217ac94->mUnk_064 = p0;
}

void func_02074854(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &data_0216569c;
    value0 = (u32) &data_0217ac94;
    value1 = (u32) * (const u16 *) ((value1) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (100)) = value1;
}

void func_02074828(void) {
    s32 t;

    t = data_0216569c;
    data_0217ac94->mUnk_064 = t;
    data_0217ac94->mUnk_060 = t + 5;
}

void func_020747f4(s32 a) {
    data_0217ac94->mUnk_248 = a;
    if (a == 0) {
        return;
    }
    data_0217ac94->mUnk_0cc = data_0217ac94->mUnk_024.y;
    data_0217ac94->mUnk_0d0 = FALSE;
}

void func_020745d4(Vec3 *a, Vec3 *b, s32 *c, Kart *d, s32 e, s32 f) {
    Vec3 v4;
    Vec3 v10;
    Vec3 v1;
    Vec3 v28;
    s32 t;

    v4 = d->mPos;
    v10 = d->mPos;
    v10.y = v10.y - e;
    Vec3AddScaled(f, &d->mUnk_12c, &v10, &v10);
    v4.y = v4.y + (f - e);
    if (!(d->mUnk_48 & 0x40000000)) {
        v1 = data_usa_02154fdc;
    } else {
        Vec3Sub(&v10, &v4, &v1);
        Vec3AddScaled(0xa000, &d->mUnk_12c, &v1, &v1);
    }
    Vec3Sub(&v1, b, &v28);
    v28.x = (s32) (((s64) v28.x * 0x266) >> 12);
    v28.y = (s32) (((s64) v28.y * 0x266) >> 12);
    v28.z = (s32) (((s64) v28.z * 0x266) >> 12);
    Vec3Add(b, &v28, b);
    Vec3Add(&v4, b, &v4);
    a->x = v4.x;
    a->z = v4.z;
    if (d->mUnk_48 & 0x10000) {
        *c = *c + 0x1000;
        if (*c > 0xa000) {
            *c = 0xa000;
        }
    } else {
        t = *c;
        *c = t + (s32) (((s64) -t * 0x29 + 0x800) >> 12);
    }
    v4.y = v4.y - *c;
    t = a->y;
    a->y = t + (s32) (((s64) (v4.y - t) * 0xccd + 0x800) >> 12);
}

void func_020741a0(Vec3 *a, Vec3 *b, Unk02061808 *c, Kart *d, Vec3 *e, const Vec3 *f, s32 g) {
    Vec3 v4;
    Vec3 v10;
    Vec3 v1;
    Vec3 v28;
    Vec3 v34;
    Vec3 v40;
    Vec3 v2;
    Vec3 v58;
    Vec3 v64;
    Vec3 v70;
    Vec3 v3;
    Vec3 v88;
    Vec3 v94;
    s32 h;
    s32 i;
    s32 j;
    s32 k;

    v1 = *f;
    h = c->mUnk_0dc - g;
    func_02063b30(d, &v10);
    if (h < 500) {
        h = 500;
    }
    Vec3Sub(&d->mPos, &d->mPrevPos, &v4);
    if (d->mUnk_48 & 0x1000) {
        if (d->mUnk_4c & 0x4000000) {
            return;
        }
        c->mUnk_088 = (s32) (((s64) c->mUnk_088 * 0xe66) >> 12);
        Vec3AddScaled(c->mUnk_088, &v4, a, a);
        return;
    }
    v4.y = 0;
    Vec3Add(a, &v4, a);
    i = -h;
    v2.x = (s32) (((s64) v1.x * i) >> 12);
    v2.y = (s32) (((s64) v1.y * i) >> 12);
    v2.z = (s32) (((s64) v1.z * i) >> 12);
    Vec3Add(&v2, &c->mUnk_188, &v2);
    Vec3Add(&v2, &c->mUnk_17c, &v2);
    Vec3AddScaled(data_usa_0217ac7c, &v10, &v2, &v3);
    Vec3Add(e, &v3, &v70);
    v2.y = data_usa_0217ac7c;
    Vec3Add(e, &v2, &v64);
    v40 = v64;
    v40.y = v40.y + c->mUnk_168;
    if (!(d->mUnk_48 & 0x40000000)) {
        v88 = data_usa_02154fdc;
    } else {
        Vec3Sub(&v70, &v40, &v88);
        Vec3AddScaled(-0x1e000, &v10, &v88, &v88);
    }
    Vec3Sub(&v88, b, &v94);
    v94.x = (s32) (((s64) v94.x * 0x19a) >> 12);
    v94.y = (s32) (((s64) v94.y * 0x19a) >> 12);
    v94.z = (s32) (((s64) v94.z * 0x19a) >> 12);
    Vec3Add(b, &v94, b);
    Vec3Add(&v40, b, &v40);
    Vec3Sub(&v40, a, &v58);
    j = v58.y;
    k = 0;
    v58.y = 0;
    if ((s64) v58.x * v58.x + (s64) v58.y * v58.y + (s64) v58.z * v58.z >= 16) {
        k = func_02039860(&v58, &v58);
    }
    Vec3AddScaled((s32) (((s64) k * 0x11f) >> 12), &v58, a, a);
    a->y = a->y + ((s32) (((s64) j * 0x11f) >> 9) + g * 2);
    if (c->mUnk_248 != 0) {
        if (c->mUnk_0d0 != FALSE) {
            s32 l;
            l = a->y - c->mUnk_0cc;
            c->mUnk_0cc = c->mUnk_0cc + (s32) (((s64) l * 0x29 + 0x800) >> 12);
        }
        a->y = c->mUnk_0cc;
    }
    Vec3Sub(a, e, &v28);
    v34 = v28;
    k = 0;
    if ((s64) v34.x * v34.x + (s64) v34.y * v34.y + (s64) v34.z * v34.z >= 16) {
        k = func_02039860(&v34, &v34);
    }
    if (k == 0) {
        return;
    }
    Vec3AddScaled((s32) (((s64) c->mUnk_0dc * c->mUnk_0e8) >> 12), &v34, e, a);
}

void func_0207409c(const Vec3 *a, void *b) {
    Unk02061808 *p;
    Vec3 m[3];
    Vec3 v;
    s32 t;

    p = data_0217ac94;
    func_01ffccd0(m, b);
    t = (s32) (((s64) -data_usa_0217ac90 * p->mUnk_0f0 + 0x800) >> 12);
    v.x = (s32) (((s64) m[2].x * t) >> 12);
    v.y = (s32) (((s64) m[2].y * t) >> 12);
    v.z = (s32) (((s64) m[2].z * t) >> 12);
    Vec3Add(a, &v, &p->mUnk_024);
    p->mUnk_024.y = p->mUnk_024.y + data_usa_0217ac7c;
    p->mUnk_0c0 = data_usa_02154fc4;
    p->mUnk_134 = p->mUnk_024;
    p->mUnk_088 = 0x1000;
    data_0217ac94->mUnk_248 = 0;
    func_020d4f94((Unk020d4f94 *) &p->mUnk_030);
    func_020d50c4();
}

void func_02073fc8(s32 a, u32 b, s32 c) {
    Unk02061808 *p;
    s32 d;
    s32 t;

    d = 0x1000;
    p = data_0217ac94;
    if (b > 1000000) {
        return;
    }
    if (b > 0x57e40) {
        d = 0x4cd;
    } else if (b > 0x15f90) {
        d = 0x99a;
    }
    t = (s32) (((s64) a * (s32) (((s64) c * d) >> 12)) >> 12);
    if (p->mUnk_140 != FALSE && p->mUnk_148 > t) {
        return;
    }
    p->mUnk_148 = t;
    p->mUnk_140 = TRUE;
    p->mUnk_144 = 0;
    p->mUnk_14c = 0x800;
    p->mUnk_150 = 1;
    p->mUnk_154 = 0xe66;
    p->mUnk_158 = 0;
}

void func_02073fb0(u32 a, s32 b) {
    func_02073fc8(0x2800, a, b);
}

void func_02073f90(void) {
    func_02073fc8(data_usa_021656b4, 0, 0x1000);
}

void func_02073eb8(Unk02061808 *p) {
    s32 t;
    BOOL u;

    if (p->mUnk_140 == FALSE) {
        return;
    }
    p->mUnk_144 = p->mUnk_144 + p->mUnk_14c * p->mUnk_150;
    t = p->mUnk_144;
    if (t > 0x1000) {
        p->mUnk_150 *= -1;
        p->mUnk_144 = 0x2000 - p->mUnk_144;
    } else if (t < -0x1000) {
        p->mUnk_150 *= -1;
        p->mUnk_144 = -0x2000 - p->mUnk_144;
    }
    p->mUnk_148 = (s32) (((s64) p->mUnk_148 * p->mUnk_154) >> 12);
    p->mUnk_148 = p->mUnk_148 - 0x14;
    p->mUnk_158 = (s32) (((s64) p->mUnk_144 * p->mUnk_148) >> 12);
    if (p->mUnk_148 <= 0) {
        u = FALSE;
        p->mUnk_158 = u;
        p->mUnk_140 = u;
    }
}
