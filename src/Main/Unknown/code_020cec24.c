#include "Main/Unknown/code_020cec24.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02026000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020cec24(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
        case 3:
            func_020ccc74(0x10, 0x1f);
            break;
        case 2:
            func_020ccc74(0xe, 0x1f);
            break;
    }
}
#pragma thumb off
