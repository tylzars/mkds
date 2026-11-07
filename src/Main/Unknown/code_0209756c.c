#include "Main/Unknown/code_0209756c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_020109c4.h"
#include "code_020184e4.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

void InitFlipper(Flipper *p) {
    p->mUnk_00.mFlags = p->mUnk_00.mFlags | data_usa_0215658c;
    func_020d2450(p);
}

u32 func_020980ec(Flipper *p, Kart *q, void *b, u8 *c) {
    u32 v;
    BOOL t;
    s32 f;
    Vec3 w;
    s32 s;
    Vec3 *e;

    v = *c;
    t = (p->mState == 2 || p->mState == 5) && p->mUnk_a0 > 0;
    if (t) {
        s = -0x19a;
    } else if ((p->mState == 3 || p->mState == 6) && p->mUnk_a0 < 0) {
        s = 0x19a;
    } else {
        s = 0;
    }
    if (s != 0) {
        if (p->mUnk_ed4[q->mIndex] != 0) {
            p->mUnk_00.mUnk_10.x = 0;
            p->mUnk_00.mUnk_10.y = 0;
            p->mUnk_00.mUnk_10.z = 0;
        } else {
            VEC_Subtract(&q->mPos, &p->mUnk_00.mPos, &w);
            f = VEC_Mag(&w);
            e = &p->mUnk_a8[p->mUnk_ec0].mUnk_00[2];
            f = ((s64) f * s) >> 12;
            p->mUnk_00.mUnk_10.x = ((s64) e->x * f) >> 12;
            p->mUnk_00.mUnk_10.y = ((s64) e->y * f) >> 12;
            p->mUnk_00.mUnk_10.z = ((s64) e->z * f) >> 12;
            p->mUnk_00.mDistanceSquaredAndFlags = p->mUnk_00.mDistanceSquaredAndFlags | data_usa_02156588;
            func_020d26ec(q, 0x1d1);
        }
        if (p->mUnk_ec8 != 0) {
            return 0xe;
        }
        return 0xc;
    }
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
    return v;
}

u32 func_02097ed0(Flipper *p, Vec3 *a, s32 b, Vec3 *c) {
    s32 r;

    p->mUnk_a0 = 0;
    if (func_020eafc4(a, &p->mUnk_00.mPos, &p->mUnk_a8[p->mUnk_ec0].mUnk_00[0], &data_usa_0215650c[p->mUnk_a4],
                      &data_usa_0215653c[p->mUnk_a4], b, NULL) != 0) {
        r = func_020eafc4(a, &p->mUnk_00.mPos, &p->mUnk_a8[p->mUnk_ec0].mUnk_00[0], &data_usa_02156554[p->mUnk_a4],
                          &data_usa_021564dc[p->mUnk_a4], b, c);
        if (r == 4 || p->mState == 2) {
            p->mUnk_a0 = 1;
        } else if (p->mState == 3) {
            p->mUnk_a0 = -1;
        }
    } else {
        if (func_020eafc4(a, &p->mUnk_00.mPos, &p->mUnk_a8[p->mUnk_ec0].mUnk_00[0], &data_usa_021564c4[p->mUnk_a4],
                          &data_usa_02156524[p->mUnk_a4], b, NULL) != 0) {
            r = func_020eafc4(a, &p->mUnk_00.mPos, &p->mUnk_648[p->mUnk_ec0].mUnk_00[0], &data_usa_0215656c[p->mUnk_a4],
                              &data_usa_021564f4[p->mUnk_a4], b, c);
            if (r == 4 || p->mState == 3) {
                p->mUnk_a0 = -1;
            } else if (p->mState == 2) {
                p->mUnk_a0 = 1;
            }
        } else {
            r = func_020ead80(a, &p->mUnk_00.mPos, &p->mUnk_a8[p->mUnk_ec0].mUnk_00[0], 0x32000, 0x3c000, 0, b, c);
        }
    }
    return r != 0;
}

void CreateFlipper(void *a) {
    gFlipper = CreateMapObjectModelAnimated(a, gFlipperNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gFlipper, gFlipperNsbtpName);
    CreateMapObjectModelNsbtaAnimation(gFlipper, gFlipperNsbtaName);
}

