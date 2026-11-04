#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce6ec.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "code_021488e8.h"
#include "code_02148950.h"

#pragma thumb on

void func_020ce6ec(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        v1 = func_020ce778();
        if (v1 == 0) {
            func_020ce760(0x19);
            func_02148950((u16) 1, (u32) 0, 0);
            func_020ce744(0x1e);
            GxsDispCntBits0To2Write((u32) 0);
        } else {
            func_020ce760(0x18);
            func_02148950((u16) 1, (u32) 0, 0);
            func_020ce744(0x12);
            GxsDispCntBits0To2Write((u32) 0);
        }
    }
    func_0211e4e8();
}

#pragma thumb off
