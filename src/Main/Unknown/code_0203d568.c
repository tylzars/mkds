#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_0207a7fc.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_02147cd8.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_0203ca38.h"

#pragma opt_rebuildconditionals off

static inline s32 func_0203d568_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline void func_0203d568_b_inline(void) {
    u16 entryIndex;

    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL && GetNextSceneNumber() != 10 &&
        (GetNextSceneNumber() != 6 || data_0217b488->mUnk_74 != 2) && func_0203d568_inline(data_0217aa00) != 0) {
        for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
            if (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN &&
                (data_0217aa00->mParticipantMask & (1 << data_0217aa00->mUnk_1e8c[entryIndex])) == 0) {
                func_0204451c(entryIndex);
            }
        }
    }
}

static inline s32 func_0203d568_c_inline(void) {
    s32 r;
    if (data_0217aa08->mBusy == 0) {
        r = gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0;
    } else {
        r = 1;
    }
    return r;
}

static inline u16 func_0203df74_inline(u16 checkpoint) {
    u16 routeIndex;
    u16 firstEntry;
    u16 endEntry;
    CourseMapRoute *route;

    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        firstEntry = route->mFirstEntry;
        endEntry = firstEntry + route->mEntryCount;
        if (checkpoint >= firstEntry && checkpoint < endEntry) {
            return routeIndex;
        }
    }
    return 0;
}

static inline s16 func_0203df74_b_inline(RaceProgressKart *kart, s32 *outProgress, Vec3 *position) {
    u16 routeIndex;
    u16 checkpoint;
    u16 lo;
    u16 hi;
    CourseMapRoute *route;

    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        lo = route->mFirstEntry;
        hi = lo + route->mEntryCount;
        for (checkpoint = lo; checkpoint < hi; checkpoint++) {
            if (TryGetKartCheckpointProgress(kart, outProgress, position, routeIndex, checkpoint) != 0) {
                return checkpoint;
            }
        }
    }
    return -1;
}

static inline s32 func_0203df74_c_inline(CourseMapRoute *route, u16 checkpoint, s32 progress) {
    s32 x;
    s32 t;

    t = (checkpoint - route->mFirstEntry) << 12;
    if (route->mEntryCount == 0) {
        x = 0;
    } else {
        x = FX_Div(t + progress, route->mEntryCount << 12);
    }
    t = x + (route->mLapProgressBase << 12);
    return ((s64) t * gRaceProgress->mLapProgressScale + 0x800) >> 12;
}

static inline void func_0203e550_inline(s32 kartIndex) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        FinishRaceProgressKartWithEndKind(kartIndex, 0);
    }
}

void CompleteRaceProgressKartLap(RaceProgressKart *kart) {
    BOOL f;
    BOOL missionTestPassed;
    Unk021759c0_28 *s;
    EntryKartCounters *entryKartCounters;

    if (kart->mLap < 0x7fffffff) {
        kart->mLap = kart->mLap + 1;
    }
    kart->mCheckpointNumber = -1;
    kart->mInOrderCheckpointNumber = -1;
    f = FALSE;
    switch (kart->mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if (kart->mLap <= kart->mHighestLap) {
        return;
    }
    if ((kart->mFlags & 1) != 0) {
        AdvanceSceneSoundLap();
    }
    StoreRaceProgressKartLapTime(kart, kart->mLap > GetLapCount());
    kart->mHighestLap = kart->mLap;
    if ((kart->mFlags & 1) != 0) {
        func_020b1a34();
    }
    f = FALSE;
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        f = TRUE;
    } else {
        switch (gRaceSetup->mMissionKind) {
            case 2:
            case 4:
            case 6:
                f = TRUE;
                break;
        }
    }
    if (f == FALSE) {
        return;
    }
    if (kart->mHighestLap <= GetLapCount()) {
        return;
    }
    kart->mHighestLap = GetLapCount();
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        s = &gRaceSetup->mUnk_28_view;
        missionTestPassed = TRUE;
        entryKartCounters = GetEntryKartCounters();
        switch (s->mMissionKind) {
            case 4:
                if (s->mUnk_0f > (u32) entryKartCounters->mUnk_04) {
                    missionTestPassed = FALSE;
                }
                break;
            case 6:
                if (kart->mRank != 1) {
                    missionTestPassed = FALSE;
                }
                break;
        }
        if (missionTestPassed != FALSE) {
            func_0203e550_inline(kart->mIndex);
        } else {
            FinishRaceProgressKartWithEndKind(kart->mIndex, 4);
        }
    } else {
        if ((kart->mFlags & 1) == 0 && gRaceSetup->mMode == 5) {
            return;
        }
        kart->mFlags |= 0x40;
    }
}

