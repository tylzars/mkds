#include "Main/Unknown/code_020cc5d8.h"

#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Unknown/unk_021759c0.h"

u32 GetCurrentCharacterIndex(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (104));
    return value0;
}

u32 GetCurrentKartIndex(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (108));
    return value0;
}

u32 func_020cc6f0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (112));
    return value0;
}

u32 GetCurrentUseTeams(void) {
    return ((u32) data_021759c0->mUseTeams);
}

u32 GetCurrentTeamIndex(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (116));
    return value0;
}

u32 func_020cc6a4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (120));
    return value0;
}

u32 func_020cc690(void) {
    return ((u32) data_021759c0->mUnk_004);
}

u32 func_020cc67c(void) {
    return ((u32) data_021759c0->mUnk_014);
}

u32 GetCurrentKartCount(void) {
    return ((u32) data_021759c0->mKartCount);
}

u32 func_020cc654(void) {
    return ((u32) data_021759c0->mUnk_08);
}

u32 GetCurrentCourseId(void) {
    return ((u32) data_021759c0->mCourseId);
}

u32 func_020cc62c(void) {
    return ((u32) data_021759c0->mUnk_010);
}

u32 func_020cc618(void) {
    return ((u32) data_021759c0->mUnk_57);
}

u32 func_020cc604(void) {
    return ((u32) data_021759c0->mUnk_18);
}

u32 func_020cc5ec(void) {
    return ((u32) data_021759c0->mUnk_3d8);
}

u32 func_020cc5d8(void) {
    return ((u32) data_021759c0->mUnk_1c);
}
