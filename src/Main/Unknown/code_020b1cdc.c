#include "Main/Unknown/code_020b1cdc.h"
#include "Main/Unknown/unk_0217b000.h"

u32 SetRaceHudKartRemoved(u32 kartIndex, u32 removed) {
    u32 value0 = kartIndex;
    u32 value1 = removed;
    u32 value2;
    value2 = (u32) &gRaceHud;
    value2 = *(const u32 *) ((value2) + (0));
    value0 = (value2) + ((value0 << 2));
    *(u32 *) ((value0) + (2204)) = value1;
    return value0;
}
