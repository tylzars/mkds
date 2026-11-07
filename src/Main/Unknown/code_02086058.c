#include "Main/Unknown/code_02086058.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_0214a4dc.h"
#include "Main/Unknown/code_0203c598.h"
#include "Main/Unknown/code_02086e8c.h"
#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_020d50e0.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02087918.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"
#include "registers.h"

void func_02086a04(void) {
    Vec3 v24;
    Vec3 v30;
    s32 i;
    ViewFrustum *q;
    KartModelsEntry *s;
    s32 k;
    u32 e;
    Kart *p;
    BOOL g;
    s32 d;
    s32 h;
    BOOL a;
    BOOL b;
    u16 n;
    s32 j;
    q = GetViewFrustum();
    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        GetKart(i);
        data_0217aed0->mUnk_0e4[i] = 0;
        p = GetKart(i);
        k = p->mRadius * 3;
        s = p->mKartModelsEntry;
        VEC_Subtract(p->mPosSource, &q->mCameraPos, &v30);
        d = VEC_DotProduct(&v30, &q->mViewDirection);
        data_0217aed0->mUnk_104[i] = d + k;
        data_0217aed0->mUnk_074[p->mIndex] = data_0217aed0->mUnk_024[p->mIndex] + data_0217aed0->mUnk_034[p->mIndex];
        data_0217aed0->mUnk_054[data_0217aed0->mUnk_074[p->mIndex]] = d;
        VEC_Subtract(p->mPosSource, &q->mCameraPos, &v24);
        v24.x = v24.x >> 12;
        v24.y = v24.y >> 12;
        v24.z = v24.z >> 12;
        e = v24.x * v24.x + v24.y * v24.y + v24.z * v24.z;
        data_0217aed0->mUnk_124[i] = e;
        data_0217aed0->mUnk_0a4[(u16) (data_0217aed0->mUnk_024[p->mIndex] + data_0217aed0->mUnk_084[p->mIndex])] = e;
        if (p->mIndex != gRaceSetup->mEntryIndex) {
            a = TRUE;
            if (e > gSoundFalloffs[0].mUnk_20) {
                a = FALSE;
            }
            if (p->mSoundSource.mUnk_34 & 1) {
                b = TRUE;
            } else {
                b = FALSE;
            }
            if ((a != FALSE && b == FALSE) || (a == FALSE && b != FALSE)) {
                SetSoundSourceFlagBit(&p->mSoundSource, 2, 1);
            }
            if (d < 0) {
                s->mUnk_058 = s->mUnk_05c = s->mUnk_060 = TRUE;
                s->mUnk_01c->mFlags &= ~1;
                p->mUnk_4c |= 0x800000;
            } else {
                g = FALSE;
                h = k >> 12;
                if (VEC_DotProduct(&v24, &q->mUnk_20) - h > 0) {
                    g = TRUE;
                } else if (VEC_DotProduct(&v24, &q->mUnk_2c) - h > 0) {
                    g = TRUE;
                }
                if (g != FALSE) {
                    p->mUnk_4c |= 0x800000;
                } else {
                    p->mUnk_4c &= ~0x800000;
                    s->mUnk_058 = s->mUnk_05c = s->mUnk_060 = FALSE;
                    s->mUnk_01c->mFlags |= 1;
                    if (e > data_0217aed8->z) {
                        p->mUnk_4c |= 0x800000;
                        s->mUnk_058 = s->mUnk_05c = s->mUnk_060 = TRUE;
                        s->mUnk_01c->mFlags &= ~1;
                    } else if (e > data_0217aed8->y) {
                        s->mUnk_058 = s->mUnk_060 = TRUE;
                        s->mUnk_01c->mFlags &= ~1;
                    } else if (e > data_0217aed8->x) {
                        s->mUnk_060 = TRUE;
                        s->mUnk_01c->mFlags &= ~1;
                    }
                }
            }
        }
    }
    if (GetCurrentCameraKind() != 3) {
        n = 0;
        for (j = data_0217aed0->mUnk_074[gRaceSetup->mEntryIndex] + 1; j < gRaceSetup->mKartCount; j++) {
            Unk02086250 *t;
            t = data_0217aed0->mUnk_000[data_0217aed0->mUnk_044[j]];
            if (t != NULL) {
                if (n >= 2) {
                    data_0217aed0->mUnk_0e4[t->mUnk_0c] = 1;
                }
                n++;
            }
        }
    } else {
        n = 0;
        for (j = 0; j < gRaceSetup->mKartCount; j++) {
            Unk02086250 *t;
            t = data_0217aed0->mUnk_000[data_0217aed0->mUnk_044[j]];
            if (t != NULL) {
                if (data_0217aed0->mUnk_054[data_0217aed0->mUnk_074[t->mUnk_0c]] >= 0) {
                    if (n >= 2) {
                        data_0217aed0->mUnk_0e4[t->mUnk_0c] = 1;
                    }
                    n++;
                }
            }
        }
    }
}

