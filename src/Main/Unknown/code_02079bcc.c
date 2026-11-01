#include "Main/Unknown/code_02079bcc.h"

Unk0206bcb0_590 *func_02079bf0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ad00;
    value1 = 0xb4u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (Unk0206bcb0_590 *) value0;
}

void *func_02079bcc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ad00;
    value1 = 0xb4u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (20));
    value0 = (u32) * (const u32 *) ((value0) + (4));
    return (void *) value0;
}
