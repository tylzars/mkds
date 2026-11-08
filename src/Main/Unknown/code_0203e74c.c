#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_0203f320.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_02077bc0.h"

s32 IsRaceEndConditionMet(void) {
    BOOL endConditionMet;
    u16 kartIndex;
    s32 s;
    BOOL f;
    s32 v;
    s32 kartCount;
    s32 removedCount;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress;
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
                f = FALSE;
                s = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    f = TRUE;
                }
                if (f != FALSE) {
                    s = gRaceProgress->mUnk_000[kartIndex].mStatus;
                    f = FALSE;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = TRUE;
                            break;
                    }
                    if (f == FALSE) {
                        endConditionMet = FALSE;
                        break;
                    }
                }
            }
            break;
        case MODE_VS:
            endConditionMet = TRUE;
            raceProgress = gRaceProgress;
            if (raceProgress->mUnk_000[0].mFinishedCount <
                (s32) func_0203f320() - (raceProgress->mUnk_000[0].mRemovedCount + 1)) {
                for (kartIndex = 0; kartIndex < func_0203f320(); kartIndex++) {
                    if (IsKartNonCpu(kartIndex) != FALSE && IsKartEnded(kartIndex) == 0) {
                        if (IsRaceProgressKartRemoved(kartIndex) == FALSE) {
                            endConditionMet = FALSE;
                            break;
                        }
                    }
                }
            }
            if (endConditionMet == FALSE && func_0203f2a0() == 1) {
                if (IsKartEnded(GetLeadingKart()) != 0) {
                    endConditionMet = TRUE;
                }
            }
            break;
        case 5:
            v = data_0217aa18->mUnk_06[func_ov000_0219bb50()];
            if (v < 0) {
                endConditionMet = FALSE;
            } else {
                kartCount = gRaceSetup->mKartCount;
                raceProgress = gRaceProgress;
                removedCount = raceProgress->mUnk_000[0].mRemovedCount;
                if (kartCount - removedCount <= 1) {
                    endConditionMet = FALSE;
                } else {
                    s = raceProgress->mUnk_000[(u16) v].mStatus;
                    f = FALSE;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = TRUE;
                            break;
                    }
                    if (f == FALSE) {
                        endConditionMet = raceProgress->mUnk_000[0].mFinishedCount + removedCount >= kartCount - 1;
                    } else {
                        endConditionMet = raceProgress->mUnk_000[0].mFinishedCount + removedCount >= kartCount;
                    }
                }
            }
            break;
        case MODE_TIME_ATTACK:
            endConditionMet = FALSE;
            switch (gRaceProgress->mUnk_000[0].mStatus) {
                case 1:
                case 2:
                case 3:
                    endConditionMet = TRUE;
                    break;
            }
            break;
        case MODE_BATTLE:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) raceSetup->mKartCount; kartIndex++) {
                f = FALSE;
                s = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    f = TRUE;
                }
                if (f != FALSE) {
                    if (IsKartEliminated(kartIndex) == FALSE) {
                        endConditionMet = FALSE;
                        break;
                    }
                }
                raceSetup = gRaceSetup;
            }
            break;
        case MODE_MISSION_RUN:
            endConditionMet = FALSE;
            if (raceSetup->mMissionKind == 6 && gRaceProgress->mUnk_000[0].mFinishedCount != 0) {
                endConditionMet = TRUE;
            }
            break;
        default:
            endConditionMet = FALSE;
            break;
    }
    return endConditionMet;
}

void FinishRemainingRaceProgressKarts(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    s32 status;
    BOOL ended;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *finishTime;
    u32 frames;
    u = FALSE;
    v = FALSE;
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        status = (OFFSET_PTR(Unk0217561c_000, gRaceProgress, kartIndex * 0x8c))->mStatus;
        ended = FALSE;
        switch (status) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != 4) {
            raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceProgress->mUnk_000[0].mElapsedFrames;
            if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            ComputeRaceTime(&finishTime->mUnk_02, &finishTime->mUnk_03, &finishTime->mUnk_00, u, frames);
            FinishRaceProgressKart(raceProgressKart, v);
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount = gRaceSetup->mKartCount;
}

void func_0203ecf0(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    s32 status;
    BOOL ended;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *finishTime;
    u32 frames;
    u = FALSE;
    v = FALSE;
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        status = (OFFSET_PTR(Unk0217561c_000, gRaceProgress, kartIndex * 0x8c))->mStatus;
        ended = FALSE;
        switch (status) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != 4) {
            raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceProgress->mUnk_000[0].mElapsedFrames;
            if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            ComputeRaceTime(&finishTime->mUnk_02, &finishTime->mUnk_03, &finishTime->mUnk_00, u, frames);
            func_0205ae8c(kartIndex);
            FinishRaceProgressKart(raceProgressKart, v);
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount = gRaceSetup->mKartCount;
}

