#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02077bc0.h"

u32 InitTeresa(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    ParkMapObject((void *) value0);
    value0 = (u32) &gUnparkedTeresaCount;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void CreateTeresa(Unk02094db4 *a) {
    gTeresa = CreateMapObjectModelNsbmdNsbtp(a, gTeresaNsbmdName, gTeresaNsbtpName);
    SetMapObjectModelPolygonId(gTeresa, 0x3f);
    a->mUnk_1c = 1;
}

void SetupDrawTeresa(void *a) {
    func_0209bbd0(a, gTeresa);
}

void DrawTeresa(void *a, Teresa *teresa) {
    s32 w;
    s32 v[3];

    if (teresa->mModelAlpha == 0) {
        return;
    }
    GetKart((u16) gRaceSetup->mEntryIndex);
    SetMapObjectModelPolygonId(gTeresa, AllocPolygonIdWrapping());
    SetMapObjectModelNsbtpFrameIndex(gTeresa, teresa->mNsbtpFrameIndex);
    SetMapObjectModelAlpha(gTeresa, teresa->mModelAlpha);
    SetMapObjectModelFogEnabled(gTeresa, IsFadeFogActive());
    SetMapObjectModelMirror(gTeresa, teresa->mMirror, 0);
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&teresa->mUnk_00.mPos), 0xc);
    if (GetCurrentCameraKind() == 2) {
        v[0] = 0x2000;
        v[1] = 0x2000;
        v[2] = 0x2000;
        func_01ff9048(0x1b, v, 3);
    }
    func_01ff9048(0x1b, &teresa->mUnk_00.mScale, 3);
    DrawMapObjectModel(a, gTeresa, teresa);
}

static inline void func_02094768_inline(Teresa *teresa) {
    teresa->mAlphaFixed12 = teresa->mAlphaFixed12 + teresa->mAlphaFixed12PerFrame;
    if (teresa->mAlphaFixed12 >= teresa->mAlphaFixed12Max) {
        teresa->mAlphaFixed12PerFrame = -teresa->mAlphaFixed12PerFrame;
        teresa->mAlphaFixed12 = teresa->mAlphaFixed12Max * 2 - teresa->mAlphaFixed12;
    } else if (teresa->mAlphaFixed12 <= teresa->mAlphaFixed12Min) {
        teresa->mAlphaFixed12PerFrame = -teresa->mAlphaFixed12PerFrame;
        teresa->mAlphaFixed12 = teresa->mAlphaFixed12Min * 2 - teresa->mAlphaFixed12;
    }
    teresa->mModelAlpha = teresa->mAlphaFixed12 >> 12;
}

static inline void func_02094768_inline_2(s32 *p, s32 *q) {
    s32 k = *p;
    if (k > 0) {
        k += *q;
        if (k <= 0) {
            k = 0;
        }
        *p = k;
    } else if (k < 0) {
        k += *q;
        if (k >= 0) {
            k = 0;
        }
        *p = k;
    }
}

// Gives each Teresa two values from its place in the list: bit 0 and bit 1 of its index.
void InitTeresaObjects(MapObjectList *mapObjectList) {
    s32 i;
    Teresa *teresa;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (teresa = mapObjectList->mMapObjects[i]) != NULL; i++) {
        teresa->mNsbtpFrameIndex = i & 1;
        teresa->mMirror = (i / 2) & 1;
    }
}

s16 func_02094c0c(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2];
}

s32 func_02094bf0(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

s16 func_02094bd0(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2 + 1];
}

