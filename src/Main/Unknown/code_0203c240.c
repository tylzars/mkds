#include "Main/Unknown/code_0203c240.h"
#include "Main/Unknown/code_020f36d8.h"

u32 GetKartFinishTimeMs(u32 kart) {
    u32 value0 = kart;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceProgress;
    value1 = 0x8cu;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (64));
    return value0;
}
