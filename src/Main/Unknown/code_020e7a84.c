#include "Main/Unknown/code_020e7a84.h"

#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_0210b000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147288.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020e8a78.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02012b30.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"

#pragma thumb off

#pragma thumb on

void func_020ea4bc(u32 param_1, void *param_2, void **param_3, void *param_4, void *param_5) {
    *param_3 = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    func_0208823c(param_1, *param_3, param_2, 1, GetHeap(func_020364e8()), param_4);
    func_0208805c(*param_3, param_5, GetHeap(func_020364e8()));
    func_02087f84(*param_3, 0);
}

#pragma thumb off

void func_020ea37c(void) {
    data_0217b8dc = 0xf662;
    data_0217b8d4 = 0x1232e;
    data_0217b9a8 = data_02159434;
    data_0217b9a8.x += 0xf662;
    data_0217b990 = data_021593d4;
    data_0217b990.x += 0xf662;
    data_0217b960 = data_02159428;
    data_0217b960.x += 0xf662;

    data_0217b978 = func_0203c5e4() ? data_021593f8 : data_0215941c;
    data_0217b978.x += data_0217b8dc;
    if (data_0217b8f8 == 0) {
        data_0217b9a8.x = -data_0217b9a8.x;
        data_0217b990.x = -data_0217b990.x;
        data_0217b978.x = -data_0217b978.x;
        data_0217b960.x = -data_0217b960.x;
    }
    data_0217b960.y += data_0217b8d4;
}

static inline s32 func_020ea1d4_inline(s32 a, s32 b, s32 t) {
    s32 d = b - a;
    return a + (s32) (((s64) d * t) >> 12);
}

void func_020ea1d4(Vec3 *param_1, const Vec3 *param_2, const Vec3 *param_3) {
    Vec3 v;
    Vec3 w;
    s32 i;
    s32 c;
    s32 s;
    s32 a;
    s32 b;

    if (func_020d849c(&data_0217bb88.mUnk_00) != FALSE) {
        do {
            for (i = 0; i < 4; i++) {
                data_0217b9cc[i] += 1;
                if (data_0217b9cc[i] > &data_0217bb7c) {
                    data_0217b9cc[i] = data_0217bb28;
                }
            }
        } while (func_020d7c84(&data_0217bb88.mUnk_00, 0, data_0217b9cc) != FALSE);
    }
    func_020d8488(&data_0217bb88, &v);
    data_0217b878 += 0x64;
    i = data_0217b878 >> 4;
    c = gPairsByAngle[i * 2];
    s = gPairsByAngle[i * 2 + 1];
    b = func_020ea1d4_inline(param_3->x, param_2->x, (s + 0x1000) >> 2);
    a = func_020ea1d4_inline(param_3->y, param_2->y, (c + 0x1000) >> 2);
    v.x = (s32) (((s64) v.x * b) >> 12);
    v.y = (s32) (((s64) v.y * a) >> 12);
    v.z = 0;
    VEC_Add(&v, param_1, &v);
    w = v;
    w.x += data_0217b88c;
    MTX_MultVec43(&w, &data_0217bab8, &data_0217b9c0);
}

