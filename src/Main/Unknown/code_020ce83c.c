#include "Main/Unknown/code_020ce83c.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_020ce894.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupGrid(void) {
    switch (AdvanceSelectCupGrid()) {
        case 1:
            func_020ccc74(0xc, 0x1f);
            break;
        case 2:
            func_020ccc74(0xa, 0x1f);
            break;
        case 3:
            if (func_020ce8bc() == 0) {
                func_020ccc74(0, 0x1f);
            } else {
                func_020ccc74(0xe, 0x1f);
            }
            func_020ce8a8(0);
            func_020ce894(1);
            break;
    }
}
#pragma thumb off
