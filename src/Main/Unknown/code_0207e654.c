#include "Main/Unknown/code_0207e654.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_0207e000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"

static inline BOOL func_0207f600_inline(s32 kartIndex) {
    return (GetKart(kartIndex)->mUnk_7c & 0x402020) == 0;
}

static inline s32 func_0207f554_inline2(u32 entryIndex) {
    return *(vs32 *) &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

static inline s32 func_0207f554_inline(u32 kartIndex, u32 targetIndex) {
    BOOL result = FALSE;
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gRaceSetup->mUseTeams == 0 ||
        gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex != func_0207f554_inline2(targetIndex)) {
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceSetup->mCurrentEntries[targetIndex].mPlayer.mKind;
        if ((u32) playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE || func_02085824(kartIndex) <= 0) {
            if (func_0207f600_inline(targetIndex)) {
                result = TRUE;
            }
        }
    }
    return result;
}

void AdvanceAwardPointLinkCursor(PointLinkCursor *pointLinkCursor) {
    u32 nextLinkIndex = 0;
    Kart *kart = GetKart(pointLinkCursor->mKartIndex);
    s32 animation;

    if (pointLinkCursor->mLink->mNextCount > 1) {
        nextLinkIndex = pointLinkCursor->mKartIndex;
    }
    pointLinkCursor->mPreviousLink = pointLinkCursor->mLink;
    pointLinkCursor->mLink = pointLinkCursor->mLink->mUnk_00[nextLinkIndex];
    animation = data_usa_021557dc[pointLinkCursor->mLink->mUnk_20->mUnk_04];
    if (animation != kart->mKartModelsEntry->mCharacterAnimation->mUnk_1a) {
        func_02068a64(kart, animation, 1);
    }
    VEC_Subtract(pointLinkCursor->mLink->mUnk_18, pointLinkCursor->mPreviousLink->mUnk_18,
                 &pointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

s32 GetPointLinkSpeedRatio(PointLinkCursor *pointLinkCursor) {
    s32 fixedValue = pointLinkCursor->mLink->mUnk_20->mUnk_02 << 12;

    return ((s64) fixedValue * 0x29 + 0x800) >> 12;
}

void AdvanceStaffRollPointLinkCursor(PointLinkCursor *pointLinkCursor) {
    Kart *kart = GetKart(pointLinkCursor->mKartIndex);
    u16 nextLinkIndex;
    s32 animation;

    if (pointLinkCursor->mLink->mNextCount > 1 && pointLinkCursor->mUnk_1e < 2) {
        if (pointLinkCursor->mUnk_1e == 0) {
            nextLinkIndex = pointLinkCursor->mKartIndex / 3;
        } else {
            nextLinkIndex = pointLinkCursor->mKartIndex % 3;
        }
        pointLinkCursor->mUnk_1e++;
    } else {
        nextLinkIndex = 0;
    }
    pointLinkCursor->mPreviousLink = pointLinkCursor->mLink;
    pointLinkCursor->mLink = pointLinkCursor->mLink->mUnk_00[nextLinkIndex];
    animation = data_usa_021557dc[pointLinkCursor->mLink->mUnk_20->mUnk_04];
    if (animation != kart->mKartModelsEntry->mCharacterAnimation->mUnk_1a) {
        func_02068a64(kart, animation, 1);
    }
    if (pointLinkCursor->mKartIndex != 0) {
        if (pointLinkCursor->mLink->mUnk_20->mUnk_06 == 0) {
            kart->mUnk_7c &= ~0x40;
        } else {
            kart->mUnk_7c |= 0x40;
        }
    }
    VEC_Subtract(pointLinkCursor->mLink->mUnk_18, pointLinkCursor->mPreviousLink->mUnk_18,
                 &pointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

void func_0207fba0(void) {
    data_usa_0217ae40 = gRaceSetup->mMode == MODE_BATTLE ? &data_usa_021557bc : &data_usa_021557c0;
    switch (func_020853dc()) {
        case 0:
            data_usa_0217ae38 = data_usa_0215572c;
            gKartAiDriftChargeRandomLimits = data_usa_02155798;
            break;
        case 1:
            data_usa_0217ae38 = data_usa_02155750;
            gKartAiDriftChargeRandomLimits = data_usa_021556e4;
            break;
        case 2:
            data_usa_0217ae38 = data_usa_02155774;
            gKartAiDriftChargeRandomLimits = data_usa_02155708;
            break;
        default:
            data_usa_0217ae38 = data_usa_02155774;
            gKartAiDriftChargeRandomLimits = data_usa_02155708;
            break;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gAdvanceKartAiPointLinkCursor = AdvanceAwardPointLinkCursor;
        gSetKartAiLinkPos = SetKartAiLinkPosAndClearSideOffset;
    } else if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        gAdvanceKartAiPointLinkCursor = AdvanceStaffRollPointLinkCursor;
        gSetKartAiLinkPos = SetKartAiLinkPosAndClearSideOffset;
    } else {
        gAdvanceKartAiPointLinkCursor = AdvancePointLinkCursor;
        gSetKartAiLinkPos = SetKartAiLinkPosAndAddSideOffset;
    }
}

void SetupRaceKartAi(KartAi *kartAi, Kart *kart, s32 a) {
    s32 v;
    RandomState64 *kartAiRandom;

    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mUnk_06 = kartAi->mIndex % 4;
    if (a != 0) {
        v = 0;
    } else {
        v = GetKartAiTableIndex(kartAi->mIndex);
    }
    kartAi->mUnk_88 = data_usa_0217ae38[v];
    kartAi->mDriftChargeRandomLimit = gKartAiDriftChargeRandomLimits[v];
    kartAi->mMinVelocityLength = ((s64) kartAi->mKart->mPhysicalParam->mBaseSpeedLimit * 0x99a + 0x800) >> 12;
    InitRacePointLinkCursor(&kartAi->mUnk_08, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    v = (s16) (u16) (kartAiRandom->mValue >> 52);
    kartAi->mUnk_cc = v > 0x800 ? 1 : -1;
}

void ResetKartAi(KartAi *kartAi, s32 a) {
    kartAi->mLinkPosWithSideOffset = *kartAi->mUnk_08.mLinkCursor.mLink->mUnk_18;
    kartAi->mSideOffset = data_usa_021557d0;
    kartAi->mUnk_6c = 0;
    kartAi->mUnk_6e = 0;
    kartAi->mTurnAngleDegrees = 0;
    kartAi->mSideOffsetRatio = 0;
    kartAi->mUnk_78 = 0;
    kartAi->mUnk_7a = 0;
    kartAi->mUnk_80 = 0;
    kartAi->mUnk_7c = 0;
    kartAi->mUnk_84 = a;
    kartAi->mUnk_a8 = 0;
    kartAi->mUnk_ac = 0;
    kartAi->mTargetKart = NULL;
    kartAi->mTargetAhead = 0;
    kartAi->mTargetDistanceSquared = 0;
    kartAi->mTargetForwardDot = -0x1000;
    kartAi->mBalloonCountGoal = 0;
    kartAi->mUnk_c2 = 0;
    kartAi->mUnk_c4 = FALSE;
    kartAi->mUnk_90 = 0;
    kartAi->mTurnSide = 0;
    kartAi->mUnk_98 = 0;
    kartAi->mUnk_a0 = FALSE;
    SetKartAiSideOffsetFromKart(kartAi);
}

void ResetRaceKartAiAtPointLink(KartAi *kartAi) {
    PointLink *pointLink;

    ResetPointLinkCursor(&kartAi->mUnk_08.mLinkCursor, pointLink);
    ResetKartAi(kartAi, 1);
}

void AdvanceRaceKartAi(KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    Vec3 *kartForward;
    LinkCursor *linkCursor;
    Kart *kart;
    PointLink *requestedLink;

    func_0207e668(kartAi);
    linkCursor = &kartAi->mUnk_08.mLinkCursor;
    kart = kartAi->mKart;
    if (kartAi->mUnk_90 == 2) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->mUnk_138;
    }
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    func_0207f6f0(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    func_0207ebfc(kartAi);
    PickKartAiTargetKart(kartAi);
}

void func_0207f6f0(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart, PointLink *requestedLink, Vec3 *kartPos,
                   Vec3 *kartForward) {
    Vec3 toLinkPos;
    Vec3 crossProduct;
    Vec3 *planeNormal;
    s32 normalComponent;
    s32 crossLength;
    s32 angle;
    s32 angleDegrees;
    s32 isLinkReached;

    if (requestedLink != NULL && linkCursor->mLink != requestedLink) {
        func_0207f05c(kartAi);
        AdvancePointLinkCursorTo(linkCursor, requestedLink);
        gSetKartAiLinkPos(kartAi, linkCursor, kart);
        return;
    }
    if (GetRaceUpdateFramesMod8() == kartAi->mIndex) {
        if (kartAi->mKart->mUnk_44 & 0x2000) {
            SetKartAiSideOffsetFromKart(kartAi);
        }
        planeNormal = &kart->mUnk_12c;
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kart->mPos, &toLinkPos);
        normalComponent = VEC_DotProduct(planeNormal, &toLinkPos);
        toLinkPos.x = toLinkPos.x - (s32) (((s64) kart->mUnk_12c.x * normalComponent) >> 12);
        toLinkPos.y = toLinkPos.y - (s32) (((s64) planeNormal->y * normalComponent) >> 12);
        toLinkPos.z = toLinkPos.z - (s32) (((s64) planeNormal->z * normalComponent) >> 12);
        Vec3CrossUnrounded(kartForward, &toLinkPos, &crossProduct);
        crossLength = VEC_Mag(&crossProduct);
        angle = FX_Atan2(crossLength, Vec3DotUnrounded(kartForward, &toLinkPos));
        angleDegrees = ((s64) angle * 0x394bb834c8LL + 0x80000000LL) >> 32;
        if (Vec3DotUnrounded(&crossProduct, planeNormal) < 0) {
            angleDegrees *= -1;
        }
        kartAi->mTurnAngleDegrees = GetAbsoluteValue(angleDegrees);
    }
    isLinkReached = IsPastPointLink((PointLinkCursor *) linkCursor, kartPos);
    if (isLinkReached == 0 && (kart->mUnk_48 & 0x40000000) == 0) {
        isLinkReached = IsWithinPointLinkDistance((PointLinkCursor *) linkCursor, kartPos);
    }
    if (isLinkReached == 0) {
        return;
    }
    func_0207f05c(kartAi);
    gAdvanceKartAiPointLinkCursor((PointLinkCursor *) linkCursor);
    gSetKartAiLinkPos(kartAi, linkCursor, kart);
    linkCursor->mRequestedLink = NULL;
    linkCursor->mUnk_18 = FALSE;
}

void SetKartAiLinkPosAndAddSideOffset(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart) {
    kartAi->mLinkPosWithSideOffset = *linkCursor->mLink->mUnk_18;
    if (kart->mUnk_48 & 0x40000000) {
        return;
    }
    if (GetRaceUpdateFrames() > 0xb4) {
        if (kartAi->mUnk_90 == 2) {
            kartAi->mSideOffset = data_usa_021557d0;
            kartAi->mSideOffsetRatio = 0;
        } else {
            AdvanceKartAiSideOffset(kartAi);
        }
    }
    VEC_Add(&kartAi->mLinkPosWithSideOffset, &kartAi->mSideOffset, &kartAi->mLinkPosWithSideOffset);
}

void SetKartAiLinkPosAndClearSideOffset(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart) {
    kartAi->mLinkPosWithSideOffset = *linkCursor->mLink->mUnk_18;
    kartAi->mSideOffset = data_usa_021557d0;
    kartAi->mSideOffsetRatio = 0;
}

BOOL func_0207f600(s32 kartIndex) {
    return (GetKart(kartIndex)->mUnk_7c & 0x402020) == 0;
}

s32 ShouldKartAiTargetKart(u32 kartIndex, u32 targetIndex) {
    BOOL result = FALSE;
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gRaceSetup->mUseTeams == 0 ||
        gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex != func_0207f554_inline2(targetIndex)) {
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceSetup->mCurrentEntries[targetIndex].mPlayer.mKind;
        if ((u32) playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE || func_02085824(kartIndex) <= 0) {
            if ((GetKart(targetIndex)->mUnk_7c & 0x402020) == 0) {
                result = TRUE;
            }
        }
    }
    return result;
}

void PickKartAiTargetKart(KartAi *kartAi) {
    u32 a;
    BOOL foundAhead;
    s32 behindKartIndex;
    s32 aheadKartIndex;
    u32 ownKartIndex;

    kartAi->mTargetKart = NULL;
    kartAi->mTargetAhead = 0;
    ownKartIndex = kartAi->mIndex;
    a = ownKartIndex;
    if (a != GetRaceUpdateFramesMod8()) {
        return;
    }
    if (gRaceSetup->mCpuDifficulty != CPU_DIFFICULTY_HARD) {
        return;
    }
    a = GetKartRank(a);
    if (a <= 1) {
        return;
    }
    aheadKartIndex = gRaceProgress->mKartAtRank[(u8) (a - 1) - 1];
    foundAhead = FALSE;
    if (aheadKartIndex >= 0) {
        aheadKartIndex = gRaceProgress->mKartAtRank[(u8) (a - 1) - 1];
        if (func_0207f554_inline(kartAi->mIndex, (u16) aheadKartIndex) != 0) {
            kartAi->mTargetKart = GetKart(aheadKartIndex);
            foundAhead = TRUE;
            kartAi->mTargetAhead = 1;
        }
    }
    if (foundAhead != FALSE) {
        return;
    }
    if (a >= gRaceSetup->mKartCount) {
        return;
    }
    behindKartIndex = gRaceProgress->mKartAtRank[(u8) (a + 1) - 1];
    if (behindKartIndex < 0) {
        return;
    }
    behindKartIndex = gRaceProgress->mKartAtRank[(u8) (a + 1) - 1];
    if (func_0207f554_inline(kartAi->mIndex, (u16) behindKartIndex) != 0) {
        kartAi->mTargetKart = GetKart(behindKartIndex);
    }
}

void func_0207f05c(KartAi *kartAi) {
    Vec3 linkPos;
    Vec3 sideAxis;
    Vec3 kartOffset;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 unitY;
    Vec3 h;
    s32 linkValue = func_02080cc0(&kartAi->mUnk_08.mLinkCursor);
    BOOL conditionsMet;
    s32 sideRange;
    s32 sidewaysDistance;
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (kartAi->mUnk_90 == 0 && linkValue >= 1 && linkValue <= 4) {
        conditionsMet = FALSE;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        if (randomValue <= kartAi->mUnk_88 && kartAi->mKart->mVelocityLength >= kartAi->mMinVelocityLength) {
            linkPos = *kartAi->mUnk_08.mLinkCursor.mLink->mUnk_18;
            unitY = data_usa_021557c4;
            Vec3CrossUnrounded(&kartAi->mUnk_08.mLinkCursor.mDirection, &unitY, &sideAxis);
            VEC_Subtract(&kartAi->mKart->mPos, &linkPos, &kartOffset);
            sidewaysDistance = Vec3DotUnrounded(&kartOffset, &sideAxis);
            sideRange = kartAi->mUnk_08.mLinkCursor.mLink->mUnk_1c;
            if (GetAbsoluteValue(sidewaysDistance) < sideRange) {
                conditionsMet = TRUE;
            }
        }
        if (conditionsMet != FALSE) {
            switch (linkValue) {
                case 1:
                    kartAi->mUnk_90 = 1;
                    kartAi->mTurnSide = 1;
                    kartAi->mUnk_98 = 0;
                    kartAi->mUnk_a0 = TRUE;
                    break;
                case 2:
                    kartAi->mUnk_90 = 1;
                    kartAi->mTurnSide = 1;
                    kartAi->mUnk_98 = 0;
                    kartAi->mUnk_a0 = FALSE;
                    break;
                case 3:
                    kartAi->mUnk_90 = 1;
                    kartAi->mTurnSide = 2;
                    kartAi->mUnk_98 = 0;
                    kartAi->mUnk_a0 = TRUE;
                    break;
                case 4:
                    kartAi->mUnk_90 = 1;
                    kartAi->mTurnSide = 2;
                    kartAi->mUnk_98 = 0;
                    kartAi->mUnk_a0 = FALSE;
                    break;
            }
        }
    }
    if (kartAi->mUnk_90 != 2) {
        return;
    }
    if (linkValue != 5) {
        return;
    }
    kartAi->mUnk_90 = 3;
    e = *kartAi->mUnk_08.mLinkCursor.mLink->mUnk_18;
    h = data_usa_021557c4;
    Vec3CrossUnrounded(&kartAi->mUnk_08.mLinkCursor.mDirection, &h, &f);
    VEC_Subtract(&kartAi->mKart->mPos, &e, &g);
    kartAi->mSideOffsetRatio = FX_Div(Vec3DotUnrounded(&g, &f), kartAi->mUnk_08.mLinkCursor.mLink->mUnk_1c + 0x1000);
    if (GetAbsoluteValue(kartAi->mSideOffsetRatio) > 0x1000) {
        if (kartAi->mSideOffsetRatio > 0) {
            kartAi->mSideOffsetRatio = 0x1000;
        }
        kartAi->mSideOffsetRatio = -0x1000;
    }
    kartAi->mSideOffsetRatio = kartAi->mSideOffsetRatio >> 1;
}

void func_0207ebfc(KartAi *kartAi) {
    Vec3 offsetToLink;
    Vec3 flatOffsetToLink;
    Vec3 kartUp;
    Vec3 sideCross;
    Vec3 offsetOnUpPlane;
    Vec3 turnCross;
    Kart *kart;
    Kart *q2;
    Vec3 *kartForward;
    Vec3 *planeNormal;
    s32 n;
    s32 m;
    BOOL chargeRollPassed;

    func_02080cc0(&kartAi->mUnk_08.mLinkCursor);
    kart = kartAi->mKart;
    if (kartAi->mUnk_90 == 1) {
        RequestBits(kart->mEntryIndex, PAD_KEY_R);
        kartAi->mUnk_90 = 2;
    }
    if (kartAi->mUnk_90 == 4) {
        if (kart->mUnk_44 & 2) {
            if (kartAi->mTurnSide == 1) {
                kart->mUnk_48 &= ~KART_48_TURN_RIGHT;
                kart->mUnk_48 |= KART_48_TURN_LEFT;
            } else if (kartAi->mTurnSide == 2) {
                kart->mUnk_48 &= ~KART_48_TURN_LEFT;
                kart->mUnk_48 |= KART_48_TURN_RIGHT;
            }
        } else {
            kartAi->mUnk_90 = 0;
            kartAi->mTurnSide = 0;
        }
    }
    if (kartAi->mUnk_90 == 3 && (kart->mUnk_44 & KART_44_ON_GROUND)) {
        planeNormal = &kart->mUnk_12c;
        kartForward = &kart->mUnk_138;
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kart->mPos, &flatOffsetToLink);
        n = VEC_DotProduct(planeNormal, &flatOffsetToLink);
        flatOffsetToLink.x -= (s32) (((s64) planeNormal->x * n) >> 12);
        flatOffsetToLink.y -= (s32) (((s64) planeNormal->y * n) >> 12);
        flatOffsetToLink.z -= (s32) (((s64) planeNormal->z * n) >> 12);
        Vec3CrossUnrounded(kartForward, &flatOffsetToLink, &turnCross);
        m = VEC_Mag(&turnCross);
        m = FX_Atan2(m, Vec3DotUnrounded(kartForward, &flatOffsetToLink));
        m = ((s64) m * 0x394bb834c8LL + 0x80000000LL) >> 32;
        n = Vec3DotUnrounded(&turnCross, planeNormal);
        if (n < 0) {
            n = -1;
            m = m * n;
        }
        kartAi->mTurnAngleDegrees = GetAbsoluteValue(m);
        kartAi->mUnk_90 = 0;
        kartAi->mTurnSide = 0;
        kartAi->mUnk_98 = 0;
        kartAi->mUnk_a0 = FALSE;
        EndKartDrift(kart);
        if (GetAbsoluteValue(kartAi->mTurnAngleDegrees) <= 0x32000) {
            return;
        }
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kart->mPos, &offsetToLink);
        kartAi->mUnk_90 = 4;
        q2 = kartAi->mKart;
        GetKartUp(q2, &kartUp);
        n = VEC_DotProduct(&kartUp, &offsetToLink);
        offsetOnUpPlane.x = offsetToLink.x - (s32) (((s64) kartUp.x * n) >> 12);
        offsetOnUpPlane.y = offsetToLink.y - (s32) (((s64) kartUp.y * n) >> 12);
        offsetOnUpPlane.z = offsetToLink.z - (s32) (((s64) kartUp.z * n) >> 12);
        Vec3CrossUnrounded(&q2->mUnk_138, &offsetOnUpPlane, &sideCross);
        m = Vec3DotUnrounded(&kartUp, &sideCross);
        if (m > 0) {
            m = 1;
        } else {
            m = -1;
        }
        if (m > 0) {
            kartAi->mTurnSide = 1;
        } else {
            kartAi->mTurnSide = 2;
        }
        kart->mUnk_44 |= 0x20000000;
        return;
    }
    if (kartAi->mUnk_90 != 2) {
        return;
    }
    if (kart->mUnk_44 & 2) {
        if (kartAi->mTurnSide == 1) {
            kart->mUnk_48 &= ~KART_48_TURN_RIGHT;
            kart->mUnk_48 |= KART_48_TURN_LEFT;
        } else if (kartAi->mTurnSide == 2) {
            kart->mUnk_48 &= ~KART_48_TURN_LEFT;
            kart->mUnk_48 |= KART_48_TURN_RIGHT;
        }
    }
    RequestBits(kart->mEntryIndex, PAD_KEY_R);
    kartAi->mUnk_98++;
    chargeRollPassed = FALSE;
    if (kartAi->mUnk_98 == 0x28 && kartAi->mUnk_a0 != FALSE) {
        RandomState64 *r = GetKartAiRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        if ((s16) (u16) (r->mValue >> 52) <= kartAi->mDriftChargeRandomLimit) {
            chargeRollPassed = TRUE;
        }
    }
    if (chargeRollPassed != FALSE) {
        SetKartDriftCharge(kart, 3);
    }
    kartAi->mSideOffset = data_usa_021557d0;
    kartAi->mSideOffsetRatio = 0;
    if (!(kart->mUnk_44 & 0xc00c0)) {
        n = kart->mVelocityLength;
        if (n > (s32) (((s64) kart->mPhysicalParam->mBaseSpeedLimit * 0x8cd) >> 12)) {
            return;
        }
    }
    kartAi->mUnk_90 = 0;
    kartAi->mTurnSide = 0;
    kartAi->mUnk_98 = 0;
    kartAi->mUnk_a0 = FALSE;
}

