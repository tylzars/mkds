#include "code_0201750c.h"

void ListInit(Unk02017328 *arg0, u16 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = 0u;
    *(u32 *) ((value0) + (0)) = value2;
    *(u32 *) ((value0) + (4)) = value2;
    *(u16 *) ((value0) + (8)) = (u16) value2;
    *(u16 *) ((value0) + (10)) = (u16) value1;
}

void ListAppendToEmpty(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value3 = (u32) * (const u16 *) ((value0) + (10));
    value2 = 0u;
    value12 = (value1) + (value3);
    *(u32 *) ((value12) + (4)) = value2;
    *(u32 *) ((value1) + (value3)) = value2;
    *(u32 *) ((value0) + (0)) = value1;
    *(u32 *) ((value0) + (4)) = value1;
    value1 = (u32) * (const u16 *) ((value0) + (8));
    value1 = (value1) + (1u);
    *(u16 *) ((value0) + (8)) = (u16) value1;
}
