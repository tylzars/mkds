#include "01/code_0218c7a0.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181000.h"
#include "01/code_0218d4c8.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02110000.h"
#include "01/code_0218155c.h"
#include "01/code_0219b250.h"
#include "01/code_0218dce4.h"
#include "01/code_02188484.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_0218d374.h"

void func_ov001_0218d2c4(Unk02188950 *a) {
    int i;
    Unk0218d87c *list;
    Unk02188950 *p;
    Unk021a7c08 local;

    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_070, a->mPrm->mUnk_074);
    SetMapObjectModelNsbtpFrameIndex(a->mNsbmd, 0);
    list = func_02100138(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            func_ov001_02187218(p, 1, NULL);
            StartAnimationNoEndCallback(p, p->mPrm->mUnk_070, p->mPrm->mUnk_074);
            SetMapObjectModelNsbtpFrameIndex((p->mNsbmd), 0);
        }
    }
    local = data_ov001_021a7c08;
    local.mUnk_04 = &a->mUnk_000.mPos;
    local.mUnk_0c = GetHorizontalCameraDistanceSquared(&a->mUnk_000.mPos);
    func_0210b734(&local, func_02108e7c());
}

void func_ov001_0218d280(void) {
    Unk0218d87c *list;
    Unk02188950 *p;
    int i;

    func_ov001_021882b8();
    list = func_02100138(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            func_ov001_0218dadc(p);
            func_ov001_0218dabc(p);
        }
    }
}

s32 func_ov001_0218d264(Unk02188950 *a) {
    int v1;
    v1 = IsRaceStarted();
    if (v1 == 1) {
        func_ov001_0218d4c8(a);
    }
    return 0;
}

void func_ov001_0218d23c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218d264);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
}

void func_ov001_0218d214(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationWithEndCallback(a, a->mPrm->mUnk_058, a->mPrm->mUnk_05c, &func_ov001_0218d23c);
}

void func_ov001_0218d1e0(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_04c, a->mPrm->mUnk_050);
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218d214);
}

void func_ov001_0218d1bc(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_040, a->mPrm->mUnk_044);
}

void func_ov001_0218d188(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_034, a->mPrm->mUnk_038);
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, &func_ov001_0218d1bc);
}

s32 func_ov001_0218d16c(Unk02188950 *a) {
    int v1;
    v1 = IsRaceStarted();
    if (v1 == 1) {
        func_ov001_0218d950(a);
    }
    return 0;
}

s32 func_ov001_0218d0fc(Unk02188950 *a) {
    int v1;
    v1 = GetMapObjectModelNsbcaFrameIndex(a->mNsbmd);
    if (v1 == 0x33) {
        ReleaseEffects(a);
        StartEffectAtOffset(a, (0xfffff666u), 0, (0x00000400u), (0x00000434u), 0);
    } else {
        v1 = GetMapObjectModelNsbcaFrameIndex(a->mNsbmd);
        if (v1 == 0x66) {
            ReleaseEffects(a);
            StartEffectAtOffset(a, (0x0000099au), 0, (0x00000400u), (0x00000434u), 0);
        }
    }
    return 0;
}

void func_ov001_0218d0d4(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218d16c);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
}

void func_ov001_0218d0a8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218d0fc);
    StartAnimationWithEndCallback(a, a->mPrm->mUnk_058, a->mPrm->mUnk_05c, &func_ov001_0218d0d4);
}

void func_ov001_0218d074(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_04c, a->mPrm->mUnk_050);
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218d0a8);
}

void func_ov001_0218d050(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_040, a->mPrm->mUnk_044);
}

void func_ov001_0218d01c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_034, a->mPrm->mUnk_038);
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, &func_ov001_0218d050);
}

void func_ov001_0218cfe8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218d0a8);
}

void InitHanachanObjects(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
            p->mUnk_2c4 = TRUE;
            if (GetRaceUseChainCameras() != 0) {
                func_ov001_0218d188(p);
            } else {
                func_ov001_0218d1e0(p);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_0218d280);
}

