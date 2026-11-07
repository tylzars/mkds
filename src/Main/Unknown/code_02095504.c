#include "Main/Unknown/code_02095504.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02077bc0.h"

u8 func_02095efc(MoveTree *a, Kart *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mState <= 1) {
        a->mUnk_a4 = 30;
    }
    return v;
}

void CreateMoveTree(void *a) {
    gMoveTree = CreateMapObjectModelAnimated(a, gMoveTreeNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gMoveTree, gMoveTreeNsbcaName);
    SetMapObjectModelPolygonId(gMoveTree, 0x3f);
}

void DrawMoveTree(void *a, MoveTree *p, u32 c, u32 d) {
    s32 t;

    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 12);
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    if ((s32) (p->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f) < 0xc5c10) {
        SetMapObjectModelNsbcaFrameIndex(gMoveTree, p->mNsbcaFrameIndex);
        DrawMapObjectModel(a, gMoveTree, p);
    } else {
        DrawMapObjectModel1Mat1Shp(a, gMoveTree, p);
    }
    if ((s32) (p->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x27100) {
        return;
    }
    func_020e5668(&p->mUnk_dc, &p->mUnk_00.mPos);
    func_020e53ac(&p->mUnk_dc, NULL, c, d);
}

void InitMoveTreeObjects(MapObjectList *p) {
    s32 i;
    MoveTree *e;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mMapObjectCount && (e = p->mMapObjects[i]) != NULL; i++) {
        e->mUnk_a8 = (e->mUnk_00.mCourseMapRow->mUnk_28 << 12) / 100;
        func_020e516c(&e->mUnk_dc, &e->mUnk_00.mPos, 0x54666, 14);
    }
}

void UpdateMoveTree(void *a, MoveTree *p) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    u32 k;
    s32 v;

    switch (p->mState) {
        case 0:
            p->mUnk_b4.mUnk_04 = 0;
            p->mUnk_b4.mUnk_10 = 0;
            if (p->mUnk_a0-- <= 0) {
                p->mState = 1;
            }
            if ((s32) (p->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (p->mUnk_a4-- > 0) {
                p->mUnk_b0 = 2;
                p->mNsbcaFrameIndex += p->mUnk_b0;
                if (p->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                    p->mNsbcaFrameIndex = 0;
                }
                return;
            }
            if (p->mNsbcaFrameIndex == 0) {
                return;
            }
            p->mNsbcaFrameIndex += p->mUnk_b0;
            if (p->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                p->mNsbcaFrameIndex = 0;
            }
            if (p->mNsbcaFrameIndex != 0 && p->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) != 0) {
                return;
            }
            if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s1.mUnk_00 = 0x11f;
            s1.mUnk_04 = &p->mUnk_00.mPos;
            s1.mUnk_08 = k;
            s1.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
            func_0210b7a8(&s1);
            break;
        case 1:
            v = p->mUnk_a8;
            p->mUnk_b4.mUnk_04 = v;
            p->mUnk_b4.mUnk_10 = ((s64) v * p->mUnk_b4.mUnk_00->mUnk_00[p->mUnk_b4.mUnk_0c].mUnk_34) >> 12;
            if (func_020d8cc8(&p->mUnk_b4) != FALSE) {
                p->mUnk_a0 = (u16) p->mUnk_b4.mUnk_1c->mUnk_0e;
                p->mState = 0;
            }
            func_020d879c(&p->mUnk_b4, &p->mUnk_00.mPos);
            if ((s32) (p->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (p->mUnk_a4-- > 0) {
                p->mUnk_b0 = 2;
            } else {
                p->mUnk_b0 = 1;
            }
            p->mNsbcaFrameIndex += p->mUnk_b0;
            if (p->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                p->mNsbcaFrameIndex = 0;
            }
            if (p->mNsbcaFrameIndex != 0 && p->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) != 0) {
                return;
            }
            if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s2.mUnk_00 = 0x11f;
            s2.mUnk_04 = &p->mUnk_00.mPos;
            s2.mUnk_08 = k;
            s2.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
            func_0210b7a8(&s2);
    }
}

void CreateMoveTreeKindData(void) {
    func_0209bf70(func_02095efc, NULL, NULL, 2, 1, 0x125);
}

void CreateMoveTreeDrawList(void) {
    CreateMapObjectDrawList1(CreateMoveTree, DrawMoveTree, NULL);
}

void CreateMoveTreeUpdateList(void) {
    CreateMapObjectUpdateList(InitMoveTreeObjects, UpdateMoveTree, NULL);
}

void CreateBakubakuAndBakuShadow(void *a) {
    gBakubaku = CreateMapObjectModelAnimated(a, gBakubakuNsbmdName);
    gBakuShadow = CreateMapObjectModelShadow(a, gBakuShadowNsbmdName);
    SetMapObjectModelPolygonId(gBakubaku, 0x3f);
    SetMapObjectModelPolygonId(gBakuShadow, 0x3f);
}

void DrawBakubaku(void *a, Bakubaku *p) {
    s32 t;
    s32 m[9];
    s32 i;

    if (p->mState != 2) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_00.mMatrix, 12);
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    DrawMapObjectModel(a, gBakuShadow, p);
    i = (u16) (u32) FX_Atan2Idx(-p->mUnk_00.mUnk_10.y, 0xc000) >> 4;
    MTX_RotX33_(m, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
    func_01ff9048(0x1a, m, 9);
    DrawMapObjectModel(a, gBakubaku, p);
}

void InitBakubakuObjects(MapObjectList *p) {
    s32 i;
    Bakubaku *e;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mMapObjectCount && (e = p->mMapObjects[i]) != NULL; i++) {
        VEC_MultAdd(0x320000, &e->mUnk_00.mMatrix.mUnk_00[2], &e->mUnk_00.mCourseMapRow->mUnk_00, &e->mUnk_a4);
    }
}

