#include "Main/Unknown/code_0209df00.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
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
#include "Main/Unknown/code_02077bc0.h"

void *CreatePuddleDrawList(void) {
    return CreateMapObjectDrawList2(CreatePuddle, DrawPuddle, SetupDrawPuddle);
}

void InitFireball2(Fireball2 *a) {
    a->mUnk_00.mFlags |= data_usa_021565ec;
    a->mUnk_a0 = a->mUnk_00.mCourseMapRow->mUnk_28;
    a->mUnk_a2 = a->mUnk_00.mCourseMapRow->mUnk_2e + 1;
    CreateMapObjectSoundSourceFalloff2(&a->mUnk_00);
    a->mUnk_00.mFlags &= ~1;
    a->mUnk_00.mFlags &= ~2;
    a->mUnk_00.mFlags &= ~8;
    a->mUnk_00.mAlpha = 0x1f;
}

u8 CollideKartWithFireball2(Fireball2 *a, Kart *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mUnk_19c4[b->mIndex] == 0) {
        if (b->mItemEffect == 1 || b->mItemEffect == 3) {
            a->mUnk_00.mDistanceSquaredAndFlags |= data_usa_021565e8;
        }
        StartSoundIfKartStarOrKiller(&a->mUnk_00, b);
    }
    a->mUnk_19c4[b->mIndex] = 0xb;
    return v;
}

static inline BOOL func_0209df84_inline(Kart *p, Fireball2 *b, s32 t) {
    s32 y;
    s32 x;
    s32 z;
    s32 u;

    u = -t;
    z = p->mPos.z - b->mUnk_00.mPos.z;
    if (z > t || z < u) {
        return FALSE;
    }
    x = p->mPos.x - b->mUnk_00.mPos.x;
    if (x > t || x < u) {
        return FALSE;
    }
    y = p->mPos.y - b->mUnk_00.mPos.y;
    if (y > t || y < u) {
        return FALSE;
    }
    return (s64) x * x + (s64) y * y + (s64) z * z < (s64) t * t;
}

BOOL IsPosNearFireball2(Fireball2 *a, Vec3 *b, s32 c) {
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

void CreateFireball2(Unk0209e950 *a) {
    gFireball2 = CreateMapObjectModelNsbmd(a, gFireball2NsbmdName);
    SetMapObjectModelPolygonId(gFireball2, 0x3f);
    a->mUnk_1c = 1;
}

void SetupDrawFireball2(void *a) {
    func_0209bbd0(a, gFireball2);
}

void DrawFireball2(void *a, Fireball2 *b) {
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
    Camera *q;

    q = GetCurrentCamera();
    c = Vec3DotUnrounded(&b->mUnk_00.mMatrix.mUnk_00[0], &q->mForward);
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
                func_01ff9048(0x19, SetViewTransposeMatrixPos(&b->mUnk_c4[i][j].mUnk_00), 0xc);
                if (b->mUnk_c4[i][j].mUnk_0e != 0) {
                    MTX_RotZ33_(m1, gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2],
                                gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2 + 1]);
                    func_01ff9048(0x1a, m1, 9);
                }
                func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
                SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
                DrawMapObjectModel(a, gFireball2, b);
            }
        }
    }
    if (b->mUnk_a2 > 1) {
        s2 = 0x1e;
        func_01ff9048(0x14, &s2, 1);
        func_01ff9048(0x19, SetViewTransposeMatrixPos(&b->mUnk_b4), 0xc);
        if (b->mUnk_c2 != 0) {
            MTX_RotZ33_(m2, gPairsByAngle[(b->mUnk_c2 >> 4) * 2], gPairsByAngle[(b->mUnk_c2 >> 4) * 2 + 1]);
            func_01ff9048(0x1a, m2, 9);
        }
        func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
        SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
        DrawMapObjectModel(a, gFireball2, b);
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
                func_01ff9048(0x19, SetViewTransposeMatrixPos(&b->mUnk_c4[i][j].mUnk_00), 0xc);
                if (b->mUnk_c4[i][j].mUnk_0e != 0) {
                    MTX_RotZ33_(m3, gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2],
                                gPairsByAngle[(b->mUnk_c4[i][j].mUnk_0e >> 4) * 2 + 1]);
                    func_01ff9048(0x1a, m3, 9);
                }
                func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
                SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
                DrawMapObjectModel(a, gFireball2, b);
            }
        }
    }
}

