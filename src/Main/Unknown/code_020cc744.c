#include "Main/Unknown/code_020cc744.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020cc0e4.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cc994.h"
#include "Main/Unknown/code_020ccab0.h"
#include "Main/Unknown/code_020ccb78.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccbb8.h"
#include "Main/Unknown/code_02045874.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cc744(void) {
    u16 i;
    u8 b[2];

    if (func_020cc120() != 2) {
        if (GetRaceSetupCopy()->mMode == 0) {
            switch (GetRaceSetupCopy()->mEngineIndex) {
                case 0:
                    GetRaceSetupCopy()->mUnk_c0 = 1;
                    break;
                case 1:
                    GetRaceSetupCopy()->mUnk_c0 = 2;
                    break;
                case 2:
                    GetRaceSetupCopy()->mUnk_c0 = 3;
                    break;
            }
        }
        func_020cca9c(GetRaceSetupCopy()->mUnk_c0);
        if (GetRaceSetupCopy()->mMode != 2 && GetRaceSetupCopy()->mMode != 3) {
            GetRaceSetupCopy()->mUseTeams = 0;
        }
        switch (GetRaceSetupCopy()->mMode) {
            case 0:
                func_020ccbb8();
                break;
            case 1:
                func_020ccb78();
                break;
            case 2:
            case 3:
            case 4:
                func_020ccab0();
                break;
        }
        SetNextMode(GetRaceSetupCopy()->mMode);
        SetNextCupIndex(GetRaceSetupCopy()->mCupIndex);
        if (GetRaceSetupCopy()->mMode == 0) {
            GetRaceSetupCopy()->mCourseId = GetCupCourseId(GetRaceSetupCopy()->mCupIndex, 0);
        }
        SetNextCourseId(GetRaceSetupCopy()->mCourseId);
        if (GetRaceSetupCopy()->mMode == 1) {
            GetRaceSetupCopy()->mEngineIndex = 2;
        } else if (GetRaceSetupCopy()->mMode == 2) {
            GetRaceSetupCopy()->mEngineIndex = 0;
        } else if (GetRaceSetupCopy()->mMode == 3) {
            if (func_020cae54() != 0 && func_020cae38() != 0) {
                GetRaceSetupCopy()->mEngineIndex = 1;
            }
        }
        SetNextEngineIndex(GetRaceSetupCopy()->mEngineIndex);
        SetNextMirrorMode(GetRaceSetupCopy()->mMirrorMode);
        func_020cca24(GetRaceSetupCopy()->mUnk_e0);
        func_020cca10(GetRaceSetupCopy()->mUnk_e4);
        SetNextUseTeams(GetRaceSetupCopy()->mUseTeams);
        SetCourseCount(GetRaceSetupCopy()->mCourseCount);
        func_020cc9d0(GetRaceSetupCopy()->mUnk_ec);
        SetNextCourseListMode(GetRaceSetupCopy()->mCourseListMode);
        if (GetRaceSetupCopy()->mMode == 4 && func_020cbad0() == 0) {
            i = GetRaceSetupCopy()->mMissionFileRowIndex;
            FindMissionTableCell(GetRaceSetupCopy()->mMissionFileRows[i].mMissionTableValue, &b[0], &b[1]);
            func_02044380(&GetRaceSetupCopy()->mMissionFileRows[i], b[0], b[1]);
        }
    } else {
        SetNextCupIndex(GetRaceSetupCopy()->mCupIndex);
        SetNextCourseId(GetRaceSetupCopy()->mCourseId);
    }
    if (GetRaceSetupCopy()->mMode == 0) {
        func_020cc9a8(0);
    } else {
        func_020cc9a8(1);
    }
    if (func_020cc994() != 0) {
        func_02045ed0();
        func_020cc10c(0);
    }
}
