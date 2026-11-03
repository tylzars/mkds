#include "Main/Unknown/code_02025d8c.h"
#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
u32 func_02025d98(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &data_021532dc;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
u32 func_02025d8c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &data_021533fc;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (u32) value0;
}
#pragma thumb off
