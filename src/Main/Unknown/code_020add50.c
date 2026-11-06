#include "Main/Unknown/code_020add50.h"
#include "Main/Unknown/code_020add80.h"
#include "code_02022aa8.h"

int func_020add50(Unk02022aa8 *arg0, int arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value4 = value1;
    value0 = func_020add80(arg0);
    value1 = *(const u32 *) ((value5) + (0));
    value1 = *(const u32 *) ((value1) + (8));
    value1 = (value1) + (8u);
    value0 = (value4) * (value0) + (value1);
    return value0;
}
