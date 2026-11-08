#include "Main/Unknown/code_020b502c.h"
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

#include "code_02147cd8.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02102674.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020b681c.h"
#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

const Vec3 data_02156874 = {0, 0, 0};

void InitRaceHudSubScreenProjection(void) {
    UnkPair020b502c state0Min;
    UnkPair020b502c state0Max;
    UnkPair020b502c courseMin;
    UnkPair020b502c courseMax;
    UnkPair020b502c bg3Min;
    UnkPair020b502c bg3Max;

    gRaceHudSubScreenProjection = HeapAlloc(RaceHudSubScreenGetCurrentHeap(), 0x9c);
    gRaceHudSubScreenProjection->mCenter.mUnk_00 = 0;
    gRaceHudSubScreenProjection->mCenter.mUnk_04 = 0;
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 = 0;
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 = 0;
    gRaceHudSubScreenProjection->mHalfSize = 0;
    gRaceHudSubScreenProjection->mAnglePairSecond = 0;
    gRaceHudSubScreenProjection->mAnglePairFirst = 0;
    gRaceHudSubScreenProjection->mAnglePairSecondScaled = 0;
    gRaceHudSubScreenProjection->mAnglePairFirstScaled = 0;
    GetRaceHudSubScreenState0MinMax(&state0Min, &state0Max);
    gRaceHudSubScreenProjection->mState0Min = state0Min;
    gRaceHudSubScreenProjection->mState0Max = state0Max;
    gRaceHudSubScreenProjection->mState0InverseX = FX_InvFx64c(state0Max.mUnk_00 - state0Min.mUnk_00);
    gRaceHudSubScreenProjection->mState0InverseZ = FX_InvFx64c(state0Max.mUnk_04 - state0Min.mUnk_04);
    GetRaceHudSubScreenCourseMinMax(&courseMin, &courseMax);
    gRaceHudSubScreenProjection->mCourseMin = courseMin;
    gRaceHudSubScreenProjection->mCourseMax = courseMax;
    gRaceHudSubScreenProjection->mCourseInverseX = FX_InvFx64c(courseMax.mUnk_00 - courseMin.mUnk_00);
    gRaceHudSubScreenProjection->mCourseInverseZ = FX_InvFx64c(courseMax.mUnk_04 - courseMin.mUnk_04);
    gRaceHudSubScreenProjection->mUnk_28 =
        MulFixed12NoRound(FX_Div(courseMax.mUnk_00 - courseMin.mUnk_00, 0x200000), 0xb0000);
    GetRaceHudSubScreenBg3MinMax(&bg3Min, &bg3Max);
    gRaceHudSubScreenProjection->mBg3Min = bg3Min;
    gRaceHudSubScreenProjection->mBg3Max = bg3Max;
    gRaceHudSubScreenProjection->mBg3InverseX = FX_InvFx64c(bg3Max.mUnk_00 - bg3Min.mUnk_00);
    gRaceHudSubScreenProjection->mBg3InverseZ = FX_InvFx64c(bg3Max.mUnk_04 - bg3Min.mUnk_04);
    gRaceHudSubScreenProjection->mScrollTimer = 0;
    gRaceHudSubScreenProjection->mScrollPosition = data_02156874;
}

u32 ClearRaceHudSubScreenProjection(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gRaceHudSubScreenProjection;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

BOOL IsCourseWithMap2DLocal3(void) {
    BOOL result = FALSE;

    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_OLD_YOSHI_GC:
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_OLD_LUIGI_GC:
        case COURSE_ID_OLD_FRAPPE_64:
        case COURSE_ID_CLOCK:
        case COURSE_ID_MANSION:
        case COURSE_ID_AIRSHIP:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_HYUDORO_64:
        case COURSE_ID_RIDGE:
        case COURSE_ID_MARIO:
        case COURSE_ID_GARDEN:
        case COURSE_ID_DESERT:
        case COURSE_ID_TOWN:
        case COURSE_ID_SNOW:
        case COURSE_ID_PINBALL:
        case COURSE_ID_STADIUM:
        case COURSE_ID_OLD_KINOKO_GC:
        case COURSE_ID_OLD_SKY_AGB:
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            result = TRUE;
            break;
    }
    return result;
}

