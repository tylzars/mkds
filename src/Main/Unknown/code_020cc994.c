#include "Main/Unknown/code_020cc994.h"
#include "00/code_02181f98.h"

void func_020cca9c(u32 p0) {
    data_021759c0->mNextHeader.mUnk_14 = p0;
}

void func_020cca88(u32 p0) {
    data_021759c0->mNextHeader.mUnk_08 = p0;
}

void func_020cca74(u32 p0) {
    data_021759c0->mNextHeader.mUnk_04 = p0;
}

void SetNextCourseId(u32 p0) {
    data_021759c0->mNextHeader.mCourseId = p0;
}

void func_020cca4c(u32 p0) {
    data_021759c0->mNextHeader.mUnk_10 = p0;
}

void func_020cca38(u32 p0) {
    data_021759c0->mNextHeader.mUnk_57 = (u8) p0;
}

void func_020cca24(u32 p0) {
    data_021759c0->mNextHeader.mUnk_24 = p0;
}

void func_020cca10(u32 p0) {
    data_021759c0->mNextHeader.mUnk_18 = p0;
}

void SetNextUseTeams(u32 p0) {
    data_021759c0->mNextHeader.mUseTeams = (u8) p0;
}

void func_020cc9e4(u32 p0) {
    data_021759c0->mUnk_3d8 = (u16) p0;
}

void func_020cc9d0(u32 p0) {
    data_021759c0->mNextHeader.mUnk_1c = p0;
}

void SetNextCourseListMode(u32 p0) {
    data_021759c0->mNextHeader.mCourseListMode = p0;
}

void func_020cc9a8(u32 p0) {
    data_0217b488->mUnk_78 = p0;
}

u32 func_020cc994(void) {
    return ((u32) data_0217b488->mUnk_04);
}
