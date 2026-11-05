#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0207b000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020f9334.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 func_0206dbf8_inline(Kart *q) {
    BOOL c;
    BOOL t;
    BOOL u;
    int v;
    u32 f;

    f = q->mUnk_4c;
    if (f & 0x400000) {
        c = FALSE;
    } else if (q->mUnk_7c & 0x200) {
        if (q->mState == 0 && !(q->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            c = TRUE;
        } else {
            c = FALSE;
        }
    } else {
        t = TRUE;
        if (!(f & 0x10000040) && !(q->mUnk_48 & 0x1800)) {
            u = FALSE;
            v = q->mState;
            if (v != 0 && v != 1 && v != 2) {
                u = TRUE;
            }
            if (u == FALSE) {
                t = FALSE;
            }
        }
        c = t == FALSE;
    }
    return c;
}

BOOL func_0206de18(Kart *p, Kart *q, const Vec3 *v) {
    BOOL r;
    s32 c;
    u32 w;

    r = FALSE;
    c = func_0206dbf8_inline(q);
    if (c != 0) {
        StartKartState4(q, v, 1);
        func_021090c4(&q->mUnk_00, 0xe8, 0x7f, 0);
        if (q->mUnk_7c & 0x200) {
            q->mUnk_514->mUnk_2c ^= 0x80;
        }
        r = TRUE;
        w = p->mUnk_7c & 0x200;
        if (w != 0) {
            switch (q->mIndex) {
                case 0:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x200;
                    }
                    break;
                case 1:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x400;
                    }
                    break;
                case 2:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x800;
                    }
                    break;
                case 3:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x1000;
                    }
                    break;
            }
        }
    }
    return r;
}

BOOL func_0206dbf8(Kart *p, Kart *q) {
    Vec3 a;
    Vec3 b;
    Vec3 v1;
    BOOL r;
    s32 c;
    u32 w;

    r = FALSE;
    c = func_0206dbf8_inline(q);
    if (c != 0) {
        a = p->mUnk_120;
        Vec3Sub(&q->mPos, &p->mPos, &b);
        Vec3Cross(&p->mUnk_138, &b, &v1);
        if (Vec3Dot(&v1, &p->mUnk_12c) < 0) {
            a.x = -a.x;
            a.y = -a.y;
            a.z = -a.z;
        }
        StartKartState5(q, &a, 1);
        func_021090c4(&q->mUnk_00, 0xe8, 0x7f, 0);
        if (q->mUnk_7c & 0x200) {
            q->mUnk_514->mUnk_2c ^= 0x80;
        }
        r = TRUE;
        w = p->mUnk_7c & 0x200;
        if (w != 0) {
            switch (q->mIndex) {
                case 0:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x400000;
                    }
                    break;
                case 1:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x800000;
                    }
                    break;
                case 2:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x1000000;
                    }
                    break;
                case 3:
                    if (w) {
                        p->mUnk_514->mUnk_2c ^= 0x2000000;
                    }
                    break;
            }
        }
    }
    return r;
}

