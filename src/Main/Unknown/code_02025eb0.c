#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
u32 func_02025eb0(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &data_021532a8;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (u32) value0;
}
#pragma thumb off