void func_020e9d10(void) {
    s32 n;
    u32 f;

    if (data_021759c0->mUnk_00c == 6) {
        return;
    }
    if (data_0217b8c8 == NULL) {
        return;
    }
    if (data_0217b9ec.mUnk_00e != 0) {
        data_0217b8e8++;
        if (data_0217b8e8 >= 0x3c) {
            data_0217b8e8 = 0;
        }
        if (data_0217b890 != 4) {
            Unk0217bb08 *p = &data_0217bae8[data_0217b890];
            if (data_0217b890 != 0 && data_0217b890 != 1) {
                if (p->mUnk_04 != NULL) {
                    func_02087de0(p->mUnk_04);
                }
                if (p->mUnk_08 != NULL) {
                    func_02087de0(p->mUnk_08);
                }
            }
        }
        if (data_0217b9ec.mUnk_00e != 4 && (data_0217b9ec.mUnk_00e != 5 || data_0217b890 != 4)) {
            data_0217b954 = data_0217b8c8->mPos;
            data_0217b954.y -= data_0217b8c8->mHopHeight;
        }
        func_020e9658();
        func_020e8ac8();
    }
    func_02046b40(&data_0217b9ec);
    if (data_0217b9ec.mUnk_00e != 0) {
        return;
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        return;
    }
    if (data_021759c0->mMode != MODE_MISSION_RUN && gRaceProgress->mUnk_000[data_0217b888].mStatus == 1 &&
        (data_0217b8c8->mUnk_48 & 0x800) == 0) {
        Vec3 v;
        data_0217ba2c.mUnk_18 = 2;
        data_0217b954 = data_0217b8c8->mPos;
        data_0217b954.y -= data_0217b8c8->mHopHeight;
        func_020e9658();
        v = data_0217b990;
        v.x += data_0217b88c;
        MTX_MultVec43(&v, &data_0217bab8, &data_0217b9c0);
        data_0217b890 = 3;
        if (func_0203c5e4() == 0) {
            if ((u32) data_0217b890 <= 1) {
                data_0217b900 = 1;
                data_0217b8ac = 1;
            }
        }
        func_02046bcc(&data_0217b9ec, 6);
        return;
    }
    if (IsKartEnded(data_0217b888) != 0) {
        return;
    }
    if (data_0217b8b0 != 0) {
        n = func_0203c8c0(data_0217b888);
        if ((u32) data_0217b87c < (u32) n) {
            Vec3 v;
            data_0217b87c = n;
            data_0217b954 = data_0217b8c8->mPos;
            data_0217b954.y -= data_0217b8c8->mHopHeight;
            func_020e9658();
            v = data_0217b978;
            v.x += data_0217b88c;
            MTX_MultVec43(&v, &data_0217bab8, &data_0217b9c0);
            if (data_0217b87c == data_0217b884) {
                data_0217b890 = 1;
                if (func_0203c5e4() == 0) {
                    if ((u32) data_0217b890 <= 1) {
                        data_0217b900 = 1;
                        data_0217b8ac = 1;
                    }
                }
                func_02046bcc(&data_0217b9ec, 6);
                return;
            }
            data_0217b890 = 0;
            if (func_0203c5e4() == 0) {
                if ((u32) data_0217b890 <= 1) {
                    data_0217b900 = 1;
                    data_0217b8ac = 1;
                }
            }
            func_02046bcc(&data_0217b9ec, 6);
            return;
        }
    }
    f = data_0217b8c8->mUnk_48;
    if (f & 1) {
        return;
    }
    if (data_0217b8b0 == 0) {
        return;
    }
    if ((gRaceProgress->mUnk_000[data_0217b888].mFlags & 4) != 0 && (f & 0x800) == 0) {
        data_0217b8c4++;
        if (data_0217b8c4 <= 0x3c) {
            return;
        }
        data_0217b954 = data_0217b8c8->mPos;
        data_0217b954.y -= data_0217b8c8->mHopHeight;
        func_020e9658();
        func_02046bcc(&data_0217b9ec, 1);
        return;
    }
    data_0217b8c4 = 0;
}

