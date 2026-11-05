#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0209b634.h"

#include "Main/Unknown/code_020a36a8.h"
#include "Main/Unknown/code_020a3690.h"
#include "Main/Unknown/code_020a392c.h"
#include "Main/Unknown/code_020a3948.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3f18.h"

void InitBalloon(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value12;
    value12 = (u32) &func_020d2398;
    value1 = ~(0u);
    *(u32 *) ((value0) + (164)) = value1;
    func_020d2398((void *) value0);
}

void CreateBalloon(Unk020a3eb8 *a) {
    gBalloon = func_0209bc74(a, gBalloonNsbmdName, gBalloonNsbtpName);
    func_0209b940(gBalloon, 0x3f);
    func_0209b9a4(gBalloon, 0x1a);
    func_0209b8ac(gBalloon, 0);
    a->mUnk_1c = 1;
}

void func_020a3e38(void *p) {
    Camera *g;

    g = GetCurrentCamera();
    data_0217b214.x = g->mPos.x >> 1;
    data_0217b214.y = g->mPos.y >> 1;
    data_0217b214.z = g->mPos.z >> 1;
    data_0217b208.x = g->mPos.x >> 3;
    data_0217b208.y = g->mPos.y >> 3;
    data_0217b208.z = g->mPos.z >> 3;
    func_0209bbd0(p, gBalloon);
}

