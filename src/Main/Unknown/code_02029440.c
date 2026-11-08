#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 GetCourseId(void) {
    return (gRaceSetupCopy->mCourseId);
}

u32 GetCharacterIndex(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex);
}

u32 GetKartIndex(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mKartIndex);
}

u32 GetPlayerKind(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mPlayerKind);
}

u32 GetEngineIndex(void) {
    return (gRaceSetupCopy->mEngineIndex);
}

u32 GetCupIndex(void) {
    return (gRaceSetupCopy->mCupIndex);
}

u32 GetMirrorMode(void) {
    return (gRaceSetupCopy->mMirrorMode);
}

u32 GetCpuDifficulty(void) {
    return (gRaceSetupCopy->mCpuDifficulty);
}

u32 GetCourseListMode(void) {
    return (gRaceSetupCopy->mCourseListMode);
}

u32 GetRaceSetupCopyCourseCount(void) {
    return (gRaceSetupCopy->mCourseCount);
}

u32 GetRuleKind(void) {
    return (gRaceSetupCopy->mRuleKind);
}

u32 GetUseTeams(void) {
    return (gRaceSetupCopy->mUseTeams);
}

u32 GetTeamIndex(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mTeamIndex);
}

u32 GetMissionTableRow(void) {
    return (gRaceSetupCopy->mMissionTableRow);
}

u32 GetMissionTableColumn(void) {
    return (gRaceSetupCopy->mMissionTableColumn);
}

u32 GetRaceSetupCopyEntryIndex(void) {
    return (gRaceSetupCopy->mEntryIndex);
}

u32 GetSessionKartCount(void) {
    return (gRaceSetupCopy->mSessionKartCount);
}

void SetEngineIndex(u32 engineIndex) {
    gRaceSetupCopy->mEngineIndex = engineIndex;
}

void SetMirrorMode(void) {
    gRaceSetupCopy->mMirrorMode = 1;
}

void ClearMirrorMode(void) {
    gRaceSetupCopy->mMirrorMode = 0;
}

void SetCupIndex(u32 cupIndex) {
    gRaceSetupCopy->mCupIndex = cupIndex;
}

void SetCourseId(u32 courseId) {
    gRaceSetupCopy->mCourseId = courseId;
}

void SetCpuDifficulty(u32 cpuDifficulty) {
    gRaceSetupCopy->mCpuDifficulty = cpuDifficulty;
}

void SetCourseListMode(u32 courseListMode) {
    gRaceSetupCopy->mCourseListMode = courseListMode;
}

void SetRaceSetupCopyCourseCount(u16 courseCount) {
    gRaceSetupCopy->mCourseCount = courseCount;
}

void SetRuleKind(u32 ruleKind) {
    gRaceSetupCopy->mRuleKind = ruleKind;
}

void SetUseTeams(void) {
    gRaceSetupCopy->mUseTeams = 1;
}

void ClearUseTeams(void) {
    gRaceSetupCopy->mUseTeams = 0;
}

#pragma thumb off

#pragma thumb on

void SetTeamIndex(u16 entryIndex, u32 teamIndex) {
    gRaceSetupCopy->mEntries[entryIndex].mTeamIndex = teamIndex;
}

void SetCharacterIndex(u16 entryIndex, u32 characterIndex) {
    gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex = characterIndex;
}

void SetKartIndex(u16 entryIndex, u32 kartIndex) {
    gRaceSetupCopy->mEntries[entryIndex].mKartIndex = kartIndex;
}

void SetPlayerKind(u16 entryIndex, u32 playerKind) {
    gRaceSetupCopy->mEntries[entryIndex].mPlayerKind = playerKind;
}

void func_020294c0(u16 entryIndex, u32 b) {
    gRaceSetupCopy->mEntries[entryIndex].mUnk_10 = b;
}

void func_020294ac(u16 entryIndex, u32 b) {
    gRaceSetupCopy->mEntries[entryIndex].mUnk_14 = b;
}

#pragma thumb off

#pragma thumb on

void func_0202949c(u32 p0) {
    gRaceSetupCopy->mUnk_e0 = p0;
}

void SetMissionTableRow(u32 missionTableRow) {
    gRaceSetupCopy->mMissionTableRow = (u8) missionTableRow;
}

void SetMissionTableColumn(u32 missionTableColumn) {
    gRaceSetupCopy->mMissionTableColumn = (u8) missionTableColumn;
}

void SetMissionFileRowIndex(u32 missionFileRowIndex) {
    gRaceSetupCopy->mMissionFileRowIndex = missionFileRowIndex;
}

void SetRaceSetupCopyEntryIndex(u32 entryIndex) {
    gRaceSetupCopy->mEntryIndex = entryIndex;
}

void SetSessionKartCount(u32 sessionKartCount) {
    gRaceSetupCopy->mSessionKartCount = sessionKartCount;
}

#pragma thumb off