void UpdateBakubaku(void *a, Bakubaku *p) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Kart *o;
    Vec3 *q;
    s64 d;
    s32 v1;
    s32 v2;

    switch (p->mState) {
        case 0:
            if (GetCurrentCameraKind() != 2) {
                o = GetKart((u16) gRaceSetup->mEntryIndex);
                q = &o->mPos;
                v2 = q->x - p->mUnk_a4.x;
                v1 = q->z - p->mUnk_a4.z;
                d = (s64) v2 * v2 + (s64) v1 * v1;
                if (d >= (s64) 0x9c4 << 32) {
                    return;
                }
            }
            p->mUnk_00.mPos.x = p->mUnk_00.mCourseMapRow->mUnk_00.x;
            p->mUnk_00.mPos.y = p->mUnk_00.mCourseMapRow->mUnk_00.y - 0x32000;
            p->mUnk_00.mPos.z = p->mUnk_00.mCourseMapRow->mUnk_00.z;
            p->mUnk_00.mUnk_10.x = ((s64) p->mUnk_00.mMatrix.mUnk_00[2].x * 0xc000) >> 12;
            p->mUnk_00.mUnk_10.y = 0xc000;
            p->mUnk_00.mUnk_10.z = ((s64) p->mUnk_00.mMatrix.mUnk_00[2].z * 0xc000) >> 12;
            p->mState = 1;
            break;
        case 1:
            p->mUnk_00.mUnk_10.y -= 0x400;
            VEC_Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
            if (p->mUnk_00.mPos.y < p->mUnk_00.mCourseMapRow->mUnk_00.y) {
                return;
            }
            StartModelEffect(3, &p->mUnk_00.mPos, 1);
            s1.mUnk_00 = 0x186;
            s1.mUnk_04 = &p->mUnk_00.mPos;
            s1.mUnk_08 = 4;
            s1.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
            func_0210b7a8(&s1);
            p->mState = 2;
            break;
        case 2:
            p->mUnk_00.mUnk_10.y -= 0x400;
            VEC_Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
            if (p->mUnk_00.mPos.y > p->mUnk_00.mCourseMapRow->mUnk_00.y) {
                return;
            }
            StartModelEffect(3, &p->mUnk_00.mPos, 1);
            s2.mUnk_00 = 0x187;
            s2.mUnk_04 = &p->mUnk_00.mPos;
            s2.mUnk_08 = 2;
            s2.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
            func_0210b7a8(&s2);
            p->mState = 3;
            break;
        case 3:
            p->mUnk_00.mUnk_10.y -= 0x400;
            VEC_Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
            if (p->mUnk_00.mPos.y <= p->mUnk_00.mCourseMapRow->mUnk_00.y - 0x32000) {
                p->mUnk_a0 = 0x708;
                p->mState = 4;
            }
            break;
        case 4:
            if (p->mUnk_a0-- <= 0) {
                p->mState = 0;
            }
            break;
    }
}

void CreateBakubakuDrawList(void) {
    CreateMapObjectDrawList1(CreateBakubakuAndBakuShadow, DrawBakubaku, NULL);
}

void CreateBakubakuUpdateList(void) {
    CreateMapObjectUpdateList(InitBakubakuObjects, UpdateBakubaku, NULL);
}
