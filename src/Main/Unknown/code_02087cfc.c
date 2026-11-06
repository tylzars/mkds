#include "Main/Unknown/code_02087cfc.h"

void func_02087cfc(void *arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = *(const u32 *) ((value0) + (32));
    *(u32 *) ((value3) + ((value1 << 2))) = value2;
    *(u16 *) ((value0) + (0)) = value2;
}