void UpdateTeresa(void *a, Teresa *teresa) {
    s32 t;
    s32 x;
    s32 anglePairSecond;
    u16 angleWobbleValue;
    s32 n;
    s32 yWobbleValue;
    Kart *kart;

    switch (teresa->mState) {
        case 1:
            t = teresa->mState1Timer;
            teresa->mState1Timer = t - 1;
            if (t <= 0) {
                teresa->mState1Timer = 0;
                func_02094768_inline(teresa);
                if (teresa->mAlphaFixed12 >= 0x2000) {
                    teresa->mState = 0;
                }
            }
            break;
        case 0:
            t = teresa->mState0Timer;
            teresa->mState0Timer = t - 1;
            if (t <= 0) {
                teresa->mState0Timer = 0;
                teresa->mAlphaFixed12 = teresa->mAlphaFixed12 - 0x1000;
                if (teresa->mAlphaFixed12 > 0) {
                    teresa->mModelAlpha = teresa->mAlphaFixed12 >> 12;
                } else {
                    teresa->mModelAlpha = 0;
                    ParkMapObject(&teresa->mUnk_00);
                    gUnparkedTeresaCount--;
                }
            } else {
                func_02094768_inline(teresa);
            }
            break;
    }
    if (teresa->mState0Timer <= 0) {
        return;
    }
    teresa->mAngleWobble.mAngle = teresa->mAngleWobble.mAngle + teresa->mAngleWobble.mAnglePerFrame;
    x = func_02094bf0(teresa->mAngleWobble.mAmplitude, func_02094c0c(teresa->mAngleWobble.mAngle));
    teresa->mAngleWobble.mUnk_08 = teresa->mAngleWobble.mMid + x - teresa->mAngleWobble.mValue;
    teresa->mAngleWobble.mValue = teresa->mAngleWobble.mValue + teresa->mAngleWobble.mUnk_08;
    func_02094768_inline_2(&teresa->mAngleWobble.mAmplitude, &teresa->mAngleWobble.mAmplitudePerFrame);
    func_02094768_inline_2(&teresa->mAngleWobble.mAnglePerFrame, &teresa->mAngleWobble.mUnk_1c);
    angleWobbleValue = teresa->mAngleWobble.mValue;
    teresa->mYWobble.mAngle = teresa->mYWobble.mAngle + teresa->mYWobble.mAnglePerFrame;
    anglePairSecond = func_02094bd0(teresa->mYWobble.mAngle);
    x = func_02094bf0(teresa->mYWobble.mAmplitude / 2, 0x1000 - anglePairSecond);
    teresa->mYWobble.mUnk_08 = teresa->mYWobble.mMid + x - teresa->mYWobble.mValue;
    teresa->mYWobble.mValue = teresa->mYWobble.mValue + teresa->mYWobble.mUnk_08;
    func_02094768_inline_2(&teresa->mYWobble.mAmplitude, &teresa->mYWobble.mAmplitudePerFrame);
    func_02094768_inline_2(&teresa->mYWobble.mAnglePerFrame, &teresa->mYWobble.mUnk_1c);
    yWobbleValue = teresa->mYWobble.mValue;
    n = teresa->mUnk_10c;
    if (GetCurrentCameraKind() == 2) {
        teresa->mUnk_00.mPos.x =
            teresa->mStartPos.x + (s32) (((s64) n * gPairsByAngle[(angleWobbleValue >> 4) * 2 + 1]) >> 12);
        teresa->mUnk_00.mPos.y = teresa->mStartPos.y + yWobbleValue;
        teresa->mUnk_00.mPos.z =
            teresa->mStartPos.z + (s32) (((s64) n * gPairsByAngle[(angleWobbleValue >> 4) * 2]) >> 12);
    } else {
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        teresa->mUnk_00.mPos.x =
            kart->mPos.x +
            (teresa->mStartPos.x + (s32) (((s64) n * gPairsByAngle[(angleWobbleValue >> 4) * 2 + 1]) >> 12));
        teresa->mUnk_00.mPos.y = teresa->mStartPos.y + yWobbleValue;
        teresa->mUnk_00.mPos.z =
            kart->mPos.z + (teresa->mStartPos.z + (s32) (((s64) n * gPairsByAngle[(angleWobbleValue >> 4) * 2]) >> 12));
    }
}

void CreateTeresaDrawList(void) {
    CreateMapObjectDrawList2(CreateTeresa, DrawTeresa, SetupDrawTeresa);
}

void CreateTeresaUpdateList(void) {
    CreateMapObjectUpdateList(InitTeresaObjects, UpdateTeresa, NULL);
}

