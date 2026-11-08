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

void func_ov001_0218a30c(Unk02188950 *a) {
    Unk021a7c08 local;

    func_ov001_02187218(a, 8, NULL);
    ReleaseEffects(a);
    StartEffectAtOffset(a, 0, 0x2000, 0, 0x421, 0);
    StartEffectAtOffset(a, 0, 0x2000, 0, 0x40c, 0);
    StartEffectAtOffset(a, 0, 0x2000, 0, 0x40e, 0);
    StartEffectAtOffset(a, 0, 0x2000, 0, 0x40d, 0);
    StartEffectAtOffset(a, 0, 0x2000, 0, 0x40f, 0);
    local = data_ov001_021a7ad0;
    local.mUnk_04 = &a->mUnk_000.mPos;
    local.mUnk_0c = GetHorizontalCameraDistanceSquared(&a->mUnk_000.mPos);
    func_0210b734(&local, func_02108e7c());
    a->mUnk_000.mFlags |= data_ov001_021a6588;
    a->mUnk_000.mFlags |= data_ov001_021a658c;
    a->mUnk_000.mFlags |= data_ov001_021a6590;
}

void func_ov001_0218a2dc(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_070, a->mPrm->mUnk_074);
    func_ov001_02188e24(a, 0x3c, &func_ov001_0218a30c);
}

void func_ov001_0218a2d4(void) {
    func_ov001_021882b8();
}

s32 func_ov001_0218a2b8(Unk02188950 *a) {
    int v1;
    v1 = IsRaceStarted();
    if (v1 == 1) {
        func_ov001_02188e88(a);
    }
    return 0;
}

void func_ov001_0218a290(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218a2b8);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
}

void func_ov001_0218a250(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationWithEndCallback(a, a->mPrm->mUnk_058, a->mPrm->mUnk_05c, (UnkFunc *) &func_ov001_0218a290);
    func_ov001_02188e74(a, ((u32) a->mPrm->mUnk_148), func_ov001_0218b034);
}

void func_ov001_0218a20c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_04c, a->mPrm->mUnk_050);
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218a250);
    StartMapObjectSound(&a->mUnk_000, 0x00000235u);
}

void func_ov001_0218a1d0(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_040, a->mPrm->mUnk_044);
    func_ov001_02188e74(a, a->mPrm->mUnk_148, func_ov001_0218affc);
}

void func_ov001_0218a19c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_034, a->mPrm->mUnk_038);
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, &func_ov001_0218a1d0);
}

void InitBombKingObjects(Unk0218d87c *a) {
    int i;
    Unk02188950 *obj;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            Vec3 v = {0, 0, 0};
            v.x = obj->mPrm->mUnk_0fc;
            v.y = obj->mPrm->mUnk_100;
            func_ov001_02187c88(obj, 5, (&v));
            if (GetRaceUseChainCameras() != 0) {
                func_ov001_0218a19c(obj);
            } else {
                func_ov001_0218a20c(obj);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_0218a2d4);
}

void UpdateBombKing(u32 a, Unk02188950 *b) {
    int active;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        active = IsWinnerDecided();
    } else {
        active = 0;
    }
    if (active != 0) {
        if (func_ov001_021871f8(b, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                active = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                active = 0;
            }
            if (active != 0) {
                func_ov001_0218a3ec(b);
            } else {
                func_ov001_0218a2dc(b);
            }
        }
    } else {
        if (func_ov001_021871f8(b, 3) != 0) {
            if (func_ov001_02188220(b) >= 2) {
                func_ov001_0218ab04(b);
            }
        }
        if (func_ov001_021871f8(b, 3) != 0) {
            func_ov001_0218a75c(b);
        }
        if (func_ov001_021871f8(b, 2) != 0) {
            func_ov001_0218a60c(b);
        }
    }
    AdvanceMissionRunMapObject(a, b);
}

void func_ov001_0218a034(Unk02188950 *a) {
    CreateParkedMapObjects(0xc9, 0xa, a);
    a->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) a->mUnk_000.mSound, 0xc, &a->mUnk_000.mPos);
    a->mUnk_000.mFarDistanceSquared = data_0217cbec[0x50 / 4];
}

void func_ov001_0218a028(Unk0201ca6c *a) {
    a->mUnk_6c = 0x2000;
}

void func_ov001_02189fe0(Unk02188950 *a, Kart *b) {
    if (b->mUnk_44 == 9) {
        if (IsItemBombState2(b) == FALSE) {
            func_0208b748(0x3a, &b->mTurnedForward, NULL, func_ov001_0218a028);
        }
    }
    a->mUnk_2e0 = 1;
    SetItemCollisionCallback(a, (UnkFunc *) func_ov001_02189fe0);
}

void func_ov001_02189ed8(Unk02188950 *a, Kart *b) {
    Vec3 v;
    s64 scale;

    if (IsItemBombStored(a) != 0) {
        func_ov001_02187bfc(a, NULL, 0);
    }
    a->mUnk_2e0 = 2;
    SetItemCollisionCallback(a, (UnkFunc *) func_ov001_02189ed8);
    if (func_ov001_021871f8(a, 7) != 0) {
        v.x = a->mUnk_000.mPos.x - b->mTurnedForward.x;
        v.y = 0;
        v.z = a->mUnk_000.mPos.z - b->mTurnedForward.z;
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        scale = a->mPrm->mUnk_16c;
        v.x = (s64) v.x * scale >> 12;
        v.y = (s64) v.y * scale >> 12;
        v.z = (s64) v.z * scale >> 12;
        v.y = a->mPrm->mUnk_170;
        SetVelocity(a, &v);
        func_ov001_0218a41c(a);
    }
}
void InitBombKing(Unk0218d87c *a) {
    Unk02188950 *obj;
    MissionRunPrm *a0;
    int i;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(a, obj, data_ov001_021a7b14, data_ov001_021a7b24, data_ov001_021a7b34);
            LoadMissionRunMapObjectShadow(a, obj, data_ov001_021a7b44);
            a0 = obj->mPrm;
            SetCollisionOffsetAndExtent(obj, a0->mUnk_008, a0->mUnk_00c, a0->mUnk_20c);
            SetShadowOffsetYAndScale(obj, 0, 0x23000);
            SetItemCollisionCallback(obj, (UnkFunc *) func_ov001_02189ed8);
        }
    }
}

void func_ov001_02189e0c(void *a, Unk02188950 *b) {
    DrawMissionRunMapObject(a, b);
    DrawMissionRunMapObjectShadow(a, b, 0);
}

void func_ov001_02189dd8(void) {
    u32 v4 = 0x23eu;
    void *v8 = &CollideKartWithMissionRunMapObject;
    void *v9 = &CollideItemWithMissionRunMapObject;
    void *v10 = &ComputeSphereHitOnMissionRunMapObject;
    void *v12 = func_ov001_0219b510(v8, v9, v10, 0x2u, 0x1u, v4, 0x0u);
}

void *func_ov001_02189dbc(void) {
    return CreateMapObjectDrawList1(InitBombKing, func_ov001_02189e0c, ToggleShadowScale);
}

void *func_ov001_02189da4(void) {
    return CreateMapObjectUpdateList(InitBombKingObjects, UpdateBombKing, NULL);
}
