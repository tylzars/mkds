#include "Main/Unknown/code_02009c34.h"
#include "Main/Unknown/code_02009c90.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

#pragma thumb on

u32 func_02009c34(void) {
    u32 v1;
    u32 v2;
    v1 = 1;
    v2 = IrqDisable();
    if (data_0216fda8->mUnk_526 == 0) {
        v1 = 0;
        // the address of mUnk_5e4 is computed with a 64-bit add; its low half is the same address, and the leftover
        // flag-setting add (removed after register allocation) is what gives the original's registers
        *(u32 *) ((u32) data_0216fda8 + 0x5e4LL) = v1;
        data_0216fda8->mUnk_526 = 1;
        if (func_0200b018() != 0) {
            func_0200aeb4(func_02009c90);
        } else {
            v1 = func_02009c98();
        }
    }
    IrqRestore(v2);
    return v1;
}

#pragma thumb off
