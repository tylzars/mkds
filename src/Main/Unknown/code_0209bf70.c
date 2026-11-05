#include "Main/Unknown/code_0209bf70.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209d5e8.h"
#include "Main/Unknown/code_0209d5ec.h"
#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_0209d650.h"
#include "Main/Unknown/code_02077bc0.h"

void InitSun(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value1 = (u32) * (const u32 *) ((value4) + (156));
    value0 = (value4) + (0xb8u);
    value2 = 0u;
    func_020d7da8((Unk020e0144 *) value0, (CourseMapRow *) value1, (s32) value2);
    value0 = 0x1aeu;
    value2 = value4;
    value1 = 0x1eu;
    CreateParkedMapObjects(value0, value1, (void *) value2);
    value0 = 0u;
    *(u32 *) ((value4) + (16)) = value0;
    *(u32 *) ((value4) + (20)) = value0;
    *(u32 *) ((value4) + (24)) = value0;
}

void CreateSunAndSunLOD(void *a) {
    gSun = CreateMapObjectModelAnimated(a, gSunNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gSun, gSunNsbcaName);
    gSunLOD = CreateMapObjectModelAnimated(a, gSunLODNsbmdName);
    SetMapObjectModelPolygonId(gSun, func_020d3c2c());
}

u32 func_0209d5e8(u32 p0) {
    return p0;
}

void DrawSun(void *a, Unk0209d3fc *b) {
    s32 s;
    s32 t;
    s32 k;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mPos), 0xc);
    if (b->mUnk_dc == 3 || b->mUnk_dc == 4) {
        t = (s32) (((s64) gPairsByAngle[((u16) b->mUnk_ac >> 4) * 2 + 1] * -0x14000) >> 12) + 0x14000;
        k = (b->mUnk_b0 >> 4) * 2;
        v.x = (s32) (((s64) t * gPairsByAngle[k + 1]) >> 12) >> 4;
        v.y = (s32) (((s64) t * gPairsByAngle[k]) >> 12) >> 4;
        v.z = 0;
        func_01ff9048(0x1c, &v, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    if (func_02061818() == 2) {
        func_0209bbd0(a, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, b->mUnk_b2);
        DrawMapObjectModel(a, gSun, b);
    } else if ((s32) (b->mUnk_00.mUnk_78 & 0x3fffffe0) < 0x3d0900) {
        func_0209bbd0(a, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, b->mUnk_b2);
        DrawMapObjectModel(a, gSun, b);
    } else {
        func_0209bbd0(a, gSunLOD);
        func_0209ba58(a, gSunLOD, b);
    }
}

static inline u32 func_0209c9fc_inline(Unk020f41c4_B *b) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (b->mUnk_00 >> 32);
}

void func_0209d394(Unk02100094 *a) {
    s32 i;
    Unk0209cf34 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (data_021759c0->mMode == 1) {
            p->mUnk_0a8 = (u16) p->mUnk_000.mCourseMapRow->mUnk_28;
        } else if (data_021759c0->mMode == 5) {
            p->mUnk_0a8 = (u16) p->mUnk_000.mCourseMapRow->mUnk_2a;
        }
    }
}

