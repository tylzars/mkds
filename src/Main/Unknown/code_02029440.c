#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 func_020296e4(void) {
    return ((u32) data_02174e1c->mCourseId);
}

u32 func_020296d4(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mCharacterIndex);
}

u32 func_020296c0(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mKartIndex);
}

u32 func_020296ac(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mUnk_08);
}

u32 func_0202969c(void) {
    return ((u32) data_02174e1c->mUnk_d4);
}

u32 func_0202968c(void) {
    return ((u32) data_02174e1c->mUnk_cc);
}

u32 func_0202967c(void) {
    return ((u32) data_02174e1c->mUnk_d8);
}

u32 func_0202966c(void) {
    return ((u32) data_02174e1c->mUnk_c0);
}

u32 func_0202965c(void) {
    return ((u32) data_02174e1c->mCourseListMode);
}

u32 func_0202964c(void) {
    return ((u32) data_02174e1c->mUnk_e8);
}

u32 func_0202963c(void) {
    return ((u32) data_02174e1c->mUnk_ec);
}

u32 func_0202962c(void) {
    return ((u32) data_02174e1c->mUseTeams);
}

u32 func_02029618(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mTeamIndex);
}

u32 func_02029608(void) {
    return ((u32) data_02174e1c->mMissionTableRow);
}

u32 func_020295f8(void) {
    return ((u32) data_02174e1c->mMissionTableColumn);
}

u32 func_020295e4(void) {
    return ((u32) data_02174e1c->mUnk_10c);
}

u32 func_020295d0(void) {
    return ((u32) data_02174e1c->mUnk_10d);
}

void func_020295c0(u32 p0) {
    data_02174e1c->mUnk_d4 = p0;
}

void func_020295b0(void) {
    data_02174e1c->mUnk_d8 = 1;
}

void func_020295a0(void) {
    data_02174e1c->mUnk_d8 = 0;
}

void func_02029590(u32 p0) {
    data_02174e1c->mUnk_cc = p0;
}

void func_02029580(u32 p0) {
    data_02174e1c->mCourseId = p0;
}

void func_02029570(u32 p0) {
    data_02174e1c->mUnk_c0 = p0;
}

void func_02029560(u32 p0) {
    data_02174e1c->mCourseListMode = p0;
}

void func_02029550(u16 p0) {
    data_02174e1c->mUnk_e8 = p0;
}

void func_02029540(u32 p0) {
    data_02174e1c->mUnk_ec = p0;
}

void func_02029530(void) {
    data_02174e1c->mUseTeams = 1;
}

void func_02029520(void) {
    data_02174e1c->mUseTeams = 0;
}

#pragma thumb off

#pragma thumb on

void func_0202950c(u16 a, u32 b) {
    data_02174e1c->mUnk_00[a].mTeamIndex = b;
}

void func_020294fc(u16 a, u32 b) {
    data_02174e1c->mUnk_00[a].mCharacterIndex = b;
}

void func_020294e8(u16 a, u32 b) {
    data_02174e1c->mUnk_00[a].mKartIndex = b;
}

void func_020294d4(u16 a, u32 b) {
    data_02174e1c->mUnk_00[a].mUnk_08 = b;
}

void func_020294c0(u16 a, u32 b) {
    data_02174e1c->mUnk_00[a].mUnk_10 = b;
}

void func_020294ac(u16 a, u32 b) {
    data_02174e1c->mUnk_00[a].mUnk_14 = b;
}

#pragma thumb off

#pragma thumb on

void func_0202949c(u32 p0) {
    data_02174e1c->mUnk_e0 = p0;
}

void func_0202948c(u32 p0) {
    data_02174e1c->mMissionTableRow = (u8) p0;
}

void func_0202947c(u32 p0) {
    data_02174e1c->mMissionTableColumn = (u8) p0;
}

void func_02029468(u32 p0) {
    data_02174e1c->mMissionFileRowIndex = (u16) p0;
}

void func_02029454(u32 p0) {
    data_02174e1c->mUnk_10c = (u8) p0;
}

void func_02029440(u32 p0) {
    data_02174e1c->mUnk_10d = (u8) p0;
}

#pragma thumb off
