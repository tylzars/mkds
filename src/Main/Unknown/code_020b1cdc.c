#include "Main/Unknown/code_020b1cdc.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020b1cdc(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &gRaceHud;
    value2 = *(const u32 *) ((value2) + (0));
    value0 = (value2) + ((value0 << 2));
    *(u32 *) ((value0) + (2204)) = value1;
    return value0;
}
