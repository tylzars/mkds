#include "Main/Unknown/code_020429b8.h"
#include "Main/Unknown/code_020b502c.h"

#pragma thumb on
u32 func_020429b8(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0) + (4u);
    value0 = (u32) &gCourseMap;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    *(u32 *) ((value0) + 24u) = (u32) value1;
    value0 = 1u;
    return (u32) value0;
}
#pragma thumb off
