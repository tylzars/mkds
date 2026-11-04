#include "Main/Unknown/code_02043a34.h"
#include "Main/Unknown/code_020ae340.h"
#include "Main/Unknown/code_020cc744.h"
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

#pragma thumb on
#pragma optimize_for_size on
void func_020cc744(void) {
    u16 i;
    u8 b[2];

    if (func_020cc120() != 2) {
        if (func_02029930()->mUnk_c8 == 0) {
            switch (func_02029930()->mUnk_d4) {
                case 0:
                    func_02029930()->mUnk_c0 = 1;
                    break;
                case 1:
                    func_02029930()->mUnk_c0 = 2;
                    break;
                case 2:
                    func_02029930()->mUnk_c0 = 3;
                    break;
            }
        }
        func_020cca9c(func_02029930()->mUnk_c0);
        if (func_02029930()->mUnk_c8 != 2 && func_02029930()->mUnk_c8 != 3) {
            func_02029930()->mUseTeams = 0;
        }
        switch (func_02029930()->mUnk_c8) {
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
        func_020cca88(func_02029930()->mUnk_c8);
        func_020cca74(func_02029930()->mUnk_cc);
        if (func_02029930()->mUnk_c8 == 0) {
            func_02029930()->mCourseId = func_020ae3a4(func_02029930()->mUnk_cc, 0);
        }
        SetNextCourseId(func_02029930()->mCourseId);
        if (func_02029930()->mUnk_c8 == 1) {
            func_02029930()->mUnk_d4 = 2;
        } else if (func_02029930()->mUnk_c8 == 2) {
            func_02029930()->mUnk_d4 = 0;
        } else if (func_02029930()->mUnk_c8 == 3) {
            if (func_020cae54() != 0 && func_020cae38() != 0) {
                func_02029930()->mUnk_d4 = 1;
            }
        }
        func_020cca4c(func_02029930()->mUnk_d4);
        func_020cca38(func_02029930()->mUnk_d8);
        func_020cca24(func_02029930()->mUnk_e0);
        func_020cca10(func_02029930()->mUnk_e4);
        SetNextUseTeams(func_02029930()->mUseTeams);
        func_020cc9e4(func_02029930()->mUnk_e8);
        func_020cc9d0(func_02029930()->mUnk_ec);
        SetNextCourseListMode(func_02029930()->mCourseListMode);
        if (func_02029930()->mUnk_c8 == 4 && func_020cbad0() == 0) {
            i = func_02029930()->mMissionFileRowIndex;
            FindMissionTableCell(func_02029930()->mMissionFileRows[i].mMissionTableValue, &b[0], &b[1]);
            func_02044380(&func_02029930()->mMissionFileRows[i], b[0], b[1]);
        }
    } else {
        func_020cca74(func_02029930()->mUnk_cc);
        SetNextCourseId(func_02029930()->mCourseId);
    }
    if (func_02029930()->mUnk_c8 == 0) {
        func_020cc9a8(0);
    } else {
        func_020cc9a8(1);
    }
    if (func_020cc994() != 0) {
        func_02045ed0();
        func_020cc10c(0);
    }
}
