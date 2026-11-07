#include "Main/Unknown/code_02121e24.h"
#include "00/code_021832d8.h"

u32 GetWiFiSessionCharacterIndex(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x44u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x1000u);
    value0 = *(const u32 *) ((value0) + (3648));
    return value0;
}

u32 GetWiFiSessionKartIndex(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x44u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x1000u);
    value0 = *(const u32 *) ((value0) + (3652));
    return value0;
}

u32 GetWiFiSessionPickedCourseId(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gWiFiSession;
    value1 = 0x44u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x1000u);
    value0 = *(const u32 *) ((value0) + (3656));
    return value0;
}
