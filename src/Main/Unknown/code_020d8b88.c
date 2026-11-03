#include "Main/Unknown/code_020d8b88.h"
#include "Main/Unknown/code_020d9340.h"

void func_020d8b88(Unk020e0144 *arg0, Vec3 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value12 = value0;
    value0 = (u32) * (const u32 *) ((value12) + (0));
    value2 = value1;
    value3 = (u32) * (const u32 *) ((value0) + (0));
    value1 = (u32) * (const u32 *) ((value12) + (12));
    value0 = 0x54u;
    value0 = (value1) * (value0) + (value3);
    value1 = (u32) * (const u32 *) ((value12) + (20));
    func_020d9340(value0, value1, value2);
}
