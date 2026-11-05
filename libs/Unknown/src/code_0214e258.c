#include "code_0214e258.h"

s32 TimeToSeconds(const Unk0214e1e0 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value3 = (u32) arg0->mUnk_04;
    value2 = (u32) arg0->mUnk_00;
    value1 = 0x3cu;
    value3 = (value2) * (value1) + (value3);
    value0 = (u32) arg0->mUnk_08;
    value0 = (value3) * (value1) + (value0);
    return value0;
}