static inline BOOL func_0209cf34_inline(void) {
    s32 i;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        if ((s32) func_0203c8c0((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL func_0209cf34_inline_b(Unk0209cf34 *p) {
    s32 i;
    Kart *k;
    Vec3 *q;
    s32 x;
    s32 z;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        k = GetKart((u16) i);
        q = &k->mPos;
        x = q->x - p->mUnk_000.mPos.x;
        z = q->z - p->mUnk_000.mPos.z;
        if ((s64) x * x + (s64) z * z < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateSun(Unk02100094 *a, Unk0209cf34 *p) {
    Vec3 v;
    Vec3 w;
    s32 t;
    s32 k;

    switch (p->mUnk_0dc) {
        case 0:
            if (p->mUnk_000.mFlags & 0x800) {
                if (p->mUnk_0a8-- <= 0) {
                    p->mUnk_0dc = 1;
                }
            } else if (func_0209cf34_inline()) {
                p->mUnk_0dc = 1;
            }
            break;
        case 1:
            p->mUnk_0b8.mUnk_04 = 0x3c000;
            p->mUnk_0b8.mUnk_10 = ((s64) p->mUnk_0b8.mUnk_00->mUnk_00[p->mUnk_0b8.mUnk_0c].mUnk_34 * 0x3c000) >> 12;
            if (func_020d8cc8(&p->mUnk_0b8) != FALSE && (t = p->mUnk_0b8.mUnk_1c->mUnk_0e) != 0) {
                if (p->mUnk_000.mFlags & 0x800) {
                    k = data_021759c0->mMode;
                    if (k == 1) {
                        p->mUnk_0a8 = t;
                    } else if (k == 5) {
                        p->mUnk_0a8 = p->mUnk_0b8.mUnk_1c->mUnk_10;
                    }
                }
                p->mUnk_0dc = 2;
            }
            func_020d8a5c(&p->mUnk_0b8, &p->mUnk_000.mPos);
            break;
        case 2:
            if (p->mUnk_000.mFlags & 0x800) {
                if (p->mUnk_0a8-- <= 0) {
                    p->mUnk_0b0 = 0;
                    p->mUnk_0ac = p->mUnk_0b0;
                    p->mUnk_0a8 = 5;
                    p->mUnk_0dc = 3;
                }
            } else if (func_0209cf34_inline_b(p)) {
                p->mUnk_0b0 = 0;
                p->mUnk_0ac = p->mUnk_0b0;
                p->mUnk_0a8 = 5;
                p->mUnk_0dc = 3;
            }
            break;
        case 3:
            p->mUnk_0b0 += 0xe39;
            if (p->mUnk_0ac < 0x8000) {
                p->mUnk_0ac += 0x222;
            }
            if (p->mUnk_0a8-- > 0) {
                break;
            }
            if (p->mUnk_0a0 == 0) {
                p->mUnk_0a4 = (u16) (((u64) func_0209c9fc_inline(func_020d22d0()) * 0x10000) >> 32);
            } else {
                p->mUnk_0a4 += 0x8000;
            }
            v.x = p->mUnk_000.mPos.x;
            v.y = p->mUnk_000.mPos.y - 0x1e000;
            v.z = p->mUnk_000.mPos.z;
            w.x = gPairsByAngle[(p->mUnk_0a4 >> 4) * 2];
            w.y = 0;
            w.z = gPairsByAngle[(p->mUnk_0a4 >> 4) * 2 + 1];
            func_0209d694(&v, &w);
            p->mUnk_0a0 += 1;
            if (p->mUnk_0a0 >= 2) {
                p->mUnk_0a0 = 0;
                p->mUnk_0dc = 4;
            } else {
                p->mUnk_0a8 = 0x1e;
            }
            break;
        case 4:
            p->mUnk_0b0 += 0xe39;
            p->mUnk_0ac += 0x222;
            if (p->mUnk_0ac > 0x10000) {
                p->mUnk_0a8 = 0x1e;
                p->mUnk_0dc = 0;
            }
            break;
    }
    if ((s32) (p->mUnk_000.mUnk_78 & ~0xc000001f) >= 0x3d0900) {
        return;
    }
    if (p->mUnk_0dc == 3) {
        t = p->mUnk_0b4 + 0x19a;
        if (t >= 0x8000) {
            t = 0x8000;
        }
        p->mUnk_0b4 = t;
    } else {
        t = p->mUnk_0b4 - 0x19a;
        if (t <= 0x1000) {
            t = 0x1000;
        }
        p->mUnk_0b4 = t;
    }
    p->mUnk_0b2 += p->mUnk_0b4 >> 12;
    if (p->mUnk_0b2 >= GetMapObjectModelNsbcaFrameCount(gSun)) {
        p->mUnk_0b2 = 0;
    }
}

void func_0209cf10(void) {
    func_0209bf1c(CreateSunAndSunLOD, DrawSun, func_0209d5e8);
}

void func_0209cef0(void) {
    func_0209bf48(func_0209d394, UpdateSun, NULL);
}

void func_0209cebc(Unk0209c220 *p) {
    p->mUnk_000.mFlags |= data_usa_021565d4;
    func_020d2450(p);
    p->mUnk_0b4 = p->mUnk_000.mScale.x;
}

s32 func_0209c9fc(Unk0209c220 *p, Kart *k, u8 *b, u8 *c) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 *q;
    u8 d;
    s32 t;
    u32 e;

    e = *b;
    d = *c;
    if (e == 3 || e == 4) {
        if (p->mUnk_120[k->mIndex] == 0) {
            Vec3Sub(&k->mPos, &p->mUnk_000.mPos, &v2);
            t = Vec3Dot(&k->mVelocityDirection, &v2);
            v0.x = ((s64) k->mVelocityDirection.x * t) >> 12;
            v0.y = ((s64) k->mVelocityDirection.y * t) >> 12;
            v0.z = ((s64) k->mVelocityDirection.z * t) >> 12;
            v1.x = v2.x - v0.x;
            v1.y = v2.y - v0.y;
            v1.z = v2.z - v0.z;
            t = Vec3Dot(&p->mUnk_000.mMatrix.mUnk_00[1], &v1);
            v0.x = ((s64) p->mUnk_000.mMatrix.mUnk_00[1].x * t) >> 12;
            v0.y = ((s64) p->mUnk_000.mMatrix.mUnk_00[1].y * t) >> 12;
            v0.z = ((s64) p->mUnk_000.mMatrix.mUnk_00[1].z * t) >> 12;
            v1.x -= v0.x;
            v1.y -= v0.y;
            v1.z -= v0.z;
            if ((s64) v1.x * v1.x + (s64) v1.y * v1.y + (s64) v1.z * v1.z < 0x10) {
                q = &k->mUnk_120;
                p->mUnk_000.mUnk_10.x = ((s64) k->mUnk_120.x * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.y = ((s64) q->y * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.z = ((s64) q->z * 0xc000) >> 12;
            } else {
                func_02039860(&v1, &v1);
                p->mUnk_000.mUnk_10.x = ((s64) v1.x * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.y = ((s64) v1.y * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.z = ((s64) v1.z * 0xc000) >> 12;
            }
            Vec3Sub(&v0, &p->mUnk_000.mMatrix.mUnk_00[1], &v0);
            Vec3AddScaled(0x19a, &v0, &p->mUnk_000.mUnk_10, &p->mUnk_000.mUnk_10);
            p->mUnk_120[k->mIndex] = 0x1f;
            if (data_021759c0->mMode == 2) {
                func_020a21bc(k->mIndex, (s32) &p->mUnk_000.mUnk_10);
            }
        } else {
            p->mUnk_000.mUnk_10.x = 0;
            p->mUnk_000.mUnk_10.y = 0;
            p->mUnk_000.mUnk_10.z = 0;
        }
        if (data_021759c0->mCurrentEntries[k->mIndex].mPlayer.mKind != 2 && p->mUnk_11c == FALSE) {
            p->mUnk_0b8 = 0x8000;
            p->mUnk_0c4 = 0x1000;
            p->mUnk_0c8 = 0x400;
            p->mUnk_0cc = -0x29;
            p->mUnk_0d0 = 0x1000;
            p->mUnk_0d4 = 0;
            p->mUnk_0d8 = 0;
            p->mUnk_0e4 = 0x1000;
            p->mUnk_0e8 = 0x400;
            p->mUnk_0ec = -0x29;
            p->mUnk_0f0 = 0x1000;
            p->mUnk_0f4 = 0;
            p->mUnk_11c = TRUE;
            switch (p->mUnk_000.mKind) {
                case 0x1b4:
                    func_020d26ec(k, 0x156);
                    break;
                case 0x1b5:
                    func_020d26ec(k, 0x155);
                    break;
                case 0x1a8:
                    func_020d26ec(k, 0x1cf);
                    break;
            }
            if ((u16) (p->mUnk_000.mKind + 0xfe4c) <= 1) {
                func_02103544(k->mIndex,
                              (u16) (((u64) func_0209c9fc_inline(&gRaceProgress->mLocalRandom) * 3) >> 32) + 1);
                Vec3Sub(&p->mUnk_000.mPos, &k->mUnk_1b8, &v3);
                if (!((s64) v3.x * v3.x + (s64) v3.y * v3.y + (s64) v3.z * v3.z < 0x10)) {
                    func_02039860(&v3, &v3);
                }
                Vec3AddScaled(k->mRadius, &v3, &k->mUnk_1b8, &v3);
                if (k->mIndex == data_021759c0->mEntryIndex) {
                    func_0208b7bc(0x74, &v3);
                } else {
                    func_0208b7bc(0x75, &v3);
                }
            }
        }
        return d;
    }
    p->mUnk_000.mUnk_10.x = 0;
    p->mUnk_000.mUnk_10.y = 0;
    p->mUnk_000.mUnk_10.z = 0;
    return 2;
}

u8 func_0209c964(Unk0209c220 *p, void *a, u8 *b, u8 *c) {
    u32 d;

    d = *c;
    if (*b == 2 && p->mUnk_11c == FALSE) {
        p->mUnk_0b8 = 0x8000;
        p->mUnk_0c4 = 0x1000;
        p->mUnk_0c8 = 0x200;
        p->mUnk_0cc = -0x14;
        p->mUnk_0d0 = 0x1000;
        p->mUnk_0d4 = 0;
        p->mUnk_0d8 = 0;
        p->mUnk_0e4 = 0x1000;
        p->mUnk_0e8 = 0x200;
        p->mUnk_0ec = -0x14;
        p->mUnk_0f0 = 0x1000;
        p->mUnk_0f4 = 0;
        p->mUnk_11c = TRUE;
        p->mUnk_000.mUnk_78 |= data_usa_021565d0;
    }
    return d;
}

BOOL func_0209c8b0(Unk0209c220 *p, Vec3 *a, s32 b, Vec3 *c) {
    if ((p->mUnk_000.mFlags & 0x800) == 0 && p->mUnk_11c == TRUE) {
        p->mUnk_0a4 = func_020ead80(a, &p->mUnk_000.mPos, &p->mUnk_000.mMatrix.mUnk_00[0],
                                    ((s64) p->mUnk_000.mUnk_58.x * p->mUnk_0bc) >> 12, p->mUnk_000.mUnk_58.y, 0, b, c);
    } else {
        p->mUnk_0a4 = func_020ead80(a, &p->mUnk_000.mPos, &p->mUnk_000.mMatrix.mUnk_00[0], p->mUnk_000.mUnk_58.x,
                                    p->mUnk_000.mUnk_58.y, 0, b, c);
    }
    return p->mUnk_0a4 != 0;
}

void CreateBound(void *a) {
    gBound = CreateMapObjectModelAnimated(a, gBoundNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gBound, gBoundNsbtpName);
}

void func_0209c7a8(Unk02100094 *a, Unk0209c220 *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mMatrix.mUnk_00[3].x = p->mUnk_000.mPos.x >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].y = p->mUnk_000.mPos.y >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].z = p->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mMatrix, 0xc);
    if (p->mUnk_11c == TRUE) {
        x = p->mUnk_0bc;
        y = p->mUnk_0dc;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    func_0209b688(gBound, p->mUnk_0a0);
    DrawMapObjectModel(a, gBound, p);
}

void CreateCream(void *a) {
    gCream = CreateMapObjectModelAnimated(a, gCreamNsbmdName);
    func_02103554(data_usa_02167328);
}

void CreateBerry(void *a) {
    gBerry = CreateMapObjectModelAnimated(a, gBerryNsbmdName);
    func_02103554(gCreamEffectNsbmdName);
}

void func_0209c678(Unk02100094 *a, Unk0209c220 *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mMatrix.mUnk_00[3].x = p->mUnk_000.mPos.x >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].y = p->mUnk_000.mPos.y >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].z = p->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mMatrix, 0xc);
    if (p->mUnk_11c == TRUE) {
        x = p->mUnk_0bc;
        y = p->mUnk_0dc;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gCream, p);
}

void func_0209c5b8(Unk02100094 *a, Unk0209c220 *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mMatrix.mUnk_00[3].x = p->mUnk_000.mPos.x >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].y = p->mUnk_000.mPos.y >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].z = p->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mMatrix, 0xc);
    if (p->mUnk_11c == TRUE) {
        x = p->mUnk_0bc;
        y = p->mUnk_0dc;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gBerry, p);
}

void func_0209c4f0(Unk02100094 *a) {
    s32 i;
    Unk0209c220 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (p->mUnk_000.mCourseMapRow->mUnk_26 >= 0) {
            func_020d7da8(&p->mUnk_0f8, p->mUnk_000.mCourseMapRow, 0);
            p->mUnk_0f8.mUnk_04 = 0x3000;
            p->mUnk_0f8.mUnk_10 = ((s64) p->mUnk_0f8.mUnk_00->mUnk_00[p->mUnk_0f8.mUnk_0c].mUnk_34 * 0x3000) >> 12;
        } else {
            p->mUnk_0f8.mUnk_08 = 0xffff;
        }
    }
}

