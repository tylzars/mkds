#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020f36d8.h"

u16 func_0203c8c0(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceProgress;
    value1 = 0x8cu;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u16 *) ((value1) + (78));
    return (u16) value0;
}