void InitFireball2Objects(MapObjectList *p) {
    s32 i;
    s32 j;
    s32 k;
    s16 v;
    float f;
    u64 t;
    Fireball2 *e;
    Unk020f41c4_B *r;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mMapObjectCount && (e = p->mMapObjects[i]) != NULL; i++) {
        v = e->mUnk_00.mCourseMapRow->mUnk_2a;
        if (v > 0) {
            f = 0.5f + (v << 12);
        } else {
            f = (v << 12) - 0.5f;
        }
        e->mUnk_ac = f;
        e->mUnk_b0 = (e->mUnk_00.mCourseMapRow->mUnk_2c * 0x16c) / 100;
        e->mUnk_a4 = 0x10000 / e->mUnk_a0;
        e->mUnk_a8 = e->mUnk_ac / e->mUnk_a2;
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        t = r->mUnk_00 >> 32;
        e->mUnk_c2 = (t * 0x10000) >> 32;
        for (j = 0; j < e->mUnk_a2; j++) {
            for (k = 0; k < e->mUnk_a0; k++) {
                r = func_020d22d0();
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                t = r->mUnk_00 >> 32;
                e->mUnk_c4[k][j].mUnk_0e = (t * 0x10000) >> 32;
            }
        }
    }
}

void UpdateFireball2(void *a, Fireball2 *b) {
    s32 i;
    s32 j;
    s32 n;
    s32 d;
    u16 w;
    Kart *p;
    NNSSndSeqPlayer **h;
    Vec3 v;

    n = b->mUnk_ac;
    b->mUnk_b4 = b->mUnk_00.mPos;
    if (b->mUnk_a2 == 1) {
        p = GetKart((u16) gRaceSetup->mEntryIndex);
        if (func_0209df84_inline(p, b, n - 0xf000) != FALSE) {
            VEC_Subtract(&p->mPos, &b->mUnk_00.mPos, &v);
            d = Vec3DotUnrounded(&v, &b->mUnk_00.mMatrix.mUnk_00[2]);
            if ((b->mUnk_19e4 < 0 && d > 0) || (b->mUnk_19e4 > 0 && d < 0)) {
                func_02108e38();
                h = GetSndHandleSlot(7);
                if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
                    if (h[0] != NULL) {
                        NNS_SndPlayerStopSeq(h, 0);
                    }
                    if (h[0] != NULL) {
                        NNS_SndPlayerStopSeq(h, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(h, 0, 0x1c2);
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
            VEC_MultAdd(((s64) n * gPairsByAngle[(w >> 4) * 2 + 1]) >> 12, &b->mUnk_00.mMatrix.mUnk_00[0],
                        &b->mUnk_00.mPos, &b->mUnk_c4[j][i].mUnk_00);
            VEC_MultAdd(((s64) n * gPairsByAngle[(w >> 4) * 2]) >> 12, &b->mUnk_00.mMatrix.mUnk_00[1],
                        &b->mUnk_c4[j][i].mUnk_00, &b->mUnk_c4[j][i].mUnk_00);
            b->mUnk_c4[j][i].mUnk_0e = b->mUnk_c4[j][i].mUnk_0e + 0x51e;
        }
        n = n - b->mUnk_a8;
    }
    b->mUnk_b2 = b->mUnk_b2 - b->mUnk_b0;
    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (b->mUnk_19c4[i] > 0) {
            b->mUnk_19c4[i] = b->mUnk_19c4[i] - 1;
        }
    }
    StartMapObjectSoundWhileRequested(&b->mUnk_00, 0x160);
}

void CreateFireball2KindData(void) {
    func_0209bf70(CollideKartWithFireball2, NULL, IsPosNearFireball2, 0, 0, 0x18d);
}

void *CreateFireball2DrawList(void) {
    return CreateMapObjectDrawList2(CreateFireball2, DrawFireball2, SetupDrawFireball2);
}

void *CreateFireball2UpdateList(void) {
    return CreateMapObjectUpdateList(InitFireball2Objects, UpdateFireball2, NULL);
}
