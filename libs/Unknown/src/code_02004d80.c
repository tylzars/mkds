#include "code_02004d80.h"
#include "code_02004dc0.h"

u32 FS_IsAvailable(void) {
    u32 value0;
    value0 = (u32) &data_0216f350;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}

void FS_InitFile(Unk02003024 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value3 = 0u;
    *(u32 *) ((value0) + (0)) = value3;
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0xeu;
    *(u32 *) ((value0) + (4)) = value2;
    *(u32 *) ((value0) + (28)) = value3;
    value2 = (u32) * (const u32 *) ((value0) + (28));
    *(u32 *) ((value0) + (24)) = value2;
    *(u32 *) ((value0) + (8)) = value3;
    arg0->mUnk_10 = value1;
    arg0->mUnk_0c = value3;
}
