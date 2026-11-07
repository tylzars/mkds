#include "Main/Unknown/code_020cc5d8.h"

#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Unknown/unk_021759c0.h"

u32 GetCurrentCharacterIndex(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceSetup;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (104));
    return value0;
}

u32 GetCurrentKartIndex(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceSetup;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (108));
    return value0;
}

u32 GetCurrentPlayerKind(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceSetup;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (112));
    return value0;
}

u32 GetCurrentUseTeams(void) {
    return (gRaceSetup->mUseTeams);
}

u32 GetCurrentTeamIndex(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceSetup;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (116));
    return value0;
}

u32 func_020cc6a4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceSetup;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (120));
    return value0;
}

u32 GetCurrentCupIndex(void) {
    return (gRaceSetup->mCupIndex);
}

u32 func_020cc67c(void) {
    return (gRaceSetup->mUnk_014);
}

u32 GetCurrentKartCount(void) {
    return (gRaceSetup->mKartCount);
}

u32 GetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

u32 GetCurrentCourseId(void) {
    return (gRaceSetup->mCourseId);
}

u32 GetCurrentEngineIndex(void) {
    return (gRaceSetup->mEngineIndex);
}

u32 GetCurrentMirrorMode(void) {
    return (gRaceSetup->mMirrorMode);
}

u32 func_020cc604(void) {
    return (gRaceSetup->mUnk_18);
}

u32 GetCurrentCourseCount(void) {
    return (gRaceSetup->mCourseCount);
}

u32 func_020cc5d8(void) {
    return (gRaceSetup->mUnk_1c);
}
