#include "01/code_02189da4.h"
#include "01/code_02187c60.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218a41c.h"
#include "01/code_0218155c.h"
#include "01/code_02185ef4.h"
#include "01/code_02187c4c.h"
#include "01/code_02188218.h"
#include "01/code_0218a3ec.h"
#include "01/code_0218a568.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/code_0218affc.h"
#include "01/code_0218b034.h"
#include "01/code_0218d520.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"
#include "01/code_02188000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"

void func_ov001_0218a30c(Unk02188950 *mapObject) {
    Unk021a7c08 local;

    func_ov001_02187218(mapObject, 8, NULL);
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x421, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40c, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40e, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40d, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40f, 0);
    local = data_ov001_021a7ad0;
    local.mUnk_04 = &mapObject->mUnk_000.mPos;
    local.mUnk_0c = GetHorizontalCameraDistanceSquared(&mapObject->mUnk_000.mPos);
    func_0210b734(&local, func_02108e7c());
    mapObject->mUnk_000.mFlags |= data_ov001_021a6588;
    mapObject->mUnk_000.mFlags |= data_ov001_021a658c;
    mapObject->mUnk_000.mFlags |= data_ov001_021a6590;
}

void func_ov001_0218a2dc(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, &func_ov001_0218a30c);
}

void func_ov001_0218a2d4(void) {
    func_ov001_021882b8();
}

s32 func_ov001_0218a2b8(Unk02188950 *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        func_ov001_02188e88(mapObject);
    }
    return 0;
}

void func_ov001_0218a290(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, func_ov001_0218a2b8);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void func_ov001_0218a250(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  (UnkFunc *) &func_ov001_0218a290);
    SetAnimationFrameCallback(mapObject, ((u32) mapObject->mPrm->mUnk_148), func_ov001_0218b034);
}

void func_ov001_0218a20c(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &func_ov001_0218a250);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000235u);
}

void func_ov001_0218a1d0(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_148, func_ov001_0218affc);
}

void func_ov001_0218a19c(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &func_ov001_0218a1d0);
}

void InitBombKingObjects(Unk0218d87c *list) {
    int i;
    Unk02188950 *mapObject;

    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (mapObject = list->mUnk_00[i]) != NULL; i++) {
            Vec3 v = {0, 0, 0};
            v.x = mapObject->mPrm->mUnk_0fc;
            v.y = mapObject->mPrm->mUnk_100;
            func_ov001_02187c88(mapObject, 5, (&v));
            if (GetRaceUseChainCameras() != 0) {
                func_ov001_0218a19c(mapObject);
            } else {
                func_ov001_0218a20c(mapObject);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_0218a2d4);
}

void UpdateBombKing(u32 a, Unk02188950 *mapObject) {
    int active;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        active = IsWinnerDecided();
    } else {
        active = 0;
    }
    if (active != 0) {
        if (func_ov001_021871f8(mapObject, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                active = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                active = 0;
            }
            if (active != 0) {
                func_ov001_0218a3ec(mapObject);
            } else {
                func_ov001_0218a2dc(mapObject);
            }
        }
    } else {
        if (func_ov001_021871f8(mapObject, 3) != 0) {
            if (func_ov001_02188220(mapObject) >= 2) {
                func_ov001_0218ab04(mapObject);
            }
        }
        if (func_ov001_021871f8(mapObject, 3) != 0) {
            func_ov001_0218a75c(mapObject);
        }
        if (func_ov001_021871f8(mapObject, 2) != 0) {
            func_ov001_0218a60c(mapObject);
        }
    }
    AdvanceMissionRunMapObject(a, mapObject);
}

void func_ov001_0218a034(Unk02188950 *mapObject) {
    CreateParkedMapObjects(0xc9, 0xa, mapObject);
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) mapObject->mUnk_000.mSound, 0xc, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = data_0217cbec[0x50 / 4];
}

void func_ov001_0218a028(Unk0201ca6c *emitter) {
    emitter->mUnk_6c = 0x2000;
}

void func_ov001_02189fe0(Unk02188950 *mapObject, Kart *itemObject) {
    if (itemObject->mUnk_44 == 9) {
        if (IsItemBombState2(itemObject) == FALSE) {
            func_0208b748(0x3a, &itemObject->mTurnedForward, NULL, func_ov001_0218a028);
        }
    }
    mapObject->mUnk_2e0 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) func_ov001_02189fe0);
}

void func_ov001_02189ed8(Unk02188950 *mapObject, Kart *itemObject) {
    Vec3 velocity;
    s64 scale;

    if (IsItemBombStored(mapObject) != 0) {
        func_ov001_02187bfc(mapObject, NULL, 0);
    }
    mapObject->mUnk_2e0 = 2;
    SetItemCollisionCallback(mapObject, (UnkFunc *) func_ov001_02189ed8);
    if (func_ov001_021871f8(mapObject, 7) != 0) {
        velocity.x = mapObject->mUnk_000.mPos.x - itemObject->mTurnedForward.x;
        velocity.y = 0;
        velocity.z = mapObject->mUnk_000.mPos.z - itemObject->mTurnedForward.z;
        if ((s64) velocity.x * velocity.x + (s64) velocity.y * velocity.y + (s64) velocity.z * velocity.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&velocity, &velocity);
        }
        scale = mapObject->mPrm->mUnk_16c;
        velocity.x = (s64) velocity.x * scale >> 12;
        velocity.y = (s64) velocity.y * scale >> 12;
        velocity.z = (s64) velocity.z * scale >> 12;
        velocity.y = mapObject->mPrm->mUnk_170;
        SetVelocity(mapObject, &velocity);
        func_ov001_0218a41c(mapObject);
    }
}
void InitBombKing(Unk0218d87c *list) {
    Unk02188950 *mapObject;
    MissionRunPrm *prm;
    int i;

    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (mapObject = list->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(mapObject);
            }
            InitMissionRunMapObject(list, mapObject, data_ov001_021a7b14, data_ov001_021a7b24, data_ov001_021a7b34);
            LoadMissionRunMapObjectShadow(list, mapObject, data_ov001_021a7b44);
            prm = mapObject->mPrm;
            SetCollisionOffsetAndExtent(mapObject, prm->mUnk_008, prm->mUnk_00c, prm->mUnk_20c);
            SetShadowOffsetYAndScale(mapObject, 0, 0x23000);
            SetItemCollisionCallback(mapObject, (UnkFunc *) func_ov001_02189ed8);
        }
    }
}

void func_ov001_02189e0c(void *mapObjectList, Unk02188950 *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

void func_ov001_02189dd8(void) {
    u32 v4 = 0x23eu;
    void *kartCollisionCallback = &CollideKartWithMissionRunMapObject;
    void *itemCollisionCallback = &CollideItemWithMissionRunMapObject;
    void *sphereHitCallback = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        func_ov001_0219b510(kartCollisionCallback, itemCollisionCallback, sphereHitCallback, 0x2u, 0x1u, v4, 0x0u);
}

void *CreateBombKingDrawList(void) {
    return CreateMapObjectDrawList1(InitBombKing, func_ov001_02189e0c, ToggleShadowScale);
}

void *CreateBombKingUpdateList(void) {
    return CreateMapObjectUpdateList(InitBombKingObjects, UpdateBombKing, NULL);
}
