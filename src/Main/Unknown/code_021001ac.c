#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02100700.h"
#include "Main/Unknown/code_02100704.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02100b78.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02100b84.h"
#include "Main/Unknown/code_02100dd8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6a74.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021025d8.h"
#include "01/code_021a2034.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void func_02102668(Unk02102668 *inUse) {
    inUse->mUnk_170 = 0x1u;
}

void ResetItemTeresa(Unk021025d8 *teresa) {
    UnkFunc *const *stateTable;
    teresa->mUnk_154 = 0x13;
    teresa->mUnk_158 = 0;
    stateTable = (UnkFunc *const *) gItemTeresaStateTable;
    teresa->mUnk_15c = 0;
    teresa->mUnk_160 = 0xe;
    InitStateMachine(teresa->mUnk_12c, stateTable, 7, teresa);
    teresa->mUnk_140 = 8;
    teresa->mUnk_144 = 0;
    FreeItemObjectCollisionSlot((s32) teresa);
    teresa->mUnk_24c = 0;
    teresa->mUnk_250 = 0xffffffff;
    teresa->mUnk_254 = 0x12;
    teresa->mUnk_258 = 0xffffffff;
    teresa->mUnk_25c = 0x12;
    teresa->mUnk_260 = 0xffffffff;
    teresa->mUnk_264 = 0xffffffff;
    teresa->mUnk_268 = 0;
    teresa->mUnk_26c = 0;
    teresa->mUnk_270 = 0;
}

static inline u32 func_02101f7c_inline_2(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    }
    return ((random->mValue >> 32) * range) >> 32;
}

static inline s32 func_02101f7c_inline(KartItems *kartItems, RaceSetup *raceSetup, s32 teamIndex, u16 kartIndex) {
    KartItems *entry;
    Kart *kart;
    BOOL v2;
    s32 l;

    l = 1;
    v2 = TRUE;
    entry = &kartItems[kartIndex];
    kart = entry->mKart;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
        v2 = FALSE;
    }
    if (v2 == FALSE && (kart->mUnk_4c & 0x10000800) == 0) {
        l = 0;
    }
    if (l | ((kart->mUnk_4c & 0x40) ? 1 : 0)) {
        v2 = FALSE;
    } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
        v2 = FALSE;
    } else {
        v2 = FALSE;
        if (entry->mHeldItem.mItemInfoIndex != 0x13 && entry->mHeldItem.mObjectStartFramesLeft == 0) {
            v2 = entry->mHeldItem.mItemInfoIndex != 0x10;
        }
    }
    return v2;
}

void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 teamIndex) {
    u16 cumulativeWeights[7];
    u16 candidateKarts[7];
    u32 kartCount;
    RaceProgress *raceProgress;
    u32 rankBehind;
    u16 kartIndex;
    u16 randomValue;
    RandomState64 *random;
    u16 index;
    s32 candidateCount;
    u16 weightSum;
    u16 *weightCursor;
    u32 rankAhead;
    KartItems *v2;
    RaceSetup *v3;
    KartItems *kartItems;
    RaceSetup *raceSetup;

    kartCount = gRaceSetup->mKartCount;
    weightSum = candidateCount = 0;
    weightCursor = data_0215a154;
    rankBehind = rankAhead =
        GetKartRank((u16) ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00) : 8));
    if (teresa->mUnk_148 != FALSE) {
        raceProgress = gRaceProgress;
        kartItems = gKartItems;
        raceSetup = gRaceSetup;
        do {
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankAhead - 1];
                if (func_02101f7c_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankBehind - 1];
                if (func_02101f7c_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    } else {
        raceProgress = gRaceProgress;
        v2 = gKartItems;
        v3 = gRaceSetup;
        do {
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankBehind - 1];
                if (func_02101f7c_inline(v2, v3, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankAhead - 1];
                if (func_02101f7c_inline(v2, v3, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    }
    random = &raceProgress->mRandom;
    randomValue = weightSum == 0 ? 0 : func_02101f7c_inline_2(random, weightSum);
    for (index = 0; index < candidateCount; index++) {
        if (randomValue < cumulativeWeights[index]) {
            teresa->mPickedKartIndex = candidateKarts[index];
            return;
        }
    }
}

void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 teamIndex) {
    RaceProgress *raceProgress;
    RandomState64 *random;
    s32 endIndex;
    s32 rowIndex;
    u32 kartCount;
    s32 skippedKartIndex;
    KartItems *kartItems;
    RaceSetup *raceSetup;
    s32 kartIndex;
    KartItems *entry;
    Kart *kart;
    s32 l;
    s32 n;
    u8 *row;

    raceProgress = gRaceProgress;
    random = &raceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    raceSetup = gRaceSetup;
    rowIndex = (u16) (((u64) (u32) (random->mValue >> 32) * 8) >> 32);
    endIndex = rowIndex + 8;
    kartCount = raceSetup->mKartCount;
    skippedKartIndex =
        (u16) ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00) : 8);
    if (rowIndex >= endIndex) {
        return;
    }
    kartItems = gKartItems;
    row = &data_0215a164[rowIndex];
    do {
        kartIndex = *row;
        if (kartIndex < kartCount && kartIndex != skippedKartIndex) {
            entry = &kartItems[kartIndex];
            kart = entry->mKart;
            n = l = 1;
            if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
                n = 0;
            }
            if (n == 0 && (kart->mUnk_4c & 0x10000800) == 0) {
                l = 0;
            }
            if (l | ((kart->mUnk_4c & 0x40) ? 1 : 0)) {
                l = 0;
            } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                l = 0;
            } else {
                l = 0;
                if (entry->mHeldItem.mItemInfoIndex != 0x13 && entry->mHeldItem.mObjectStartFramesLeft == 0) {
                    l = entry->mHeldItem.mItemInfoIndex != 0x10;
                }
            }
            if (l != 0) {
                teresa->mPickedKartIndex = kartIndex;
                return;
            }
        }
        rowIndex++;
        row++;
    } while (rowIndex < endIndex);
}