void DrawBalloon(void *p, Balloon *a) {
    s32 j;
    s32 n;
    s32 i;
    s32 k;
    s32 u;
    u32 m;
    s32 t;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m0[9];
    s32 m1[9];
    s32 f0[3];
    s32 g0[3];
    s32 f1[3];
    s32 g1[3];
    s32 h[3];
    Balloon *e;

    if (a->mUnk_a4 >= 0) {
        if (GetKart(a->mUnk_a4)->mUnk_384 == 0) {
            return;
        }
    }
    n = a->mUnk_f4;
    if (n == 1 && a->mUnk_f8 == NULL) {
        m = a->mUnk_00.mUnk_78 & ~0xc000001f;
        if (m < 0x2710) {
            a->mUnk_e8.x = data_0217b214.x + (a->mUnk_00.mPos.x >> 1);
            a->mUnk_e8.y = data_0217b214.y + (a->mUnk_00.mPos.y >> 1);
            a->mUnk_e8.z = data_0217b214.z + (a->mUnk_00.mPos.z >> 1);
            a->mUnk_e4 = 0x800;
        } else if (m < 0x9c40) {
            a->mUnk_e8.x = data_0217b208.x + a->mUnk_00.mPos.x - (a->mUnk_00.mPos.x >> 3);
            a->mUnk_e8.y = data_0217b208.y + a->mUnk_00.mPos.y - (a->mUnk_00.mPos.y >> 3);
            a->mUnk_e8.z = data_0217b208.z + a->mUnk_00.mPos.z - (a->mUnk_00.mPos.z >> 3);
            a->mUnk_e4 = 0xe00;
        } else {
            a->mUnk_e8 = a->mUnk_00.mPos;
            a->mUnk_e4 = 0x1000;
        }
        w0 = 0x1e;
        func_01ff9048(0x14, &w0, 1);
        func_01ff9048(0x19, func_020e6cf8(&a->mUnk_e8), 12);
        if (a->mUnk_00.mAngle != 0) {
            i = (a->mUnk_00.mAngle >> 4) * 2;
            Matrix3x3FromPairZ(m0, gPairsByAngle[i + 1], gPairsByAngle[i]);
            func_01ff9048(0x1a, m0, 9);
        }
        u = a->mUnk_e4;
        f0[0] = u;
        f0[1] = u;
        f0[2] = u;
        func_01ff9048(0x1b, f0, 3);
        t = a->mUnk_d0 + a->mUnk_d8;
        if (t != 0x1000) {
            g0[0] = t;
            g0[1] = t;
            g0[2] = t;
            func_01ff9048(0x1b, g0, 3);
        }
        func_0209b940(gBalloon, func_020d3c44());
        func_0209b688(gBalloon, a->mUnk_a8);
        func_0209bb2c(p, gBalloon, a);
    } else if (n > 0) {
        m = a->mUnk_00.mUnk_78 & ~0xc000001f;
        if (m < 0x2710) {
            a->mUnk_e8.x = data_0217b214.x + (a->mUnk_b0.x >> 1);
            a->mUnk_e8.y = data_0217b214.y + (a->mUnk_b0.y >> 1);
            a->mUnk_e8.z = data_0217b214.z + (a->mUnk_b0.z >> 1);
            a->mUnk_e4 = 0x800;
        } else if (m < 0x9c40) {
            a->mUnk_e8.x = data_0217b208.x + a->mUnk_b0.x - (a->mUnk_b0.x >> 3);
            a->mUnk_e8.y = data_0217b208.y + a->mUnk_b0.y - (a->mUnk_b0.y >> 3);
            a->mUnk_e8.z = data_0217b208.z + a->mUnk_b0.z - (a->mUnk_b0.z >> 3);
            a->mUnk_e4 = 0xe00;
        } else {
            a->mUnk_e8 = a->mUnk_b0;
            a->mUnk_e4 = 0x1000;
        }
        w1 = 0x1e;
        func_01ff9048(0x14, &w1, 1);
        func_01ff9048(0x19, func_020e6cbc(&a->mUnk_e8), 12);
        u = a->mUnk_e4;
        f1[0] = u;
        f1[1] = u;
        f1[2] = u;
        func_01ff9048(0x1b, f1, 3);
        for (j = 0; j < n; j++) {
            i = data_02156720[n - 1][j];
            e = a->mUnk_f8[i];
            func_01ff9048(0x11, NULL, 0);
            k = data_02156700[n - 1][i];
            Matrix3x3FromPairZ(m1, gPairsByAngle[(k >> 4) * 2 + 1], gPairsByAngle[(k >> 4) * 2]);
            func_01ff9048(0x1a, m1, 9);
            t = e->mUnk_d0;
            if (t != 0x1000) {
                g1[0] = t;
                g1[1] = t;
                g1[2] = t;
                func_01ff9048(0x1b, g1, 3);
            }
            h[0] = 0;
            h[1] = 0xf66;
            h[2] = 0;
            func_01ff9048(0x1c, h, 3);
            func_0209b940(gBalloon, func_020d3c44());
            func_0209b688(gBalloon, e->mUnk_a8);
            func_0209bb2c(p, gBalloon, a);
            w2 = 1;
            func_01ff9048(0x12, &w2, 1);
        }
    }
}

void func_020a392c(Unk0206c1ac *a, Balloon *b) {
    a->mUnk_72 = func_0208606c(b->mUnk_a8);
}

