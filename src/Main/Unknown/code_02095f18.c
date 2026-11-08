#include "Main/Unknown/code_02095f18.h"
#include "Main/Unknown/code_020d7da8.h"

void InitMoveTree(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value1 = *(const u32 *) ((value0) + (156));
    value0 = (value0) + (0xb4u);
    value2 = 0u;
    InitGroupFollower((GroupFollower *) value0, (CourseMapRow *) value1, value2);
}
