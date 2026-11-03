#include "Main/Unknown/code_020aca08.h"
#include "Main/Unknown/code_02105e98.h"

#pragma thumb on

u32 func_020aca20(u32 p0) {
    return p0;
}

void func_020aca08(int a) {
    if (a != 0) {
        *(u16 *) (a + 4) = 0xb;
        func_02105e98();
    }
}

#pragma thumb off
