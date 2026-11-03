#include "Main/Unknown/code_020add50.h"
#include "Main/Unknown/code_020add80.h"

int func_020add50(u32 arg0, int arg1) {
    u32 value0 = arg0;
    u32 value1 = (u32) arg1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value4 = value1;
    value0 = (u32) func_020add80(value0);
    value1 = (u32) * (const u32 *) ((value5) + (0));
    value1 = (u32) * (const u32 *) ((value1) + (8));
    value1 = (value1) + (8u);
    value0 = (value4) * (value0) + (value1);
    return value0;
}
