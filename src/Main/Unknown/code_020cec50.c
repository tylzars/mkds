#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "Main/Unknown/code_020cec50.h"
#include "code_021488e8.h"
#include "code_02148950.h"

#pragma thumb on

void func_020cec50(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        func_020ceb70(0xb);
        func_02148950((u16) 1, (u32) 0, 1);
        func_020ceb54(8);
        func_02148934((u32) 0);
    }
    func_020ceb54(0x12);
    func_02026058();
}

#pragma thumb off
