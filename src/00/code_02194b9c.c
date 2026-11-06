#include "00/code_02194b9c.h"

u32 GpiCompareProfiles(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value1) + 0u);
    value0 = (value2) - (value0);
    return value0;
}