void UpdateHanachan(u32 a, Unk02188950 *b) {
    int r;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        r = IsWinnerDecided();
    } else {
        r = 0;
    }
    if (r != 0) {
        if (func_ov001_021871f8(b, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                r = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                r = 0;
            }
            if (r != 0) {
                func_ov001_0218d374(b);
            } else {
                func_ov001_0218d2c4(b);
            }
        }
    } else {
        if (func_ov001_021871f8(b, 1) != 0) {
            func_ov001_0218d3ec(b);
        }
    }
    if (func_020d2c2c(&b->mPosWithOffset, &b->mUnk_000.mUnk_10, b->mPrm->mUnk_100, b->mUnk_000.mCollisionSlotIndex, 9,
                      NULL) == 2) {
        StartMapObjectSound(&b->mUnk_000, 0x253);
    }
    AdvanceMissionRunMapObject(a, b);
}

void func_ov001_0218ce90(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
            if (GetRaceUseChainCameras() != 0) {
                func_ov001_0218d01c(p);
            } else if (i == 0) {
                func_ov001_0218d074(p);
            } else {
                func_ov001_0218cfe8(p);
            }
        }
    }
}

void func_ov001_0218ce30(u32 a, Unk02188950 *b) {
    int v1;
    func_ov001_0218dc20(b);
    func_ov001_0218dba8(b);
    v1 = func_020d2c2c(&b->mPosWithOffset, &b->mUnk_000.mUnk_10, b->mPrm->mUnk_100, b->mUnk_000.mCollisionSlotIndex, 9,
                       NULL);
    if (v1 == 2) {
        StartMapObjectSound(&b->mUnk_000, 0x253);
    }
    AdvanceMissionRunMapObject(a, b);
}

void func_ov001_0218cdb8(Unk02188950 *e) {
    Unk02188950 *a;
    Unk02188950 *b;
    Unk02188950 *c;
    Unk02188950 *d;

    a = (Unk02188950 *) CreateMapObjectFromObject(&e->mUnk_000, 0x1fe);
    b = (Unk02188950 *) CreateMapObjectFromObject(&e->mUnk_000, 0x1fe);
    c = (Unk02188950 *) CreateMapObjectFromObject(&e->mUnk_000, 0x1fe);
    d = (Unk02188950 *) CreateMapObjectFromObject(&e->mUnk_000, 0x1fe);
    a->mUnk_0a4 = (struct Unk0218dabc *) e;
    b->mUnk_0a4 = (struct Unk0218dabc *) a;
    c->mUnk_0a4 = (struct Unk0218dabc *) b;
    d->mUnk_0a4 = (struct Unk0218dabc *) c;
    e->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&e->mUnk_000.mSound->mSoundSource, 0xd, &e->mUnk_000.mPos);
    e->mUnk_000.mFarDistanceSquared = data_0217cbec[0x1d];
}

void func_ov001_0218cd80(Unk02188950 *a) {
    a->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&a->mUnk_000.mSound->mSoundSource, 0xd, &a->mUnk_000.mPos);
    a->mUnk_000.mFarDistanceSquared = data_0217cbec[0x1d];
}

