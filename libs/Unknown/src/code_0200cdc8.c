#include "code_0200cdc8.h"

u32 ClearCardSlotAccessBit(void) {
    u32 value0;
    u32 value1;
    value1 = 0x4000204u;
    value0 = (u32) * (const u16 *) ((value1) + (0));
    value0 = (value0) & ~(0x800u);
    *(u16 *) ((value1) + (0)) = (u16) value0;
    return value0;
}

u32 SetCardSlotAccessBit(void) {
    u32 value0;
    u32 value1;
    value1 = 0x4000204u;
    value0 = (u32) * (const u16 *) ((value1) + (0));
    value0 = (value0) | (0x800u);
    *(u16 *) ((value1) + (0)) = (u16) value0;
    return value0;
}
