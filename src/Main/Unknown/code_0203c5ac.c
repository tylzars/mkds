#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020f36d8.h"

u32 GetKartRaceProgress(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceProgress;
    value1 = 0x8cu;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (88));
    return value0;
}

u32 GetKartLapProgress(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceProgress;
    value1 = 0x8cu;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (92));
    return value0;
}