void FinishRemainingMissionRunKarts(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    EntryKartCounters *entryKartCounters;
    s32 status;
    BOOL ended;
    u32 succeeded;
    u8 *missionSettings;
    Unk0217aa1c_144_00 *finishTime;
    u32 frames;
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        status = (OFFSET_PTR(Unk0217561c_000, gRaceProgress, kartIndex * 0x8c))->mStatus;
        ended = FALSE;
        switch (status) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended == FALSE) {
            raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceProgress->mUnk_000[0].mElapsedFrames;
            if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            ComputeRaceTime(&finishTime->mUnk_02, &finishTime->mUnk_03, &finishTime->mUnk_00, 0, frames);
            succeeded = 1;
            missionSettings = (u8 *) &gRaceSetup->mMissionTimeLimitFrameCount;
            entryKartCounters = GetEntryKartCounters();
            switch (missionSettings[7]) {
                case 4:
                    if (missionSettings[0xf] > (u32) entryKartCounters->mUnk_04) {
                        succeeded = 0;
                    }
                    break;
                case 6:
                    if (((u32) (raceProgressKart->mUnk_3c << 28) >> 28) != 1) {
                        succeeded = 0;
                    }
                    break;
            }
            if (succeeded != 0) {
                u32 storedKartIndex = (u32) (raceProgressKart->mUnk_3c << 24) >> 28;
                if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                    FinishRaceProgressKartWithEndKind(storedKartIndex, 0);
                }
            } else {
                FinishRaceProgressKartWithEndKind((u32) (raceProgressKart->mUnk_3c << 24) >> 28, 4);
            }
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount = gRaceSetup->mKartCount;
}

void FinishRaceProgressKart(RaceProgressKart *raceProgressKart, s32 finished) {
    Unk0217aa1c_144_00 *finishTime;
    s32 inputSlotIndex;
    s32 mode;
    s16 score;
    inputSlotIndex = gRaceSetup->mCurrentEntries[(u32) (raceProgressKart->mUnk_3c << 24) >> 28].mPlayer.mIndex;
    if (finished != 0) {
        raceProgressKart->mStatus = 1;
    } else {
        raceProgressKart->mStatus = 3;
    }
    switch (data_02175628[inputSlotIndex].mSourceKind) {
        case 2:
            FinishKeyRecording(&data_02175628[inputSlotIndex].mUnk_28);
            break;
        case 1:
            func_0204a904((KeyRecording *) &data_02175628[inputSlotIndex].mUnk_28);
            break;
    }
    raceProgressKart->mFlags |= 8;
    if ((raceProgressKart->mFlags & 1) != 0 && (raceProgressKart->mFlags & 0x10) == 0) {
        RefreshRaceNewRecordTaRecordFlags();
    }
    finishTime = &raceProgressKart->mLapTimes[5];
    if (finished != 0) {
        raceProgressKart->mFinishTimeMs =
            (finishTime->mUnk_02 * 0x3c + finishTime->mUnk_03) * 1000 + finishTime->mUnk_00;
    } else if (gRaceSetup->mMode != 5) {
        raceProgressKart->mFinishTimeMs = 0x5b8d80;
    }
    mode = gRaceSetup->mMode;
    if (mode == MODE_GRAND_PRIX || mode == MODE_MISSION_RUN) {
        if ((raceProgressKart->mFlags & 1) != 0) {
            raceProgressKart->mScore = ComputeRaceProgressKartScore((u32) (raceProgressKart->mUnk_3c << 24) >> 28);
            score = raceProgressKart->mScore;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                gCupRecords->mUnk_140 = score;
            } else {
                gCupRecords->mUnk_140 += score;
            }
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount++;
}

void FinishRaceProgressKartWithEndKind(s32 kartIndex, s32 endKind) {
    Kart *kart;
    Unk0217aa1c_144_00 finishTime;
    s32 status;
    BOOL ended;
    RaceProgressKart *raceProgressKart;
    raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
    status = raceProgressKart->mStatus;
    ended = FALSE;
    switch (status) {
        case 1:
        case 2:
        case 3:
            ended = TRUE;
            break;
    }
    if (ended != FALSE) {
        return;
    }
    if ((raceProgressKart->mFlags & 0x10) != 0) {
        return;
    }
    if ((raceProgressKart->mFlags & 0x20) != 0) {
        return;
    }
    kart = GetKart(kartIndex);
    raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartIndex * 0x8c);
    gRaceProgress->mUnk_000[0].mClockEnabled = 0;
    ComputeRaceTime(&finishTime.mUnk_02, &finishTime.mUnk_03, &finishTime.mUnk_00, 0,
                    gRaceProgress->mUnk_000[0].mElapsedFrames);
    raceProgressKart->mLapTimes[5] = finishTime;
    if ((raceProgressKart->mFlags & 1) != 0) {
        gRaceProgress->mEntryEndKind = endKind;
        kart->mUnk_7c |= 0x20000000;
        kart->mUnk_48 &= ~0x2000000;
        if (endKind == 0) {
            raceProgressKart->mFlags |= 0x10;
            gRaceProgress->mFramesSinceFinish = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                EliminateKartsUntilWinnerDecided();
            }
        } else {
            raceProgressKart->mFlags |= 0x20;
            gRaceProgress->mFramesSinceFailure = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                ((void (*)(s32)) EliminateKartAndCheckWinner)(kartIndex);
            }
        }
    }
    FinishRaceProgressKart(raceProgressKart, endKind == 0);
    if (IsRaceEndConditionMet() == 0) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            EliminateKartsUntilWinnerDecided();
            return;
        case MODE_MISSION_RUN:
            FinishRemainingMissionRunKarts();
            return;
        case 5:
            func_0203ecf0();
            return;
        default:
            FinishRemainingRaceProgressKarts();
            return;
        case MODE_TIME_ATTACK:
            return;
    }
}

void FinishMissionRunKartWithEndKind0(u16 kartIndex) {
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    FinishRaceProgressKartWithEndKind(kartIndex, 0);
}
