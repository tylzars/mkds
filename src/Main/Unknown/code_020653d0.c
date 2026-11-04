#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020653d0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206b000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02082000.h"
#include "Main/Unknown/code_0210a000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

static inline void func_020653d0_inline(Unk0206bcb0 *o, Unk0206bcb0 *o2, Vec3 *t) {
    Vec3 t1;
    Vec3 t2;

    *t = *(Vec3 *) &o2->mUnk_120;
    Vec3Sub(&o->mUnk_80, &o2->mUnk_80, &t1);
    Vec3Cross(&o2->mUnk_138, &t1, &t2);
    if (Vec3Dot(&t2, &o2->mUnk_12c) < 0) {
        t->x = -t->x;
        t->y = -t->y;
        t->z = -t->z;
    }
}

void func_020653d0(Unk0206bcb0 *p, Unk020653d0 *a, s32 n) {
    Vec3 v;
    Vec3 v2;
    Vec3 v3;
    Vec3 v4;
    Vec3 v5;
    Vec3 v6;
    Matrix3x3 m1;
    Matrix3x3 m2;
    u32 w;
    u32 f;
    Unk0206bcb0_514 *q;
    s32 b;
    u16 i;
    u16 s;
    Unk0206bcb0_514 *r;
    s32 k;
    s32 c;
    Unk0206bcb0 *o;
    Unk0206bcb0 *o2;
    s32 e;
    u8 x;
    Vec3 *u;

    f = a->mUnk_0c;
    b = (p->mUnk_44 & 0x10) != 0;
    q = p->mUnk_514;
    v.x = a->mUnk_00 << 10;
    v.y = a->mUnk_02 << 10;
    v.z = a->mUnk_04 << 10;
    p->mUnk_2a8 = a->mUnk_06 << 2;
    p->mUnk_236 = a->mUnk_0a;
    q->mUnk_44 = a->mUnk_14;
    q->mUnk_48 = a->mUnk_10;
    x = q->mUnk_48 >> 24;
    q->mUnk_98.x = (s16) (((x & 0x80) ? 0xc000 : 0) | (x << 6));
    x = q->mUnk_48 >> 16;
    q->mUnk_98.y = (s16) (((x & 0x80) ? 0xc000 : 0) | (x << 6));
    x = q->mUnk_48 >> 8;
    q->mUnk_98.z = (s16) (((x & 0x80) ? 0xc000 : 0) | (x << 6));
    q->mUnk_48 = q->mUnk_48 & 0xff;
    q->mUnk_40 = a->mUnk_08;
    p->mUnk_388 = a->mUnk_08;
    if (b) {
        p->mUnk_44 |= 0x10;
    } else {
        p->mUnk_44 &= ~0x10;
    }
    if (p->mUnk_514->mUnk_48 & 2) {
        p->mUnk_44 |= 2;
    } else {
        p->mUnk_44 &= ~2;
    }
    if (p->mUnk_514->mUnk_48 & 8) {
        p->mUnk_44 |= 8;
    } else {
        p->mUnk_44 &= ~8;
    }
    if (((p->mUnk_514->mUnk_30 & 0x10000) != 0) != ((f & 0x10000) != 0)) {
        s = p->mUnk_236;
        func_02072b94(p, &v, 0, 0);
        p->mUnk_236 = s;
        v3 = data_02165530;
        func_01ffd190(&v3, p->mUnk_236, (Vec4 *) &p->mUnk_e0);
        *(Vec4 *) &p->mUnk_108.z = *(Vec4 *) &p->mUnk_e0;
        if (p->mUnk_7c & 0x400) {
            r = p->mUnk_514;
            r->mUnk_00 = p->mUnk_80;
            r->mUnk_10 = r->mUnk_00;
            r->mUnk_4c = *(Vec4 *) &p->mUnk_108.z;
            r->mUnk_a8 = data_02154f94;
            r->mUnk_b4 = 0;
        }
    }
    if ((s64) (p->mUnk_80.x - v.x) * (p->mUnk_80.x - v.x) + (s64) (p->mUnk_80.y - v.y) * (p->mUnk_80.y - v.y) +
            (s64) (p->mUnk_80.z - v.z) * (p->mUnk_80.z - v.z) >=
        0x15f90000000LL) {
        switch (q->mUnk_b4) {
            case 0:
                u = &p->mUnk_138;
                v4.x = (s32) (((s64) u->x * -0x7000) >> 12);
                v4.y = (s32) (((s64) u->y * -0x7000) >> 12);
                v4.z = (s32) (((s64) u->z * -0x7000) >> 12);
                break;
            case 1:
                u = &p->mUnk_138;
                v4.x = (s32) (((s64) u->x * 0x7000) >> 12);
                v4.y = (s32) (((s64) u->y * 0x7000) >> 12);
                v4.z = (s32) (((s64) u->z * 0x7000) >> 12);
                break;
            case 2:
                u = (Vec3 *) &p->mUnk_120;
                v4.x = (s32) (((s64) u->x * 0x7000) >> 12);
                v4.y = (s32) (((s64) u->y * 0x7000) >> 12);
                v4.z = (s32) (((s64) u->z * 0x7000) >> 12);
                break;
            case 3:
            default:
                u = (Vec3 *) &p->mUnk_120;
                v4.x = (s32) (((s64) u->x * -0x7000) >> 12);
                v4.y = (s32) (((s64) u->y * -0x7000) >> 12);
                v4.z = (s32) (((s64) u->z * -0x7000) >> 12);
                break;
        }
        q->mUnk_a8 = v4;
        v.y += 0x14000;
        Vec3Add(&v, &v4, &v);
        p->mUnk_80 = v;
        p->mUnk_8c = p->mUnk_80;
        p->mUnk_98 = p->mUnk_8c;
        q->mUnk_00 = p->mUnk_98;
        *(Vec3 *) &p->mUnk_25c = data_02154f94;
        func_01ffc064(&p->mUnk_1b8, &v, 0x400, p);
        func_01ffbfe4(p);
        q->mUnk_b4++;
        if (q->mUnk_b4 > 3) {
            q->mUnk_b4 = 0;
        }
    } else if (!(p->mUnk_48 & 0x20000)) {
        v6 = p->mUnk_8c;
        Vec3Add(&v, &q->mUnk_a8, &v);
        func_020d5180(&v, n * 0xd000 + p->mUnk_1d0, 0x8000);
        for (i = 0; i < n; i++) {
            if (p->mUnk_48 & 0x40) {
                p->mUnk_80.y -= 0x19a;
            } else {
                if (i < 3 && i < n / 2) {
                    func_01ffc090(p, func_01ffc27c(p, 0));
                }
                func_01ffd190(&data_02154f7c, p->mUnk_236, (Vec4 *) &p->mUnk_e0);
                func_01ffcebc((Vec4 *) &p->mUnk_f0, (Vec4 *) &p->mUnk_e0, (Vec4 *) &p->mUnk_108.z);
                func_01ffcd84((Vec3 *) &p->mUnk_120, (Vec4 *) &p->mUnk_108.z);
                r = p->mUnk_514;
                r->mUnk_5c = r->mUnk_5c + (s32) (((s64) (r->mUnk_40 - r->mUnk_5c) * 0x333 + 0x800) >> 12);
                p->mUnk_388 = r->mUnk_5c;
                Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) &m1, &p->mUnk_12c,
                                                       data_0215d4b4[((u16) p->mUnk_388 >> 4) * 2],
                                                       data_0215d4b4[((u16) p->mUnk_388 >> 4) * 2 + 1]);
                if (p->mUnk_48 & 1) {
                    Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) &m2, (Vec3 *) &p->mUnk_120,
                                                           data_0215d4b4[0xba], data_0215d4b4[0xbb]);
                    Matrix3x3Multiply(m2.mUnk_00, m1.mUnk_00, m1.mUnk_00);
                }
                Vec3MultiplyMatrix3x3(&p->mUnk_278, m1.mUnk_00, &p->mUnk_50);
                k = p->mUnk_2a8;
                v2.x = (s32) (((s64) p->mUnk_50.x * k) >> 12);
                v2.y = (s32) (((s64) p->mUnk_50.y * k) >> 12);
                v2.z = (s32) (((s64) p->mUnk_50.z * k) >> 12);
                Vec3Add(&v, &v2, &v);
                Vec3Add(&v, &p->mUnk_2d8, &v);
                Vec3Add(&p->mUnk_a4, &p->mUnk_2d8, &p->mUnk_a4);
                if (p->mUnk_514->mUnk_44 & 1) {
                    p->mUnk_260 = 0;
                }
                k = (p->mUnk_44 & 0x10) ? 0xee1 : 0xfae;
                p->mUnk_2d8.x = (s32) (((s64) p->mUnk_2d8.x * k) >> 12);
                p->mUnk_2d8.y = (s32) (((s64) p->mUnk_2d8.y * k) >> 12);
                p->mUnk_2d8.z = (s32) (((s64) p->mUnk_2d8.z * k) >> 12);
                if ((s64) p->mUnk_2d8.x * p->mUnk_2d8.x + (s64) p->mUnk_2d8.y * p->mUnk_2d8.y +
                        (s64) p->mUnk_2d8.z * p->mUnk_2d8.z >=
                    0xa429) {
                    p->mUnk_44 |= 0x2000;
                } else {
                    p->mUnk_2d8 = data_02154f94;
                    p->mUnk_44 &= ~0x2000;
                }
            }
            if (func_01ffdee4(&v, (u32 *) &v6, 0, p->mUnk_1d0, 1, p->mUnk_2c8, &v5, 0, 0, &w, 0, 0, 0, 0)) {
                Vec3Add(&v, &v5, &v);
            }
            v6 = v;
        }
    }
    if (p->mUnk_48 & 0x40) {
        goto l0;
    }
    p->mUnk_80.x = v.x;
    p->mUnk_80.z = v.z;
    c = 0;
    if (((p->mUnk_514->mUnk_30 & 1) != 0) != ((f & 1) != 0) && (p->mUnk_44 & 0x10)) {
        r = ((volatile Unk0206bcb0 *) p)->mUnk_514;
        r->mUnk_64 = 0x1405;
        r->mUnk_60 = 0;
        p->mUnk_260 += 0x21a2;
    }
    if (((p->mUnk_514->mUnk_30 & 0x20000) != 0) != ((f & 0x20000) != 0)) {
        func_0206b914(p);
        c = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 4) != 0) != ((f & 4) != 0)) {
        func_0206bbb4(p, 1, 0);
        c = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 8) != 0) != ((f & 8) != 0)) {
        func_0206bbb4(p, 2, 0);
        c = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 0x10) != 0) != ((f & 0x10) != 0)) {
        func_0206b358(p);
        c = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 0x2000) != 0) != ((f & 0x2000) != 0)) {
        func_02069c38(p);
    }
    if (((p->mUnk_514->mUnk_30 & 0x4000) != 0) != ((f & 0x4000) != 0)) {
        i = 0;
        func_02061874();
        func_02082e4c(p->mIndex);
        e = p->mUnk_7c & 0x200;
        if (e) {
            if (e) {
                p->mUnk_514->mUnk_2c ^= 0x4000;
            }
        } else {
            for (; i < (u32) data_021759c0->mKartCount; i++) {
                if (i != p->mIndex) {
                    func_0206a624(func_0207a974(i));
                }
            }
        }
    }
    if (((p->mUnk_514->mUnk_30 & 0x8000) != 0) != ((f & 0x8000) != 0)) {
        func_0206a624(p);
    }
    if (((p->mUnk_514->mUnk_30 & 0x100000) != 0) != ((f & 0x100000) != 0)) {
        func_020695c4(p);
    }
    if (((p->mUnk_514->mUnk_30 & 0x200000) != 0) != ((f & 0x200000) != 0)) {
        p->mUnk_538.mUnk_24 = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 0x4000000) != 0) != ((f & 0x4000000) != 0)) {
        func_02069aa0(p);
    }
    if (((p->mUnk_514->mUnk_30 & 0x40) != 0) != ((f & 0x40) != 0)) {
        if (p->mUnk_7c & 0x200) {
            if ((p->mUnk_4c & 0x10000040) || p->mState == 4) {
                goto l1;
            }
        } else if (p->mState == 5) {
            goto l1;
        }
        func_021090c4(&p->mUnk_00, 0xe8, 0x7f, 0);
        func_0206a980(p, &q->mUnk_98, 0);
    l1:
        if (((p->mUnk_514->mUnk_30 & 0x80) != 0) != ((f & 0x80) != 0)) {
            func_021090c4(&p->mUnk_00, 0xe8, 0x7f, 0);
        }
    } else if (((p->mUnk_514->mUnk_30 & 0x20) != 0) != ((f & 0x20) != 0)) {
        if (p->mUnk_7c & 0x200) {
            if ((p->mUnk_4c & 0x10000040) || p->mState == 4) {
                goto l2;
            }
        } else if (p->mState == 4) {
            goto l2;
        }
        func_0206add0(p, &q->mUnk_98, 0);
    l2:
        if (((p->mUnk_514->mUnk_30 & 0x80) != 0) != ((f & 0x80) != 0)) {
            func_021090c4(&p->mUnk_00, 0xe8, 0x7f, 0);
        }
    }
    if (((p->mUnk_514->mUnk_30 & 0x40000) != 0) != ((f & 0x40000) != 0)) {
        func_02069068(p);
    }
    if (((p->mUnk_514->mUnk_30 & 0x80000) != 0) != ((f & 0x80000) != 0)) {
        p->mUnk_538.mUnk_1c = 0;
        p->mUnk_4c |= 0x8000000;
        p->mUnk_4c &= ~0x20000;
        if (p->mUnk_4c & 0x2000) {
            func_0207b0d0(p);
        }
        func_02079f70(p->mKartModelsEntry, 0, 0x1084, 0);
        if (p->mUnk_7c & 0x10) {
            func_0207b054(p, 1, 0);
            func_0207b708(p->mKartModelsEntry, 1);
        }
        if (!(p->mUnk_48 & 0x840)) {
            func_0210af40(p, p->mUnk_3cc, 0);
        }
        func_021038f0(p->mIndex, 0);
    }
    if (c) {
        o = func_0207a974((u16) ((f & 0x60000000) >> 29));
        if (o != p) {
            o->mUnk_4c |= 0x1000;
        }
    }
    o = func_0207a974(data_021759c0->mUnk_62);
    e = 0;
    if (((p->mUnk_514->mUnk_30 & 0x400000) != 0) != ((f & 0x400000) != 0) && o->mIndex == 0) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l3;
            }
        } else if (o->mState == 4) {
            goto l3;
        }
        func_020653d0_inline(o, o2, &t);
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206a980(o, &t, 0);
    l3:
        e = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 0x800000) != 0) != ((f & 0x800000) != 0) && o->mIndex == 1) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l4;
            }
        } else if (o->mState == 4) {
            goto l4;
        }
        func_020653d0_inline(o, o2, &t);
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206a980(o, &t, 0);
    l4:
        e = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 0x1000000) != 0) != ((f & 0x1000000) != 0) && o->mIndex == 2) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l5;
            }
        } else if (o->mState == 4) {
            goto l5;
        }
        func_020653d0_inline(o, o2, &t);
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206a980(o, &t, 0);
    l5:
        e = 1;
    }
    if (((p->mUnk_514->mUnk_30 & 0x2000000) != 0) != ((f & 0x2000000) != 0) && o->mIndex == 3) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l6;
            }
        } else if (o->mState == 4) {
            goto l6;
        }
        func_020653d0_inline(o, o2, &t);
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206a980(o, &t, 0);
    l6:
        e = 1;
    }
    if (e) {
        goto l0;
    }
    if (((p->mUnk_514->mUnk_30 & 0x200) != 0) != ((f & 0x200) != 0) && o->mIndex == 0) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l7;
            }
        } else if (o->mState == 4) {
            goto l7;
        }
        Vec3Sub((Vec3 *) &o->mUnk_1d8, (Vec3 *) &o2->mUnk_1d8, &t);
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            func_02039860(&t, &t);
        }
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206add0(o, &t, 0);
    l7:
    }
    if (((p->mUnk_514->mUnk_30 & 0x400) != 0) != ((f & 0x400) != 0) && o->mIndex == 1) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l8;
            }
        } else if (o->mState == 4) {
            goto l8;
        }
        Vec3Sub((Vec3 *) &o->mUnk_1d8, (Vec3 *) &o2->mUnk_1d8, &t);
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            func_02039860(&t, &t);
        }
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206add0(o, &t, 0);
    l8:
    }
    if (((p->mUnk_514->mUnk_30 & 0x800) != 0) != ((f & 0x800) != 0) && o->mIndex == 2) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l9;
            }
        } else if (o->mState == 4) {
            goto l9;
        }
        Vec3Sub((Vec3 *) &o->mUnk_1d8, (Vec3 *) &o2->mUnk_1d8, &t);
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            func_02039860(&t, &t);
        }
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206add0(o, &t, 0);
    l9:
    }
    if (((p->mUnk_514->mUnk_30 & 0x1000) != 0) != ((f & 0x1000) != 0) && o->mIndex == 3) {
        Vec3 t;

        s = p->mIndex;
        t = data_02154f88;
        o2 = func_0207a974(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == 4) {
                goto l10;
            }
        } else if (o->mState == 4) {
            goto l10;
        }
        Vec3Sub((Vec3 *) &o->mUnk_1d8, (Vec3 *) &o2->mUnk_1d8, &t);
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            func_02039860(&t, &t);
        }
        func_021090c4(&o->mUnk_00, 0xe8, 0x7f, 0);
        func_0206add0(o, &t, 0);
    l10:
    }
l0:
    p->mUnk_514->mUnk_30 = f;
}