void func_0203e4c4(u32 kartIndex, u32 b) {
    RaceProgressKart *kart;
    u16 finishRequest;

    kart = &gRaceProgress->mKarts[kartIndex];
    finishRequest = b != 0 ? 1 : 2;
    kart->mUnk_3c = (kart->mUnk_3c & ~0x300) | ((finishRequest & 3) << 8);
    if (gRaceProgress->mUnk_000[0].mFinishedCount + gRaceProgress->mUnk_000[0].mRemovedCount >=
        gRaceSetup->mKartCount) {
        FinishRaceProgress();
    }
}

void EnterRaceProgressKartCheckpoint(RaceProgressKart *kart, s32 checkpoint) {
    s16 checkpointNumber;

    checkpointNumber = gCourseMap->mCheckpoints[kart->mCheckpoint].mNumber;
    if (checkpointNumber != -1) {
        kart->mCheckpointNumber = checkpointNumber;
        if (kart->mInOrderCheckpointNumber + 1 >= checkpointNumber) {
            kart->mInOrderCheckpointNumber = checkpointNumber;
        }
    }
    if (checkpoint == 0 && kart->mInOrderCheckpointNumber >= gCourseMap->mNumberedCheckpointCount - 1) {
        CompleteRaceProgressKartLap(kart);
    } else if (kart->mCheckpoint == 0 && checkpoint == gCourseMap->mLastCheckpoint) {
        if (kart->mLap > -100) {
            kart->mLap = kart->mLap - 1;
        }
        kart->mCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
        kart->mInOrderCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
    }
    kart->mCheckpoint = checkpoint;
    kart->mRoute = func_0203df74_inline(checkpoint);
}

