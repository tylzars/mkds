#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020c13d0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceGoalS;
    value1 = 0u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (164)) = value1;
    return value0;
}
