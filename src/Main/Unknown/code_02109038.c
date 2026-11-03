#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_0210c134.h"

void func_02109038(void *arg0, u32 arg1, void *arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    u32 value12;
    value12 = (u32) &func_0210c134;
    *(u8 *) ((value0) + (60)) = (u8) value1;
    value3 = ~(0u);
    value1 = value2;
    *(u32 *) ((value0) + (64)) = value3;
    func_0210c134(value0, value1);
}
