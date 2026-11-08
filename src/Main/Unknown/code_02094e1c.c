#include "Main/Unknown/code_02094e1c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void func_020954e4(u32 mapObject) {
    u32 value0 = mapObject;
    u32 value1;
    u32 value2;
    value2 = value0;
    value1 = *(const u32 *) ((value2) + (156));
    value0 = MAP_OBJECT_KIND_TERESA;
    value1 = *(const s16 *) ((value1) + (42));
    CreateParkedMapObjects(value0, value1, (void *) value2);
}

static inline u32 func_02095228_inline(RandomState64 *randomState64, u32 n) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (n == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * n) >> 32;
}

static inline u16 func_020952dc_inline(u32 n) {
    RandomState64 *randomState64;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        randomState64 = &gRaceProgress->mLocalRandom;
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        return (randomState64->mValue >> 32) * 0x10000 >> 32;
    }
    randomState64 = &gRaceProgress->mLocalRandom;
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (m == 0) {
            t = randomState64->mValue >> 32;
        } else {
            t = ((randomState64->mValue >> 32) * m) >> 32;
        }
    }
    return t;
}

void func_020952dc(Unk02094e8c *a, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit, s32 timerLimit) {
    s32 i;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 distance;
    u16 angle;
    Vec3 position;

    if (GetUnparkedTeresaCount() < teresaCountLimit) {
        k = i = 0;
        for (; i < spawnCount; i++) {
            if (distanceLimit > 0) {
                f = 0.5f + (distanceLimit << 12);
            } else {
                f = (distanceLimit << 12) - 0.5f;
            }
            z = 0;
            y = a->mUnk_00.mPos.y;
            x = 0;
            distance = NextRandomBelow(GetRaceLocalRandom(), (s32) f);
            angle = func_020951b4(GetRaceLocalRandom());
            position.x = x + func_0209518c(distance, func_0209519c(angle));
            position.y = y + NextRandomBelow(GetRaceLocalRandom(), k);
            position.z = z + func_0209518c(distance, func_0209516c(angle));
            StartTeresa(&position);
        }
        a->mUnk_a8 = func_020952dc_inline((u16) timerLimit);
    }
}

void func_02095228(Unk02095228 *mapObjectList) {
    s32 i;
    Unk02094e8c *o;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mUnk_04 && (o = mapObjectList->mUnk_00[i]) != NULL; i++) {
        o->mUnk_a0 = (u16) func_02095228_inline(&gRaceProgress->mLocalRandom, 0xf);
    }
}

RandomState64 *GetRaceLocalRandom(void) {
    return &gRaceProgress->mLocalRandom;
}

u16 func_020951b4(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return ((randomState64->mValue >> 32) * 0x10000) >> 32;
}

s16 func_0209519c(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209518c(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}

s16 func_0209516c(s32 a) {
    return gPairsByAngle[(a >> 4) * 2 + 1];
}

void func_02094e8c(void *a, Unk02094e8c *o) {
    s32 t;
    s32 c;
    s32 e;
    s32 deltaX;
    s32 deltaZ;
    s32 i;
    BOOL k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 distance;
    u16 angle;
    Kart *kart;
    Vec3 position;
    Vec3 *kartPos;

    t = o->mUnk_a0;
    o->mUnk_a0 = t - 1;
    if (t <= 0) {
        o->mUnk_a0 = 0xf;
        c = o->mUnk_00.mCourseMapRow->mUnk_28;
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        e = c << 12;
        kartPos = &kart->mPos;
        deltaX = kartPos->x - o->mUnk_00.mPos.x;
        deltaZ = kartPos->z - o->mUnk_00.mPos.z;
        if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) e * e) {
            o->mUnk_a4 = TRUE;
        } else {
            o->mUnk_a4 = FALSE;
        }
    }
    switch (o->mUnk_ac) {
        case 0:
            k = FALSE;
            if (GetCurrentCameraKind() == 2) {
                for (i = 0; i < o->mUnk_00.mCourseMapRow->mUnk_2a; i++) {
                    if (o->mUnk_00.mCourseMapRow->mUnk_28 > 0) {
                        f = 0.5f + (o->mUnk_00.mCourseMapRow->mUnk_28 << 12);
                    } else {
                        f = (o->mUnk_00.mCourseMapRow->mUnk_28 << 12) - 0.5f;
                    }
                    z = o->mUnk_00.mPos.z;
                    y = o->mUnk_00.mPos.y;
                    x = o->mUnk_00.mPos.x;
                    distance = NextRandomBelow(GetRaceLocalRandom(), (s32) f);
                    angle = func_020951b4(GetRaceLocalRandom());
                    position.x = x + func_0209518c(distance, func_0209519c(angle));
                    position.y = y + NextRandomBelow(GetRaceLocalRandom(), k);
                    position.z = z + func_0209518c(distance, func_0209516c(angle));
                    StartTeresa(&position);
                }
            }
            o->mUnk_ac = 1;
        case 1:
            if (GetCurrentCameraKind() == 2) {
                break;
            }
            if (o->mUnk_a4 == FALSE) {
                break;
            }
            if (GetCurrentCameraKind() != 0) {
                func_020952dc(o, 0x1e, 0x14, 0x1f4, 4);
            } else {
                func_020952dc(o, 6, 4, 0xa, 0x14);
            }
            o->mUnk_ac = 2;
            break;
        case 2:
            t = o->mUnk_a8;
            o->mUnk_a8 = t - 1;
            if (t > 0) {
                break;
            }
            if (o->mUnk_a4 != FALSE) {
                if (GetCurrentCameraKind() != 0) {
                    func_020952dc(o, 0x1e, 1, 0x1f4, 4);
                } else {
                    func_020952dc(o, 6, 1, 0xa, 0x14);
                }
            } else {
                ClearTeresaTimers();
                o->mUnk_ac = 1;
            }
            break;
    }
    if (GetUnparkedTeresaCount() > 0) {
        func_020d26e0(GetKart((u16) gRaceSetup->mEntryIndex), 0x11e);
    }
}

u32 func_02094e3c(void) {
    s32 mode;

    mode = gRaceSetup->mMode;
    if (mode == MODE_VS || mode == 5) {
        if (GetCurrentCameraKind() == 0) {
            return 0;
        }
    }
    return CreateEmptyMapObjectKindData();
}

void func_02094e1c(void) {
    CreateMapObjectUpdateList(func_02095228, func_02094e8c, NULL);
}
