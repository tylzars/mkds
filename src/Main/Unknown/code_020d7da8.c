#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d7db4.h"

#pragma thumb on
void func_020d7da8(Unk020e0144 *arg0, Unk020fa294 *arg1, s32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value1 = (u32) * (const u16 *) ((value1) + 38u);
    value3 = (u32) &func_020d7db4;
    func_020d7db4((Unk020e0144 *) value0, value1, value2);
}
#pragma thumb off
