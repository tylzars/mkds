#include "code_0201661c.h"

void func_0201661c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    *(u16 *) ((value0) + (10)) = (u16) value2;
    value1 = (u32) * (const u16 *) ((value0) + (10));
    *(u16 *) ((value0) + (8)) = (u16) value1;
    *(u16 *) ((value0) + (12)) = (u16) value2;
    *(u32 *) ((value0) + (16)) = value2;
}
