#include "Main/Unknown/code_0207ffa4.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020800f4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02077bc0.h"

void func_02081060(Kart *kart) {
    Unk0201ca6c *effect;

    if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    if (data_0217ae94[kart->mIndex] != NULL) {
        return;
    }
    data_0217ae94[kart->mIndex] = StartEffect(0x80, &data_02155a14);
    effect = data_0217ae94[kart->mIndex];
    effect->mUnk_98_24 = kart->mIndex;
    effect->mUnk_94 = 0;
    effect->mUnk_90 = AdvanceKartAheadEffect;
}

void func_02081000(Kart *kart) {
    Unk0201ca6c *effect = data_0217ae94[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->mUnk_98_16 = 0;
    effect->mUnk_98_8 = 3;
    effect->mUnk_90 = AdvanceKartAheadEffectWithLimit;
    data_0217ae94[kart->mIndex] = NULL;
}

void func_02080fb8(Kart *kart) {
    if (data_0217ae94[kart->mIndex] == NULL) {
        return;
    }
    func_0208b710(data_0217ae94[kart->mIndex]);
    data_0217ae94[kart->mIndex] = NULL;
}

void func_02080f44(Kart *kart) {
    Unk0201ca6c *effect;

    if (data_0217ae74[kart->mIndex] != NULL) {
        return;
    }
    data_0217ae74[kart->mIndex] = StartEffect(0x7f, &data_02155a14);
    effect = data_0217ae74[kart->mIndex];
    effect->mUnk_98_24 = kart->mIndex;
    effect->mUnk_94 = (void *) 1;
    effect->mUnk_90 = AdvanceKartAheadEffect;
}

void func_02080ee4(Kart *kart) {
    Unk0201ca6c *effect = data_0217ae74[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->mUnk_98_16 = 0;
    effect->mUnk_98_8 = 5;
    effect->mUnk_90 = AdvanceKartAheadEffectWithLimit;
    data_0217ae74[kart->mIndex] = NULL;
}

void func_02080e9c(Kart *kart) {
    if (data_0217ae74[kart->mIndex] == NULL) {
        return;
    }
    func_0208b710(data_0217ae74[kart->mIndex]);
    data_0217ae74[kart->mIndex] = NULL;
}

void func_02080e88(Unk0201ca6c *effect, Kart *kart) {
    effect->mUnk_6c = (s16) kart->mScale.z;
}

BOOL IsWithinBattlePointLinkDistance(LinkCursor *linkCursor, Vec3 *position) {
    Vec3 offset;
    s32 radius;
    BOOL result = FALSE;

    radius = linkCursor->mLink->mUnk_24;
    VEC_Subtract(linkCursor->mLink->mUnk_20, position, &offset);
    offset.y = result;
    if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z < (s64) radius * radius) {
        result = TRUE;
    }
    return result;
}

BOOL IsPastBattlePointLink(LinkCursor *linkCursor, Vec3 *position) {
    Vec3 offset;
    Vec3 *linkPosition = linkCursor->mLink->mUnk_20;
    BOOL result = FALSE;

    if (linkCursor->mDirection.x != 0 || linkCursor->mDirection.y != 0 || linkCursor->mDirection.z != 0) {
        VEC_Subtract(position, linkPosition, &offset);
        if (Vec3DotUnrounded(&linkCursor->mDirection, &offset) > 0) {
            result = TRUE;
        }
    }
    return result;
}

void InitRacePointLinkCursor(Unk02080d34 *racePointLinkCursor, u16 kartIndex) {
    racePointLinkCursor->mLinkCursor.mLink = gCourseMap->mRaceRoute0FirstLink;
    racePointLinkCursor->mLinkCursor.mPreviousLink = racePointLinkCursor->mLinkCursor.mLink->mUnk_0c;
    racePointLinkCursor->mLinkCursor.mDirection = data_021557ec;
    VEC_Subtract(racePointLinkCursor->mLinkCursor.mLink->mUnk_18,
                 racePointLinkCursor->mLinkCursor.mPreviousLink->mUnk_18, &racePointLinkCursor->mLinkCursor.mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&racePointLinkCursor->mLinkCursor.mDirection,
                                       &racePointLinkCursor->mLinkCursor.mDirection);
    racePointLinkCursor->mLinkCursor.mRequestedLink = NULL;
    racePointLinkCursor->mLinkCursor.mUnk_18 = FALSE;
    racePointLinkCursor->mKartIndex = kartIndex;
    racePointLinkCursor->mUnk_1e = 0;
}

void ResetPointLinkCursor(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mLink = pointLink;
    linkCursor->mPreviousLink = linkCursor->mLink->mUnk_0c;
    linkCursor->mRequestedLink = NULL;
    linkCursor->mUnk_18 = FALSE;
    linkCursor->mDirection = data_021557ec;
    VEC_Subtract(linkCursor->mLink->mUnk_18, linkCursor->mPreviousLink->mUnk_18, &linkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
}

s16 func_02080cc0(LinkCursor *linkCursor) {
    return *(s16 *) linkCursor->mLink->mUnk_20;
}

BOOL IsWithinPointLinkDistance(PointLinkCursor *pointLinkCursor, Vec3 *position) {
    Vec3 offset;
    s32 radius;
    BOOL result;
    Unk02080b1c_00 *link = pointLinkCursor->mLink;

    result = FALSE;
    radius = link->mUnk_1c;
    VEC_Subtract(link->mUnk_18, position, &offset);
    offset.y = result;
    if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z < (s64) radius * radius) {
        result = TRUE;
    }
    return result;
}

BOOL IsPastPointLink(PointLinkCursor *pointLinkCursor, Vec3 *position) {
    Vec3 offset;
    BOOL result;
    Vec3 *linkPosition = pointLinkCursor->mLink->mUnk_18;

    result = FALSE;
    if (pointLinkCursor->mDirection.x != 0 || pointLinkCursor->mDirection.y != 0 ||
        pointLinkCursor->mDirection.z != 0) {
        VEC_Subtract(position, linkPosition, &offset);
        if (Vec3DotUnrounded(&pointLinkCursor->mDirection, &offset) > 0) {
            result = TRUE;
        }
    }
    return result;
}

void AdvancePointLinkCursor(PointLinkCursor *pointLinkCursor) {
    u16 nextIndex = 0;
    u16 nextLinkCount;
    u32 randomValue;
    RandomState64 *kartAiRandom;

    if (!(GetKart(pointLinkCursor->mKartIndex)->mUnk_4c & 0x10000000)) {
        nextLinkCount = pointLinkCursor->mLink->mNextCount;
        if (nextLinkCount > 1) {
            kartAiRandom = GetKartAiRandom();
            if (nextLinkCount == 0) {
                randomValue = 0;
            } else {
                kartAiRandom->mValue =
                    (s64) kartAiRandom->mMultiplier * (s64) kartAiRandom->mValue + kartAiRandom->mIncrement;
                randomValue = (nextLinkCount == 0) ? (u32) (kartAiRandom->mValue >> 32)
                                                   : (u32) (((kartAiRandom->mValue >> 32) * (u32) nextLinkCount) >> 32);
            }
            nextIndex = randomValue;
        }
    }
    pointLinkCursor->mPreviousLink = pointLinkCursor->mLink;
    pointLinkCursor->mLink = pointLinkCursor->mLink->mUnk_00[nextIndex];
    VEC_Subtract(pointLinkCursor->mLink->mUnk_18, pointLinkCursor->mPreviousLink->mUnk_18,
                 &pointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

void AdvancePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    VEC_Subtract(linkCursor->mLink->mUnk_18, linkCursor->mPreviousLink->mUnk_18, &linkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
}

void SetRequestedLinkToPreviousIfNone(LinkCursor *linkCursor) {
    if (linkCursor->mRequestedLink == NULL) {
        linkCursor->mRequestedLink = linkCursor->mPreviousLink;
        linkCursor->mUnk_18 = FALSE;
    }
}

void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 c) {
    PointLink *bestLink = NULL;
    u16 pointIndex;
    u16 candidateIndex;
    s32 slot;
    s32 bestDot;
    s32 d;
    PointLink *firstLink = gCourseMap->mFirstBattlePointLink;
    PointLink *nearestLinks[3] = {0, 0, 0};
    s32 nearestDistances[3];
    Vec3 offset;
    Vec3 directionToLink;

    nearestDistances[0] = nearestDistances[1] = nearestDistances[2] = 0xc8000;
    bestDot = -0x1000;
    for (pointIndex = 0; pointIndex < gCourseMap->mBattlePointCount; pointIndex++) {
        VEC_Subtract(&gCourseMap->mBattlePoints[pointIndex].mPos, position, &offset);
        d = VEC_Mag(&offset);
        if (d < 0xc8000) {
            for (slot = 0; slot < 3; slot++) {
                if (d < nearestDistances[slot]) {
                    nearestDistances[slot] = d;
                    nearestLinks[slot] = &firstLink[pointIndex];
                    break;
                }
            }
        }
    }
    for (candidateIndex = 0; candidateIndex < 3; candidateIndex++) {
        if (nearestLinks[candidateIndex] != NULL) {
            VEC_Subtract(nearestLinks[candidateIndex]->mUnk_20, position, &directionToLink);
            if ((s64) directionToLink.x * directionToLink.x + (s64) directionToLink.y * directionToLink.y +
                    (s64) directionToLink.z * directionToLink.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&directionToLink, &directionToLink);
            }
            d = Vec3DotUnrounded(&directionToLink, direction);
            if (d >= bestDot) {
                bestLink = nearestLinks[candidateIndex];
                bestDot = d;
            }
        }
    }
    linkCursor->mLink = bestLink;
    linkCursor->mPreviousLink = bestLink;
    linkCursor->mDirection = data_021557ec;
    linkCursor->mRequestedLink = NULL;
    linkCursor->mUnk_18 = FALSE;
}

void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = pointLink;
    linkCursor->mLink = linkCursor->mPreviousLink;
    linkCursor->mDirection = data_021557ec;
    linkCursor->mRequestedLink = NULL;
    linkCursor->mUnk_18 = FALSE;
}

