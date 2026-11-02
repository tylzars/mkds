#include "Main/Unknown/code_0204a928.h"

void func_0204a928(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 compareLeft0;
    u32 compareRight0;
    value1 = (u32) * (const u32 *) ((value0) + (8));
    compareLeft0 = value1;
    compareRight0 = 1u;
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
        return;
    }
    value3 = (u32) * (const u16 *) ((value0) + (4));
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0u;
    value3 = (value3 << 1);
    *(u32 *) ((value2) + (0)) = value3;
    *(u32 *) ((value0) + (8)) = value1;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0xdccu;
    func_0200ee58((void *) value0, value1);
}