void func_020a36a8(Balloon *a) {
    Kart *p;
    Vec3 *q;
    Vec3 v;
    s32 s;
    s32 t;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;

    if (a->mUnk_a4 < 0) {
        a->mUnk_00.mUnk_10.y = a->mUnk_00.mUnk_10.y + 0x1800;
    } else {
        p = GetKart((u16) a->mUnk_a4);
        q = &p->mUnk_12c;
        a->mUnk_00.mUnk_10.x = a->mUnk_00.mUnk_10.x + (q->x + (q->x >> 1));
        a->mUnk_00.mUnk_10.y = a->mUnk_00.mUnk_10.y + (q->y + (q->y >> 1));
        a->mUnk_00.mUnk_10.z = a->mUnk_00.mUnk_10.z + (q->z + (q->z >> 1));
    }
    v1 = (a->mUnk_00.mPos.x + a->mUnk_00.mUnk_10.x) - (a->mUnk_b0.x + a->mUnk_bc.x);
    v3 = (a->mUnk_00.mPos.z + a->mUnk_00.mUnk_10.z) - (a->mUnk_b0.z + a->mUnk_bc.z);
    t = (s32) (((s64) 0xa000 * (a->mUnk_d0 + a->mUnk_d8)) >> 12);
    v6 = v3 < 0 ? -v3 : v3;
    v4 = v1 < 0 ? -v1 : v1;
    v7 = v4 / 2 + v6 / 2;
    if (v7 <= t) {
        a->mUnk_e0 = 1;
    } else if (a->mUnk_e0 != 0) {
        if (v7 > t) {
            s = DivFixed12(v7 - t, v7);
            v.x = (s32) (((s64) v1 * s) >> 12);
            v.y = 0;
            v.z = (s32) (((s64) v3 * s) >> 12);
            Vec3Sub(&a->mUnk_00.mPos, &v, &a->mUnk_00.mPos);
        }
    }
    v1 = (a->mUnk_00.mPos.x + a->mUnk_00.mUnk_10.x) - (a->mUnk_b0.x + a->mUnk_bc.x);
    v2 = (a->mUnk_00.mPos.y + a->mUnk_00.mUnk_10.y) - (a->mUnk_b0.y + a->mUnk_bc.y);
    v3 = (a->mUnk_00.mPos.z + a->mUnk_00.mUnk_10.z) - (a->mUnk_b0.z + a->mUnk_bc.z);
    t = (a->mUnk_d0 + a->mUnk_d8) << 4;
    v5 = v2 < 0 ? -v2 : v2;
    v4 = v1 < 0 ? -v1 : v1;
    v6 = v3 < 0 ? -v3 : v3;
    v7 = v5 + (v4 >> 2) + (v6 >> 2);
    if (v7 > t) {
        s = DivFixed12(v7 - t, v7);
        v.x = (s32) (((s64) v1 * s) >> 12);
        v.y = (s32) (((s64) v2 * s) >> 12);
        v.z = (s32) (((s64) v3 * s) >> 12);
        if (a->mUnk_a4 >= 0) {
            Vec3Sub(&a->mUnk_00.mUnk_10, &v, &a->mUnk_00.mUnk_10);
        } else {
            Vec3Add(&a->mUnk_bc, &v, &a->mUnk_bc);
        }
    }
    Vec3Add(&a->mUnk_00.mPos, &a->mUnk_00.mUnk_10, &a->mUnk_00.mPos);
    Vec3Add(&a->mUnk_b0, &a->mUnk_bc, &a->mUnk_b0);
}

u32 func_020a369c(Balloon *p) {
    return p->mUnk_00.mFlags & 0x12;
}

u32 func_020a3690(Balloon *p) {
    return p->mUnk_00.mUnk_78 & ~0xc000001fu;
}

void func_020a35b0(Balloon *a) {
    Camera *g;
    Vec3 v;
    u16 v1;
    s32 i;
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 u;
    s32 w;

    g = GetCurrentCamera();
    v1 = AngleFromPair(g->mForward.x, g->mForward.z) - 0x4000;
    Vec3Sub(&a->mUnk_00.mPos, &g->mPos, &v);
    i = (v1 >> 4) * 2;
    s = gPairsByAngle[i];
    c = gPairsByAngle[i + 1];
    x = (s32) (((s64) v.z * c) >> 12);
    y = (s32) (((s64) v.x * s) >> 12);
    u = v.y;
    Vec3Sub(&a->mUnk_b0, &g->mPos, &v);
    w = (s32) (((s64) v.x * s) >> 12) + (s32) (((s64) v.z * c) >> 12);
    a->mUnk_00.mAngle = AngleFromPair(u - v.y, -(y + x - w));
}

