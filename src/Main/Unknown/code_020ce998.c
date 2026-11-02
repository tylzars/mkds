#include "Main/Unknown/code_020ce998.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02028000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ce998(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            func_020ccc74(0xa, 0x1f);
            break;
        case 2:
            func_020ccc74(8, 0x1f);
            break;
    }
}
#pragma thumb off
