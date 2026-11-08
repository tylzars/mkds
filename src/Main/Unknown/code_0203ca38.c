#include "Main/Unknown/code_0203ca38.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b3f64.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 func_0203ca38_inline(u32 i) {
    return GetKartStandingRankIndex(i) + 1;
}

void FinishRaceProgress(void) {
    RaceProgress *raceProgress;
    s32 winningTeamIndex = -1;
    RaceSetup *raceSetup = gRaceSetup;
    s32 mode = raceSetup->mMode;
    u32 kartIndex;
    BOOL usesTeams = FALSE;
    switch (mode) {
        case MODE_BATTLE:
        case MODE_VS:
            if (raceSetup->mUseTeams != 0) {
                usesTeams = TRUE;
            }
            break;
    }
    switch (mode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case 5: {
            for (kartIndex = 0; kartIndex < raceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                u32 t;
                u8 rank;
                u32 rankPoints = 0;
                if (raceSetup->mMode == 5) {
                    t = data_0217aa14->mUnk_104[data_0217aa18->mUnk_00[kartIndex & 0xff]].mUnk_86_1;
                } else {
                    t = gRaceProgress->mKarts[kartIndex].mRank;
                }
                rank = t;
                if (gRaceProgress->mUnk_000[kartIndex].mStatus != 4) {
                    rankPoints = LookupRankPoints(rank);
                }
                SetKartCourseResult(kartIndex, rank, rankPoints);
                SetKartCourseFinishTime(kartIndex, &gRaceProgress->mKarts[kartIndex].mLapTimes[5]);
                if (gRaceSetup->mMode == 5) {
                    if (gRaceProgress->mUnk_000[kartIndex].mStatus == 4) {
                        ClearKartCourseTotalPoints(kartIndex);
                    }
                }
                if (usesTeams != FALSE) {
                    if (rank == 1) {
                        winningTeamIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                    }
                }
                raceSetup = gRaceSetup;
            }
            break;
        }
        case MODE_BATTLE: {
            s32 e;
            if (usesTeams != FALSE) {
                kartIndex = 0;
                if (kartIndex < raceSetup->mKartCount) {
                    raceProgress = gRaceProgress;
                    do {
                        if (raceProgress->mUnk_000[kartIndex].mStatus == 1) {
                            if (usesTeams != FALSE) {
                                if (winningTeamIndex == -1) {
                                    raceSetup = gRaceSetup;
                                    winningTeamIndex = raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                                }
                            }
                        }
                        kartIndex = (u16) (kartIndex + 1);
                    } while (kartIndex < raceSetup->mKartCount);
                }
            }
            for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                gRaceProgress->mUnk_000[kartIndex].mFlags |= 2;
                if (gRaceProgress->mUnk_000[kartIndex].mStatus == 1) {
                    if (usesTeams != FALSE) {
                        e = winningTeamIndex == gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        e = 1;
                    }
                    func_0205d88c(kartIndex, 1);
                } else {
                    if (usesTeams != FALSE) {
                        e = winningTeamIndex == gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        e = 0;
                    }
                    func_0205d88c(kartIndex, 0);
                    if (gRaceProgress->mUnk_000[kartIndex].mStatus == 0) {
                        gRaceProgress->mUnk_000[kartIndex].mStatus = 2;
                    }
                }
                func_02068640(GetKart(kartIndex), e);
            }
            func_02110cc8(0);
            break;
        }
    }
    if (usesTeams != FALSE) {
        SetTeamWinCountsAndPoints(winningTeamIndex);
    }
    gRaceProgress->mRaceDone = 1;
}

void func_0203d078(void) {
    u32 kartIndex;
    if (IsWinnerDecidedAndEndReached() != 0) {
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
            if (kart->mStatus == 0) {
                if (IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
                    kart->mStatus = 1;
                } else {
                    kart->mStatus = 2;
                }
                kart->mFlags |= 2;
            }
        }
        return;
    }
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        if (IsKartEliminated(kartIndex) != FALSE) {
            RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
            if (kart->mStatus == 0) {
                if (IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
                    kart->mStatus = 1;
                } else {
                    kart->mStatus = 2;
                }
                kart->mFlags |= 2;
            }
        }
    }
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
}

static inline u16 func_0203cd14_inline(s32 v) {
    return (u16) v;
}

// TRUE once no kart is still racing in battle, until the race is marked done.
BOOL ShouldFinishBattle(void) {
    u32 kartIndex;
    s32 racingCount;
    BOOL noneRacing = TRUE;
    RaceProgress *raceProgress = gRaceProgress;
    if (raceProgress->mRaceDone != 0) {
        return FALSE;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        racingCount = 0;
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            if (raceProgress->mUnk_000[kartIndex].mStatus == 0) {
                racingCount++;
                if (racingCount > 0) {
                    noneRacing = FALSE;
                    break;
                }
            }
        }
        return noneRacing;
    }
    return FALSE;
}