s32 ComputeAngleToPositionDegrees(Vec3 *targetPos, Vec3 *originPos, Vec3 *planeNormal, Vec3 *forward) {
    Vec3 flatOffset;
    Vec3 crossProduct;
    s32 n;
    s32 crossLength;
    s32 angleDegrees;

    VEC_Subtract(targetPos, originPos, &flatOffset);
    n = VEC_DotProduct(planeNormal, &flatOffset);
    flatOffset.x -= (s32) (((s64) planeNormal->x * n) >> 12);
    flatOffset.y -= (s32) (((s64) planeNormal->y * n) >> 12);
    flatOffset.z -= (s32) (((s64) planeNormal->z * n) >> 12);
    Vec3CrossUnrounded(forward, &flatOffset, &crossProduct);
    crossLength = VEC_Mag(&crossProduct);
    angleDegrees = FX_Atan2(crossLength, Vec3DotUnrounded(forward, &flatOffset));
    angleDegrees = ((s64) angleDegrees * 0x394bb834c8LL + 0x80000000LL) >> 32;
    n = Vec3DotUnrounded(&crossProduct, planeNormal);
    if (n < 0) {
        n = -1;
        angleDegrees = angleDegrees * n;
    }
    return angleDegrees;
}

void AdvanceKartAiSideOffset(KartAi *kartAi) {
    Vec3 unitY = data_usa_021557c4;
    s32 sideDistance;

    Vec3CrossUnrounded(&kartAi->mUnk_08.mLinkCursor.mDirection, &unitY, &kartAi->mSideOffset);
    kartAi->mUnk_6c++;
    if (kartAi->mUnk_6c > kartAi->mUnk_6e) {
        RandomState64 *kartAiRandom;
        s32 randomValue;
        s32 newSideOffsetRatio;

        kartAi->mUnk_6c = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        kartAi->mUnk_6e = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        newSideOffsetRatio = kartAi->mSideOffsetRatio +
                             (s32) (((s64) ((s32) (((s64) randomValue * 0x2000) >> 12) - 0x1000) * 0x267) >> 12);
        if (GetAbsoluteValue(newSideOffsetRatio) > 0xb36) {
            if (newSideOffsetRatio > 0) {
                newSideOffsetRatio = 0xb36;
            } else {
                newSideOffsetRatio = -0xb36;
            }
        }
        kartAi->mSideOffsetRatio = newSideOffsetRatio;
    }
    sideDistance = ((s64) kartAi->mSideOffsetRatio * kartAi->mUnk_08.mLinkCursor.mLink->mUnk_1c) >> 12;
    kartAi->mSideOffset.x = ((s64) kartAi->mSideOffset.x * sideDistance) >> 12;
    kartAi->mSideOffset.y = ((s64) kartAi->mSideOffset.y * sideDistance) >> 12;
    kartAi->mSideOffset.z = ((s64) kartAi->mSideOffset.z * sideDistance) >> 12;
}

