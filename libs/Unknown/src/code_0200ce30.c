#include "code_0200ce30.h"

u32 ClearCartridgeSlotAccessBit(void) {
    u32 value0;
    u32 value1;
    value1 = 0x4000204u;
    value0 = (u32) * (const u16 *) ((value1) + (0));
    value0 = (value0) & ~(0x80u);
    *(u16 *) ((value1) + (0)) = (u16) value0;
    return value0;
}

u32 SetCartridgeSlotAccessBit(void) {
    u32 value0;
    u32 value1;
    value1 = 0x4000204u;
    value0 = (u32) * (const u16 *) ((value1) + (0));
    value0 = (value0) | (0x80u);
    *(u16 *) ((value1) + (0)) = (u16) value0;
    return value0;
}
