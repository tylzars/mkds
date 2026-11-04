#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02109000.h"

#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020720dc.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02089d14.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a588.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210b564.h"

Unk0210bf24 *func_020719bc(Unk0210bfbc *p, u32 a) {
    u32 value0 = (u32) p;
    u32 value1 = a;
    u32 value2;
    u32 value3;
    u32 value12;
    value12 = (u32) &func_021090c4;
    value2 = 0x7fu;
    value3 = 0u;
    return func_021090c4((Unk0210bfbc *) value0, value1, value2, value3);
}

void func_020719a8(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value12 = (u32) &func_02109078;
    value2 = 0x7fu;
    value3 = 0u;
    func_02109078((Unk0210bfbc *) value0, value1, value2, value3);
}

void func_02071980(void *p, int b) {
    func_0210b2a8((Unk0206bcb0 *) p, b, ((Unk0206bcb0 *) p)->mUnk_3e0, ((Unk0206bcb0 *) p)->mUnk_3e4,
                  ((Unk0206bcb0 *) p)->mUnk_500);
}

void func_02071958(Unk0206bcb0 *p, s32 b) {
    func_0210b564(&p->mUnk_00, b, p->mUnk_3e0, p->mUnk_3e4, p->mUnk_500);
}

void func_02071944(void *p, int v1) {
    u32 v2 = (u32) p;
    u32 v3 = (u32) v1;
    u32 v4;
    u32 v5;
    u32 v6;
    v6 = (u32) &func_021090c4;
    v4 = 0x7fu;
    v5 = 0u;
    func_021090c4((Unk0210bfbc *) v2, v3, v4, v5);
    return;
}

void func_02071914(void *p, int a) {
    if (func_02109078((Unk0210bfbc *) p, a, 0x7f, 0) != NULL) {
        ((Unk0206bcb0 *) p)->mUnk_488 = a;
    }
}

void func_020718c8(void *p, int v1) {
    int v;

    v = func_02086080(((Unk0206bcb0 *) p)->mIndex);
    func_0210ddf4(&data_0217d284, v + func_0210a588(), func_02071914, p, v1);
}

void func_02071894(Unk0206bcb0 *p) {
    if (p->mUnk_48 & 0x840) {
        return;
    }
    func_0210af40(p, p->mUnk_3cc, 7);
}

void func_02071788(Unk0206bcb0 *p) {
    p->mUnk_3fe++;
    if (p->mUnk_3fe >= p->mUnk_400) {
        p->mUnk_3fe = 0;
        p->mUnk_4c &= ~8;
        return;
    }
    if (p->mUnk_3fc == 0) {
        p->mUnk_404 = data_02154be4[p->mUnk_3fe];
        p->mUnk_408 = data_02154c20[p->mUnk_3fe];
        p->mUnk_418 = 0x1000;
        p->mUnk_414 = p->mUnk_418;
    } else if (p->mUnk_3fc == 1) {
        p->mUnk_404 = data_02154c5c[p->mUnk_3fe];
        p->mUnk_408 = data_02154c98[p->mUnk_3fe];
        p->mUnk_418 = 0x1000;
        p->mUnk_414 = p->mUnk_418;
    } else if (p->mUnk_3fc == 2) {
        p->mUnk_404 = 0x1000;
        p->mUnk_408 = data_02154c20[p->mUnk_3fe];
        p->mUnk_414 = data_02154cd4[p->mUnk_3fe];
        p->mUnk_418 = data_02154d10[p->mUnk_3fe];
    }
}

