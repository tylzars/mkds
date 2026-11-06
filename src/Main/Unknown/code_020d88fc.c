#include "Main/Unknown/code_020d88fc.h"

Vec3 *func_020d88fc(Unk020e0144 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = *(const u32 *) ((value0) + (0));
    value1 = *(const u32 *) ((value0) + (12));
    value2 = *(const u32 *) ((value2) + (0));
    value0 = 0x54u;
    value0 = (value1) * (value0) + (value2);
    value0 = (value0) + (0x48u);
    return (Vec3 *) value0;
}