void ClearTeresaTimers(void) {
    MapObjectList *mapObjectList;
    Teresa *teresa;
    s32 i;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_TERESA);
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (teresa = mapObjectList->mMapObjects[i]) != NULL; i++) {
        teresa->mState1Timer = 0;
        teresa->mState0Timer = 0;
    }
}

static inline u32 func_02094000_inline(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

static inline void func_02094000_inline_2(TeresaWobble *teresaWobble, u16 angle, s32 mid, s32 amplitude,
                                          s32 amplitudePerFrame, s32 anglePerFrame, s32 f) {
    teresaWobble->mAngle = angle;
    teresaWobble->mMid = mid;
    teresaWobble->mAmplitude = amplitude;
    teresaWobble->mAmplitudePerFrame = amplitudePerFrame;
    teresaWobble->mAnglePerFrame = anglePerFrame;
    teresaWobble->mUnk_1c = f;
}

void StartTeresa(Vec3 *startPos) {
    Teresa *teresa;
    Camera *chaseCamera;
    s32 alphaFixed12Max;
    s32 alphaFixed12PerFrame;
    s32 e;
    s16 c;
    u16 b;
    s32 k;
    s32 d;
    s32 f;

    teresa = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_TERESA));
    if (teresa == NULL) {
        return;
    }
    teresa->mModelAlpha = 0;
    teresa->mStartPos = *startPos;
    if (GetCurrentCameraKind() == 0) {
        chaseCamera = GetChaseCamera();
        e = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x30);
        c = (u16) (func_02094000_inline(&gRaceProgress->mLocalRandom, 0) >> 20);
        b = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x5555);
        k = FX_Atan2Idx(chaseCamera->mLookAt.z - chaseCamera->mPos.z, chaseCamera->mLookAt.x - chaseCamera->mPos.x) +
            b - 0x2aaa;
        func_02094000_inline_2(&teresa->mAngleWobble, func_02094000_inline(&gRaceProgress->mLocalRandom, 0x10000), k,
                               c + 0x1000, 0, e + 0x60, 0);
    } else {
        e = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x30);
        c = (u16) (func_02094000_inline(&gRaceProgress->mLocalRandom, 0) >> 20);
        func_02094000_inline_2(&teresa->mAngleWobble, func_02094000_inline(&gRaceProgress->mLocalRandom, 0x10000),
                               (u16) func_02094000_inline(&gRaceProgress->mLocalRandom, 0x10000), c + 0x1000, 0,
                               e + 0x60, 0);
    }
    d = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x80);
    f = func_02094000_inline(&gRaceProgress->mLocalRandom, 0xa000);
    func_02094000_inline_2(&teresa->mYWobble, 0, func_02094000_inline(&gRaceProgress->mLocalRandom, 0x19000) + 0x19000,
                           f + 0xa000, 0, d + 0x100, 0);
    teresa->mUnk_10c = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x3c000) + 0x3c000;
    alphaFixed12Max = func_02094000_inline(&gRaceProgress->mLocalRandom, 0xc000) + 0xe000;
    alphaFixed12PerFrame = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x200) + 0x400;
    teresa->mAlphaFixed12 = 0;
    teresa->mAlphaFixed12PerFrame = alphaFixed12PerFrame;
    teresa->mAlphaFixed12Min = 0x2000;
    teresa->mAlphaFixed12Max = alphaFixed12Max;
    if (GetCurrentCameraKind() == 2) {
        teresa->mState1Timer = 0;
        teresa->mState0Timer = 0xffff;
        teresa->mState = 0;
    } else {
        teresa->mState1Timer = (u16) func_02094000_inline(&gRaceProgress->mLocalRandom, 0x4b);
        teresa->mState0Timer = (u16) func_02094000_inline(&gRaceProgress->mLocalRandom, 0x96) + 0x12c;
        teresa->mState = 1;
    }
    gUnparkedTeresaCount++;
}

s32 GetUnparkedTeresaCount(void) {
    return gUnparkedTeresaCount;
}
