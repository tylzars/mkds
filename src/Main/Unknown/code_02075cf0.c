#include "Main/Unknown/code_02075cf0.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_02075cf0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217acbc;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (564)) = value1;
    return value0;
}
