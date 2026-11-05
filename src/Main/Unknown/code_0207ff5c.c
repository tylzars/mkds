#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"

u32 func_0207ff5c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    value2 = (value4) + (8u);
    *(u32 *) ((value4) + (4)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value4) + (0)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    value1 = (u32) * (const u32 *) ((value4) + (4));
    value0 = (u32) * (const u32 *) ((value0) + (24));
    value1 = (u32) * (const u32 *) ((value1) + (24));
    Vec3Sub((const Vec3 *) value0, (const Vec3 *) value1, (Vec3 *) value2);
    value0 = (value4) + (8u);
    value1 = value0;
    value0 = (u32) Vec3NormalizeAndGetLengthUnchecked((const Vec3 *) value0, (Vec3 *) value1);
    return value0;
}