void UpdateRaceProgressKart(Vec3 *position, RaceProgressKart *kart) {
    s32 checkpointProgress;
    u16 checkpoint;
    u16 routeIndex;
    s16 p;
    s32 lapProgress;
    s32 k;
    CourseMapRoute *route;

    checkpoint = kart->mCheckpoint;
    routeIndex = kart->mRoute;
    p = checkpoint;
    checkpointProgress = 0;
    if (func_0207a5c4(kart->mIndex) != 0) {
        return;
    }
    if (TryGetKartCheckpointProgress(kart, &checkpointProgress, position, routeIndex, checkpoint) == 0) {
        if (checkpointProgress >= 0) {
            p = FindKartCheckpointForward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (p == -1) {
                p = FindKartCheckpointBackward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        } else {
            p = FindKartCheckpointBackward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (p == -1) {
                p = FindKartCheckpointForward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        }
        if (p == -1) {
            p = func_0203df74_b_inline(kart, &checkpointProgress, position);
        }
        if (p == -1) {
            return;
        }
        routeIndex = func_0203df74_inline(p);
    }
    route = &gCourseMap->mCheckpointRoutes[routeIndex];
    lapProgress = func_0203df74_c_inline(route, p, checkpointProgress);
    k = 0;
    if (p != -1) {
        if (gCourseMap->mNumberedCheckpointCount >= 1) {
            k = gRaceProgress->mCheckpointLapProgress[gCourseMap->mNumberedCheckpointCount - 1];
        }
        if (lapProgress <= gRaceProgress->mCheckpointLapProgress[kart->mInOrderCheckpointNumber + 1]) {
            EnterRaceProgressKartCheckpoint(kart, p);
        } else if (kart->mCheckpoint == 0 && lapProgress > k) {
            EnterRaceProgressKartCheckpoint(kart, p);
        } else {
            checkpointProgress = kart->mCheckpointProgress;
            lapProgress = func_0203df74_c_inline(route, kart->mCheckpoint, checkpointProgress);
        }
    }
    kart->mCheckpointProgress = checkpointProgress;
    kart->mLapProgress = lapProgress;
    k = ((kart->mLap - 1) << 12) + kart->mLapProgress;
    kart->mRaceProgress = ((s64) k * gRaceProgress->mRaceProgressScale + 0x800) >> 12;
}

void UpdateRaceProgressKarts(void) {
    Unk02040d24 t;
    s32 progressByKart[8];
    s32 progressByRank[8];
    s32 lapByRank[8];
    u16 kartByRank[8];
    Vec3 position;
    Vec3 forward;
    u16 i;
    s32 k;
    RaceProgressKart *kart;
    BOOL f;
    RaceProgress *raceProgress;
    Unk02040d24 *checkpointDirection;
    u16 m;
    s32 finishedCount;
    s32 notRemovedCount;
    s32 insertPos;
    s32 rankIndex;
    s32 progressKey;
    s32 lapKey;
    s32 kartKey;
    u16 g;
    RaceProgressKart *s;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        kart = &gRaceProgress->mKarts[i];
        if (kart->mStatus != 4 && gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            for (k = 0; k < 16; k++) {
                kart->mCheckpointTestedBits[k] = 0;
            }
            GetKartPos(&position, i);
            GetKartForward(GetKart(i), &forward);
            UpdateRaceProgressKart(&position, kart);
            f = FALSE;
            if (func_0207a7fc(kart->mIndex) == 0) {
                checkpointDirection = &gCourseMap->mCheckpoints[kart->mCheckpoint].mDirection;
                t.mUnk_00 = forward.x;
                t.mUnk_04 = forward.z;
                if (ComputeDotOfPairsRounded(&t, checkpointDirection) < -1394) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                kart->mFlags |= 4;
            } else {
                kart->mFlags &= ~4;
            }
            progressByKart[i] = kart->mRaceProgress;
        }
    }
    if (gRaceSetup->mKartCount > 1) {
        raceProgress = gRaceProgress;
        notRemovedCount = gRaceSetup->mKartCount - raceProgress->mUnk_000[0].mRemovedCount;
        finishedCount = raceProgress->mUnk_000[0].mFinishedCount;
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            rankIndex = raceProgress->mUnk_000[i].mUnk_50_0 - 1;
            progressByRank[rankIndex] = progressByKart[i];
            kartByRank[rankIndex] = i;
            lapByRank[rankIndex] = raceProgress->mUnk_000[(u32) i].mLap;
        }
        for (i = finishedCount + 1; i < notRemovedCount; i++) {
            progressKey = progressByRank[i];
            kartKey = kartByRank[i];
            lapKey = lapByRank[i];
            for (insertPos = i; insertPos > finishedCount &&
                                (lapByRank[insertPos - 1] < lapKey ||
                                 (lapKey == lapByRank[insertPos - 1] && progressByRank[insertPos - 1] < progressKey));
                 insertPos--) {
                lapByRank[insertPos] = lapByRank[insertPos - 1];
                progressByRank[insertPos] = progressByRank[insertPos - 1];
                kartByRank[insertPos] = kartByRank[insertPos - 1];
            }
            progressByRank[insertPos] = progressKey;
            kartByRank[insertPos] = kartKey;
        }
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (kartByRank[i] < 8) {
                gRaceProgress->mKarts[kartByRank[i]].mRank = i + 1;
            }
        }
        gRaceProgress->mUnk_000[kartByRank[0]].mFirstPlaceFrames++;
        for (g = 0; g < (u32) gRaceSetup->mKartCount; g++) {
            gRaceProgress->mKartAtRank[g] = kartByRank[g];
        }
        for (; g < 8; g++) {
            gRaceProgress->mKartAtRank[g] = -1;
        }
    } else {
        gRaceProgress->mUnk_000[0].mUnk_50_0 = 1;
        gRaceProgress->mUnk_000[0].mFirstPlaceFrames++;
        gRaceProgress->mKartAtRank[0] = 0;
        for (g = 1; g < 8; g++) {
            gRaceProgress->mKartAtRank[g] = -1;
        }
    }
    f = FALSE;
    switch (gRaceSetup->mRaceKind) {
        case RACE_KIND_DEMO:
        case 2:
        case RACE_KIND_STAFF_ROLL:
            f = TRUE;
            break;
        case RACE_KIND_NORMAL:
            if (func_02040bc0() != 0) {
                f = TRUE;
            }
            break;
    }
    gRaceProgress->mUnk_4f0 = f;
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        s = &gRaceProgress->mKarts[i];
        f = FALSE;
        switch (s->mStatus) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && (s->mFlags & 0x40) != 0) {
            FinishRaceProgressKart(s, 1);
            if (IsRaceEndConditionMet() != 0) {
                switch (gRaceSetup->mMode) {
                    case MODE_TIME_ATTACK:
                        break;
                    case MODE_BATTLE:
                        EliminateKartsUntilWinnerDecided();
                        break;
                    case MODE_MISSION_RUN:
                        FinishRemainingMissionRunKarts();
                        break;
                    case 5:
                        func_0203ecf0();
                        break;
                    default:
                        FinishRemainingRaceProgressKarts();
                        break;
                }
            }
            s->mFlags &= ~0x40;
        }
        if ((s->mFlags & 8) != 0) {
            s->mFlags &= ~8;
            if (gRaceSetup->mMode != MODE_MISSION_RUN) {
                func_0207a828(s->mIndex);
                if ((s->mFlags & 1) != 0) {
                    func_02110cc8(0);
                }
            }
        }
    }
}