void DrawFlipper(void *a, Flipper *p) {
    s32 v;
    MtxFx43 *e;
    Unk02087d0c *s;

    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    e = &p->mUnk_a8[p->mUnk_ec0];
    e->mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    e->mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    e->mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, e, 0xc);
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    SetMapObjectModelMirror(gFlipper, p->mUnk_a4, 0);
    s = gFlipper->mAnimations[1];
    s->mUnk_0c = p->mUnk_ec4 << 12;
    s->mUnk_1c[s->mUnk_1a]->mFrame = s->mUnk_0c;
    s = gFlipper->mAnimations[3];
    s->mUnk_0c = p->mUnk_ec6 << 12;
    s->mUnk_1c[s->mUnk_1a]->mFrame = s->mUnk_0c;
    DrawMapObjectModel(a, gFlipper, p);
}

void InitFlipperObjects(MapObjectList *a) {
    s32 i;
    s32 j;
    s32 v1;
    s32 d;
    s32 k;
    u32 e;
    Flipper *p;
    MtxFx43 *q;
    s32 m2[9];
    s32 m1[9];

    if (a == NULL) {
        return;
    }
    v1 = data_usa_0215653c[0].x;
    for (i = 0; i < a->mMapObjectCount && (p = a->mMapObjects[i]) != NULL; i++) {
        switch (p->mUnk_00.mCourseMapRow->mUnk_28) {
            case 0:
                p->mUnk_a4 = 0;
                p->mUnk_00.mFlags &= ~0x400;
                p->mUnk_00.mAngle = 0x2000;
                p->mUnk_eb8 = 0x1e;
                MTX_RotY33_(m2, data_usa_02160fb4[0x74], data_usa_02160fb4[0x75]);
                break;
            case 1:
                p->mUnk_a4 = 1;
                p->mUnk_00.mFlags |= data_usa_02156584;
                p->mUnk_00.mAngle = 0x2000;
                p->mUnk_eb8 = 0x1e;
                MTX_RotY33_(m2, data_usa_0215d8b4[10], data_usa_0215d8b4[11]);
                break;
        }
        p->mUnk_ec8 = 0;
        if (p->mUnk_a4 == 0) {
            e = p->mUnk_00.mAngle;
        } else {
            e = -p->mUnk_00.mAngle;
        }
        for (j = 0; j < 30; j++) {
            if (p->mUnk_a4 == 0) {
                d = 0x16c;
            } else {
                d = -0x16c;
            }
            e = e - d;
            k = (u16) e >> 4;
            MTX_RotY33_(m1, gPairsByAngle[k * 2], gPairsByAngle[k * 2 + 1]);
            q = &p->mUnk_a8[j];
            MTX_Concat33(m1, &p->mUnk_00.mMatrix.mUnk_00[0].x, &q->mUnk_00[0].x);
            MTX_Concat33(m2, &q->mUnk_00[0].x, &p->mUnk_648[j].mUnk_00[0].x);
            p->mUnk_be8[j].x = p->mUnk_00.mPos.x >> 4;
            p->mUnk_be8[j].y = p->mUnk_00.mPos.y >> 4;
            p->mUnk_be8[j].z = p->mUnk_00.mPos.z >> 4;
            if (p->mUnk_a4 == 0) {
                k = (u16) (-e + FX_Atan2Idx(-2, -10)) >> 4;
                p->mUnk_d50[j].x = (p->mUnk_00.mPos.x + (s32) (((s64) v1 * gPairsByAngle[k * 2 + 1]) >> 12)) >> 4;
                p->mUnk_d50[j].y = p->mUnk_00.mPos.y >> 4;
                p->mUnk_d50[j].z = (p->mUnk_00.mPos.z + (s32) (((s64) v1 * gPairsByAngle[k * 2]) >> 12)) >> 4;
            } else {
                k = (u16) (-e - FX_Atan2Idx(-2, -10)) >> 4;
                p->mUnk_d50[j].x = (p->mUnk_00.mPos.x - (s32) (((s64) v1 * gPairsByAngle[k * 2 + 1]) >> 12)) >> 4;
                p->mUnk_d50[j].y = p->mUnk_00.mPos.y >> 4;
                p->mUnk_d50[j].z = (p->mUnk_00.mPos.z - (s32) (((s64) v1 * gPairsByAngle[k * 2]) >> 12)) >> 4;
            }
        }
    }
}

