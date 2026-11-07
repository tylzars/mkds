#include "Main/Unknown/code_02057624.h"
#include "code_0214d018.h"

#pragma thumb on
// Sets a buddy record to empty: counts zero, date year 0 month 1 day 1, no name, flags clear.
void ResetBuddyRecord(u32 recordAddress) {
    u32 value0 = recordAddress;
    u32 value1;
    u32 value2;
    u32 recordBase;
    recordBase = (value0) + (0u);
    value1 = 0u;
    value2 = 36u;
    MI_CpuFill8((void *) value0, value1, value2);
    value1 = 0u;
    *(u16 *) ((recordBase) + 0u) = value1;
    *(u16 *) ((recordBase) + 2u) = value1;
    *(u16 *) ((recordBase) + 4u) = value1;
    *(u16 *) ((recordBase) + 6u) = value1;
    *(u16 *) ((recordBase) + 8u) = value1;
    *(u16 *) ((recordBase) + 10u) = value1;
    value2 = *(const u16 *) ((recordBase) + 12u);
    value0 = 127u;
    value2 = (value2) & ~(value0);
    *(u16 *) ((recordBase) + 12u) = value2;
    value2 = *(const u16 *) ((recordBase) + 12u);
    value0 = 0xfffff87fu;
    value2 = (value2) & (value0);
    value0 = 128u;
    value2 = (value2) | (value0);
    *(u16 *) ((recordBase) + 12u) = value2;
    value2 = *(const u16 *) ((recordBase) + 12u);
    value0 = 0xffff07ffu;
    value2 = (value2) & (value0);
    value0 = 0x800u;
    value2 = (value2) | (value0);
    *(u16 *) ((recordBase) + 12u) = value2;
    value0 = (recordBase) + (0u);
    value0 = (value0) + 14u;
    value2 = 20u;
    MI_CpuFill8((void *) value0, value1, value2);
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    value1 = *(const u8 *) ((value0) + 0u);
    value0 = 1u;
    value1 = (value1) & ~(value0);
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    *(u8 *) ((value0) + 0u) = value1;
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    value1 = *(const u8 *) ((value0) + 0u);
    value0 = 2u;
    value1 = (value1) & ~(value0);
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    *(u8 *) ((value0) + 0u) = value1;
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    value1 = *(const u8 *) ((value0) + 0u);
    value0 = 4u;
    value1 = (value1) & ~(value0);
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    *(u8 *) ((value0) + 0u) = value1;
    value0 = (recordBase) + (0u);
    value0 = (value0) + 34u;
    value1 = *(const u8 *) ((value0) + 0u);
    value0 = 8u;
    value1 = (value1) & ~(value0);
    recordBase = (recordBase) + 34u;
    *(u8 *) ((recordBase) + 0u) = value1;
}
#pragma thumb off
