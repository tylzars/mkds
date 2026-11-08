#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209dd40.h"
#include "Main/Unknown/code_0209dd44.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_0209decc.h"

void InitSunFireball(u32 mapObject) {
    u32 flagBitsAddress = ((u32) (&data_021565e4));
    u32 flags = (*(u16 *) ((mapObject) + (2)));
    u32 flagBits = (*(u16 *) ((flagBitsAddress) + (0)));
    u32 newFlags = ((flags) | (flagBits));
    u32 unused1;
    u32 unused2;
    *(u16 *) ((mapObject) + (2)) = newFlags;
    ParkMapObject((void *) mapObject);
    CreateMapObjectSoundSourceFalloff2((MapObject *) mapObject);
}

u8 CollideKartWithSunFireball(SunFireball *sunFireball, Kart *kart, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && sunFireball->mState <= 1) {
        sunFireball->mUnk_00.mFlags |= data_usa_021565d8;
        sunFireball->mUnk_00.mFlags |= data_usa_021565dc;
        sunFireball->mState = 2;
        sunFireball->mTimer = 0x168;
        sunFireball->mUnk_00.mUnk_10.x = 0;
        sunFireball->mUnk_00.mUnk_10.y = 0x3000;
        sunFireball->mUnk_00.mUnk_10.z = 0;
        sunFireball->mUnk_bc->mUnk_70 = 0x23;
        sunFireball->mUnk_c0->mUnk_70 = 0x23;
        sunFireball->mUnk_bc->mUnk_80 = 5;
        sunFireball->mUnk_c0->mUnk_80 = 5;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            sunFireball->mUnk_00.mDistanceSquaredAndFlags |= data_usa_021565e0;
        }
        StartSoundIfKartStarOrKiller(&sunFireball->mUnk_00, kart);
    }
    return v;
}

u8 CollideItemObjectWithSunFireball(SunFireball *sunFireball, ItemObject *itemObject, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && sunFireball->mState <= 1) {
        sunFireball->mUnk_00.mFlags |= data_usa_021565d8;
        sunFireball->mUnk_00.mFlags |= data_usa_021565dc;
        sunFireball->mState = 2;
        sunFireball->mTimer = 0x168;
        sunFireball->mUnk_00.mUnk_10.x = 0;
        sunFireball->mUnk_00.mUnk_10.y = 0x3000;
        sunFireball->mUnk_00.mUnk_10.z = 0;
        sunFireball->mUnk_bc->mUnk_70 = 0x23;
        sunFireball->mUnk_c0->mUnk_70 = 0x23;
        sunFireball->mUnk_bc->mUnk_80 = 5;
        sunFireball->mUnk_c0->mUnk_80 = 5;
    }
    return v;
}

u32 func_0209dd40(u32 p0) {
    return p0;
}

