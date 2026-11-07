#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 GetCourseId(void) {
    return (gRaceSetupCopy->mCourseId);
}

u32 GetCharacterIndex(u16 p0) {
    return (gRaceSetupCopy->mEntries[p0].mCharacterIndex);
}

u32 GetKartIndex(u16 p0) {
    return (gRaceSetupCopy->mEntries[p0].mKartIndex);
}

u32 GetPlayerKind(u16 p0) {
    return (gRaceSetupCopy->mEntries[p0].mPlayerKind);
}

u32 GetEngineIndex(void) {
    return (gRaceSetupCopy->mEngineIndex);
}

u32 GetCupIndex(void) {
    return (gRaceSetupCopy->mCupIndex);
}

u32 func_0202967c(void) {
    return (gRaceSetupCopy->mUnk_d8);
}

u32 func_0202966c(void) {
    return (gRaceSetupCopy->mUnk_c0);
}

u32 GetCourseListMode(void) {
    return (gRaceSetupCopy->mCourseListMode);
}

u32 func_0202964c(void) {
    return (gRaceSetupCopy->mUnk_e8);
}

u32 func_0202963c(void) {
    return (gRaceSetupCopy->mUnk_ec);
}

u32 GetUseTeams(void) {
    return (gRaceSetupCopy->mUseTeams);
}

u32 GetTeamIndex(u16 p0) {
    return (gRaceSetupCopy->mEntries[p0].mTeamIndex);
}

u32 GetMissionTableRow(void) {
    return (gRaceSetupCopy->mMissionTableRow);
}

u32 GetMissionTableColumn(void) {
    return (gRaceSetupCopy->mMissionTableColumn);
}

u32 func_020295e4(void) {
    return (gRaceSetupCopy->mEntryIndex);
}

u32 func_020295d0(void) {
    return (gRaceSetupCopy->mUnk_10d);
}

void SetEngineIndex(u32 p0) {
    gRaceSetupCopy->mEngineIndex = p0;
}

void func_020295b0(void) {
    gRaceSetupCopy->mUnk_d8 = 1;
}

void func_020295a0(void) {
    gRaceSetupCopy->mUnk_d8 = 0;
}

void SetCupIndex(u32 p0) {
    gRaceSetupCopy->mCupIndex = p0;
}

void SetCourseId(u32 p0) {
    gRaceSetupCopy->mCourseId = p0;
}

void func_02029570(u32 p0) {
    gRaceSetupCopy->mUnk_c0 = p0;
}

void SetCourseListMode(u32 p0) {
    gRaceSetupCopy->mCourseListMode = p0;
}

void func_02029550(u16 p0) {
    gRaceSetupCopy->mUnk_e8 = p0;
}

void func_02029540(u32 p0) {
    gRaceSetupCopy->mUnk_ec = p0;
}

void SetUseTeams(void) {
    gRaceSetupCopy->mUseTeams = 1;
}

void ClearUseTeams(void) {
    gRaceSetupCopy->mUseTeams = 0;
}

#pragma thumb off

#pragma thumb on

void SetTeamIndex(u16 a, u32 b) {
    gRaceSetupCopy->mEntries[a].mTeamIndex = b;
}

void SetCharacterIndex(u16 a, u32 b) {
    gRaceSetupCopy->mEntries[a].mCharacterIndex = b;
}

void SetKartIndex(u16 a, u32 b) {
    gRaceSetupCopy->mEntries[a].mKartIndex = b;
}

void SetPlayerKind(u16 a, u32 b) {
    gRaceSetupCopy->mEntries[a].mPlayerKind = b;
}

void func_020294c0(u16 a, u32 b) {
    gRaceSetupCopy->mEntries[a].mUnk_10 = b;
}

void func_020294ac(u16 a, u32 b) {
    gRaceSetupCopy->mEntries[a].mUnk_14 = b;
}

#pragma thumb off

#pragma thumb on

void func_0202949c(u32 p0) {
    gRaceSetupCopy->mUnk_e0 = p0;
}

void SetMissionTableRow(u32 p0) {
    gRaceSetupCopy->mMissionTableRow = (u8) p0;
}

void SetMissionTableColumn(u32 p0) {
    gRaceSetupCopy->mMissionTableColumn = (u8) p0;
}

void SetMissionFileRowIndex(u32 p0) {
    gRaceSetupCopy->mMissionFileRowIndex = p0;
}

void func_02029454(u32 p0) {
    gRaceSetupCopy->mEntryIndex = p0;
}

void func_02029440(u32 p0) {
    gRaceSetupCopy->mUnk_10d = p0;
}

#pragma thumb off
