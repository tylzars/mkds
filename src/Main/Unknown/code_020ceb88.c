#include "Main/Unknown/code_020ceb88.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_020cebe4.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ceb88(void) {
    switch (AdvanceSelectRaceRule()) {
        case 1:
            if (func_020cebe4() != 0) {
                GetRaceSetupCopy()->mCourseListMode = 2;
            }
            if (GetRaceSetupCopy()->mCourseListMode == 2) {
                GetRaceSetupCopy()->mCourseId = COURSE_ID_MINI_STAGE1;
                func_020ccc74(0x1d, 0x1f);
            } else {
                func_020ccc74(SCREEN_SELECT_BATTLE_STAGE, 0x1f);
            }
            break;
        case 2:
            func_020ccc74(0xf, 0x1f);
            break;
    }
}
#pragma thumb off
