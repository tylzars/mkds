#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020cea28.h"
#include "code_021488e8.h"
#include "code_02148950.h"

#pragma thumb on

void func_020cea28(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        func_020ce760(0xb);
        func_02148950((u16) 1, (u32) 0, 1);
        func_020ce744(8);
        GxsDispCntBits0To2Write((u32) 0);
    }
    func_020ce744(0x12);
    func_02026058();
}

#pragma thumb off
