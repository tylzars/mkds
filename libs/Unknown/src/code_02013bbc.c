#include "code_02013bbc.h"

u32 *func_02013bcc(const void *a, u32 b) {
    u32 value0 = (u32) a;
    u32 value1 = b;
    u32 value2;
    value2 = (u32) * (const u16 *) ((value0) + (8));
    value0 = (value0) + (value2);
    value0 = (value0) + ((value1 << 4));
    return (u32 *) value0;
}

u32 *func_02013bbc(const void *a, u32 b) {
    u32 value0 = (u32) a;
    u32 value1 = b;
    u32 value2;
    value2 = (u32) * (const u16 *) ((value0) + (10));
    value0 = (value0) + (value2);
    value0 = (value0) + ((value1 << 4));
    return (u32 *) value0;
}
