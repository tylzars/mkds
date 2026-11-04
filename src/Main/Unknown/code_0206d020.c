#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020fa4c8.h"
#include "Main/Unknown/code_020fa4b4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020a1748.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_02061874.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020f9334.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"

void func_0206d020(Unk0206bcb0 *p, int a, int b) {
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
    if (p->mUnk_7c & 0x1) {
        if (!a) {
            f = 0;
        } else {
            f = 1;
        }
        func_02084034(f, p);
        func_02074874(0x1770);
        func_02055c80(5);
        if (a != 3) {
            return;
        }
        func_021090c4(&p->mUnk_00, 0xa2, 0x7f, 0);
        return;
    }
    func_021090c4(&p->mUnk_00, 0x9f, 0x7f, 0);
}

void func_0206d138(Unk0206bcb0 *p) {
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

// non-matching: +0x2b4 to +0x2c4 the mask 1 << mUnk_74 & 0xff and the test with the byte at 0x128 use r2 for the
// `and` result and r0 for `ands`/`orr` in ours; the original keeps the mask in r0 and sends the `ands` result to r2;
// same size
void func_0206d18c(Unk0206bcb0 *p) {
    s32 r;
    Unk020f41c4_A *e;
    Unk0206bcb0 *q;
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
    switch (e->mUnk_44) {
        case 0:
        case 1:
        case 7:
            r = func_0206b4d0(p);
            break;
        case 2:
            r = func_0206bcb0(p, 1, r);
            if (r != 0 && p->mKartModelsEntry->mUnk_058 == 0) {
                func_0208b7bc(0xc, &p->mUnk_80);
                func_0208b7bc(0xd, &p->mUnk_80);
                func_0208b7bc(0xe, &p->mUnk_80);
            }
            break;
        case 3:
            func_0206d020(p, r, 0x5a);
            p->mUnk_48 |= 0x100000;
            p->mUnk_538.mUnk_00 = 0x5a;
            if (data_021759c0->mUnk_08 == 2) {
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
                r = func_0206bab8(p);
            }
            break;
        case 9:
            if (((Unk020fc2e8 *) e)->mUnk_16c != 0) {
                r = func_0206bcb0(p, 2, r);
            } else {
                r = func_0206bab8(p);
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
                        func_0206a624(func_0207a974(i));
                    }
                    i = (u16) (i + 1);
                }
            }
            break;
        case 8:
            func_02104ee0((Unk02104c68 *) e, p);
            break;
    }
    if (r != 0 && data_021759c0->mUnk_08 == 4) {
        func_0207a70c(p->mIndex);
    }
    if (data_021759c0->mUnk_08 == 2) {
        func_020a1e40(p->mIndex, e);
    }
    if (func_020f9880(e) == 0) {
        return;
    }
    if (p->mUnk_4c & 0x10000040) {
        u32 m;
        u8 b = e->mUnk_128;
        m = (1 << p->mIndex) & 0xff;
        if (b & m) {
            return;
        }
        e->mUnk_128 = b | m;
        func_021090c4(&p->mUnk_00, 0xe9, 0x7f, 0);
        return;
    }
    i = (u16) ((e->mUnk_78 & 0x8000) == 0 ? (u16) (e->mUnk_78 & ~0xff00) : 8);
    if (i >= data_021759c0->mKartCount) {
        return;
    }
    q = func_0207a974(i);
    if (q->mIndex != p->mIndex && r != 0) {
        if (data_021759c0->mUnk_08 != 4) {
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

void func_0206d578(Unk0206bcb0 *p) {
    s32 d;
    BOOL v1;
    s32 i;
    Unk0206bcb0 *q;
    Vec3 v;

    d = 0;
    v1 = FALSE;
    func_01ffc064(&p->mUnk_1f0, p->mUnk_510, 0x400, p);
    Vec3AddScaled((s32) (((s64) p->mUnk_1d0 * -0x4000) >> 12), &p->mUnk_50, &p->mUnk_1f0, &p->mUnk_1f0);
    if (p->mIndex == func_02061f90() && !(p->mUnk_4c & 0x10002000)) {
        if (p->mUnk_2a4 > 0x4000 && p->mState == 0) {
            for (i = 0; i < data_0217b5a8; i++) {
                q = data_0217b5c4[i];
                if (q->mUnk_2a4 >= 0x2000 && (data_0217b5bc[i] & 0x800) && q != p && !(q->mUnk_7c & 0x402000)) {
                    Vec3Sub(&q->mUnk_80, &p->mUnk_80, &v);
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

// non-matching: same size (0x430); registers and scheduling only: the first product of (a * t >> 12) * scale sits in r2
// (original r1) with scale in r5/r4 swapped, and the three q->mUnk_244 products with dot are ordered x, z, y in other
// registers from +0x2d8, with the 0xaab/0x800 rounding product placed after them
void func_0206d7c8(Unk0206bcb0 *p, Unk0206bcb0 *q, const Vec3 *v, s32 c, Vec3 *v1) {
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

    a = p->mUnk_2cc->mUnk_0c + p->mUnk_2d0[1];
    b = q->mUnk_2cc->mUnk_0c + q->mUnk_2d0[1];
    v2 = p->mUnk_2a0;
    if (p->mUnk_7c & 0x600) {
        if ((float) v2 > 4.8828128e-05f) {
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
    t = (s32) (((s64) a * t) >> 12);
    v2 = (s32) (((s64) t * v2) >> 12);
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
    v6 = (s32) (((s64) q->mUnk_244.x * v3) >> 12);
    v7 = (s32) (((s64) q->mUnk_244.z * v3) >> 12);
    v8 = (s32) (((s64) q->mUnk_244.y * v3) >> 12);
    q->mUnk_2d8.x += m.x - v6;
    q->mUnk_2d8.z += m.z - v7;
    q->mUnk_260 += m.y - v8;
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
    t = q->mUnk_2a8;
    if (t <= 0) {
        t = -t;
    }
    if (t <= 0x3000) {
        return;
    }
    q->mUnk_4c |= 0x2000000;
    if (v2 > 0) {
        t = v2;
    } else {
        t = -v2;
    }
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

static inline s32 func_0206dbf8_inline(Unk0206bcb0 *q) {
    BOOL c;
    BOOL t;
    BOOL u;
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
            if (q->mState != 0 && q->mState != 1 && q->mState != 2) {
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

// non-matching: size 0x248 against 0x220; the original keeps `mov r0, #1` (the result) in r0 and the masked 0x200 word
// of the flag in r2 for the whole switch and ends each case with its own epilogue; ours rebuilds `mov r0, #1` at every
// return and tests r1; the opening flag test also differs (original keeps the 0x4c word in r2, the flag result in r1)
BOOL func_0206dbf8(Unk0206bcb0 *p, Unk0206bcb0 *q) {
    Vec3 a;
    Vec3 b;
    Vec3 v1;
    s32 c;
    u32 w;

    c = func_0206dbf8_inline(q);
    if (c == 0) {
        return FALSE;
    }
    a = p->mUnk_120;
    Vec3Sub(&q->mUnk_80, &p->mUnk_80, &b);
    Vec3Cross(&p->mUnk_138, &b, &v1);
    if (Vec3Dot(&v1, &p->mUnk_12c) < 0) {
        a.x = -a.x;
        a.y = -a.y;
        a.z = -a.z;
    }
    func_0206a980(q, &a, 1);
    func_021090c4(&q->mUnk_00, 0xe8, 0x7f, 0);
    if (q->mUnk_7c & 0x200) {
        q->mUnk_514->mUnk_2c ^= 0x80;
    }
    w = p->mUnk_7c & 0x200;
    if (w == 0) {
        return TRUE;
    }
    switch (q->mIndex) {
        case 0:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x400000;
            }
            return TRUE;
        case 1:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x800000;
            }
            return TRUE;
        case 2:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x1000000;
            }
            return TRUE;
        case 3:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x2000000;
            }
            return TRUE;
    }
    return TRUE;
}

// non-matching: size 0x1e0 against 0x1b8, the same difference as func_0206dbf8
BOOL func_0206de18(Unk0206bcb0 *p, Unk0206bcb0 *q, const Vec3 *v) {
    s32 c;
    u32 w;

    c = func_0206dbf8_inline(q);
    if (c == 0) {
        return FALSE;
    }
    func_0206add0(q, v, 1);
    func_021090c4(&q->mUnk_00, 0xe8, 0x7f, 0);
    if (q->mUnk_7c & 0x200) {
        q->mUnk_514->mUnk_2c ^= 0x80;
    }
    w = p->mUnk_7c & 0x200;
    if (w == 0) {
        return TRUE;
    }
    switch (q->mIndex) {
        case 0:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x200;
            }
            return TRUE;
        case 1:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x400;
            }
            return TRUE;
        case 2:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x800;
            }
            return TRUE;
        case 3:
            if (w) {
                p->mUnk_514->mUnk_2c ^= 0x1000;
            }
            return TRUE;
    }
    return TRUE;
}