void func_02071568(Unk0206bcb0 *p) {
    s32 f;
    u16 i;
    u16 j;
    s32 v;
    s32 s;
    s32 t;

    p->mUnk_4ec = p->mUnk_4ec + p->mUnk_4e8;
    t = p->mUnk_4ec - 0x8000;
    if (t >= 0) {
        p->mUnk_4ec = t;
    }
    f = p->mUnk_4ec & 0xfff;
    i = (u16) (p->mUnk_4ec >> 12);
    j = i + 1;
    if (j >= 8) {
        j = 0;
    }
    p->mUnk_4f0.x = data_02154b64[i] + (s32) (((s64) ((data_02154b64[j] - data_02154b64[i]) >> 1) * f) >> 12);
    p->mUnk_4f0.y = data_02154b84[i] + (s32) (((s64) ((data_02154b84[j] - data_02154b84[i]) >> 1) * f) >> 12);
    p->mUnk_4f0.z = data_02154ba4[i] + (s32) (((s64) ((data_02154ba4[j] - data_02154ba4[i]) >> 1) * f) >> 12);
    v = p->mUnk_4d4;
    s = (s32) (((s64) v * 0x333) >> 12);
    if (v > 0xf33) {
        t = (s32) (((s64) ((v - 0xf33) * 0x32) * 0x19a) >> 12);
        if (t > 0x19a) {
            t = 0x19a;
        }
        t = t + 0x333;
        s = (s32) (((s64) v * t) >> 12);
    } else if (v > 0xd9a) {
        t = (s32) (((s64) ((v - 0xd9a) * 0x32) * 0x52) >> 12);
        if (t > 0x52) {
            t = 0x52;
        }
        t = t + 0x333;
        s = (s32) (((s64) v * t) >> 12);
    }
    p->mUnk_4f0.x = p->mUnk_4f0.x + (s32) (((s64) p->mUnk_4f0.x * s) >> 12);
    p->mUnk_4f0.y = p->mUnk_4f0.y + (s32) (((s64) p->mUnk_4f0.y * s) >> 12);
    p->mUnk_4f0.z = p->mUnk_4f0.z + (s32) (((s64) p->mUnk_4f0.z * s) >> 12);
}

void func_020713a0(Unk0206bcb0 *p) {
    s32 t;

    if (p->mUnk_4e4 <= 2) {
        p->mUnk_4e0 = p->mUnk_4e2 * 0x3c + p->mUnk_4e0;
        if (p->mUnk_4e0 > 0x17c) {
            p->mUnk_4e0 = 0x17c;
        } else if (p->mUnk_4e0 < -0x17c) {
            p->mUnk_4e0 = -0x17c;
        }
        p->mUnk_4de = p->mUnk_4de + p->mUnk_4e0;
        t = p->mUnk_4de;
        if ((t > 0 ? t : -t) > 0x1770) {
            if ((t > 0 && p->mUnk_4e2 > 0) || (t < 0 && p->mUnk_4e2 < 0)) {
                p->mUnk_4e2 *= -1;
                p->mUnk_4e4 = p->mUnk_4e4 + 1;
            }
        }
        p->mUnk_4d4 = 0x1000;
    } else {
        p->mUnk_4e0 = p->mUnk_4e2 * 0x3c + p->mUnk_4e0;
        if (p->mUnk_4e0 > 0xd2) {
            p->mUnk_4e0 = 0xd2;
        } else if (p->mUnk_4e0 < -0xd2) {
            p->mUnk_4e0 = -0xd2;
        }
        p->mUnk_4de = p->mUnk_4de + p->mUnk_4e0;
        p->mUnk_4d4 = (s32) (((s64) p->mUnk_4d4 * 0xf5c) >> 12);
        t = p->mUnk_4de;
        if ((t > 0 && p->mUnk_4e2 > 0) || (t < 0 && p->mUnk_4e2 < 0)) {
            p->mUnk_4de = 0;
            p->mUnk_4c &= ~0x20000000;
            func_02068a64(p, 0, 1);
            p->mUnk_44 |= 0x1000000;
        }
    }
}

void func_02071318(Unk0206bcb0 *p, s32 a) {
    s32 k;

    k = p->mState;
    if (k != 0 && k != 6) {
        return;
    }
    if (a == 2) {
        p->mUnk_3fc = 2;
    } else if (p->mUnk_44 & 2) {
        p->mUnk_3fc = 1;
    } else if (p->mUnk_380 > 0xa) {
        p->mUnk_3fc = 1;
    } else {
        p->mUnk_3fc = 0;
    }
    p->mUnk_3fe = 0;
    p->mUnk_400 = 0xf;
    p->mUnk_4c |= 8;
}

void func_020710b0(Unk0206bcb0 *p, s32 b) {
    Unk0212c400 **h;
    Unk0210bf24 *d;

    if (b == 0) {
        p->mUnk_48 |= 0x40000;
        p->mUnk_44 &= ~0x10;
    }
    p->mUnk_48 &= 0xdfe77fdf;
    p->mUnk_238 = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mUnk_23c = 0;
    if (p->mUnk_7c & 1) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            func_02074854();
        }
        func_02055c5c();
    }
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
    func_02080fb8(p);
    p->mUnk_44 &= 0xfffff7f4;
    p->mUnk_2c4 = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_30c = 0;
    func_0208c534(func_0208c5b8(p->mIndex));
    p->mState = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    func_02072600(p);
    func_02070f8c(p);
    if (!(p->mUnk_7c & 1)) {
        return;
    }
    func_02073f90();
    switch (data_021759c0->mCourseId) {
        case 0x13:
            func_02089d14(0);
            d = func_021090c4((Unk0210bfbc *) p, 0x15c, 0x7f, 0);
            if (d != NULL) {
                d->mUnk_19 |= 0x10;
            }
            h = func_02108e6c(7);
            if (!(data_0217c780 & 1)) {
                return;
            }
            if (data_0217d084.mUnk_0c == 0) {
                return;
            }
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            func_0212ecc0(h, 0, 0x1d2);
            break;
        case 0x21:
            d = func_021090c4((Unk0210bfbc *) p, 0x15b, 0x7f, 0);
            if (d != NULL) {
                d->mUnk_19 |= 0x10;
            }
            break;
    }
}