void UpdateFlipper(void *a, Flipper *p) {
    s32 i;
    s32 n;
    Unk020f41c4_B *v1;
    u32 r;
    s32 w;

    p->mUnk_ebc = p->mUnk_ebc - (p->mUnk_ebc > 0);
    switch (p->mState) {
        case 0:
            p->mUnk_ed0 = StartEffect(0x5f, &p->mUnk_00.mPos);
            p->mState = 1;
            break;
        case 1:
            if (p->mUnk_ebc != 0) {
                p->mState = 4;
            } else {
                p->mUnk_eb8 = p->mUnk_eb8 - 1;
                if (p->mUnk_eb8 <= 0) {
                    p->mUnk_ec0 = 0;
                    p->mState = 2;
                }
            }
            p->mUnk_ec8 = 0;
            break;
        case 2:
            p->mUnk_00.mAngle -= 0x16c;
            p->mUnk_ec0 = p->mUnk_ec0 + 1;
            if (p->mUnk_ec0 >= 0x1d) {
                p->mUnk_ec0 = 0x1d;
                p->mState = 3;
            }
            p->mUnk_ec8 = 1;
            break;
        case 3:
            p->mUnk_00.mAngle += 0x16c;
            if (p->mUnk_ec0 >= 0xf) {
                p->mUnk_ec8 = 1;
            } else {
                p->mUnk_ec8 = 0;
            }
            p->mUnk_ec0 = p->mUnk_ec0 - 1;
            if (p->mUnk_ec0 <= 0) {
                p->mUnk_ec0 = 0;
                v1 = func_020d22d0();
                v1->mUnk_00 = (s64) v1->mUnk_08 * (s64) v1->mUnk_00 + v1->mUnk_10;
                r = ((u64) (u32) (v1->mUnk_00 >> 32) * 12) >> 32;
                p->mUnk_eb8 = (u16) ((u16) r * 0x14);
                p->mState = 1;
            }
            break;
        case 4:
            if (p->mUnk_ebc <= 0) {
                p->mUnk_ec0 = 0;
                p->mState = 5;
            }
            p->mUnk_ec8 = 0;
            break;
        case 5:
            p->mUnk_00.mAngle -= 0x2d8;
            p->mUnk_ec0 = p->mUnk_ec0 + 2;
            if (p->mUnk_ec0 >= 0x1c) {
                p->mUnk_ec0 = 0x1c;
                p->mState = 6;
            }
            p->mUnk_ec8 = 1;
            break;
        case 6:
            p->mUnk_00.mAngle += 0x2d8;
            if (p->mUnk_ec0 >= 0xf) {
                p->mUnk_ec8 = 1;
            } else {
                p->mUnk_ec8 = 0;
            }
            p->mUnk_ec0 = p->mUnk_ec0 - 2;
            if (p->mUnk_ec0 <= 0) {
                p->mUnk_ec0 = 0;
                v1 = func_020d22d0();
                v1->mUnk_00 = (s64) v1->mUnk_08 * (s64) v1->mUnk_00 + v1->mUnk_10;
                r = ((u64) (u32) (v1->mUnk_00 >> 32) * 12) >> 32;
                p->mUnk_eb8 = (u16) ((u16) r * 0x14);
                p->mState = 1;
            }
            break;
    }
    if (p->mUnk_ec8 != 0 && (p->mUnk_00.mFlags & 0x12) == 0) {
        w = p->mUnk_ec4 + 1;
        if (w >= GetMapObjectModelNsbtpFrameCount(gFlipper)) {
            w = 1;
        }
        p->mUnk_ec4 = w;
        w = p->mUnk_ec6 + 1;
        if (w >= GetMapObjectModelNsbtaFrameCount(gFlipper)) {
            w = 1;
        }
        p->mUnk_ec6 = w;
        p->mUnk_ed0->mUnk_24.mUnk_00_1 = 0;
        SPLUtil_SetCylinderEmitterDir(p->mUnk_ed0, &p->mUnk_be8[p->mUnk_ec0], &p->mUnk_d50[p->mUnk_ec0]);
    } else {
        p->mUnk_ec4 = 0;
        p->mUnk_ec6 = 0;
        p->mUnk_ed0->mUnk_24.mUnk_00_1 = 1;
    }
    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        if (p->mUnk_ed4[i] > 0) {
            p->mUnk_ed4[i] = p->mUnk_ed4[i] - 1;
        }
    }
}

void CreateFlipperKindData(void) {
    func_0209bf70(func_020980ec, NULL, func_02097ed0, 0, 1, 0x1d0);
}

void *CreateFlipperDrawList(void) {
    return CreateMapObjectDrawList1(CreateFlipper, DrawFlipper, NULL);
}

void *CreateFlipperUpdateList(void) {
    return CreateMapObjectUpdateList(InitFlipperObjects, UpdateFlipper, NULL);
}