void InitItemTeresa(Unk02101d18 *inUse, ItemTeresa *teresa) {
    Kart *kart;

    kart = inUse->mUnk_10;
    StartKartTeresa(kart);
    func_020f8e3c((u32) kart, 0xf6);
    SetActiveItem(inUse->mUnk_0c, 0x10);
    InitCourseColorBlend(&teresa->mUnk_000.mColorBlend, 1);
    if (inUse->mUnk_0c->mFlags & 0x20) {
        teresa->mUnk_148 = FALSE;
    } else {
        teresa->mUnk_148 = TRUE;
    }
    SetStateMachineState(teresa->mUnk_12c, 0);
    teresa->mUnk_24c = TRUE;
}

void AdvanceItemTeresa(ItemTeresa *teresa) {
    Kart *kart;
    Vec3 *kartDrawMatrixPos;
    Vec3 offset;

    AdvanceStateMachine(teresa->mUnk_12c);
    VEC_Subtract(&teresa->mUnk_000.mPos, &teresa->mUnk_000.mPrevPos, &teresa->mUnk_000.mVelocity);
    if (teresa->mUnk_000.mUnk_d0 != &teresa->mUnk_000.mDrawPos) {
        return;
    }
    kart = teresa->mKart;
    if (kart == NULL) {
        return;
    }
    kartDrawMatrixPos = &kart->mDrawMatrixPos;
    VEC_Subtract(&teresa->mUnk_000.mPos, kartDrawMatrixPos, &offset);
    MTX_MultVec33(&offset, GetViewTransposeMatrix(), &offset);
    VEC_Add(kartDrawMatrixPos, &offset, &teresa->mUnk_000.mDrawPos);
}

void func_02101964(ItemTeresa *teresa, s32 a) {
    Kart *kart;
    Vec3 *position;
    s32 *camera;
    s32 *cameraSide;
    s32 delta[3];
    s32 k;
    BOOL m;
    s32 s;
    s32 c;
    s32 t;
    s32 n;

    kart = teresa->mKart;
    camera = GetCurrentCamera();
    position = &teresa->mUnk_000.mPos;
    k = m = TRUE;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
        k = 0;
    }
    if (k == 0 && (kart->mUnk_4c & 0x10000800) == 0) {
        m = FALSE;
    }
    if (m != FALSE) {
        if (teresa->mUnk_144 == FALSE && (teresa->mUnk_000.mFlags & 0x8000000) && teresa->mUnk_24c != FALSE) {
            teresa->mUnk_144 = TRUE;
            func_020fe694(0xb, teresa->mUnk_000.mId, 1, teresa->mState & 0xff);
        } else {
            teresa->mUnk_144 = TRUE;
        }
    }
    ((Vec3 *) delta)->x = position->x - (&teresa->mUnk_000.mVelocity)->x;
    delta[2] = position->z - (&teresa->mUnk_000.mVelocity)->z;
    if (teresa->mUnk_144 != FALSE) {
        VEC_Add(&teresa->mKartDrawMatrixPos, &teresa->mKartVelocity, &teresa->mKartDrawMatrixPos);
        teresa->mKartVelocity.x = ((s64) teresa->mKartVelocity.x * 0xeb8) >> 12;
        teresa->mKartVelocity.y = ((s64) teresa->mKartVelocity.y * 0xeb8) >> 12;
        teresa->mKartVelocity.z = ((s64) teresa->mKartVelocity.z * 0xeb8) >> 12;
        *position = teresa->mKartDrawMatrixPos;
    } else {
        *position = kart->mDrawMatrixPos;
        VEC_Subtract(position, &teresa->mKartDrawMatrixPos, &teresa->mKartVelocity);
        teresa->mKartDrawMatrixPos = *position;
        position->y -= kart->mHopHeight;
    }
    VEC_Add(position, (Vec3 *) &teresa->mOffsetX, position);
    cameraSide = camera + 3;
    if (teresa->mUnk_15c != FALSE) {
        s = 0xccd;
        c = 0x800;
    } else {
        s = 0x800;
        c = 0x400;
    }
    if (a != 0) {
        n = ((s64) * (s32 *) kart->mPhysicalParam * kart->mScale.z + 0x800) >> 12;
        position->x += (s32) (((s64) -n * cameraSide[0]) >> 12);
        position->z += (s32) (((s64) -n * cameraSide[2]) >> 12);
    }
    delta[0] -= position->x;
    delta[2] -= position->z;
    t = ((s64) cameraSide[0] * delta[0] + (s64) cameraSide[2] * delta[2]) >> 12;
    delta[0] = ((s64) cameraSide[0] * t) >> 12;
    delta[2] = ((s64) cameraSide[2] * t) >> 12;
    delta[0] = ((s64) delta[0] * s) >> 12;
    delta[2] = ((s64) delta[2] * s) >> 12;
    if (delta[0] > c) {
        delta[0] = c;
    } else if (delta[0] < -c) {
        delta[0] = -c;
    }
    if (delta[2] > c) {
        delta[2] = c;
    } else if (delta[2] < -c) {
        delta[2] = -c;
    }
    teresa->mOffsetX = delta[0] + (s32) teresa->mOffsetX;
    teresa->mOffsetZ = delta[2] + (s32) teresa->mOffsetZ;
}