void func_02070f8c(Unk0206bcb0 *p) {
    s32 q[2];
    Vec3 v;
    Vec3 u;
    Unk02061808 *r;
    Vec3 *c;
    BOOL v1;
    s32 n;
    s32 i;
    s32 *v2;
    s32 *w;

    v = data_0216553c;
    v1 = TRUE;
    r = func_02061808();
    c = &r->mUnk_024;
    if (c->x > -0x64f000) {
        if (c->x < -0x3cb000) {
            if (c->z > -0x1ad7000) {
                if (c->z < -0x164d000) {
                    v1 = FALSE;
                }
            }
        }
    }
    if (v1 != FALSE) {
        u = data_02165548;
        w = q;
        q[0] = data_02165510[0];
        q[1] = data_02165510[1];
        n = 3;
        v2 = (s32 *) &u;
        if (!(p->mUnk_7c & 1)) {
            n = 2;
            v2 = w;
        }
        for (i = 0; i < n; i++) {
            func_0208b7bc(*v2, &v);
            v2++;
        }
    } else {
        func_0208b7bc((p->mUnk_7c & 1) ? 0x47 : 0x52, &v);
    }
}

static inline s32 func_020708a4_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return func_02039860(v, n);
}

void func_020708a4(Unk0206bcb0 *p) {
    Unk0206ceb4 *s;
    u16 i;
    s32 d;
    s32 k;
    s32 t;
    u32 w;
    Vec3 a;
    Vec3 b;
    Vec3 n;
    Vec3 c;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 h;
    Vec3 l;
    Unk02012f58 m2;
    s32 m1[9];
    Vec3 q;

    b = data_02154f94;
    i = *gCourseMap->mUnk_fc;
    a.x = gCourseMap->mUnk_34[i].mUnk_00.x;
    a.y = gCourseMap->mUnk_34[i].mUnk_00.y;
    a.z = gCourseMap->mUnk_34[i].mUnk_00.z;
    b.x = gCourseMap->mUnk_34[*gCourseMap->mUnk_fc].mUnk_0c.x;
    b.y = gCourseMap->mUnk_34[*gCourseMap->mUnk_fc].mUnk_0c.y;
    b.z = gCourseMap->mUnk_34[*gCourseMap->mUnk_fc].mUnk_0c.z;
    k = (u16) (((s64) b.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    Matrix3x3FromPairY(m1, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
    Vec3MultiplyMatrix3x3(&data_02154f70, m1, &e);
    func_021035ac(p->mIndex);

    w = p->mUnk_4c;
    if (!(w & 0x20000) && (w & 0x8000000)) {
        s = &p->mUnk_538;
        if (s->mUnk_1c <= 0x190) {
            s->mUnk_1c = 0x190;
            p->mUnk_4c |= 0x20000;
            func_02079f70(p->mKartModelsEntry, func_0207a134(), func_0207a11c(), func_0207a104());
        }
    }
    if (p->mUnk_4c & 0x8000000) {
        func_02069134(p);
    }
    w = p->mUnk_4c;
    if (w & 0x10000000) {
        func_0206938c(p);
    } else {
        if (w & 0x80) {
            func_0206a354(p);
        }
        if (p->mUnk_4c & 0x10000) {
            func_02069f6c(p);
        }
        if (p->mUnk_7c & 0x402000) {
            func_0206988c(p);
        }
    }

    if (p->mUnk_4c & 0x2000) {
        s = &p->mUnk_538;
        if (p->mUnk_7c & 1) {
            func_0210ddf4(&data_0217d26c, func_02086080(p->mIndex), func_020718c8, p, 0xa3);
        }
        s->mUnk_0a++;
        if (s->mUnk_0a > 0xb4 && (p->mUnk_4c & 0x2000)) {
            p->mUnk_4c &= ~0x2000;
            p->mUnk_d8 = 0x1000;
            if (!(p->mUnk_4c & 0x8000000)) {
                func_0207b0d0(p);
            }
            func_02080ee4(p);
        }
    }

    if (p->mUnk_4c & 0x40) {
        s = &p->mUnk_538;
        func_0208181c(p->mIndex);
        if ((p->mUnk_7c & 0x10) && p->mKartModelsEntry->mUnk_008->mUnk_1a == 0) {
            func_02068a64(p, 2, 1);
        }
        s->mUnk_06++;
        if (s->mUnk_06 > 0x1c2) {
            p->mUnk_4c &= ~0x40;
            func_0207b1a8(p);
            p->mUnk_29c = 0;
            func_020817b8(p->mIndex);
            func_02068a64(p, 0, 1);
            if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
                func_02106dc8();
            }
            if (p->mUnk_4c & 0x2000) {
                func_0207b13c(p);
            }
        }
    }

    data_0217566a[p->mUnk_78].mBitMask = 0xe04;
    func_020397a8(&data_02154f7c, &e, &f);
    Vec3Sub(&p->mUnk_80, &a, &g);
    g.y = 0;
    Vec3AddScaled(func_02039828(&f, &g), &f, &a, &a);
    func_02039828(&f, &g);
    Vec3Sub(&a, &p->mUnk_80, &c);
    d = func_020708a4_inline(&c, &c);

    if (func_02039828(&c, &e) <= 0) {
        func_02055c5c();
        p->mUnk_48 &= ~0x10000;
        func_01ffa11c(p, &p->mUnk_244);
        p->mUnk_48 &= ~0x40000;
        p->mUnk_3e8 = (s16) ((s32) (((s64) b.x * 0x4000) >> 12) >> 12) + 0x32;
        if ((p->mUnk_7c & 1) && data_021759c0->mCourseId == 0x13) {
            func_0212c6f0(func_02108e6c(7), 0x14);
        }
    } else {
        if (d > 0x64000) {
            p->mUnk_50 = c;
        }
        h = p->mUnk_50;
        h.y = 0;
        p->mUnk_3a8 = 0x1000;
        func_020708a4_inline(&h, &h);
        p->mUnk_236 = (s32) (((s64) func_02148538(h.x, h.z) * 0x28be60d) >> 12) >> 12;
        q = data_02165524;
        func_01ffd190(&q, p->mUnk_236, (Vec4 *) &p->mUnk_e0);
        func_020397a8(&data_02154f7c, &p->mUnk_50, &l);
        func_020397a8(&p->mUnk_50, &l, &n);
        if (p->mUnk_234 > -5000) {
            p->mUnk_234 -= 300;
            if (p->mUnk_234 < -5000) {
                p->mUnk_234 = -5000;
            }
        }
        Matrix4x3FirstThreeRowsFromVec3AndPair(&m2, &p->mUnk_120, data_0215d4b4[((u16) p->mUnk_234 >> 4) * 2],
                                               data_0215d4b4[((u16) p->mUnk_234 >> 4) * 2 + 1]);
        Vec3MultiplyMatrix3x3(&n, &m2.mUnk_00[0].x, &n);
        p->mUnk_244 = n;
        func_01ff9f60(p, &n);
    }

    p->mUnk_2a8 = 0x1e000;
    t = p->mUnk_2a8;
    m2.mUnk_00[3].x = ((s64) p->mUnk_50.x * t) >> 12;
    m2.mUnk_00[3].y = ((s64) p->mUnk_50.y * t) >> 12;
    m2.mUnk_00[3].z = ((s64) p->mUnk_50.z * t) >> 12;
    p->mUnk_68 = p->mUnk_50;
    if (d < 0x3e8000) {
        t = (s32) (((s64) d * 0x29) >> 12) + 0x14000;
        if (p->mUnk_2a8 > t) {
            p->mUnk_2a8 = t;
        }
    }
    p->mUnk_a4 = m2.mUnk_00[3];
    Vec3Add(&p->mUnk_80, &p->mUnk_a4, &p->mUnk_80);
}

void func_020705fc(Unk0206bcb0 *p, u32 b) {
    Vec3 a;
    Vec3 e;
    s32 m[9];
    Vec3 v;
    Vec3 w;
    Unk0212c400 **h;
    u16 i;
    s32 k;

    func_020710b0(p, 1);
    p->mUnk_260 = 0x3000;
    i = gCourseMap->mUnk_fc[b];
    a.x = gCourseMap->mUnk_34[i].mUnk_00.x;
    a.y = gCourseMap->mUnk_34[i].mUnk_00.y;
    a.z = gCourseMap->mUnk_34[i].mUnk_00.z;
    k = (u16) (((s64) gCourseMap->mUnk_34[gCourseMap->mUnk_fc[b]].mUnk_0c.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >>
        4;
    Matrix3x3FromPairY(m, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
    Vec3MultiplyMatrix3x3(&data_02154f70, m, &e);
    if (data_021759c0->mUnk_08 == 2) {
        Vec3Sub(&a, &p->mUnk_80, &v);
        func_020a21bc(p->mIndex, (s32) &v);
    }
    p->mUnk_80 = a;
    p->mUnk_8c = p->mUnk_80;
    p->mUnk_98 = p->mUnk_8c;
    p->mUnk_2a8 = 0x5000;
    p->mUnk_50 = e;
    p->mUnk_68 = p->mUnk_50;
    p->mUnk_236 = (s32) (((s64) func_02148538(e.x, e.z) * 0x28be60dLL) >> 12) >> 12;
    w = data_02165524;
    func_01ffd190(&w, p->mUnk_236, (Vec4 *) &p->mUnk_e0);
    if (p->mUnk_7c & 1) {
        func_02076a5c();
        if (data_0217c780 & 1) {
            h = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (h[0] != NULL) {
                    func_0212c6f0(h, 0);
                }
                if (h[0] != NULL) {
                    func_0212c6f0(h, 0);
                }
                func_0212ecc0(h, 0, 0x159);
            }
        }
    }
    if (!(p->mUnk_7c & 2)) {
        return;
    }
    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    func_02089754(p->mUnk_310, func_02040da8(b));
}

void func_02070484(Unk0206bcb0 *p, Vec4 *q) {
    Unk02012f58 m1;
    Unk02012f58 m2;
    Vec3 v1;
    Vec3 v2;
    s32 d;
    u16 k;
    u16 t;

    if (p->mUnk_2a4 < 0x1000) {
        return;
    }
    if (func_02039828(&p->mUnk_12c, &data_02154f7c) <= 0) {
        return;
    }
    p->mUnk_234 = p->mUnk_234 + p->mUnk_3e8;
    k = p->mUnk_236;
    t = (u16) p->mUnk_234;
    Matrix4x3FromPairY(&m1, data_0215d4b4[(k >> 4) * 2], data_0215d4b4[(k >> 4) * 2 + 1]);
    Vec3MultiplyMatrix4x3(&data_02154f88, &m1, &v1);
    Matrix4x3FromVec3AndPair(&m2, &v1, data_0215d4b4[(t >> 4) * 2], data_0215d4b4[(t >> 4) * 2 + 1]);
    Vec3MultiplyMatrix4x3(&data_02154f7c, &m2, &v2);
    func_01ffd0e8(q, &data_02154f7c, &v2);
    if (p->mUnk_48 & 0x80000000) {
        q->x = -q->x;
        q->y = -q->y;
        q->z = -q->z;
        q->w = -q->w;
    }
    if (p->mUnk_44 & 2) {
        return;
    }
    d = func_02039828(&p->mUnk_b0, &p->mUnk_138);
    if (d <= 0) {
        d = -d;
    }
    p->mUnk_3f8 = d;
    if (p->mUnk_3f8 < 0xb33) {
        p->mUnk_3f8 = 0xb33;
    }
}

BOOL func_02070398(Unk0206bcb0 *p, u32 b, void *c) {
    u32 w;

    w = p->mUnk_44;
    if (!(w & 0xc2200) && !(p->mUnk_7c & 0x400)) {
        if (!(w & 0xc0000) && !(p->mUnk_4c & 0x100) && p->mUnk_1fc.x == 0 && p->mUnk_1fc.y == 0 && p->mUnk_1fc.z == 0 &&
            p->mUnk_274 == 0 && p->mUnk_4d0 >= 0x64) {
            p->mUnk_80.x = p->mUnk_8c.x;
            p->mUnk_80.z = p->mUnk_8c.z;
        } else {
            func_020d5aa0(c, b, (Unk020e04b0 *) p->mUnk_208, &p->mUnk_80, NULL);
        }
        p->mUnk_a4 = data_02154f94;
        p->mUnk_2a4 = 0;
        p->mUnk_44 |= 0x1000;
        return TRUE;
    }
    return FALSE;
}