void UpdateBalloon(void *p, Balloon *a) {
    Kart *o;

    if (a->mUnk_a4 >= 0) {
        switch (a->mState) {
            case 0:
                a->mUnk_d8 = a->mUnk_d8 + a->mUnk_dc;
                if (a->mUnk_d8 >= 0) {
                    if (a->mUnk_dc < 0) {
                        a->mUnk_dc = -50;
                    } else {
                        a->mUnk_dc = a->mUnk_dc - 10;
                    }
                } else {
                    if (a->mUnk_dc >= 0) {
                        a->mUnk_dc = 50;
                    } else {
                        a->mUnk_dc = a->mUnk_dc + 10;
                    }
                }
                if (a->mUnk_a4 == data_021759c0->mEntryIndex) {
                    if (func_02061fec() == 1) {
                        o = GetKart((u16) a->mUnk_a4);
                        func_020249b8(o, a->mUnk_d0 + a->mUnk_d8, a->mUnk_d4);
                    }
                }
                if (a->mUnk_f4 == 1 && a->mUnk_f8 == NULL) {
                    func_020a36a8(a);
                    if (func_020a369c(a) != 0) {
                        return;
                    }
                    if (func_020a3690(a) >= 0x9c40) {
                        return;
                    }
                    func_020a35b0(a);
                } else {
                    a->mUnk_00.mPos.x = a->mUnk_b0.x;
                    a->mUnk_00.mPos.y = a->mUnk_b0.y + 0xf666;
                    a->mUnk_00.mPos.z = a->mUnk_b0.z;
                }
                break;
            case 1:
                a->mUnk_d8 = 0;
                a->mUnk_d0 = a->mUnk_d0 + a->mUnk_d4;
                if (a->mUnk_d0 >= 0x1000) {
                    a->mUnk_d4 = a->mUnk_d4 - 200;
                }
                if (a->mUnk_d4 < 0) {
                    if (a->mUnk_d0 <= 0x1000) {
                        a->mUnk_d0 = 0x1000;
                        a->mState = 2;
                    }
                }
                if (a->mUnk_f4 == 1 && a->mUnk_f8 == NULL) {
                    func_020a36a8(a);
                    if (func_020a369c(a) != 0) {
                        return;
                    }
                    if (func_020a3690(a) >= 0x9c40) {
                        return;
                    }
                    func_020a35b0(a);
                } else {
                    a->mUnk_00.mPos.x = a->mUnk_b0.x;
                    a->mUnk_00.mPos.y = a->mUnk_b0.y + 0xf666;
                    a->mUnk_00.mPos.z = a->mUnk_b0.z;
                }
                break;
            case 2:
                a->mUnk_d8 = 0;
                a->mUnk_d0 = 0x1000;
                if (a->mUnk_f4 == 1 && a->mUnk_f8 == NULL) {
                    func_020a36a8(a);
                    if (func_020a369c(a) != 0) {
                        return;
                    }
                    if (func_020a3690(a) >= 0x9c40) {
                        return;
                    }
                    func_020a35b0(a);
                } else {
                    a->mUnk_00.mPos.x = a->mUnk_b0.x;
                    a->mUnk_00.mPos.y = a->mUnk_b0.y + 0xf666;
                    a->mUnk_00.mPos.z = a->mUnk_b0.z;
                }
                break;
            default:
                return;
        }
    } else {
        a->mUnk_d8 = 0;
        a->mUnk_d0 = 0x1000;
        if (a->mUnk_a0-- <= 0) {
            func_0208b748(0x5b, &a->mUnk_00.mPos, a, func_020a392c);
            func_0208b748(0x5c, &a->mUnk_00.mPos, a, func_020a392c);
            func_0208b748(0x5d, &a->mUnk_00.mPos, a, func_020a392c);
            func_0210b8f4(&a->mUnk_00.mPos, func_020d4ef4(&a->mUnk_00.mPos));
            func_020d2398(&a->mUnk_00);
        } else {
            a->mUnk_c8 = a->mUnk_c8 + a->mUnk_cc;
            if (a->mUnk_c8 >= 0) {
                if (a->mUnk_cc < 0) {
                    a->mUnk_cc = -0x640;
                } else {
                    a->mUnk_cc = a->mUnk_cc - 200;
                }
            } else {
                if (a->mUnk_cc >= 0) {
                    a->mUnk_cc = 0x640;
                } else {
                    a->mUnk_cc = a->mUnk_cc + 200;
                }
            }
        }
        a->mUnk_00.mAngle = a->mUnk_c8 + 0x4000;
        a->mUnk_00.mUnk_10.y = a->mUnk_00.mUnk_10.y + 0x59a;
        a->mUnk_bc.y = a->mUnk_bc.y - 0x2000;
        a->mUnk_00.mUnk_10.x = (s32) (((s64) a->mUnk_00.mUnk_10.x * 0xc00) >> 12);
        a->mUnk_00.mUnk_10.y = (s32) (((s64) a->mUnk_00.mUnk_10.y * 0xc00) >> 12);
        a->mUnk_00.mUnk_10.z = (s32) (((s64) a->mUnk_00.mUnk_10.z * 0xc00) >> 12);
        Vec3Add(&a->mUnk_00.mPos, &a->mUnk_00.mUnk_10, &a->mUnk_00.mPos);
        Vec3Add(&a->mUnk_b0, &a->mUnk_bc, &a->mUnk_b0);
    }
}

