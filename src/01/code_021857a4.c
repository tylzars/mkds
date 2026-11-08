#include "01/code_021857a4.h"
#include "01/code_0218550c.h"
#include "01/code_02185ef4.h"
#include "01/code_0219e000.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_ov001_02197b34.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_021173e4.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_0211e000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "gx.h"
#include "code_02148950.h"
#include "registers.h"

#pragma optimize_for_size on

u16 func_ov001_02185b50(MissionGateObject *missionGateObject) {
    return missionGateObject->mNsbmaFrameIndex != 0;
}

void func_ov001_02185b1c(void) {
    if (func_020cccc0()) {
        func_ov001_02185ad8(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        func_ov001_02185abc(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteMissionRunLVselBg0Offset();
}

void UpdateMissionRunLVsel(void) {
    switch (AdvanceMissionRunLVsel()) {
        case 1:
            SwitchMenuScreen(SCREEN_MISSION_RUN_MSSEL, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0, 0x1f);
            break;
    }
}

#pragma thumb off
void func_ov001_02185ad8(u32 bits) {
    vu32 *dispCnt = &reg_GX_DISPCNT;
    *dispCnt = (*dispCnt & ~0x1f00) | (bits << 8);
}

void func_ov001_02185abc(u32 bits) {
    vu32 *dispCnt = &reg_GXS_DB_DISPCNT;
    *dispCnt = (*dispCnt & ~0x1f00) | (bits << 8);
}
#pragma thumb on

void func_ov001_02185a88(void) {
    if (func_020cccc0()) {
        func_ov001_02185ad8(0x1b);
        GX_SetGraphicsMode(1, 0, 0);
        func_ov001_02185abc(0x16);
        GXS_SetGraphicsMode(0);
    }
    func_ov001_0219f8ec();
}

void UpdateMissionRunMSsel(void) {
    switch (AdvanceMissionRunMSsel()) {
        case 1:
            SwitchMenuScreen(0x1d, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(SCREEN_MISSION_RUN_LVSEL, 0x1f);
            break;
    }
}

void func_ov001_02185a28(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        func_ov001_0218568c(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteTimeAttackTopMenuBg0Offset();
}

#pragma thumb off
void SetGhostSceneInitialCallbacksIndex(s32 callbacksIndex) {
    data_0217b488->mGhostSceneInitialCallbacksIndex = callbacksIndex;
}
#pragma thumb on

void UpdateTimeAttackTopMenu(void) {
    switch (AdvanceTimeAttackTopMenu()) {
        case 1:
            SwitchMenuScreen(0x15, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0x1c, 0x1f);
            SetGhostSceneInitialCallbacksIndex(0);
            break;
        case 3:
            SwitchMenuScreen(0x1c, 0x1f);
            SetGhostSceneInitialCallbacksIndex(1);
            break;
        case 4:
            SwitchMenuScreen(0, 0x1f);
            break;
    }
}

void func_ov001_02185980(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        func_ov001_0218568c(8);
        GXS_SetGraphicsMode(0);
    }
    func_ov001_0218568c(0x12);
    WriteSelectCharacterRegisters();
}

void UpdateTimeAttackSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            SwitchMenuScreen(0x16, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(SCREEN_TIME_ATTACK_TOP_MENU, 0x1f);
            break;
    }
}

void func_ov001_02185928(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0xb);
        GX_SetGraphicsMode(1, 0, 1);
    }
    func_ov001_0218568c(0x12);
    WriteSelectKartRegisters();
}

void UpdateTimeAttackSelectKart(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            SwitchMenuScreen(0x17, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0x15, 0x1f);
            break;
    }
}

void func_ov001_021858c8(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        func_ov001_0218568c(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupGridRegisters();
}

#pragma thumb off
void func_ov001_021858b4(s32 value) {
    data_0217b488->mUnk_08 = value;
}

void func_ov001_021858a0(s32 value) {
    data_0217b488->mUnk_04 = value;
}
#pragma thumb on

void UpdateTimeAttackSelectCupGrid(void) {
    switch (AdvanceSelectCupGrid()) {
        case 1:
            SwitchMenuScreen(0x18, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0x16, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0, 0x1f);
            func_ov001_021858b4(0);
            func_ov001_021858a0(1);
            break;
    }
}

void func_ov001_02185828(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        func_ov001_0218568c(0x1e);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupCourseBgOffsets();
}

void UpdateTimeAttackSelectCupCourse(void) {
    switch (AdvanceSelectCupCourse()) {
        case 1:
            if (func_0211e130()) {
                SwitchMenuScreen(0x1d, 0x1f);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_GHOST, 0x1f);
            }
            break;
        case 2:
            SwitchMenuScreen(0x18, 0x1f);
            break;
    }
}

#pragma thumb off
void WriteMainBg1Offset(u32 offsetX, u32 offsetY) {
    reg_G2_BG1OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void func_ov001_021857a4(u32 bits) {
    vu16 *bg1Cnt = &reg_G2_BG1CNT;
    *bg1Cnt = (*bg1Cnt & ~3) | bits;
}
#pragma thumb on