void AdvanceBattlePointLinkCursor(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 kartIndex,
                                  MapObject *targetShine, s32 targetKartIndex) {
    s32 bestFallbackDot;
    PointLink *nextLink;
    s32 lowestTargetDot;
    PointLink *currentLink = linkCursor->mLink;
    u16 fallbackCount = 0;
    PointLink *candidateLinks[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u16 n1;
    s32 bestTargetDot;
    Kart *kart;
    PointLink *neighborLink;
    s32 targetDot;
    u16 candidateCount;
    u16 chosenIndex;
    u16 pairIndex;
    u32 randomValue;
    BOOL v3;
    PointLink *fallbackLink;
    u16 n0;
    s32 directionDot;
    u16 linkIndex;
    u8 neighborLinkIndex;
    RandomState64 *kartAiRandom;
    u16 k;
    Vec3 directionToTargetShine;
    Vec3 directionToLink;
    Vec3 directionToTargetKart;
    Vec3 directionToCandidateLink;
    Vec3 directionsToCandidates[2];
    Vec3 neighborLinkDirection;

    bestFallbackDot = -0x1000;
    lowestTargetDot = 0x1000;
    nextLink = NULL;
    bestTargetDot = bestFallbackDot;
    fallbackLink = NULL;
    if (linkCursor->mLink->mLinkCount == 1) {
        nextLink = linkCursor->mLink->mLinks[0];
    } else {
        PointLink *v4[2] = {0, 0};

        candidateCount = 0;
        n1 = 0;
        n1 = n1;
        n0 = 0;
        if (targetShine != NULL) {
            k = 0;
            VEC_Subtract(&targetShine->mPos, &GetKart(kartIndex)->mPos, &directionToTargetShine);
            if ((s64) directionToTargetShine.x * directionToTargetShine.x +
                    (s64) directionToTargetShine.y * directionToTargetShine.y +
                    (s64) directionToTargetShine.z * directionToTargetShine.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&directionToTargetShine, &directionToTargetShine);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VEC_Subtract(linkCursor->mLink->mLinks[linkIndex]->mUnk_20, &GetKart(kartIndex)->mPos,
                             &directionToLink);
                if ((s64) directionToLink.x * directionToLink.x + (s64) directionToLink.y * directionToLink.y +
                        (s64) directionToLink.z * directionToLink.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&directionToLink, &directionToLink);
                }
                directionDot = Vec3DotUnrounded(&directionToLink, direction);
                if (directionDot >= -0x800) {
                    targetDot = VEC_DotProduct(&directionToTargetShine, &directionToLink);
                    if (targetDot > bestTargetDot || k == 0) {
                        bestTargetDot = targetDot;
                        k++;
                        nextLink = linkCursor->mLink->mLinks[linkIndex];
                    }
                } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                    bestFallbackDot = directionDot;
                    fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                    fallbackCount++;
                }
            }
        } else if (targetKartIndex != -1) {
            n1 = (u16) n1;
            if (GetKart(targetKartIndex)->mUnk_4c & 0x40) {
                v3 = TRUE;
            } else {
                v3 = FALSE;
            }
            kart = GetKart(kartIndex);
            VEC_Subtract(&GetKart(targetKartIndex)->mPos, &kart->mPos, &directionToTargetKart);
            if ((s64) directionToTargetKart.x * directionToTargetKart.x +
                    (s64) directionToTargetKart.y * directionToTargetKart.y +
                    (s64) directionToTargetKart.z * directionToTargetKart.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&directionToTargetKart, &directionToTargetKart);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VEC_Subtract(linkCursor->mLink->mLinks[linkIndex]->mUnk_20, &GetKart(kartIndex)->mPos,
                             &directionToCandidateLink);
                if ((s64) directionToCandidateLink.x * directionToCandidateLink.x +
                        (s64) directionToCandidateLink.y * directionToCandidateLink.y +
                        (s64) directionToCandidateLink.z * directionToCandidateLink.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&directionToCandidateLink, &directionToCandidateLink);
                }
                directionDot = Vec3DotUnrounded(&directionToCandidateLink, direction);
                if (directionDot >= -0x800) {
                    if (v3 == FALSE) {
                        targetDot = VEC_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot > bestTargetDot || n0 == 0) {
                            bestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            n0++;
                        }
                    } else {
                        targetDot = VEC_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot < lowestTargetDot || n1 == 0) {
                            lowestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            n1++;
                        }
                    }
                } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                    bestFallbackDot = directionDot;
                    fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                    fallbackCount++;
                }
            }
        } else {
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink != ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex] &&
                    !(linkCursor->mLink->mUnk_2e & (1 << (u8) linkIndex))) {
                    v4[n0] = ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex];
                    n0++;
                    n1 = 1;
                }
            }
            if (n1 != 0) {
                chosenIndex = 0;
                if (n0 > 1) {
                    for (pairIndex = 0; pairIndex < 2; pairIndex++) {
                        VEC_Subtract(v4[pairIndex]->mUnk_20, linkCursor->mLink->mUnk_20,
                                     &directionsToCandidates[pairIndex]);
                        if ((s64) directionsToCandidates[pairIndex].x * directionsToCandidates[pairIndex].x +
                                (s64) directionsToCandidates[pairIndex].y * directionsToCandidates[pairIndex].y +
                                (s64) directionsToCandidates[pairIndex].z * directionsToCandidates[pairIndex].z >=
                            0x10) {
                            Vec3NormalizeAndGetLengthUnchecked(&directionsToCandidates[pairIndex],
                                                               &directionsToCandidates[pairIndex]);
                        }
                    }
                    if (Vec3DotUnrounded(&directionsToCandidates[0], direction) <
                        Vec3DotUnrounded(&directionsToCandidates[1], direction)) {
                        chosenIndex = 1;
                    }
                }
                candidateLinks[0] = v4[chosenIndex];
                candidateCount = 1;
            } else {
                for (linkIndex = 0; linkIndex < ((const PointLink *) linkCursor->mLink)->mLinkCount; linkIndex++) {
                    if (linkCursor->mPreviousLink != ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex] &&
                        (linkCursor->mLink->mUnk_2e & (1 << (u8) linkIndex))) {
                        neighborLinkDirection = data_021557ec;
                        neighborLink = linkCursor->mLink->mLinks[linkIndex];
                        for (neighborLinkIndex = 0; neighborLinkIndex < neighborLink->mLinkCount; neighborLinkIndex++) {
                            if (!(neighborLink->mUnk_2e & (1 << neighborLinkIndex)) &&
                                ((const LinkCursor *) linkCursor)->mLink != neighborLink->mLinks[neighborLinkIndex]) {
                                VEC_Subtract(neighborLink->mLinks[neighborLinkIndex]->mUnk_20, neighborLink->mUnk_20,
                                             &neighborLinkDirection);
                                if ((s64) neighborLinkDirection.x * (s64) neighborLinkDirection.x +
                                        (s64) neighborLinkDirection.y * (s64) neighborLinkDirection.y +
                                        (s64) neighborLinkDirection.z * (s64) neighborLinkDirection.z >=
                                    0x10) {
                                    Vec3NormalizeAndGetLengthUnchecked(&neighborLinkDirection, &neighborLinkDirection);
                                }
                                break;
                            }
                        }
                        directionDot = Vec3DotUnrounded(&neighborLinkDirection, direction);
                        if (directionDot >= -0x800) {
                            candidateLinks[candidateCount] = linkCursor->mLink->mLinks[linkIndex];
                            candidateCount++;
                        } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                            bestFallbackDot = directionDot;
                            fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                            fallbackCount++;
                        }
                    }
                }
            }
        }
        if (nextLink == NULL) {
            if (candidateCount == 0) {
                nextLink = fallbackLink;
            } else {
                if (candidateCount == 1) {
                    k = 0;
                } else {
                    kartAiRandom = GetKartAiRandom();
                    if (candidateCount == 0) {
                        randomValue = 0;
                    } else {
                        kartAiRandom->mValue =
                            kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
                        if (candidateCount == 0) {
                            randomValue = kartAiRandom->mValue >> 32;
                        } else {
                            randomValue = ((kartAiRandom->mValue >> 32) * (u32) candidateCount) >> 32;
                        }
                    }
                    k = randomValue;
                }
                nextLink = candidateLinks[k];
            }
        }
    }
    linkCursor->mLink = nextLink;
    linkCursor->mPreviousLink = currentLink;
    linkCursor->mDirection = data_021557ec;
    VEC_Subtract(linkCursor->mLink->mUnk_20, linkCursor->mPreviousLink->mUnk_20, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

s32 GetBattlePointLinkSpeedLimit(LinkCursor *linkCursor) {
    s32 result = 0;
    s16 unscaledSpeedLimit = *linkCursor->mLink->mUnk_28;

    if (unscaledSpeedLimit != 0) {
        result = ((s64) unscaledSpeedLimit * 0x28f5c) >> 12;
    }
    return result;
}

void AdvanceBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    linkCursor->mDirection = data_021557ec;
    VEC_Subtract(linkCursor->mLink->mUnk_20, linkCursor->mPreviousLink->mUnk_20, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, Unk02080b1c_00 *link) {
    cursor->mDirection = data_021557ec;
    cursor->mPreviousLink = link;
    cursor->mLink = cursor->mPreviousLink->mUnk_00[0];
    VEC_Subtract(cursor->mLink->mUnk_18, cursor->mPreviousLink->mUnk_18, &cursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&cursor->mDirection, &cursor->mDirection);
    cursor->mUnk_14 = 0;
    cursor->mUnk_18 = 0;
    cursor->mKartIndex = kartIndex;
}