u32 func_020a3130(void) {
    return func_0209bef0(CreateBalloon, DrawBalloon, func_020a3e38);
}

u32 func_020a3114(void) {
    return func_0209bf48(NULL, UpdateBalloon, NULL);
}

void func_020a305c(void) {
    s32 i;
    Unk02100094 *v1;
    Balloon *e;

    v1 = func_02100138(0x6c);
    if (v1 == NULL) {
        return;
    }
    for (i = 0; i < v1->mUnk_04 && (e = v1->mUnk_00[i]) != NULL; i++) {
        if (e->mUnk_a4 >= 0) {
            e->mUnk_a4 = (u16) data_021759c0->mEntryIndex;
            e->mUnk_d0 = 0x1000;
            e->mUnk_d4 = 0;
            e->mUnk_d8 = 0;
            e->mUnk_dc = 0;
            e->mState = 2;
        } else if ((e->mUnk_00.mFlags & 0x100) == 0) {
            func_020d2398(&e->mUnk_00);
        }
    }
}

Balloon *func_020a2fe4(u16 a, Vec3 *b) {
    Balloon *o;

    o = func_0209bbfc(func_02100138(0x6c));
    if (o == NULL) {
        return NULL;
    }
    o->mUnk_b0 = *b;
    o->mUnk_00.mPos = o->mUnk_b0;
    o->mUnk_d0 = 0;
    o->mUnk_d4 = 0;
    o->mUnk_d8 = 0;
    o->mUnk_dc = 0;
    o->mUnk_e0 = 0;
    o->mUnk_a8 = a;
    o->mState = 0;
    return o;
}

void func_020a2f9c(Balloon *a, u16 b, s32 c) {
    a->mUnk_a4 = b;
    a->mUnk_d4 = c;
    a->mUnk_d0 = a->mUnk_d0 + a->mUnk_d4;
    a->mUnk_d8 = 0;
    a->mUnk_dc = 0;
    a->mState = 0;
    if (a->mUnk_d0 >= 0x1000) {
        a->mUnk_d8 = 0;
        a->mUnk_d4 = 0x258;
        a->mState = 1;
    }
}

void func_020a2f30(Balloon *a, u16 b, s32 c) {
    a->mUnk_a4 = b;
    a->mUnk_d4 = -c;
    a->mUnk_d0 = a->mUnk_d0 + a->mUnk_d4;
    a->mState = 0;
    if (a->mUnk_d0 > 0) {
        return;
    }
    a->mUnk_d8 = 0;
    a->mUnk_d0 = 0;
    a->mUnk_a4 = -1;
    a->mUnk_f4 = 1;
    a->mUnk_f8 = NULL;
    func_020d2398(&a->mUnk_00);
}
