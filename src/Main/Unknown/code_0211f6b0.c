#include "Main/Unknown/code_0211f6b0.h"
#include "00/code_021832d8.h"

u32 func_0211f6b0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gWiFiSession;
    value1 = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x1000u);
    *(u32 *) ((value0) + (3324)) = value1;
    return value0;
}