void SetRankTimeFromRankTimeGp(RankTimeGp *rankTimeGp) {
    s32 entryIndex;
    RankTimeGpEntry *entry;

    gRaceProgress->mUnk_000[0].mRankTime = 0;
    for (entryIndex = 0; entryIndex < rankTimeGp->mEntryCount; entryIndex++) {
        entry = &rankTimeGp->mUnk_1c[entryIndex];
        if (entry->mCourseId == gRaceSetup->mCourseId) {
            switch (gRaceSetup->mEngineIndex) {
                case 0:
                    gRaceProgress->mUnk_000[0].mRankTime = entry->mUnk_02;
                    return;
                case 1:
                    gRaceProgress->mUnk_000[0].mRankTime = entry->mUnk_04;
                    return;
                case 2:
                    gRaceProgress->mUnk_000[0].mRankTime = entry->mUnk_06;
                    break;
            }
            return;
        }
    }
}

void CreateRaceProgress(void *heap) {
    gRaceProgress = HeapAlloc(heap, 0x524);
    gRaceProgress->mCheckpointLapProgress = HeapAlloc(heap, (gCourseMap->mNumberedCheckpointCount + 1) << 2);
    gRaceProgress->mRankPointFile = FindMainRaceOrMainEffectFile(gRankPointRptName);
    gRaceProgress->mRankTimeGpFile = FindMainRaceOrMainEffectFile(gRankTimeGpRttName);
    SetRankTimeFromRankTimeGp(gRaceProgress->mRankTimeGpFile);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        CreateShapeMapObjectCountList(heap);
    }
    InitRaceProgress();
}

void func_0203d568(void) {
    u16 entryIndex;
    enum { K0 } inputSlotIndex;

    SetReadRaceKeys(0);
    if (func_0203d568_c_inline() != 0) {
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    switch (gRaceSetup->mMode) {
        case MODE_VS:
            func_0203d568_b_inline();
            break;
        case MODE_MISSION_RUN:
            func_0205e2b8();
            break;
        case MODE_BATTLE:
            func_0203d568_b_inline();
            break;
    }
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        inputSlotIndex = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
        FinishKeyRecording(&data_02175628[inputSlotIndex].mUnk_28);
    }
}
