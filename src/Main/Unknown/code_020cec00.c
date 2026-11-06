#include "Main/Unknown/code_020cec00.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "Main/Unknown/code_02119e14.h"
#include "code_021488e8.h"

#pragma thumb on

void func_020cec00(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        GxsDispCntBits8To12Write2(0x1f);
        GXS_SetGraphicsMode((u32) 0);
    }
    func_0211a794();
}

#pragma thumb off
