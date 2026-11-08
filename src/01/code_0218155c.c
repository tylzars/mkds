#include "01/code_0218155c.h"

#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020b4000.h"
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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108edc.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

MissionRunData *gMissionRunData;

void AddMissionRunMapObject(Unk02188950 *mapObject) {
    u8 kartCount;
    u16 entryIndex;

    kartCount = gRaceSetup->mKartCount;
    entryIndex = gMissionRunData->mMapObjectCount + kartCount;
    gMissionRunData->mMapObjects[entryIndex - kartCount] = mapObject;
    ClearStandingEliminationStatus(entryIndex);
    gMissionRunData->mMapObjectCount++;
}

Unk02188950 *GetMissionRunMapObject(int entryIndex) {
    return gMissionRunData->mMapObjects[entryIndex - gRaceSetup->mKartCount];
}

u8 func_ov001_02181b54(void) {
    return gRaceSetup->mKartCount;
}

u16 GetMissionRunMapObjectLastIndex(void) {
    return gMissionRunData->mMapObjectCount + gRaceSetup->mKartCount - 1;
}

void func_ov001_02181aa0(void) {
    MissionRunData *missionRunData;
    u32 countLimit;

    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
        return;
    }
    missionRunData = gMissionRunData;
    countLimit = GetMissionRunCountLimit();
    if (missionRunData->mCount >= countLimit) {
        return;
    }
    missionRunData->mCount = missionRunData->mCount + 1;
    func_02108edc(gMissionRunData->mCount, GetMissionRunCountLimit());
    switch (gRaceSetup->mMissionKind) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
            countLimit = GetMissionRunCountLimit();
            if (gMissionRunData->mCount >= countLimit) {
                FinishMissionRunKartWithEndKind0(gRaceSetup->mEntryIndex);
            }
            break;
    }
}

Vec3 *GetMissionRunKartPos(void) {
    return &gMissionRunData->mKartPos;
}

Vec3 *GetMissionRunPrevKartPos(void) {
    return &gMissionRunData->mPrevKartPos;
}

u16 GetMissionRunKartHeadingAngle(void) {
    return (gMissionRunData->mKartHeadingAngle);
}

u16 GetMissionRunPrevKartHeadingAngle(void) {
    return (gMissionRunData->mPrevKartHeadingAngle);
}

void CreateMissionRunData(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    gMissionRunData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x68);
    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    missionRunData = gMissionRunData;
    missionRunData->mPrevKartPos = kart->mPos;
    missionRunData->mKartPos = missionRunData->mPrevKartPos;
    missionRunData->mPrevKartHeadingAngle = kart->mHeadingAngle;
    missionRunData = gMissionRunData;
    missionRunData->mKartHeadingAngle = missionRunData->mPrevKartHeadingAngle;
}

void UpdateMissionRunData(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mUnk_48 & 0x200) == 0) {
        missionRunData = gMissionRunData;
        missionRunData->mPrevKartPos = missionRunData->mKartPos;
        missionRunData->mPrevKartHeadingAngle = missionRunData->mKartHeadingAngle;
        missionRunData = gMissionRunData;
        missionRunData->mKartPos = kart->mPos;
        missionRunData->mKartHeadingAngle = kart->mHeadingAngle;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
            if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex)) {
                gMissionRunData->mSinceHitCallbackFrames += 1;
                if (gMissionRunData->mSinceHitCallbackFrames > 0xf) {
                    gMissionRunData->mSinceHitCallbackFrames = 0;
                    CallKartHitCallbackForSelf(gRaceSetup->mEntryIndex);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 missionKind = gRaceSetup->mMissionKind;
        if (missionKind == 1 || missionKind == 5) {
            if (GetRaceUpdateFramesMod8() == 0) {
                missionRunData = gMissionRunData;
                if (missionRunData->mUnk_0c != 0) {
                    missionRunData->mUnk_0c -= 1;
                    missionRunData = gMissionRunData;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                        gMissionRunData->mUnk_06 += 1;
                    }
                    if (gMissionRunData->mUnk_20 != NULL) {
                        gMissionRunData->mUnk_20();
                    }
                    gMissionRunData->mTimer = 0;
                } else if (missionRunData->mUnk_0a != 0) {
                    missionRunData->mUnk_0a -= 1;
                    missionRunData = gMissionRunData;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                    }
                    if (gMissionRunData->mUnk_1c != NULL) {
                        gMissionRunData->mUnk_1c();
                    }
                    gMissionRunData->mTimer = 0;
                } else if (missionRunData->mPendingCountUp != 0) {
                    missionRunData->mPendingCountUp -= 1;
                    func_ov001_02181aa0();
                    if (gMissionRunData->mCountUpCallback != NULL) {
                        gMissionRunData->mCountUpCallback();
                    }
                }
            }
            missionRunData = gMissionRunData;
            if (missionRunData->mTimer != 0) {
                missionRunData->mTimer -= 1;
                missionRunData = gMissionRunData;
                if (missionRunData->mTimer == 0) {
                    if (missionRunData->mTimerEndCallback != NULL) {
                        missionRunData->mTimerEndCallback();
                    }
                }
            }
        }
    }
}

