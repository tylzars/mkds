#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/unk_0217b000.h"

struct KartPhysicalParam *GetKartPhysicalParam(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartPhysicalParamTable;
    value1 = 0x98u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (struct KartPhysicalParam *) value0;
}

s32 *GetCharPhysicalParam(u32 p0) {
    return (s32 *) (gKartPhysicalParamTable->mCharParams + (p0 << 3));
}

u32 func_0208ae60(void) {
    return ((u32) gKartPhysicalParamTable->mFirstBaseSpeedLimit);
}
