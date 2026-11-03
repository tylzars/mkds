#include "Main/Unknown/code_02026120.h"
#include "Main/Unknown/code_020ce9f0.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02026000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ce9f0(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            func_020ccc74(9, 0x1f);
            break;
        case 2:
            func_020ccc74(0, 0x1f);
            break;
        case 3:
            func_020ccc74(0xa, 0x1f);
            break;
    }
}
#pragma thumb off
