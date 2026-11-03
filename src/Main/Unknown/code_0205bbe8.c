#include "Main/Unknown/code_0205bbe8.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0205bbe8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa14;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + (0x700u);
    value1 = (u32) * (const u16 *) ((value0) + (92));
    value1 = (value1) & ~(0x100u);
    *(u16 *) ((value0) + (92)) = (u16) value1;
    return value0;
}