BOOL IsCourseWithSubBg3CntBit13(void) {
    BOOL result = FALSE;

    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_OLD_YOSHI_GC:
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_OLD_FRAPPE_64:
        case COURSE_ID_OLD_HYUDORO_64:
        case COURSE_ID_RIDGE:
        case COURSE_ID_MARIO:
        case COURSE_ID_GARDEN:
        case COURSE_ID_DESERT:
        case COURSE_ID_STADIUM:
        case COURSE_ID_OLD_SKY_AGB:
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            result = TRUE;
            break;
    }
    return result;
}

// Only state 1, which takes the angle from the camera, also clears the scroll timer.
u16 GetSubScreenAngleAndClearScrollTimer(void) {
    u16 angle = 0;
    Camera *camera;
    s32 a;

    switch (GetRaceHudSubScreenState()) {
        case 1:
            if (RaceHudSubScreenGetCurrentMode() == MODE_BATTLE) {
                camera = GetCurrentCamera();
            } else {
                camera = GetChaseCamera();
            }
            a = FX_Atan2Idx(camera->mViewMatrix.mUnk_00[2].z, camera->mViewMatrix.mUnk_00[0].z);
            angle = (0x14000 - a) % 0x10000;
            gRaceHudSubScreenProjection->mScrollTimer = 0;
            break;
        case 2:
            angle = 0;
            break;
        case 3:
            a = GetFixed12Whole(func_020b57e4()->mUnk_10);
            angle = (a << 16) / 360 + 0x8000;
            break;
        default:
            break;
    }
    return angle;
}

u16 GetRaceHudSubScreenKartAngle(s32 kartIndex) {
    return (0x18000 - GetKartHeadingAngle(kartIndex)) % 0x10000;
}

void ComputeSubScreenState0KartPosition(s32 kartIndex, UnkPair020b502c *out) {
    UnkPair020b502c state0Min = gRaceHudSubScreenProjection->mState0Min;
    Vec3 kartPos;

    GetKartPos(&kartPos, (u8) kartIndex);
    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_KINOKO_GC:
            if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
                out->mUnk_00 = GetFixed12Whole(
                                   MulFixed12NoRound(0x80000, MulFx64c(state0Min.mUnk_00 - kartPos.z,
                                                                       gRaceHudSubScreenProjection->mState0InverseX))) +
                               0xf8;
            } else {
                out->mUnk_00 = GetFixed12Whole(
                                   MulFixed12NoRound(0x80000, MulFx64c(kartPos.z - state0Min.mUnk_00,
                                                                       gRaceHudSubScreenProjection->mState0InverseX))) +
                               0x78;
            }
            out->mUnk_04 =
                GetFixed12Whole(MulFixed12NoRound(
                    0x98000, MulFx64c(kartPos.x - state0Min.mUnk_04, gRaceHudSubScreenProjection->mState0InverseZ))) +
                0x28;
            break;
        case COURSE_ID_BANK:
            if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
                out->mUnk_00 = GetFixed12Whole(
                                   MulFixed12NoRound(0x80000, MulFx64c(state0Min.mUnk_00 - kartPos.z,
                                                                       gRaceHudSubScreenProjection->mState0InverseX))) +
                               0xf8;
            } else {
                out->mUnk_00 = GetFixed12Whole(
                                   MulFixed12NoRound(0x80000, MulFx64c(kartPos.z - state0Min.mUnk_00,
                                                                       gRaceHudSubScreenProjection->mState0InverseX))) +
                               0x78;
            }
            out->mUnk_04 =
                GetFixed12Whole(MulFixed12NoRound(
                    0x98000, MulFx64c(kartPos.x - state0Min.mUnk_04, gRaceHudSubScreenProjection->mState0InverseZ))) +
                0x28;
            break;
        default:
            if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
                out->mUnk_00 = GetFixed12Whole(
                                   MulFixed12NoRound(0x80000, MulFx64c(state0Min.mUnk_00 - kartPos.x,
                                                                       gRaceHudSubScreenProjection->mState0InverseX))) +
                               0xf8;
            } else {
                out->mUnk_00 = GetFixed12Whole(
                                   MulFixed12NoRound(0x80000, MulFx64c(kartPos.x - state0Min.mUnk_00,
                                                                       gRaceHudSubScreenProjection->mState0InverseX))) +
                               0x78;
            }
            out->mUnk_04 =
                GetFixed12Whole(MulFixed12NoRound(
                    0x98000, MulFx64c(kartPos.z - state0Min.mUnk_04, gRaceHudSubScreenProjection->mState0InverseZ))) +
                0x28;
            break;
    }
}

