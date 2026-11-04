#include "Main/Unknown/code_02060c38.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

void func_02060c38(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    value1 = (u32) &data_0217aa08;
    value3 = 0x874u;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = value0;
    value0 = (u32) * (const u32 *) ((value2) + (32));
    value12 = (u32) &MemCopy;
    value2 = 0x2d0u;
    value0 = (value0) + (value3);
    MemCopy((const void *) value0, (void *) value1, value2);
}
