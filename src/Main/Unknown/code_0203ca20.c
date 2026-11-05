#include "Main/Unknown/code_0203ca20.h"
#include "Main/Unknown/code_020f36d8.h"

u32 StartRaceClock(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceProgress;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = value1;
    return value0;
}
