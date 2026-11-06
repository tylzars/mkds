#include "Main/Unknown/code_02122ae4.h"
#include "00/code_021832d8.h"

u32 func_02122ae4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value1 = (u32) &gWiFiSession;
    value0 = 0u;
    value1 = *(const u32 *) ((value1) + (0));
    value1 = (value1) + (0x1000u);
    value2 = *(const u8 *) ((value1) + (2477));
    compareLeft0 = value2;
    compareRight0 = 1u;
    if (compareLeft0 != compareRight0) {
        return value0;
    }
    value1 = *(const u32 *) ((value1) + (2384));
    compareLeft1 = value1;
    compareRight1 = 0xcu;
    if (compareLeft1 == compareRight1) {
        value0 = 1u;
    }
    return value0;
}
