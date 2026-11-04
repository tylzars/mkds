#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209df00.h"
#include "Main/Unknown/code_0209eb54.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"

u32 func_0209eb04(void) {
    return func_0209bef0(CreatePuddle, func_0209eb54, func_0209ec00);
}

void func_0209ea90(Unk0209df84 *a) {
    a->mUnk_00.mFlags |= data_usa_021565ec;
    a->mUnk_a0 = a->mUnk_00.mCourseMapRow->mUnk_28;
    a->mUnk_a2 = a->mUnk_00.mCourseMapRow->mUnk_2e + 1;
    func_020d28e0(&a->mUnk_00);
    a->mUnk_00.mFlags &= ~1;
    a->mUnk_00.mFlags &= ~2;
    a->mUnk_00.mFlags &= ~8;
    a->mUnk_00.mUnk_66 = 0x1f;
}

u8 func_0209ea10(Unk0209df84 *a, Kart *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mUnk_19c4[b->mIndex] == 0) {
        if (b->mUnk_29c == 1 || b->mUnk_29c == 3) {
            a->mUnk_00.mUnk_78 |= data_usa_021565e8;
        }
        func_020d26f8(&a->mUnk_00, b);
    }
    a->mUnk_19c4[b->mIndex] = 0xb;
    return v;
}

static inline BOOL func_0209df84_inline(Kart *p, Unk0209df84 *b, s32 t) {
    s32 y;
    s32 x;
    s32 z;
    s32 u;

    u = -t;
    z = p->mUnk_80.z - b->mUnk_00.mPos.z;
    if (z > t || z < u) {
        return FALSE;
    }
    x = p->mUnk_80.x - b->mUnk_00.mPos.x;
    if (x > t || x < u) {
        return FALSE;
    }
    y = p->mUnk_80.y - b->mUnk_00.mPos.y;
    if (y > t || y < u) {
        return FALSE;
    }
    return (s64) x * x + (s64) y * y + (s64) z * z < (s64) t * t;
}

BOOL func_0209e988(Unk0209df84 *a, Vec3 *b, s32 c) {
    s32 i;
    s32 d;
    s32 e;
    s32 f;

    for (i = 0; i < a->mUnk_a0; i++) {
        d = b->x - a->mUnk_c4[i][0].mUnk_00.x;
        e = b->y - a->mUnk_c4[i][0].mUnk_00.y;
        f = b->z - a->mUnk_c4[i][0].mUnk_00.z;
        if ((s64) d * d + (s64) e * e + (s64) f * f < (s64) (c + 0xf000) * (c + 0xf000)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_0209e950(Unk0209e950 *a) {
    gFireball2 = func_0209bd08(a, gFireball2NsbmdName);
    func_0209b940(gFireball2, 0x3f);
    a->mUnk_1c = 1;
}

void func_0209e938(void *a) {
    func_0209bbd0(a, gFireball2);
}

void func_0209e508(void *a, Unk0209df84 *b) {
    s32 s1;
    s32 s2;
    s32 s3;
    s32 m1[9];
    s32 m2[9];
    s32 m3[9];
    s32 i;
    s32 c;
    s32 j;
    s32 f;
    s32 g;
    Unk02061808 *q;

    q = func_02061808();
    c = func_02039828(&b->mUnk_00.mMatrix.mUnk_00[0], &q->mUnk_15c);
    for (i = 0; i < b->mUnk_a0; i++) {
        if (c >= 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (b->mUnk_c4[i][0].mUnk_0c >= 0x4000 && b->mUnk_c4[i][0].mUnk_0c < 0xc000) {
            g = 1;
        } else {
            g = 0;
        }
        if (f ^ g) {
            for (j = 0; j < b->mUnk_a2; j++) {
                s1 = 0x1e;
                func_01ff9048(0x14, &s1, 1);
                func_01ff9048(0x19, func_020e6cf8(&b->mUnk_c4[i][j].mUnk_00), 0xc);
                if (b->mUnk_c4[i][j].mUnk_0e != 0) {
                    Matrix3x3FromPairZ(m1, gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2],
                                       gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2 + 1]);
                    func_01ff9048(0x1a, m1, 9);
                }
                func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
                func_0209b940(gFireball2, func_020d3c44());
                func_0209bb2c(a, gFireball2, b);
            }
        }
    }
    if (b->mUnk_a2 > 1) {
        s2 = 0x1e;
        func_01ff9048(0x14, &s2, 1);
        func_01ff9048(0x19, func_020e6cf8(&b->mUnk_b4), 0xc);
        if (b->mUnk_c2 != 0) {
            Matrix3x3FromPairZ(m2, gPairsByAngle[(b->mUnk_c2 >> 4) * 2], gPairsByAngle[(b->mUnk_c2 >> 4) * 2 + 1]);
            func_01ff9048(0x1a, m2, 9);
        }
        func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
        func_0209b940(gFireball2, func_020d3c44());
        func_0209bb2c(a, gFireball2, b);
    }
    for (i = 0; i < b->mUnk_a0; i++) {
        if (c >= 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (b->mUnk_c4[i][0].mUnk_0c >= 0x4000 && b->mUnk_c4[i][0].mUnk_0c < 0xc000) {
            g = 1;
        } else {
            g = 0;
        }
        if ((f ^ g) == 0) {
            for (j = b->mUnk_a2 - 1; j >= 0; j--) {
                s3 = 0x1e;
                func_01ff9048(0x14, &s3, 1);
                func_01ff9048(0x19, func_020e6cf8(&b->mUnk_c4[i][j].mUnk_00), 0xc);
                if (b->mUnk_c4[i][j].mUnk_0e != 0) {
                    Matrix3x3FromPairZ(m3, gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2],
                                       gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2 + 1]);
                    func_01ff9048(0x1a, m3, 9);
                }
                func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
                func_0209b940(gFireball2, func_020d3c44());
                func_0209bb2c(a, gFireball2, b);
            }
        }
    }
}

void func_0209e310(Unk020e6fd4 *p) {
    s32 i;
    s32 j;
    s32 k;
    s16 v;
    float f;
    u64 t;
    Unk0209df84 *e;
    Unk020f41c4_B *r;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (e = p->mUnk_00[i]) != NULL; i++) {
        v = e->mUnk_00.mCourseMapRow->mUnk_2a;
        if (v > 0) {
            f = 0.5f + (float) (v << 12);
        } else {
            f = (float) (v << 12) - 0.5f;
        }
        e->mUnk_ac = (s32) f;
        e->mUnk_b0 = (e->mUnk_00.mCourseMapRow->mUnk_2c * 0x16c) / 100;
        e->mUnk_a4 = 0x10000 / e->mUnk_a0;
        e->mUnk_a8 = e->mUnk_ac / e->mUnk_a2;
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        t = r->mUnk_00 >> 32;
        e->mUnk_c2 = (u16) ((t * 0x10000) >> 32);
        for (j = 0; j < e->mUnk_a2; j++) {
            for (k = 0; k < e->mUnk_a0; k++) {
                r = func_020d22d0();
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                t = r->mUnk_00 >> 32;
                e->mUnk_c4[k][j].mUnk_0e = (u16) ((t * 0x10000) >> 32);
            }
        }
    }
}