void SetKartAiSideOffsetFromKart(KartAi *kartAi) {
    Vec3 linkPos;
    Vec3 g;
    Vec3 linkPosCopy;
    Vec3 sideAxis;
    Vec3 kartOffset;
    Vec3 unitYCopy;
    Vec3 unitY;
    s32 s;

    linkPos = *kartAi->mUnk_08.mLinkCursor.mLink->mUnk_18;
    linkPosCopy = *kartAi->mUnk_08.mLinkCursor.mLink->mUnk_18;
    unitY = data_usa_021557c4;
    unitYCopy = *(Vec3 *) &data_usa_021557c4;
    Vec3CrossUnrounded(&kartAi->mUnk_08.mLinkCursor.mDirection, &unitYCopy, &sideAxis);
    VEC_Subtract(&kartAi->mKart->mPos, &linkPosCopy, &kartOffset);
    s = Vec3DotUnrounded(&kartOffset, &sideAxis);
    kartAi->mSideOffsetRatio = FX_Div(s, kartAi->mUnk_08.mLinkCursor.mLink->mUnk_1c + 0x1000);
    if (GetAbsoluteValue(kartAi->mSideOffsetRatio) > 0x1000) {
        if (kartAi->mSideOffsetRatio > 0) {
            kartAi->mSideOffsetRatio = 0x1000;
        }
        kartAi->mSideOffsetRatio = -0x1000;
    }
    g = unitY;
    Vec3CrossUnrounded(&kartAi->mUnk_08.mLinkCursor.mDirection, &g, &kartAi->mSideOffset);
    s = ((s64) kartAi->mSideOffsetRatio * kartAi->mUnk_08.mLinkCursor.mLink->mUnk_1c) >> 12;
    kartAi->mSideOffset.x = ((s64) kartAi->mSideOffset.x * s) >> 12;
    kartAi->mSideOffset.y = ((s64) kartAi->mSideOffset.y * s) >> 12;
    kartAi->mSideOffset.z = ((s64) kartAi->mSideOffset.z * s) >> 12;
    VEC_Add(&linkPos, &kartAi->mSideOffset, &kartAi->mLinkPosWithSideOffset);
}

