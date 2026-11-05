#include "Main/Unknown/code_020cec50.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on

void func_020cec50(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        GxDispCntBits8To12Write2(0xb);
        func_02148950((u16) 1, (u32) 0, 1);
        GxsDispCntBits8To12Write2(8);
        GxsDispCntBits0To2Write((u32) 0);
    }
    GxsDispCntBits8To12Write2(0x12);
    func_02026058();
}

#pragma thumb off