void func_020e9810(void) {
    s32 a, b, c, d, e, f, g, h;
    s32 m[9];
    Vec3 v0, v1, v2, v3, v4, v5, v6;
    BOOL n;
    s32 x;
    s32 y;
    Unk020e9810 *p5;
    Unk020e6488 *p4;

    if (data_021759c0->mUnk_00c == 6) {
        return;
    }
    if (data_0217b8c8 == NULL) {
        return;
    }
    if (data_0217b8e4 == 0) {
        goto reset;
    }
    n = FALSE;
    p5 = NULL;
    p4 = NULL;
    switch (data_0217b890) {
        case 2:
        case 3:
            p5 = data_0217bae8[data_0217b890].mUnk_00;
            break;
        case 0:
        case 1:
            p4 = data_0217baf4[data_0217b890].mUnk_00;
            break;
    }
    func_0208ab4c(data_0217b8c0);
    data_0217b874++;
    if (data_0217b874 > 0x1f) {
        data_0217b874 = 0x1f;
    }
    data_0217ba2c.mUnk_14 &= ~0x1f0000;
    data_0217ba2c.mUnk_14 |= data_0217b874 << 16;
    data_0217ba00.mUnk_14 &= ~0x1f0000;
    data_0217ba00.mUnk_14 |= data_0217b874 << 16;
    if (p5 != NULL) {
        NNS_G3dMdlSetMdlAlphaAll(p5->mUnk_04, data_0217b874);
    }
    if (p4 != NULL) {
        p4->mUnk_14 &= ~0x1f0000;
        p4->mUnk_14 |= data_0217b874 << 16;
    }
    if (data_0217b900 != 0) {
        a = 0;
        func_01ff9048(0x10, &a, 1);
        func_01ff9048(0x11, NULL, 0);
        v0.x = 0x19a;
        v0.y = 0x19a;
        v0.z = 0x19a;
        func_01ff9048(0x1b, &v0, 3);
        b = 2;
        func_01ff9048(0x10, &b, 1);
        n = TRUE;
    }
    c = 0x1e;
    func_01ff9048(0x14, &c, 1);
    func_01ff9048(0x19, func_020e6cf8(&data_0217b948), 0xc);
    v1.y = data_0217b8a4[data_0217b8e8];
    v1.x = 0;
    v1.z = 0;
    func_01ff9048(0x1c, &v1, 3);
    v2.x = data_0217b8f8 != 0 ? 0x1666 : -0x1666;
    v2.y = 0x1666;
    v2.z = 0x1666;
    func_01ff9048(0x1b, &v2, 3);
    func_01ff9048(0x11, NULL, 0);
    x = data_0217b904[data_0217b8e8];
    y = data_0217b8e0[data_0217b8e8];
    v3.x = x;
    v3.y = y;
    v3.z = 0;
    func_01ff9048(0x1b, &v3, 3);
    func_020e6a18(&data_0217ba00);
    func_020e6854(&data_0217ba00, NULL, 0, 0x1f);
    d = 1;
    func_01ff9048(0x12, &d, 1);
    v4.x = 0;
    v4.y = 0;
    v4.z = 0xa4;
    func_01ff9048(0x1c, &v4, 3);
    MTX_RotZ33_(m, data_0217b8a8[data_0217b8e8], data_0217b8a0[data_0217b8e8]);
    func_01ff9048(0x1a, m, 9);
    func_020e6a18(&data_0217ba2c);
    func_020e6854(&data_0217ba2c, NULL, 0, 0x1f);
    if (p5 != NULL) {
        if (data_0217b890 == 3) {
            e = 0;
            func_01ff9048(0x12, &e, 1);
            func_01ff8cf0(p5);
        } else {
            func_01ff9048(0x1c, &data_021593c8, 3);
            if (data_0217b8f8 == 0) {
                v5.x = -0x1000;
                v5.y = 0x1000;
                v5.z = 0x1000;
                func_01ff9048(0x1b, &v5, 3);
            }
            func_01ff8cf0(p5);
        }
    }
    if (p4 != NULL) {
        func_01ff9048(0x1c, &data_021593c8, 3);
        if (data_0217b8f8 == 0) {
            v6.x = -0x1000;
            v6.y = 0x1000;
            v6.z = 0x1000;
            func_01ff9048(0x1b, &v6, 3);
        }
        func_020e6a18(p4);
        func_020e6854(p4, NULL, 0, 0x1f);
    }
    if (n != FALSE) {
        f = 0;
        func_01ff9048(0x10, &f, 1);
        g = 1;
        func_01ff9048(0x12, &g, 1);
        h = 2;
        func_01ff9048(0x10, &h, 1);
    }
    goto done;
reset:
    data_0217b874 = 0;
done:;
}

void func_020e9658(void) {
    s32 r;
    s64 sq;
    Vec3 *v;

    data_0217ba88 = data_0217ba58;
    VEC_Subtract(&data_0217b954, &data_0217bab8.mUnk_00[3], &data_0217b9b4);
    data_0217bab8.mUnk_00[3] = data_0217b954;
    data_0217bab8.mUnk_00[3].y = data_0217bab8.mUnk_00[3].y + (data_0217b8c8->mVelocity.y - data_0217b8c8->mHopSpeed);
    data_0217bab8.mUnk_00[1] = data_02159494;

    if (func_0203c5e4() != 0) {
        v = &data_0217b8c8->mUnk_50;
        data_0217bab8.mUnk_00[2].x = -v->x;
        data_0217bab8.mUnk_00[2].y = -v->y;
        data_0217bab8.mUnk_00[2].z = -v->z;
    } else {
        data_0217bab8.mUnk_00[2] = ((MtxFx43 *) func_020e6b38())->mUnk_00[2];
    }
    Vec3CrossUnrounded(&data_0217bab8.mUnk_00[1], &data_0217bab8.mUnk_00[2], &data_0217bab8.mUnk_00[2]);
    sq = (s64) data_0217bab8.mUnk_00[2].x * data_0217bab8.mUnk_00[2].x +
         (s64) data_0217bab8.mUnk_00[2].y * data_0217bab8.mUnk_00[2].y +
         (s64) data_0217bab8.mUnk_00[2].z * data_0217bab8.mUnk_00[2].z;
    r = 0;
    if (sq >= 0x10) {
        r = Vec3NormalizeAndGetLengthUnchecked(&data_0217bab8.mUnk_00[2], &data_0217bab8.mUnk_00[2]);
    }
    if (r != 0) {
        data_0217bab8.mUnk_00[0] = data_0217bab8.mUnk_00[2];
    }
    Vec3CrossUnrounded(&data_0217bab8.mUnk_00[0], &data_0217bab8.mUnk_00[1], &data_0217bab8.mUnk_00[2]);
    MTX_Transpose33_(&data_0217bab8, &data_0217ba58);
    MTX_MultVec33(&data_0217bab8.mUnk_00[3], (const s32 *) &data_0217ba58, &data_0217ba7c);
    data_0217ba58.mUnk_00[3].x = -data_0217ba58.mUnk_00[3].x;
    data_0217ba58.mUnk_00[3].y = -data_0217ba58.mUnk_00[3].y;
    data_0217ba58.mUnk_00[3].z = -data_0217ba58.mUnk_00[3].z;
}

