#include "Main/Unknown/code_020cc994.h"
#include "00/code_02181f98.h"

void SetNextCpuDifficulty(u32 cpuDifficulty) {
    gRaceSetup->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void SetNextMode(u32 mode) {
    gRaceSetup->mNextHeader.mMode = mode;
}

void SetNextCupIndex(u32 cupIndex) {
    gRaceSetup->mNextHeader.mCupIndex = cupIndex;
}

void SetNextCourseId(u32 courseId) {
    gRaceSetup->mNextHeader.mCourseId = courseId;
}

void SetNextEngineIndex(u32 engineIndex) {
    gRaceSetup->mNextHeader.mEngineIndex = engineIndex;
}

void SetNextMirrorMode(u32 mirrorMode) {
    gRaceSetup->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void func_020cca24(u32 p0) {
    gRaceSetup->mNextHeader.mGhostRecordIndex = p0;
}

void SetNextBattleKind(u32 battleKind) {
    gRaceSetup->mNextHeader.mBattleKind = battleKind;
}

void SetNextUseTeams(u32 useTeams) {
    gRaceSetup->mNextHeader.mUseTeams = useTeams;
}

void SetCourseCount(u32 courseCount) {
    gRaceSetup->mCourseCount = courseCount;
}

void SetNextRuleKind(u32 ruleKind) {
    gRaceSetup->mNextHeader.mRuleKind = ruleKind;
}

void SetNextCourseListMode(u32 courseListMode) {
    gRaceSetup->mNextHeader.mCourseListMode = courseListMode;
}

void func_020cc9a8(u32 p0) {
    data_0217b488->mUnk_78 = p0;
}

u32 func_020cc994(void) {
    return (data_0217b488->mUnk_04);
}
