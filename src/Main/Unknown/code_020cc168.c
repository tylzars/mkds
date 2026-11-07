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

// Returns the mission table row, or -1 outside Mission Run.
s32 GetRaceSetupMissionTableRow(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableRow;
    }
    return -1;
}

// Returns the mission table column, or -1 outside Mission Run.
s32 GetRaceSetupMissionTableColumn(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
#pragma optimize_for_size on
// Fills the race setup copy from the current setup; some modes are remapped and the course can be forced.
void CopyCurrentToRaceSetupCopy(void) {
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
    GetRaceSetupCopy()->mCpuDifficulty = GetCurrentCpuDifficulty();
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
    GetRaceSetupCopy()->mEngineIndex = GetCurrentEngineIndex();
    GetRaceSetupCopy()->mMirrorMode = GetCurrentMirrorMode();
    GetRaceSetupCopy()->mUseTeams = GetCurrentUseTeams();
    GetRaceSetupCopy()->mBattleKind = GetCurrentBattleKind();
    GetRaceSetupCopy()->mBattleKind = GetCurrentBattleKind();
    GetRaceSetupCopy()->mCourseCount = GetCurrentCourseCount();
    GetRaceSetupCopy()->mRuleKind = GetCurrentRuleKind();
    if (GetCurrentMode() == MODE_MISSION_RUN) {
        GetRaceSetupCopy()->mMissionTableRow = GetRaceSetupMissionTableRow();
        GetRaceSetupCopy()->mMissionTableColumn = GetRaceSetupMissionTableColumn();
    }
}

void CopyMenuScreenCallbacks(void) {
    s32 i;

    for (i = 0; i < 0x1e; i++) {
        data_0217b43c->mScreenCallbacks[i].mUnk_00 = data_0216ab34[i].mUnk_00;
        data_0217b43c->mScreenCallbacks[i].mUpdate = data_0216ab34[i].mUpdate;
    }
}

void func_020cc36c(void) {
    if (func_020cbad0() == 0) {
        AdvanceKartModelMenuLoad();
    }
    data_0217b43c->mScreenCallbacks[data_0217b43c->mScreenNumber].mUnk_00();
    func_021258f0();
    data_0217b43c->mUnk_004 = 0;
    func_020ae5f0(data_0217b43c->mMainOam, data_0217b43c->mSubOam);
}
#pragma thumb off

void SetMainBg0Record(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg0Record(a->mMainBgRecords, b, c, d, e, f, g, h);
}

void func_020cc2f4(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg1Record(a->mMainBgRecords, b, c, d, e, f, g, h);
}

void func_020cc2c0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg2RecordParams(a->mMainBgRecords, b, c, d, e, f, g);
}

void func_020cc28c(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(a->mMainBgRecords, b, c, d, e, f, g);
}

void SetSubBg0Record(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg0Record(a->mSubBgRecords, b, c, d, e, f, g, h);
}

void SetSubBg1Record(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg1Record(a->mSubBgRecords, b, c, d, e, f, g, h);
}

void func_020cc1e0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg2RecordParams(a->mSubBgRecords, b, c, d, e, f, g);
}

void func_020cc1ac(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(a->mSubBgRecords, b, c, d, e, f, g);
}

void func_020cc18c(u32 a) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | a;
}

void SetSubDispcntBits(u32 a) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | a;
}