void ComputeRaceHudSubScreenCoursePosition(const Vec3 *pos, UnkPair020b502c *out) {
    UnkPair020b502c courseMin = gRaceHudSubScreenProjection->mCourseMin;

    out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
        0x200000, MulFx64c(pos->x - courseMin.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX)));
    out->mUnk_04 = GetFixed12Whole(MulFixed12NoRound(
        0x200000, MulFx64c(pos->z - courseMin.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ)));
}

BOOL IsRaceHudSubScreenPairNearCenter(const UnkPair020b502c *position) {
    UnkPair020b502c centerWhole = gRaceHudSubScreenProjection->mCenterWhole;
    s32 halfSize = gRaceHudSubScreenProjection->mHalfSize;

    if (position->mUnk_00 - halfSize < centerWhole.mUnk_00 && centerWhole.mUnk_00 < position->mUnk_00 + halfSize &&
        position->mUnk_04 - halfSize < centerWhole.mUnk_04 && centerWhole.mUnk_04 < position->mUnk_04 + halfSize) {
        return TRUE;
    }
    return FALSE;
}

void ComputeRaceHudSubScreenKartPosition(s32 kartIndex, UnkPair020b502c *out, s32 v1) {
    UnkPair020b502c center = gRaceHudSubScreenProjection->mCenter;
    s32 centerY = center.mUnk_04;
    s32 pairSecondScaled = gRaceHudSubScreenProjection->mAnglePairSecondScaled;
    s32 pairFirstScaled = gRaceHudSubScreenProjection->mAnglePairFirstScaled;
    UnkPair020b502c courseMin = gRaceHudSubScreenProjection->mCourseMin;
    Vec3 kartPos;
    s32 projectedX;
    s32 projectedY;
    s32 dx;
    s32 dy;

    GetKartPos(&kartPos, (u8) kartIndex);
    projectedX = MulFixed12NoRound(
        0x200000, MulFx64c(kartPos.x - courseMin.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX));
    projectedY = MulFixed12NoRound(
        0x200000, MulFx64c(kartPos.z - courseMin.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ));
    if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
        dy = projectedY - centerY;
        dx = projectedX - center.mUnk_00;
        out->mUnk_00 =
            GetFixed12Whole(MulFixed12NoRound(-pairSecondScaled, dx) + MulFixed12NoRound(pairFirstScaled, dy)) + 0x80;
        out->mUnk_04 =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, dy)) + 0x60;
    } else {
        dx = projectedX - center.mUnk_00;
        dy = projectedY - centerY;
        out->mUnk_00 =
            GetFixed12Whole(MulFixed12NoRound(pairSecondScaled, dx) - MulFixed12NoRound(pairFirstScaled, dy)) + 0x80;
        out->mUnk_04 =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, dy)) + 0x60;
    }
}

static inline s32 ClearFixed12Fraction(s32 value) {
    float wholePart;

    if (GetFixed12Whole(value) > 0) {
        wholePart = 0.5f + (GetFixed12Whole(value) << 12);
    } else {
        wholePart = (GetFixed12Whole(value) << 12) - 0.5f;
    }
    return wholePart;
}