void func_ov001_02181844(u16 a, u16 b, u16 c, u16 d) {
    gMissionRunData->mUnk_10 = a;
    gMissionRunData->mUnk_12 = b;
    gMissionRunData->mUnk_14 = c;
    gMissionRunData->mUnk_16 = d;
}

s32 GetMissionRunTimer(void) {
    return (gMissionRunData->mTimer);
}

void SetMissionRunTimer(u32 timer) {
    gMissionRunData->mTimer = timer;
}

u32 GetMissionRunCount(void) {
    return (gMissionRunData->mCount);
}

u32 GetMissionRunCountLimit(void) {
    u32 countLimit = gRaceSetup->mUnk_37;
    if (countLimit == 0) {
        countLimit = 1;
    }
    return countLimit;
}

s32 func_ov001_02181800(void) {
    return (gMissionRunData->mUnk_06);
}

void func_ov001_021817e0(void) {
    if (gRaceSetup->mMissionKind == '\a') {
        func_ov001_02181aa0();
    }
}

void func_ov001_0218175c(s32 b) {
    RaceSetup *raceSetup = gRaceSetup;
    u32 missionKind = raceSetup->mMissionKind;
    if (missionKind == 3 || missionKind == 7 || missionKind == 0) {
        u32 a = raceSetup->mUnk_3c;
        if (a == 0 && raceSetup->mUnk_3e == 0 && raceSetup->mUnk_40 == 0 && raceSetup->mUnk_42 == 0 && b > 400 &&
            b < 500) {
            func_ov001_02181aa0();
            return;
        }
        if (b == a || b == raceSetup->mUnk_3e || b == raceSetup->mUnk_40 || b == raceSetup->mUnk_42) {
            func_ov001_02181aa0();
        }
    }
}

void func_ov001_0218173c(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_02181678(5);
    }
}

void func_ov001_0218171c(void) {
    if (gRaceSetup->mMissionKind == 4) {
        func_ov001_02181aa0();
    }
}

void func_ov001_021816fc(void) {
    if (gRaceSetup->mMissionKind == 0) {
        func_ov001_02181aa0();
    }
}

BOOL func_ov001_021816b4(void) {
    BalloonList *list;
    Balloon *balloon;
    s32 i;

    list = func_02100138(MAP_OBJECT_KIND_BALLOON);
    if (list != NULL) {
        for (i = 0; i < list->mObjectCount && (balloon = list->mObjects[i]) != NULL; i++) {
            if ((balloon->mUnk_00.mFlags & 0x100) == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void func_ov001_021816a8(UnkFunc *callback) {
    gMissionRunData->mCountUpCallback = callback;
}

void func_ov001_0218169c(UnkFunc *callback) {
    gMissionRunData->mUnk_1c = callback;
}

void func_ov001_02181690(UnkFunc *callback) {
    gMissionRunData->mUnk_20 = callback;
}

void func_ov001_02181678(u32 amount) {
    MissionRunData *missionRunData = gMissionRunData;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mUnk_0a += amount;
}

void func_ov001_02181660(u16 amount) {
    MissionRunData *missionRunData = gMissionRunData;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mUnk_0c += amount;
}

void func_ov001_02181630(short amount) {
    gMissionRunData->mUnk_06 += amount;
    if (gMissionRunData->mUnk_06 > GetMissionRunCountLimit()) {
        gMissionRunData->mUnk_06 = GetMissionRunCountLimit();
    }
}

void func_ov001_021815d0(s32 stepCount) {
    s32 i;

    for (i = 0; i < stepCount; i++) {
        if (++gMissionRunData->mPendingCountUp > GetMissionRunCountLimit()) {
            gMissionRunData->mPendingCountUp = GetMissionRunCountLimit();
            return;
        }
        if (gMissionRunData->mTimer == 0) {
            gMissionRunData->mTimer = gMissionRunData->mUnk_10;
        } else {
            gMissionRunData->mTimer += gMissionRunData->mUnk_14;
            if (gMissionRunData->mTimer > gMissionRunData->mUnk_12) {
                gMissionRunData->mTimer = gMissionRunData->mUnk_12;
            }
        }
    }
}

void func_ov001_0218155c(s32 stepCount) {
    s32 i;

    if ((u32) stepCount >= gMissionRunData->mUnk_06) {
        stepCount = gMissionRunData->mUnk_06;
    }
    for (i = 0; i < stepCount; i++) {
        gMissionRunData->mUnk_06--;
        if (++gMissionRunData->mPendingCountUp > GetMissionRunCountLimit()) {
            gMissionRunData->mPendingCountUp = GetMissionRunCountLimit();
            return;
        }
        if (gMissionRunData->mTimer == 0) {
            gMissionRunData->mTimer = gMissionRunData->mUnk_10;
        } else {
            gMissionRunData->mTimer += gMissionRunData->mUnk_16;
            if (gMissionRunData->mTimer > gMissionRunData->mUnk_12) {
                gMissionRunData->mTimer = gMissionRunData->mUnk_12;
            }
        }
    }
}