void func_ov001_0218cbdc(Unk02188950 *a, MissionRunPrm *b) {
    s32 r4;
    s32 diff;

    if (b->mUnk_29c == 1) {
        if (a->mTimer > 0) {
            a->mUnk_2d8 = 0xc;
        } else {
            r4 = a->mMoveAngle;
            diff = (u16) (FX_Atan2Idx(b->mUnk_080 - a->mUnk_000.mPos.x, b->mUnk_088 - a->mUnk_000.mPos.z) - r4);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                a->mUnk_000.mUnk_10.x = ((s64) a->mPrm->mUnk_0fc * gPairsByAngle[(((u16) r4 + 0x4000) >> 4) * 2]) >> 12;
                a->mUnk_000.mUnk_10.y = 0;
                a->mUnk_000.mUnk_10.z =
                    ((s64) a->mPrm->mUnk_0fc * gPairsByAngle[(((u16) a->mMoveAngle + 0x4000) >> 4) * 2 + 1]) >> 12;
            } else {
                a->mUnk_000.mUnk_10.x = ((s64) a->mPrm->mUnk_0fc * gPairsByAngle[(((u16) r4 - 0x4000) >> 4) * 2]) >> 12;
                a->mUnk_000.mUnk_10.y = 0;
                a->mUnk_000.mUnk_10.z =
                    ((s64) a->mPrm->mUnk_0fc * gPairsByAngle[(((u16) a->mMoveAngle - 0x4000) >> 4) * 2 + 1]) >> 12;
            }
            a->mUnk_2d8 = 0xc;
            StartCameraWobbleAtDistance(a->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
            a->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a65ac;
            func_020d26ec(b, 0x252);
        }
    } else {
        a->mUnk_2d8 = 0xa;
        StartCameraWobbleAtDistance(a->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
        a->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a65ac;
        func_020d26ec(b, 0x251);
    }
    SetKartCollisionCallback(a, func_ov001_0218cbdc);
}

void InitHanachan(Unk0218d87c *a) {
    Unk02188950 *obj;
    s32 i;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(a, obj, data_ov001_021a7d0c, data_ov001_021a7d1c, data_ov001_021a7d2c);
            LoadMissionRunMapObjectShadow(a, obj, data_ov001_021a7d3c);
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, data_ov001_021a7d4c);
            SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_008, obj->mPrm->mUnk_00c, obj->mPrm->mUnk_00c);
            SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
            SetKartCollisionCallback(obj, func_ov001_0218cbdc);
            SetItemCollisionCallback(obj, func_ov001_0218dd9c);
            obj->mUnk_0a8 = obj->mPrm->mUnk_12c;
        }
    }
}

void func_ov001_0218c87c(Unk0218d87c *d) {
    void *a;
    void *b;
    void *c;
    Unk02188950 *obj;
    Unk02188950 *src;

    a = LoadMissionRunFile(data_ov001_021a7c80);
    b = LoadMissionRunFile(data_ov001_021a7c94);
    c = LoadMissionRunFile(data_ov001_021a7ca8);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        src = GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0);
    } else {
        src = NULL;
    }

    obj = d->mUnk_00[0];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(d, obj, data_ov001_021a7cbc, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, a);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->mUnk_0a8 = 1;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0dc, obj->mPrm->mUnk_00c, src->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);

    obj = d->mUnk_00[1];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(d, obj, data_ov001_021a7cd0, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, b);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->mUnk_0a8 = 2;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0e4, obj->mPrm->mUnk_00c, src->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);

    obj = d->mUnk_00[2];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(d, obj, data_ov001_021a7ce4, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, a);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->mUnk_0a8 = 3;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0ec, obj->mPrm->mUnk_00c, src->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);

    obj = d->mUnk_00[3];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(d, obj, data_ov001_021a7cf8, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, b);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->mUnk_0a8 = 4;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0f4, obj->mPrm->mUnk_00c, src->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);
}

void func_ov001_0218c85c(void *a, Unk02188950 *b) {
    DrawMissionRunMapObject(a, b);
    DrawMissionRunMapObjectShadow(a, b, 0);
}

void func_ov001_0218c830(void) {
    void *v7 = &CollideKartWithMissionRunMapObject;
    void *v8 = &CollideItemWithMissionRunMapObject;
    void *v9 = &ComputeSphereHitOnMissionRunMapObject;
    void *v11 = func_ov001_0219b510(v7, v8, v9, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *func_ov001_0218c818(void) {
    return CreateMapObjectDrawList1(InitHanachan, func_ov001_0218c85c, NULL);
}

void *func_ov001_0218c800(void) {
    return CreateMapObjectUpdateList(InitHanachanObjects, UpdateHanachan, NULL);
}

void func_ov001_0218c7d4(void) {
    void *v7 = &CollideKartWithMissionRunMapObject;
    void *v8 = &CollideItemWithMissionRunMapObject;
    void *v9 = &ComputeSphereHitOnMissionRunMapObject;
    void *v11 = func_ov001_0219b510(v7, v8, v9, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *func_ov001_0218c7b8(void) {
    return CreateMapObjectDrawList1(func_ov001_0218c87c, func_ov001_0218c85c, ToggleShadowScale);
}

void *func_ov001_0218c7a0(void) {
    return CreateMapObjectUpdateList(func_ov001_0218ce90, func_ov001_0218ce30, NULL);
}
