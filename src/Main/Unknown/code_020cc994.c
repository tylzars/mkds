#include "Main/Unknown/code_020cc994.h"
#include "00/code_02181f98.h"

void func_020cca9c(u32 p0) {
    gRaceSetup->mNextHeader.mUnk_14 = p0;
}

void SetNextMode(u32 p0) {
    gRaceSetup->mNextHeader.mMode = p0;
}

void SetNextCupIndex(u32 p0) {
    gRaceSetup->mNextHeader.mCupIndex = p0;
}

void SetNextCourseId(u32 p0) {
    gRaceSetup->mNextHeader.mCourseId = p0;
}

void SetNextEngineIndex(u32 p0) {
    gRaceSetup->mNextHeader.mEngineIndex = p0;
}

void SetNextMirrorMode(u32 p0) {
    gRaceSetup->mNextHeader.mMirrorMode = (u8) p0;
}

void func_020cca24(u32 p0) {
    gRaceSetup->mNextHeader.mUnk_24 = p0;
}

void func_020cca10(u32 p0) {
    gRaceSetup->mNextHeader.mUnk_18 = p0;
}

void SetNextUseTeams(u32 p0) {
    gRaceSetup->mNextHeader.mUseTeams = p0;
}

void SetCourseCount(u32 p0) {
    gRaceSetup->mCourseCount = p0;
}

void func_020cc9d0(u32 p0) {
    gRaceSetup->mNextHeader.mUnk_1c = p0;
}

void SetNextCourseListMode(u32 p0) {
    gRaceSetup->mNextHeader.mCourseListMode = p0;
}

void func_020cc9a8(u32 p0) {
    data_0217b488->mUnk_78 = p0;
}

u32 func_020cc994(void) {
    return (data_0217b488->mUnk_04);
}