void func_0207e668(KartAi *kartAi) {
    BOOL limitReached = FALSE;
    BOOL timerActive = FALSE;
    Kart *kart;

    kartAi->mUnk_ac--;
    if (kartAi->mUnk_ac <= 0) {
        kartAi->mUnk_ac = 0;
    } else {
        timerActive = TRUE;
    }
    kart = kartAi->mKart;
    {
        BOOL isTriggered;
        if ((kart->mUnk_44 & 0xc0) && kart->mVelocityLength < 0x3000) {
            isTriggered = TRUE;
        } else {
            isTriggered = FALSE;
        }
        if (isTriggered != FALSE) {
            kartAi->mUnk_ac = 10;
            timerActive = TRUE;
        }
    }
    if (timerActive != FALSE) {
        kartAi->mUnk_78++;
        if (kartAi->mUnk_78 >= kartAi->mUnk_7a) {
            kartAi->mUnk_78 = 0;
            limitReached = TRUE;
        }
    } else if (kartAi->mUnk_ac <= 0) {
        kartAi->mUnk_78 = 0;
        kartAi->mUnk_a8 = 0;
        kartAi->mUnk_7a = 0x14;
    }
    if (limitReached == FALSE) {
        return;
    }
    switch (kartAi->mUnk_a8) {
        case 0:
            kartAi->mUnk_a8 = 1;
            kartAi->mUnk_7a = 0x78;
            break;
        case 1:
            if (gRaceSetup->mMode == MODE_BATTLE) {
                kartAi->mUnk_a8 = 3;
                CallKartAiRequestLink(kartAi->mKart->mAi);
                kartAi->mUnk_7a = 0xb4;
            } else {
                kartAi->mUnk_a8 = 2;
                kartAi->mUnk_7a = 0xb4;
                SetRequestedLinkToPreviousIfNone(&kartAi->mUnk_08.mLinkCursor);
            }
            break;
        case 2:
            kartAi->mUnk_a8 = 3;
            CallKartAiRequestLink(kartAi->mKart->mAi);
            kartAi->mUnk_7a = 0xb4;
            break;
        case 3:
            kartAi->mUnk_a8 = 4;
            func_02063a68(kartAi->mKart);
            break;
    }
}

BOOL IsTargetKartSet(KartAi *kartAi) {
    return kartAi->mTargetKart != NULL;
}