void AdvanceMissionRunEnd(void) {
    BOOL endFound = FALSE;
    s32 endKind = 2;
    RaceSetup *raceSetup = gRaceSetup;
    s32 entryIndex = raceSetup->mEntryIndex;
    u16 w;
    u32 kartOffset;
    RaceProgressKart *kart;
    BOOL hasEnded;
    if (entryIndex < 0) {
        return;
    }
    w = entryIndex;
    kartOffset = w * 0x8c;
    kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartOffset);
    hasEnded = FALSE;
    switch (kart->mStatus) {
        case 1:
        case 2:
        case 3:
            hasEnded = TRUE;
            break;
    }
    if (hasEnded != FALSE) {
        if ((kart->mFlags & 0x10) != 0) {
            gRaceProgress->mFramesSinceFinish++;
            if (gRaceProgress->mFramesSinceFinish <= gRaceSetup->mFinishWaitFrameCount) {
                return;
            }
            func_020688a0(GetKart((u16) entryIndex));
            func_0207a828(func_0203cd14_inline(entryIndex));
            func_020b3f64();
            func_02110cc8(0);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                FinishStandings();
            }
            kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartOffset);
            kart->mFlags &= ~0x10;
        } else if ((kart->mFlags & 0x20) != 0) {
            if (func_0207a218() != 0) {
                gRaceProgress->mFramesSinceFailure++;
            }
            if (gRaceProgress->mFramesSinceFailure <= 0x3c) {
                return;
            }
            func_020688a0(GetKart(entryIndex));
            func_0207a828((u16) entryIndex);
            func_02110cc8(0);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                FinishStandings();
            }
            kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartOffset);
            kart->mFlags &= ~0x20;
        }
        return;
    }
    if ((raceSetup->mUnk_044 & 2) != 0) {
        if (func_0207a574() != FALSE) {
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        if ((gRaceSetup->mUnk_044 & 4) != 0) {
            if (func_0207a538() != 0) {
                endKind = 3;
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if ((gRaceSetup->mUnk_044 & 8) != 0) {
            if (func_0207a4fc() != 0) {
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if (func_0205e1c4() != 0) {
            endKind = 4;
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        return;
    }
    FinishRaceProgressKartWithEndKind((u16) gRaceSetup->mEntryIndex, endKind);
}

void FinishRaceProgressKartWithEndKind4(u16 kartIndex) {
    FinishRaceProgressKartWithEndKind(kartIndex, 4);
}

void UpdateRaceProgress(void) {
    u32 i;
    UpdateRaceClock();
    if (gRaceSetup->mMode == 5) {
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], i * 0x8c);
            if (kart->mFinishRequest != 0) {
                FinishRaceProgressKart(kart, kart->mFinishRequest == 1 ? 1 : 0);
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
                kart->mFinishRequest = 0;
            }
        }
    }
    if (gCourseMap->mCheckpoints != NULL) {
        UpdateRaceProgressKarts();
    } else {
        BOOL t = FALSE;
        switch (gRaceSetup->mRaceKind) {
            case RACE_KIND_DEMO:
            case 2:
            case RACE_KIND_STAFF_ROLL:
                t = TRUE;
                break;
            case RACE_KIND_NORMAL:
                if (func_02040bc0() != 0) {
                    t = TRUE;
                }
                break;
        }
        gRaceProgress->mUnk_4f0 = t;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            u16 *q;
            u8 standingRank = func_0203ca38_inline(i);
            q = OFFSET_PTR(u16, &gRaceProgress->mUnk_000[0].mUnk_50, i * 0x8c);
            *q = (*q & ~0xf) | (standingRank & 0xf);
        }
        for (i = 0; i < 8; i = (u16) (i + 1)) {
            gRaceProgress->mKartAtRank[i] = -1;
        }
        func_0203d078();
        if (ShouldFinishBattle() != 0) {
            FinishRaceProgress();
        }
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AdvanceMissionRunEnd();
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        BOOL f = FALSE;
        switch (gRaceProgress->mUnk_000[0].mStatus) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE) {
            return;
        }
        if (gRaceProgress->mRaceDone == 0) {
            gRaceProgress->mRaceDone = 1;
        }
        return;
    }
    if ((u32) gRaceProgress->mUnk_000[0].mFinishedCount < gRaceSetup->mKartCount) {
        return;
    }
    if (gRaceProgress->mRaceDone != 0) {
        return;
    }
    FinishRaceProgress();
}