void EnterItemTeresaState0(ItemTeresa *teresa) {
    teresa->mKart = GetKart((u16) (teresa->mUnk_000.mUnk_78 & ~0xff00));
    teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
    teresa->mKartVelocity = teresa->mKart->mVelocity;
    *(Vec3 *) &teresa->mOffsetX =
        (Vec3){0, (s32) (((s64) * (s32 *) teresa->mKart->mPhysicalParam * teresa->mKart->mScale.z + 0x800) >> 12), 0};
    teresa->mOffsetVelocityY = 0;
    teresa->mUnk_000.mAlpha = 0x1f;
    if (teresa->mKart->mUnk_48 & 1) {
        teresa->mUnk_000.mUnk_d0 = &teresa->mUnk_000.mDrawPos;
    }
}

void func_0210174c(ItemTeresa *teresa) {
    Vec3 v;
    Vec3 s;
    Vec3 *q;

    if (teresa->mPointIndex >= 0xb) {
        return;
    }
    if (AdvanceSegmentProgress(&teresa->mUnk_1a4.mUnk_00) != FALSE) {
        do {
            teresa->mPointIndex++;
            if (teresa->mPointIndex >= 0xb) {
                return;
            }
        } while (PushSegmentPoint(&teresa->mUnk_1a4, &data_0215a1c0[teresa->mPointIndex]) != 0);
    }
    GetSegmentProgressPoint(&teresa->mUnk_1a4, &s);
    SetSegmentProgressRate(&teresa->mUnk_1a4.mUnk_00, s.y);
    if (teresa->mUnk_000.mUnk_d0 == &teresa->mUnk_000.mDrawPos) {
        v = (Vec3){s.x};
    } else {
        s32 f = s.x;

        q = func_020e6b28();
        v.x = ((s64) q->x * f) >> 12;
        v.y = ((s64) q->y * f) >> 12;
        v.z = ((s64) q->z * f) >> 12;
    }
    v.y += s.z;
    VEC_Subtract(&v, (Vec3 *) &teresa->mOffsetX, &s);
    VEC_MultAdd(0x4f6, &s, (Vec3 *) &teresa->mOffsetX, (Vec3 *) &teresa->mOffsetX);
}

