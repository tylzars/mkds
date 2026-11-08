#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203ba70.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467a0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200f5ac.h"
#include "code_02133048.h"
#include "code_0214d93c.h"

#pragma thumb on

BOOL func_0203b96c(s32 cupIndex) {
    if (cupIndex == 9) {
        return FALSE;
    }
    switch (cupIndex) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (IsBackupFlagSet(0) != 0 || IsBackupFlagSet(1) != 0 || IsBackupFlagSet(2) != 0 ||
                IsBackupFlagSet(3) != 0) {
                return TRUE;
            }
            break;
        case 3:
            if (IsBackupFlagSet(4) != 0 || IsBackupFlagSet(5) != 0 || IsBackupFlagSet(6) != 0 ||
                IsBackupFlagSet(7) != 0) {
                return TRUE;
            }
            break;
        case 6:
            if (IsBackupFlagSet(8) != 0 || IsBackupFlagSet(9) != 0 || IsBackupFlagSet(10) != 0 ||
                IsBackupFlagSet(11) != 0) {
                return TRUE;
            }
            break;
        case 7:
            if (IsBackupFlagSet(12) != 0 || IsBackupFlagSet(13) != 0 || IsBackupFlagSet(14) != 0 ||
                IsBackupFlagSet(15) != 0) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

u32 func_0203b8e4(RandomState64 *random) {
    u8 passingCupCount;
    u8 cupIndex;
    u16 seenCount;
    u16 pickedPosition;
    u32 randomPosition;

    passingCupCount = 0;
    seenCount = 0;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        if (func_0203b96c(cupIndex) != FALSE) {
            passingCupCount++;
        }
    }
    if (passingCupCount == 0) {
        randomPosition = 0;
    } else {
        random->mValue = _ll_mul(random->mMultiplier, random->mValue) + random->mIncrement;
        if (passingCupCount == 0) {
            randomPosition = random->mValue >> 32;
        } else {
            randomPosition = (u64) (u32) (random->mValue >> 32) * (u32) passingCupCount >> 32;
        }
    }
    pickedPosition = randomPosition;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        if (func_0203b96c(cupIndex) != FALSE) {
            seenCount++;
            if (seenCount > pickedPosition) {
                break;
            }
        }
    }
    return cupIndex;
}

void SetNextDemoRace(u8 *picks) {
    RandomState64 random;
    RTCTime time;
    u16 otherKartIndices[2];
    u32 characterIndex;
    u32 kartIndex;
    u16 shuffledIndices[8];
    u16 cupIndex;
    u16 courseIndexInCup;
    u16 swapIndex;
    u16 g;
    u16 i;
    u16 j;
    u16 k;
    u16 followedKartIndex;
    u32 swapTemp;
    u32 l;

    if (RTC_GetTime(&time) != 0) {
        time.mHour = 0;
        time.mMinute = 0;
        time.mSecond = 0;
    }
    random.mValue = (u32) ((time.mHour * 60 + time.mMinute) * 60 + time.mSecond + OS_GetTick());
    random.mMultiplier = 0x5d588b656c078965ULL;
    random.mIncrement = 0x269ec3;
    gRaceSetup->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_DEMO;
    gRaceSetup->mNextHeader.mEngineIndex = 2;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mRuleKind = 0;
    gRaceSetup->mNextHeader.mCourseListMode = 0;
    gRaceSetup->mNextHeader.mMirrorMode = 0;
    gRaceSetup->mNextHeader.mLapCount = -1;
    gRaceSetup->mNextHeader.mCpuDifficulty = 2;
    random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
    courseIndexInCup = (u64) (u32) (random.mValue >> 32) * 4 >> 32;
    cupIndex = func_0203b8e4(&random);
    gRaceSetup->mNextHeader.mCourseId = gCupCourseIdTable[cupIndex][courseIndexInCup];
    random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
    followedKartIndex = (u64) (u32) (random.mValue >> 32) * 8 >> 32;
    gRaceSetup->mNextHeader.mFollowedKartIndex = followedKartIndex;
    for (k = 0; k < 2; k++) {
        for (j = 0; j < 8; j++) {
            if (j != followedKartIndex) {
                otherKartIndices[k] = j;
                break;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        shuffledIndices[i] = i;
    }
    for (g = 0; g < 1000; g++) {
        random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
        swapIndex = (u64) (u32) (random.mValue >> 32) * 7 >> 32;
        random.mValue = _ll_mul(random.mMultiplier, random.mValue) + random.mIncrement;
        swapTemp = shuffledIndices[swapIndex];
        shuffledIndices[swapIndex] = shuffledIndices[(u16) ((u64) (u32) (random.mValue >> 32) * 7 >> 32)];
        shuffledIndices[(u16) ((u64) (u32) (random.mValue >> 32) * 7 >> 32)] = swapTemp;
    }
    SetGivenCharacterAndKart(picks, 0, 0, 0);
    PickRandomCharactersAndKarts(picks);
    for (i = 0; i < 8; i++) {
        l = 3;
        if (otherKartIndices[0] == i) {
            l = 0;
        }
        if (otherKartIndices[1] == i) {
            l = 1;
        }
        GetEntryCharacterAndKart(picks, i, &characterIndex, &kartIndex);
        SetNextRaceEntry(i, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, l);
    }
    ResetCupToFirstCourse();
}

#pragma thumb off
