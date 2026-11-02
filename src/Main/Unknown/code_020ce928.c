#include "Main/Unknown/code_020ce928.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02119e14.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ce928(void) {
    switch (func_0211a7bc()) {
        case 1:
            if (func_02029930()->mUnk_f0 == 2) {
                func_02029930()->mUnk_d0 = 0x14;
                func_020ccc74(0x1d, 0x1f);
            } else {
                func_020ccc74(0xb, 0x1f);
            }
            break;
        case 2:
            func_020ccc74(9, 0x1f);
            break;
    }
}
#pragma thumb off