static inline void func_020e8ac8_inline(Vec3 *o, const Vec3 *a, const Vec3 *b) {
    o->x = a->x < b->x ? a->x : b->x;
    o->y = a->y < b->y ? a->y : b->y;
    o->z = a->z < b->z ? a->z : b->z;
}

static inline void func_020e8ac8_inline_2(Vec3 *o, const Vec3 *a, const Vec3 *b) {
    o->x = a->x > b->x ? a->x : b->x;
    o->y = a->y > b->y ? a->y : b->y;
    o->z = a->z > b->z ? a->z : b->z;
}

void func_020e8ac8(void) {
    s64 sq;
    s32 dz;
    s32 dx;

    if (data_0217b9ec.mUnk_00e == 4 || data_0217b8e4 == 0) {
        data_0217b90c = data_0217b9c0;
        data_0217b918 = data_0217b90c;
        data_0217b93c = data_0217b918;
        data_0217b99c = data_0217b93c;
        data_0217b930 = data_0217b99c;
        data_0217b9b4.x = 0;
        data_0217b9b4.y = 0;
        data_0217b9b4.z = 0;
        data_0217b924.x = 0;
        data_0217b924.y = 0;
        data_0217b924.z = 0;
        data_0217b870 = 0;
        data_0217b8b8 = 0;
        data_0217b88c = 0;
        data_0217b8cc = 0;
        data_0217b8ec = 0;
        data_0217b948 = data_0217b930;
        data_0217b8f0 = 1;
        data_0217b8bc = 1;
        data_0217b894 = 0;
    } else {
        void *p;
        Vec3 t;
        Vec3 u;
        Vec3 v;
        s32 i;
        BOOL f = FALSE;
        Vec3 lo, hi;
        s32 d;
        s32 w;
        s32 lim;
        s32 n;

        lo = (Vec3){0, 0, 0};
        hi = (Vec3){0, 0, 0};
        if (data_0217b9ec.mUnk_00e == 6 || data_0217b9ec.mUnk_00e == 2) {
            p = NULL;
        } else {
            p = &data_0217b918;
        }
        data_0217b918 = data_0217b93c;
        if (data_0217b8f8 != 0) {
            d = -data_0217b8dc >> 1;
            t.x = (s32) (((s64) data_0217bab8.mUnk_00[0].x * d) >> 12);
            t.y = (s32) (((s64) data_0217bab8.mUnk_00[0].y * d) >> 12);
            t.z = (s32) (((s64) data_0217bab8.mUnk_00[0].z * d) >> 12);
        } else {
            d = data_0217b8dc >> 1;
            t.x = (s32) (((s64) data_0217bab8.mUnk_00[0].x * d) >> 12);
            t.y = (s32) (((s64) data_0217bab8.mUnk_00[0].y * d) >> 12);
            t.z = (s32) (((s64) data_0217bab8.mUnk_00[0].z * d) >> 12);
        }
        VEC_Add(&data_0217b930, &t, &data_0217b93c);
        d = -data_0217b8d4 >> 1;
        t.x = (s32) (((s64) data_0217bab8.mUnk_00[1].x * d) >> 12);
        t.y = (s32) (((s64) data_0217bab8.mUnk_00[1].y * d) >> 12);
        t.z = (s32) (((s64) data_0217bab8.mUnk_00[1].z * d) >> 12);
        VEC_Add(&data_0217b93c, &t, &data_0217b93c);
        data_0217b8fc = 0;
        if (data_0217b900 == 0) {
            if (data_0217b8bc != 0 || data_0217b8f0 != 0) {
                func_020d5180(&data_0217b93c, 0x12000, 0x2000);
                for (i = 0; i < data_0217b5a8; i++) {
                    MapObject *q = data_0217b5c4[i];

                    if ((q->mFlags & 0x40) == 0 && func_020d3e34(&data_0217b93c, 0x12000, q, &t) != FALSE) {
                        func_020e8ac8_inline(&lo, &t, &lo);
                        func_020e8ac8_inline_2(&hi, &t, &hi);
                        f = TRUE;
                    }
                }
                if (func_01ffdee4(&data_0217b93c, p, 0, 0x12000, 4, -1, &t, NULL, NULL, &data_0217b8fc, NULL, NULL,
                                  NULL, NULL) != 0) {
                    func_020e8ac8_inline(&lo, &t, &lo);
                    func_020e8ac8_inline_2(&hi, &t, &hi);
                    f = TRUE;
                }
            }
        }
        if (f != FALSE) {
            if ((data_0217b8fc & 0x80000) == 0) {
                data_0217b894 = 0;
            }
            t = lo;
            VEC_Add(&t, &hi, &t);
            if (t.y < 0 && data_0217b9ec.mUnk_00e == 5) {
                t.y = 0;
            }
            VEC_Add(&data_0217b930, &t, &data_0217b930);
            VEC_Add(&data_0217b93c, &t, &data_0217b93c);
        }
        if (data_0217b900 == 0) {
            data_0217b870++;
            if (data_0217b870 > 0xc) {
                data_0217b870 = 0;
            }
            data_0217b90c.x =
                data_0217b930.x + data_0217b870 * (s32) (((s64) data_0217b8c8->mVelocity.x * 0x5000) >> 12);
            data_0217b90c.z =
                data_0217b930.z + data_0217b870 * (s32) (((s64) data_0217b8c8->mVelocity.z * 0x5000) >> 12);
            data_0217b90c.y = data_0217b930.y;
            if (func_01ffdee4(&data_0217b90c, NULL, 0, 0x18e66, 0x10, -1, NULL, NULL, (s32 *) &v, NULL, NULL, NULL,
                              NULL, NULL) != 0) {
                w = data_0217b8c8->mForwardSpeed;
                if (w <= 0) {
                    w = -w;
                }
                if (Vec3DotUnrounded(&v, &data_0217bab8.mUnk_00[0]) > 0) {
                    data_0217b8b8 = (s32) (((s64) w << 11) >> 12);
                } else {
                    data_0217b8b8 = -(s32) (((s64) w << 11) >> 12);
                }
                data_0217b908 += 0xc;
                data_0217b870 = 0xc;
            }
            w = data_0217b8b8 - (s32) (((s64) data_0217b88c * 0x29) >> 12);
            data_0217b8b8 = w;
            if (data_0217b88c * (s64) w < 0) {
                data_0217b8b8 = w - (s32) (((s64) w * 0x19a) >> 12);
            }
            data_0217b88c += data_0217b8b8;
            if (data_0217b8bc == 0) {
                data_0217b8cc += 0xcd;
                data_0217b8ec += data_0217b8cc;
            } else {
                if (data_0217b8ec <= 0) {
                    data_0217b8ec = 0;
                    data_0217b8cc = 0;
                } else {
                    data_0217b8ec -= data_0217b8cc;
                    data_0217b8cc -= 0xcd;
                }
            }
        }
        data_0217b99c = data_0217b930;
        if (data_0217b8c8->mState >= 4) {
            data_0217b8ac = 0;
        }
        if (data_0217b900 != 0 && data_0217b8ac != 0) {
            data_0217b930.x = data_0217b9c0.x;
            data_0217b930.z = data_0217b9c0.z;
            u.x = u.z = 0;
            t.y = data_0217b9c0.y - data_0217b930.y;
            t.y = t.y + data_0217b8ec;
        } else {
            data_0217b908 -= 0x29;
            if (data_0217b908 > data_021593bc.x) {
                data_0217b908 = data_021593bc.x;
            }
            if (data_0217b908 < 0x7b) {
                data_0217b908 = 0x7b;
            }
            VEC_Subtract(&data_0217b9c0, &data_0217b930, &t);
            t.y += data_0217b8ec;
            u.x = Vec3DotUnrounded(&t, &data_0217bab8.mUnk_00[0]);
            u.z = Vec3DotUnrounded(&t, &data_0217bad0);
            data_0217b924.x = (s32) (((s64) data_0217b908 * u.x) >> 12);
            data_0217b924.z +=
                (s32) (((s64) data_021593bc.z * u.z) >> 12) - (s32) (((s64) data_021593b0.z * data_0217b924.z) >> 12);
            v.x = Vec3DotUnrounded(&data_0217b9b4, &data_0217bab8.mUnk_00[0]);
            v.z = Vec3DotUnrounded(&data_0217b9b4, &data_0217bad0);
            data_0217b924.x -= v.x;
            data_0217b924.z -= v.z;
            if (data_0217b8f0 != 0 || data_0217b8bc != 0) {
                lim = data_0217b894 != 0 ? 0x1000 : 0x800;
                if (data_0217b924.x > lim) {
                    data_0217b924.x = lim;
                } else if (data_0217b924.x < -lim) {
                    data_0217b924.x = -lim;
                }
                n = data_0217b894 != 0 ? 0x2000 : 0x1000;
                if (data_0217b924.z > n) {
                    data_0217b924.z = n;
                } else if (data_0217b924.z < -n) {
                    data_0217b924.z = -n;
                }
            }
            data_0217b924.x += v.x;
            data_0217b924.z += v.z;
            MTX_MultVec33(&data_0217b924, (const s32 *) &data_0217bab8.mUnk_00[0], &u);
        }
        data_0217b924.y = data_0217b924.y + ((s32) (((s64) data_021593bc.y * t.y) >> 12) -
                                             (s32) (((s64) data_021593b0.y * data_0217b924.y) >> 12));
        u.y = data_0217b924.y;
        VEC_Add(&data_0217b930, &u, &data_0217b930);
        VEC_Subtract(&data_0217b930, &data_0217b948, &v);
        VEC_MultAdd(0xd9a, &v, &data_0217b948, &data_0217b948);
    }
    if (data_0217b8e4 == 0) {
        return;
    }
    data_0217b8f0 = (func_01ffd648(&data_0217b930, 0x12000, 0x708000, 0x5f592e1, 0x1f) & 3) == 0 ? 1 : 0;
    dx = data_0217b930.x - data_0217bab8.mUnk_00[3].x;
    dz = data_0217b930.z - data_0217bab8.mUnk_00[3].z;
    sq = (s64) dx * dx + (s64) dz * dz;
    data_0217b8bc = sq < 0x57e4000000LL ? 1 : 0;
    if (data_0217b8bc != 0) {
        data_0217b8f4 = 0;
        return;
    }
    data_0217b8f4 = sq >= 0x3d090000000LL ? 1 : 0;
}