BOOL ComputeRaceHudSubScreenPosition(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 requireNearCenter,
                                     s32 exactCenter) {
    UnkPair020b502c center = gRaceHudSubScreenProjection->mCenter;
    s32 pairSecondScaled = gRaceHudSubScreenProjection->mAnglePairSecondScaled;
    s32 pairFirstScaled = gRaceHudSubScreenProjection->mAnglePairFirstScaled;
    UnkPair020b502c courseMin = gRaceHudSubScreenProjection->mCourseMin;
    s32 centerX;
    s32 centerY;
    s32 dx;
    s32 projectedX;
    s32 projectedY;
    s32 dy;
    s32 e;
    s32 screenX;
    s32 screenY;
    UnkPair020b502c centerWhole;
    s32 halfSize;
    s32 wholeX;
    s32 wholeY;

    projectedX =
        MulFixed12NoRound(0x200000, MulFx64c(pos->x - courseMin.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX));
    projectedY =
        MulFixed12NoRound(0x200000, MulFx64c(pos->z - courseMin.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ));
    if (requireNearCenter != 0) {
        centerWhole = gRaceHudSubScreenProjection->mCenterWhole;
        halfSize = gRaceHudSubScreenProjection->mHalfSize;
        wholeX = GetFixed12Whole(projectedX);
        wholeY = GetFixed12Whole(projectedY);

        if (wholeX - halfSize >= centerWhole.mUnk_00 || centerWhole.mUnk_00 >= wholeX + halfSize ||
            wholeY - halfSize >= centerWhole.mUnk_04 || centerWhole.mUnk_04 >= wholeY + halfSize) {
            return FALSE;
        }
    }
    if (exactCenter != 0) {
        centerX = center.mUnk_00;
        centerY = center.mUnk_04;
    } else {
        centerX = ClearFixed12Fraction(center.mUnk_00);
        centerY = ClearFixed12Fraction(center.mUnk_04);
    }
    if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
        dx = projectedX - centerX;
        dy = projectedY - centerY;
        screenX =
            GetFixed12Whole(MulFixed12NoRound(-pairSecondScaled, dx) + MulFixed12NoRound(pairFirstScaled, dy)) + 0x80;
        screenY =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, dy)) + 0x60;
    } else {
        dx = projectedX - centerX;
        e = projectedY - centerY;
        screenX =
            GetFixed12Whole(MulFixed12NoRound(pairSecondScaled, dx) - MulFixed12NoRound(pairFirstScaled, e)) + 0x80;
        screenY =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, e)) + 0x60;
    }
    if (screenX > -32 && screenX < 0x120 && screenY > -32 && screenY < 0xe0) {
        out->mUnk_00 = screenX;
        out->mUnk_04 = screenY;
        return TRUE;
    }
    out->mUnk_00 = screenX;
    out->mUnk_04 = screenY;
    return FALSE;
}

void UpdateRaceHudSubScreenCenter(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c courseMin = gRaceHudSubScreenProjection->mCourseMin;
    Vec3 pos;
    float wholePart;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, GetFollowedKartOrEntryIndex());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    gRaceHudSubScreenProjection->mCenter.mUnk_00 =
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - courseMin.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX));
    gRaceHudSubScreenProjection->mCenter.mUnk_04 =
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - courseMin.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ));
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 = GetFixed12Whole(gRaceHudSubScreenProjection->mCenter.mUnk_00);
    out->mCenterX = gRaceHudSubScreenProjection->mCenterWhole.mUnk_00;
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 = GetFixed12Whole(gRaceHudSubScreenProjection->mCenter.mUnk_04);
    out->mCenterY = gRaceHudSubScreenProjection->mCenterWhole.mUnk_04;
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
    if (gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 > 0) {
        wholePart = 0.5f + (gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 << 12);
    } else {
        wholePart = (gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 << 12) - 0.5f;
    }
    gRaceHudSubScreenProjection->mCenterRemainderX = gRaceHudSubScreenProjection->mCenter.mUnk_00 - (s32) wholePart;
    if (gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 > 0) {
        wholePart = 0.5f + (gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 << 12);
    } else {
        wholePart = (gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 << 12) - 0.5f;
    }
    gRaceHudSubScreenProjection->mCenterRemainderY = gRaceHudSubScreenProjection->mCenter.mUnk_04 - (s32) wholePart;
}

