#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Unknown/code_020cc5d8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_021804e0.h"
#include "registers.h"

s32 func_020cc5b8(void) {
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        return data_021759c0->mMissionTableRow;
    }
    return -1;
}

s32 func_020cc598(void) {
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        return data_021759c0->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
#pragma optimize_for_size on
void func_020cc3e8(void) {
    u16 i;

    for (i = 0; i < 8; i++) {
        GetRaceSetupCopy()->mEntries[i].mCharacterIndex = GetCurrentCharacterIndex(i);
        GetRaceSetupCopy()->mEntries[i].mKartIndex = GetCurrentKartIndex(i);
        GetRaceSetupCopy()->mEntries[i].mPlayerKind = GetCurrentPlayerKind(i);
        if (GetCurrentUseTeams() != 0) {
            GetRaceSetupCopy()->mEntries[i].mTeamIndex = GetCurrentTeamIndex(i);
        } else {
            GetRaceSetupCopy()->mEntries[i].mTeamIndex = -1;
        }
        GetRaceSetupCopy()->mEntries[i].mUnk_10 = func_020cc6a4(i);
        GetRaceSetupCopy()->mEntries[i].mUnk_14 = 0;
    }
    GetRaceSetupCopy()->mCupIndex = GetCurrentCupIndex();
    GetRaceSetupCopy()->mUnk_c0 = func_020cc67c();
    GetRaceSetupCopy()->mKartCount = GetCurrentKartCount();
    if (func_020cae54() != 0) {
        u32 v;

        v = GetCurrentMode();
        switch (v) {
            case 0:
            case 1:
            case 4:
                GetRaceSetupCopy()->mMode = 3;
                break;
            case 2:
            case 3:
            case 5:
                GetRaceSetupCopy()->mMode = v;
                break;
        }
    } else {
        GetRaceSetupCopy()->mMode = GetCurrentMode();
    }
    if (func_020cae38() != 0) {
        GetRaceSetupCopy()->mCourseId = COURSE_ID_OLD_MARIO_SFC;
    } else {
        GetRaceSetupCopy()->mCourseId = GetCurrentCourseId();
    }
    GetRaceSetupCopy()->mEngineIndex = func_020cc62c();
    GetRaceSetupCopy()->mUnk_d8 = func_020cc618();
    GetRaceSetupCopy()->mUseTeams = GetCurrentUseTeams();
    GetRaceSetupCopy()->mUnk_e4 = func_020cc604();
    GetRaceSetupCopy()->mUnk_e4 = func_020cc604();
    GetRaceSetupCopy()->mUnk_e8 = func_020cc5ec();
    GetRaceSetupCopy()->mUnk_ec = func_020cc5d8();
    if (GetCurrentMode() == MODE_MISSION_RUN) {
        GetRaceSetupCopy()->mMissionTableRow = func_020cc5b8();
        GetRaceSetupCopy()->mMissionTableColumn = func_020cc598();
    }
}

void func_020cc3b8(void) {
    s32 i;

    for (i = 0; i < 0x1e; i++) {
        data_0217b43c->mUnk_014[i].mUnk_00 = data_0216ab34[i].mUnk_00;
        data_0217b43c->mUnk_014[i].mUnk_04 = data_0216ab34[i].mUnk_04;
    }
}

void func_020cc36c(void) {
    if (func_020cbad0() == 0) {
        func_02077c1c();
    }
    data_0217b43c->mUnk_014[data_0217b43c->mUnk_00c].mUnk_00();
    func_021258f0();
    data_0217b43c->mUnk_004 = 0;
    func_020ae5f0(data_0217b43c->mUnk_108, data_0217b43c->mUnk_50c);
}
#pragma thumb off

void func_020cc330(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg0Record(a->mUnk_28, b, c, d, e, f, g, h);
}

void func_020cc2f4(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg1Record(a->mUnk_28, b, c, d, e, f, g, h);
}

void func_020cc2c0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg2RecordParams(a->mUnk_28, b, c, d, e, f, g);
}

void func_020cc28c(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(a->mUnk_28, b, c, d, e, f, g);
}

void func_020cc250(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg0Record(a->mUnk_70, b, c, d, e, f, g, h);
}

void func_020cc214(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg1Record(a->mUnk_70, b, c, d, e, f, g, h);
}

void func_020cc1e0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg2RecordParams(a->mUnk_70, b, c, d, e, f, g);
}

void func_020cc1ac(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(a->mUnk_70, b, c, d, e, f, g);
}

void func_020cc18c(u32 a) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | a;
}

void func_020cc168(u32 a) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | a;
}