void func_0208677c(void) {
    Vec3 v;
    s32 i;
    s32 x;
    s32 r;
    Unk02086250 *p;
    Vec3 *w;
    Kart *m;
    if (GetCurrentCameraKind() == 0) {
        data_0217aed8 = &data_02155a3c;
    } else {
        data_0217aed8 = &data_02155a48;
    }
    func_02086a04();
    i = 0;
    while (i < data_0217aed0->mUnk_020) {
        p = data_0217aed0->mUnk_0c4[i];
        m = GetKart(p->mUnk_0c);
        w = m->mPosSource;
        v = *w;
        x = data_0217aed0->mUnk_104[p->mUnk_0c];
        r = 0x1000;
        if (x > 0) {
            if (data_0217aed0->mUnk_124[p->mUnk_0c] < 0x9c400 || GetCurrentCameraKind() == 3) {
                x -= 0x14000;
                p->mUnk_20 = 1;
                p->mUnk_14 = 1;
                if (x < 0) {
                    x = 0;
                }
                r = ((s64) x * 0x44 + 0x800) >> 12;
            } else {
                p->mUnk_20 = -1;
                p->mUnk_14 = 2;
            }
        }
        if (data_0217aed0->mUnk_0e4[p->mUnk_0c] != 0 || (GetKart(p->mUnk_0c)->mUnk_7c & 0x402020) != 0 ||
            (func_020738f8(w->y - GetKart(gRaceSetup->mEntryIndex)->mPos.y) > 0x96000 && GetCurrentCameraKind() != 3)) {
            p->mUnk_20 = -1;
        }
        if (p->mUnk_18 != FALSE) {
            if (GetRaceElapsedFrames() - 0x3c > 0) {
                p->mUnk_18 = FALSE;
            }
        } else if (p->mUnk_20 != 0) {
            p->mUnk_22 = p->mUnk_22 + p->mUnk_20;
            if (p->mUnk_22 > 0x1e) {
                p->mUnk_22 = 0x1e;
                p->mUnk_20 = 0;
            } else if (p->mUnk_22 < 0) {
                p->mUnk_22 = 0;
                p->mUnk_20 = 0;
            }
        }
        if (r >= 0x1000) {
            p->mUnk_24 = p->mUnk_22;
        } else {
            p->mUnk_24 = (s32) (((s64) p->mUnk_22 * r + 0x800) >> 12);
        }
        v.y += 0xf000;
        p->mUnk_00.x = v.x >> 4;
        p->mUnk_00.y = v.y >> 4;
        p->mUnk_00.z = v.z >> 4;
        i += 1;
    }
    func_020866b4();
    func_020865ec();
}

void func_020866b4(void) {
    u16 *p;
    s16 *q;
    u16 i;
    s32 *a;
    s32 j;
    s32 x;
    s32 y;
    u16 u;
    a = data_0217aed0->mUnk_054;
    for (i = 1; (u32) i < gRaceSetup->mKartCount; i++) {
        j = i - 1;
        x = a[j];
        y = a[i];
        if (x > y) {
            p = data_0217aed0->mUnk_044;
            q = data_0217aed0->mUnk_034;
            a[j] = y;
            a[i] = x;
            q[p[i]]--;
            q[p[j]]++;
            u = p[i];
            p[i] = p[j];
            p[j] = u;
        }
    }
}

void func_020865ec(void) {
    u16 *p;
    s16 *q;
    u16 i;
    u32 *a;
    s32 j;
    u32 x;
    u32 y;
    u16 u;
    a = data_0217aed0->mUnk_0a4;
    for (i = 1; (u32) i < gRaceSetup->mKartCount; i++) {
        j = i - 1;
        x = a[j];
        y = a[i];
        if (x > y) {
            p = data_0217aed0->mUnk_094;
            q = data_0217aed0->mUnk_084;
            a[j] = y;
            a[i] = x;
            q[p[i]]--;
            q[p[j]]++;
            u = p[i];
            p[i] = p[j];
            p[j] = u;
        }
    }
}

