#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_020ce7e4.h"
#include "Main/Unknown/code_021189f4.h"
#include "code_021488e8.h"
#include "code_02148950.h"

#pragma thumb on

void func_020ce7e4(void) {
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
            func_020ce760(0x1c);
            func_02148950((u16) 1, (u32) 0, 0);
            func_020ce744(0x12);
            GxsDispCntBits0To2Write((u32) 0);
        }
    }
    func_02118e30();
}

#pragma thumb off