u32 func_020e8a78(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 value12;
    u32 value14;
    value12 = (u32) &data_0217b890;
    value4 = 4u;
    value3 = (u32) &data_0217b8e4;
    value14 = 0u;
    value2 = (u32) &data_0217b8c4;
    value1 = (u32) &data_0217b900;
    value0 = (u32) &data_0217b8ac;
    *(u32 *) ((value12) + (0)) = value4;
    *(u32 *) ((value3) + (0)) = value14;
    *(u32 *) ((value2) + (0)) = value14;
    *(u32 *) ((value1) + (0)) = value14;
    *(u32 *) ((value0) + (0)) = value14;
    return value0;
}

u32 func_020e8a74(u32 p0) {
    return p0;
}

void func_020e8790(void) {
    Unk020e6514 *p;
    s32 t;

    // Stored through a pointer cast: as a plain store the compiler folds the test of data_0217b890 below,
    // which the original keeps.
    *(s32 *) &data_0217b890 = 2;
    data_0217b8e4 = 1;
    data_0217b8c4 = 0;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    data_0217b8e8 = 0;
    if (data_0217b890 != 4) {
        p = data_0217baec[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
        p = data_0217baf0[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
    }
    data_0217b9cc[0] = &data_0217bb7c;
    data_0217b9cc[1] = data_0217bb28;
    data_0217b9cc[2] = &data_0217bb34;
    data_0217b9cc[3] = &data_0217bb40;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, data_0217b9cc, 0x1ec);
    data_0217b878 = 0;
    t = (s32) (((s64) data_0217b9a8.z * data_0215f4b4[1]) >> 12) -
        (s32) (((s64) data_0217b9a8.x * data_0215f4b4[0]) >> 12);
    data_0217b8b4 = 0x8000;
    data_0217b9c0.z = t;
    if (t > 0) {
        data_0217b9c0.z = t * 3;
    }
    data_0217b9c0.x = (s32) (((s64) data_0217b9a8.z * data_0215f4b4[0]) >> 12) +
                      (s32) (((s64) data_0217b9a8.x * data_0215f4b4[1]) >> 12);
    data_0217b9c0.y = data_0217b9a8.y;
    MTX_MultVec43(&data_0217b9c0, &data_0217bab8, &data_0217b9c0);
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    data_0217b930 = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b924.x = 0;
    data_0217b870 = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b948 = data_0217b930;
    data_0217b8ec = 0;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

void func_020e84b0(void) {
    Unk020e6514 *p;
    s32 n;
    u32 a;
    s32 i;
    s32 s;
    s32 c;
    s32 t;
    u32 *q;
    s32 b;
    enum { K0 } d;

    p = data_0217baf0[data_0217b890].mUnk_00;
    d = p->mUnk_00c;
    n = data_0217b8b4;
    a = ((u32) d << 4) >> 16;
    if (n > 0 && n < 0x10000) {
        i = (n >> 4) << 1;
        s = gPairsByAngle[i];
        c = gPairsByAngle[i + 1];
        b = (s32) (((s64) data_0217b9a8.z * c) >> 12);
        t = b - (s32) (((s64) data_0217b9a8.x * s) >> 12);
        data_0217b9c0.z = t;
        if (t > 0) {
            data_0217b9c0.z = t * 3;
        }
        data_0217b9c0.x = (s32) (((s64) data_0217b9a8.z * s) >> 12) + (s32) (((s64) data_0217b9a8.x * c) >> 12);
        data_0217b9c0.y = data_0217b9a8.y;
        MTX_MultVec43(&data_0217b9c0, &data_0217bab8, &data_0217b9c0);
        if (data_0217b8f8 != 0) {
            data_0217b8b4 -= 0xf0;
        } else {
            data_0217b8b4 += 0xf0;
        }
        data_0217b908 = data_021593bc.x;
        data_0217b894 = 1;
    } else {
        data_0217b894 = 0;
        func_020ea1d4(&data_0217b9a8, &data_02159404, &data_02159410);
        if (data_0217b8f0 == 0 && data_0217b8bc == 0) {
            func_02046bcc(&data_0217b9ec, 1);
        }
    }
    if (a == 0xa || a == 0x28) {
        q = (u32 *) func_02108e6c(4);
        data_0217b9dc.mUnk_0c = func_020d4ef4(&data_0217b930);
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
        func_0210b760(&data_0217b9dc, (NNSSndSeqPlayer **) q);
    }
    if (IsKartEnded(data_0217b888) != 0 || (data_0217b8c8->mUnk_48 & 0x800) != 0) {
        func_02046bcc(&data_0217b9ec, 5);
        return;
    }
    if ((gRaceProgress->mUnk_000[data_0217b888].mFlags & 4) == 0) {
        if (++data_0217b8c4 > 0x3c) {
            func_02046bcc(&data_0217b9ec, 5);
            return;
        }
    } else {
        data_0217b8c4 = 0;
    }
    if ((data_0217b8c8->mUnk_48 & 1) == 0) {
        return;
    }
    func_02046bcc(&data_0217b9ec, 5);
}

void func_020e8418(void) {
    Vec3 v;

    if (data_0217b87c != data_0217b884) {
        data_0217bae8[0].mUnk_0c->mUnk_18 = data_0217b87c - 2;
    }
    data_0217b8b4 = 0;
    v = data_0217b978;
    v.x += data_0217b88c;
    MTX_MultVec43(&v, &data_0217bab8, &data_0217b9c0);
}

void func_020e8368(void) {
    Vec3 v;

    v = data_0217b978;
    v.x += data_0217b88c;
    MTX_MultVec43(&v, &data_0217bab8, &data_0217b9c0);
    if (++data_0217b8b4 > data_0217b880 || (data_0217b8c8->mUnk_48 & 0x800) != 0) {
        func_02046bcc(&data_0217b9ec, 5);
    }
}

void func_020e82dc(void) {
    data_0217b9cc[0] = &data_0217bb7c;
    data_0217b9cc[1] = data_0217bb28;
    data_0217b9cc[2] = &data_0217bb34;
    data_0217b9cc[3] = &data_0217bb40;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, data_0217b9cc, 0x1ec);
    data_0217b878 = 0;
    func_020ea1d4(&data_0217b990, &data_021593e0, &data_021593ec);
}

void func_020e827c(void) {
    func_020ea1d4(&data_0217b990, &data_021593e0, &data_021593ec);
    if ((data_0217b8c8->mUnk_48 & 0x800) == 0) {
        return;
    }
    func_02046bcc(&data_0217b9ec, 5);
}

void func_020e7fa8(void) {
    Unk020e6514 *p;
    u32 *q;

    data_0217b8c4 = 0;
    // Stored through a pointer cast: as a plain store the compiler folds the test of data_0217b890 below,
    // which the original keeps.
    *(s32 *) &data_0217b890 = 4;
    data_0217b8e4 = 1;
    data_0217b874 = 0x1f;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    data_0217b8e8 = 0;
    if (data_0217b890 != 4) {
        p = data_0217baec[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
        p = data_0217baf0[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
    }
    data_0217ba2c.mUnk_18 = 1;
    data_0217b8b4 = 0;
    if (func_0203c5e4() != 0) {
        q = (u32 *) func_020e6b48();
        ((MtxFx43 *) q)->mUnk_00[3] = data_0217b954;
        MTX_MultVec43(&data_0217b960, (MtxFx43 *) q, &data_0217b9c0);
    } else {
        MTX_MultVec43(&data_0217b960, &data_0217bab8, &data_0217b9c0);
    }
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    data_0217b930 = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b924.x = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    data_0217b948 = data_0217b930;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
    NNS_SndPlayerStopSeq(func_02108e6c(4), 1);
    q = (u32 *) func_02108e6c(4);
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (q[0] != 0) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
    }
    if (q[0] != 0) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
    }
    func_0212ecc0(q, 0, 0x102);
}

void func_020e7ed0(void) {
    void *p;

    if (data_0217b8b4 == 0) {
        data_0217b954 = data_0217b8c8->mPos;
    } else if (--data_0217b8b4 <= 0) {
        data_0217ba2c.mUnk_18 = 0;
        func_02046bcc(&data_0217b9ec, 5);
    }
    if (func_0203c5e4() != 0) {
        p = (void *) func_020e6b48();
        ((MtxFx43 *) p)->mUnk_00[3] = data_0217b954;
        MTX_MultVec43(&data_0217b960, (MtxFx43 *) p, &data_0217b9c0);
    } else {
        MTX_MultVec43(&data_0217b960, &data_0217bab8, &data_0217b9c0);
    }
}

void func_020e7e58(void) {
    s32 a;

    data_0217b8e4 = 1;
    MTX_MultVec43(&data_0217b9c0, &data_0217ba88, &data_0217b984);
    data_0217b89c = 0;
    a = 0;
    if ((data_0217b8c8->mUnk_48 & 1) == 0) {
        a = 0xffffbccd;
    }
    data_0217b8d8 = a;
}

void func_020e7d90(void) {
    s32 a;

    MTX_MultVec43(&data_0217b984, &data_0217bab8, &data_0217b9c0);
    if ((data_0217b8c8->mUnk_48 & 1) != 0) {
        a = 0x2000;
    } else {
        a = 0x800;
    }
    data_0217b8d8 += a;
    data_0217b89c += data_0217b8d8;
    data_0217b9c0.y += data_0217b89c;
    if (data_0217b89c <= 0x5dc000) {
        return;
    }
    if (data_0217b8f0 != 0) {
        return;
    }
    NNS_SndPlayerStopSeq(func_02108e6c(4), 1);
    func_02046bcc(&data_0217b9ec, 0);
}

void func_020e7b7c(void) {
    Unk020e6514 *p;
    s32 b;
    s32 a;
    s32 i;
    s32 t;

    data_0217b8e4 = 1;
    data_0217b8e8 = 0;
    if (data_0217b890 != 4) {
        p = data_0217baec[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
        p = data_0217baf0[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
    }
    MTX_MultVec43(&data_0217b9c0, &data_0217ba88, &data_0217b96c);
    for (i = 0, b = 0, a = 0; i < 0x1e; i++) {
        t = (b > -0x3000) ? -0x3000 : b;
        a -= t;
        b += 0x19a;
    }
    data_0217b9c0.y += a;
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b898 = a;
    data_0217b99c = data_0217b93c;
    data_0217b8d0 = b;
    data_0217b930 = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b924.x = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    data_0217b948 = data_0217b930;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

void func_020e7a84(void) {
    s32 a;
    s32 b;

    MTX_MultVec43(&data_0217b96c, &data_0217bab8, &data_0217b9c0);
    data_0217b8d0 -= 0x19a;
    a = data_0217b8d0;
    if (a > -0x3000) {
        a = -0x3000;
    }
    b = data_0217b898 + a;
    data_0217b898 = b;
    data_0217b9c0.y += b;
    if (b <= 0) {
        switch (data_0217b890) {
            case 0:
            case 1:
                func_02046bcc(&data_0217b9ec, 2);
                break;
            case 3:
                func_02046bcc(&data_0217b9ec, 3);
                break;
            default:
                func_02046bcc(&data_0217b9ec, 5);
                break;
        }
    }
    data_0217b908 = data_021593bc.x;
}