s16 func_0209c4d8(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209c4bc(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void func_0209c220(Unk02100094 *a, Unk0209c220 *p) {
    u16 v;
    s32 t;
    s32 i;
    s32 n;

    if (p->mUnk_0f8.mUnk_08 != 0xffff) {
        func_020d8cc8(&p->mUnk_0f8);
        func_020d8bf8(&p->mUnk_0f8, &p->mUnk_000.mPos, &p->mUnk_000.mUnk_10);
        v = func_0209b634(gBound);
        p->mUnk_0a0 += 1;
        if (p->mUnk_0a0 >= v) {
            p->mUnk_0a0 = 1;
        }
    } else {
        p->mUnk_000.mUnk_10.x = 0;
        p->mUnk_000.mUnk_10.y = 0;
        p->mUnk_000.mUnk_10.z = 0;
        p->mUnk_0a0 = 0;
    }
    if (p->mUnk_11c == TRUE) {
        p->mUnk_0b8 += p->mUnk_0d0;
        t = func_0209c4bc(p->mUnk_0c8, func_0209c4d8(p->mUnk_0b8));
        p->mUnk_0c0 = p->mUnk_0c4 + t - p->mUnk_0bc;
        p->mUnk_0bc += p->mUnk_0c0;
        if (p->mUnk_0c8 > 0) {
            t = p->mUnk_0c8 + p->mUnk_0cc;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0c8 = t;
        } else if (p->mUnk_0c8 < 0) {
            t = p->mUnk_0c8 + p->mUnk_0cc;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0c8 = t;
        }
        if (p->mUnk_0d0 > 0) {
            t = p->mUnk_0d0 + p->mUnk_0d4;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0d0 = t;
        } else if (p->mUnk_0d0 < 0) {
            t = p->mUnk_0d0 + p->mUnk_0d4;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0d0 = t;
        }
        p->mUnk_0d8 += p->mUnk_0f0;
        t = func_0209c4bc(p->mUnk_0e8, func_0209c4d8(p->mUnk_0d8));
        p->mUnk_0e0 = p->mUnk_0e4 + t - p->mUnk_0dc;
        p->mUnk_0dc += p->mUnk_0e0;
        if (p->mUnk_0e8 > 0) {
            t = p->mUnk_0e8 + p->mUnk_0ec;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0e8 = t;
        } else if (p->mUnk_0e8 < 0) {
            t = p->mUnk_0e8 + p->mUnk_0ec;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0e8 = t;
        }
        if (p->mUnk_0f0 > 0) {
            t = p->mUnk_0f0 + p->mUnk_0f4;
            if (t <= 0) {
                t = 0;
            }
            p->mUnk_0f0 = t;
        } else if (p->mUnk_0f0 < 0) {
            t = p->mUnk_0f0 + p->mUnk_0f4;
            if (t >= 0) {
                t = 0;
            }
            p->mUnk_0f0 = t;
        }
        if (p->mUnk_0c8 == 0 && p->mUnk_0e8 == 0) {
            p->mUnk_11c = FALSE;
            p->mUnk_000.mScale.x = p->mUnk_0b4;
        } else {
            p->mUnk_000.mScale.x = ((s64) p->mUnk_0b4 * p->mUnk_0bc) >> 12;
        }
    } else {
        p->mUnk_000.mScale.x = p->mUnk_0b4;
    }
    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        if (p->mUnk_120[i] > 0) {
            p->mUnk_120[i] -= 1;
        }
    }
}

void func_0209c1dc(void) {
    Unk0209bf70 *o;

    o = func_0209bfa8(func_0209c9fc, func_0209c964, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x1cf;
}

void func_0209c198(void) {
    Unk0209bf70 *o;

    o = func_0209bfa8(func_0209c9fc, func_0209c964, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x156;
}

void func_0209c154(void) {
    Unk0209bf70 *o;

    o = func_0209bfa8(func_0209c9fc, func_0209c964, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x155;
}

void func_0209c134(void) {
    func_0209bf1c(CreateBound, func_0209c7a8, NULL);
}

void func_0209c114(void) {
    func_0209bf1c(CreateCream, func_0209c678, NULL);
}

void func_0209c0f4(void) {
    func_0209bf1c(CreateBerry, func_0209c5b8, NULL);
}

void func_0209c0d4(void) {
    func_0209bf48(func_0209c4f0, func_0209c220, NULL);
}

BOOL func_0209bfe0(s32 a) {
    Unk0209c220 *p;
    Unk0210b7a8 s;
    s32 k;

    p = func_0209bc5c(func_02100138(0x1a8), a);
    if (p->mUnk_11c == FALSE) {
        p->mUnk_0b8 = 0x8000;
        p->mUnk_0c4 = 0x1000;
        p->mUnk_0c8 = 0x400;
        p->mUnk_0cc = -0x29;
        p->mUnk_0d0 = 0x1000;
        p->mUnk_0d4 = 0;
        p->mUnk_0d8 = 0;
        p->mUnk_0e4 = 0x1000;
        p->mUnk_0e8 = 0x400;
        p->mUnk_0ec = -0x29;
        p->mUnk_0f0 = 0x1000;
        p->mUnk_0f4 = 0;
        p->mUnk_11c = TRUE;
        if ((p->mUnk_000.mUnk_78 & 4) == 0) {
            if (p->mUnk_000.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_000.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s.mUnk_00 = 0x1cf;
            s.mUnk_04 = &p->mUnk_000.mPos;
            s.mUnk_08 = k;
            s.mUnk_0c = func_020d4ef4(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
        }
        return TRUE;
    }
    return FALSE;
}

#pragma thumb on

void *func_0209bfa8(void *param_1, void *param_2, void *param_3, u32 param_4, u16 param_5) {
    Unk0209bf70 *o;

    GetHeap(func_020364e8());
    o = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    o->mUnk_00 = param_1;
    o->mUnk_04 = param_2;
    o->mUnk_20 = param_4;
    o->mUnk_1c = param_5;
    o->mUnk_18 = param_3;
    return o;
}

u32 func_0209bf8c(void) {
    return (u32) func_0209bfa8(NULL, NULL, NULL, 0, 1);
}

Unk0209bf70 *func_0209bf70(void *a, void *b, void *c, u32 d, u16 e, u16 f) {
    Unk0209bf70 *o;

    o = func_0209bfa8(a, b, c, d, e);
    o->mUnk_24 = f;
    return o;
}
