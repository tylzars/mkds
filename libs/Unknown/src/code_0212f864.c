#include "code_0212f864.h"

void InterpolatorInit(Interpolator *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    *(u32 *) ((value0) + (4)) = value2;
    value1 = (u32) * (const u32 *) ((value0) + (4));
    *(u32 *) ((value0) + (0)) = value1;
    *(u32 *) ((value0) + (12)) = value2;
    value1 = (u32) * (const u32 *) ((value0) + (12));
    *(u32 *) ((value0) + (8)) = value1;
}