void func_02086250(MtxFx43 *a) {
    s32 i;
    s16 h;
    s32 u;
    s32 t;
    s32 z;
    Vec3 v;
    MtxFx43 *m;
    Unk02086250 *p;
    BOOL f;
    if (GetCurrentCameraKind() != 0 && GetCurrentCameraKind() != 3) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_DIF_AMB = 0x42100000;
    reg_G3_MTX_MODE = 0;
    G3_LoadMtx44(&data_0217aee0);
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    for (i = gRaceSetup->mKartCount - 1; i >= 0; i--) {
        p = data_0217aed0->mUnk_000[data_0217aed0->mUnk_044[i]];
        if (p == NULL) {
            continue;
        }
        if (data_0217aed0->mUnk_054[i] <= 0) {
            continue;
        }
        h = p->mUnk_24;
        if (h == 0) {
            continue;
        }
        if ((GetKart(data_0217aed0->mUnk_044[i])->mUnk_7c & 0xe0) != 0) {
            continue;
        }
        MTX_MultVec43(&p->mUnk_00, a, &v);
        if (v.z >= 0) {
            f = FALSE;
        } else {
            m = GetProjectionMatrix();
            t = ((s64) v.x * m->mUnk_00[0].x + (s64) v.z * m->mUnk_00[2].z) >> 12;
            u = ((s64) v.y * m->mUnk_00[1].z + (s64) v.z * m->mUnk_00[3].x) >> 12;
            z = -((const Vec3 *) &v)->z;
            t = FX_Div(t, z);
            u = FX_Div(u, z);
            t = (((s64) t << 19) + 0x800) >> 12;
            u = ((s64) u * 0x60000 + 0x800) >> 12;
            f = TRUE;
        }
        if (f == FALSE) {
            continue;
        }
        if (p->mUnk_1c->mUnk_00[3].mUnk_0c != NULL) {
            func_02086098(&p->mUnk_1c->mUnk_00[3], p, a, data_021659a8, data_021659a0, h, t, u, data_021659bc,
                          data_021659b0, func_02087ab0);
        }
        func_02086098(&p->mUnk_1c->mUnk_00[2], p, a, data_021659cc, 0x9000, h, t, u, data_021659d0, 0, func_0208784c);
        func_02086098(&p->mUnk_1c->mUnk_00[1], p, a, 0x21000, 0xa000, h, t, u, data_021659a4, 0x199a, func_02087ab0);
        func_02086098(&p->mUnk_1c->mUnk_00[0], p, a, data_021659c8, data_021659c4, h, t, u, data_021659ac,
                      data_021659b8, func_02087918);
    }
}

static inline s32 func_02086098_inline(Unk02086250 *b) {
    return (b->mUnk_0c + 11) << 24;
}

void func_02086098(Unk02086098 *a, Unk02086250 *b, MtxFx43 *c, s32 d, s32 e, s16 f, s32 g, s32 h, s32 i, s32 j,
                   UnkFunc *k) {
    MtxFx43 m;
    s32 x;
    s32 y;
    s32 z;
    reg_G3_TEXIMAGE_PARAM = a->mUnk_00;
    if (a->mUnk_08 != 0) {
        reg_G3_PLTT_BASE = a->mUnk_18 >> (4 - ((a->mUnk_00 >> 26 & 7) == 2));
    }
    MTX_Identity43_(&m);
    m.mUnk_00[3] = b->mUnk_00;
    MTX_Concat43(&m, c, &m);
    m.mUnk_00[3].x = g;
    if (b->mUnk_10 == TRUE) {
        m.mUnk_00[3].x = g + ((s32) (((s64) i * d + 0x800) >> 12) + 0x1e000);
    }
    m.mUnk_00[3].y = 0x5000 + h + (s32) (((s64) j * e + 0x800) >> 12);
    m.mUnk_00[3].z = 0;
    x = a->mUnk_1c;
    y = a->mUnk_20;
    m.mUnk_00[1].y = e;
    m.mUnk_00[0].x = d;
    m.mUnk_00[0].y = 0;
    m.mUnk_00[0].z = 0;
    m.mUnk_00[1].x = 0;
    m.mUnk_00[1].z = 0;
    m.mUnk_00[2].z = 0;
    m.mUnk_00[2].y = 0;
    m.mUnk_00[2].x = 0;
    reg_G3_POLYGON_ATTR = (func_02086098_inline(b) | 0xc0) | (f << 16);
    reg_G3_MTX_MODE = 2;
    G3_LoadMtx43(&m);
    reg_G3_BEGIN_VTXS = 1;
    reg_G3_COLOR = 0x7fff;
    k(x, y, b->mUnk_26);
    reg_G3_END_VTXS = 0;
}

int func_02086080(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217aed0;
    value1 = *(const u32 *) ((value1) + (0));
    value0 = (value1) + ((value0 << 2));
    value0 = *(const u32 *) ((value0) + (292));
    return value0;
}

u16 func_0208606c(int a) {
    return data_02155a64[a];
}

u16 *func_02086058(void) {
    return data_0217aed0->mUnk_094;
}
