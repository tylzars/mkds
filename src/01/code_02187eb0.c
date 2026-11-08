#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02042044.h"

Kart *GetEntryKartInRange(Unk02188950 *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && IsPointInRange(mapObject, &kart->mPos, radius, halfAngle) != FALSE &&
        (kart->mUnk_48 & 0x40) == 0) {
        return kart;
    }
    return NULL;
}

Kart *GetEntryKartInAngleRange(Unk02188950 *mapObject, s32 angleOffset, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mUnk_48 & 0x40) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || func_ov001_02188f04(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 ||
                func_ov001_02188eac(mapObject, mapObject->mAngle + angleOffset, &kart->mPos, halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

Kart *GetEntryKartFacingObject(Unk02188950 *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mUnk_48 & 0x40) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || func_ov001_02188f04(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 ||
                func_ov001_02188eac(mapObject, kart->mHeadingAngle + 0x8000, &kart->mPos, halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

CourseMapGroupEntry *GetCurrentGroupEntry(Unk02188950 *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex);
    }
    return NULL;
}

s32 func_ov001_02187f7c(Unk02188950 *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mUnk_0e;
    }
    return 0;
}

s32 func_ov001_02187f38(Unk02188950 *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mUnk_10;
    }
    return 0;
}

CourseMapGroupEntry *GetNextGroupEntry(Unk02188950 *mapObject) {
    CourseMap *courseMap = gCourseMap;
    s32 nextEntryIndex;

    if (mapObject->mEntryGroupIndex < courseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= courseMap->mEntryGroups[(u16) mapObject->mEntryGroupIndex].mEntryCount) {
            nextEntryIndex = 0;
        }
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, nextEntryIndex);
    }
    return NULL;
}

void func_ov001_02187eb0(Unk02188950 *mapObject) {
    CourseMap *courseMap;
    CourseMapEntryGroup *entryGroup;
    s32 groupIndex;
    s32 entryIndex;

    courseMap = gCourseMap;
    groupIndex = mapObject->mEntryGroupIndex;
    if (groupIndex < courseMap->mEntryGroupCount) {
        entryGroup = &courseMap->mEntryGroups[(u16) groupIndex];
        entryIndex = mapObject->mEntryIndex - 1;
        if (entryIndex <= 0) {
            entryIndex = entryGroup->mEntryCount - 1;
        }
        mapObject->mEntryIndex = entryIndex;
    }
}
