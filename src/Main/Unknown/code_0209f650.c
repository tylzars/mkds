#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0209bf70.h"

u16 FX_Atan2Idx(s32 a, s32 b);

static inline u16 func_0209f800_inline(u32 n) {
    RandomState64 *mapObjectRandom;
    u32 m;
    u32 r;

    if (n == 0x10000) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        return ((mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
    } else {
        mapObjectRandom = GetMapObjectRandom();
        m = (u16) n;
        if (m == 0) {
            r = 0;
        } else {
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            if (m == 0) {
                r = mapObjectRandom->mValue >> 32;
            } else {
                r = ((mapObjectRandom->mValue >> 32) * m) >> 32;
            }
        }
    }
    return r;
}

static inline void func_0209f6d8_inline(TownMonte *townMonte) {
    townMonte->mUnk_a4 += townMonte->mUnk_a8;
    townMonte->mUnk_a8 += 0x4000;
    if (townMonte->mUnk_a4 == 0) {
        townMonte->mUnk_a4 += townMonte->mUnk_a8;
        townMonte->mUnk_a8 += 0x4000;
    } else if (townMonte->mUnk_a4 >= 0x16c000) {
        townMonte->mUnk_a8 = 0x4000 - townMonte->mUnk_a8;
        townMonte->mMirror = townMonte->mMirror == 0 ? 1 : 0;
    }
}

static inline void func_0209fdb4_inline(Airship *airship) {
    s32 t;

    airship->mWobbleAngle = (u16) airship->mWobbleAngle + airship->mWobbleAnglePerFrame;
    airship->mUnk_b0 =
        airship->mWobbleMid +
        func_020a0028(airship->mWobbleAmplitude / 2, 0x1000 - func_020a0044((u16) airship->mWobbleAngle)) -
        airship->mWobbleOffset;
    airship->mWobbleOffset += airship->mUnk_b0;
    if (airship->mWobbleAmplitude > 0) {
        t = airship->mWobbleAmplitude + airship->mWobbleAmplitudePerFrame;
        if (t <= 0) {
            t = 0;
        }
        airship->mWobbleAmplitude = t;
    } else if (airship->mWobbleAmplitude < 0) {
        t = airship->mWobbleAmplitude + airship->mWobbleAmplitudePerFrame;
        if (t >= 0) {
            t = 0;
        }
        airship->mWobbleAmplitude = t;
    }
    if (airship->mWobbleAnglePerFrame > 0) {
        t = airship->mWobbleAnglePerFrame + airship->mUnk_c4;
        if (t <= 0) {
            t = 0;
        }
        airship->mWobbleAnglePerFrame = t;
    } else if (airship->mWobbleAnglePerFrame < 0) {
        t = airship->mWobbleAnglePerFrame + airship->mUnk_c4;
        if (t >= 0) {
            t = 0;
        }
        airship->mWobbleAnglePerFrame = t;
    }
}

static inline BOOL func_0209fdb4_inline_b(void) {
    s32 i;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (GetKartHighestLap((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateAirship(void *a, Airship *airship) {
    switch (airship->mState) {
        case 0:
            if (func_0209fdb4_inline_b() != FALSE) {
                airship->mState = 1;
            }
            break;
        case 1:
            airship->mUnk_a0 += 0x1000;
            if (airship->mUnk_a0 >= 0) {
                airship->mUnk_a0 = 0;
                airship->mState = 2;
            }
            func_0209fdb4_inline(airship);
            break;
        case 2:
            AdvanceGroupFollower(&airship->mUnk_c8);
            GetGroupFollowerCurvePosStep(&airship->mUnk_c8, &airship->mUnk_00.mPos, &airship->mUnk_00.mUnk_10);
            func_0209fdb4_inline(airship);
            break;
    }
    airship->mUnk_00.mAngle = FX_Atan2Idx(airship->mUnk_00.mUnk_10.x, airship->mUnk_00.mUnk_10.z);
}

void *CreateAirshipDrawList(void) {
    return CreateMapObjectDrawList1(CreateAirship, DrawAirship, NULL);
}

void *CreateAirshipUpdateList(void) {
    return CreateMapObjectUpdateList(InitAirshipObjects, UpdateAirship, NULL);
}

void func_0209fc78(MapObject *mapObject) {
    s32 i;

    i = mapObject->mCourseMapRow->mUnk_28;
    if (data_usa_0217b18c[i] == NULL) {
        data_usa_0217b18c[i] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
        *data_usa_0217b18c[i] = *data_usa_0217b18c[0];
    }
    switch (i) {
        case 0x10:
            data_usa_0217b18c[i]->mUnk_24 = 0x127;
            break;
        case 0x11:
            data_usa_0217b18c[i]->mUnk_24 = 0x100;
            break;
        case 0x12:
            data_usa_0217b18c[i]->mUnk_24 = 0x1da;
            break;
        default:
            data_usa_0217b18c[i]->mUnk_24 = func_0210bafc(0, 8, i);
            break;
    }
    mapObject->mKindData = data_usa_0217b18c[i];
}

void func_0209fc38(void) {
    s32 i;

    for (i = 0; i < 19; i++) {
        data_usa_0217b18c[i] = NULL;
    }
    data_usa_0217b18c[0] = (MapObjectKindData *) CreateEmptyMapObjectKindData();
}

void func_0209fc2c(void) {
    func_020e6c0c();
}

void CreateTownMonte(MapObjectModel *mapObjectModel) {
    mapObjectModel->mShadowModel = (void *) func_0209fc2c;
    SetMapObjectModelPolygonId(
        gTownMonte = CreateMapObjectModelNsbmdNsbtp(mapObjectModel, gTownMonteNsbmdName, gTownMonteNsbtpName), 0x3f);
}

void DrawTownMonte(void *a, TownMonte *townMonte) {
    s32 v;
    s32 d;
    MtxFx43 *h;

    d = (0x16c000 - townMonte->mUnk_a4) >> 12;
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    if (townMonte->mMirror != 0) {
        h = func_020e6c3c(&townMonte->mUnk_00.mPos, -d, d);
        func_01ff9048(0x19, h, 0xc);
    } else {
        h = func_020e6c3c(&townMonte->mUnk_00.mPos, d, d);
        func_01ff9048(0x19, h, 0xc);
    }
    func_01ff9048(0x1b, &townMonte->mUnk_00.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gTownMonte, townMonte->mNsbtpFrameIndex);
    func_0209bbd0(a, gTownMonte);
    DrawMapObjectModel(a, gTownMonte, townMonte);
}

void InitTownMonteObjects(Unk0209f800 *a) {
    TownMonte *townMonte;
    RandomState64 *mapObjectRandom;
    s32 i;
    s32 j;
    u32 nsbtpFrameCount;
    u16 m;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (townMonte = a->mUnk_00[i]) != NULL; i++) {
        townMonte->mUnk_a4 = 0;
        townMonte->mUnk_a8 = 0;
        nsbtpFrameCount = GetMapObjectModelNsbtpFrameCount(gTownMonte);
        townMonte->mNsbtpFrameIndex = func_0209f800_inline(nsbtpFrameCount);
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        m = ((mapObjectRandom->mValue >> 32) * 0x1a) >> 32;
        for (j = 0; j < m; j++) {
            func_0209f6d8_inline(townMonte);
        }
        if (townMonte->mUnk_00.mCourseMapRow->mUnk_28 != 0) {
            if (townMonte->mNsbtpFrameIndex == 0) {
                townMonte->mSoundId = 0x1a7;
            } else if (townMonte->mNsbtpFrameIndex == 1) {
                townMonte->mSoundId = 0x1a8;
            } else if (townMonte->mNsbtpFrameIndex == 2) {
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                townMonte->mSoundId = (u16) (((mapObjectRandom->mValue >> 32) * 2) >> 32) != 0 ? 0x1a7 : 0x1a8;
            }
        }
    }
}

void UpdateTownMonte(void *a, TownMonte *townMonte) {
    Unk0210b7a8 s;
    s32 t;
    u16 w;

    func_0209f6d8_inline(townMonte);
    if (townMonte->mSoundId == 0) {
        return;
    }
    if (townMonte->mUnk_00.mCourseMapRow->mUnk_28 != GetSeqVariableSinceChangeFrames(0)) {
        return;
    }
    w = townMonte->mSoundId;
    if (townMonte->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (townMonte->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        t = 2;
    } else if (townMonte->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        t = 3;
    } else {
        t = 4;
    }
    s.mSoundId = w;
    s.mPositionSource = &townMonte->mUnk_00.mPos;
    s.mUnk_08 = t;
    s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&townMonte->mUnk_00.mPos);
    func_0210b7a8(&s);
}

void *CreateTownMonteDrawList(void) {
    return CreateMapObjectDrawList2(CreateTownMonte, DrawTownMonte, NULL);
}

void *CreateTownMonteUpdateList(void) {
    return CreateMapObjectUpdateList(InitTownMonteObjects, UpdateTownMonte, NULL);
}

void CreateChandelier(void *a) {
    CreateMapObjectModelNsbcaAnimation(gChandelier = CreateMapObjectModelAnimated(a, gChandelierNsbmdName),
                                       gChandelierNsbcaName);
    SetMapObjectModelPolygonId(gChandelier, 0x3f);
}
