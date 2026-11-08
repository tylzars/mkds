#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/code_02077bc0.h"

PointLink *GetKeyedPlacementBattlePointLink(u32 key) {
    return &gCourseMap
                ->mBattlePointLinks[gCourseMap->mKeyedPlacements[gCourseMap->mKeyedPlacementIndexByKey[key]].mUnk_18];
}

s32 ComputeDotOfPairsRounded(const UnkPair020b502c *first, const UnkPair020b502c *second) {
    return ((s64) first->mUnk_00 * second->mUnk_00 + (s64) first->mUnk_04 * second->mUnk_04 + 0x800) >> 12;
}

s64 ComputeDotOfPairsRoundedS64(const UnkPair020b502c *first, const UnkPair020b502c *second) {
    return ((s64) first->mUnk_00 * second->mUnk_00 + (s64) first->mUnk_04 * second->mUnk_04 + 0x800) >> 12;
}

static inline s32 func_02040bc0_inline(s8 entryIndex) {
    BOOL f = FALSE;
    if (gRaceSetup->mCurrentEntries[(u16) entryIndex].mPlayer.mKind <= 3 &&
        ((1 << gRaceSetup->mCurrentEntries[(u16) entryIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        f = TRUE;
    }
    return f;
}

BOOL func_02040bc0(void) {
    BOOL result = FALSE;
    BOOL ended;
    s8 entryIndex = gRaceSetup->mEntryIndex;

    if (entryIndex == -1 || func_02040bc0_inline(entryIndex) == 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        return result;
    }
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            ended = FALSE;
            switch (gRaceProgress->mUnk_000[(u16) entryIndex].mStatus) {
                case 1:
                case 2:
                case 3:
                    ended = TRUE;
                    break;
            }
            if (ended == FALSE) {
                if (gRaceProgress->mEntryEndKind != 0) {
                    return result;
                }
            }
            return TRUE;
        case MODE_BATTLE:
            if (gRaceProgress->mRaceDone != 0) {
                result = TRUE;
            }
            return result;
        default:
            ended = FALSE;
            switch (gRaceProgress->mUnk_000[(u16) entryIndex].mStatus) {
                case 1:
                case 2:
                case 3:
                    ended = TRUE;
                    break;
            }
            if (ended != FALSE) {
                result = TRUE;
            }
            return result;
    }
}

void ComputeGrandPrixScoreTerms(RaceProgressScoreTerms *scoreTerms, s32 kartIndex) {
    EntryKartCounters *entryKartCounters = GetEntryKartCounters();
    RaceProgress *raceProgress = gRaceProgress;
    RaceProgressKart *raceProgressKart = &raceProgress->mKarts[kartIndex];
    RankTimeGp *rankTimeGpFile = raceProgress->mRankTimeGpFile;

    if (raceProgress->mUnk_000[0].mRankTime == 0) {
        scoreTerms->mUnk_00 = 0;
    } else {
        scoreTerms->mUnk_00 = (FX_Div(rankTimeGpFile->mUnk_0a * (raceProgress->mUnk_000[0].mRankTime -
                                                                 raceProgress->mUnk_000[0].mElapsedFrames),
                                      raceProgress->mUnk_000[0].mRankTime) +
                               0x800) >>
                              12;
    }
    scoreTerms->mUnk_04 = (rankTimeGpFile->mUnk_0c * FX_Div(raceProgressKart->mFirstPlaceFrames << 12,
                                                            gRaceProgress->mUnk_000[0].mRankTime << 12)) >>
                          12;
    if (entryKartCounters->mUnk_00 != 0) {
        scoreTerms->mUnk_08 = rankTimeGpFile->mUnk_0e;
    } else {
        scoreTerms->mUnk_08 = 0;
    }
    scoreTerms->mUnk_0c = rankTimeGpFile->mUnk_10 * entryKartCounters->mUnk_04;
    scoreTerms->mUnk_10 = rankTimeGpFile->mUnk_12 * entryKartCounters->mUnk_08;
    scoreTerms->mUnk_14 = -((u32) (entryKartCounters->mUnk_0c * FX_Inv(rankTimeGpFile->mUnk_14 << 12)) >> 12);
    scoreTerms->mUnk_18 = entryKartCounters->mUnk_10 * -rankTimeGpFile->mUnk_16;
    scoreTerms->mUnk_1c = entryKartCounters->mUnk_14 * -rankTimeGpFile->mUnk_18;
    scoreTerms->mUnk_20 = entryKartCounters->mUnk_18 * -rankTimeGpFile->mUnk_1a;
}

// Sum of the nine score terms (also saved in gRaceProgress->mUnk_500), clamped to -9999..9999; 0 unless kart a is the
// local entry in Grand Prix or Mission Run.
s16 ComputeRaceProgressKartScore(s32 kartIndex) {
    RaceProgressScoreTerms scoreTerms;
    EntryKartCounters *entryKartCounters;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress = gRaceProgress;
    RaceProgressScoreTerms *savedScoreTerms = &raceProgress->mScoreTerms;
    s32 score;
    u8 *missionSettings;

    if ((raceProgress->mUnk_000[kartIndex].mFlags & 1) == 0) {
        return 0;
    }
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            ComputeGrandPrixScoreTerms(&scoreTerms, kartIndex);
            break;
        case MODE_MISSION_RUN:
            missionSettings = (u8 *) raceSetup + 0x28;
            entryKartCounters = GetEntryKartCounters();
            scoreTerms.mUnk_00 = FX_Div(*(s16 *) (missionSettings + 4) * (*(u16 *) (missionSettings + 2) -
                                                                          raceProgress->mUnk_000[0].mElapsedFrames)
                                            << 12,
                                        0x3e8000) >>
                                 12;
            scoreTerms.mUnk_04 = 0;
            scoreTerms.mUnk_08 = 0;
            scoreTerms.mUnk_0c = 0;
            scoreTerms.mUnk_10 = entryKartCounters->mUnk_08 * -5;
            scoreTerms.mUnk_14 = 0;
            scoreTerms.mUnk_18 = entryKartCounters->mUnk_10 * -5;
            scoreTerms.mUnk_1c = entryKartCounters->mUnk_14 * -10;
            scoreTerms.mUnk_20 = entryKartCounters->mUnk_18 * -20;
            break;
        default:
            return 0;
    }
    *savedScoreTerms = scoreTerms;
    score = savedScoreTerms->mUnk_00 + savedScoreTerms->mUnk_04 + savedScoreTerms->mUnk_08 + savedScoreTerms->mUnk_0c +
            savedScoreTerms->mUnk_10 + savedScoreTerms->mUnk_14 + savedScoreTerms->mUnk_18 + savedScoreTerms->mUnk_1c +
            savedScoreTerms->mUnk_20;
    if (score < -9999) {
        score = -9999;
    }
    if (score > 9999) {
        score = 9999;
    }
    return score;
}

void InitRaceProgressKart(RaceProgressKart *raceProgressKart, s32 kartIndex) {
    s32 i;
    Unk0217aa1c_144_00 *lapTime;
    CourseMapRoute *route;
    s32 firstEntry;

    if (gCourseMap->mCheckpoints == NULL) {
        raceProgressKart->mRoute = 0;
        raceProgressKart->mCheckpoint = 0;
    } else {
        raceProgressKart->mRoute = gCourseMap->mCheckpointRoutes->mPreviousRoutes[0];
        route = &gCourseMap->mCheckpointRoutes[raceProgressKart->mRoute];
        firstEntry = gCourseMap->mCheckpointRoutes[raceProgressKart->mRoute].mFirstEntry;
        raceProgressKart->mCheckpoint = firstEntry + route->mEntryCount - 1;
    }
    raceProgressKart->mLapFrames = 0;
    raceProgressKart->mUnk_08 = 0;
    raceProgressKart->mFinishTimeMs = 0;
    raceProgressKart->mHighestLap = 1;
    raceProgressKart->mLap = 0;
    raceProgressKart->mStatus = 0;
    raceProgressKart->mFlags = 0;
    raceProgressKart->mInOrderCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
    raceProgressKart->mCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
    raceProgressKart->mUnk_3c = (raceProgressKart->mUnk_3c & ~0xf0) | (((u16) kartIndex & 0xf) << 4);
    raceProgressKart->mRaceProgress = 0;
    raceProgressKart->mLapProgress = 0;
    raceProgressKart->mScore = 0;
    raceProgressKart->mFirstPlaceFrames = 0;
    raceProgressKart->mCheckpointProgress = 0;
    raceProgressKart->mUnk_3c = raceProgressKart->mUnk_3c & ~0x300;
    lapTime = raceProgressKart->mLapTimes;
    for (i = 0; i < 5; i++) {
        ComputeRaceTime(&lapTime->mUnk_02, &lapTime->mUnk_03, &lapTime->mUnk_00, 0,
                        gRaceProgress->mUnk_000[0].mElapsedFrames);
        lapTime++;
    }
    ComputeRaceTime(&raceProgressKart->mLapTimes[5].mUnk_02, &raceProgressKart->mLapTimes[5].mUnk_03,
                    &raceProgressKart->mLapTimes[5].mUnk_00, 0, gRaceProgress->mUnk_000[0].mElapsedFrames);
    if (kartIndex == gRaceSetup->mEntryIndex) {
        raceProgressKart->mFlags = raceProgressKart->mFlags | 1;
    }
    raceProgressKart->mUnk_3c = (raceProgressKart->mUnk_3c & ~0xf) | ((u16) (kartIndex + 1) & 0xf);
}

static inline u32 func_020401ac_inline(Unk0217aa00 *p) {
    return p == NULL ? 0 : p->mUnk_0000;
}

static inline void func_020401ac_inline2(Unk0217561c_000 *q) {
    q->mElapsedFrames = 0;
    q->mClockEnabled = 0;
}

static inline void func_020401ac_inline3(Unk0217aa1c_144_00 *time, u32 frames) {
    ComputeRaceTime(&time->mUnk_02, &time->mUnk_03, &time->mUnk_00, 0, frames);
}

static inline void func_020401ac_inline4(RandomState64 *randomState64, u32 seed) {
    randomState64->mValue = seed;
    randomState64->mMultiplier = 0x5d588b656c078965;
    randomState64->mIncrement = 0x269ec3;
}

static inline s32 func_020401ac_inline5(s32 a, s32 b) {
    return b == 0 ? 0 : FX_Div(a + 0x1000, b << 12);
}

static inline u32 func_020401ac_inline6(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = (s64) randomState64->mMultiplier * (s64) randomState64->mValue + randomState64->mIncrement;
    return ((s64) (randomState64->mValue >> 32) * limit) >> 32;
}

void InitRaceProgress(void) {
    BOOL f;
    s32 i;
    u32 seed;
    s32 checkpointNumber;
    u64 a;
    u64 c;
    u64 d;
    u16 routeIndex;
    u16 entryInRoute;
    u16 checkpointIndex;
    s32 v;
    Unk0217aa00 *p;
    CourseMapRoute *route;
    CourseMapCheckpoint *checkpoint;

    func_020401ac_inline2(&gRaceProgress->mUnk_000[0]);
    func_020401ac_inline3(&gRaceProgress->mUnk_000[0].mUnk_08_view, gRaceProgress->mUnk_000[0].mElapsedFrames);
    f = FALSE;
    gRaceProgress->mUnk_000[0].mFinishedCount = 0;
    gRaceProgress->mUnk_000[0].mRemovedCount = 0;
    gRaceProgress->mRaceDone = 0;
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
    gRaceProgress->mEntryEndKind = 6;
    gRaceProgress->mTimeCountsDown = FALSE;
    gRaceProgress->mTimeLimitFrameCount = 0;
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            if (gRaceSetup->mMissionKind == 6) {
                gRaceProgress->mTimeCountsDown = FALSE;
            } else {
                gRaceProgress->mTimeCountsDown = TRUE;
            }
            gRaceProgress->mTimeLimitFrameCount = gRaceSetup->mMissionTimeLimitFrameCount;
            break;
        case MODE_BATTLE:
            if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
                gRaceProgress->mTimeCountsDown = TRUE;
                gRaceProgress->mTimeLimitFrameCount = gCourseMap->mSettings->mLapCountOrBattleSeconds * 0x3c;
            }
            break;
    }
    for (i = 0; i < 8; i++) {
        InitRaceProgressKart(&gRaceProgress->mKarts[i], i);
        gRaceProgress->mKartAtRank[i] = -1;
    }
    switch (gRaceSetup->mRaceKind) {
        case 2:
            seed = gRaceSetup->mUnk_05c;
            break;
        case RACE_KIND_AWARD:
            seed = 0xc240793;
            break;
        case RACE_KIND_STAFF_ROLL:
            seed = 0x71abc95;
            break;
        default:
            switch (gRaceSetup->mMode) {
                case MODE_TIME_ATTACK:
                    seed = 0x34a8f71;
                    break;
                case MODE_MISSION_RUN:
                    seed = 0x158b76f;
                    break;
                case 5:
                    seed = 0x5b12f73;
                    break;
                default:
                    p = data_0217aa00;
                    v = 0;
                    if (func_020401ac_inline(p) != 0) {
                        if (p->mUnk_0004 != 0xd) {
                            v = 1;
                        }
                    }
                    if (v != 0) {
                        seed = p->mUnk_1eb0;
                    } else {
                        a = OS_GetTick();
                        seed = (a << 16) + OS_GetTick();
                    }
                    break;
            }
            break;
    }
    func_020401ac_inline4(&gRaceProgress->mRandom, seed);
    gRaceProgress->mSeed = seed;
    gRaceSetup->mNextHeader.mUnk_5c = seed;
    a = OS_GetTick();
    c = OS_GetTick();
    d = OS_GetTick();
    func_020401ac_inline4(&gRaceProgress->mLocalRandom, a + ((c << 24) + (d << 8)));
    func_020401ac_inline4(&gRaceProgress->mFixedSeedRandom, 0xa094a2f);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        ShuffleCourseMapRespawnSlots(&gRaceProgress->mRandom);
    }
    gRaceProgress->mCameraChainEnded = 0;
    gRaceProgress->mLapProgressScale = FX_Inv((gCourseMap->mLapProgressBaseMax + 1) << 12);
    gRaceProgress->mRaceProgressScale = FX_Inv(GetLapCount() << 12);
    for (i = 0; i < gCourseMap->mNumberedCheckpointCount + 1; i++) {
        checkpointNumber = i % (gCourseMap->mNumberedCheckpointCount + 1);
        if (checkpointNumber == gCourseMap->mNumberedCheckpointCount) {
            gRaceProgress->mCheckpointLapProgress[i] = 0x1000;
        } else {
            for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
                route = &gCourseMap->mCheckpointRoutes[routeIndex];
                for (entryInRoute = 0; entryInRoute < route->mEntryCount; entryInRoute++) {
                    checkpointIndex = entryInRoute + route->mFirstEntry;
                    checkpoint = &gCourseMap->mCheckpoints[checkpointIndex];
                    if (checkpoint->mNumber == checkpointNumber) {
                        v = func_020401ac_inline5((checkpointIndex - route->mFirstEntry) << 12, route->mEntryCount);
                        v += route->mLapProgressBase << 12;
                        gRaceProgress->mCheckpointLapProgress[i] =
                            ((s64) v * gRaceProgress->mLapProgressScale + 0x800) >> 12;
                    }
                }
            }
        }
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        gRaceProgress->mStartPlacementOffset = 0;
        return;
    }
    gRaceProgress->mStartPlacementOffset = func_020401ac_inline6(&gRaceProgress->mRandom, 8);
}