void UpdateRaceHudSubScreenBg3Center(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c bg3Min = gRaceHudSubScreenProjection->mBg3Min;
    Vec3 pos;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, GetFollowedKartOrEntryIndex());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    out->mCenterX = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - bg3Min.mUnk_00, gRaceHudSubScreenProjection->mBg3InverseX)));
    out->mCenterY = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - bg3Min.mUnk_04, gRaceHudSubScreenProjection->mBg3InverseZ)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

Unk020b57e4 *func_020b57e4(void) {
    return gCourseMap->mUnk_2c;
}

s32 MulFx64c(s32 value, s64 factor) {
    return (factor * value + 0x80000000) >> 32;
}

void UpdateRaceHudSubScreenBg3CenterByFrames(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c bg3Min = gRaceHudSubScreenProjection->mBg3Min;
    UnkPair020b502c bg3Max = gRaceHudSubScreenProjection->mBg3Max;
    Vec3 pos;
    s32 framesQuotient;
    s32 spanX;
    s32 spanZ;
    s32 offsetX;
    s32 offsetZ;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, GetFollowedKartOrEntryIndex());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    spanX = bg3Max.mUnk_00 - bg3Min.mUnk_00;
    spanZ = bg3Max.mUnk_04 - bg3Min.mUnk_04;
    framesQuotient = GetRaceHudUpdateFrames() / 32;
    offsetX = spanX * framesQuotient;
    offsetZ = spanZ * framesQuotient;
    pos.x -= offsetX / 512;
    pos.z -= offsetZ / 512;
    out->mCenterX = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - bg3Min.mUnk_00, gRaceHudSubScreenProjection->mBg3InverseX)));
    out->mCenterY = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - bg3Min.mUnk_04, gRaceHudSubScreenProjection->mBg3InverseZ)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

u16 RaceHudSubScreenGetSlotDownBits(InputSlot *inputSlot, s32 mask) {
    return inputSlot->mBits & mask;
}

u16 RaceHudSubScreenGetDownBits(s32 slotIndex, s32 mask) {
    return RaceHudSubScreenGetSlotDownBits(&data_02175628[slotIndex], mask);
}

