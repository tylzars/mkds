#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020ccab0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ccb48.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ccab0(void) {
    u8 i;
    s32 a;

    for (i = 0; i < 8; i++) {
        if (func_02029930()->mUnk_c0 == 0 && func_02029930()->mUnk_00[i].mUnk_08 == 1) {
            func_020ccb48(i);
        } else {
            a = func_02029930()->mUseTeams != 0 ? func_02029930()->mUnk_00[i].mTeamIndex : -1;
            func_020468b0(i, func_02029930()->mUnk_00[i].mCharacterIndex, func_02029930()->mUnk_00[i].mKartIndex,
                          func_02029930()->mUnk_00[i].mUnk_08, a, func_02029930()->mUnk_00[i].mUnk_10);
        }
    }
}
#pragma thumb off
