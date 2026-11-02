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
            a = func_02029930()->mUnk_dc != 0 ? func_02029930()->mUnk_00[i].mUnk_0c : -1;
            func_020468b0(i, func_02029930()->mUnk_00[i].mUnk_00, func_02029930()->mUnk_00[i].mUnk_04,
                          func_02029930()->mUnk_00[i].mUnk_08, a, func_02029930()->mUnk_00[i].mUnk_10);
        }
    }
}
#pragma thumb off