void UpdateRaceHudSubScreenScroll(void) {
    UnkPair020b502c scrollMin;
    UnkPair020b502c scrollMax;
    Vec3 target;
    Vec3 dir;

    GetRaceHudSubScreenScrollLimits(&scrollMin, &scrollMax);
    if (RaceHudSubScreenGetDownBits(func_020435bc(), PAD_KEY_LEFT) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.x -= 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.x < scrollMin.mUnk_00) {
                gRaceHudSubScreenProjection->mScrollPosition.x = scrollMin.mUnk_00;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (RaceHudSubScreenGetDownBits(func_020435bc(), PAD_KEY_RIGHT) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.x += 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.x > scrollMax.mUnk_00) {
                gRaceHudSubScreenProjection->mScrollPosition.x = scrollMax.mUnk_00;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (RaceHudSubScreenGetDownBits(func_020435bc(), PAD_KEY_UP) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.z -= 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.z < scrollMin.mUnk_04) {
                gRaceHudSubScreenProjection->mScrollPosition.z = scrollMin.mUnk_04;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (RaceHudSubScreenGetDownBits(func_020435bc(), PAD_KEY_DOWN) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.z += 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.z > scrollMax.mUnk_04) {
                gRaceHudSubScreenProjection->mScrollPosition.z = scrollMax.mUnk_04;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        gRaceHudSubScreenProjection->mScrollTimer--;
        if (gRaceHudSubScreenProjection->mScrollTimer < 300) {
            GetKartPosFromPosSourceCopy(&target, GetFollowedKartOrEntryIndex());
            gRaceHudSubScreenProjection->mScrollTimer = 300;
            VEC_Subtract(&target, &gRaceHudSubScreenProjection->mScrollPosition, &dir);
            Vec3NormalizeAndGetLengthUnchecked(&dir, &dir);
            VEC_MultAdd(0xa000, &dir, &gRaceHudSubScreenProjection->mScrollPosition,
                        &gRaceHudSubScreenProjection->mScrollPosition);
            if (GetFixed12Whole(target.x - gRaceHudSubScreenProjection->mScrollPosition.x) *
                        GetFixed12Whole(target.x - gRaceHudSubScreenProjection->mScrollPosition.x) +
                    GetFixed12Whole(target.z - gRaceHudSubScreenProjection->mScrollPosition.z) *
                        GetFixed12Whole(target.z - gRaceHudSubScreenProjection->mScrollPosition.z) <
                GetFixed12Whole(0xa000) * GetFixed12Whole(0xa000)) {
                gRaceHudSubScreenProjection->mScrollPosition = target;
                gRaceHudSubScreenProjection->mScrollTimer = 0;
            }
        }
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.x < scrollMin.mUnk_00) {
        gRaceHudSubScreenProjection->mScrollPosition.x = scrollMin.mUnk_00;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.x > scrollMax.mUnk_00) {
        gRaceHudSubScreenProjection->mScrollPosition.x = scrollMax.mUnk_00;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.z < scrollMin.mUnk_04) {
        gRaceHudSubScreenProjection->mScrollPosition.z = scrollMin.mUnk_04;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.z > scrollMax.mUnk_04) {
        gRaceHudSubScreenProjection->mScrollPosition.z = scrollMax.mUnk_04;
    }
}

s32 GetAnglePairSecond(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2 + 1];
}

s32 GetAnglePairFirst(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2];
}

s32 GetFixed12Whole(s32 value) {
    return value >> 12;
}

s32 RaceHudSubScreenGetCurrentMirrorMode(void) {
    return gRaceSetup->mMirrorMode;
}

void UpdateRaceHudSubScreenProjectionAndBgAffine(RaceHudSubScreenBgAffine *bgAffines, s32 scale) {
    s32 angle = GetSubScreenAngleAndClearScrollTimer();
    s32 secondByInverseScale;
    s32 firstByInverseScale;

    gRaceHudSubScreenProjection->mAnglePairSecond = GetAnglePairSecond(angle);
    gRaceHudSubScreenProjection->mAnglePairFirst = GetAnglePairFirst(angle);
    gRaceHudSubScreenProjection->mAnglePairSecondScaled =
        MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairSecond, scale);
    gRaceHudSubScreenProjection->mAnglePairFirstScaled =
        MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairFirst, scale);
    if (GetRaceHudSubScreenState() == 2) {
        UpdateRaceHudSubScreenScroll();
    }
    gRaceHudSubScreenProjection->mHalfSize = GetFixed12Whole(FX_Div(0xb0000, scale));
    scale = FX_Inv(scale);
    secondByInverseScale = MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairSecond, scale);
    firstByInverseScale = MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairFirst, scale);
    if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
        bgAffines[0].mMatrix0 = bgAffines[1].mMatrix0 = -secondByInverseScale;
        bgAffines[0].mMatrix2 = bgAffines[1].mMatrix2 = firstByInverseScale;
    } else {
        bgAffines[0].mMatrix0 = bgAffines[1].mMatrix0 = secondByInverseScale;
        bgAffines[0].mMatrix2 = bgAffines[1].mMatrix2 = -firstByInverseScale;
    }
    bgAffines[0].mMatrix1 = bgAffines[1].mMatrix1 = firstByInverseScale;
    bgAffines[0].mMatrix3 = bgAffines[1].mMatrix3 = secondByInverseScale;
    UpdateRaceHudSubScreenCenter(bgAffines);
    switch (RaceHudSubScreenGetCurrentCourseId()) {
        default:
            bgAffines[1] = bgAffines[0];
            break;
        case COURSE_ID_OLD_LUIGI_GC:
        case COURSE_ID_MANSION:
        case COURSE_ID_CROSS:
        case COURSE_ID_TOWN:
        case COURSE_ID_SNOW:
        case COURSE_ID_PINBALL:
        case COURSE_ID_OLD_KINOKO_GC:
            UpdateRaceHudSubScreenBg3Center(&bgAffines[1]);
            break;
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            UpdateRaceHudSubScreenBg3CenterByFrames(&bgAffines[1]);
            break;
    }
}

s32 MulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return ((s64) multiplicand * multiplier) >> 12;
}