void func_0209df84(void *a, Unk0209df84 *b) {
    s32 i;
    s32 j;
    s32 n;
    s32 d;
    u16 w;
    Kart *p;
    Unk0212c400 **h;
    Vec3 v;

    n = b->mUnk_ac;
    b->mUnk_b4 = b->mUnk_00.mPos;
    if (b->mUnk_a2 == 1) {
        p = GetKart((u16) data_021759c0->mEntryIndex);
        if (func_0209df84_inline(p, b, n - 0xf000) != FALSE) {
            Vec3Sub(&p->mUnk_80, &b->mUnk_00.mPos, &v);
            d = func_02039828(&v, &b->mUnk_00.mMatrix.mUnk_00[2]);
            if ((b->mUnk_19e4 < 0 && d > 0) || (b->mUnk_19e4 > 0 && d < 0)) {
                func_02108e38();
                h = func_02108e6c(7);
                if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
                    if (h[0] != NULL) {
                        func_0212c6f0(h, 0);
                    }
                    if (h[0] != NULL) {
                        func_0212c6f0(h, 0);
                    }
                    func_0212ecc0(h, 0, 0x1c2);
                }
                b->mUnk_19e4 = 0;
            } else {
                b->mUnk_19e4 = d;
            }
        } else {
            b->mUnk_19e4 = 0;
        }
    }
    if (b->mUnk_a2 > 1) {
        b->mUnk_c2 = b->mUnk_c2 + 0x51e;
    }
    for (i = 0; i < b->mUnk_a2; i++) {
        w = b->mUnk_b2;
        for (j = 0; j < b->mUnk_a0; j++) {
            w = w + b->mUnk_a4;
            b->mUnk_c4[j][i].mUnk_0c = w;
            Vec3AddScaled(((s64) n * gPairsByAngle[(w >> 4) * 2 + 1]) >> 12, &b->mUnk_00.mMatrix.mUnk_00[0],
                          &b->mUnk_00.mPos, &b->mUnk_c4[j][i].mUnk_00);
            Vec3AddScaled(((s64) n * gPairsByAngle[(w >> 4) * 2]) >> 12, &b->mUnk_00.mMatrix.mUnk_00[1],
                          &b->mUnk_c4[j][i].mUnk_00, &b->mUnk_c4[j][i].mUnk_00);
            b->mUnk_c4[j][i].mUnk_0e = b->mUnk_c4[j][i].mUnk_0e + 0x51e;
        }
        n = n - b->mUnk_a8;
    }
    b->mUnk_b2 = b->mUnk_b2 - b->mUnk_b0;
    for (i = 0; i < data_021759c0->mKartCount; i++) {
        if (b->mUnk_19c4[i] > 0) {
            b->mUnk_19c4[i] = b->mUnk_19c4[i] - 1;
        }
    }
    func_020d275c(&b->mUnk_00, 0x160);
}

void func_0209df44(void) {
    func_0209bf70(func_0209ea10, NULL, func_0209e988, 0, 0, 0x18d);
}

u32 func_0209df20(void) {
    return func_0209bef0(func_0209e950, func_0209e508, func_0209e938);
}

u32 func_0209df00(void) {
    return func_0209bf48(func_0209e310, func_0209df84, NULL);
}