BOOL func_02101618(ItemTeresa *teresa, s32 a, s32 nextState) {
    s32 stateFrames;
    s32 fadeStartFrame;
    s32 fadeStep;

    stateFrames = teresa->mStateFrames;
    if (teresa->mUnk_15c != FALSE) {
        fadeStartFrame = -7;
        fadeStep = GetRaceUpdateFramesMod8() > 2;
        func_0210174c(teresa);
    } else {
        if (nextState < 7) {
            teresa->mOffsetVelocityY += 0x133;
            fadeStartFrame = 0x1c;
            fadeStep = 6;
        } else {
            fadeStartFrame = 0x14;
            fadeStep = 2;
            if (teresa->mOffsetVelocityY < 0) {
                teresa->mOffsetVelocityY += 0x2cd;
            } else {
                teresa->mOffsetVelocityY += 0x8f;
            }
        }
        teresa->mOffsetY += teresa->mOffsetVelocityY;
    }
    func_02101964(teresa, a);
    if (stateFrames > fadeStartFrame) {
        if (teresa->mUnk_000.mAlpha > 0) {
            teresa->mUnk_000.mAlpha -= fadeStep;
        }
        if (stateFrames >= (teresa->mUnk_15c != FALSE ? 0x37 : 0x28)) {
            if (nextState < 7) {
                if (teresa->mState == 0) {
                    teresa->mSavedOffsetY = teresa->mOffsetY;
                    teresa->mSavedOffsetVelocityY = teresa->mOffsetVelocityY;
                }
                teresa->mNextState = nextState;
                teresa->mNextStateRequested = 1;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_021014a0(ItemTeresa *teresa, s32 a, s32 nextState) {
    s32 stateFrames;
    u16 factor;

    stateFrames = teresa->mStateFrames;
    if (teresa->mUnk_15c != FALSE) {
        func_0210174c(teresa);
    } else if (teresa->mUnk_26c != FALSE) {
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = ((s64) teresa->mOffsetX * factor) >> 12;
        teresa->mOffsetZ = ((s64) teresa->mOffsetZ * factor) >> 12;
    } else {
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        teresa->mOffsetVelocityY += 0x133;
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = ((s64) teresa->mOffsetX * factor) >> 12;
        teresa->mOffsetZ = ((s64) teresa->mOffsetZ * factor) >> 12;
    }
    func_02101964(teresa, a);
    if (stateFrames > 7) {
        if (teresa->mUnk_000.mAlpha < 0x1f) {
            teresa->mUnk_000.mAlpha += 6;
        }
        if (stateFrames == 0x27) {
            if (teresa->mUnk_15c == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ;
            }
        } else if (stateFrames == 0x28) {
            if (teresa->mUnk_15c == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX - teresa->mOffsetVelocityX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ - teresa->mOffsetVelocityZ;
            }
            teresa->mNextState = nextState;
            teresa->mNextStateRequested = 1;
            teresa->mUnk_26c = FALSE;
        }
    }
    return stateFrames;
}

void UpdateItemTeresaState0(ItemTeresa *teresa) {
    func_02101618(teresa, 0, (teresa->mUnk_000.mFlags & 0x8000000) ? 1 : 2);
    if (!(teresa->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mUnk_144 != FALSE) {
        return;
    }
    if (teresa->mUnk_264 == 0xffffffff) {
        return;
    }
    if (teresa->mUnk_264 == 0 || teresa->mUnk_264 == 7) {
        teresa->mUnk_144 = TRUE;
        teresa->mUnk_264 = -1;
    }
}

void EnterItemTeresaState1(ItemTeresa *teresa) {
    if (teresa->mUnk_24c == FALSE) {
        return;
    }
    PickItemTeresaKartByRank(teresa, -1);
    func_020fe694(0xb, teresa->mUnk_000.mId, 0, teresa->mPickedKartIndex & 0xff);
    teresa->mUnk_250 = teresa->mPickedKartIndex;
    teresa->mUnk_24c = FALSE;
}

void UpdateItemTeresaState1(ItemTeresa *teresa) {
    s32 stateFrames;

    if (teresa->mUnk_250 == 0xffffffff) {
        return;
    }
    stateFrames = teresa->mStateFrames;
    if (teresa->mUnk_24c == FALSE && stateFrames < 0x28) {
        return;
    }
    teresa->mUnk_268 = stateFrames - 0x28;
    teresa->mPickedKartIndex = teresa->mUnk_250;
    teresa->mNextState = 2;
    teresa->mNextStateRequested = 1;
}

void EnterItemTeresaState2(ItemTeresa *teresa) {
    s32 *offset;
    Camera *camera;
    RaceSetup *raceSetup;
    void (*pickFunction)(ItemTeresa *, s32);
    int ownerKartIndex;

    offset = &teresa->mOffsetX;
    camera = GetCurrentCamera();
    if (!(teresa->mUnk_000.mFlags & 0x8000000)) {
        raceSetup = gRaceSetup;
        pickFunction = (raceSetup->mMode == MODE_BATTLE) ? PickItemTeresaKartBattle : PickItemTeresaKartByRank;
        if (raceSetup->mUseTeams != 0) {
            if ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0) {
                ownerKartIndex = (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00);
            } else {
                ownerKartIndex = 8;
            }
            pickFunction(teresa, raceSetup->mCurrentEntries[(u16) ownerKartIndex].mPlayer.mTeamIndex);
            if (teresa->mPickedKartIndex == 8) {
                pickFunction(teresa, -1);
            }
        } else {
            pickFunction(teresa, -1);
        }
    }
    if (teresa->mUnk_000.mUnk_d0 == &teresa->mUnk_000.mDrawPos) {
        teresa->mUnk_000.mPos = teresa->mUnk_000.mDrawPos;
        teresa->mUnk_000.mUnk_d0 = &teresa->mUnk_000.mPos;
    }
    if (teresa->mPickedKartIndex < 8) {
        teresa->mKart = GetKart(teresa->mPickedKartIndex);
        teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
        teresa->mKartVelocity = teresa->mKart->mVelocity;
        teresa->mUnk_144 = FALSE;
        func_020f8e3c((u32) teresa->mKart, 0xf4);
        if (teresa->mKart->mUnk_48 & 1) {
            teresa->mUnk_000.mUnk_d0 = &teresa->mUnk_000.mDrawPos;
        }
    }
    offset[0] = ((s64) camera->mSide.x * -0xa000) >> 12;
    offset[2] = ((s64) camera->mSide.z * -0xa000) >> 12;
    offset[0] += (s32) (((s64) camera->mForward.x * -0x11000) >> 12);
    offset[2] += (s32) (((s64) camera->mForward.z * -0x11000) >> 12);
    teresa->mOffsetVelocityY = -teresa->mOffsetVelocityY;
    teresa->mStallFrames = 0;
}

s32 func_02101014(ItemTeresa *teresa) {
    KartItems *pickedKartItems;
    Kart *kart;
    HeldItem *heldItem;
    s32 a;
    s32 b;
    enum { K0 } itemInfoIndex;

    pickedKartItems = &gKartItems[(u16) teresa->mPickedKartIndex];
    kart = pickedKartItems->mKart;
    heldItem = &pickedKartItems->mHeldItem;
    if (heldItem->mItemInfoIndex == 0x13 || heldItem->mObjectStartFramesLeft != 0) {
        return 0xf;
    }
    if (heldItem->mItemInfoIndex == 0x10) {
        return 0xf;
    }
    if (teresa->mUnk_144 != FALSE) {
        return 0xf;
    }
    a = b = 1;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
        a = 0;
    }
    if (a == 0 && (kart->mUnk_4c & 0x10000800) == 0) {
        b = 0;
    }
    if (b | ((kart->mUnk_4c & 0x40) ? 1 : 0)) {
        return 0xf;
    }
    if (teresa->mUnk_000.mFlags & 0x8000000) {
        teresa->mItemInfoIndex = heldItem->mItemInfoIndex;
        teresa->mItemCount = heldItem->mObjectCount;
        func_0205a5b0(((u8 *) gParticipantKartMap)[teresa->mPickedKartIndex & 0xff]);
    } else {
        RemoveHeldItem(heldItem, &teresa->mItemInfoIndex, &teresa->mItemCount);
    }
    func_02068a10(kart);
    itemInfoIndex = teresa->mItemInfoIndex;
    return gItemInfos[itemInfoIndex].mObjectKind;
}

void UpdateItemTeresaState2(ItemTeresa *teresa) {
    u32 framesLeft;
    BOOL k;

    if (teresa->mPickedKartIndex == 8) {
        if (teresa->mStateFrames > 0x6e) {
            teresa->mItemObjectKind = 0xf;
            teresa->mNextState = (teresa->mUnk_000.mFlags & 0x8000000) ? 4 : 5;
            teresa->mNextStateRequested = 1;
        }
    } else {
        framesLeft = 0x28 - func_021014a0(teresa, 1, 3);
        if (teresa->mItemObjectKind == 0xe) {
            if (teresa->mUnk_24c != FALSE) {
                if (framesLeft == 0xa) {
                    teresa->mItemObjectKind = func_02101014(teresa);
                    teresa->mItemModelAlpha = 0;
                    if (teresa->mUnk_000.mFlags & 0x8000000) {
                        func_020fe694(0xb, teresa->mUnk_000.mId, 2,
                                      ((teresa->mItemInfoIndex << 2) | teresa->mItemCount) & 0xff);
                    }
                }
            } else if (framesLeft <= 0xa) {
                if (teresa->mUnk_258 != -1) {
                    teresa->mItemInfoIndex = teresa->mUnk_254;
                    teresa->mItemCount = teresa->mUnk_258;
                    teresa->mUnk_254 = 0x12;
                    teresa->mUnk_258 = -1;
                    if (teresa->mItemInfoIndex == 0x13) {
                        teresa->mItemObjectKind = 0xf;
                    } else {
                        teresa->mItemObjectKind = gItemInfos[teresa->mItemInfoIndex].mObjectKind;
                        func_0205a5b0(((u8 *) gParticipantKartMap)[teresa->mPickedKartIndex & 0xff]);
                    }
                    teresa->mItemModelAlpha = 0;
                    k = TRUE;
                } else {
                    k = FALSE;
                }
                if (k == FALSE && framesLeft == 1) {
                    teresa->mStateFrames--;
                    teresa->mUnk_26c = TRUE;
                    teresa->mStallFrames++;
                    if (teresa->mStallFrames > 0x3c) {
                        teresa->mUnk_254 = 0x13;
                        teresa->mUnk_258 = 0;
                    }
                }
            }
        }
    }
    if (!(teresa->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mUnk_144 != FALSE) {
        return;
    }
    if (teresa->mUnk_264 == 0xffffffff) {
        return;
    }
    if (teresa->mUnk_264 == 2 || teresa->mUnk_264 == 7) {
        teresa->mUnk_144 = TRUE;
        teresa->mUnk_264 = -1;
    }
}

void EnterItemTeresaState3(Unk02100dd8 *teresa) {
    teresa->mUnk_19c = 0x0u;
}

void UpdateItemTeresaState3(ItemTeresa *teresa) {
    if (teresa->mItemModelAlpha < 0x1f) {
        teresa->mItemModelAlpha += 5;
    }
    teresa->mOffsetVelocityX = ((s64) teresa->mOffsetVelocityX * 0xf85) >> 12;
    teresa->mOffsetVelocityZ = ((s64) teresa->mOffsetVelocityZ * 0xf85) >> 12;
    if (teresa->mStateFrames == 0x12) {
        if (teresa->mUnk_19c == 0) {
            teresa->mUnk_19c = -0x1ae;
            teresa->mUnk_1a0 = teresa->mOffsetVelocityY;
        }
        teresa->mOffsetVelocityY += teresa->mUnk_19c;
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        func_02101964(teresa, 1);
        if (teresa->mUnk_19c >= 0 && teresa->mOffsetVelocityY >= teresa->mUnk_1a0) {
            return;
        }
        teresa->mStateFrames--;
        if (teresa->mUnk_19c >= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY < -0xc00) {
            teresa->mUnk_19c = 0x133;
            return;
        }
        if (teresa->mOffsetVelocityY <= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY >= -teresa->mUnk_19c) {
            return;
        }
        func_020f8e3c((u32) teresa->mKart, 0xf5);
    } else {
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
        func_02101618(teresa, 1, (teresa->mUnk_000.mFlags & 0x8000000) ? 4 : 5);
        if (!(teresa->mUnk_000.mFlags & 0x8000000)) {
            return;
        }
        if (teresa->mUnk_24c != FALSE) {
            return;
        }
        if (teresa->mUnk_144 != FALSE) {
            return;
        }
        if (teresa->mUnk_264 == 0xffffffff) {
            return;
        }
        if (teresa->mUnk_264 - 2 <= 1) {
            teresa->mUnk_144 = TRUE;
            teresa->mUnk_264 = -1;
        }
    }
}

void EnterItemTeresaState4(ItemTeresa *teresa) {
    teresa->mUnk_268 = ((teresa->mUnk_000.mFlags & 0x10000000) ? 0xf : 0) - teresa->mUnk_268;
    teresa->mUnk_24c = FALSE;
}

void UpdateItemTeresaState4(ItemTeresa *teresa) {
    teresa->mUnk_268--;
    if (teresa->mUnk_268 >= 0) {
        return;
    }
    teresa->mUnk_24c = (teresa->mUnk_000.mFlags & 0x10000000) == 0;
    teresa->mNextState = 5;
    teresa->mNextStateRequested = 1;
}

void SetItemTeresaPosPointerToDrawPos(ItemTeresa *teresa) {
    teresa->mUnk_000.mUnk_d0 = &teresa->mUnk_000.mDrawPos;
}

void func_02100b54(ItemTeresa *teresa) {
    if (teresa->mUnk_000.mUnk_d0 == &teresa->mUnk_000.mDrawPos) {
        teresa->mUnk_000.mPos = teresa->mUnk_000.mDrawPos;
        teresa->mUnk_000.mUnk_d0 = &teresa->mUnk_000.mPos;
    }
}

void EnterItemTeresaState5(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;
    void (*positionFunction)(ItemTeresa *);

    if ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = &gKartItems[(u16) ownerKartIndex];
    teresa->mKart = ownerKartItems->mKart;
    teresa->mUnk_144 = FALSE;
    if (teresa->mUnk_24c != FALSE) {
        if (ownerKartItems->mActiveItem == 0x10) {
            teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
            teresa->mKartVelocity = teresa->mKart->mVelocity;
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        } else {
            teresa->mUnk_144 = TRUE;
            if (teresa->mUnk_000.mFlags & 0x8000000) {
                func_020fe694(0xb, teresa->mUnk_000.mId, 1, 5);
            }
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        }
    }
    if (teresa->mItemObjectKind == 0xf) {
        InitSegmentPoints(&teresa->mUnk_1a4, data_0215a1c0, data_0215a1c0[0].y);
        teresa->mPointIndex = 3;
        teresa->mUnk_15c = TRUE;
    } else {
        teresa->mOffsetVelocityY = -teresa->mSavedOffsetVelocityY;
        teresa->mOffsetY = teresa->mSavedOffsetY;
    }
    if (teresa->mUnk_144 == FALSE) {
        func_020f8e3c((u32) teresa->mKart, 0xf7);
    }
    teresa->mStallFrames = 0;
    positionFunction = (teresa->mKart->mUnk_48 & 1) ? SetItemTeresaPosPointerToDrawPos : func_02100b54;
    positionFunction(teresa);
}

void UpdateItemTeresaState5(ItemTeresa *teresa) {
    s32 ownerKartIndex;
    KartItems *ownerKartItems;
    u32 framesLeft;
    BOOL k;
    s32 startOffsetX;
    s32 startOffsetZ;

    if ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = &gKartItems[(u16) ownerKartIndex];
    if (teresa->mUnk_24c != FALSE && ownerKartItems->mActiveItem != 0x10 && teresa->mItemCount != -0x40) {
        teresa->mUnk_144 = TRUE;
        if (teresa->mUnk_000.mFlags & 0x8000000) {
            func_020fe694(0xb, teresa->mUnk_000.mId, 1, 5);
        }
    } else {
        framesLeft = 0x28 - func_021014a0(teresa, teresa->mUnk_15c == FALSE ? 1 : 0, 6);
        if (framesLeft < 7) {
            if (teresa->mItemModelAlpha > 0) {
                teresa->mItemModelAlpha -= 5;
            }
            if (framesLeft == 1) {
                if (teresa->mUnk_24c == FALSE) {
                    if (teresa->mUnk_260 == -1) {
                        k = FALSE;
                    } else {
                        teresa->mItemInfoIndex = teresa->mUnk_25c;
                        teresa->mItemCount = teresa->mUnk_260;
                        teresa->mUnk_25c = 0x12;
                        teresa->mUnk_260 = -1;
                        k = TRUE;
                    }
                    if (k == FALSE) {
                        teresa->mStateFrames--;
                        teresa->mUnk_26c = TRUE;
                        teresa->mStallFrames++;
                        if (teresa->mStallFrames > 0x3c) {
                            teresa->mUnk_25c = 0x13;
                            teresa->mUnk_260 = -0x40;
                            teresa->mItemObjectKind = 0xe;
                        }
                        goto skip;
                    }
                }
                ownerKartItems->mActiveItem = 0x13;
                if (teresa->mItemInfoIndex != 0x13) {
                    if (teresa->mUnk_24c == FALSE) {
                        func_0205a548(((u8 *) gParticipantKartMap)[ownerKartItems->mKartIndex & 0xff],
                                      teresa->mItemInfoIndex, teresa->mItemCount);
                    } else {
                        SetHeldItemWithCount(&ownerKartItems->mHeldItem, teresa->mItemInfoIndex, teresa->mItemCount);
                    }
                    teresa->mItemInfoIndex = 0x13;
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = 0xe;
                    func_020f8e3c((u32) ownerKartItems->mKart, 0xf8);
                } else {
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = 0xe;
                }
                if ((teresa->mUnk_000.mFlags & 0x8000000) && teresa->mUnk_24c != FALSE) {
                    func_020fe694(
                        0xb, teresa->mUnk_000.mId, 3,
                        ((ownerKartItems->mHeldItem.mItemInfoIndex << 2) | ownerKartItems->mHeldItem.mObjectCount) &
                            0xff);
                }
            }
        }
    }
skip:
    if (teresa->mUnk_15c == FALSE && teresa->mUnk_144 != FALSE) {
        startOffsetX = teresa->mOffsetX;
        startOffsetZ = teresa->mOffsetZ;
        func_021014a0(teresa, 1, 6);
        teresa->mOffsetVelocityX = teresa->mOffsetX - startOffsetX;
        teresa->mOffsetVelocityZ = teresa->mOffsetZ - startOffsetZ;
        teresa->mNextState = 6;
        teresa->mNextStateRequested = 1;
        teresa->mUnk_26c = FALSE;
    }
    if (!(teresa->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mUnk_144 != FALSE) {
        return;
    }
    if (teresa->mUnk_264 == 0xffffffff) {
        return;
    }
    if (teresa->mUnk_264 == 5 || teresa->mUnk_264 == 7) {
        teresa->mUnk_144 = TRUE;
        teresa->mUnk_264 = -1;
    }
}

u32 EnterItemTeresaState6(u32 value) {
    return value;
}

void UpdateItemTeresaState6(ItemTeresa *teresa) {
    BOOL hasItem;
    s32 ownerKartIndex;

    hasItem = teresa->mItemInfoIndex != 0x13;
    if (teresa->mUnk_15c == FALSE) {
        teresa->mOffsetVelocityX = ((s64) teresa->mOffsetVelocityX * 0xf85) >> 12;
        teresa->mOffsetVelocityZ = ((s64) teresa->mOffsetVelocityZ * 0xf85) >> 12;
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
    }
    if (hasItem != FALSE) {
        if (teresa->mItemModelAlpha < 0x1f) {
            teresa->mItemModelAlpha += 8;
        }
    }
    if (func_02101618(teresa, teresa->mUnk_15c == FALSE ? 1 : 0, 7) != FALSE) {
        if (hasItem != FALSE) {
            if ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0) {
                ownerKartIndex = (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00);
            } else {
                ownerKartIndex = 8;
            }
            ((void (*)(s32 param_1, s32 param_2, s32 param_3)) RemoveReservedItemObjects)(
                teresa->mItemInfoIndex, teresa->mItemCount, (u16) ownerKartIndex);
        }
        ReleaseItemPoolObject(gItemPools + teresa->mUnk_000.mKind, &teresa->mUnk_000);
    }
    if (!(teresa->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mUnk_144 != FALSE) {
        return;
    }
    if (teresa->mUnk_264 == 0xffffffff) {
        return;
    }
    if (teresa->mUnk_264 - 5 <= 1) {
        teresa->mUnk_144 = TRUE;
        teresa->mUnk_264 = -1;
    }
}

void func_0210050c(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;

    if ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = &gKartItems[(u16) ownerKartIndex];
    if (ownerKartItems->mActiveItem != 0x10) {
        return;
    }
    if (teresa->mItemCount != -0x40) {
        ownerKartItems->mActiveItem = 0x13;
    }
}

void func_021004c4(void *cursor, ItemTeresa *teresa, void *toData) {
    CopyItemObjectData(cursor, teresa, toData);
    if (teresa == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    func_020fe8ac(teresa->mUnk_000.mKind);
}

void InitItemTeresaFromData(ItemTeresa *teresa) {
    int ownerKartIndex;

    func_020f8e78(teresa);
    InitCourseColorBlend(&teresa->mUnk_000.mColorBlend, 1);
    SetStateMachineState(teresa->mUnk_12c, 0);
    if ((teresa->mUnk_000.mUnk_78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    SetActiveItem(&gKartItems[(u16) ownerKartIndex], 0x10);
}

void func_021003e8(ItemTeresa *teresa, u32 sel, s32 value) {
    switch (sel) {
        case 0:
            teresa->mUnk_250 = value;
            if (teresa->mUnk_250 == gRaceSetup->mEntryIndex) {
                teresa->mUnk_24c = TRUE;
            }
            break;
        case 1:
            teresa->mUnk_264 = value;
            break;
        case 2:
            teresa->mUnk_254 = value >> 2;
            teresa->mUnk_258 = value & 3;
            break;
        case 3:
            teresa->mUnk_25c = value >> 2;
            teresa->mUnk_260 = value & 3;
            break;
    }
}

void DrawItemTeresa(ItemTeresa *teresa, s32 c, NsbmdModel *model) {
    s32 a;
    s32 itemModelAlpha;
    s32 b;
    s32 polygonId;
    u16 drawAlpha;
    s32 scale[3];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    NsbmdModel *itemModel;
    s32 index;
    s32 itemCount;

    if (teresa->mUnk_000.mAlpha <= 0) {
        return;
    }
    a = 0x1e;
    func_01ff9048(0x14, &a, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(teresa->mUnk_000.mUnk_d0), 0xc);
    scaleZ = teresa->mUnk_000.mScale.z;
    scaleY = teresa->mUnk_000.mScale.y;
    scaleX = teresa->mUnk_000.mScale.x;
    scale[0] = scaleX;
    scale[1] = scaleY;
    scale[2] = scaleZ;
    func_01ff9048(0x1b, scale, 3);
    if (teresa->mItemObjectKind < 0xe && teresa->mState >= 3) {
        itemModel = GetItemModel(teresa->mItemObjectKind);
        itemModelAlpha = teresa->mItemModelAlpha;
        itemCount = teresa->mItemCount;
        if (teresa->mUnk_000.mAlpha < 0x1f) {
            if (teresa->mUnk_000.mAlpha < itemModelAlpha) {
                itemModelAlpha = teresa->mUnk_000.mAlpha;
            }
        }
        if (itemModelAlpha > 0x1f) {
            itemModelAlpha = 0x1f;
        }
        if (itemModelAlpha < 1) {
            itemModelAlpha = 1;
        }
        func_01ff9048(0x11, NULL, 0);
        itemModel->mUnk_14 = itemModel->mUnk_14 & ~0x1f0000;
        itemModel->mUnk_14 = itemModel->mUnk_14 | ((u16) itemModelAlpha << 16);
        func_020e6a18(itemModel);
        index = 0;
        itemModel->mFrameIndex = 0;
        while (index < itemCount) {
            func_01ff9048(0x1c, &data_0215a190[itemCount == 2 ? 1 - index : index + 1], 3);
            polygonId = AllocPolygonIdWrapping();
            itemModel->mUnk_14 = itemModel->mUnk_14 & ~0x3f000000;
            itemModel->mUnk_14 = itemModel->mUnk_14 | (polygonId << 24);
            func_020e6854(itemModel, &teresa->mUnk_000.mPos, 1, 0x1f);
            index++;
        }
        b = 1;
        func_01ff9048(0x12, &b, 1);
        if (itemModelAlpha != 0x1f) {
            itemModel->mUnk_14 = itemModel->mUnk_14 & ~0x1f0000;
            itemModel->mUnk_14 = itemModel->mUnk_14 | 0x1f0000;
        }
    }
    polygonId = AllocPolygonIdWrapping();
    model->mUnk_14 = model->mUnk_14 & ~0x3f000000;
    model->mUnk_14 = model->mUnk_14 | (polygonId << 24);
    drawAlpha = teresa->mUnk_000.mAlpha;
    model->mUnk_14 = model->mUnk_14 & ~0x1f0000;
    model->mUnk_14 = model->mUnk_14 | (drawAlpha << 16);
    func_020ed588(&teresa->mUnk_000, model);
}