void func_0206d7c8(Kart *p, Kart *q, const Vec3 *v, s32 c, Vec3 *v1) {
    s32 a;
    s32 b;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 t;
    s32 v5 = -1;
    s32 v6;
    s32 v7;
    s32 v8;
    Vec3 s;
    Vec3 v9;
    Vec3 d;
    Vec3 n;
    Vec3 m;
    Vec3 v10;

    a = p->mPhysicalParam->mWeight + p->mCharPhysicalParam[1];
    b = q->mPhysicalParam->mWeight + q->mCharPhysicalParam[1];
    v2 = p->mVelocityLengthRatio;
    if (p->mUnk_7c & 0x600) {
        if ((float) v2 > 4.8828125e-05f) {
            v2 = 0x333;
        }
    } else if (v2 > 0x800) {
        v2 = 0x1000;
    } else {
        v2 = v2 * 2;
        if (v2 < 0x333) {
            v2 = 0x333;
        }
    }
    t = p->mUnk_4c & 0x80;
    if (t) {
        a >>= 3;
    }
    if (t) {
        b >>= 3;
    }
    if (p->mUnk_48 & 0x100000) {
        a <<= 1;
    }
    if (q->mUnk_48 & 0x100000) {
        a >>= 2;
    }
    t = DivFixed12(a, b);
    if (t > 0x5000) {
        t = 0x5000;
    }
    b = (s32) (((s64) a * t) >> 12);
    v2 = (s32) (((s64) b * v2) >> 12);
    d = q->mUnk_50;
    if (q->mUnk_44 & 0x100) {
        d.x = -d.x;
        d.y = -d.y;
        d.z = -d.z;
    }
    s.x = (s32) (((s64) v->x * v2) >> 12);
    s.y = (s32) (((s64) v->y * v2) >> 12);
    s.z = (s32) (((s64) v->z * v2) >> 12);
    v3 = Vec3Dot(&d, &s);
    v9.x = s.x - (s32) (((s64) d.x * v3) >> 12);
    v9.y = s.y - (s32) (((s64) d.y * v3) >> 12);
    v9.z = s.z - (s32) (((s64) d.z * v3) >> 12);
    v4 = 0;
    if ((s64) v9.x * v9.x + (s64) v9.y * v9.y + (s64) v9.z * v9.z >= 16) {
        v4 = func_02039860(&v9, &n);
    }
    if (v4 <= 0) {
        return;
    }
    if (c != 0) {
        *v1 = n;
    } else if (v1->x != 0 || v1->y != 0 || v1->z != 0) {
        if (Vec3Dot(&n, v1) > 0x19a) {
            n = data_02154f94;
        }
    }
    m.x = (s32) (((s64) n.x * v2) >> 12);
    m.y = (s32) (((s64) n.y * v2) >> 12);
    m.z = (s32) (((s64) n.z * v2) >> 12);
    if (m.y > 0) {
        m.y = 0;
    }
    v3 = Vec3Dot(&q->mUnk_244, &m);
    v6 = m.x - (s32) (((s64) q->mUnk_244.x * v3) >> 12);
    v8 = m.y - (s32) (((s64) q->mUnk_244.y * v3) >> 12);
    v7 = m.z - (s32) (((s64) q->mUnk_244.z * v3) >> 12);
    q->mUnk_2d8.x += v6;
    q->mUnk_2d8.z += v7;
    q->mVerticalSpeed += v8;
    v2 = (s32) (((s64) v2 * 0xaab + 0x800) >> 12);
    if (v2 > 0x1000) {
        v2 = 0x1000;
    }
    Vec3Cross(&n, &q->mUnk_278, &v10);
    if (v10.y < 0) {
        v2 = v2 * v5;
    }
    if (q->mKartModelsEntry->mUnk_058 != 0) {
        return;
    }
    t = q->mForwardSpeed;
    if (t <= 0) {
        t = -t;
    }
    if (t <= 0x3000) {
        return;
    }
    if (v2 > 0) {
        t = v2;
    } else {
        t = -v2;
    }
    q->mUnk_4c |= 0x2000000;
    if (t <= q->mUnk_594) {
        return;
    }
    q->mUnk_594 = t;
    if (v2 > 0) {
        t = 1;
    } else {
        t = -1;
    }
    q->mUnk_598 = t;
}

void func_0206d578(Kart *p) {
    s32 d;
    BOOL v1;
    s32 i;
    Kart *q;
    Vec3 v;

    d = 0;
    v1 = FALSE;
    ComputeKartPointAlongUp(&p->mUnk_1f0, p->mUnk_510, 0x400, p);
    Vec3AddScaled((s32) (((s64) p->mRadius * -0x4000) >> 12), &p->mUnk_50, &p->mUnk_1f0, &p->mUnk_1f0);
    if (p->mIndex == func_02061f90() && !(p->mUnk_4c & 0x10002000)) {
        if (p->mVelocityLength > 0x4000 && p->mState == 0) {
            for (i = 0; i < data_0217b5a8; i++) {
                q = data_0217b5c4[i];
                if (q->mVelocityLength >= 0x2000 && (data_0217b5bc[i] & 0x800) && q != p && !(q->mUnk_7c & 0x402000)) {
                    Vec3Sub(&q->mPos, &p->mPos, &v);
                    d = Vec3Length(&v);
                    if (func_02039828(&q->mUnk_50, &v) > (s32) (((s64) d * 0xe7f) >> 12)) {
                        v1 = TRUE;
                        p->mUnk_538.mUnk_08++;
                        break;
                    }
                }
            }
        }
        if (!(p->mUnk_7c & 0x400)) {
            if (v1 != FALSE) {
                p->mUnk_4c |= 0x4000;
                func_02081060(p);
                if (p->mUnk_538.mUnk_08 > 0xf && d < 0x3c000) {
                    func_02069068(p);
                }
            } else {
                p->mUnk_538.mUnk_08 = 0;
                p->mUnk_4c &= ~0x4000;
                if (!(p->mUnk_4c & 0x2000)) {
                    p->mUnk_d8 = 0x1000;
                }
                func_02081000(p);
            }
        }
    }
    if (p->mUnk_4c & 0x4000) {
        p->mUnk_d8 += 7;
        if (p->mUnk_d8 > 0x1333) {
            p->mUnk_d8 = 0x1333;
        }
    }
}

