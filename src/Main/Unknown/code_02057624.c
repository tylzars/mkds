#include "Main/Unknown/code_02057624.h"
#include "code_0214d018.h"

#pragma thumb on
void func_02057624(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = (value0) + (0u);
    value1 = 0u;
    value2 = 36u;
    func_0214d168((void *) value0, (u8) value1, value2);
    value1 = 0u;
    *(u16 *) ((value4) + 0u) = (u16) value1;
    *(u16 *) ((value4) + 2u) = (u16) value1;
    *(u16 *) ((value4) + 4u) = (u16) value1;
    *(u16 *) ((value4) + 6u) = (u16) value1;
    *(u16 *) ((value4) + 8u) = (u16) value1;
    *(u16 *) ((value4) + 10u) = (u16) value1;
    value2 = (u32) * (const u16 *) ((value4) + 12u);
    value0 = 127u;
    value2 = (value2) & ~(value0);
    *(u16 *) ((value4) + 12u) = (u16) value2;
    value2 = (u32) * (const u16 *) ((value4) + 12u);
    value0 = 0xfffff87fu;
    value2 = (value2) & (value0);
    value0 = 128u;
    value2 = (value2) | (value0);
    *(u16 *) ((value4) + 12u) = (u16) value2;
    value2 = (u32) * (const u16 *) ((value4) + 12u);
    value0 = 0xffff07ffu;
    value2 = (value2) & (value0);
    value0 = 0x800u;
    value2 = (value2) | (value0);
    *(u16 *) ((value4) + 12u) = (u16) value2;
    value0 = (value4) + (0u);
    value0 = (value0) + 14u;
    value2 = 20u;
    func_0214d168((void *) value0, (u8) value1, value2);
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    value1 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = 1u;
    value1 = (value1) & ~(value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    value1 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = 2u;
    value1 = (value1) & ~(value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    value1 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = 4u;
    value1 = (value1) & ~(value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 34u;
    value1 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = 8u;
    value1 = (value1) & ~(value0);
    value4 = (value4) + 34u;
    *(u8 *) ((value4) + 0u) = (u8) value1;
}
#pragma thumb off
