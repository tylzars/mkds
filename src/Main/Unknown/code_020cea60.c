#include "Main/Unknown/code_020cea60.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020ceaf8.h"
#include "01/code_0219c784.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020cea60(void) {
    s32 t[6] = {COURSE_ID_MINI_STAGE1, COURSE_ID_MINI_STAGE2,   COURSE_ID_MINI_STAGE3,
                COURSE_ID_MINI_STAGE4, COURSE_ID_MINI_BLOCK_64, COURSE_ID_MINI_DOKAN_GC};
    s32 a;

    a = AdvanceSelectBattleStage();
    switch (a) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            func_02029930()->mCourseId = t[a];
            func_020ccc74(0x1d, 0x1f);
            break;
        case -3:
            func_020ccc74(0x10, 0x1f);
            break;
        case -2:
            func_020ccc74(0xe, 0x1f);
            func_020ceb0c(0);
            func_020ceaf8(1);
            break;
        case -1:
            func_020ccc74(0x1b, 0x1f);
            func_020ceb0c(0);
            func_020ceaf8(1);
            break;
    }
}
#pragma thumb off
