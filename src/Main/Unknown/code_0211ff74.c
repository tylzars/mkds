#include "Main/Unknown/code_0211ff74.h"
#include "00/code_021832d8.h"

u32 func_0211ff74(void) {
    u32 value0;
    u32 flags;
    u32 testedValue;
    u32 zero;
    value0 = (u32) &gWiFiSession;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x1000u);
    value0 = *(const u32 *) ((value0) + (3896));
    testedValue = value0;
    zero = 0u;
    if (testedValue == zero) {
        return value0;
    }
    value0 = (u32) &data_0217aa14;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x700u);
    flags = *(const u16 *) ((value0) + (92));
    flags = (flags) & ~(4u);
    *(u16 *) ((value0) + (92)) = flags;
    return value0;
}