void func_0206d18c(Kart *p) {
    s32 r;
    ItemObject *e;
    Kart *q;
    u32 i;
    u32 t;
    u32 f;

    if (p->mUnk_7c & 0x400400) {
        return;
    }
    if (func_020fa4c8(p) == 0) {
        return;
    }
    if (p->mUnk_7c & 0x402020) {
        return;
    }
    if (p->mUnk_4c & 0x800) {
        return;
    }
    e = func_020fa4b4(0);
    r = 0;
    switch (e->mKind) {
        case 0:
        case 1:
        case 7:
            r = TryStartKartState3(p);
            break;
        case 2:
            r = func_0206bcb0(p, 1, r);
            if (r != 0 && p->mKartModelsEntry->mUnk_058 == 0) {
                func_0208b7bc(0xc, &p->mPos);
                func_0208b7bc(0xd, &p->mPos);
                func_0208b7bc(0xe, &p->mPos);
            }
            break;
        case 3:
            func_0206d020(p, r, 0x5a);
            p->mUnk_48 |= 0x100000;
            p->mUnk_538.mUnk_00 = 0x5a;
            if (data_021759c0->mMode == MODE_BATTLE) {
                func_020a1ddc(p->mIndex);
            }
            break;
        case 4:
            func_02069c38(p);
            break;
        case 5:
            if (((Unk020fc2e8 *) e)->mUnk_2e4 != 0) {
                r = func_0206bcb0(p, 2, r);
            } else {
                r = TryStartKartState6(p);
            }
            break;
        case 9:
            if (((Unk020fc2e8 *) e)->mUnk_16c != 0) {
                r = func_0206bcb0(p, 2, r);
            } else {
                r = TryStartKartState6(p);
            }
            break;
        case 6:
            i = r;
            func_02061874();
            func_02082e4c(p->mIndex);
            t = p->mUnk_7c & 0x200;
            if (t) {
                if (t) {
                    p->mUnk_514->mUnk_2c ^= 0x4000;
                }
            } else {
                while (i < data_021759c0->mKartCount) {
                    if (i != p->mIndex) {
                        func_0206a624(GetKart(i));
                    }
                    i = (u16) (i + 1);
                }
            }
            break;
        case 8:
            func_02104ee0((Unk02104c68 *) e, p);
            break;
    }
    if (r != 0 && data_021759c0->mMode == MODE_MISSION_RUN) {
        func_0207a70c(p->mIndex);
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        func_020a1e40(p->mIndex, e);
    }
    if (func_020f9880(e) == 0) {
        return;
    }
    if (p->mUnk_4c & 0x10000040) {
        if (e->mUnk_128 & (u8) (1 << p->mIndex)) {
            return;
        }
        e->mUnk_128 |= (u8) (1 << p->mIndex);
        func_021090c4(&p->mUnk_00, 0xe9, 0x7f, 0);
        return;
    }
    i = (u16) ((e->mUnk_78 & 0x8000) == 0 ? (u16) (e->mUnk_78 & ~0xff00) : 8);
    if (i >= data_021759c0->mKartCount) {
        return;
    }
    q = GetKart(i);
    if (q->mIndex != p->mIndex && r != 0) {
        if (data_021759c0->mMode != MODE_MISSION_RUN) {
            func_0207a70c(i);
        }
        if (!(q->mUnk_48 & 0x840)) {
            func_0210af40(q, q->mUnk_3cc, 8);
        }
        f = q->mUnk_7c;
        if ((f & 0x10) && !(f & 0x30000)) {
            func_0207b054(q, 2, 0);
        }
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c &= ~0x60000000;
        p->mUnk_514->mUnk_2c |= (i & 3) << 0x1d;
    }
}

void func_0206d138(Kart *p) {
    u32 f;

    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 8);
    }
    f = p->mUnk_7c;
    if (!(f & 0x10)) {
        return;
    }
    if (f & 0x30000) {
        return;
    }
    func_0207b054(p, 2, 0);
}

void func_0206d020(Kart *p, int a, int b) {
    s32 c;
    u32 d;
    s16 e;
    enum { K0 } f;
    if (p->mState != 0) {
        return;
    }
    d = p->mUnk_48 & 0x1000;
    if (d) {
        return;
    }
    if (p->mUnk_4c & 0x10000000) {
        return;
    }
    p->mUnk_48 |= 0x20;
    e = p->mUnk_238;
    if (b > e) {
        p->mUnk_238 = b;
    }
    if (a != 1 && a != 3) {
        p->mUnk_48 |= 0x20000000;
    }
    func_0210a53c(p);
    c = ~0x8000;
    p->mUnk_48 &= c;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!a) {
            f = 0;
        } else {
            f = 1;
        }
        func_02084034(f, p);
        SetCameraHalfFovAngleGoal(0x1770);
        func_02055c80(5);
        if (a != 3) {
            return;
        }
        func_021090c4(&p->mUnk_00, 0xa2, 0x7f, 0);
        return;
    }
    func_021090c4(&p->mUnk_00, 0x9f, 0x7f, 0);
}