static inline u32 func_0209d84c_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void UpdateSunFireball(void *a, SunFireball *sunFireball) {
    Vec3 v;
    Unk0210b7a8 soundRequest;
    u32 f;
    s32 t;
    s32 k;
    s32 randomValue;

    switch (sunFireball->mState) {
        case 0:
            if (sunFireball->mState0Timer-- <= 0) {
                sunFireball->mState = 1;
                soundRequest.mSoundId = 0x195;
                soundRequest.mPositionSource = &sunFireball->mUnk_00.mPos;
                soundRequest.mUnk_08 = 2;
                soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sunFireball->mUnk_00.mPos);
                func_0210b7a8(&soundRequest);
            }
            break;
        case 1:
            if (sunFireball->mTimer-- != 0) {
                t = sunFireball->mUnk_00.mUnk_10.y - 0x19a;
                if (t <= -0x8000) {
                    t = -0x8000;
                }
                sunFireball->mUnk_00.mUnk_10.y = t;
                VEC_Add(&sunFireball->mUnk_00.mPos, &sunFireball->mUnk_00.mUnk_10, &sunFireball->mUnk_00.mPos);
                if (sunFireball->mTimer > 0x78 && sunFireball->mUnk_00.mUnk_10.y < 0) {
                    if (func_01ffdee4(&sunFireball->mUnk_00.mPos, NULL, 0, sunFireball->mUnk_00.mExtent.x, 8, -2, &v,
                                      NULL, NULL, &f, NULL, NULL, NULL, NULL) != 0 &&
                        (f & 0x3f77ef) != 0) {
                        VEC_Add(&sunFireball->mUnk_00.mPos, &v, &sunFireball->mUnk_00.mPos);
                        t = sunFireball->mUnk_00.mPos.x - sunFireball->mStartPos.x;
                        k = sunFireball->mUnk_00.mPos.z - sunFireball->mStartPos.z;
                        if ((s64) t * t + (s64) k * k < 0x2710000000LL) {
                            randomValue = (u16) (((u64) func_0209d84c_inline(GetMapObjectRandom()) * 0x10000) >> 32);
                            k = (randomValue >> 4) * 2;
                            sunFireball->mUnk_00.mUnk_10.x = ((s64) gPairsByAngle[k] * 0x1800) >> 12;
                            sunFireball->mUnk_00.mUnk_10.z = ((s64) gPairsByAngle[k + 1] * 0x1800) >> 12;
                        } else {
                            sunFireball->mUnk_00.mUnk_10.x = -sunFireball->mUnk_00.mUnk_10.x;
                            sunFireball->mUnk_00.mUnk_10.z = -sunFireball->mUnk_00.mUnk_10.z;
                        }
                        sunFireball->mUnk_00.mUnk_10.y = 0x2c00;
                        sunFireball->mState0Timer += 0x3c;
                        sunFireball->mState = 0;
                        sunFireball->mUnk_bc->mUnk_70 = 0x2a;
                        sunFireball->mUnk_c0->mUnk_70 = 0x2a;
                        sunFireball->mUnk_bc->mUnk_80 = 6;
                        sunFireball->mUnk_c0->mUnk_80 = 6;
                    }
                }
            } else {
                ParkMapObject(&sunFireball->mUnk_00);
                if (sunFireball->mUnk_bc != NULL) {
                    func_0208b6b0((void **) &sunFireball->mUnk_bc);
                }
                if (sunFireball->mUnk_c0 != NULL) {
                    func_0208b6b0((void **) &sunFireball->mUnk_c0);
                }
            }
            break;
        case 2:
            t = sunFireball->mUnk_00.mUnk_10.y - 0xcd;
            if (t <= -0x2000) {
                t = -0x2000;
            }
            sunFireball->mUnk_00.mUnk_10.y = t;
            sunFireball->mUnk_00.mPos.y = sunFireball->mUnk_00.mPos.y + sunFireball->mUnk_00.mUnk_10.y;
            if (sunFireball->mUnk_00.mUnk_10.y < 0) {
                sunFireball->mMoveAngle = ((u64) func_0209d84c_inline(GetMapObjectRandom()) * 0x10000) >> 32;
                sunFireball->mState = 3;
            }
            break;
        case 3:
            if (sunFireball->mTimer-- != 0) {
                t = sunFireball->mUnk_00.mUnk_10.y - 0xcd;
                if (t <= -0x2000) {
                    t = -0x2000;
                }
                sunFireball->mUnk_00.mUnk_10.y = t;
                sunFireball->mMoveAngle += 0xe39;
                sunFireball->mUnk_00.mPos.x =
                    sunFireball->mUnk_00.mPos.x +
                    (s32) (((s64) gPairsByAngle[(sunFireball->mMoveAngle >> 4) * 2] * 0x2000) >> 12);
                sunFireball->mUnk_00.mPos.z =
                    sunFireball->mUnk_00.mPos.z +
                    (s32) (((s64) gPairsByAngle[(sunFireball->mMoveAngle >> 4) * 2 + 1] * 0x2000) >> 12);
                sunFireball->mUnk_00.mPos.y = sunFireball->mUnk_00.mPos.y + sunFireball->mUnk_00.mUnk_10.y;
            } else {
                ParkMapObject(&sunFireball->mUnk_00);
                if (sunFireball->mUnk_bc != NULL) {
                    func_0208b6b0((void **) &sunFireball->mUnk_bc);
                }
                if (sunFireball->mUnk_c0 != NULL) {
                    func_0208b6b0((void **) &sunFireball->mUnk_c0);
                }
            }
            break;
    }
    if ((sunFireball->mUnk_00.mFlags & 0x12) == 0) {
        if (sunFireball->mUnk_bc != NULL) {
            PlaceEffect(sunFireball->mUnk_bc, &sunFireball->mUnk_00.mPos);
            sunFireball->mUnk_bc->mUnk_24 &= ~2;
        }
        if (sunFireball->mUnk_c0 != NULL) {
            PlaceEffect(sunFireball->mUnk_c0, &sunFireball->mUnk_00.mPos);
            sunFireball->mUnk_c0->mUnk_24 &= ~2;
        }
    } else {
        if (sunFireball->mUnk_bc != NULL) {
            sunFireball->mUnk_bc->mUnk_24 |= 2;
        }
        if (sunFireball->mUnk_c0 != NULL) {
            sunFireball->mUnk_c0->mUnk_24 |= 2;
        }
    }
}

void CreateSunFireballKindData(void) {
    MapObjectKindData *kindData;

    kindData = func_0209bf70(&CollideKartWithSunFireball, &CollideItemObjectWithSunFireball, NULL, 1, 0, 0x18d);
    kindData->mUnk_28 = 0x196;
}

void CreateSunFireballUpdateList(void) {
    CreateMapObjectUpdateList(&func_0209dd40, &UpdateSunFireball, NULL);
}

void StartSunFireball(Vec3 *startPos, Vec3 *direction) {
    SunFireball *sunFireball;

    sunFireball = UnparkFirstParkedMapObject(func_02100138(0x1ae));
    if (sunFireball == NULL) {
        return;
    }
    sunFireball->mTimer = 0x1c2;
    sunFireball->mStartPos = *startPos;
    sunFireball->mUnk_00.mPos = sunFireball->mStartPos;
    sunFireball->mUnk_00.mMatrix.mUnk_00[2] = *direction;
    sunFireball->mUnk_00.mUnk_10.x = ((s64) direction->x * 0x2000) >> 12;
    sunFireball->mUnk_00.mUnk_10.y = ((s64) direction->y * 0x2000) >> 12;
    sunFireball->mUnk_00.mUnk_10.z = ((s64) direction->z * 0x2000) >> 12;
    sunFireball->mState0Timer = 0;
    sunFireball->mState = 0;
    sunFireball->mUnk_bc = StartEffect(0x35, &sunFireball->mUnk_00.mPos);
    sunFireball->mUnk_c0 = StartEffect(0x34, &sunFireball->mUnk_00.mPos);
    sunFireball->mUnk_bc->mUnk_70 = 0x15;
    sunFireball->mUnk_c0->mUnk_70 = 0x15;
    sunFireball->mUnk_bc->mUnk_80 = 3;
    sunFireball->mUnk_c0->mUnk_80 = 3;
    sunFireball->mUnk_00.mFlags &= ~1;
    sunFireball->mUnk_00.mFlags &= ~8;
    sunFireball->mUnk_00.mFlags &= ~2;
    sunFireball->mUnk_00.mFlags &= ~8;
    sunFireball->mUnk_00.mAlpha = 0x1f;
}
